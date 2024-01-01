# RollbackUnionFind

通常のUnionFindに加えて，

- 直前の `merge` の操作の取り消し
- グラフの状態を記憶
- 記憶した状態への巻き戻し

ができます．

## コンストラクタ

```cpp
RollbackUnionFind uf(int n)
```

- $n$ 頂点 $0$ 辺の無向グラフを作ります．

**計算量**

- $O(n)$

## merge

```cpp
int uf.merge(int a, int b)
```

辺 $(a, b)$ を足します．

頂点 $a$ と $b$ が連結だった場合はその代表元，非連結だった場合は新たな代表元を返します．

**制約**

- $0 \leq a < n$
- $0 \leq b < n$

**計算量**

- $O(\log n)$

## same

```cpp
bool uf.same(int a, int b)
```

頂点 $a$ と $b$ が連結かどうかを返します．

**制約**

- $0 \leq a < n$
- $0 \leq b < n$

**計算量**

- $O(\log n)$

## leader

```cpp
int uf.leader(int a)
```

頂点 $a$ の属する連結成分の代表元を返します．

**制約**

- $0 \leq a < n$

**計算量**

- $O(\log n)$

## size

```cpp
int uf.size(int a)
```

頂点 $a$ の属する連結成分のサイズを返します．

**制約**

- $0 \leq a < n$

**計算量**

- $O(\log n)$

## undo

```cpp
void uf.undo()
```

直前の `merge` の操作を取り消します．

**制約**

- 少なくとも一回の `merge` を行なっていること

**計算量**

- $O(1)$

## get_state

```cpp
int uf.get_state()
```

`merge` を何回行った状態であるかを返します．

**計算量**

- $O(1)$

## snapshot

```cpp
int uf.snapshot()
```

現在のグラフの状態を記憶します．

複数の状態を記憶することはできません．<br>
最後に呼び出したときの状態のみを記憶します．

**計算量**

- $O(1)$

## rollback

```cpp
void uf.rollback(int state = -1)
```

$\mathrm{state = -1}$ のとき，最新の `snapshot` で記憶した状態までグラフを巻き戻します．<br>
それ以外のとき， `merge` が $\mathrm{state}$ 回行われた状態へ戻します．

**制約**

- $\mathrm{state = -1}$ または $0 \leq \mathrm{state} \leq$ `merge` が呼び出された階数

**計算量**

- 償却 $O(1)$