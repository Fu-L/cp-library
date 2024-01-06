---
title: linear_equation
documentation_of: ../../src/matrix/linear_equation.hpp
---

## linear_equation

```cpp
vector<vector<T>> linear_equation(Matrix<T> A, Matrix<T> b)
```

線形方程式 $Ax = b$ を解きます．

返り値は $\{v, w_1, w_2, ..., w_k\}$ という `vector<vector<T>>` です．<br>
$v$ は方程式の解のうちの $1$ つである `vector<T>` です．<br>
$w_i$ は解空間の（それぞれ独立な）基底ベクトルである `vector<T>` です．

**制約**

- $A.H() = b.H()$
- $b.W() = 1$

**計算量**

行列 $A$ のサイズを $H \times W$ として

- $O(HW^2)$