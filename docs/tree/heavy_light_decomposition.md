---
title: HeavyLightDecomposition
documentation_of: ../../src/tree/heavy_light_decomposition.hpp
---

# HeavyLightDecomposition

木をHL分解します．

## コンストラクタ

```cpp
HeavyLightDecomposition<T> hld(Graph<T>& g, int root = 0)
```

`root` を根とする $n$ 頂点の木 `g` をHL分解します．

頂点 $v$ のheavy childが `g[v][0]` に来るように `g` が変更されます．

これを呼び出した後に `a[hld.idx(i).first] = (頂点iに関する値)` という配列を作成すると，木上の $1$ つのパスクエリを，配列上の $O(\log n)$ 個の区間クエリとして処理することができます．

**制約**

- $0 \leq \mathrm{root} < n$

**制約**

- $O(n)$

## idx

```cpp
pair<int, int> hld.idx(int i)
```

頂点 $i$ のオイラーツアー順を返します．

返り値の第一要素が行き順で，第二要素が帰り順です．

**制約**

- $0 \leq i < n$

**計算量**

- $O(1)$

## la

```cpp
int hld.la(int v, int x = 1)
```

頂点 $v$ から根方向に $x$ 個進んだ頂点のラベルを返します．

$x$ が頂点 $v$ の深さよりも大きいときは $-1$ を返します．

**制約**

- $0 \leq v < n$
- $0 \leq x$

**計算量**

- $O(\log n)$

## lca

```cpp
int hld.lca(int u, int v)
```

頂点 $u$ と $v$ の最小共通祖先を返します．

**制約**

- $0 \leq u < n$
- $0 \leq v < n$

**計算量**

- $O(\log n)$

## dist

```cpp
int hld.dist(int u, int v)
```

頂点 $u$ と $v$ の木上の距離を返します．

**制約**

- $0 \leq u < n$
- $0 \leq v < n$

**計算量**

- $O(1)$

## path_query

```cpp
void hld.path_query(int u, int v, bool vertex, F f)
```

木上のパス $u - v$ に関するクエリを処理します．

`vertex = true` のとき，パス上の頂点に関するクエリを処理し， `vertex = false` のとき，パス上の辺に関するクエリを処理します．

`f` は `void f(int u, int v)` の形のラムダ式で，構築した数列の区間 $[\min(u, v), \max(u, v))$ に対する処理を書いてください． ( $u \leq v$ は保証されません！)

**制約**

- $0 \leq u < n$
- $0 \leq v < n$

**計算量**

- $O(\log^2 n)$

## subtree_query

```cpp
void hld.subtree_query(int v, bool vertex, F f)
```

$v$ を根とする部分木に関するクエリを処理します．

`vertex = true` のとき，部分木の頂点に関するクエリを処理し， `vertex = false` のとき，部分木の辺に関するクエリを処理します．

`f` は `void f(int u, int v)` の形のラムダ式で，構築した数列の区間 $[u, v)$ に対する処理を書いてください． ( $u \leq v$ が保証されます)

**制約**

- $0 \leq v < n$

**計算量**

- $O(\log n)$