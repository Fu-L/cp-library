---
title: SlideWindowAggregation
documentation_of: ../../src/data_structure/slide_window_aggregation.hpp
---

# SlideWindowAggregation

モノイド，つまり

- 結合則: $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ for all $a, b, c \in S$
- 単位元の存在: $a \cdot e = e \cdot a = a$ for all $a \in S$

を満たす代数構造に対し使用できるデータ構造です．

- queueの操作
- queue内部の全要素の総積の取得

を償却 $O(1)$ で計算できます．

ただし，これは二項演算 `op` と単位元取得 `e` が定数時間で動くと仮定したときの計算量です．<br>
これらが $O(f(n))$ かかる場合は，すべての計算量が $O(f(n))$ 倍となります．

## コンストラクタ

```cpp
SlideWindowAggregation<S, op, e> swag
```

空のキュー `swag` を作ります．

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
SlideWindowAggregation<int, op, e> swag;
```

のようになります．

**計算量**

- $O(1)$

## push

```cpp
void swag.push(S x)
```

`swag` の末尾に $x$ を挿入します．

**計算量**

- 償却 $O(1)$

## pop

```cpp
void swag.pop()
```

`swag` から先頭の要素を削除します．

**制約**

- `swag` が空でない

**計算量**

- 償却 $O(1)$

## query

```cpp
S swag.query()
```

`op(swag[0], ..., swag[|swag| - 1])` を，モノイドの性質を満たしていると仮定して計算します．

**計算量**

- $O(1)$