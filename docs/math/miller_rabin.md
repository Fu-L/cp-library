---
title: miller_rabin
documentation_of: ../../src/math/miller_rabin.hpp
---

## miller_rabin

```cpp
bool miller_rabin(ll n)
```

整数 $n$ が素数であるか判定します．<br>
$n$ が非正の場合は `false` を返します．

**計算量**

- $O(\log n)$