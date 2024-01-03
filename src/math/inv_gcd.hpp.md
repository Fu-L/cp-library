---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/math/chinese_remainder_theorem.hpp
    title: chinese_remainder_theorem
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/inv_gcd.hpp\"\n\
    constexpr pair<ll, ll> inv_gcd(ll a, ll b) {\n    a %= b;\n    if(a < 0) a +=\
    \ b;\n    if(a == 0) return {b, 0};\n    ll s = b, t = a, m0 = 0, m1 = 1;\n  \
    \  while(t) {\n        const ll u = s / t;\n        s -= t * u;\n        m0 -=\
    \ m1 * u;\n        ll tmp = s;\n        s = t;\n        t = tmp;\n        tmp\
    \ = m0;\n        m0 = m1;\n        m1 = tmp;\n    }\n    if(m0 < 0) m0 += b /\
    \ s;\n    return {s, m0};\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nconstexpr pair<ll, ll>\
    \ inv_gcd(ll a, ll b) {\n    a %= b;\n    if(a < 0) a += b;\n    if(a == 0) return\
    \ {b, 0};\n    ll s = b, t = a, m0 = 0, m1 = 1;\n    while(t) {\n        const\
    \ ll u = s / t;\n        s -= t * u;\n        m0 -= m1 * u;\n        ll tmp =\
    \ s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n        m0 = m1;\n\
    \        m1 = tmp;\n    }\n    if(m0 < 0) m0 += b / s;\n    return {s, m0};\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/inv_gcd.hpp
  requiredBy:
  - src/math/chinese_remainder_theorem.hpp
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
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