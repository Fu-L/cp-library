---
title: DisjointSparseTable
documentation_of: ../../src/data_structure/disjoint_sparse_table.hpp
---

# DisjointSparseTable

モノイド，つまり

- 結合則: $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ for all $a, b, c \in S$
- 単位元の存在: $a \cdot e = e \cdot a = a$ for all $a \in S$

を満たす代数構造に対し使用できるデータ構造です．

長さ $N$ の $S$ の配列に対し，

- 区間の要素の総積の取得

を $O(1)$ で行うことができます．

ただし，これは二項演算 `op` と単位元取得 `e` が定数時間で動くと仮定したときの計算量です．<br>
これらが $O(f(n))$ かかる場合は，すべての計算量が $O(f(n))$ 倍となります．

また，要素を更新することはできません．

## コンストラクタ

```cpp
DisjointSparseTable<S, op, e> st(vector<S> v)
```

- 型 `S`
- 二項演算 `S op(S a, S b)`
- 単位元 `S e()`

を定義する必要があります．

例として，Range Minimum Queryなら，

```cpp
int op(int a, int b) {
    return min(a, b);
}
int e() {
    return (int)1e9;
}
SparseTable<int, op, e> st(v);
```

のようになります．

- 長さ `n = ssize(v)` の数列 `a` を作ります．<br>
`v` の内容が初期値となります．

**計算量**

- $O(n \log n)$

## prod

```cpp
S st.prod(int l, int r)
```

`op(a[l], a[l + 1], ..., a[r - 1])` を，モノイドの性質を満たしていると仮定して返します．<br>
$l = r$ のときは `e()` を返します．

**制約**

- $0 \leq l \leq r \leq n$

**計算量**

- $O(1)$