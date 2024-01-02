---
title: FenwickTree2D
documentation_of: ../../src/data_structure/fenwick_tree_2d.hpp
---

# FenwickTree2D

サイズが $N \times M$ である $2$ 次元配列に対し，

- $1$ 点加算
- 長方形領域の総和の取得

を $O(\log N \log M)$ 時間で処理することができます．

## コンストラクタ

```cpp
FenwickTree2D<T> fw(int n, int m)
```

- 型が `T` でサイズが $n \times m$ である$2$ 次元配列 `fw` を作ります．<br>
- 初期値はすべて $0$ です．

**計算量**

- $O(nm)$

## add

```cpp
void fw.add(int i, int j, T x)
```

`fw[i][j] += x` をします．

**制約**

- $0 \leq i < n$
- $0 \leq j < m$

**計算量**

- $O(\log n \log m)$

## sum

```cpp
T fw.sum(int li, int lj, int ri, int rj)
```

長方形領域 $[li, ri) \times [lj, rj)$ における配列 `fw` の総和を返します．

**制約**

- $0 \leq li \leq ri \leq n$
- $0 \leq lj \leq rj \leq m$

**計算量**

- $O(\log n \log m)$

## get

```cpp
T fw.get(int i, int j)
```

`fw[i][j]` を返します．

**制約**

- $0 \leq i < n$
- $0 \leq j < m$

**計算量**

- $O(\log n \log m)$