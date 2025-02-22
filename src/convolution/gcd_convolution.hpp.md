---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/divisor_multiple_transform.hpp
    title: Divisor/MultipleTransform
  - icon: ':heavy_check_mark:'
    path: src/math/eratosthenes_sieve.hpp
    title: EratosthenesSieve
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/convolution/gcd_convolution.test.cpp
    title: verify/library_checker/convolution/gcd_convolution.test.cpp
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
    \ ++k) g[k] -= g[k * p];\n        }\n    }\n};\n#line 4 \"src/convolution/gcd_convolution.hpp\"\
    \ntemplate <typename mint>\nvector<mint> gcd_convolution(const vector<mint>& a,\
    \ const vector<mint>& b) {\n    assert(a.size() == b.size());\n    auto s = a,\
    \ t = b;\n    MultipleTransform::zeta_transform(s);\n    MultipleTransform::zeta_transform(t);\n\
    \    for(int i = 0; i < (int)a.size(); ++i) s[i] *= t[i];\n    MultipleTransform::moebius_transform(s);\n\
    \    return s;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../math/divisor_multiple_transform.hpp\"\
    \ntemplate <typename mint>\nvector<mint> gcd_convolution(const vector<mint>& a,\
    \ const vector<mint>& b) {\n    assert(a.size() == b.size());\n    auto s = a,\
    \ t = b;\n    MultipleTransform::zeta_transform(s);\n    MultipleTransform::zeta_transform(t);\n\
    \    for(int i = 0; i < (int)a.size(); ++i) s[i] *= t[i];\n    MultipleTransform::moebius_transform(s);\n\
    \    return s;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/divisor_multiple_transform.hpp
  - src/math/eratosthenes_sieve.hpp
  isVerificationFile: false
  path: src/convolution/gcd_convolution.hpp
  requiredBy: []
  timestamp: '2025-02-22 22:56:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/convolution/gcd_convolution.test.cpp
documentation_of: src/convolution/gcd_convolution.hpp
layout: document
title: gcd_convolution
---

## gcd_convolution

```cpp
vector<T> gcd_convolution(vector<T> a, vector<T> b)
```

GCD畳み込みを行います．<br>
長さ $N$ の数列 $a$ と $b$ から，長さ $N$ の数列，

$$c_k = \sum\limits_{\gcd(i, j) = k} a_i b_j$$

を計算します．

**制約**

- 数列 $a$ と $b$ の長さは等しい．

**計算量**

- $O(N \log \log N)$