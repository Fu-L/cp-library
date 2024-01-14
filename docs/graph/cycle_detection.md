---
title: cycle_detection
documentation_of: ../../src/graph/cycle_detection.hpp
---

## cycle_detection

```cpp
Edges<T> cycle_detection(Graph<T> g, bool directed = true)
```

$n$ 頂点 $m$ 辺のグラフ `g` の閉路検出を行います．

`directed = true` のとき `g` を有向グラフとして計算します．<br>
`directed = false` のとき `g` を無向グラフとして計算します．

閉路がある場合，閉路を構成する辺を返します．<br>
閉路がない場合，空の辺集合を返します．<br>

**計算量**

- $O(m)$