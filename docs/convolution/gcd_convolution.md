---
title: gcd_convolution
documentation_of: ../../src/convolution/gcd_convolution.hpp
---

## gcd_convolution

```cpp
vector<T> gcd_convolution(vector<T> a, vector<T> b)
```

GCD畳み込みを行います．<br>
長さ $N$ の数列 $a$ と $b$ から，長さ $N$ の数列，

$$c_k = \sum\limits_{\gcd(i, j) = k} a_i b_j$$

を計算します．

**制約**

- 数列 $a$ と $b$ の長さは等しい．

**計算量**

- $O(N \log \log N)$