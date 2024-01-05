---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/lucas.hpp\"\ntemplate\
    \ <typename mint>\nstruct Lucas {\n    Lucas()\n        : mod(mint::mod()), fact(mint::mod()),\
    \ ifact(mint::mod()) {\n        fact[0] = 1;\n        for(int i = 1; i < mod;\
    \ ++i) fact[i] = fact[i - 1] * i;\n        ifact[mod - 1] = fact[mod - 1].inv();\n\
    \        for(int i = mod - 1; i >= 1; --i) ifact[i - 1] = ifact[i] * i;\n    }\n\
    \    mint operator()(long long n, long long k) {\n        if(n < 0 or n < k or\
    \ k < 0) return 0;\n        mint res = 1;\n        while(n > 0) {\n          \
    \  long long n0 = n % mod, k0 = k % mod;\n            if(n0 < k0) return 0;\n\
    \            res *= fact[n0] * ifact[k0] * ifact[n0 - k0];\n            n /= mod;\n\
    \            k /= mod;\n        }\n        return res;\n    }\n\n   private:\n\
    \    int mod;\n    vector<mint> fact, ifact;\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename mint>\n\
    struct Lucas {\n    Lucas()\n        : mod(mint::mod()), fact(mint::mod()), ifact(mint::mod())\
    \ {\n        fact[0] = 1;\n        for(int i = 1; i < mod; ++i) fact[i] = fact[i\
    \ - 1] * i;\n        ifact[mod - 1] = fact[mod - 1].inv();\n        for(int i\
    \ = mod - 1; i >= 1; --i) ifact[i - 1] = ifact[i] * i;\n    }\n    mint operator()(long\
    \ long n, long long k) {\n        if(n < 0 or n < k or k < 0) return 0;\n    \
    \    mint res = 1;\n        while(n > 0) {\n            long long n0 = n % mod,\
    \ k0 = k % mod;\n            if(n0 < k0) return 0;\n            res *= fact[n0]\
    \ * ifact[k0] * ifact[n0 - k0];\n            n /= mod;\n            k /= mod;\n\
    \        }\n        return res;\n    }\n\n   private:\n    int mod;\n    vector<mint>\
    \ fact, ifact;\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/lucas.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/lucas.hpp
layout: document
title: Lucas
---

# Lucas

- 二項係数 $_n C _k \pmod{p}$

などを計算するアルゴリズムです．

$p$ が素数でさえあれば $n > p$ の場合でも正しく計算できることが特徴です．

## コンストラクタ

```cpp
Lucas<mint> binom
```

- `mint` の法 $p$ における $0!$ ~ $(p - 1)!$ および $(0!)^{-1}$ ~ $((p - 1)!)^{-1}$ のテーブルを構築します．

**制約**

- $p$ は素数

**計算量**

- $O(p)$

## operator ()

```cpp
mint binom(ll n, ll k)
```

$_n C _k \pmod{p}$ を計算します．

$n < 0$ または $n < k$ または $k < 0$ の場合は $0$ を返します．

**計算量**

- $O(\log_p n)$