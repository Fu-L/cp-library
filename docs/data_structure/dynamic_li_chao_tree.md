# DynamicLiChaoTree

- 直線 $y = ax + b$ の追加
- 線分 $y = ax + b ~ (l \leq x < r)$ の追加
- 与えられた $x$ 座標における直線・線分群の $y$ 座標の最小値の取得

を処理するデータ構造です．

`ConvexHullTrick` よりやや計算量は重いですが，単調性が必要ありません．

## コンストラクタ

```cpp
DynamicLiChaoTree<T, T x_low, T x_high> cht
```

空の直線・線分群 `cht` を構築します．

$x_{low}$ には `query` で与える $x$ の最小値を， $x_{high}$ には `query` で与える $x$ の最大値を与えてください．<br>
以下， $V = x_{high} - x_{low}$ とおきます．

**計算量**

- $O(1)$

## add_line

```cpp
void cht.add_line(T a, T b)
```

`cht` に直線 $y = ax + b$ を追加します．

**計算量**

- $O(\log V)$

## add_segment

```cpp
void cht.add_segment(T l, T r, T a, T b)
```

`cht` に線分 $y = ax + b ~ (l \leq x < r)$ を追加します．

**計算量**

- $O(\log V^2)$

## operator ()

```cpp
T cht(T x)
```

与えられた $x$ 座標における，直線・線分群 `cht` の $y$ 座標の最小値を取得します．

**制約**

- $x_{low} \leq x \leq x_{high}$

**計算量**

- $O(\log V)$