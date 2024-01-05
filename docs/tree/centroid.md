---
title: centroid
documentation_of: ../../src/tree/centroid.hpp
---

## centroid

```cpp
vector<int> centroid(Graph<T> g)
```

$n$ 頂点の木 `g` の重心を全て返します．

頂点 $v$ が $n$ 頂点の木 `g` の重心であるとは，頂点 $v$ を取り除いたときにできる連結成分の大きさの最大値が $n / 2$ 以下であることを指します．<br>
任意の木には重心が $1$ つ，または $2$ つ存在します．

**制約**

- `g` は木である

**計算量**

- $O(n)$