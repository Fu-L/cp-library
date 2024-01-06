---
title: Matrix
documentation_of: ../../src/matrix/matrix.hpp
---

# Matrix

行列演算を行うライブラリです．

## コンストラクタ

```cpp
Matrix<T> mat(int h, int w, T val = 0)
```

- $h \times w$ 行列を構築します．
- 初期値は全て $\mathrm{val}$ となります．

**計算量**

- $O(hw)$

## H

```cpp
int mat.H()
```

行列 `mat` の行数を返します．

**計算量**

- $O(1)$

## W

```cpp
int mat.W()
```

行列 `mat` の列数を返します．

**計算量**

- $O(1)$

## I

```cpp
Matrix<T> Matrix::I(int n)
```

$n$ 次単位行列を返します．

**計算量**

- $O(n^2)$

## operator []

```cpp
vector<T> mat[int i]
```

行列 `mat` の $i$ 行目を返します．

**制約**

- $0 \leq i < h$

**計算量**

- $O(w)$

## 各種演算

```cpp
Matrix += Matrix
Matrix -= Matrix
Matrix *= Matrix

Matrix + Matrix
Matrix - Matrix
Matrix * Matrix

Matrix == Matrix
Matrix != Matrix
```

が動きます．

**制約**

`a += b` と `a -= b` と `a + b` と `a - b` と `a == b` と `a != b` を行うとき，
- $a.H() = b.H()$ かつ $a.W() = b.W()$

`a * b` を行うとき，
- $a.W() = b.H()$

**計算量**

- $O(a.H() \times a.W())$ (掛け算以外)
- $O(a.H() \times a.W() \times b.W())$ (掛け算)

## pow

```cpp
Matrix<T> mat.pow(ll n)
```

$\mathrm{mat}^n$ を返します．

**制約**

- $\mathrm{mat}$ は正方行列である
- $0 \leq n$

**計算量**

- $O(h^3 \log n)$