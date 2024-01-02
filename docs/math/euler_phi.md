## euler_phi

```cpp
ll euler_phi(ll n)
```

$n$ と互いに素な正の整数の個数を返します．

テーブルが必要な場合は，以下の式に従ってエラトステネスの篩のように計算するとよいです．

$\phi (n) = n \prod\limits_i (1 - \frac{1}{p_i})$ ( $p_i$ は $n$ の素因数)

**計算量**

- $O(\sqrt{n})$