---
title: cartesian_tree
documentation_of: ../../src/tree/cartesian_tree.hpp
---

## cartesian_tree

```cpp
pair<Graph<int>, int> cartesian_tree(vector<T> a)
```

数列 `a` から導かれるCartesian Treeとその根のインデックスを返します．

Cartesian Treeとは，長さ $n$ の数列 `a` の区間 $[0, n)$ に対して次の操作を再帰的に繰り返すことにより得られる二分木のことです．

- 区間 $[l, r)$ について， $i \in [l, r)$ のうち $a_i$ が最小であるような $i$ (のうちの最小値) を $m$ とおく．
- 頂点 $m$ を根，区間 $[l, m)$ から得られる二分木を左の子，区間 $[m + 1, r)$ から得られる二分木を右の子とした木を返す．

Cartesian Treeの $2$ つの頂点 $(u, v)$ の LCA は 区間 $[u, v]$ の最小値に対応します．

**計算量**

- $O(n)$