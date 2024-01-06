---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/xor_convolution.hpp
    title: xor_convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/convolution/bitwise_xor_convolution.test.cpp
    title: verify/library_checker/convolution/bitwise_xor_convolution.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/walsh_hadamard_transform.hpp\"\
    \ntemplate <typename T>\nvoid walsh_hadamard_transform(vector<T>& f, bool inv\
    \ = false) {\n    int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for(int\
    \ i = 1; i < n; i <<= 1) {\n        for(int j = 0; j < n; ++j) {\n           \
    \ if((j & i) == 0) {\n                T x = f[j], y = f[j | i];\n            \
    \    f[j] = x + y, f[j | i] = x - y;\n            }\n        }\n    }\n    if(inv)\
    \ {\n        if constexpr(is_integral<T>::value) {\n            for(auto& x :\
    \ f) x /= n;\n        } else {\n            T invn = T(1) / T(f.size());\n   \
    \         for(auto& x : f) x *= invn;\n        }\n    }\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    void walsh_hadamard_transform(vector<T>& f, bool inv = false) {\n    int n = f.size();\n\
    \    assert((n & (n - 1)) == 0);\n    for(int i = 1; i < n; i <<= 1) {\n     \
    \   for(int j = 0; j < n; ++j) {\n            if((j & i) == 0) {\n           \
    \     T x = f[j], y = f[j | i];\n                f[j] = x + y, f[j | i] = x -\
    \ y;\n            }\n        }\n    }\n    if(inv) {\n        if constexpr(is_integral<T>::value)\
    \ {\n            for(auto& x : f) x /= n;\n        } else {\n            T invn\
    \ = T(1) / T(f.size());\n            for(auto& x : f) x *= invn;\n        }\n\
    \    }\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/walsh_hadamard_transform.hpp
  requiredBy:
  - src/convolution/xor_convolution.hpp
  timestamp: '2024-01-07 03:22:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/convolution/bitwise_xor_convolution.test.cpp
documentation_of: src/math/walsh_hadamard_transform.hpp
layout: document
title: walsh_hadamard_transform
---

## walsh_hadamard_transform

```cpp
void walsh_hadamard_transform(vector<T>& f, bool inv = false)
```

長さ $2^N$ の数列 $f$ の高速ウォルシュアダマール変換を計算します．<br>
`inv = true` のとき，逆変換を計算します．

**制約**

- 数列 $f$ の長さは $2$ の累乗である．

**計算量**

- $O(2^N N)$