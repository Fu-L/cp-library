---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/enumerative_combinatrics/binomial_coefficient_prime_mod.test.cpp
    title: verify/library_checker/enumerative_combinatrics/binomial_coefficient_prime_mod.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/binomial.hpp\"\
    \ntemplate <typename mint>\nstruct Binomial {\n    Binomial(int n)\n        :\
    \ fac(n + 1), ifac(n + 1) {\n        fac[0] = 1;\n        for(int i = 1; i <=\
    \ n; ++i) fac[i] = fac[i - 1] * i;\n        ifac[n] = fac[n].inv();\n        for(int\
    \ i = n; i >= 1; --i) ifac[i - 1] = ifac[i] * i;\n    }\n    mint fact(int n)\
    \ const {\n        if(n < 0) return 0;\n        return fac[n];\n    }\n    mint\
    \ perm(int n, int r) const {\n        if(n < 0 or n < r or r < 0) return 0;\n\
    \        return fac[n] * ifac[n - r];\n    }\n    mint comb(int n, int r) const\
    \ {\n        if(n < 0 or n < r or r < 0) return 0;\n        return fac[n] * ifac[n\
    \ - r] * ifac[r];\n    }\n    mint homo(int n, int r) const {\n        if(n <\
    \ 0 or r < 0) return 0;\n        if(r == 0) return 1;\n        return comb(n +\
    \ r - 1, r);\n    }\n    mint operator()(int n, int r) const {\n        return\
    \ comb(n, r);\n    }\n\n   private:\n    vector<mint> fac, ifac;\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename mint>\n\
    struct Binomial {\n    Binomial(int n)\n        : fac(n + 1), ifac(n + 1) {\n\
    \        fac[0] = 1;\n        for(int i = 1; i <= n; ++i) fac[i] = fac[i - 1]\
    \ * i;\n        ifac[n] = fac[n].inv();\n        for(int i = n; i >= 1; --i) ifac[i\
    \ - 1] = ifac[i] * i;\n    }\n    mint fact(int n) const {\n        if(n < 0)\
    \ return 0;\n        return fac[n];\n    }\n    mint perm(int n, int r) const\
    \ {\n        if(n < 0 or n < r or r < 0) return 0;\n        return fac[n] * ifac[n\
    \ - r];\n    }\n    mint comb(int n, int r) const {\n        if(n < 0 or n < r\
    \ or r < 0) return 0;\n        return fac[n] * ifac[n - r] * ifac[r];\n    }\n\
    \    mint homo(int n, int r) const {\n        if(n < 0 or r < 0) return 0;\n \
    \       if(r == 0) return 1;\n        return comb(n + r - 1, r);\n    }\n    mint\
    \ operator()(int n, int r) const {\n        return comb(n, r);\n    }\n\n   private:\n\
    \    vector<mint> fac, ifac;\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/binomial.hpp
  requiredBy: []
  timestamp: '2024-11-09 02:03:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/enumerative_combinatrics/binomial_coefficient_prime_mod.test.cpp
documentation_of: src/math/binomial.hpp
layout: document
title: Binomial
---

# Binomial

- 二項係数 $_n C _k \pmod{p}$

などを計算するアルゴリズムです．

## コンストラクタ

```cpp
Binomial<mint> binom(int N)
```

- `mint` の法 $p$ における $0!$ ~ $N!$ および $(0!)^{-1}$ ~ $(N!)^{-1}$ のテーブルを構築します．

**制約**

- $\forall_{1 \leq i \leq N} ~ \mathrm{gcd} (i, p) = 1$

**計算量**

- $O(N)$

## fact

```cpp
mint binom.fact(int n)
```

$n! \pmod{p}$ を返します．

$n < 0$ の場合は $0$ を返します．

**制約**

- $n \leq N$

**計算量**

- $O(1)$

## perm

```cpp
mint binom.perm(int n, int k)
```

$_n P _k \pmod{p}$ を返します．

$n < 0$ または $n < k$ または $k < 0$ の場合は $0$ を返します．

**制約**

- $n \leq N$

**計算量**

- $O(1)$

## comb, operator ()

```cpp
(1) mint binom.comb(int n, int k)
(2) mint binom(int n, int k)
```

$_n C _k \pmod{p}$ を返します．

$n < 0$ または $n < k$ または $k < 0$ の場合は $0$ を返します．

**制約**

- $n \leq N$

**計算量**

- $O(1)$

## homo

```cpp
mint binom.homo(int n, int k)
```

$_n H _k \pmod{p}$ を返します．

$n < 0$ または $k < 0$ の場合は $0$ を返します．<br>
$k = 0$ の場合は $1$ を返します．

**制約**

- $n + k - 1 \leq N$

**計算量**

- $O(1)$