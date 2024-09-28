---
title: bfs
documentation_of: ../../src/graph/bfs.hpp
---

## bfs

```cpp
vector<pair<int, int>> bfs(Graph<int> g, int s = 0)
```

$n$ 頂点の重みなしグラフ `g` 上で頂点 `s` を始点とした最短経路探索を行います．

返り値は長さ $n$ の `pair` 型の配列です．<br>
`pair` 型の第一要素は頂点 `s` から頂点 `i` までの最短距離を，第二要素は頂点 `i` にたどり着く直前にいた頂点番号を保持しています．

もし頂点 `i` に到達できない場合， `pair` 型の第一要素は `numeric_limits<int>::max()` で，第二要素は $-1$ です．

**制約**

- $0 \leq s < n$
- 辺の重みが $1$ である ( `assert` 等で検知されません)．

**計算量**

- $O(E + V)$