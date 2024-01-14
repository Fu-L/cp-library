---
title: strongly_connected_components
documentation_of: ../../src/graph/strongly_connected_components.hpp
---

## strongly_connected_components

```cpp
vector<vector<int>> strongly_connected_components(Graph<T> g)
```

$n$ 頂点 $m$ 辺の有向グラフ `g` を強連結成分分解します．

具体的には，以下の条件を満たすような「頂点のリスト」のリストを返します．

- 全ての頂点がちょうど1つずつ，どれかのリストに含まれます．
- 内側のリストと強連結成分が一対一に対応します．<br>
リスト内での頂点の順序は未定義です．
- リストはトポロジカルソートされています．<br>
異なる強連結成分の頂点 $u, v$ について， $u$ から $v$ に到達できるとき， $u$ の属するリストは $v$ の属するリストよりも前です．

**計算量**

- $O(n + m)$

## scc_ids

```cpp
pair<int, vector<int>> scc_ids(Graph<T> g)
```

内部処理用の関数です．<br>
把握の必要はありません．