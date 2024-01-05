---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/ntl/prime_factorize.test.cpp
    title: verify/aizu_online_judge/ntl/prime_factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/prime_factorization.hpp\"\
    \nmap<ll, ll> prime_factor(ll n) {\n    assert(n >= 1);\n    map<ll, ll> res;\n\
    \    for(ll i = 2; i * i <= n; ++i) {\n        while(n % i == 0) {\n         \
    \   ++res[i];\n            n /= i;\n        }\n    }\n    if(n != 1) {\n     \
    \   res[n] = 1;\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nmap<ll, ll> prime_factor(ll\
    \ n) {\n    assert(n >= 1);\n    map<ll, ll> res;\n    for(ll i = 2; i * i <=\
    \ n; ++i) {\n        while(n % i == 0) {\n            ++res[i];\n            n\
    \ /= i;\n        }\n    }\n    if(n != 1) {\n        res[n] = 1;\n    }\n    return\
    \ res;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/prime_factorization.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/ntl/prime_factorize.test.cpp
documentation_of: src/math/prime_factorization.hpp
layout: document
title: prime_factor
---

## prime_factor

```cpp
map<ll, ll> prime_factor(ll n)
```

正整数 $n$ を素因数分解します．

**制約**

- $1 \leq n$

**計算量**

- $O(\sqrt{n})$