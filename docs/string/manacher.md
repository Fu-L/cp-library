---
title: manacher
documentation_of: ../../src/string/manacher.hpp
---

## manacher

```cpp
vector<int> manacher(string s)
```

長さ $n$ の文字列 $s$ に含まれる回文の中心として考えられる位置は $2n - 1$ 個あります．<br>
それぞれの位置 $i$ について $i$ を中心とする最長の回文の長さ $l_{i}$ を並べた長さ $2n - 1$ の配列 `l` を返します．<br>
存在しない場合は $l_{i} = 0$ とします．

**計算量**

- $O(n)$