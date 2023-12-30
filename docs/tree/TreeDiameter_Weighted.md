# tree_diameter_weighted

```cpp
pair<vector<int>, T> tree_diameter_weighted(vector<vector<pair<int, T>>> g)
```

$n$ 頂点の隣接リスト形式の重み付き木 `g` を与えると，その木の直径のうち1つを選んでパスの頂点を順に格納した配列と，パス長を返します．<br> 
木の直径になりうるパスが複数あるとき，どのパスが選ばれるかは未定義です．

**制約**

- `T` は `int / uint / ll / ull / double / long double`
- `g` は木

**計算量**

- $O(n)$