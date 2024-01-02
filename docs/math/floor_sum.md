---
title: floor_sum
documentation_of: ../../src/math/floor_sum.hpp
---

## floor_sum

```cpp
ll floor_sum(ll n, ll m, ll a, ll b)
```

$$\sum_{i = 0}^{n - 1} \left\lfloor \frac{a \times i + b}{m} \right\rfloor$$

を返します．

**制約**

- $0 \leq n \leq 10^9$
- $1 \leq m \leq 10^9$
- 答えがオーバーフローしないこと．

**計算量**

- $O(\log (n + m + a + b))$