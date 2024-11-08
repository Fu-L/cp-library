---
title: Divisor/MultipleTransform
documentation_of: ../../src/math/divisor_multiple_transform.hpp
---

# DivisorTransform

```cpp
(1) void DivisorTransform::zeta_transform(vector<T>& f)
(2) void DivisorTransform::moebius_transform(vector<T>& g)
```

約数系ゼータ/メビウス変換を行います．

$$g(n) = \sum_{d | n} f(d)$$

という関係式を満たす関数 $f(n)$ と $g(n)$ を考えます．<br>
ただし $d | n$ とは， $d$ が $n$ の約数であるという意味です．

約数系ゼータ変換とは， $f(1), f(2), \dots, f(N)$ が与えられたときに $g(n)$ を計算するアルゴリズムです．<br>
約数系メビウス変換とは， $g(1), g(2), \dots, g(N)$ が与えられたときに $f(n)$ を計算するアルゴリズムです．

**計算量**

- $O(N \log \log N)$

# MultipleTransform

```cpp
(1) void MultipleTransform::zeta_transform(vector<T>& f)
(2) void MultipleTransform::moebius_transform(vector<T>& g)
```

倍数系ゼータ/メビウス変換を行います．

$$g(n) = \sum_{n | i} f(i)$$

という関係式を満たす関数 $f(n)$ と $g(n)$ を考えます．<br>
ただし $n | i$ とは， $i$ が $n$ の倍数であるという意味です．

倍数系ゼータ変換とは， $f(1), f(2), \dots, f(N)$ が与えられたときに $g(n)$ を計算するアルゴリズムです．<br>
倍数系メビウス変換とは， $g(1), g(2), \dots, g(N)$ が与えられたときに $f(n)$ を計算するアルゴリズムです．

**計算量**

- $O(N \log \log N)$