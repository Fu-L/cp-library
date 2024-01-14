---
title: MinCostFlow
documentation_of: ../../src/graph/min_cost_flow.hpp
---

# MinCostFlow

[最小費用流問題](https://en.wikipedia.org/wiki/Minimum-cost_flow_problem) を解くライブラリです．

## コンストラクタ

```cpp
MinCostFlow<Cap, Cost> graph(int n)
```

- $n$ 頂点 $0$ 辺のグラフを作ります．
- `Cap`は容量の型， `Cost`はコストの型です．

**計算量**

- $O(n)$

## add_edge

```cpp
int graph.add_edge(int from, int to, Cap cap, Cost cost)
```

`from` から `to` へ最大容量 `cap` ，コスト `cost` の辺を追加し，何番目に追加された辺かを返します．

**制約**

- $0 \leq \mathrm{from}, \mathrm{to} \lt n$
- $0 \leq \mathrm{cap}, \mathrm{cost}$

**計算量**

- 償却 $O(1)$

## flow

```cpp
(1) pair<Cap, Cost> graph.flow(int s, int t)
(2) pair<Cap, Cost> graph.flow(int s, int t, Cap flow_limit)
```

$s$ から $t$ へ流せるだけ流し，その流量とコストを返します．

- (1) $s$ から $t$ へ流せるだけ流します．
- (2) $s$ から $t$ へ流量 `flow_limit` まで流せるだけ流します．

**制約**

- `slope` と同じ．

**計算量**

- `slope` と同じ．

## slope

```cpp
vector<pair<Cap, Cost>> graph.slope(int s, int t)
vector<pair<Cap, Cost>> graph.slope(int s, int t, Cap flow_limit)
```

返り値に流量とコストの関係の折れ線が入ります．<br>
全ての $x$ について，流量 $x$ の時の最小コストを $g(x)$ とすると， $(x, g(x))$ は返り値を折れ線として見たものに含まれます．

- 返り値の最初の要素は $(0, 0)$
- 返り値の `.first` ， `.second` は共に狭義単調増加．
- 3点が同一線上にあることはない．
- (1) 返り値の最後の要素は最大流量 $x$ として $(x, g(x))$
- (2) 返り値の最後の要素は $y = \min(x, \mathrm{flow\\_limit})$ として $(y, g(y))$

**制約**

辺のコストの最大を $x$ として

- $s \neq t$
- $0 \leq s, t \lt n$
- `slope` や `max_flow` を合わせて複数回呼んだときの挙動は未定義．
- `s` から `t` へ流したフローの流量が `Cap` に収まる．
- 流したフローのコストの総和が `Cost` に収まる．

**計算量**

$F$ を流量， $m$ を追加した辺の本数として

- $O(F (n + m) \log (n + m))$

## edges

```cpp
struct edge<Cap, Cost> {
    int from, to;
    Cap cap, flow;
    Cost cost;
};

(1) MinCostFlow<Cap, Cost>::edge graph.get_edge(int i)
(2) vector<MinCostFlow<Cap, Cost>::edge> graph.edges()
```

- 今の内部の辺の状態を返します．
- 辺の順番は `add_edge` で追加された順番と同一です．

$m$ を追加された辺数として

**制約**

- (1): $0 \leq i \lt m$

**計算量**

- (1): $O(1)$
- (2): $O(m)$
