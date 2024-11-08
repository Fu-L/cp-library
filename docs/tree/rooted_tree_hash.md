---
title: rooted_tree_hash
documentation_of: ../../src/tree/rooted_tree_hash.hpp
---

## rooted_tree_hash

```cpp
vector<ll> rooted_tree_hash(Graph<T> g, int root = 0)
```

`root` を根とする $n$ 頂点の木 `g` を与えると，根付き木のハッシュ値を計算します．<br>
長さ $n$ の配列 `h` を返し， `h[i]` には `i` を根とする部分木のハッシュ値が格納されています．

**制約**

- `g` は木
- $0 \leq \mathrm{root} < n$

**計算量**

- $O(n)$