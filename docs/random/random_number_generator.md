---
title: RandomNumberGenerator
documentation_of: ../../src/random/random_number_generator.hpp
---

# RandomNumberGenerator

- 一様ランダムな整数・実数
- 一様ランダムな配列 (重複あり・なし指定可)
- 一様ランダムな順列
- 一様ランダムな木
- 一様ランダムな単純無向グラフ
- 一様ランダムな重み付き単純無向グラフ
- ランダムな単純連結無向グラフ
- ランダムな重み付き単純連結無向グラフ
- 一様ランダムな括弧列

を生成できます．

# コンストラクタ

```cpp
RandomNumberGenerator rng()
```

- 乱数生成器 `rng` を作成します．シードには実行時の時刻を用いています．

**計算量**

- $O(1)$

# operator ()

```cpp
T rng(T lower, T upper)
```

$\mathrm{lower}$ 以上 $\mathrm{upper}$ 以下の整数・実数を一様ランダムに返します．

**制約**

- $\mathrm{lower} \leq \mathrm{upper}$

**計算量**

- $O(1)$

# vec

```cpp
vector<T> rng.vec(int n, T lower, T upper, bool dup = true)
```

$\mathrm{lower}$ 以上 $\mathrm{upper}$ 以下の整数からなる長さ $n$ の配列を一様ランダムに返します．

`dup = true` ならば要素の重複を許し，`dup = false` ならば要素の重複を許しません．

**制約**

- $0 \leq n \leq 10^8$
- $\mathrm{lower} \leq \mathrm{upper}$

**計算量**

- 期待 $O(n)$

# perm

```cpp
vector<int> rng.perm(int n, bool one = true)
```

長さ $n$ の順列を一様ランダムに返します．

`one = true` のとき要素は $[1, n]$ で，`one = false` のとき要素は $[0, n - 1]$ です．

**制約**

- $0 \leq n \leq 10^8$

**計算量**

- $O(n)$

# tree

```cpp
pair<vector<int>, vector<int>> rng.tree(int n, bool one = true)
```

$n$ 頂点の木を一様ランダムに生成し，辺の両端の頂点ラベルを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $0 \leq n \leq 10^8$

**計算量**

- $O(n \log n)$

# weighted_tree

```cpp
tuple<vector<int>, vector<int>, vector<T>> rng.weighted_tree(int n, T lower, T upper, bool one = true)
```

辺の重みが $[\mathrm{lower}, \mathrm{upper}]$ である $n$ 頂点の重み付き木を一様ランダムに生成し，辺の両端の頂点ラベルと重みを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $0 \leq n \leq 10^8$
- $\mathrm{lower} \leq \mathrm{upper}$

**計算量**

- $O(n \log n)$

# graph

```cpp
pair<vector<int>, vector<int>> rng.graph(int n, int m, bool one = true)
```

$n$ 頂点 $m$ 辺の単純無向グラフを一様ランダムに生成し，辺の両端の頂点ラベルを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $0 \leq n \leq 10^8$
- $0 \leq m \leq \mathrm{min}(10^8, \frac{n (n - 1)}{2})$

**計算量**

- 期待 $O(m \log m)$

# weighted_graph

```cpp
tuple<vector<int>, vector<int>, vector<T>> rng.weighted_graph(int n, int m, T lower, T upper, bool one = true)
```

辺の重みが $[\mathrm{lower}, \mathrm{upper}]$ である $n$ 頂点 $m$ 辺の重み付き単純無向グラフを一様ランダムに生成し，辺の両端の頂点ラベルと重みを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $0 \leq n \leq 10^8$
- $0 \leq m \leq \mathrm{min}(10^8, \frac{n (n - 1)}{2})$
- $\mathrm{lower} \leq \mathrm{upper}$

**計算量**

- 期待 $O(m \log m)$

# connected_graph

```cpp
pair<vector<int>, vector<int>> rng.connected_graph(int n, int m, bool one = true)
```

$n$ 頂点 $m$ 辺の単純無向連結グラフをランダムに生成し，辺の両端の頂点ラベルを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $0 \leq n \leq 10^8$
- $\mathrm{max}(n - 1, 0) \leq m \leq \mathrm{min}(10^8, \frac{n (n - 1)}{2})$

**計算量**

- 期待 $O(m \log m)$

# weighted_connected_graph

```cpp
tuple<vector<int>, vector<int>, vector<T>> rng.weighted_connected_graph(int n, int m, T lower, T upper, bool one = true)
```

辺の重みが $[\mathrm{lower}, \mathrm{upper}]$ である $n$ 頂点 $m$ 辺の重み付き単純無向連結グラフをランダムに生成し，辺の両端の頂点ラベルと重みを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $0 \leq n \leq 10^8$
- $\mathrm{max}(n - 1, 0) \leq m \leq \mathrm{min}(10^8, \frac{n (n - 1)}{2})$
- $\mathrm{lower} \leq \mathrm{upper}$

**計算量**

- 期待 $O(m \log m)$

# parenthesis

```cpp
string rng.parenthesis(int n)
```

長さ $2n$ の括弧列を一様ランダムに返します．

**制約**

- $1 \leq n \leq 10^8$

**計算量**

- $O(n)$