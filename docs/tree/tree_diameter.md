---
title: tree_diameter
documentation_of: ../../src/tree/tree_diameter.hpp
---

# tree_diameter

```cpp
pair<T, vector<int>> tree_diameter(Graph<T> g)
```

$n$ 頂点の木 `g` を与えると，その木の直径のうち1つを選んで，パス長と，パスの頂点を順に格納した配列を返します．<br> 
木の直径になりうるパスが複数あるとき，どのパスが選ばれるかは未定義です．

**制約**

- `T` は `int / uint / ll / ull / double / long double`
- `g` は木

**計算量**

- $O(n)$