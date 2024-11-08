---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/chinese_remainder_theorem.hpp
    title: chinese_remainder_theorem
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/186.test.cpp
    title: verify/yukicoder/186.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/inv_gcd.hpp\"\
    \nconstexpr pair<long long, long long> inv_gcd(long long a, const long long b)\
    \ {\n    a %= b;\n    if(a < 0) a += b;\n    if(a == 0) return {b, 0};\n    long\
    \ long s = b, t = a, m0 = 0, m1 = 1;\n    while(t) {\n        const long long\
    \ u = s / t;\n        s -= t * u;\n        m0 -= m1 * u;\n        long long tmp\
    \ = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n        m0 = m1;\n\
    \        m1 = tmp;\n    }\n    if(m0 < 0) m0 += b / s;\n    return {s, m0};\n\
    }\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nconstexpr pair<long\
    \ long, long long> inv_gcd(long long a, const long long b) {\n    a %= b;\n  \
    \  if(a < 0) a += b;\n    if(a == 0) return {b, 0};\n    long long s = b, t =\
    \ a, m0 = 0, m1 = 1;\n    while(t) {\n        const long long u = s / t;\n   \
    \     s -= t * u;\n        m0 -= m1 * u;\n        long long tmp = s;\n       \
    \ s = t;\n        t = tmp;\n        tmp = m0;\n        m0 = m1;\n        m1 =\
    \ tmp;\n    }\n    if(m0 < 0) m0 += b / s;\n    return {s, m0};\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/inv_gcd.hpp
  requiredBy:
  - src/math/chinese_remainder_theorem.hpp
  timestamp: '2024-11-09 02:03:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/186.test.cpp
documentation_of: src/math/inv_gcd.hpp
layout: document
title: inv_gcd
---

## inv_gcd

```cpp
pair<ll, ll> inv_gcd(ll a, ll m)
```

$\mathrm{gcd} (a, m)$ と $a^{-1} \pmod{m}$ を返します．

$\mathrm{gcd} (a, m) = 1$ でない場合，動作はしますが逆元は (存在しないので) 正しく計算できていないことに注意してください．

**制約**

- $0 \leq a$
- $1 \leq m$

**計算量**

- $O(\log m)$