---
title: AuxiliaryTree
documentation_of: ../../src/tree/auxiliary_tree.hpp
---

# AuxiliaryTree

$n$ 頂点の根付き木が与えられたとき，

- 与えられた頂点集合 $U$ に対して，子孫関係を保ったまま圧縮した木

を前計算 $O(n)$ クエリ $O(|U| \log n)$ で求めます．

## コンストラクタ

```cpp
AuxiliaryTree<T> aux(Graph<T> g, int root = 0)
```

- 頂点数 $n$ の木 `g` を与えると，`root` を根として前計算を行います．

**制約**

- `T` は `int / uint / ll / ull / double / long double`
- `g` は木
- $0 \leq \mathrm{root} < n$

**計算量**

- $O(n)$

## get

```cpp
pair<Graph<int>, vector<int>> aux.get(vector<int> idx)
```

頂点集合 `idx` を指定したときのAuxiliary Treeと，Auxiliary Treeと元の木の頂点番号の対応配列を返します．

**計算量**

$m$ を頂点集合 `idx` のサイズとして，

- $O(m \log n)$