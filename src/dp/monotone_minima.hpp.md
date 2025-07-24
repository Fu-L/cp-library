---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/min_plus_convolution.hpp
    title: min_plus_convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/convolution/min_plus_convolution(convex_and_arbitrary).test.cpp
    title: verify/library_checker/convolution/min_plus_convolution(convex_and_arbitrary).test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/convolution/min_plus_convolution(convex_and_convex).test.cpp
    title: verify/library_checker/convolution/min_plus_convolution(convex_and_convex).test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/dp/monotone_minima.hpp\"\
    \ntemplate <class F>\nvector<int> monotone_minima(const int n, const int m, const\
    \ F& f) {\n    vector<int> res(n);\n    auto dfs = [&](const auto& dfs, const\
    \ int is, const int ie, const int l, const int r) -> void {\n        if(is ==\
    \ ie) return;\n        const int i = (is + ie) / 2;\n        int m = l;\n    \
    \    for(int k = l + 1; k < r; ++k) {\n            if(!f(i, m, k)) m = k;\n  \
    \      }\n        res[i] = m;\n        dfs(dfs, is, i, l, m + 1);\n        dfs(dfs,\
    \ i + 1, ie, m, r);\n    };\n    dfs(dfs, 0, n, 0, m);\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <class F>\n\
    vector<int> monotone_minima(const int n, const int m, const F& f) {\n    vector<int>\
    \ res(n);\n    auto dfs = [&](const auto& dfs, const int is, const int ie, const\
    \ int l, const int r) -> void {\n        if(is == ie) return;\n        const int\
    \ i = (is + ie) / 2;\n        int m = l;\n        for(int k = l + 1; k < r; ++k)\
    \ {\n            if(!f(i, m, k)) m = k;\n        }\n        res[i] = m;\n    \
    \    dfs(dfs, is, i, l, m + 1);\n        dfs(dfs, i + 1, ie, m, r);\n    };\n\
    \    dfs(dfs, 0, n, 0, m);\n    return res;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/dp/monotone_minima.hpp
  requiredBy:
  - src/convolution/min_plus_convolution.hpp
  timestamp: '2025-07-24 13:14:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/convolution/min_plus_convolution(convex_and_convex).test.cpp
  - verify/library_checker/convolution/min_plus_convolution(convex_and_arbitrary).test.cpp
documentation_of: src/dp/monotone_minima.hpp
layout: document
title: monotone_minima
---

## monotone_minima

```cpp
vector<int> monotome_minima<F>(int n, int m, F f)
```

$n \times m$ のmonotone行列 $A$ に対して，各行における最小値を取る列を列挙します．<br>
以下の要件を満たす関数 `bool f(int i, int j, int k)` を定義する必要があります．<br>
- $A[i][j] < A[i][k]$ のとき `true` を返す ( $j < k$ が保証される．等号はどちらでもよい)．

**計算量**

- $O((n + m) \log n)$