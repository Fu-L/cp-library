---
title: xor_base
documentation_of: ../../src/math/xor_base.hpp
---

## xor_base

```cpp
vector<T> xor_base(vector<T> a)
```

長さ $n$ の数列 $a$ の $\mathrm{xor}$ 基底を返します．

基底を取り出すだけであり，基本形になっているとは限らないことに注意してください．

**計算量**

$a$ の $\mathrm{xor}$ 基底の本数を $\mathrm{rank}$ として，

- $O(n \times \mathrm{rank})$