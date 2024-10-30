---
title: WaveletMatrix
documentation_of: ../../src/data_structure/wavelet_matrix.hpp
---

# WaveletMatrix

静的な非負整数列に対するさまざまな区間クエリを $O(\log n)$ で行えるデータ構造です．

## コンストラクタ

```cpp
(1) WaveletMatrix<T> wm(int n)
(2) WaveletMatrix<T> wm(vector<T> a)
```

- (1): 長さ `n` の数列 `wm` を作ります．初期値は $0$ です．
- (2): 長さ `n = ssize(v)` の数列 `wm` を作り， `v` の内容を初期値として `build` を行います．

**計算量**

- (1) $O(n)$
- (2) $O(n \log n)$

## set

```cpp
void wm.set(int i, T x)
```

`wm[i]` に $x$ を代入します．

**制約**

- $0 \leq n < n$
- $0 \leq x$
- `build` をした後に呼び出してはいけない

**計算量**

- $O(1)$

## build

```cpp
void wm.build()
```

`wm` の初期化を行います．

**計算量**

- $O(n \log n)$

## get

```cpp
T wm.get(int i)
```

`wm[i]` を返します．

**制約**

- $0 \leq i < n$

**計算量**

- $O(\log n)$

## kth_smallest

```cpp
T wm.kth_smallest(int l, int r, int k)
```

`wm[l, r)` における $k$ 番目 ( $0 \mathrm{-indexed}$ ) に小さい値を返します．

**制約**

- $0 \leq l \leq r \leq n$
- $0 \leq k < r - l$

**計算量**

- $O(\log n)$

## kth_largest

```cpp
T wm.kth_largest(int l, int r, int k)
```

`wm[l, r)` における $k$ 番目 ( $0 \mathrm{-indexed}$ ) に大きい値を返します．

**制約**

- $0 \leq l \leq r \leq n$
- $0 \leq k < r - l$

**計算量**

- $O(\log n)$

## range_freq

```cpp
(1) int range_freq(int l, int r, T upper)
(2) int range_freq(int l, int r, T lower, T upper)
```

(1) `wm[l, r)` における $\mathrm{upper}$ 未満の要素の個数を返します．<br>
(2) `wm[l, r)` における $\mathrm{lower}$ 以上 $\mathrm{upper}$ 未満の要素の個数を返します．

**制約**

- $0 \leq l \leq r \leq n$
- (2) $\mathrm{lower} \leq \mathrm{upper}$

**計算量**

- $O(\log n)$

## prev_value

```cpp
T wm.prev_value(int l, int r, T upper)
```

`wm[l, r)` における $\mathrm{upper}$ 未満の最大値を返します．<br>
そのような値が存在しない存在しない場合は $-1$ を返します．

**制約**

- $0 \leq l \leq r \leq n$

**計算量**

- $O(\log n)$

## next_value

```cpp
T wm.next_value(int l, int r, T lower)
```

`wm[l, r)` における $\mathrm{lower}$ 以上の最小値を返します．<br>
存在しない場合は $-1$ を返します．

**制約**

- $0 \leq l \leq r \leq n$

**計算量**

- $O(\log n)$