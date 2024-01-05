---
title: or_convolution
documentation_of: ../../src/convolution/or_convolution.hpp
---

```cpp
vector<T> or_convolution(vector<T> a, vector<T> b)
```

OR畳み込みを行います．<br>
長さ $2^N$ の数列 $a$ と $b$ から，長さ $2^N$ の数列，

$$c_k = \sum\limits_{i \parallel j = k} a_i b_j$$

を計算します．

**制約**

- 数列 $a$ と $b$ の長さは等しい
- 数列 $a$ と $b$ の長さは $2$ の累乗である．

**計算量**

- $O(2^N N)$