---
title: longest_increasing_sequence
documentation_of: ../../src/dp/longest_increasing_sequence.hpp
---

## longest_increasing_sequence

```cpp
vector<int> longest_increasing_sequence(vector<T> a)
```

長さ $n$ の配列 `a` の最長増加部分列 `lcp` を計算します．<br>
`lcp[i]` は，最長増加部分列の $i$ 番目の要素の添え字を表します．

**計算量**

- $O(n \log n)$