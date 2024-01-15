---
title: nth_term
documentation_of: ../../src/fps/nth_term.hpp
---

## nth_term

```cpp
mint nth_term(FPS<mint> s, ll n)
```

斉次線形漸化式

$$a_i = \sum\limits_{j = 0}^{d - 1} c_j a_{i - 1 - j}$$

の形で表される線形回帰数列 $a$ の前 $k$ 項が与えられたときに $a_n$ を返します．

$c$ を一意に確定させるために $k \geq 2d$ が必要です．<br>
$k < 2d$ の場合，正しく計算できていない可能性があるので注意してください．

**制約**

- $0 \leq n$

**計算量**

- $O(k^2 + k \log k \log n)$
