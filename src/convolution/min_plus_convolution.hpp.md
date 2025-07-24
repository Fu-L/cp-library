---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/monotone_minima.hpp
    title: monotone_minima
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
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
    \ i + 1, ie, m, r);\n    };\n    dfs(dfs, 0, n, 0, m);\n    return res;\n}\n#line\
    \ 4 \"src/convolution/min_plus_convolution.hpp\"\ntemplate <typename T>\nvector<T>\
    \ min_plus_convolution(const vector<T>& a, const vector<T>& b) {\n    if(a.empty()\
    \ or b.empty()) return {};\n    const int n = a.size(), m = b.size();\n    auto\
    \ f = [&](const int i, const int j, const int k) -> bool {\n        if(i < k)\
    \ return true;\n        if(i - j >= n) return false;\n        return a[i - j]\
    \ + b[j] < a[i - k] + b[k];\n    };\n    const auto argmin = monotone_minima(n\
    \ + m - 1, m, f);\n    vector<int> res(n + m - 1);\n    for(int i = 0; i < n +\
    \ m - 1; ++i) {\n        const int j = argmin[i];\n        res[i] = a[i - j] +\
    \ b[j];\n    }\n    return res;\n}\ntemplate <typename T>\nvector<T> max_plus_convolution(const\
    \ vector<T>& a, const vector<T>& b) {\n    if(a.empty() or b.empty()) return {};\n\
    \    const int n = a.size(), m = b.size();\n    auto f = [&](const int i, const\
    \ int j, const int k) -> bool {\n        if(i < k) return true;\n        if(i\
    \ - j >= n) return false;\n        return a[i - j] + b[j] > a[i - k] + b[k];\n\
    \    };\n    const auto argmax = monotone_minima(n + m - 1, m, f);\n    vector<int>\
    \ res(n + m - 1);\n    for(int i = 0; i < n + m - 1; ++i) {\n        const int\
    \ j = argmax[i];\n        res[i] = a[i - j] + b[j];\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../dp/monotone_minima.hpp\"\
    \ntemplate <typename T>\nvector<T> min_plus_convolution(const vector<T>& a, const\
    \ vector<T>& b) {\n    if(a.empty() or b.empty()) return {};\n    const int n\
    \ = a.size(), m = b.size();\n    auto f = [&](const int i, const int j, const\
    \ int k) -> bool {\n        if(i < k) return true;\n        if(i - j >= n) return\
    \ false;\n        return a[i - j] + b[j] < a[i - k] + b[k];\n    };\n    const\
    \ auto argmin = monotone_minima(n + m - 1, m, f);\n    vector<int> res(n + m -\
    \ 1);\n    for(int i = 0; i < n + m - 1; ++i) {\n        const int j = argmin[i];\n\
    \        res[i] = a[i - j] + b[j];\n    }\n    return res;\n}\ntemplate <typename\
    \ T>\nvector<T> max_plus_convolution(const vector<T>& a, const vector<T>& b) {\n\
    \    if(a.empty() or b.empty()) return {};\n    const int n = a.size(), m = b.size();\n\
    \    auto f = [&](const int i, const int j, const int k) -> bool {\n        if(i\
    \ < k) return true;\n        if(i - j >= n) return false;\n        return a[i\
    \ - j] + b[j] > a[i - k] + b[k];\n    };\n    const auto argmax = monotone_minima(n\
    \ + m - 1, m, f);\n    vector<int> res(n + m - 1);\n    for(int i = 0; i < n +\
    \ m - 1; ++i) {\n        const int j = argmax[i];\n        res[i] = a[i - j] +\
    \ b[j];\n    }\n    return res;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/dp/monotone_minima.hpp
  isVerificationFile: false
  path: src/convolution/min_plus_convolution.hpp
  requiredBy: []
  timestamp: '2025-07-24 13:14:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/convolution/min_plus_convolution(convex_and_convex).test.cpp
  - verify/library_checker/convolution/min_plus_convolution(convex_and_arbitrary).test.cpp
documentation_of: src/convolution/min_plus_convolution.hpp
layout: document
title: min_plus_convolution
---

## min_plus_convolution

```cpp
vector<T> min_plus_convolution(vector<T> a, vector<T> b)
```

長さ $n$ の下に凸な数列 $a$ と，長さ $m$ の任意の数列 $b$ から，長さ $n+m-1$の数列

$$c_i = \min_{j}\{a_{i-j} + b_{j}\}$$

を計算します．

**制約**

- $a$ は下に凸

**計算量**

- $O((n + m) \log n)$

## max_plus_convolution

```cpp
vector<T> max_plus_convolution(vector<T> a, vector<T> b)
```

長さ $n$ の上に凸な数列 $a$ と，長さ $m$ の任意の数列 $b$ から，長さ $n+m-1$の数列

$$c_i = \max_{j}\{a_{i-j} + b_{j}\}$$

を計算します．

**制約**

- $a$ は上に凸

**計算量**

- $O((n + m) \log n)$