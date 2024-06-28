---
title: AhoCorasick
documentation_of: ../../src/string/aho_corasick.hpp
---

# AhoCorasick

複数のパターン文字列に対する文字列マッチングを行います．

## コンストラクタ
```cpp
AhoCorasick<size_t X = 26, char margin = 'a'> aho()
```

- 文字の種類数が $X$ で最小の文字が $\mathrm{margin}$ であるような空のデータ構造 `aho` を作ります．

**計算量**

- $O(1)$

## insertなど
```cpp
void insert(string s, int x)
```

`Trie` を継承しているため `Trie` にある関数が使えます．

`aho`　にパターン文字列 $s$ を識別子 $x$ として追加します．

**計算量**

$s$ の長さを $n$ として，

- $O(n)$

## build
```cpp
void build(bool heavy = true)
```

追加されたパターン文字列集合をもとにオートマトンを構築します．

**制約**

- パターン文字列を追加した後にちょうど1回だけ呼ぶ．
- `build` を呼んだ以降 `insert` を呼ばない．

**計算量**

- $O(\sum n)$

## match

```cpp
vector<int> match(string s, bool heavy = true)
```

テキスト文字列 $s$ が各パターン文字列とマッチした回数を返します．

**制約**

- `build` を呼んだ後に使う．

**計算量**

$s$ の長さを $n$ として，

- $O(n)$