---
title: PermutedCongruentialGenerator
documentation_of: ../../src/random/permuted_congruential_generator.hpp
---

# PermutedCongruentialGenerator

- 一様ランダムな整数・実数

を生成します．

メルセンヌツイスタを用いた `RandomNumberGenerator` よりやや質が悪いですが，かなり高速です．
アルゴリズムコンテストでは `RandomNumberGenerator` を使い，ヒューリスティックコンテストでは `PermutedCongruentialGenerator` を使うことを推奨します．

# コンストラクタ

```cpp
PermutedCongruentialGenerator rng()
```

- 乱数生成器 `rng` を作成します．シードには実行時の時刻を用いています．

**計算量**

- $O(1)$

# operator ()

```cpp
T rng(T l, T r)
```

$[l, r]$ の範囲の整数・実数を一様ランダムに返します．

**制約**

- $l \leq r$
- `T` は `int` か `unsigned int` か `double`

**計算量**

- $O(1)$