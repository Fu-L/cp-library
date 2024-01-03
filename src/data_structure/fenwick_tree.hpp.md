---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/point_add_range_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_range_inversions_query.test.cpp
    title: verify/library_checker/data_structure/static_range_inversions_query.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/fenwick_tree.hpp\"\
    \ntemplate <typename T>\nstruct FenwickTree {\n    FenwickTree(int N)\n      \
    \  : n(N), data(N) {}\n    void add(int p, T x) {\n        assert(0 <= p and p\
    \ < n);\n        ++p;\n        while(p <= n) {\n            data[p - 1] += x;\n\
    \            p += p & -p;\n        }\n    }\n    T sum(int l, int r) const {\n\
    \        assert(0 <= l and l <= r and r <= n);\n        return sum(r) - sum(l);\n\
    \    }\n    T operator[](int x) const {\n        assert(0 <= x and x < n);\n \
    \       return sum(x + 1) - sum(x);\n    }\n\n   private:\n    int n;\n    vector<T>\
    \ data;\n    inline T sum(int r) const {\n        T s = 0;\n        while(r >\
    \ 0) {\n            s += data[r - 1];\n            r -= r & -r;\n        }\n \
    \       return s;\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    struct FenwickTree {\n    FenwickTree(int N)\n        : n(N), data(N) {}\n   \
    \ void add(int p, T x) {\n        assert(0 <= p and p < n);\n        ++p;\n  \
    \      while(p <= n) {\n            data[p - 1] += x;\n            p += p & -p;\n\
    \        }\n    }\n    T sum(int l, int r) const {\n        assert(0 <= l and\
    \ l <= r and r <= n);\n        return sum(r) - sum(l);\n    }\n    T operator[](int\
    \ x) const {\n        assert(0 <= x and x < n);\n        return sum(x + 1) - sum(x);\n\
    \    }\n\n   private:\n    int n;\n    vector<T> data;\n    inline T sum(int r)\
    \ const {\n        T s = 0;\n        while(r > 0) {\n            s += data[r -\
    \ 1];\n            r -= r & -r;\n        }\n        return s;\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/static_range_inversions_query.test.cpp
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
documentation_of: src/data_structure/fenwick_tree.hpp
layout: document
title: FenwickTree
---

# FenwickTree

長さ $N$ の配列に対し，

- 1点加算
- 区間和取得

を $O(\log N)$ 時間で処理することができます．

## コンストラクタ

```cpp
FenwickTree<T> fw(int n)
```

- 長さ $n$ の配列 $a$ を作ります．初期値はすべて $0$ です．

**制約**

- $T$ は `int / uint / ll / ull / mint`

**計算量**

- $O(n)$

## add

```cpp
void fw.add(int p, T x)
```

`a[p] += x` をします．

**制約**

- $0 \leq p < n$

**計算量**

- $O(\log n)$

## sum

```cpp
T fw.sum(int l, int r)
```

`a[l] + a[l + 1] + ... + a[r - 1]` を返します．

**制約**

- $0 \leq l \leq r \leq n$

**計算量**

- $O(\log n)$

## operator []

```cpp
T fw[int x]
```

`a[x]` を返します．

**制約**

- $0 \leq x < n$

**計算量**

- $O(\log n)$