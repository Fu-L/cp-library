---
title: kruskal
documentation_of: ../../src/graph/kruskal.hpp
---

# kruskal

```cpp
pair<T, Edges<T>> kruskal(int n, Edges<T> es)
```

$n$ 頂点無向グラフの辺集合 `es` からグラフの最小全域木を計算します．<br>
返り値は最小全域木のコストの合計と，採用された辺集合です．

仮に元のグラフが連結でない場合，各連結成分ごとの最小全域木を計算します．

**計算量**

辺数を $E$ として，

- $O(E \log E)$