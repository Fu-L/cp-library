---
title: WeightedUnionFind
documentation_of: ../../src/data_structure/weighted_union_find.hpp
---

# WeightedUnionFind

通常のUnionFindに加えて，

- 頂点に重みを持たせる
- 頂点の重みや頂点間の重みの差の取得
- 重みの情報が矛盾しないかの判定

ができます．

## コンストラクタ

```cpp
WeightedUnionFind<T> uf(int n)
```

- $n$ 頂点 $0$ 辺の無向グラフを作ります．
- 各頂点の重み $\mathrm{weight_i}$ は $0$ で初期化されます．

**計算量**

- $O(n)$

## merge

```cpp
bool uf.merge(int a, int b, T w)
```

辺 $(a, b)$ を追加し， $\mathrm{weight_a} = \mathrm{weight_b} + w$ と設定します．

今までの情報と矛盾が生じない場合は `true` を返し，矛盾が生じる場合は `false` を返します．<br>
矛盾が生じるとは `merge` を行う前の状態において，頂点 $a$ と $b$ が連結かつ$\mathrm{weight_a} - \mathrm{weight_b} \neq w$ であることを指します．

**制約**

- $0 \leq a < n$
- $0 \leq b < n$

**計算量**

- 償却 $O(\alpha(n))$

## same

```cpp
bool uf.same(int a, int b)
```

頂点 $a$ と $b$ が連結かどうかを返します．

**制約**

- $0 \leq a < n$
- $0 \leq b < n$

**計算量**

- 償却 $O(\alpha(n))$

## leader

```cpp
int uf.leader(int a)
```

頂点 $a$ の属する連結成分の代表元を返します．

**制約**

- $0 \leq a < n$

**計算量**

- 償却 $O(\alpha(n))$

## size

```cpp
int uf.size(int a)
```

頂点 $a$ の属する連結成分のサイズを返します．

**制約**

- $0 \leq a < n$

**計算量**

- 償却 $O(\alpha(n))$

## weight

```cpp
T uf.weight(int a)
```

$\mathrm{weight_a} - \mathrm{weight_{leader(a)}}$ を返します．

**制約**

- $0 \leq a < n$

**計算量**

- 償却 $O(\alpha(n))$

## diff

```cpp
T uf.diff(int a, int b)
```

$\mathrm{weight_a} - \mathrm{weight_b}$ を返します．

**制約**

- $0 \leq a < n$
- $0 \leq b < n$

**計算量**

- 償却 $O(\alpha(n))$
