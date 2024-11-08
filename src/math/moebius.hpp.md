---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/math/prime_factors.hpp
    title: prime_factors
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/unit_test/math/eratosthenes_seive.test.cpp
    title: verify/unit_test/math/eratosthenes_seive.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/prime_factors.hpp\"\
    \nvector<pair<long long, int>> prime_factors(long long n) {\n    assert(n >= 1);\n\
    \    vector<pair<long long, int>> res;\n    for(long long i = 2; i * i <= n; ++i)\
    \ {\n        if(n % i == 0) {\n            res.emplace_back(i, 0);\n         \
    \   while(n % i == 0) {\n                n /= i;\n                ++res.back().second;\n\
    \            }\n        }\n    }\n    if(n >= 2) res.emplace_back(n, 1);\n   \
    \ return res;\n}\n#line 4 \"src/math/moebius.hpp\"\nint moebius(const long long\
    \ n) {\n    assert(n >= 1);\n    if(n == 1) return 1;\n    vector<pair<long long,\
    \ int>> p = prime_factors(n);\n    int res = 1;\n    for(const auto& it : p) {\n\
    \        if(it.second >= 2) return 0;\n        res = -res;\n    }\n    return\
    \ res;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./prime_factors.hpp\"\
    \nint moebius(const long long n) {\n    assert(n >= 1);\n    if(n == 1) return\
    \ 1;\n    vector<pair<long long, int>> p = prime_factors(n);\n    int res = 1;\n\
    \    for(const auto& it : p) {\n        if(it.second >= 2) return 0;\n       \
    \ res = -res;\n    }\n    return res;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/prime_factors.hpp
  isVerificationFile: false
  path: src/math/moebius.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/unit_test/math/eratosthenes_seive.test.cpp
documentation_of: src/math/moebius.hpp
layout: document
title: moebius
---

## moebius

```cpp
int moebius(ll n)
```

メビウス関数値 $\mu(n)$ を返します．

**制約**

- $1 \leq n$

**計算量**

- $O(\sqrt{n})$