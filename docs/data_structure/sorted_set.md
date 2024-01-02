# SortedSet

- 要素の挿入・削除
- 要素の検索
- 要素の個数の取得
- $k$ 番目に小さい値の取得
- $x$ 以上の最小値の取得

を $O(\log n)$ 時間で処理できます．

## コンストラクタ

```cpp
(1) SortedSet st
(2) SortedMultiSet mst
```

- (1): 空の平衡二分探索木 `st` を構築します．
- (2): 要素の重複をゆるした空の平衡二分探索木 `mst` を構築します．

**計算量**

- $O(1)$

## insert

```cpp
(1) pair<iterator, bool> st.insert(int x)
(2) pair<iterator, bool> mst.insert(int x)
```

`st` および `mst` に要素 $x$ を追加します．<br>
`st` にすでに $x$ が入っている場合は何もしません．

返り値として，イテレータと挿入が成功したかを示すフラグが得られます．

**計算量**

- $O(\log n)$

## erase

```cpp
(1) pair<iterator, bool> st.erase(int x)
(2) pair<iterator, bool> mst.erase(st.find_by_order(st.order_of_key(6)))
```

`st` および `mst` から要素 $x$ を削除します．<br>
すでに $x$ が入っていない場合は何もしません．<br>
`mst` に複数の $x$ が入っている場合，要素は $1$ つだけ削除されます．

返り値として，イテレータと削除が成功したかを示すフラグが得られます．

**計算量**

- $O(\log n)$

## find

```cpp
(1) iterator st.find(int x)
(2) iterator mst.find(int x)
```

要素 $x$ のイテレータを返します．<br>
要素がない場合，`st.end()` および `mst.end()` を返します．

**計算量**

- $O(\log n)$

## size

```cpp
(1) int st.size()
(2) int mst.size()
```

`st` や `mst` の中に入っている要素の個数を返します．

**計算量**

- $O(1)$

## find_by_order

```cpp
(1) iterator st.find_by_order(int k)
(2) iterator mst.find_by_order(int k)
```

$k$ 番目に小さい値のイテレータを返します．

**計算量**

- $O(\log n)$

## order_of_key

```cpp
(1) int st.order_of_key(int x)
(2) int mst.order_of_key(int x)
```

$x$ 以上の最小値が何番目に小さいかを返します．

**計算量**

- $O(\log n)$