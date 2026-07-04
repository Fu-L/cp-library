---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/template/debug.test.cpp
    title: verify/unit_test/template/debug.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/template/debug_without_modint.test.cpp
    title: verify/unit_test/template/debug_without_modint.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    #line 4 \"src/template/template.hpp\"\nusing namespace std;\nusing ll = long long;\n\
    using P = pair<long long, long long>;\n#define rep(i, a, b) for(long long i =\
    \ (a); i < (b); ++i)\n#define rrep(i, a, b) for(long long i = (a); i >= (b); --i)\n\
    constexpr long long inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/template/debug.hpp\"\nnamespace dbg {\ntemplate <typename T>\nstruct\
    \ is_pair : false_type {};\ntemplate <typename A, typename B>\nstruct is_pair<pair<A,\
    \ B>> : true_type {};\n\ntemplate <typename T>\nstruct is_optional : false_type\
    \ {};\ntemplate <typename T>\nstruct is_optional<optional<T>> : true_type {};\n\
    \ntemplate <typename T>\nstruct is_variant : false_type {};\ntemplate <typename...\
    \ Ts>\nstruct is_variant<variant<Ts...>> : true_type {};\n\ntemplate <typename\
    \ T>\nstruct is_bitset : false_type {};\ntemplate <size_t N>\nstruct is_bitset<bitset<N>>\
    \ : true_type {};\n\ntemplate <typename T>\nstruct is_vector_bool : false_type\
    \ {};\ntemplate <typename Allocator>\nstruct is_vector_bool<vector<bool, Allocator>>\
    \ : true_type {};\n\ntemplate <typename T>\nstruct is_stack : false_type {};\n\
    template <typename T, typename Container>\nstruct is_stack<stack<T, Container>>\
    \ : true_type {};\n\ntemplate <typename T>\nstruct is_queue : false_type {};\n\
    template <typename T, typename Container>\nstruct is_queue<queue<T, Container>>\
    \ : true_type {};\n\ntemplate <typename T>\nstruct is_priority_queue : false_type\
    \ {};\ntemplate <typename T, typename Container, typename Compare>\nstruct is_priority_queue<priority_queue<T,\
    \ Container, Compare>> : true_type {};\n\ntemplate <typename T>\nconcept Streamable\
    \ = requires(ostream& os, const T& x) {\n    os << x;\n};\n\ntemplate <typename\
    \ T>\nconcept Range = ranges::range<T>;\n\ntemplate <typename T>\nconcept TupleLike\
    \ = requires {\n    typename tuple_size<T>::type;\n};\n\ntemplate <typename T>\n\
    string to_string(const T& x);\n\nstring to_string_integer(__int128_t x) {\n  \
    \  bool neg = x < 0;\n    __uint128_t y = neg ? __uint128_t(-(x + 1)) + 1 : __uint128_t(x);\n\
    \    if(y == 0) return \"0\";\n    string res;\n    while(y > 0) {\n        res\
    \ += char('0' + y % 10);\n        y /= 10;\n    }\n    if(neg) res += '-';\n \
    \   reverse(res.begin(), res.end());\n    return res;\n}\nstring to_string_integer(__uint128_t\
    \ x) {\n    if(x == 0) return \"0\";\n    string res;\n    while(x > 0) {\n  \
    \      res += char('0' + x % 10);\n        x /= 10;\n    }\n    reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n\nstring to_string_char(char c) {\n    if(c\
    \ == '\\n') return \"'\\\\n'\";\n    if(c == '\\t') return \"'\\\\t'\";\n    if(c\
    \ == '\\r') return \"'\\\\r'\";\n    if(c == '\\0') return \"'\\\\0'\";\n    if(c\
    \ == '\\\\') return \"'\\\\\\\\'\";\n    if(c == '\\'') return \"'\\\\''\";\n\
    \    return \"'\" + string(1, c) + \"'\";\n}\nstring to_string_string(const string&\
    \ s) {\n    string res;\n    res += '\"';\n    for(char c : s) {\n        if(c\
    \ == '\\n') res += \"\\\\n\";\n        else if(c == '\\t') res += \"\\\\t\";\n\
    \        else if(c == '\\r') res += \"\\\\r\";\n        else if(c == '\\0') res\
    \ += \"\\\\0\";\n        else if(c == '\\\\') res += \"\\\\\\\\\";\n        else\
    \ if(c == '\"') res += \"\\\\\\\"\";\n        else res += c;\n    }\n    res +=\
    \ '\"';\n    return res;\n}\n\ntemplate <typename T>\nstring to_string_range(const\
    \ T& v) {\n    bool first = true;\n    string res = \"{\";\n    for(const auto&\
    \ x : v) {\n        if(!first) res += \", \";\n        first = false;\n      \
    \  res += dbg::to_string(x);\n    }\n    res += \"}\";\n    return res;\n}\n\n\
    template <typename T>\nstring to_string_tuple(const T& t) {\n    string res =\
    \ \"(\";\n    bool first = true;\n    apply(\n        [&](const auto&... xs) {\n\
    \            ((res += (exchange(first, false) ? \"\" : \", \") + dbg::to_string(xs)),\
    \ ...);\n        },\n        t);\n    res += \")\";\n    return res;\n}\n\ntemplate\
    \ <typename T>\nstring to_string_adaptor(T q) {\n    bool first = true;\n    string\
    \ res = \"{\";\n    while(!q.empty()) {\n        if(!first) res += \", \";\n \
    \       first = false;\n        if constexpr(is_stack<T>::value || is_priority_queue<T>::value)\
    \ {\n            res += dbg::to_string(q.top());\n        } else {\n         \
    \   res += dbg::to_string(q.front());\n        }\n        q.pop();\n    }\n  \
    \  res += \"}\";\n    return res;\n}\n\ntemplate <typename T>\nstring to_string(const\
    \ T& x) {\n    using U = remove_cvref_t<T>;\n    if constexpr(same_as<U, string>)\
    \ {\n        return to_string_string(x);\n    } else if constexpr(same_as<U, const\
    \ char*> || same_as<U, char*>) {\n        return x == nullptr ? \"null\" : dbg::to_string(string(x));\n\
    \    } else if constexpr(is_array_v<U> && same_as<remove_extent_t<U>, char>) {\n\
    \        return dbg::to_string(static_cast<const char*>(x));\n    } else if constexpr(same_as<U,\
    \ char>) {\n        return to_string_char(x);\n    } else if constexpr(same_as<U,\
    \ bool>) {\n        return x ? \"true\" : \"false\";\n    } else if constexpr(same_as<U,\
    \ __int128_t>) {\n        return to_string_integer(x);\n    } else if constexpr(same_as<U,\
    \ __uint128_t>) {\n        return to_string_integer(x);\n    } else if constexpr(is_arithmetic_v<U>)\
    \ {\n        return std::to_string(x);\n    } else if constexpr(is_pair<U>::value)\
    \ {\n        return \"(\" + dbg::to_string(x.first) + \", \" + dbg::to_string(x.second)\
    \ + \")\";\n    } else if constexpr(is_optional<U>::value) {\n        return x\
    \ ? \"optional(\" + dbg::to_string(*x) + \")\" : \"nullopt\";\n    } else if constexpr(is_variant<U>::value)\
    \ {\n        return visit([](const auto& v) { return \"variant(\" + dbg::to_string(v)\
    \ + \")\"; }, x);\n    } else if constexpr(is_bitset<U>::value) {\n        string\
    \ res;\n        for(size_t i = 0; i < x.size(); ++i) {\n            res += char('0'\
    \ + x[x.size() - 1 - i]);\n        }\n        return res;\n    } else if constexpr(is_vector_bool<U>::value)\
    \ {\n        string res = \"{\";\n        for(int i = 0; i < static_cast<int>(x.size());\
    \ ++i) {\n            if(i != 0) res += \", \";\n            res += dbg::to_string(static_cast<bool>(x[i]));\n\
    \        }\n        res += \"}\";\n        return res;\n    } else if constexpr(is_stack<U>::value\
    \ || is_queue<U>::value || is_priority_queue<U>::value) {\n        return to_string_adaptor(x);\n\
    \    } else if constexpr(Range<U>) {\n        return to_string_range(x);\n   \
    \ } else if constexpr(TupleLike<U>) {\n        return to_string_tuple(x);\n  \
    \  } else if constexpr(Streamable<U>) {\n        stringstream ss;\n        ss\
    \ << x;\n        return ss.str();\n    } else {\n        return \"<unprintable>\"\
    ;\n    }\n}\n\nvoid debug_out() {\n    cerr << endl;\n}\ntemplate <typename Head,\
    \ typename... Tail>\nvoid debug_out(const Head& H, const Tail&... T) {\n    cerr\
    \ << \" \" << dbg::to_string(H);\n    if(sizeof...(T) != 0) cerr << \",\";\n \
    \   debug_out(T...);\n}\n}  // namespace dbg\n#define debug(...)             \
    \          \\\n    cerr << \"Line \" << __LINE__ << \", \"  \\\n         << \"\
    [\" << #__VA_ARGS__ << \"]:\", \\\n        dbg::debug_out(__VA_ARGS__)\n"
  code: "#pragma once\n#include \"./template.hpp\"\nnamespace dbg {\ntemplate <typename\
    \ T>\nstruct is_pair : false_type {};\ntemplate <typename A, typename B>\nstruct\
    \ is_pair<pair<A, B>> : true_type {};\n\ntemplate <typename T>\nstruct is_optional\
    \ : false_type {};\ntemplate <typename T>\nstruct is_optional<optional<T>> : true_type\
    \ {};\n\ntemplate <typename T>\nstruct is_variant : false_type {};\ntemplate <typename...\
    \ Ts>\nstruct is_variant<variant<Ts...>> : true_type {};\n\ntemplate <typename\
    \ T>\nstruct is_bitset : false_type {};\ntemplate <size_t N>\nstruct is_bitset<bitset<N>>\
    \ : true_type {};\n\ntemplate <typename T>\nstruct is_vector_bool : false_type\
    \ {};\ntemplate <typename Allocator>\nstruct is_vector_bool<vector<bool, Allocator>>\
    \ : true_type {};\n\ntemplate <typename T>\nstruct is_stack : false_type {};\n\
    template <typename T, typename Container>\nstruct is_stack<stack<T, Container>>\
    \ : true_type {};\n\ntemplate <typename T>\nstruct is_queue : false_type {};\n\
    template <typename T, typename Container>\nstruct is_queue<queue<T, Container>>\
    \ : true_type {};\n\ntemplate <typename T>\nstruct is_priority_queue : false_type\
    \ {};\ntemplate <typename T, typename Container, typename Compare>\nstruct is_priority_queue<priority_queue<T,\
    \ Container, Compare>> : true_type {};\n\ntemplate <typename T>\nconcept Streamable\
    \ = requires(ostream& os, const T& x) {\n    os << x;\n};\n\ntemplate <typename\
    \ T>\nconcept Range = ranges::range<T>;\n\ntemplate <typename T>\nconcept TupleLike\
    \ = requires {\n    typename tuple_size<T>::type;\n};\n\ntemplate <typename T>\n\
    string to_string(const T& x);\n\nstring to_string_integer(__int128_t x) {\n  \
    \  bool neg = x < 0;\n    __uint128_t y = neg ? __uint128_t(-(x + 1)) + 1 : __uint128_t(x);\n\
    \    if(y == 0) return \"0\";\n    string res;\n    while(y > 0) {\n        res\
    \ += char('0' + y % 10);\n        y /= 10;\n    }\n    if(neg) res += '-';\n \
    \   reverse(res.begin(), res.end());\n    return res;\n}\nstring to_string_integer(__uint128_t\
    \ x) {\n    if(x == 0) return \"0\";\n    string res;\n    while(x > 0) {\n  \
    \      res += char('0' + x % 10);\n        x /= 10;\n    }\n    reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n\nstring to_string_char(char c) {\n    if(c\
    \ == '\\n') return \"'\\\\n'\";\n    if(c == '\\t') return \"'\\\\t'\";\n    if(c\
    \ == '\\r') return \"'\\\\r'\";\n    if(c == '\\0') return \"'\\\\0'\";\n    if(c\
    \ == '\\\\') return \"'\\\\\\\\'\";\n    if(c == '\\'') return \"'\\\\''\";\n\
    \    return \"'\" + string(1, c) + \"'\";\n}\nstring to_string_string(const string&\
    \ s) {\n    string res;\n    res += '\"';\n    for(char c : s) {\n        if(c\
    \ == '\\n') res += \"\\\\n\";\n        else if(c == '\\t') res += \"\\\\t\";\n\
    \        else if(c == '\\r') res += \"\\\\r\";\n        else if(c == '\\0') res\
    \ += \"\\\\0\";\n        else if(c == '\\\\') res += \"\\\\\\\\\";\n        else\
    \ if(c == '\"') res += \"\\\\\\\"\";\n        else res += c;\n    }\n    res +=\
    \ '\"';\n    return res;\n}\n\ntemplate <typename T>\nstring to_string_range(const\
    \ T& v) {\n    bool first = true;\n    string res = \"{\";\n    for(const auto&\
    \ x : v) {\n        if(!first) res += \", \";\n        first = false;\n      \
    \  res += dbg::to_string(x);\n    }\n    res += \"}\";\n    return res;\n}\n\n\
    template <typename T>\nstring to_string_tuple(const T& t) {\n    string res =\
    \ \"(\";\n    bool first = true;\n    apply(\n        [&](const auto&... xs) {\n\
    \            ((res += (exchange(first, false) ? \"\" : \", \") + dbg::to_string(xs)),\
    \ ...);\n        },\n        t);\n    res += \")\";\n    return res;\n}\n\ntemplate\
    \ <typename T>\nstring to_string_adaptor(T q) {\n    bool first = true;\n    string\
    \ res = \"{\";\n    while(!q.empty()) {\n        if(!first) res += \", \";\n \
    \       first = false;\n        if constexpr(is_stack<T>::value || is_priority_queue<T>::value)\
    \ {\n            res += dbg::to_string(q.top());\n        } else {\n         \
    \   res += dbg::to_string(q.front());\n        }\n        q.pop();\n    }\n  \
    \  res += \"}\";\n    return res;\n}\n\ntemplate <typename T>\nstring to_string(const\
    \ T& x) {\n    using U = remove_cvref_t<T>;\n    if constexpr(same_as<U, string>)\
    \ {\n        return to_string_string(x);\n    } else if constexpr(same_as<U, const\
    \ char*> || same_as<U, char*>) {\n        return x == nullptr ? \"null\" : dbg::to_string(string(x));\n\
    \    } else if constexpr(is_array_v<U> && same_as<remove_extent_t<U>, char>) {\n\
    \        return dbg::to_string(static_cast<const char*>(x));\n    } else if constexpr(same_as<U,\
    \ char>) {\n        return to_string_char(x);\n    } else if constexpr(same_as<U,\
    \ bool>) {\n        return x ? \"true\" : \"false\";\n    } else if constexpr(same_as<U,\
    \ __int128_t>) {\n        return to_string_integer(x);\n    } else if constexpr(same_as<U,\
    \ __uint128_t>) {\n        return to_string_integer(x);\n    } else if constexpr(is_arithmetic_v<U>)\
    \ {\n        return std::to_string(x);\n    } else if constexpr(is_pair<U>::value)\
    \ {\n        return \"(\" + dbg::to_string(x.first) + \", \" + dbg::to_string(x.second)\
    \ + \")\";\n    } else if constexpr(is_optional<U>::value) {\n        return x\
    \ ? \"optional(\" + dbg::to_string(*x) + \")\" : \"nullopt\";\n    } else if constexpr(is_variant<U>::value)\
    \ {\n        return visit([](const auto& v) { return \"variant(\" + dbg::to_string(v)\
    \ + \")\"; }, x);\n    } else if constexpr(is_bitset<U>::value) {\n        string\
    \ res;\n        for(size_t i = 0; i < x.size(); ++i) {\n            res += char('0'\
    \ + x[x.size() - 1 - i]);\n        }\n        return res;\n    } else if constexpr(is_vector_bool<U>::value)\
    \ {\n        string res = \"{\";\n        for(int i = 0; i < static_cast<int>(x.size());\
    \ ++i) {\n            if(i != 0) res += \", \";\n            res += dbg::to_string(static_cast<bool>(x[i]));\n\
    \        }\n        res += \"}\";\n        return res;\n    } else if constexpr(is_stack<U>::value\
    \ || is_queue<U>::value || is_priority_queue<U>::value) {\n        return to_string_adaptor(x);\n\
    \    } else if constexpr(Range<U>) {\n        return to_string_range(x);\n   \
    \ } else if constexpr(TupleLike<U>) {\n        return to_string_tuple(x);\n  \
    \  } else if constexpr(Streamable<U>) {\n        stringstream ss;\n        ss\
    \ << x;\n        return ss.str();\n    } else {\n        return \"<unprintable>\"\
    ;\n    }\n}\n\nvoid debug_out() {\n    cerr << endl;\n}\ntemplate <typename Head,\
    \ typename... Tail>\nvoid debug_out(const Head& H, const Tail&... T) {\n    cerr\
    \ << \" \" << dbg::to_string(H);\n    if(sizeof...(T) != 0) cerr << \",\";\n \
    \   debug_out(T...);\n}\n}  // namespace dbg\n#define debug(...)             \
    \          \\\n    cerr << \"Line \" << __LINE__ << \", \"  \\\n         << \"\
    [\" << #__VA_ARGS__ << \"]:\", \\\n        dbg::debug_out(__VA_ARGS__)\n"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/template/debug.hpp
  requiredBy: []
  timestamp: '2026-07-04 16:48:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/template/debug.test.cpp
  - verify/unit_test/template/debug_without_modint.test.cpp
documentation_of: src/template/debug.hpp
layout: document
title: debug
---

## debug

```cpp
debug(hoge)
```

変数 `hoge` の行数，名前，中身を表示するデバッグマクロです．<br>

```cpp
debug(hoge, fuga, piyo)
```

などのように複数入力しても大丈夫です．

`int` 型などの数値型だけでなく `pair` 型や `tuple` 型や `vector` 型や `map` 型や `set` 型や `bitset` 型などにも対応しています．<br>
また `optional` 型や `variant` 型， `stack` 型や `queue` 型や `priority_queue` 型， `operator<<` で出力できる型にも対応しています．<br>
`UnionFind` や `Graph` や `FenwickTree` などの構造体には現状では対応していません．

`make b` の際に `debug` が含まれる行が削除されます．<br>
`#include "template/debug.hpp"` や `debug(hoge)` を消す目的ですが，以下のように書いてしまうと消えるべきでない行が消えてしまうので注意が必要です．<br>
また"debug"という連続部分文字列を含む変数や関数の宣言にも気をつけてください．

```cpp
int n = 5; debug(n);
```

`modint` 型は `operator<<` で出力できるため， `modint/static_modint.hpp` や `modint/dynamic_modint.hpp` を明示的にインクルードしていればデバッグできます．<br>
`debug.hpp` 自体は `modint` をインクルードしないので， `debug.hpp` を入れただけで `modint` 型が使えるようにはなりません．