---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/itp1/how_many_divisors.test.cpp
    title: verify/aizu_online_judge/itp1/how_many_divisors.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/divisor.hpp\"\n\
    vector<ll> divisor(ll n) {\n    assert(n >= 1);\n    vector<ll> res;\n    for(ll\
    \ i = 1; i * i <= n; ++i) {\n        if(n % i == 0) {\n            res.push_back(i);\n\
    \            if(i * i != n) res.push_back(n / i);\n        }\n    }\n    sort(res.begin(),\
    \ res.end());\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nvector<ll> divisor(ll\
    \ n) {\n    assert(n >= 1);\n    vector<ll> res;\n    for(ll i = 1; i * i <= n;\
    \ ++i) {\n        if(n % i == 0) {\n            res.push_back(i);\n          \
    \  if(i * i != n) res.push_back(n / i);\n        }\n    }\n    sort(res.begin(),\
    \ res.end());\n    return res;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/divisor.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/itp1/how_many_divisors.test.cpp
documentation_of: src/math/divisor.hpp
layout: document
title: divisor
---

## divisor

```cpp
vector<ll> divisor(ll n)
```

正整数 $n$ の正の約数を昇順に返します．

**制約**

- $1 \leq n$

**計算量**

- $O(\sqrt{n})$