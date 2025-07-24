---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/eratosthenes_sieve.hpp
    title: EratosthenesSieve
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/gcd_convolution.hpp
    title: gcd_convolution
  - icon: ':heavy_check_mark:'
    path: src/convolution/lcm_convolution.hpp
    title: lcm_convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/convolution/gcd_convolution.test.cpp
    title: verify/library_checker/convolution/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/convolution/lcm_convolution.test.cpp
    title: verify/library_checker/convolution/lcm_convolution.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/eratosthenes_sieve.hpp\"\
    \nstruct EratosthenesSieve {\n    vector<int> primes, min_factor, moebius, euler;\n\
    \    EratosthenesSieve(const int N)\n        : primes(), min_factor(N + 1), moebius(N\
    \ + 1, 1), euler(N + 1), N(N) {\n        assert(N >= 1);\n        iota(min_factor.begin(),\
    \ min_factor.end(), 0);\n        min_factor[0] = min_factor[1] = -1;\n       \
    \ iota(euler.begin(), euler.end(), 0);\n        for(int i = 2; i <= N; ++i) {\n\
    \            if(min_factor[i] < i) continue;\n            primes.emplace_back(i);\n\
    \            moebius[i] = -1;\n            euler[i] = euler[i] / i * (i - 1);\n\
    \            for(int j = i * 2; j <= N; j += i) {\n                if(min_factor[j]\
    \ == j) min_factor[j] = i;\n                if((j / i) % i == 0) moebius[j] =\
    \ 0;\n                else moebius[j] = -moebius[j];\n                euler[j]\
    \ = euler[j] / i * (i - 1);\n            }\n        }\n    }\n    vector<pair<int,\
    \ int>> prime_factors(int n) const {\n        assert(1 <= n and n <= N);\n   \
    \     vector<pair<int, int>> res;\n        while(n > 1) {\n            const int\
    \ p = min_factor[n];\n            int exp = 0;\n            while(min_factor[n]\
    \ == p) {\n                n /= p;\n                ++exp;\n            }\n  \
    \          res.emplace_back(p, exp);\n        }\n        return res;\n    }\n\
    \    vector<int> divisor(const int n) const {\n        assert(1 <= n and n <=\
    \ n);\n        vector<int> res({1});\n        const auto pf = prime_factors(n);\n\
    \        for(const auto& p : pf) {\n            const int s = (int)res.size();\n\
    \            for(int i = 0; i < s; ++i) {\n                int v = 1;\n      \
    \          for(int j = 0; j < p.second; ++j) {\n                    v *= p.first;\n\
    \                    res.push_back(res[i] * v);\n                }\n         \
    \   }\n        }\n        sort(res.begin(), res.end());\n        return res;\n\
    \    }\n\n   private:\n    int N;\n};\n#line 4 \"src/math/divisor_multiple_transform.hpp\"\
    \nstruct DivisorTransform {\n    template <typename T>\n    static void zeta_transform(vector<T>&\
    \ f) {\n        const int N = f.size() - 1;\n        const auto sieve = EratosthenesSieve(N).primes;\n\
    \        for(const auto& p : sieve) {\n            for(int k = 1; k * p <= N;\
    \ ++k) f[k * p] += f[k];\n        }\n    }\n    template <typename T>\n    static\
    \ void moebius_transform(vector<T>& g) {\n        const int N = g.size() - 1;\n\
    \        const auto sieve = EratosthenesSieve(N).primes;\n        for(const auto&\
    \ p : sieve) {\n            for(int k = N / p; k > 0; --k) g[k * p] -= g[k];\n\
    \        }\n    }\n};\nstruct MultipleTransform {\n    template <typename T>\n\
    \    static void zeta_transform(vector<T>& f) {\n        const int N = f.size()\
    \ - 1;\n        const auto sieve = EratosthenesSieve(N).primes;\n        for(const\
    \ auto& p : sieve) {\n            for(int k = N / p; k > 0; --k) f[k] += f[k *\
    \ p];\n        }\n    }\n    template <typename T>\n    static void moebius_transform(vector<T>&\
    \ g) {\n        const int N = g.size() - 1;\n        const auto sieve = EratosthenesSieve(N).primes;\n\
    \        for(const auto& p : sieve) {\n            for(int k = 1; k * p <= N;\
    \ ++k) g[k] -= g[k * p];\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./eratosthenes_sieve.hpp\"\
    \nstruct DivisorTransform {\n    template <typename T>\n    static void zeta_transform(vector<T>&\
    \ f) {\n        const int N = f.size() - 1;\n        const auto sieve = EratosthenesSieve(N).primes;\n\
    \        for(const auto& p : sieve) {\n            for(int k = 1; k * p <= N;\
    \ ++k) f[k * p] += f[k];\n        }\n    }\n    template <typename T>\n    static\
    \ void moebius_transform(vector<T>& g) {\n        const int N = g.size() - 1;\n\
    \        const auto sieve = EratosthenesSieve(N).primes;\n        for(const auto&\
    \ p : sieve) {\n            for(int k = N / p; k > 0; --k) g[k * p] -= g[k];\n\
    \        }\n    }\n};\nstruct MultipleTransform {\n    template <typename T>\n\
    \    static void zeta_transform(vector<T>& f) {\n        const int N = f.size()\
    \ - 1;\n        const auto sieve = EratosthenesSieve(N).primes;\n        for(const\
    \ auto& p : sieve) {\n            for(int k = N / p; k > 0; --k) f[k] += f[k *\
    \ p];\n        }\n    }\n    template <typename T>\n    static void moebius_transform(vector<T>&\
    \ g) {\n        const int N = g.size() - 1;\n        const auto sieve = EratosthenesSieve(N).primes;\n\
    \        for(const auto& p : sieve) {\n            for(int k = 1; k * p <= N;\
    \ ++k) g[k] -= g[k * p];\n        }\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  - src/math/eratosthenes_sieve.hpp
  isVerificationFile: false
  path: src/math/divisor_multiple_transform.hpp
  requiredBy:
  - src/convolution/lcm_convolution.hpp
  - src/convolution/gcd_convolution.hpp
  timestamp: '2025-02-22 22:56:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/convolution/gcd_convolution.test.cpp
  - verify/library_checker/convolution/lcm_convolution.test.cpp
documentation_of: src/math/divisor_multiple_transform.hpp
layout: document
title: Divisor/MultipleTransform
---

# DivisorTransform

```cpp
(1) void DivisorTransform::zeta_transform(vector<T>& f)
(2) void DivisorTransform::moebius_transform(vector<T>& g)
```

約数系ゼータ/メビウス変換を行います．

$$g(n) = \sum_{d | n} f(d)$$

という関係式を満たす関数 $f(n)$ と $g(n)$ を考えます．<br>
ただし $d | n$ とは， $d$ が $n$ の約数であるという意味です．

約数系ゼータ変換とは， $f(1), f(2), \dots, f(N)$ が与えられたときに $g(n)$ を計算するアルゴリズムです．<br>
約数系メビウス変換とは， $g(1), g(2), \dots, g(N)$ が与えられたときに $f(n)$ を計算するアルゴリズムです．

**計算量**

- $O(N \log \log N)$

# MultipleTransform

```cpp
(1) void MultipleTransform::zeta_transform(vector<T>& f)
(2) void MultipleTransform::moebius_transform(vector<T>& g)
```

倍数系ゼータ/メビウス変換を行います．

$$g(n) = \sum_{n | i} f(i)$$

という関係式を満たす関数 $f(n)$ と $g(n)$ を考えます．<br>
ただし $n | i$ とは， $i$ が $n$ の倍数であるという意味です．

倍数系ゼータ変換とは， $f(1), f(2), \dots, f(N)$ が与えられたときに $g(n)$ を計算するアルゴリズムです．<br>
倍数系メビウス変換とは， $g(1), g(2), \dots, g(N)$ が与えられたときに $f(n)$ を計算するアルゴリズムです．

**計算量**

- $O(N \log \log N)$