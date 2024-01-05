---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/walsh_hadamard_transform.hpp
    title: walsh_hadamard_transform
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
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
    \ = false) {\n    int n = f.size();\n    for(int i = 1; i < n; i <<= 1) {\n  \
    \      for(int j = 0; j < n; ++j) {\n            if((j & i) == 0) {\n        \
    \        T x = f[j], y = f[j | i];\n                f[j] = x + y, f[j | i] = x\
    \ - y;\n            }\n        }\n    }\n    if(inv) {\n        if constexpr(is_integral<T>::value)\
    \ {\n            for(auto& x : f) x /= n;\n        } else {\n            T invn\
    \ = T(1) / T(f.size());\n            for(auto& x : f) x *= invn;\n        }\n\
    \    }\n}\n#line 4 \"src/convolution/xor_convolution.hpp\"\ntemplate <typename\
    \ T>\nvector<T> xor_convolution(vector<T> a, vector<T> b) {\n    walsh_hadamard_transform(a);\n\
    \    walsh_hadamard_transform(b);\n    for(int i = 0; i < (int)a.size(); i++)\
    \ a[i] *= b[i];\n    walsh_hadamard_transform(a, true);\n    return a;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../math/walsh_hadamard_transform.hpp\"\
    \ntemplate <typename T>\nvector<T> xor_convolution(vector<T> a, vector<T> b) {\n\
    \    walsh_hadamard_transform(a);\n    walsh_hadamard_transform(b);\n    for(int\
    \ i = 0; i < (int)a.size(); i++) a[i] *= b[i];\n    walsh_hadamard_transform(a,\
    \ true);\n    return a;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/walsh_hadamard_transform.hpp
  isVerificationFile: false
  path: src/convolution/xor_convolution.hpp
  requiredBy: []
  timestamp: '2024-01-05 00:10:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/convolution/bitwise_xor_convolution.test.cpp
documentation_of: src/convolution/xor_convolution.hpp
layout: document
title: xor_convolution
---

## xor_convolution

```cpp
vector<T> xor_convolution(vector<T> a, vector<T> b)
```

XOR畳み込みを行います．<br>
長さ $2^N$ の数列 $a$ と $b$ から，長さ $2^N$ の数列，

$$c_k = \sum\limits_{i \oplus j = k} a_i b_j$$

を計算します．

**制約**

- 数列 $a$ と $b$ の長さは等しい
- 数列 $a$ と $b$ の長さは $2$ の累乗である．

**計算量**

- $O(2^N N)$