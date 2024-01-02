---
title: seive
documentation_of: ../../src/math/seive.hpp
---

## seive

```cpp
pair<vector<int>, vector<int>> seive(int n)
```

正整数 $n$ を与えると $2$ つの配列 `prime` と `min_factor` を返します．

`prime` には $n$ 以下の素数が昇順に格納されています．

`min_factor` は長さ $n + 1$ の配列です．<br>
`min_factor[i]` は $i$ の素因数の最小値が格納されています．<br>
便宜上 `min_factor[0] = min_factor[1] = -1` としています．

$i$ が素数であることと `min_factor[i] = i` であることは同値です．

また以下のようにして，前計算 $O(n \log \log n)$ クエリ $O(\log n)$ で $n$ を素因数分解できます．

```cpp
vector<int> prime_factor;
while(n > 1) {
    prime_factor.push_back(min_factor[n])
    n /= min_factor[n];
}
```

**制約**

- $1 \leq n$

**計算量**

- $O(n \log \log n)$