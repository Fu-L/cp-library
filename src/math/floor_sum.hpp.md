---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number_theory/sum_of_floor_of_linear.test.cpp
    title: verify/library_checker/number_theory/sum_of_floor_of_linear.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/floor_sum.hpp\"\
    \nconstexpr long long floor_sum(const long long n, const long long m, long long\
    \ a, long long b) {\n    long long res = 0;\n    if(a >= m) res += (n - 1) * n\
    \ * (a / m) / 2, a %= m;\n    if(b >= m) res += n * (b / m), b %= m;\n    const\
    \ long long y = (a * n + b) / m;\n    if(y == 0) return res;\n    const long long\
    \ x = y * m - b;\n    res += (n - (x + a - 1) / a) * y;\n    res += floor_sum(y,\
    \ a, m, (a - x % a) % a);\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nconstexpr long long\
    \ floor_sum(const long long n, const long long m, long long a, long long b) {\n\
    \    long long res = 0;\n    if(a >= m) res += (n - 1) * n * (a / m) / 2, a %=\
    \ m;\n    if(b >= m) res += n * (b / m), b %= m;\n    const long long y = (a *\
    \ n + b) / m;\n    if(y == 0) return res;\n    const long long x = y * m - b;\n\
    \    res += (n - (x + a - 1) / a) * y;\n    res += floor_sum(y, a, m, (a - x %\
    \ a) % a);\n    return res;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/floor_sum.hpp
  requiredBy: []
  timestamp: '2024-11-09 02:03:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/number_theory/sum_of_floor_of_linear.test.cpp
documentation_of: src/math/floor_sum.hpp
layout: document
title: floor_sum
---

## floor_sum

```cpp
ll floor_sum(ll n, ll m, ll a, ll b)
```

$$\sum_{i = 0}^{n - 1} \left\lfloor \frac{a \times i + b}{m} \right\rfloor$$

を返します．

**制約**

- $0 \leq n \leq 10^9$
- $1 \leq m \leq 10^9$
- 答えがオーバーフローしないこと．

**計算量**

- $O(\log (n + m + a + b))$