---
title: suffix_array
documentation_of: ../../src/string/suffix_array.hpp
---

## suffix_array

```cpp
vector<int> suffix_array(string s)
```

長さ $n$ の文字列 `s` のSuffix Array `sa` を返します．

`sa` は， $(0, 1, ..., n - 1)$ の順列であって，各 $i = 0, 1, ..., n - 2$ について<br>
`s[sa[i], n) < s[sa[i + 1], n)` を満たすものです．

**計算量**

- $O(n \log n)$

## lcp_array

```cpp
vector<int> lcp_array(string s, vector<int> sa)
```

`s` のLCP Array `lcp` を返します．

`lcp` は以下で定義される，長さ $n - 1$ の配列です．<br>
`lcp[i] = LCP(s[sa[i], n), s[sa[i + 1], n))`

**計算量**

- $O(n)$

## チートシート
```cpp
int op(int a, int b) {
    return min(a, b);
}
int e() {
    return (int)1e9;
}
string s;
vector<int> sa = saffix_array(s);
vector<int> lcp = lcp_array(s, sa);
SparseTable<int, op, e> st(lcp);
int len = st.query(l, r)
```
により，`LCP(s[sa[l], n), s[sa[r], n))` を前計算 $O(n \log n)$ クエリ $O(1)$ で計算できます．