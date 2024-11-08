---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/fps/berlekamp_massey.hpp
    title: berlekamp_massey
  - icon: ':x:'
    path: src/fps/bostan_mori.hpp
    title: bostan_mori
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yukicoder/1559.test.cpp
    title: verify/yukicoder/1559.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n\
    #define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a,\
    \ b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
    struct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/fps/berlekamp_massey.hpp\"\
    \ntemplate <template <typename> typename FPS, typename mint>\nFPS<mint> berlekamp_massey(const\
    \ FPS<mint>& s) {\n    const int n = (int)s.size();\n    FPS<mint> b = {mint(-1)},\
    \ c = {mint(-1)};\n    mint y = mint(1);\n    for(int ed = 1; ed <= n; ++ed) {\n\
    \        int l = (int)c.size(), m = (int)b.size();\n        mint x = 0;\n    \
    \    for(int i = 0; i < l; ++i) x += c[i] * s[ed - l + i];\n        b.emplace_back(0);\n\
    \        ++m;\n        if(x == mint(0)) continue;\n        mint freq = x / y;\n\
    \        if(l < m) {\n            auto tmp = c;\n            c.insert(begin(c),\
    \ m - l, mint(0));\n            for(int i = 0; i < m; ++i) c[m - 1 - i] -= freq\
    \ * b[m - 1 - i];\n            b = tmp;\n            y = x;\n        } else {\n\
    \            for(int i = 0; i < m; ++i) c[l - 1 - i] -= freq * b[m - 1 - i];\n\
    \        }\n    }\n    c.pop_back();\n    c = c.rev();\n    return c;\n}\n#line\
    \ 3 \"src/fps/bostan_mori.hpp\"\ntemplate <template <typename> typename FPS, typename\
    \ mint>\nmint bostan_mori(const FPS<mint>& a, const FPS<mint>& c, long long k)\
    \ {\n    assert(k >= 0);\n    if(k < (int)a.size()) return a[k];\n    assert(a.size()\
    \ >= c.size());\n    FPS<mint> q = FPS<mint>{1} - (c << 1);\n    FPS<mint> p =\
    \ (a * q).pre((int)c.size());\n    if(p.empty()) return 0;\n    while(k > 0) {\n\
    \        auto q2 = q;\n        for(int i = 1; i < (int)q2.size(); i += 2) q2[i]\
    \ = -q2[i];\n        const auto s = p * q2;\n        const auto t = q * q2;\n\
    \        if(k & 1) {\n            for(int i = 1; i < (int)s.size(); i += 2) p[i\
    \ >> 1] = s[i];\n            for(int i = 0; i < (int)t.size(); i += 2) q[i >>\
    \ 1] = t[i];\n        } else {\n            for(int i = 0; i < (int)s.size();\
    \ i += 2) p[i >> 1] = s[i];\n            for(int i = 0; i < (int)t.size(); i +=\
    \ 2) q[i >> 1] = t[i];\n        }\n        k >>= 1;\n    }\n    return p[0];\n\
    }\n#line 5 \"src/fps/nth_term.hpp\"\ntemplate <template <typename> typename FPS,\
    \ typename mint>\nmint nth_term(const FPS<mint>& s, long long n) {\n    assert(n\
    \ >= 0);\n    const FPS<mint> c = berlekamp_massey(s);\n    return bostan_mori(s,\
    \ c, n);\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./berlekamp_massey.hpp\"\
    \n#include \"./bostan_mori.hpp\"\ntemplate <template <typename> typename FPS,\
    \ typename mint>\nmint nth_term(const FPS<mint>& s, long long n) {\n    assert(n\
    \ >= 0);\n    const FPS<mint> c = berlekamp_massey(s);\n    return bostan_mori(s,\
    \ c, n);\n}"
  dependsOn:
  - src/template/template.hpp
  - src/fps/berlekamp_massey.hpp
  - src/fps/bostan_mori.hpp
  isVerificationFile: false
  path: src/fps/nth_term.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yukicoder/1559.test.cpp
documentation_of: src/fps/nth_term.hpp
layout: document
title: nth_term
---

## nth_term

```cpp
mint nth_term(FPS<mint> s, ll n)
```

斉次線形漸化式

$$a_i = \sum\limits_{j = 0}^{d - 1} c_j a_{i - 1 - j}$$

の形で表される線形回帰数列 $a$ の前 $k$ 項が与えられたときに $a_n$ を返します．

$c$ を一意に確定させるために $k \geq 2d$ が必要です．<br>
$k < 2d$ の場合，正しく計算できていない可能性があるので注意してください．

**制約**

- $0 \leq n$

**計算量**

- $O(k^2 + k \log k \log n)$
