## chinese_remainder_theorem

```cpp
pair<ll, ll> chinese_remainder_theorem(vectpr<ll> r, vector<ll> m)
```

同じ長さの配列 $r, m$ を渡します．<br>
この配列の長さを $n$ としたとき，

$$x \equiv r[i] \pmod{m[i]}, \forall i \in \lbrace 0,1,\cdots, n - 1 \rbrace$$

を解きます．<br>
答えは (存在するならば) $y, z (0 \leq y < z = \mathrm{lcm}(m[i]))$ を用いて $x \equiv y \pmod z$ の形で書けることが知られており，この $(y, z)$ をpairとして返します．<br>
答えがない場合は $(0, 0)$ を返します．<br>
$n = 0$ の時は $(0, 1)$ を返します．

**制約**

- $|r| = |m|$
- $1 \le m[i]$
- $\mathrm{lcm} (m[i])$ が `ll` に収まる．

**計算量**

- $O(n \log \mathrm{lcm} (m[i]))$