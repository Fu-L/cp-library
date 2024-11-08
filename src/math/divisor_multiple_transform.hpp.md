---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/eratosthenes_seive.hpp
    title: EratosthenesSeive
  - icon: ':question:'
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/eratosthenes_seive.hpp\"\
    \nstruct EratosthenesSeive {\n    vector<int> primes, min_factor, moebius, euler;\n\
    \    EratosthenesSeive(const int n)\n        : primes(), min_factor(n + 1), moebius(n\
    \ + 1, 1), euler(n + 1) {\n        assert(n >= 1);\n        iota(min_factor.begin(),\
    \ min_factor.end(), 0);\n        min_factor[0] = min_factor[1] = -1;\n       \
    \ iota(euler.begin(), euler.end(), 0);\n        for(int i = 2; i <= n; ++i) {\n\
    \            if(min_factor[i] < i) continue;\n            primes.emplace_back(i);\n\
    \            moebius[i] = -1;\n            euler[i] = euler[i] / i * (i - 1);\n\
    \            for(int j = i * 2; j <= n; j += i) {\n                if(min_factor[j]\
    \ == j) min_factor[j] = i;\n                if((j / i) % i == 0) moebius[j] =\
    \ 0;\n                else moebius[j] = -moebius[j];\n                euler[j]\
    \ = euler[j] / i * (i - 1);\n            }\n        }\n    }\n};\n#line 4 \"src/math/divisor_multiple_transform.hpp\"\
    \nstruct DivisorTransform {\n    template <typename T>\n    static void zeta_transform(vector<T>&\
    \ f) {\n        const int N = f.size() - 1;\n        const auto sieve = EratosthenesSeive(N).primes;\n\
    \        for(const auto& p : sieve) {\n            for(int k = 1; k * p <= N;\
    \ ++k) f[k * p] += f[k];\n        }\n    }\n    template <typename T>\n    static\
    \ void moebius_transform(vector<T>& g) {\n        const int N = g.size() - 1;\n\
    \        const auto sieve = EratosthenesSeive(N).primes;\n        for(const auto&\
    \ p : sieve) {\n            for(int k = N / p; k > 0; --k) g[k * p] -= g[k];\n\
    \        }\n    }\n};\nstruct MultipleTransform {\n    template <typename T>\n\
    \    static void zeta_transform(vector<T>& f) {\n        const int N = f.size()\
    \ - 1;\n        const auto sieve = EratosthenesSeive(N).primes;\n        for(const\
    \ auto& p : sieve) {\n            for(int k = N / p; k > 0; --k) f[k] += f[k *\
    \ p];\n        }\n    }\n    template <typename T>\n    static void moebius_transform(vector<T>&\
    \ g) {\n        const int N = g.size() - 1;\n        const auto sieve = EratosthenesSeive(N).primes;\n\
    \        for(const auto& p : sieve) {\n            for(int k = 1; k * p <= N;\
    \ ++k) g[k] -= g[k * p];\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./eratosthenes_seive.hpp\"\
    \nstruct DivisorTransform {\n    template <typename T>\n    static void zeta_transform(vector<T>&\
    \ f) {\n        const int N = f.size() - 1;\n        const auto sieve = EratosthenesSeive(N).primes;\n\
    \        for(const auto& p : sieve) {\n            for(int k = 1; k * p <= N;\
    \ ++k) f[k * p] += f[k];\n        }\n    }\n    template <typename T>\n    static\
    \ void moebius_transform(vector<T>& g) {\n        const int N = g.size() - 1;\n\
    \        const auto sieve = EratosthenesSeive(N).primes;\n        for(const auto&\
    \ p : sieve) {\n            for(int k = N / p; k > 0; --k) g[k * p] -= g[k];\n\
    \        }\n    }\n};\nstruct MultipleTransform {\n    template <typename T>\n\
    \    static void zeta_transform(vector<T>& f) {\n        const int N = f.size()\
    \ - 1;\n        const auto sieve = EratosthenesSeive(N).primes;\n        for(const\
    \ auto& p : sieve) {\n            for(int k = N / p; k > 0; --k) f[k] += f[k *\
    \ p];\n        }\n    }\n    template <typename T>\n    static void moebius_transform(vector<T>&\
    \ g) {\n        const int N = g.size() - 1;\n        const auto sieve = EratosthenesSeive(N).primes;\n\
    \        for(const auto& p : sieve) {\n            for(int k = 1; k * p <= N;\
    \ ++k) g[k] -= g[k * p];\n        }\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  - src/math/eratosthenes_seive.hpp
  isVerificationFile: false
  path: src/math/divisor_multiple_transform.hpp
  requiredBy:
  - src/convolution/lcm_convolution.hpp
  - src/convolution/gcd_convolution.hpp
  timestamp: '2024-11-09 01:34:39+09:00'
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