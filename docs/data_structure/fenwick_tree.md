---
title: FenwickTree
documentation_of: ../../src/data_structure/fenwick_tree.hpp
---

# FenwickTree

長さ $N$ の配列に対し，

- 1点加算
- 区間和取得

を $O(\log N)$ 時間で処理することができます．

## コンストラクタ

```cpp
FenwickTree<T> fw(int n)
```

- 長さ $n$ の配列 $a$ を作ります．初期値はすべて $0$ です．

**制約**

- $T$ は `int / uint / ll / ull / mint`

**計算量**

- $O(n)$

## add

```cpp
void fw.add(int p, T x)
```

`a[p] += x` をします．

**制約**

- $0 \leq p < n$

**計算量**

- $O(\log n)$

## sum

```cpp
T fw.sum(int l, int r)
```

`a[l] + a[l + 1] + ... + a[r - 1]` を返します．

**制約**

- $0 \leq l \leq r \leq n$

**計算量**

- $O(\log n)$

## get

```cpp
T fw.get(int x)
```

`a[x]` を返します．

**制約**

- $0 \leq x < n$

**計算量**

- $O(\log n)$