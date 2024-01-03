---
title: extgcd
documentation_of: ../../src/math/extgcd.hpp
---

## extgcd

```cpp
ll extgcd(ll a, ll b, ll& x, ll& y)
```

$\mathrm{gcd}(a, b)$ を返します．<br>
副作用として $(x, y)$ に $ax + by = \mathrm{gcd}(a, b)$ を満たす整数解が格納されます．<br>
整数解は無数に存在しますが， $\mathrm{abs}(x) + \mathrm{abs}(y)$ が最小であるものが採用されます．<br>
$\mathrm{abs}(x) + \mathrm{abs}(y)$ が最小であるものが複数存在する場合は，その中で $x \leq y$ であるものが採用されます．

**計算量**

- $O(\log \min(a, b))$