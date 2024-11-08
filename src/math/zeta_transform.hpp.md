---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/and_convolution.hpp
    title: and_convolution
  - icon: ':heavy_check_mark:'
    path: src/convolution/or_convolution.hpp
    title: or_convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/convolution/bitwise_and_convolution.test.cpp
    title: verify/library_checker/convolution/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/convolution/or_convolution.test.cpp
    title: verify/unit_test/convolution/or_convolution.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/zeta_transform.hpp\"\
    \ntemplate <typename T>\nvoid superset_zeta_transform(vector<T>& f, const bool\
    \ inv = false) {\n    const int n = (int)f.size();\n    assert((n & (n - 1)) ==\
    \ 0);\n    const int sign = inv ? -1 : 1;\n    for(int i = 1; i < n; i <<= 1)\
    \ {\n        for(int j = 0; j < n; ++j) {\n            if((j & i) == 0) {\n  \
    \              f[j] += sign * f[j | i];\n            }\n        }\n    }\n}\n\
    template <typename T>\nvoid subset_zeta_transform(vector<T>& f, const bool inv\
    \ = false) {\n    const int n = (int)f.size();\n    assert((n & (n - 1)) == 0);\n\
    \    const int sign = inv ? -1 : 1;\n    for(int i = 1; i < n; i <<= 1) {\n  \
    \      for(int j = 0; j < n; ++j) {\n            if((j & i) == 0) {\n        \
    \        f[j | i] += sign * f[j];\n            }\n        }\n    }\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    void superset_zeta_transform(vector<T>& f, const bool inv = false) {\n    const\
    \ int n = (int)f.size();\n    assert((n & (n - 1)) == 0);\n    const int sign\
    \ = inv ? -1 : 1;\n    for(int i = 1; i < n; i <<= 1) {\n        for(int j = 0;\
    \ j < n; ++j) {\n            if((j & i) == 0) {\n                f[j] += sign\
    \ * f[j | i];\n            }\n        }\n    }\n}\ntemplate <typename T>\nvoid\
    \ subset_zeta_transform(vector<T>& f, const bool inv = false) {\n    const int\
    \ n = (int)f.size();\n    assert((n & (n - 1)) == 0);\n    const int sign = inv\
    \ ? -1 : 1;\n    for(int i = 1; i < n; i <<= 1) {\n        for(int j = 0; j <\
    \ n; ++j) {\n            if((j & i) == 0) {\n                f[j | i] += sign\
    \ * f[j];\n            }\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/zeta_transform.hpp
  requiredBy:
  - src/convolution/or_convolution.hpp
  - src/convolution/and_convolution.hpp
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/convolution/bitwise_and_convolution.test.cpp
  - verify/unit_test/convolution/or_convolution.test.cpp
documentation_of: src/math/zeta_transform.hpp
layout: document
title: zeta_transform
---

## zeta_transform

```cpp
(1) void superset_zeta_transform(vector<T>& f, bool inv = false)
(2) void subset_zeta_transform(vector<T>& f, bool inv = false)
```

長さ $2^N$ の数列 $f$ に対して，

- (1): 上位集合高速ゼータ変換 ( `inv = true` ならばメビウス変換) を計算します．
- (2): 下位集合高速ゼータ変換 ( `inv = true` ならばメビウス変換) を計算します．

上位・下位高速ゼータ変換の定義式は以下の通りで，メビウス変換はその逆変換です．

$$ (1) ~ g_x = \sum\limits_{i \supseteq x} f_i$$

$$ (2) ~ g_x = \sum\limits_{i \subseteq x} f_i$$

**制約**

- 数列 $f$ の長さは $2$ の累乗である．

**計算量**

- $O(2^N N)$