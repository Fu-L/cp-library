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

注: `#include "graph/max_matching.hpp"` を `#include "template/template.hpp"` の上に書かないとCompile Errorが起こります．

**制約**

- 辺の重みが $1$ である．

**計算量**

頂点数，辺数をそれぞれ $V, E$ として，

- $O(VE \alpha(E, V))$