---
title: topological_sort
documentation_of: ../../src/graph/topological_sort.hpp
---

## topological_sort

```cpp
vector<int> topological_sort(Graph<T> g)
```

$n$ 頂点 $m$ 辺の有向グラフ `g` をトポロジカルソートしたときの頂点順序を返します．

`g` がDAGでない場合は空の配列を返します．

**計算量**

- $O(n + m)$