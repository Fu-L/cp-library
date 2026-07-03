#pragma once
#include "./template.hpp"
namespace dbg {
template <typename T>
struct is_pair : false_type {};
template <typename A, typename B>
struct is_pair<pair<A, B>> : true_type {};

template <typename T>
struct is_optional : false_type {};
template <typename T>
struct is_optional<optional<T>> : true_type {};

template <typename T>
struct is_variant : false_type {};
template <typename... Ts>
struct is_variant<variant<Ts...>> : true_type {};

template <typename T>
struct is_bitset : false_type {};
template <size_t N>
struct is_bitset<bitset<N>> : true_type {};

template <typename T>
struct is_vector_bool : false_type {};
template <typename Allocator>
struct is_vector_bool<vector<bool, Allocator>> : true_type {};

template <typename T>
struct is_stack : false_type {};
template <typename T, typename Container>
struct is_stack<stack<T, Container>> : true_type {};

template <typename T>
struct is_queue : false_type {};
template <typename T, typename Container>
struct is_queue<queue<T, Container>> : true_type {};

template <typename T>
struct is_priority_queue : false_type {};
template <typename T, typename Container, typename Compare>
struct is_priority_queue<priority_queue<T, Container, Compare>> : true_type {};

template <typename T>
concept Streamable = requires(ostream& os, const T& x) {
    os << x;
};

template <typename T>
concept Range = ranges::range<T>;

template <typename T>
concept TupleLike = requires {
    typename tuple_size<T>::type;
};

template <typename T>
string to_string(const T& x);

string to_string_integer(__int128_t x) {
    bool neg = x < 0;
    __uint128_t y = neg ? __uint128_t(-(x + 1)) + 1 : __uint128_t(x);
    if(y == 0) return "0";
    string res;
    while(y > 0) {
        res += char('0' + y % 10);
        y /= 10;
    }
    if(neg) res += '-';
    reverse(res.begin(), res.end());
    return res;
}
string to_string_integer(__uint128_t x) {
    if(x == 0) return "0";
    string res;
    while(x > 0) {
        res += char('0' + x % 10);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string to_string_char(char c) {
    if(c == '\n') return "'\\n'";
    if(c == '\t') return "'\\t'";
    if(c == '\r') return "'\\r'";
    if(c == '\0') return "'\\0'";
    if(c == '\\') return "'\\\\'";
    if(c == '\'') return "'\\''";
    return "'" + string(1, c) + "'";
}
string to_string_string(const string& s) {
    string res;
    res += '"';
    for(char c : s) {
        if(c == '\n') res += "\\n";
        else if(c == '\t') res += "\\t";
        else if(c == '\r') res += "\\r";
        else if(c == '\0') res += "\\0";
        else if(c == '\\') res += "\\\\";
        else if(c == '"') res += "\\\"";
        else res += c;
    }
    res += '"';
    return res;
}

template <typename T>
string to_string_range(const T& v) {
    bool first = true;
    string res = "{";
    for(const auto& x : v) {
        if(!first) res += ", ";
        first = false;
        res += dbg::to_string(x);
    }
    res += "}";
    return res;
}

template <typename T>
string to_string_tuple(const T& t) {
    string res = "(";
    bool first = true;
    apply(
        [&](const auto&... xs) {
            ((res += (exchange(first, false) ? "" : ", ") + dbg::to_string(xs)), ...);
        },
        t);
    res += ")";
    return res;
}

template <typename T>
string to_string_adaptor(T q) {
    bool first = true;
    string res = "{";
    while(!q.empty()) {
        if(!first) res += ", ";
        first = false;
        if constexpr(is_stack<T>::value || is_priority_queue<T>::value) {
            res += dbg::to_string(q.top());
        } else {
            res += dbg::to_string(q.front());
        }
        q.pop();
    }
    res += "}";
    return res;
}

template <typename T>
string to_string(const T& x) {
    using U = remove_cvref_t<T>;
    if constexpr(same_as<U, string>) {
        return to_string_string(x);
    } else if constexpr(same_as<U, const char*> || same_as<U, char*>) {
        return x == nullptr ? "null" : dbg::to_string(string(x));
    } else if constexpr(is_array_v<U> && same_as<remove_extent_t<U>, char>) {
        return dbg::to_string(static_cast<const char*>(x));
    } else if constexpr(same_as<U, char>) {
        return to_string_char(x);
    } else if constexpr(same_as<U, bool>) {
        return x ? "true" : "false";
    } else if constexpr(same_as<U, __int128_t>) {
        return to_string_integer(x);
    } else if constexpr(same_as<U, __uint128_t>) {
        return to_string_integer(x);
    } else if constexpr(is_arithmetic_v<U>) {
        return std::to_string(x);
    } else if constexpr(is_pair<U>::value) {
        return "(" + dbg::to_string(x.first) + ", " + dbg::to_string(x.second) + ")";
    } else if constexpr(is_optional<U>::value) {
        return x ? "optional(" + dbg::to_string(*x) + ")" : "nullopt";
    } else if constexpr(is_variant<U>::value) {
        return visit([](const auto& v) { return "variant(" + dbg::to_string(v) + ")"; }, x);
    } else if constexpr(is_bitset<U>::value) {
        string res;
        for(size_t i = 0; i < x.size(); ++i) {
            res += char('0' + x[x.size() - 1 - i]);
        }
        return res;
    } else if constexpr(is_vector_bool<U>::value) {
        string res = "{";
        for(int i = 0; i < static_cast<int>(x.size()); ++i) {
            if(i != 0) res += ", ";
            res += dbg::to_string(static_cast<bool>(x[i]));
        }
        res += "}";
        return res;
    } else if constexpr(is_stack<U>::value || is_queue<U>::value || is_priority_queue<U>::value) {
        return to_string_adaptor(x);
    } else if constexpr(Range<U>) {
        return to_string_range(x);
    } else if constexpr(TupleLike<U>) {
        return to_string_tuple(x);
    } else if constexpr(Streamable<U>) {
        stringstream ss;
        ss << x;
        return ss.str();
    } else {
        return "<unprintable>";
    }
}

void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(const Head& H, const Tail&... T) {
    cerr << " " << dbg::to_string(H);
    if(sizeof...(T) != 0) cerr << ",";
    debug_out(T...);
}
}  // namespace dbg
#define debug(...) cerr << "Line " << __LINE__ << ", "  \
                        << "[" << #__VA_ARGS__ << "]:", \
                   dbg::debug_out(__VA_ARGS__)
