# SparseTable2D

冪等モノイド，つまり

- 結合則: $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ for all $a, b, c \in S$
- 単位元の存在: $a \cdot e = e \cdot a = a$ for all $a \in S$
- 冪等性: $a \cdot a = a$ for all $a \in S$

を満たす代数構造に対し使用できるデータ構造です．

サイズ $N \times M$ の $S$ の二次元配列に対し，

- 長方形領域の要素の総積の取得

を $O(1)$ で行うことができます．

ただし，これは二項演算 `op` と単位元取得 `e` が定数時間で動くと仮定したときの計算量です．<br>
これらが $O(f(n))$ かかる場合は，すべての計算量が $O(f(n))$ 倍となります．

また，要素を更新することはできません．

## コンストラクタ

```cpp
SparseTable2D<S, op, e> st(vector<vector<S>> v)
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
SparseTable2D<int, op, e> st(v);
```

のようになります．

- サイズ `n * m = ssize(v) * ssize(v[0])` の二次元数列 `a` を作ります．<br>
`v` の内容が初期値となります．

**計算量**

- $O(nm \log (nm))$

## query

```cpp
S st.query(int lx, int rx, int ly, int ry)
```

`op(a[lx][ly], a[lx][ly + 1], ..., a[lx][ry - 1], a[lx + 1][ly], ..., a[rx - 1][ry - 1])` を，冪等モノイドの性質を満たしていると仮定して返します．<br>
$lx = rx$ または $ly = ry$ のときは `e()` を返します．

**制約**

- $0 \leq lx \leq rx \leq n$
- $0 \leq ly \leq ry \leq n$

**計算量**

- $O(1)$