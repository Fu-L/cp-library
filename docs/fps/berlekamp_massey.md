---
title: berlekamp_massey
documentation_of: ../../src/fps/berlekamp_massey.hpp
---

## berlekamp_massey

```cpp
FPS<mint> berlekamp_massey(FPS<mint> s)
```

斉次線形漸化式
$$a_i = \sum\limits_{j=0}^{d-1} c_j a_{i-1-j}$$
の形で表される線形回帰数列 $a$ の前 $N$ 項が与えられたときに，数列 $c$ を返します．

$c$ を一意に確定させるためには $N \geq 2d$ が必要です．<br>
$c$ が一意に定まらない場合，条件を満たす $c$ のうち，最も $d$ を小さいものを返します．

**計算量**

- $O(N^2)$