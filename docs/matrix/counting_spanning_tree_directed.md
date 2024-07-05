---
title: counting_spanning_tree_directed
documentation_of: ../../src/matrix/counting_spanning_tree_directed.hpp
---

## counting_spanning_tree_directed

```cpp
T counting_spanning_tree_directed(Graph<U> g, int r)
```

有向グラフ $G$ の頂点 $r$ を根とする有向全域木の個数を返します．

**制約**

$G$ の頂点数を $N$ として，

- $0 \leq r < N$

**計算量**

$G$ の頂点数と辺数をそれぞれ $N, M$ として，

- $O(NM + N^3)$
