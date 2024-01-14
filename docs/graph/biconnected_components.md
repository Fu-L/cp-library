---
title: BiconnectedComponents
documentation_of: ../../src/graph/biconnected_components.hpp
---

# BiconnectedComponents

グラフの二重頂点連結成分分解を行います．

頂点の部分集合 $A$ が二重頂点連結成分であるとは，任意の頂点 $a \in A$ について， $A$ から $a$ を除いても連結であり，かつ $A$ が極大であることを言います．

## コンストラクタ

```cpp
BiconnectedComponents<T> low(Graph<T> g)
```

$n$ 頂点 $m$ 辺のグラフ `g` を二重頂点連結成分分解します．

**計算量**

- $O(n + m)$

## メンバ変数

```cpp
vector<vector<pair<int, int>>> low.bc
```

`i` 番目の二重頂点連結成分の辺集合を返します．