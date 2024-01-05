---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/zeta_transform.hpp
    title: zeta_transform
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/convolution/bitwise_and_convolution.test.cpp
    title: verify/library_checker/convolution/bitwise_and_convolution.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/zeta_transform.hpp\"\
    \ntemplate <typename T>\nvoid superset_zeta_transform(vector<T>& f, bool inv =\
    \ false) {\n    int n = (int)f.size();\n    assert((n & (n - 1)) == 0);\n    const\
    \ int sign = inv ? -1 : 1;\n    for(int i = 1; i < n; i <<= 1) {\n        for(int\
    \ j = 0; j < n; ++j) {\n            if((j & i) == 0) {\n                f[j] +=\
    \ sign * f[j | i];\n            }\n        }\n    }\n}\ntemplate <typename T>\n\
    void subset_zeta_transform(vector<T>& f, bool inv = false) {\n    int n = (int)f.size();\n\
    \    assert((n & (n - 1)) == 0);\n    const int sign = inv ? -1 : 1;\n    for(int\
    \ i = 1; i < n; i <<= 1) {\n        for(int j = 0; j < n; ++j) {\n           \
    \ if((j & i) == 0) {\n                f[j | i] += f[j];\n            }\n     \
    \   }\n    }\n}\n#line 4 \"src/convolution/and_convolution.hpp\"\ntemplate <typename\
    \ T>\nvector<T> and_convolution(vector<T> a, vector<T> b) {\n    superset_zeta_transform(a);\n\
    \    superset_zeta_transform(b);\n    for(int i = 0; i < (int)a.size(); ++i) a[i]\
    \ *= b[i];\n    superset_zeta_transform(a, true);\n    return a;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../math/zeta_transform.hpp\"\
    \ntemplate <typename T>\nvector<T> and_convolution(vector<T> a, vector<T> b) {\n\
    \    superset_zeta_transform(a);\n    superset_zeta_transform(b);\n    for(int\
    \ i = 0; i < (int)a.size(); ++i) a[i] *= b[i];\n    superset_zeta_transform(a,\
    \ true);\n    return a;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/zeta_transform.hpp
  isVerificationFile: false
  path: src/convolution/and_convolution.hpp
  requiredBy: []
  timestamp: '2024-01-05 00:03:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/convolution/bitwise_and_convolution.test.cpp
documentation_of: src/convolution/and_convolution.hpp
layout: document
title: and_convolution
---

```cpp
vector<T> and_convolution(vector<T> a, vector<T> b)
```

AND畳み込みを行います．<br>
長さ $2^N$ の数列 $a$ と $b$ から，長さ $2^N$ の数列，

$$c_k = \sum\limits_{i \& j = k} a_i b_j$$

を計算します．

**制約**

- 数列 $a$ と $b$ の長さは等しい
- 数列 $a$ と $b$ の長さは $2$ の累乗である．

**計算量**

- $O(2^N N)$