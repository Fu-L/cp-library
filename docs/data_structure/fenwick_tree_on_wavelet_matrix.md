---
title: FenwickTreeonWaveletMatrix
documentation_of: ../../src/data_structure/fenwick_tree_on_wavelet_matrix.hpp
---

# FenwickTreeonWaveletMatrix

矩形和クエリに高速に答えるデータ構造です．<br>
更新クエリがある場合，クエリが先読みできる必要があります．

## コンストラクタ

```cpp
FenwickTreeonWaveletMatrix<S, T> wm;
```

点がない状態の $2$ 次元平面を作ります．

`S` は点の座標の型で， `T` は点の重みの型です．

**計算量**

- $O(1)$

## add_point

```cpp
void wm.add_point(S x, S y)
```

平面上に点 $(x, y)$ を追加します．<br>
重なりがあっても構いません．

**制約**

- `build` をした後に呼び出してはいけない

**計算量**

- $O(1)$

## build

```cpp
void wm.build()
```

`wm` の初期化を行います．

**計算量**

点の数を $n$ 個として

- $O(n \log n)$

## add

```cpp
void wm.add(S x, S y, T w)
```

点 $(x, y)$ の重みを $w$ 増加させます．

`add_point` で登録していない点を呼び出した場合の動作は未定義です． (assertなどはないので要注意！)

**制約**

- `add_point` で登録していない点を呼ばない

**計算量**

- $O(\log^2 n)$

## sum

```cpp
T wm.sum(S l, S d, S r, S u)
```

$l \leq x < r, d \leq y < u$ を満たす点について，重みの総和を求めます．

**制約**

- $l \leq r$
- $d \leq u$

**計算量**

- $O(\log^2 n)$