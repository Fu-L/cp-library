---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/fps/nth_term.hpp
    title: nth_term
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: verify/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':x:'
    path: verify/yukicoder/1559.test.cpp
    title: verify/yukicoder/1559.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/fps/bostan_mori.hpp\"\
    \ntemplate <template <typename> typename FPS, typename mint>\nmint bostan_mori(const\
    \ FPS<mint>& a, const FPS<mint>& c, long long k) {\n    assert(k >= 0);\n    if(k\
    \ < (int)a.size()) return a[k];\n    assert(a.size() >= c.size());\n    FPS<mint>\
    \ q = FPS<mint>{1} - (c << 1);\n    FPS<mint> p = (a * q).pre((int)c.size());\n\
    \    while(k > 0) {\n        auto q2 = q;\n        for(int i = 1; i < (int)q2.size();\
    \ i += 2) q2[i] = -q2[i];\n        const auto s = p * q2;\n        const auto\
    \ t = q * q2;\n        if(k & 1) {\n            for(int i = 1; i < (int)s.size();\
    \ i += 2) p[i >> 1] = s[i];\n            for(int i = 0; i < (int)t.size(); i +=\
    \ 2) q[i >> 1] = t[i];\n        } else {\n            for(int i = 0; i < (int)s.size();\
    \ i += 2) p[i >> 1] = s[i];\n            for(int i = 0; i < (int)t.size(); i +=\
    \ 2) q[i >> 1] = t[i];\n        }\n        k >>= 1;\n    }\n    return p[0];\n\
    }\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <template <typename>\
    \ typename FPS, typename mint>\nmint bostan_mori(const FPS<mint>& a, const FPS<mint>&\
    \ c, long long k) {\n    assert(k >= 0);\n    if(k < (int)a.size()) return a[k];\n\
    \    assert(a.size() >= c.size());\n    FPS<mint> q = FPS<mint>{1} - (c << 1);\n\
    \    FPS<mint> p = (a * q).pre((int)c.size());\n    while(k > 0) {\n        auto\
    \ q2 = q;\n        for(int i = 1; i < (int)q2.size(); i += 2) q2[i] = -q2[i];\n\
    \        const auto s = p * q2;\n        const auto t = q * q2;\n        if(k\
    \ & 1) {\n            for(int i = 1; i < (int)s.size(); i += 2) p[i >> 1] = s[i];\n\
    \            for(int i = 0; i < (int)t.size(); i += 2) q[i >> 1] = t[i];\n   \
    \     } else {\n            for(int i = 0; i < (int)s.size(); i += 2) p[i >> 1]\
    \ = s[i];\n            for(int i = 0; i < (int)t.size(); i += 2) q[i >> 1] = t[i];\n\
    \        }\n        k >>= 1;\n    }\n    return p[0];\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/fps/bostan_mori.hpp
  requiredBy:
  - src/fps/nth_term.hpp
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
  - verify/yukicoder/1559.test.cpp
documentation_of: src/fps/bostan_mori.hpp
layout: document
title: bostan_mori
---

## bostan_mori

```cpp
mint bostan_mori(FPS<mint> a, FPS<mint> c, ll k)
```

斉次線形漸化式

$$a_i = \sum\limits_{j = 0}^{d - 1} c_j a_{i - 1 - j}$$

の $a$ の前 $n ~(\geq d)$ 項と $c$ が与えられたときに $a_k$ を返します．

**制約**

- $0 \leq k$
- $d \leq n$

**計算量**

- $O(d \log d \log k)$
