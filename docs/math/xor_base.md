---
title: xor_base
documentation_of: ../../src/math/xor_base.hpp
---

## xor_base

```cpp
vector<T> xor_base(vector<T> a)
```

長さ $n$ の数列 $a$ の $\mathrm{xor}$ 基底を返します．

基本形にはなっていますが，昇順・降順にソートされているとは限らないので注意してください．

**計算量**

$a$ の $\mathrm{xor}$ 基底の本数を $\mathrm{rank}$ として，

- $O(n \times \mathrm{rank})$