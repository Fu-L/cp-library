---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/ntl/eulers_phi_function.test.cpp
    title: verify/aizu_online_judge/ntl/eulers_phi_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/eratosthenes_seive.test.cpp
    title: verify/unit_test/math/eratosthenes_seive.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/euler_phi.hpp\"\
    \nlong long euler_phi(long long n) {\n    long long res = max(n, 0ll);\n    for(long\
    \ long i = 2; i * i <= n; ++i) {\n        if(n % i == 0) {\n            res -=\
    \ res / i;\n            while(n % i == 0) n /= i;\n        }\n    }\n    if(n\
    \ > 1) res -= res / n;\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nlong long euler_phi(long\
    \ long n) {\n    long long res = max(n, 0ll);\n    for(long long i = 2; i * i\
    \ <= n; ++i) {\n        if(n % i == 0) {\n            res -= res / i;\n      \
    \      while(n % i == 0) n /= i;\n        }\n    }\n    if(n > 1) res -= res /\
    \ n;\n    return res;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/euler_phi.hpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/eratosthenes_seive.test.cpp
  - verify/aizu_online_judge/ntl/eulers_phi_function.test.cpp
documentation_of: src/math/euler_phi.hpp
layout: document
title: euler_phi
---

## euler_phi

```cpp
ll euler_phi(ll n)
```

$n$ と互いに素な正の整数の個数を返します．

テーブルが必要な場合は，以下の式に従ってエラトステネスの篩のように計算するとよいです．

$\phi (n) = n \prod\limits_i (1 - \frac{1}{p_i})$ ( $p_i$ は $n$ の素因数)

**計算量**

- $O(\sqrt{n})$