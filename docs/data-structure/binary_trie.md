# BinaryTrie

- 値の挿入・削除
- 値の検索
- 要素数の取得
- 全要素に `xor` を作用させる
- 最小値，最大値，ランダムアクセス
- lower_bound, upper_bound

を $O(d)$ で行えるデータ構造です．( $d$ は値の桁数)

## コンストラクタ

```cpp
BinaryTrie<T, MAX_LOG> trie
```

- $0$ 以上 $2^{MAX\\_LOG}$ 未満の値を格納できる空の `trie` を構築します．

**制約**

- $T$ は `int / uint / ll / ull`
- $2^{MAX\\_LOG}$ が $T$ で表現できる値に収まる

**計算量**

- $O(1)$

## insert

```cpp
void trie.insert(T x)
```

`trie` に $x$ を挿入します．<br>
すでに `trie` に $x$ が存在する場合は何もしません．

**制約**

- $0 \leq x < 2^{MAX\\_LOG}$

**計算量**

- $O(MAX\\_LOG)$

## erase

```cpp
void trie.erase(T x)
```

`trie` から $x$ を削除します．<br>
すでに `trie` に $x$ が存在しない場合は何もしません．

**制約**

- $0 \leq x < 2^{MAX\\_LOG}$

**計算量**

- $O(MAX\\_LOG)$

## contains

```cpp
bool trie.contains(T x)
```

`trie` に $x$ が含まれるかどうかを返します．

**制約**

- $0 \leq x < 2^{MAX\\_LOG}$

**計算量**

- $O(MAX\\_LOG)$

## size

```cpp
int trie.size()
```

`trie` に何個の要素が格納されているかを返します．

**計算量**

- $O(1)$

## min

```cpp
T trie.min(T x = 0)
```

`trie` に格納されている要素全てに対して $\mathrm{xor} ~ x$ を作用させたときの最小値を返します．

**制約**

- $0 \leq x < 2^{MAX\\_LOG}$

**計算量**

- $O(MAX\\_LOG)$

## max

```cpp
T trie.max(T x = 0)
```

`trie` に格納されている要素全てに対して $\mathrm{xor} ~ x$ を作用させたときの最大値を返します．

**制約**

- $0 \leq x < 2^{MAX\\_LOG}$

**計算量**

- $O(MAX\\_LOG)$

## kth_element

```cpp
T trie.kth_element(T x = 0)
```

`trie` に格納されている要素全てに対して $\mathrm{xor} ~ x$ を作用させたときの $k$ 番目に小さい値を返します．

**制約**

- $0 \leq k < \mathrm{trie.size()}$
- $0 \leq x < 2^{MAX\\_LOG}$

**計算量**

- $O(MAX\\_LOG)$

## lower_bound

```cpp
int trie.lower_bound(T val, T x = 0)
```

`trie` に格納されている要素全てに対して $\mathrm{xor} ~ x$ を作用させたときの $\mathrm{val}$ 以上の最小値が何番目に小さいかを返します．

**制約**

- $0 \leq \mathrm{val} < 2^{MAX\\_LOG}$
- $0 \leq x < 2^{MAX\\_LOG}$

**計算量**

- $O(MAX\\_LOG)$

## upper_bound

```cpp
int trie.upper_bound(T val, T x = 0)
```

`trie` に格納されている要素全てに対して $\mathrm{xor} ~ x$ を作用させたときの $\mathrm{val}$ より大きい最小値が何番目に小さいかを返します．

**制約**

- $0 \leq \mathrm{val} < 2^{MAX\\_LOG} - 1$
- $0 \leq x < 2^{MAX\\_LOG}$

**計算量**

- $O(MAX\\_LOG)$