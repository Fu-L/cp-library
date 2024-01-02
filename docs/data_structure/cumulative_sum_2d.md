---
title: CumulativeSum2D
documentation_of: ../../src/data_structure/cumulative_sum_2d.hpp
---

# CumulativeSum2D

$2$ 次元累積和を計算するデータ構造です．

事前に `add` で $2$ 次元配列を作り， `init` で累積和テーブルの初期化を行ってください．<br>
それ以降は `sum` で長方形領域の総和を計算できます．

## コンストラクタ

```cpp
CumulativeSum2D<T> cum(int n, int m)
```

- 型が `T` でサイズが $n \times m$ である $2$ 次元配列 `cum` を作成します．
- 初期値はすべて $0$ です．

**計算量**

- $O(nm)$

## add

```cpp
cum.add(int i, int j, T x)
```

`cum[i][j] += x` をします．

**制約**

- $0 \leq i < n$
- $0 \leq j < m$
- `init` を呼び出していない

**計算量**

- $O(1)$

## init

```cpp
cum.init()
```

$2$ 次元累積和テーブルの初期化を行います．<br>
`add` による配列の構築が終わった後，ちょうど $1$ 度だけ呼び出してください．

**計算量**

- $O(nm)$

## sum

```cpp
T cum.sum(int li, int lj, int ri, int rj)
```

長方形領域 $[li, ri) \times [lj, rj)$ における配列 `cum` の総和を返します．

**制約**

- $0 \leq li \leq ri \leq n$
- $0 \leq lj \leq rj \leq m$
- 事前に `init` をちょうど $1$ 度だけ呼び出している．

**計算量**

- $O(1)$

## get

```cpp
T cum.get(int i, int j)
```

`cum[i][j]` の値を返します．

**制約**

- $0 \leq i < n$
- $0 \leq j < m$
- 事前に `init` をちょうど $1$ 度だけ呼び出している．

**計算量**

- $O(1)$