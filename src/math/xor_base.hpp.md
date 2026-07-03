---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yukicoder/184.test.cpp
    title: verify/yukicoder/184.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    #line 4 \"src/template/template.hpp\"\nusing namespace std;\nusing ll = long long;\n\
    using P = pair<long long, long long>;\n#define rep(i, a, b) for(long long i =\
    \ (a); i < (b); ++i)\n#define rrep(i, a, b) for(long long i = (a); i >= (b); --i)\n\
    constexpr long long inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/math/xor_base.hpp\"\ntemplate <typename T>\nvector<T> xor_base(const\
    \ vector<T>& a) {\n    vector<T> base;\n    for(T v : a) {\n        for(const\
    \ T& e : base) {\n            if((v xor e) < v) v ^= e;\n        }\n        for(T&\
    \ e : base) {\n            if((v xor e) < e) e ^= v;\n        }\n        if(v)\
    \ base.emplace_back(v);\n    }\n    return base;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    vector<T> xor_base(const vector<T>& a) {\n    vector<T> base;\n    for(T v : a)\
    \ {\n        for(const T& e : base) {\n            if((v xor e) < v) v ^= e;\n\
    \        }\n        for(T& e : base) {\n            if((v xor e) < e) e ^= v;\n\
    \        }\n        if(v) base.emplace_back(v);\n    }\n    return base;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/xor_base.hpp
  requiredBy: []
  timestamp: '2026-07-04 00:41:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
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

基本形にはなっていますが，昇順・降順にソートされているとは限らないので注意してください．

**計算量**

$a$ の $\mathrm{xor}$ 基底の本数を $\mathrm{rank}$ として，

- $O(n \times \mathrm{rank})$