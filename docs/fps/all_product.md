---
title: all_product
documentation_of: ../../src/fps/all_product.hpp
---

## all_product

```cpp
FPS<T> all_product(vector<FPS<T>> f)
```

$n$ 個の多項式 $f_0, f_1, ..., f_{n - 1}$ に対して $\prod\limits_{i = 0}^{n - 1} f_i$ を返します．

**計算量**

$f_i$ の次数を $d_i$ とし， $N := \sum\limits_{i = 0}^{n - 1} d_i$ としたとき，

- $O(N \log^2 {N})$