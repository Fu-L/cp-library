---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/divisor_multiple_transform.hpp
    title: Divisor/MultipleTransform
  - icon: ':heavy_check_mark:'
    path: src/math/eratosthenes_seive.hpp
    title: EratosthenesSeive
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    \ ++k) g[k] -= g[k * p];\n        }\n    }\n};\n#line 4 \"src/convolution/lcm_convolution.hpp\"\
    \ntemplate <typename mint>\nvector<mint> lcm_convolution(const vector<mint>& a,\
    \ const vector<mint>& b) {\n    assert(a.size() == b.size());\n    auto s = a,\
    \ t = b;\n    DivisorTransform::zeta_transform(s);\n    DivisorTransform::zeta_transform(t);\n\
    \    for(int i = 0; i < (int)a.size(); ++i) s[i] *= t[i];\n    DivisorTransform::moebius_transform(s);\n\
    \    return s;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../math/divisor_multiple_transform.hpp\"\
    \ntemplate <typename mint>\nvector<mint> lcm_convolution(const vector<mint>& a,\
    \ const vector<mint>& b) {\n    assert(a.size() == b.size());\n    auto s = a,\
    \ t = b;\n    DivisorTransform::zeta_transform(s);\n    DivisorTransform::zeta_transform(t);\n\
    \    for(int i = 0; i < (int)a.size(); ++i) s[i] *= t[i];\n    DivisorTransform::moebius_transform(s);\n\
    \    return s;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/divisor_multiple_transform.hpp
  - src/math/eratosthenes_seive.hpp
  isVerificationFile: false
  path: src/convolution/lcm_convolution.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/convolution/lcm_convolution.test.cpp
documentation_of: src/convolution/lcm_convolution.hpp
layout: document
title: lcm_convolution
---

## lcm_convolution

```cpp
vector<T> lcm_convolution(vector<T> a, vector<T> b)
```

LCM畳み込みを行います．<br>
長さ $N$ の数列 $a$ と $b$ から，長さ $N$ の数列，

$$c_k = \sum\limits_{\mathrm{lcm}(i, j) = k} a_i b_j$$

を計算します．

**制約**

- 数列 $a$ と $b$ の長さは等しい．

**計算量**

- $O(N \log \log N)$