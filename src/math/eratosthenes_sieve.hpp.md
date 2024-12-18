---
data:
  _extendedDependsOn:
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
  - icon: ':heavy_check_mark:'
    path: src/math/divisor_multiple_transform.hpp
    title: Divisor/MultipleTransform
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
    title: verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/convolution/gcd_convolution.test.cpp
    title: verify/library_checker/convolution/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/convolution/lcm_convolution.test.cpp
    title: verify/library_checker/convolution/lcm_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/eratosthenes_sieve.test.cpp
    title: verify/unit_test/math/eratosthenes_sieve.test.cpp
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
    \    EratosthenesSieve(const int n)\n        : primes(), min_factor(n + 1), moebius(n\
    \ + 1, 1), euler(n + 1) {\n        assert(n >= 1);\n        iota(min_factor.begin(),\
    \ min_factor.end(), 0);\n        min_factor[0] = min_factor[1] = -1;\n       \
    \ iota(euler.begin(), euler.end(), 0);\n        for(int i = 2; i <= n; ++i) {\n\
    \            if(min_factor[i] < i) continue;\n            primes.emplace_back(i);\n\
    \            moebius[i] = -1;\n            euler[i] = euler[i] / i * (i - 1);\n\
    \            for(int j = i * 2; j <= n; j += i) {\n                if(min_factor[j]\
    \ == j) min_factor[j] = i;\n                if((j / i) % i == 0) moebius[j] =\
    \ 0;\n                else moebius[j] = -moebius[j];\n                euler[j]\
    \ = euler[j] / i * (i - 1);\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nstruct EratosthenesSieve\
    \ {\n    vector<int> primes, min_factor, moebius, euler;\n    EratosthenesSieve(const\
    \ int n)\n        : primes(), min_factor(n + 1), moebius(n + 1, 1), euler(n +\
    \ 1) {\n        assert(n >= 1);\n        iota(min_factor.begin(), min_factor.end(),\
    \ 0);\n        min_factor[0] = min_factor[1] = -1;\n        iota(euler.begin(),\
    \ euler.end(), 0);\n        for(int i = 2; i <= n; ++i) {\n            if(min_factor[i]\
    \ < i) continue;\n            primes.emplace_back(i);\n            moebius[i]\
    \ = -1;\n            euler[i] = euler[i] / i * (i - 1);\n            for(int j\
    \ = i * 2; j <= n; j += i) {\n                if(min_factor[j] == j) min_factor[j]\
    \ = i;\n                if((j / i) % i == 0) moebius[j] = 0;\n               \
    \ else moebius[j] = -moebius[j];\n                euler[j] = euler[j] / i * (i\
    \ - 1);\n            }\n        }\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/eratosthenes_sieve.hpp
  requiredBy:
  - src/convolution/lcm_convolution.hpp
  - src/convolution/gcd_convolution.hpp
  - src/math/divisor_multiple_transform.hpp
  timestamp: '2024-12-18 16:39:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/eratosthenes_sieve.test.cpp
  - verify/library_checker/convolution/lcm_convolution.test.cpp
  - verify/library_checker/convolution/gcd_convolution.test.cpp
  - verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
documentation_of: src/math/eratosthenes_sieve.hpp
layout: document
title: EratosthenesSieve
---

# EratosthenesSieve

```cpp
EratosthenesSieve sieve(int n)
```

$n$ 以下の正の整数に対してエラトステネスの篩を行います．

## メンバ変数

```cpp
(1) vector<int> sieve.primes
(2) vector<int> sieve.min_factor
(3) vector<int> sieve.moebius
(4) vector<int> sieve.euler
```

- (1): $n$ 以下の素数が昇順に格納されています．
- (2): `sieve.min_factor[i]` に $i$ の素因数の最小値が格納された，長さ $n + 1$ の配列です．<br>
便宜上 `min_factor[0] = min_factor[1] = -1` としています．<br>
$i$ が素数であることと `min_factor[i] = i` であることは同値です．<br>
また以下のようにして，前計算 $O(n \log \log n)$ クエリ $O(\log n)$ で $n$ を素因数分解できます．

```cpp
vector<int> prime_factor;
while(n > 1) {
    prime_factor.push_back(min_factor[n])
    n /= min_factor[n];
}
```

- (3): `sieve.moebius[i]` に $\mu(i)$ が格納された，長さ $n + 1$ の配列です．
- (4): `sieve.euler[i]` に $\phi(i)$ が格納された，長さ $n + 1$ の配列です．

**制約**

- $1 \leq n$

**計算量**

- $O(n \log \log n)$