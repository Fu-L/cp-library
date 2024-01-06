---
title: inverse
documentation_of: ../../src/matrix/inverse.hpp
---

## inverse

```cpp
Matrix<T> inverse(Matrix<T> A)
```

$N \times N$ 行列 $A$ の逆行列を返します．

逆行列が存在しない場合は $0 \times 0$ の行列を返します．

**制約**

- $A$ は正方行列

**計算量**

- $O(N^3)$