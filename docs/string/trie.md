---
title: Trie
documentation_of: ../../src/string/trie.hpp
---

# Trie

集合に対する文字列の追加や検索を効率的に行うデータ構造です．

## コンストラクタ
```cpp
Trie<size_t X = 26, char margin = 'a'> trie(char c = '$')
```

- 文字の種類数が $X$ で最小の文字が $\mathrm{margin}$ であるような空の木 `trie` を作ります．

- $c$ は根ノードの文字です．

**計算量**

- $O(1)$

## next
```cpp
int& next(int i, int j)
```

基本的に内部用の関数です．

ノード $i$ からのびる $j$ 番目に小さい文字のノード番号を返します．<br>
そのようなノードがない場合は $-1$ を返します．

**制約**

- $i$ に存在しないノードを指定しない．
- $0 \leq j < X$

**計算量**

- $O(1)$

## insert
```cpp
void insert(string s, int x)
```

`trie` に識別子 $x$ として文字列 $s$ を追加します．

**計算量**

$s$ の長さを $n$ として，

- $O(n)$

## find
```cpp
int find(string s)
```

文字列 $s$ の最後の文字に対応するノード番号を返します．<br>
文字列 $s$ が `trie` に含まれていない場合は $-1$ を返します．

**計算量**

$s$ の長さを $n$ として，

- $O(n)$

## move
```cpp
int move(int pos, char c)
```

ノード $\mathrm{pos}$ からのびる文字 $c$ のノード番号を返します．<br>
そのようなノードがない場合は $-1$ を返します．

**計算量**

- $O(1)$

## size
```cpp
int size()
```

`trie` のノードの個数を返します．

**計算量**

- $O(1)$

## idx
```cpp
int idx(int pos)
```

ノード $\mathrm{pos}$ がある文字列の最後の文字に対応するノードである場合，その文字列の識別子を返します (2つ以上ある場合，最新のものを返します)．<br>
そうでない場合は $-1$ を返します．

**計算量**

- $O(1)$

## idxs
```cpp
vector<int> idxs(int pos)
```

ノード $\mathrm{pos}$ がある文字列の最後の文字に対応するノードである場合，その文字列の識別子をすべて返します．<br>
そうでない場合は $-1$ を返します．

**計算量**

返り値の配列の長さを $m$ として，

- $O(m)$

## count
```cpp
int count(int pos)
```

ノード $\mathrm{pos}$ 以下に格納されている文字列の個数を返します．

**計算量**

- $O(1)$