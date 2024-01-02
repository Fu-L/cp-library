---
title: RollingHash
documentation_of: ../../src/string/rolling_hash.hpp
---

# RollingHash

文字列 `s` に対して，

- 部分文字列のハッシュ値の取得

を 前計算 $O(|s|)$ クエリ $O(1)$ で行えるアルゴリズムです．

## コンストラクタ
```cpp
RollingHash rh(string s, ll BASE = 0)
```

- 文字列 `s` に対するローリングハッシュ，`rh` を構築します．

- 法は $2^{61} - 1$ です．`BASE` を指定しないときや負の値を指定したとき，基数は乱数となります．

**計算量**

- $O(|s|)$

## get
```cpp
ll rh.get(int lower, int upper)
```

部分文字列 `s[lower, upper)` のハッシュ値を返します．

**制約**

- $0 \leq \mathrm{lower} \leq \mathrm{upper} \leq |s|$

**計算量**

- $O(1)$

## get_hash

```cpp
ll rh.get_hash(string t)
```

文字列 `t` のハッシュ値を返します．

**計算量**

- $O(|t|)$

## find

```cpp
int rh.find(string t, int lower = 0)
```

`s` の $\mathrm{lower}$ 文字目以降で初めて文字列 `t` が現れるインデックスを返します．<br>
(存在しない場合は $-1$ を返します．)

**計算量**

- $O(|s|)$

## lcp

```cpp
int rh.lcp(RollingHash a, RollingHash b, int al, int bl)
```

文字列 `a[al, |a|)` と文字列 `b[bl, |b|)` のLongest Common Prefix (先頭から何文字一致するか) を返します．<br>
$\mathrm{min} (|a| - al, |b| - bl) \geq 0$ のときは $0$ を返します．

**計算量**

- $O(\log (|a| + |b|))$