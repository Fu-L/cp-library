---
title: DynamicRollingHash
documentation_of: ../../src/string/dynamic_rolling_hash.hpp
---

# DynamicRollingHash

長さ $n$ の文字列 `s` に対して，

- 部分文字列のハッシュ値の取得
- 1文字更新

を，前計算 $O(n \log n)$ クエリ $O(\log n)$ で行えるアルゴリズムです．

## コンストラクタ
```cpp
DynamicRollingHash drh(string s, ull BASE = 0)
```

- 長さ $n$ の文字列 `s` に対する動的ローリングハッシュ，`drh` を構築します．

- 法は $2^{61} - 1$ です．`BASE` を指定しないときや $0$ を指定したとき，基数は乱数となります．

**計算量**

- $O(n \log n)$

## get
```cpp
ull drh.get(int lower, int upper)
```

部分文字列 `s[lower, upper)` のハッシュ値を返します．

**制約**

- $0 \leq \mathrm{lower} \leq \mathrm{upper} \leq n$

**計算量**

- $O(\log n)$

## get_hash

```cpp
ull drh.get_hash(string t)
```

長さ $m$ の文字列 `t` のハッシュ値を返します．

**計算量**

- $O(m)$

## set

```cpp
void drh.set(int idx, char c)
```

`s[idx]` を `c` に更新します．

**制約**

- $0 \leq \mathrm{idx} < n$

**計算量**

- $O(\log n)$
