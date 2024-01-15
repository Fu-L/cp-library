---
title: bostan_mori
documentation_of: ../../src/fps/bostan_mori.hpp
---

## bostan_mori

```cpp
mint bostan_mori(FPS<mint> a, FPS<mint> c, ll k)
```

斉次線形漸化式
$$a_i = \sum\limits_{j=0}^{d-1} c_j a_{i-1-j}$$
の $a$ の前 $n ~(\geq d)$ 項と $c$ が与えられたときに $a_k$ を返します．

**制約**

- $0 \leq k$
- $d \leq n$

**計算量**

- $O(d \log d \log k)$