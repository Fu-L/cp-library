---
title: z_algorithm
documentation_of: ../../src/string/z_algorithm.hpp
---

## z_algorithm

```cpp
vector<int> z_algorithm(string s)
```

`s` の長さを $n$ として，長さ $n$ の配列 `z` を返します．<br>
`z[i] = LCP(s, s[i, n))` です．<br>
(LCPとは，Longest Common Prefix (先頭から何文字一致しているか) の略です．)

**計算量**

- $O(n)$