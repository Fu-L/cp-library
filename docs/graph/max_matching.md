---
title: max_matching
documentation_of: ../../src/graph/max_matching.hpp
---

## max_matching

```cpp
Edges<T> max_matching(int n, Edges<T> es)
```

$n$ 頂点無向グラフの辺集合 `es` からグラフの最大マッチングを計算します．<br>
返り値は採用された辺集合です．

- 自己ループは無視されます．
- 多重辺が含まれていても動作します．
- 返り値の各辺は `from < to` です．

**制約**

- 辺の重みが $1$ である．
- 各辺 `e` について， $0 \leq e.\mathrm{from}, e.\mathrm{to} \lt n$

**計算量**

頂点数，辺数をそれぞれ $V, E$ として，

- $O(VE \alpha(V, E))$