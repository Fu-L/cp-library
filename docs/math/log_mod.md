---
title: log_mod
documentation_of: ../../src/math/log_mod.hpp
---

## log_mod

```cpp
ll log_mod(ll a, ll b, ll mod)
```

$a^x \equiv b \pmod{\mathrm{mod}}$ を満たす非負整数 $x$ の最小値を返します．<br>
存在しない場合は $-1$ を返します．

**計算量**

- $O(\sqrt{mod})$