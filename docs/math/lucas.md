---
title: Lucas
documentation_of: ../../src/math/lucas.hpp
---

# Lucas

- 二項係数 $_n C _k \pmod{p}$

などを計算するアルゴリズムです．

$p$ が素数でさえあれば $n > p$ の場合でも正しく計算できることが特徴です．

## コンストラクタ

```cpp
Lucas<mint> binom
```

- `mint` の法 $p$ における $0!$ ~ $(p - 1)!$ および $(0!)^{-1}$ ~ $((p - 1)!)^{-1}$ のテーブルを構築します．

**制約**

- $p$ は素数

**計算量**

- $O(p)$

## operator ()

```cpp
mint binom(ll n, ll k)
```

$_n C _k \pmod{p}$ を計算します．

$n < 0$ または $n < k$ または $k < 0$ の場合は $0$ を返します．

**計算量**

- $O(\log_p n)$