---
title: EratosthenesSieve
documentation_of: ../../src/math/eratosthenes_sieve.hpp
---

# EratosthenesSieve

```cpp
EratosthenesSieve sieve(int N)
```

$N$ 以下の正の整数に対してエラトステネスの篩を行います．

## メンバ変数

```cpp
(1) vector<int> sieve.primes
(2) vector<int> sieve.min_factor
(3) vector<int> sieve.moebius
(4) vector<int> sieve.euler
```

- (1): $N$ 以下の素数が昇順に格納されています．
- (2): `sieve.min_factor[i]` に $i$ の素因数の最小値が格納された，長さ $N + 1$ の配列です．<br>
便宜上 `min_factor[0] = min_factor[1] = -1` としています．<br>
$i$ が素数であることと `min_factor[i] = i` であることは同値です．<br>
- (3): `sieve.moebius[i]` に $\mu(i)$ が格納された，長さ $N + 1$ の配列です．
- (4): `sieve.euler[i]` に $\phi(i)$ が格納された，長さ $N + 1$ の配列です．

**制約**

- $1 \leq N$

**計算量**

- $O(N \log \log N)$

## prime_factors

```cpp
vector<pair<int, int>> prime_factors(int n)
```

正整数 $n$ を素因数分解します．

**制約**

- $1 \leq n \leq N$

**計算量**

- $O(\log{n})$

## divisor

```cpp
vector<int> divisor(int n)
```

正整数 $n$ の正の約数を昇順に返します．

**制約**

- $1 \leq n \leq N$

**計算量**

- $O(\log{n})$