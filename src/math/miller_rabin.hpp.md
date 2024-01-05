---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/math/primality_test.test.cpp
    title: verify/library_checker/math/primality_test.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/miller_rabin.hpp\"\
    \nconstexpr __int128_t pow_mod_128(__int128_t x, __int128_t n, __int128_t mod)\
    \ {\n    assert(n >= 0 and mod >= 1);\n    x %= mod;\n    if(x < 0) x += mod;\n\
    \    __int128_t res = 1;\n    while(n > 0) {\n        if(n & 1) res = res * x\
    \ % mod;\n        x = x * x % mod;\n        n >>= 1;\n    }\n    return res;\n\
    }\nconstexpr bool miller_rabin(ll n) {\n    if(n <= 2) return n == 2;\n    if(n\
    \ % 2 == 0) return false;\n    constexpr ll bases[7] = {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022};\n    ll d = n - 1;\n    while(d % 2 == 0) d /= 2;\n  \
    \  ll e = 1, rev = n - 1;\n    for(const ll& base : bases) {\n        if(base\
    \ % n == 0) continue;\n        ll t = d;\n        ll y = pow_mod_128(base, t,\
    \ n);\n        while(t != n - 1 and y != e and y != rev) {\n            y = (__int128_t)y\
    \ * y % n;\n            t *= 2;\n        }\n        if(y != rev and t % 2 == 0)\
    \ return false;\n    }\n    return true;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nconstexpr __int128_t\
    \ pow_mod_128(__int128_t x, __int128_t n, __int128_t mod) {\n    assert(n >= 0\
    \ and mod >= 1);\n    x %= mod;\n    if(x < 0) x += mod;\n    __int128_t res =\
    \ 1;\n    while(n > 0) {\n        if(n & 1) res = res * x % mod;\n        x =\
    \ x * x % mod;\n        n >>= 1;\n    }\n    return res;\n}\nconstexpr bool miller_rabin(ll\
    \ n) {\n    if(n <= 2) return n == 2;\n    if(n % 2 == 0) return false;\n    constexpr\
    \ ll bases[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n    ll d\
    \ = n - 1;\n    while(d % 2 == 0) d /= 2;\n    ll e = 1, rev = n - 1;\n    for(const\
    \ ll& base : bases) {\n        if(base % n == 0) continue;\n        ll t = d;\n\
    \        ll y = pow_mod_128(base, t, n);\n        while(t != n - 1 and y != e\
    \ and y != rev) {\n            y = (__int128_t)y * y % n;\n            t *= 2;\n\
    \        }\n        if(y != rev and t % 2 == 0) return false;\n    }\n    return\
    \ true;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/miller_rabin.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/math/primality_test.test.cpp
documentation_of: src/math/miller_rabin.hpp
layout: document
title: miller_rabin
---

## miller_rabin

```cpp
bool miller_rabin(ll n)
```

整数 $n$ が素数であるか判定します．<br>
$n$ が非正の場合は `false` を返します．

**計算量**

- $O(\log n)$