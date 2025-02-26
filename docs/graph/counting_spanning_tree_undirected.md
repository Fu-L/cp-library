---
title: counting_spanning_tree_undirected
documentation_of: ../../src/graph/counting_spanning_tree_undirected.hpp
---

## counting_spanning_tree_undirected

```cpp
T counting_spanning_tree_undirected(Graph<U> g)
```

無向グラフ $G$ の全域木の個数を返します．

**制約**

- $G$ は無向グラフ

**計算量**

$G$ の頂点数と辺数をそれぞれ $N, M$ として，

- $O(NM + N^3)$
