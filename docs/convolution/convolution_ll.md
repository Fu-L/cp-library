---
title: convolution_ll
documentation_of: ../../src/convolution/convolution_ll.hpp
---

## convolution_ll

```cpp
vector<ll> convolution_ll(vector<ll> a, vector<ll> b)
```

長さ $N$ の配列 $a$ と長さ $M$ の配列 $b$ の畳み込みを `long long` で計算します．<br>
$N$ または $M$ の少なくとも一方が $0$ である場合は空配列を返します．

**制約**

- $N + M - 1 \leq 2^{24}$
- 計算結果が `long long` 型に収まる．

**計算量**

$n = N + M$ として，

- $O(n \log n)$