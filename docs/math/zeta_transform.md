---
title: zeta_transform
documentation_of: ../../src/math/zeta_transform.hpp
---

## zeta_transform

```cpp
(1) void superset_zeta_transform(vector<T>& f, bool inv = false)
(2) void subset_zeta_transform(vector<T>& f, bool inv = false)
```

長さ $2^N$ の数列 $f$ に対して，

- (1): 上位集合高速ゼータ変換 ( `inv = true` ならばメビウス変換) を計算します．
- (2): 下位集合高速ゼータ変換 ( `inv = true` ならばメビウス変換) を計算します．

上位・下位高速ゼータ変換の定義式は以下の通りで，メビウス変換はその逆変換です．

$$ (1) ~ g_x = \sum\limits_{i \supseteq x} f_i$$
$$ (2) ~ g_x = \sum\limits_{i \subseteq x} f_i$$

**制約**

- 数列 $f$ の長さは $2$ の累乗である．

**計算量**

- $O(2^N N)$