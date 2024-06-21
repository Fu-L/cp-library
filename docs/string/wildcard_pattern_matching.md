---
title: wildcard_pattern_matching
documentation_of: ../../src/string/wildcard_pattern_matching.hpp
---

## wildcard_pattern_matching

```cpp
vector<bool> wildcard_pattern_matching(string t, string p)
```

ワイルドカード `*` を含むテキスト文字列 `t` とパターン文字列 `p` のパターンマッチングを行います．<br>
`t` と `p` の長さをそれぞれ $n$ と $m$ として，長さ $n - m + 1$ の `bool` 型の配列 `wpm` を返します．<br>
$n < m$ の場合には空の配列を返します．<br>
`t[i : i + m] = p[0 : m]` が成立するとき `wpm[i] = 1` であり，そうでないとき `wpm[i] = 0` です．

**計算量**

- $O((n + m) \log (n + m))$