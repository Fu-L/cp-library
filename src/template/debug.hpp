#pragma once
#include "./template.hpp"
#include "./static_modint.hpp"
#include "./dynamic_modint.hpp"
namespace dbg {
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) {
    return "\"" + s + "\"";
}
string to_string(const char& c) {
    return "'" + string(1, c) + "'";
}
string to_string(bool b) {
    return (b ? "true" : "false");
}
template <typename T, enable_if_t<is_arithmetic<T>::value, nullptr_t> = nullptr>
string to_string(T t) {
    return std::to_string(t);
}
template <uint32_t m>
string to_string(StaticModint<m> x) {
    return std::to_string(x.val());
}
template <int id>
string to_string(DynamicModint<id> x) {
    return std::to_string(x.val());
}
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for(int i = 0; i < static_cast<int>(v.size()); i++) {
        if(!first) {
            res += ", ";
        }
        first = false;
        res += dbg::to_string(v[i]);
    }
    res += "}";
    return res;
}
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for(size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
template <typename A, enable_if_t<!is_arithmetic<A>::value, nullptr_t> = nullptr>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for(const auto& x : v) {
        if(!first) {
            res += ", ";
        }
        first = false;
        res += dbg::to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + dbg::to_string(p.first) + ", " + dbg::to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + dbg::to_string(get<0>(p)) + ", " + dbg::to_string(get<1>(p)) + ", " + dbg::to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + dbg::to_string(get<0>(p)) + ", " + dbg::to_string(get<1>(p)) + ", " + dbg::to_string(get<2>(p)) + ", " + dbg::to_string(get<3>(p)) + ")";
}
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << dbg::to_string(H);
    if(sizeof...(T) != 0) cerr << ",";
    debug_out(T...);
}
}  // namespace dbg
#define debug(...) cerr << "Line " << __LINE__ << ", " << "[" << #__VA_ARGS__ << "]:", dbg::debug_out(__VA_ARGS__)