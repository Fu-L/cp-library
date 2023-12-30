### 依存関係

- `lib/template/StaticModint.hpp` または `lib/template/DynamicModint.hpp`
- `lib/math/ElementaryFunction.hpp`

## ntt

```cpp
void ntt(vector<mint>& a, bool inv = true)
```

`a` のNumber-Theoretic Transformを計算します．

`inv = false` のとき，INTTを計算します．

**制約**

`mint` の法を $m$ として，

- $2 \leq m \leq 2 \cdot 10^9$
- $\mathrm{m}$ は素数
- $2^c | (\mathrm{m} - 1)$ かつ $|a| + |b| - 1 \leq 2^c$ なる $c$ が存在する

**計算量**

- $O(|a| \log |a| + \log m)$

## convolution

```cpp
(1) vector<mint> convolution(vector<mint> a, vector<mint> b)
(2) vector<T> convolution<int m = 998244353>(vector<T> a, vector<T> b)
```

畳み込みを行います．<br>
数列 $a_0, a_1, \cdots, a_{N - 1}$ と数列 $b_0, b_1, \cdots, b_{M - 1}$ から，長さ $N + M - 1$ の数列

$$c_i = \sum_{j = 0}^i a_j b_{i - j}$$

を $\bmod ~ m$ で計算します．

$a$ または $b$ が空配列の場合は空配列を返します．

**制約**

- $2 \leq m \leq 2 \cdot 10^9$
- $\mathrm{m}$ は素数
- $2^c | (\mathrm{m} - 1)$ かつ $|a| + |b| - 1 \leq 2^c$ なる $c$ が存在する
- (2) `T`は`int, uint, ll, ull`

**計算量**

$n = |a| + |b|$ として，

- $O(n \log n + \log m)$