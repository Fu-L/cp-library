---
title: centroid_decomposition
documentation_of: ../../src/tree/centroid_decomposition.hpp
---

## centroid_decomposition

```cpp
pait<Graph<int>, int> centroid_decomposition(Graph<T> g)
```

$n$ 頂点の木 `g` を入力すると重心分解した木 `tree` と，その根 `root` を返します．

`tree[i][j]` は頂点 $i$ まで木を分解したときにできる連結成分の重心を指しています．

**制約**

- `g` は木

**計算量**

- $O(n \log n)$