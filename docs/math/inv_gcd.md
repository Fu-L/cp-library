## inv_gcd

```cpp
pair<ll, ll> inv_gcd(ll a, ll m)
```

$\mathrm{gcd} (a, m)$ と $a^{-1} \pmod{m}$ を返します．

$\mathrm{gcd} (a, m) = 1$ でない場合，動作はしますが逆元は (存在しないので) 正しく計算できていないことに注意してください．

**制約**

- $0 \leq a$
- $1 \leq m$

**計算量**

- $O(\log m)$