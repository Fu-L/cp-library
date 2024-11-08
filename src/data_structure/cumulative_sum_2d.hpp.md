---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps.test.cpp
    title: verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/cumulative_sum_2d.hpp\"\
    \ntemplate <typename T>\nstruct CumulativeSum2D {\n    CumulativeSum2D(const int\
    \ H, const int W)\n        : h(H), w(W), data(H + 1, vector<T>(W + 1, 0)) {}\n\
    \    void add(const int i, const int j, const T& x) {\n        assert(0 <= i and\
    \ i < h);\n        assert(0 <= j and j < w);\n        data[i + 1][j + 1] += x;\n\
    \    }\n    void init() {\n        for(int i = 1; i < (int)data.size(); ++i) {\n\
    \            for(int j = 1; j < (int)data[i].size(); ++j) {\n                data[i][j]\
    \ += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];\n            }\n  \
    \      }\n    }\n    T sum(const int li, const int lj, const int ri, const int\
    \ rj) const {\n        assert(0 <= li and li <= ri and ri <= h);\n        assert(0\
    \ <= lj and lj <= rj and rj <= w);\n        return data[ri][rj] - data[li][rj]\
    \ - data[ri][lj] + data[li][lj];\n    }\n    T get(const int i, const int j) const\
    \ {\n        assert(0 <= i and i < h);\n        assert(0 <= j and j < w);\n  \
    \      return data[i + 1][j + 1] - data[i][j + 1] - data[i + 1][j] + data[i][j];\n\
    \    }\n\n   private:\n    int h, w;\n    vector<vector<T>> data;\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    struct CumulativeSum2D {\n    CumulativeSum2D(const int H, const int W)\n    \
    \    : h(H), w(W), data(H + 1, vector<T>(W + 1, 0)) {}\n    void add(const int\
    \ i, const int j, const T& x) {\n        assert(0 <= i and i < h);\n        assert(0\
    \ <= j and j < w);\n        data[i + 1][j + 1] += x;\n    }\n    void init() {\n\
    \        for(int i = 1; i < (int)data.size(); ++i) {\n            for(int j =\
    \ 1; j < (int)data[i].size(); ++j) {\n                data[i][j] += data[i][j\
    \ - 1] + data[i - 1][j] - data[i - 1][j - 1];\n            }\n        }\n    }\n\
    \    T sum(const int li, const int lj, const int ri, const int rj) const {\n \
    \       assert(0 <= li and li <= ri and ri <= h);\n        assert(0 <= lj and\
    \ lj <= rj and rj <= w);\n        return data[ri][rj] - data[li][rj] - data[ri][lj]\
    \ + data[li][lj];\n    }\n    T get(const int i, const int j) const {\n      \
    \  assert(0 <= i and i < h);\n        assert(0 <= j and j < w);\n        return\
    \ data[i + 1][j + 1] - data[i][j + 1] - data[i + 1][j] + data[i][j];\n    }\n\n\
    \   private:\n    int h, w;\n    vector<vector<T>> data;\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/cumulative_sum_2d.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:50:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps.test.cpp
documentation_of: src/data_structure/cumulative_sum_2d.hpp
layout: document
title: CumulativeSum2D
---

# CumulativeSum2D

$2$ 次元累積和を計算するデータ構造です．

事前に `add` で $2$ 次元配列を作り， `init` で累積和テーブルの初期化を行ってください．<br>
それ以降は `sum` で長方形領域の総和を計算できます．

## コンストラクタ

```cpp
CumulativeSum2D<T> cum(int n, int m)
```

- 型が `T` でサイズが $n \times m$ である $2$ 次元配列 `cum` を作成します．
- 初期値はすべて $0$ です．

**計算量**

- $O(nm)$

## add

```cpp
cum.add(int i, int j, T x)
```

`cum[i][j] += x` をします．

**制約**

- $0 \leq i < n$
- $0 \leq j < m$
- `init` を呼び出していない

**計算量**

- $O(1)$

## init

```cpp
cum.init()
```

$2$ 次元累積和テーブルの初期化を行います．<br>
`add` による配列の構築が終わった後，ちょうど $1$ 度だけ呼び出してください．

**計算量**

- $O(nm)$

## sum

```cpp
T cum.sum(int li, int lj, int ri, int rj)
```

長方形領域 $[li, ri) \times [lj, rj)$ における配列 `cum` の総和を返します．

**制約**

- $0 \leq li \leq ri \leq n$
- $0 \leq lj \leq rj \leq m$
- 事前に `init` をちょうど $1$ 度だけ呼び出している．

**計算量**

- $O(1)$

## get

```cpp
T cum.get(int i, int j)
```

`cum[i][j]` の値を返します．

**制約**

- $0 \leq i < n$
- $0 \leq j < m$
- 事前に `init` をちょうど $1$ 度だけ呼び出している．

**計算量**

- $O(1)$