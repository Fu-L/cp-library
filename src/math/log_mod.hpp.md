---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/policy_based_data_structure.hpp
    title: policy_based_data_structure
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/math/discrete_logarithm.test.cpp
    title: verify/library_checker/math/discrete_logarithm.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 2 \"src/template/policy_based_data_structure.hpp\"\
    \n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    #include <ext/pb_ds/tag_and_trait.hpp>\nusing namespace __gnu_pbds;\n#line 4 \"\
    src/math/log_mod.hpp\"\nll log_mod(ll a, ll b, ll mod) {\n    assert(mod >= 1);\n\
    \    ll g = 1;\n    for(ll i = mod; i; i /= 2) (g *= a) %= mod;\n    g = gcd(g,\
    \ mod);\n    ll t = 1, c = 0;\n    for(; t % g; ++c) {\n        if(t == b) return\
    \ c;\n        (t *= a) %= mod;\n    }\n    if(b % g) return -1;\n    t /= g;\n\
    \    b /= g;\n    ll n = mod / g, h = 0, gs = 1;\n    for(; h * h < n; ++h) (gs\
    \ *= a) %= n;\n    gp_hash_table<ll, ll> ht;\n    for(ll s = 0, e = b; s < h;\
    \ ht[e] = ++s) {\n        (e *= a) %= n;\n    }\n    for(ll s = 0, e = t; s <\
    \ n;) {\n        (e *= gs) %= n;\n        s += h;\n        if(ht.find(e) != ht.end())\
    \ return c + s - ht[e];\n    }\n    return -1;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../template/policy_based_data_structure.hpp\"\
    \nll log_mod(ll a, ll b, ll mod) {\n    assert(mod >= 1);\n    ll g = 1;\n   \
    \ for(ll i = mod; i; i /= 2) (g *= a) %= mod;\n    g = gcd(g, mod);\n    ll t\
    \ = 1, c = 0;\n    for(; t % g; ++c) {\n        if(t == b) return c;\n       \
    \ (t *= a) %= mod;\n    }\n    if(b % g) return -1;\n    t /= g;\n    b /= g;\n\
    \    ll n = mod / g, h = 0, gs = 1;\n    for(; h * h < n; ++h) (gs *= a) %= n;\n\
    \    gp_hash_table<ll, ll> ht;\n    for(ll s = 0, e = b; s < h; ht[e] = ++s) {\n\
    \        (e *= a) %= n;\n    }\n    for(ll s = 0, e = t; s < n;) {\n        (e\
    \ *= gs) %= n;\n        s += h;\n        if(ht.find(e) != ht.end()) return c +\
    \ s - ht[e];\n    }\n    return -1;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/policy_based_data_structure.hpp
  isVerificationFile: false
  path: src/math/log_mod.hpp
  requiredBy: []
  timestamp: '2024-01-07 03:22:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/math/discrete_logarithm.test.cpp
documentation_of: src/math/log_mod.hpp
layout: document
title: log_mod
---

## log_mod

```cpp
ll log_mod(ll a, ll b, ll mod)
```

$a^x \equiv b \pmod{\mathrm{mod}}$ を満たす非負整数 $x$ の最小値を返します．<br>
存在しない場合は $-1$ を返します．

**制約**

- $1 \leq \mathrm{mod}$

**計算量**

- $O(\sqrt{mod})$