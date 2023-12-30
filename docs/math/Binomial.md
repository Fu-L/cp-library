### 依存関係

- `lib/template/StaticModint.hpp` または `lib/template/DynamicModint.hpp`

# Binomial

- 二項係数 $_n C _k \pmod{p}$

などを計算するアルゴリズムです．

## コンストラクタ

```cpp
Binomial<mint> binom(int N)
```

- `mint` の法 $p$ における $0!$ ~ $N!$ および $(0!)^{-1}$ ~ $(N!)^{-1}$ のテーブルを構築します．

**制約**

- $\forall_{1 \leq i \leq N} ~ \mathrm{gcd} (i, p) = 1$

**計算量**

- $O(N)$

## fact

```cpp
mint binom.fact(int n)
```

$n! \pmod{p}$ を返します．

$n < 0$ の場合は $0$ を返します．

**制約**

- $n \leq N$

**計算量**

- $O(1)$

## perm

```cpp
mint binom.perm(int n, int k)
```

$_n P _k \pmod{p}$ を返します．

$n < 0$ または $n < k$ または $k < 0$ の場合は $0$ を返します．

**制約**

- $n \leq N$

**計算量**

- $O(1)$

## comb, operator ()

```cpp
(1) mint binom.comb(int n, int k)
(2) mint binom(int n, int k)
```

$_n C _k \pmod{p}$ を返します．

$n < 0$ または $n < k$ または $k < 0$ の場合は $0$ を返します．

**制約**

- $n \leq N$

**計算量**

- $O(1)$

## homo

```cpp
mint binom.homo(int n, int k)
```

$_n H _k \pmod{p}$ を返します．

$n < 0$ または $k < 0$ の場合は $0$ を返します．<br>
$k = 0$ の場合は $1$ を返します．

**制約**

- $n + k - 1 \leq N$

**計算量**

- $O(1)$