---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
    title: verify/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/fps/all_product.hpp\"\
    \ntemplate <template <typename> typename FPS, typename T>\nFPS<T> all_product(vector<FPS<T>>\
    \ f) {\n    if(f.empty()) return {1};\n    priority_queue<pair<int, int>, vector<pair<int,\
    \ int>>, greater<pair<int, int>>> pq;\n    for(int i = 0; i < (int)f.size(); ++i)\
    \ pq.emplace(f[i].size(), i);\n    while((int)pq.size() > 1) {\n        const\
    \ auto [d1, i1] = pq.top();\n        pq.pop();\n        const auto [d2, i2] =\
    \ pq.top();\n        pq.pop();\n        f[i1] *= f[i2];\n        f[i2].clear();\n\
    \        pq.emplace(d1 + d2, i1);\n    }\n    return f[pq.top().second];\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <template <typename>\
    \ typename FPS, typename T>\nFPS<T> all_product(vector<FPS<T>> f) {\n    if(f.empty())\
    \ return {1};\n    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,\
    \ int>>> pq;\n    for(int i = 0; i < (int)f.size(); ++i) pq.emplace(f[i].size(),\
    \ i);\n    while((int)pq.size() > 1) {\n        const auto [d1, i1] = pq.top();\n\
    \        pq.pop();\n        const auto [d2, i2] = pq.top();\n        pq.pop();\n\
    \        f[i1] *= f[i2];\n        f[i2].clear();\n        pq.emplace(d1 + d2,\
    \ i1);\n    }\n    return f[pq.top().second];\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/fps/all_product.hpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
documentation_of: src/fps/all_product.hpp
layout: document
title: all_product
---

## all_product

```cpp
FPS<T> all_product(vector<FPS<T>> f)
```

$n$ 個の多項式 $f_0, f_1, ..., f_{n - 1}$ に対して $\prod\limits_{i = 0}^{n - 1} f_i$ を返します．

**計算量**

$f_i$ の次数を $d_i$ とし， $N := \sum\limits_{i = 0}^{n - 1} d_i$ としたとき，

- $O(N \log^2 {N})$