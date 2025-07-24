---
title: min_plus_convolution
documentation_of: ../../src/convolution/min_plus_convolution.hpp
---

## min_plus_convolution

```cpp
vector<T> min_plus_convolution(vector<T> a, vector<T> b)
```

長さ $n$ の下に凸な数列 $a$ と，長さ $m$ の任意の数列 $b$ から，長さ $n+m-1$の数列

$$c_i = \min_{j}\{a_{i-j} + b_{j}\}$$

を計算します．

**計算量**

- $O((n + m) \log n)$

## max_plus_convolution

```cpp
vector<T> max_plus_convolution(vector<T> a, vector<T> b)
```

長さ $n$ の上に凸な数列 $a$ と，長さ $m$ の任意の数列 $b$ から，長さ $n+m-1$の数列

$$c_i = \max_{j}\{a_{i-j} + b_{j}\}$$

を計算します．

**計算量**

- $O((n + m) \log n)$