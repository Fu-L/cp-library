---
title: walsh_hadamard_transform
documentation_of: ../../src/math/walsh_hadamard_transform.hpp
---

## walsh_hadamard_transform

```cpp
void walsh_hadamard_transform(vector<T>& f, bool inv = false)
```

長さ $2^N$ の数列 $f$ の高速ウォルシュアダマール変換を計算します．<br>
`inv = true` のとき，逆変換を計算します．

**制約**

- 数列 $f$ の長さは $2$ の累乗である．

**計算量**

- $O(2^N N)$