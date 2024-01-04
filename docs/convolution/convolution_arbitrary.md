---
title: convolution_arbitrary
documentation_of: ../../src/convolution/convolution_arbitrary.hpp
---

## convolution_arbitrary

```cpp
vector<mint> convolution_arbitrary(vector<mint> a, vector<mint> b)
```

任意 $\mathrm{mod}$ 畳み込みを行います．<br>
数列 $a_0, a_1, \cdots, a_{N - 1}$ と数列 $b_0, b_1, \cdots, b_{M - 1}$ から，長さ $N + M - 1$ の数列

$$c_i = \sum_{j = 0}^i a_j b_{i - j}$$

を計算します．

$a$ または $b$ が空配列の場合は空配列を返します．

**制約**

`mint` の法を $m$ として，

- $2 \leq m \leq 2 \cdot 10^9$

**計算量**

$n = N + M$ として，

- $O(n \log n + \log m)$