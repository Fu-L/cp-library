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
  - icon: ':warning:'
    path: src/convolution/or_convolution.hpp
    title: or_convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/math/and_convolution.test.cpp
    title: verify/library_checker/math/and_convolution.test.cpp
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
    \ true) {\n    int n = (int)f.size();\n    assert((n & (n - 1)) == 0);\n    const\
    \ int sign = inv ? 1 : -1;\n    for(int i = 1; i < n; i <<= 1) {\n        for(int\
    \ j = 0; j < n; ++j) {\n            if((j & i) == 0) {\n                f[j] +=\
    \ sign * f[j | i];\n            }\n        }\n    }\n}\ntemplate <typename T>\n\
    void subset_zeta_transform(vector<T>& f, bool inv = true) {\n    int n = (int)f.size();\n\
    \    assert((n & (n - 1)) == 0);\n    const int sign = inv ? 1 : -1;\n    for(int\
    \ i = 1; i < n; i <<= 1) {\n        for(int j = 0; j < n; ++j) {\n           \
    \ if((j & i) == 0) {\n                f[j | i] += f[j];\n            }\n     \
    \   }\n    }\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    void superset_zeta_transform(vector<T>& f, bool inv = true) {\n    int n = (int)f.size();\n\
    \    assert((n & (n - 1)) == 0);\n    const int sign = inv ? 1 : -1;\n    for(int\
    \ i = 1; i < n; i <<= 1) {\n        for(int j = 0; j < n; ++j) {\n           \
    \ if((j & i) == 0) {\n                f[j] += sign * f[j | i];\n            }\n\
    \        }\n    }\n}\ntemplate <typename T>\nvoid subset_zeta_transform(vector<T>&\
    \ f, bool inv = true) {\n    int n = (int)f.size();\n    assert((n & (n - 1))\
    \ == 0);\n    const int sign = inv ? 1 : -1;\n    for(int i = 1; i < n; i <<=\
    \ 1) {\n        for(int j = 0; j < n; ++j) {\n            if((j & i) == 0) {\n\
    \                f[j | i] += f[j];\n            }\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/zeta_transform.hpp
  requiredBy:
  - src/convolution/or_convolution.hpp
  - src/convolution/and_convolution.hpp
  timestamp: '2024-01-04 23:45:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/math/and_convolution.test.cpp
documentation_of: src/math/zeta_transform.hpp
layout: document
title: zeta_transform
---
