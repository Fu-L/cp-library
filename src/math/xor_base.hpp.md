---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/184.test.cpp
    title: verify/yukicoder/184.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/xor_base.hpp\"\n\
    template <typename T>\nvector<T> xor_base(const vector<T>& a) {\n    vector<T>\
    \ base;\n    for(T v : a) {\n        for(const T e : base) {\n            v =\
    \ min(v, v xor e);\n        }\n        if(v > 0) base.emplace_back(v);\n    }\n\
    \    return base;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    vector<T> xor_base(const vector<T>& a) {\n    vector<T> base;\n    for(T v : a)\
    \ {\n        for(const T e : base) {\n            v = min(v, v xor e);\n     \
    \   }\n        if(v > 0) base.emplace_back(v);\n    }\n    return base;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/xor_base.hpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/184.test.cpp
documentation_of: src/math/xor_base.hpp
layout: document
title: xor_base
---

## xor_base

```cpp
vector<T> xor_base(vector<T> a)
```

長さ $n$ の数列 $a$ の $\mathrm{xor}$ 基底を返します．

基底を取り出すだけであり，基本形になっているとは限らないことに注意してください．

**計算量**

$a$ の $\mathrm{xor}$ 基底の本数を $\mathrm{rank}$ として，

- $O(n \times \mathrm{rank})$