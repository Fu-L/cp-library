---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/moebius.hpp
    title: moebius
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/ntl/prime_factorize.test.cpp
    title: verify/aizu_online_judge/ntl/prime_factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/eratosthenes_seive.test.cpp
    title: verify/unit_test/math/eratosthenes_seive.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n\
    #define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a,\
    \ b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
    struct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/prime_factors.hpp\"\
    \nvector<pair<long long, int>> prime_factors(long long n) {\n    assert(n >= 1);\n\
    \    vector<pair<long long, int>> res;\n    for(long long i = 2; i * i <= n; ++i)\
    \ {\n        if(n % i == 0) {\n            res.emplace_back(i, 0);\n         \
    \   while(n % i == 0) {\n                n /= i;\n                ++res.back().second;\n\
    \            }\n        }\n    }\n    if(n >= 2) res.emplace_back(n, 1);\n   \
    \ return res;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nvector<pair<long long,\
    \ int>> prime_factors(long long n) {\n    assert(n >= 1);\n    vector<pair<long\
    \ long, int>> res;\n    for(long long i = 2; i * i <= n; ++i) {\n        if(n\
    \ % i == 0) {\n            res.emplace_back(i, 0);\n            while(n % i ==\
    \ 0) {\n                n /= i;\n                ++res.back().second;\n      \
    \      }\n        }\n    }\n    if(n >= 2) res.emplace_back(n, 1);\n    return\
    \ res;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/prime_factors.hpp
  requiredBy:
  - src/math/moebius.hpp
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/eratosthenes_seive.test.cpp
  - verify/aizu_online_judge/ntl/prime_factorize.test.cpp
documentation_of: src/math/prime_factors.hpp
layout: document
title: prime_factors
---

## prime_factors

```cpp
vector<pair<ll, int>> prime_factors(ll n)
```

正整数 $n$ を素因数分解します．

**制約**

- $1 \leq n$

**計算量**

- $O(\sqrt{n})$