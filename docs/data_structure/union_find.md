---
title: UnionFind
documentation_of: ../../src/data_structure/union_find.hpp
---

# UnionFind

- 頂点集合のマージ
- $2$ 頂点が連結かの判定
- 頂点集合の代表元の取得
- 頂点集合のサイズの取得
- 頂点集合の列挙

を償却 $O(\alpha(n))$ 時間で処理することができます．

## コンストラクタ

```cpp
UnionFind uf(int n)
```

- $n$ 頂点 $0$ 辺の無向グラフを作ります．

**計算量**

- $O(n)$

## merge

```cpp
int uf.merge(int a, int b)
```

辺 $(a, b)$ を足します．

頂点 $a$ と $b$ が連結だった場合はその代表元，非連結だった場合は新たな代表元を返します．

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

## groups

```cpp
vector<vector<int>> uf.groups()
```

グラフを連結成分に分け，その情報を返します．

返り値は「「一つの連結成分の頂点番号のリスト」のリスト」です．<br>
(内側外側限らず) vector内でどの順番で頂点が格納されているかは未定義です．

**計算量**

- $O(n)$