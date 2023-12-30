# LowestCommonAncestor

$n$ 頂点根付き木が与えられたとき，

- $2$ 頂点の最小共通祖先の取得
- $2$ 頂点間の距離の取得

を前計算 $O(n \log n)$ クエリ $O(\log n)$ でできるアルゴリズムです．

内部はダブリングで実装されています．

## コンストラクタ

```cpp
LowestCommonAncestor tree(vector<vector<int>> g, int root = 0)
```

- 頂点数 $n$ の隣接リスト形式の木 `g` を与えると，`root` を根として前計算を行います．

**制約**

- `g` は木
- $0 \leq \mathrm{root} < n$

**計算量**

- $O(n \log n)$

## depth

```cpp
int tree.depth(int v)
```

根付き木 `tree` における頂点 `v` の深さを返します．

**制約**

- $0 \leq v < n$

**計算量**

- $O(1)$

## parent

```cpp
int tree.parent(int v, int x = 1)
```

頂点 `v` から根方向に $x$ だけ進んだ頂点のラベルを返します．

$x$ が 頂点 `v` の深さよりも大きいときは $-1$ を返します．

**制約**

- $0 \leq v < n$
- $0 \leq x$

**計算量**

- $O(\log n)$

## lca

```cpp
int tree.lca(int u, int v)
```

根付き木 `tree` における頂点 `u` と `v` の最小共通祖先を返します．

**制約**

- $0 \leq u < n$
- $0 \leq v < n$

**計算量**

- $O(\log n)$

## dist

```cpp
int tree.dist(int u, int v)
```

根付き木 `tree` における頂点 `u` と `v` の間の距離を返します．

**制約**

- $0 \leq u < n$
- $0 \leq v < n$

**計算量**

- $O(\log n)$