---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/ntl/extended_euclid_algorithm.test.cpp
    title: verify/aizu_online_judge/ntl/extended_euclid_algorithm.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 2 \"src/math/extgcd.hpp\"\n\
    ll extgcd(ll a, ll b, ll& x, ll& y) {\n    ll d = a;\n    if(b != 0) {\n     \
    \   d = extgcd(b, a % b, y, x);\n        y -= (a / b) * x;\n    } else {\n   \
    \     x = 1;\n        y = 0;\n    }\n    return d;\n}\n"
  code: "#include \"../template/template.hpp\"\nll extgcd(ll a, ll b, ll& x, ll& y)\
    \ {\n    ll d = a;\n    if(b != 0) {\n        d = extgcd(b, a % b, y, x);\n  \
    \      y -= (a / b) * x;\n    } else {\n        x = 1;\n        y = 0;\n    }\n\
    \    return d;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/extgcd.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/ntl/extended_euclid_algorithm.test.cpp
documentation_of: src/math/extgcd.hpp
layout: document
title: extgcd
---

## extgcd

```cpp
ll extgcd(ll a, ll b, ll& x, ll& y)
```

$\mathrm{gcd}(a, b)$ を返します．<br>
副作用として $(x, y)$ に $ax + by = \mathrm{gcd}(a, b)$ を満たす整数解が格納されます．<br>
整数解は無数に存在しますが， $\mathrm{abs}(x) + \mathrm{abs}(y)$ が最小であるものが採用されます．<br>
$\mathrm{abs}(x) + \mathrm{abs}(y)$ が最小であるものが複数存在する場合は，その中で $x \leq y$ であるものが採用されます．

**計算量**

- $O(\log \min(a, b))$