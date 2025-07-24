---
title: monotone_minima
documentation_of: ../../src/dp/monotone_minima.hpp
---

## monotone_minima

```cpp
vector<int> monotome_minima<F>(int n, int m, F f)
```

$n \times m$ のmonotone行列 $A$ に対して，各行における最小値を取る列を列挙します．<br>
以下の要件を満たす関数 `bool f(int i, int j, int k)` を定義する必要があります．<br>
- $A[i][j] < A[i][k]$ のとき `true` を返す ( $j < k$ が保証される．等号はどちらでもよい)．

**計算量**

- $O((n + m) \log n)$