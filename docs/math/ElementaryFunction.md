## is_prime

```cpp
bool is_prime(ll n)
```

正整数 $n$ が素数であるかどうかを返します．

**制約**

- $1 \leq n$

**計算量**

- $O(\sqrt{n})$

## divisor

```cpp
vector<ll> divisor(ll n)
```

正整数 $n$ の正の約数を昇順に返します．

**制約**

- $1 \leq n$

**計算量**

- $O(\sqrt{n})$

## prime_factor

```cpp
map<ll, ll> prime_factor(ll n)
```

正整数 $n$ を素因数分解します．

**制約**

- $1 \leq n$

**計算量**

- $O(\sqrt{n})$

## seive

```cpp
pair<vector<ll>, vector<bool>> seive(ll n)
```

正整数 $n$ を与えると $2$ つの配列 `vector<ll> prime` と `vector<bool> is_prime` を返します．

`prime` には $n$ 以下の素数が昇順に格納されています．

`is_prime` は長さ $n + 1$ の配列です．<br>
$i$ が素数であるとき `is_prime[i] = true` ，そうでないとき `is_prime[i] = false` です．

**制約**

- $1 \leq n$

**計算量**

- $O(n \log \log n)$

## pow_mod

```cpp
ll pow_mod(ll x, ll n, ll mod)
```

$x^{n}$ を $\mathrm{mod}$ で割った余りを返します．

**制約**

- $0 \leq n$
- $1 \leq \mathrm{mod}$

**計算量**

- $O(\log n)$

## inv_mod

```cpp
ll inv_mod(ll x, ll mod)
```

法 $\mathrm{mod}$ における $x$ の逆元を返します．

**制約**

- $\mathrm{mod}$ は素数
- $\mathrm{mod}$ を法として $x \not\equiv 0$

**計算量**

- $O(\log \mathrm{mod})$

## inv_gcd

```cpp
pair<ll, ll> inv_gcd(ll a, ll m)
```

$\mathrm{gcd} (a, m)$ と $a^{-1} \pmod{m}$ を返します．

$m$ が素数でなくとも動作しますが， $\mathrm{gcd} (a, m) = 1$ でない場合，逆元は (存在しないので) 正しく計算できていないことに注意してください．

**制約**

- $0 \leq a$
- $1 \leq m$

**計算量**

- $O(\log m)$

## primitive_root

```cpp
int primitive_root(int m)
```

$m$ の原始根を返します．

**制約**

- $m$ は素数

**計算量**

- 期待 $O(\sqrt{m})$