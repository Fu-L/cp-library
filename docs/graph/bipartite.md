---
title: bipartite
documentation_of: ../../src/graph/bipartite.hpp
---

## bipartite

```cpp
vector<int> bipartite(Graph<T> g)
```

$n$ 頂点 $m$ 辺の無向グラフ `g` が二部グラフかどうか判定します．

`g` が二部グラフである場合， `g` の各頂点を $0$ と $1$ で彩色した配列を返します．<br>
二部グラフでない場合は空の配列を返します．

**計算量**

- $O(n + m)$