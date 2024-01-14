---
title: MaxFlow
documentation_of: ../../src/graph/max_flow.hpp
---

# MaxFlow

[最大流問題](https://ja.wikipedia.org/wiki/%E6%9C%80%E5%A4%A7%E3%83%95%E3%83%AD%E3%83%BC%E5%95%8F%E9%A1%8C) を解くライブラリです。

## コンストラクタ

```cpp
MaxFlow<Cap> graph(int n)
```

- `n` 頂点 $0$ 辺のグラフを作ります．
- `Cap` は容量の型です．

**計算量**

- $O(n)$

## add_edge

```cpp
int graph.add_edge(int from, int to, Cap cap);
```

`from` から `to` へ最大容量 `cap` ，流量 $0$ の辺を追加し，何番目に追加された辺かを返します．

**制約**

- $0 \leq \mathrm{from}, \mathrm{to} \lt n$
- $0 \leq \mathrm{cap}$

**計算量**

- 償却 $O(1)$

## flow

```cpp
(1) Cap graph.flow(int s, int t);
(2) Cap graph.flow(int s, int t, Cap flow_limit);
```

- (1) 頂点 $s$ から $t$ へ流せる限り流し，流せた量を返します．
- (2) 頂点 $s$ から $t$ へ流量 `flow_limit` に達するまで流せる限り流し，流せた量を返します．

複数回呼ぶことも可能です．

**制約**

- $s \neq t$
- $0 \leq s, t \lt n$
- 返り値が `Cap` に収まる．

**計算量**

$m$ を追加された辺数として

- $O((n + m) \sqrt{m})$ (辺の容量がすべて $1$ の時)
- $O(n^2 m)$
- 返り値を $F$ として $O(F(n + m))$

## min_cut

```cpp
vector<bool> graph.min_cut(int s)
```

長さ $n$ のvectorを返します．<br>
$i$ 番目の要素には，頂点 $s$ から $i$ へ残余グラフで到達可能なとき，またその時のみ `true` を返します．<br>
`flow(s, t)` をflow_limitなしでちょうど一回呼んだ後に呼ぶと，返り値は $s, t$ 間のmincutに対応します．

**制約**

- $0 \leq s < n$

**計算量**

$m$ を追加された辺数として

- $O(n + m)$

## get_edge / edges

```cpp
struct MaxFlow<Cap>::edge {
    int from, to;
    Cap cap, flow;
};

(1) MaxFlow<Cap>::edge graph.get_edge(int i);
(2) vector<MaxFlow<Cap>::edge> graph.edges();
```

- 今の内部の辺の状態を返します．
- 辺の順番はadd_edgeで追加された順番と同一です．

**制約**

- (1): $0 \leq i \lt m$

**計算量**

$m$ を追加された辺数として

- (1): $O(1)$
- (2): $O(m)$

## change_edge

```cpp
void graph.change_edge(int i, Cap new_cap, Cap new_flow);
```

$i$ 番目に追加された辺の容量，流量を`new_cap` , `new_flow`に変更します．<br>
他の辺の容量，流量は変更しません．

**制約**

- $0 \leq \mathrm{newflow} \leq \mathrm{newcap}$

**計算量**

- $O(1)$