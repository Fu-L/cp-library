---
title: gauss_elimination
documentation_of: ../../src/matrix/gauss_elimination.hpp
---

## gauss_elimination

```cpp
pair<int, T> gauss_elimination(Matrix<T>& A, int pivot_end = -1)
```

$H \times W$ 行列 $A$ の階数と行列式を返します．<br>
副作用として $A$ は簡約階段系になります．

$A$ が正方行列でないとき，返り値の行列式の値は未定義です．

$\mathrm{pivot\\_end}$ で行列の何列目までを見て欲しいかを指定することができます．(実質的に内部用の変数)<br>
$\mathrm{pivot\\_end} = -1$ のときは $W$ 列目まで見ます．

**制約**

- $-1 \leq \mathrm{pivot\\_end} \leq W$

**計算量**

- $O(HW^2)$
