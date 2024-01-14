---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/alds1/prime_numbers.test.cpp
    title: verify/aizu_online_judge/alds1/prime_numbers.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/is_prime.hpp\"\n\
    constexpr bool is_prime(ll n) {\n    if(n <= 1) return false;\n    for(ll i =\
    \ 2; i * i <= n; ++i) {\n        if(n % i == 0) return false;\n    }\n    return\
    \ true;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nconstexpr bool is_prime(ll\
    \ n) {\n    if(n <= 1) return false;\n    for(ll i = 2; i * i <= n; ++i) {\n \
    \       if(n % i == 0) return false;\n    }\n    return true;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/is_prime.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/alds1/prime_numbers.test.cpp
documentation_of: src/math/is_prime.hpp
layout: document
title: is_prime
---

## is_prime

```cpp
bool is_prime(ll n)
```

整数 $n$ が素数であるかどうかを返します．<br>
$n$ が非正の場合は `false` を返します．

**計算量**

- $O(\sqrt{n})$