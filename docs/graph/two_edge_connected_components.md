---
title: TwoEdgeConnectedComponents
documentation_of: ../../src/graph/two_edge_connected_components.hpp
---

# TwoEdgeConnectedComponents

グラフの二重辺連結成分分解を行います．

二重辺連結成分とは，グラフから橋を全て削除したときの連結成分です．

異なる $2$ つの二重辺連結成分 $A, B$ について，以下の性質が成り立ちます．

- 任意の異なる $2$ 頂点 $a_1, a_2 \in A$ について，辺について互いに素なパス $a_1 - a_2$ が少なくとも $2$ つ存在する．

- 任意の $2$ 頂点 $a \in A, b \in B$ について，辺について互いに素なパス $a - b$ を $2$ つ以上取ることはできない

## コンストラクタ

```cpp
TwoEdgeConnectedComponents<T> tecc(Graph<T> g)
```

$n$ 頂点 $m$ 辺のグラフ `g` を二重辺連結成分分解します．

**計算量**

- $O(n + m)$

## operator []

```cpp
int tecc[int i]
```

頂点 `i` が何番目の二重辺連結成分に属するかを返します．

**制約**

- $0 \leq i < n$

**計算量**

- $O(1)$

## メンバ変数

```cpp
(1) vector<vector<int>> tecc.groups
(2) vector<vector<int>> tecc.tree
```

- (1): `i` 番目の二重辺連結成分に含まれる頂点集合を保持しています．
- (2): 二重辺連結成分からなる木構造を保持しています．