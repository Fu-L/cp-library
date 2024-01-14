---
title: Graph
documentation_of: ../../src/graph/graph_template.hpp
---

# Edge

グラフの辺の情報を保持する構造体です．

グラフの辺の重みを `T` とします．<br>
重みなしグラフを扱う場合も，重み $1$ の重み付きグラフと考えてください．

## コンストラクタ

```cpp
(1) Edge<T = int> e()
(2) Edge<T = int> e(int from, int to, T cost = 1, int idx = -1)
```

- (1): 有向辺 `e` を作ります．<br>
`from` などのメンバ変数は $-1$ で初期化されます．
- (2): `from` を始点 `to` を終点とする 重み `cost` の有向辺 `e` を作ります．<br>
ラベル `idx` をつけることもできます．

**計算量**

- $O(1)$

## メンバ変数

```cpp
(1) int e.from
(2) int e.to
(3) T e.cost
(4) int e.idx
```

- (1): 有向辺 `e` の始点を返します．
- (2): 有向辺 `e` の終点を返します．
- (3): `e` の重みを返します．
- (4): `e` のラベルを返します．

## operator int()

```cpp
int(e)
```

有向辺 `e` を `int` 型でキャストすると， `e.to` を返します．

**計算量**

- $O(1)$

## Tips

辺集合 `vector<Edge<T>>` を扱いたいときは， `Edges` というエイリアスが用意されています．

# Graph

グラフを扱う構造体です．

グラフの辺の重みを `T` とします．<br>
重みなしグラフを扱う場合も，重み $1$ の重み付きグラフと考えてください．

## コンストラクタ

```cpp
Graph<T = int> g(int n)
```

- $n$ 頂点 $0$ 辺のグラフを作成します．

**計算量**

- $O(n)$

## size

```cpp
size_t g.size()
```

グラフ `g` の頂点数を返します．

**計算量**

- $O(1)$

## add_edge

```cpp
void g.add_edge(int from, int to, T cost = 1)
```

頂点 `from` と頂点 `to` を結ぶ重み `cost` の無向辺を追加します．

辺のラベルはグラフに追加した順番と一致します．<br>
`from → to` の辺と `to → from` の辺のラベルは一致します．

また，メンバ変数の辺数は $1$ 本だけ増えます．

**制約**

- $0 \leq \mathrm{from} < n$
- $0 \leq \mathrm{to} < n$

**計算量**

- 償却 $O(1)$

## add_directed_edge

```cpp
void g.add_directed_edge(int from, int to, T cost = 1)
```

頂点 `from` から頂点 `to` への重み `cost` の有向辺を追加します．

辺のラベルはグラフに追加した順番と一致します．

また，メンバ変数の辺数は $1$ 本だけ増えます．

**制約**

- $0 \leq \mathrm{from} < n$
- $0 \leq \mathrm{to} < n$

**計算量**

- 償却 $O(1)$

## operator []

```cpp
vector<Edge<T>> g[int i]
```

頂点 $i$ に隣接する頂点集合を返します．

**制約**

- $0 \leq i < n$

**計算量**

- $O(1)$

## メンバ変数

```cpp
int g.es
```

`g` の辺数を返します．