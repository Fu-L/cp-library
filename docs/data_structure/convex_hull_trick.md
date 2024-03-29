---
title: ConvexHullTrick
documentation_of: ../../src/data_structure/convex_hull_trick.hpp
---

# ConvexHullTrick

- 直線 $y = ax + b$ の追加
- 与えられた $x$ 座標における直線群の $y$ 座標の最小値の取得

をならし $O(1)$ で処理するデータ構造です．

ただし，追加される直線の $a$ は単調非増加である必要があります．<br>
また，最小値クエリの $x$ は単調非減少である必要があります．

## コンストラクタ

```cpp
ConvecHullTrick<T> cht
```

空の直線群 `cht` を構築します．

**計算量**

- $O(1)$

## add

```cpp
void cht.add(T a, T b)
```

`cht` に直線 $y = ax + b$ を追加します．

**制約**

- $a$ は単調非増加

**計算量**

- 償却 $O(1)$

## operator ()

```cpp
T cht(T x)
```

与えられた $x$ 座標における，直線群 `cht` の $y$ 座標の最小値を取得します．

**制約**

- $x$ は単調非減少

**計算量**

- 償却 $O(1)$