---
title: rerooting
documentation_of: ../../src/tree/rerooting.hpp
---

# rerooting

```cpp
vector<DP> rerooting(Graph<T> g, auto F1 f1, auto F2 f2, DP id)
```

全方位木DPを計算します．

`g` には木を入れてください．

`f1` には $2$ つの子ノードのdpテーブルをマージする関数を入れてください．

`f2` には 子ノードから親ノードへの遷移を計算する関数を入れてください．

`id` には `f1` の単位元，および葉ノードのdpテーブルの値を入れてください．

**制約**

- `g` は木

**計算量**

`f1, f2, id` の取得計算時間を $O(f(n))$ として，

- $O(n f(n))$