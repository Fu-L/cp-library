---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_range_inversions_query.test.cpp
    title: verify/library_checker/data_structure/static_range_inversions_query.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/mo.hpp\"\
    \nstruct Mo {\n    Mo(const int N, const int Q)\n        : n(N), order(Q) {\n\
    \        width = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));\n\
    \        iota(order.begin(), order.end(), 0);\n    }\n    void insert(const int\
    \ l, const int r) {\n        assert(0 <= l and l <= r and r <= n);\n        left.emplace_back(l);\n\
    \        right.emplace_back(r);\n    }\n    template <typename AL, typename AR,\
    \ typename DL, typename DR, typename OUT>\n    void run(const AL& add_left, const\
    \ AR& add_right, const DL& delete_left, const DR& delete_right, const OUT& out)\
    \ {\n        assert(left.size() == order.size());\n        sort(order.begin(),\
    \ order.end(), [&](const int i, const int j) {\n            const int iblock =\
    \ left[i] / width, jblock = left[j] / width;\n            if(iblock != jblock)\
    \ return iblock < jblock;\n            if(iblock & 1) return right[i] < right[j];\n\
    \            return right[i] > right[j];\n        });\n        int nl = 0, nr\
    \ = 0;\n        for(const int idx : order) {\n            while(nl > left[idx])\
    \ add_left(--nl);\n            while(nr < right[idx]) add_right(nr++);\n     \
    \       while(nl < left[idx]) delete_left(nl++);\n            while(nr > right[idx])\
    \ delete_right(--nr);\n            out(idx);\n        }\n    }\n\n   private:\n\
    \    int n, width;\n    vector<int> left, right, order;\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nstruct Mo {\n    Mo(const\
    \ int N, const int Q)\n        : n(N), order(Q) {\n        width = max<int>(1,\
    \ 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));\n        iota(order.begin(),\
    \ order.end(), 0);\n    }\n    void insert(const int l, const int r) {\n     \
    \   assert(0 <= l and l <= r and r <= n);\n        left.emplace_back(l);\n   \
    \     right.emplace_back(r);\n    }\n    template <typename AL, typename AR, typename\
    \ DL, typename DR, typename OUT>\n    void run(const AL& add_left, const AR& add_right,\
    \ const DL& delete_left, const DR& delete_right, const OUT& out) {\n        assert(left.size()\
    \ == order.size());\n        sort(order.begin(), order.end(), [&](const int i,\
    \ const int j) {\n            const int iblock = left[i] / width, jblock = left[j]\
    \ / width;\n            if(iblock != jblock) return iblock < jblock;\n       \
    \     if(iblock & 1) return right[i] < right[j];\n            return right[i]\
    \ > right[j];\n        });\n        int nl = 0, nr = 0;\n        for(const int\
    \ idx : order) {\n            while(nl > left[idx]) add_left(--nl);\n        \
    \    while(nr < right[idx]) add_right(nr++);\n            while(nl < left[idx])\
    \ delete_left(nl++);\n            while(nr > right[idx]) delete_right(--nr);\n\
    \            out(idx);\n        }\n    }\n\n   private:\n    int n, width;\n \
    \   vector<int> left, right, order;\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/mo.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/static_range_inversions_query.test.cpp
documentation_of: src/data_structure/mo.hpp
layout: document
title: Mo
---

# Mo

- 配列の要素が不変
- クエリの先読みができる
- 区間クエリ $[l, r)$ の結果から $[l - 1, r), [l + 1, r), [l, r - 1), [l, r + 1)$ の結果を高速に計算できる ( $O(\alpha)$ と仮定)

以上の $3$ つの条件を満たすとき， $Q$ 個のクエリの結果を $O(\alpha N \sqrt{Q} + Q \log Q)$ で計算するデータ構造です． ( $N$ は配列長)

## コンストラクタ

```cpp
Mo mo(int N, int Q)
```

配列長 $N$ ，クエリ数 $Q$ として初期化します．

**計算量**

- $O(Q)$

## insert

```cpp
void mo.insert(int l, int r)
```

区間クエリ $[l, r)$ を追加します．

**制約**

- $0 \leq l \leq r \leq N$

**計算量**

- $O(1)$

## run

```cpp
void mo.run(auto add_left, auto add_right, auto delete_left, auto delete_right, auto out)
```

全クエリの結果を計算します．<br>

`add_left` は区間クエリ $[l, r)$ の結果から $[l - 1, r)$ の結果を計算する関数です．<br>
`add_right` は区間クエリ $[l, r)$ の結果から $[l, r + 1)$ の結果を計算する関数です．<br>
`delete_left` は区間クエリ $[l, r)$ の結果から $[l + 1, r)$ の結果を計算する関数です．<br>
`delete_right` は区間クエリ $[l, r)$ の結果から $[l, r - 1)$ の結果を計算する関数です．<br>
`out` は区間を伸縮させた結果を元に，答えを格納する配列に値を書き込む関数です．

`main` 関数でラムダ式などの形で定義して引数に入れてください．

例えば `add_left` や `out` は以下のように定義できます．

```cpp
auto add_left = [&](int idx) -> void{
    // [idx + 1, r) の結果から [idx, r) の結果を計算する処理を書く
};

auto out = [&](int idx) -> void{
    // 例えば ans[idx] = hoge; など
};
```

**制約**

- `run` が呼び出される前に `insert` がちょうど $Q$ 回呼び出されている．

**計算量**

- $O(\alpha N \sqrt{Q} + Q \log Q)$