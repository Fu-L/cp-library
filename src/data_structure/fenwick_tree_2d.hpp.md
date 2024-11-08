---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps_2.test.cpp
    title: verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps_2.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/fenwick_tree_2d.hpp\"\
    \ntemplate <typename T>\nstruct FenwickTree2D {\n    FenwickTree2D(const int H,\
    \ const int W)\n        : h(H), w(W), data(H + 1, vector<T>(W + 1, 0)) {}\n  \
    \  void add(const int i, const int j, const T& z) {\n        assert(0 <= i and\
    \ i < h);\n        assert(0 <= j and j < w);\n        for(int x = i + 1; x <=\
    \ h; x += x & -x) {\n            for(int y = j + 1; y <= w; y += y & -y) {\n \
    \               data[x - 1][y - 1] += z;\n            }\n        }\n    }\n  \
    \  T sum(const int li, const int lj, const int ri, const int rj) const {\n   \
    \     assert(0 <= li and li <= ri and ri <= h);\n        assert(0 <= lj and lj\
    \ <= rj and rj <= w);\n        return sum(ri, rj) - sum(li, rj) - sum(ri, lj)\
    \ + sum(li, lj);\n    }\n    T get(const int i, const int j) const {\n       \
    \ assert(0 <= i and i < h);\n        assert(0 <= j and j < w);\n        return\
    \ sum(i + 1, j + 1) - sum(i, j + 1) - sum(i + 1, j) + sum(i, j);\n    }\n\n  \
    \ private:\n    int h, w;\n    vector<vector<T>> data;\n    inline T sum(const\
    \ int i, const int j) const {\n        T s = 0;\n        for(int x = i; x > 0;\
    \ x -= x & -x) {\n            for(int y = j; y > 0; y -= y & -y) {\n         \
    \       s += data[x - 1][y - 1];\n            }\n        }\n        return s;\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    struct FenwickTree2D {\n    FenwickTree2D(const int H, const int W)\n        :\
    \ h(H), w(W), data(H + 1, vector<T>(W + 1, 0)) {}\n    void add(const int i, const\
    \ int j, const T& z) {\n        assert(0 <= i and i < h);\n        assert(0 <=\
    \ j and j < w);\n        for(int x = i + 1; x <= h; x += x & -x) {\n         \
    \   for(int y = j + 1; y <= w; y += y & -y) {\n                data[x - 1][y -\
    \ 1] += z;\n            }\n        }\n    }\n    T sum(const int li, const int\
    \ lj, const int ri, const int rj) const {\n        assert(0 <= li and li <= ri\
    \ and ri <= h);\n        assert(0 <= lj and lj <= rj and rj <= w);\n        return\
    \ sum(ri, rj) - sum(li, rj) - sum(ri, lj) + sum(li, lj);\n    }\n    T get(const\
    \ int i, const int j) const {\n        assert(0 <= i and i < h);\n        assert(0\
    \ <= j and j < w);\n        return sum(i + 1, j + 1) - sum(i, j + 1) - sum(i +\
    \ 1, j) + sum(i, j);\n    }\n\n   private:\n    int h, w;\n    vector<vector<T>>\
    \ data;\n    inline T sum(const int i, const int j) const {\n        T s = 0;\n\
    \        for(int x = i; x > 0; x -= x & -x) {\n            for(int y = j; y >\
    \ 0; y -= y & -y) {\n                s += data[x - 1][y - 1];\n            }\n\
    \        }\n        return s;\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/fenwick_tree_2d.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps_2.test.cpp
documentation_of: src/data_structure/fenwick_tree_2d.hpp
layout: document
title: FenwickTree2D
---

# FenwickTree2D

サイズが $N \times M$ である $2$ 次元配列に対し，

- $1$ 点加算
- 長方形領域の総和の取得

を $O(\log N \log M)$ 時間で処理することができます．

## コンストラクタ

```cpp
FenwickTree2D<T> fw(int n, int m)
```

- 型が `T` でサイズが $n \times m$ である$2$ 次元配列 `fw` を作ります．<br>
- 初期値はすべて $0$ です．

**計算量**

- $O(nm)$

## add

```cpp
void fw.add(int i, int j, T x)
```

`fw[i][j] += x` をします．

**制約**

- $0 \leq i < n$
- $0 \leq j < m$

**計算量**

- $O(\log n \log m)$

## sum

```cpp
T fw.sum(int li, int lj, int ri, int rj)
```

長方形領域 $[li, ri) \times [lj, rj)$ における配列 `fw` の総和を返します．

**制約**

- $0 \leq li \leq ri \leq n$
- $0 \leq lj \leq rj \leq m$

**計算量**

- $O(\log n \log m)$

## get

```cpp
T fw.get(int i, int j)
```

`fw[i][j]` を返します．

**制約**

- $0 \leq i < n$
- $0 \leq j < m$

**計算量**

- $O(\log n \log m)$