---
title: lcm_convolution
documentation_of: ../../src/convolution/lcm_convolution.hpp
---

## lcm_convolution

```cpp
vector<T> lcm_convolution(vector<T> a, vector<T> b)
```

LCM畳み込みを行います．<br>
長さ $N$ の数列 $a$ と $b$ から，長さ $N$ の数列，

$$c_k = \sum\limits_{\mathrm{lcm}(i, j) = k} a_i b_j$$

を計算します．

**制約**

- 数列 $a$ と $b$ の長さは等しい．

**計算量**

- $O(N \log \log N)$