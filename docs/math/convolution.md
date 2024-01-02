## convolution

```cpp
vector<mint> convolution(vector<mint> a, vector<mint> b)
```

畳み込みを行います．<br>
数列 $a_0, a_1, \cdots, a_{N - 1}$ と数列 $b_0, b_1, \cdots, b_{M - 1}$ から，長さ $N + M - 1$ の数列

$$c_i = \sum_{j = 0}^i a_j b_{i - j}$$

を計算します．

$a$ または $b$ が空配列の場合は空配列を返します．

**制約**

`mint` の法を $m$ として，

- $\mathrm{m}$ は素数
- $2^c | (\mathrm{m} - 1)$ かつ $|a| + |b| - 1 \leq 2^c$ なる $c$ が存在する

**計算量**

$n = |a| + |b|$ として，

- $O(n \log n + \log m)$

## butterfly

```cpp
void butterfly(vector<mint>& a)
```

`a` のNumber-Theoretic Transformを計算します．<br>
参照渡しであることに注意してください．

**制約**

`mint` の法を $m$ として，

- $\mathrm{m}$ は素数
- $2^c | (\mathrm{m} - 1)$ かつ $|a| + |b| - 1 \leq 2^c$ なる $c$ が存在する

**計算量**

- $O(|a| \log |a| + \log m)$

## butterfly_inv

```cpp
void butterfly_inv(vector<mint>& a)
```

`a` のInverse Number-Theoretic Transformを計算します．<br>
参照渡しであることに注意してください．

**制約**

`mint` の法を $m$ として，

- $\mathrm{m}$ は素数
- $2^c | (\mathrm{m} - 1)$ かつ $|a| + |b| - 1 \leq 2^c$ なる $c$ が存在する

**計算量**

- $O(|a| \log |a| + \log m)$