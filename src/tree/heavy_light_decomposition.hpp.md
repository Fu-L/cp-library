---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/range_query_on_a_tree.test.cpp
    title: verify/aizu_online_judge/grl/range_query_on_a_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp
    title: verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/jump_on_tree.test.cpp
    title: verify/library_checker/tree/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/vertex_add_path_sum.test.cpp
    title: verify/library_checker/tree/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
    title: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/vertex_set_path_composite.test.cpp
    title: verify/library_checker/tree/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/graph/graph_template.hpp\"\
    \ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T cost;\n    int\
    \ idx;\n    Edge()\n        : from(-1), to(-1), cost(-1), idx(-1) {}\n    Edge(int\
    \ from, int to, const T& cost = 1, int idx = -1)\n        : from(from), to(to),\
    \ cost(cost), idx(idx) {}\n    operator int() const {\n        return to;\n  \
    \  }\n};\ntemplate <typename T>\nstruct Graph {\n    Graph(int N)\n        : n(N),\
    \ es(0), g(N) {}\n    int size() const {\n        return n;\n    }\n    int edge_size()\
    \ const {\n        return es;\n    }\n    void add_edge(int from, int to, const\
    \ T& cost = 1) {\n        assert(0 <= from and from < n);\n        assert(0 <=\
    \ to and to < n);\n        g[from].emplace_back(from, to, cost, es);\n       \
    \ g[to].emplace_back(to, from, cost, es++);\n    }\n    void add_directed_edge(int\
    \ from, int to, const T& cost = 1) {\n        assert(0 <= from and from < n);\n\
    \        assert(0 <= to and to < n);\n        g[from].emplace_back(from, to, cost,\
    \ es++);\n    }\n    inline vector<Edge<T>>& operator[](const int& k) {\n    \
    \    assert(0 <= k and k < n);\n        return g[k];\n    }\n    inline const\
    \ vector<Edge<T>>& operator[](const int& k) const {\n        assert(0 <= k and\
    \ k < n);\n        return g[k];\n    }\n\n   private:\n    int n, es;\n    vector<vector<Edge<T>>>\
    \ g;\n};\ntemplate <typename T>\nusing Edges = vector<Edge<T>>;\n#line 4 \"src/tree/heavy_light_decomposition.hpp\"\
    \ntemplate <typename T>\nstruct HeavyLightDecomposition {\n    HeavyLightDecomposition(Graph<T>&\
    \ _g, int root = 0)\n        : g(_g), n(g.size()), id(0), sz(n, 0), dep(n, 0),\
    \ down(n, -1), up(n, -1), nex(n, root), par(n, -1), rev(n, 0), co(n, 0) {\n  \
    \      assert(0 <= root and root < n);\n        dfs_sz(root);\n        dfs_hld(root);\n\
    \    }\n    pair<int, int> idx(int i) const {\n        assert(0 <= i and i < n);\n\
    \        return make_pair(down[i], up[i]);\n    }\n    int depth(int v) const\
    \ {\n        assert(0 <= v and v < n);\n        return dep[v];\n    }\n    T cost(int\
    \ v) const {\n        assert(0 <= v and v < n);\n        return co[v];\n    }\n\
    \    int parent(int v) const {\n        assert(0 <= v and v < n);\n        return\
    \ par[v];\n    }\n    int la(int v, int x) const {\n        assert(0 <= v and\
    \ v < n);\n        assert(x >= 0);\n        if(x > dep[v]) return -1;\n      \
    \  while(true) {\n            const int u = nex[v];\n            if(down[v] -\
    \ x >= down[u]) return rev[down[v] - x];\n            x -= down[v] - down[u] +\
    \ 1;\n            v = par[u];\n        }\n    }\n    int lca(int u, int v) const\
    \ {\n        assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n  \
    \      while(nex[u] != nex[v]) {\n            if(down[u] < down[v]) swap(u, v);\n\
    \            u = par[nex[u]];\n        }\n        return dep[u] < dep[v] ? u :\
    \ v;\n    }\n    int dist(int u, int v) const {\n        assert(0 <= u and u <\
    \ n);\n        assert(0 <= v and v < n);\n        return dep[u] + dep[v] - dep[lca(u,\
    \ v)] * 2;\n    }\n    T length(int u, int v) const {\n        assert(0 <= u and\
    \ u < n);\n        assert(0 <= v and v < n);\n        return co[u] + co[v] - co[lca(u,\
    \ v)] * 2;\n    }\n    template <typename F>\n    void path_query(int u, int v,\
    \ bool vertex, const F& f) {\n        assert(0 <= u and u < n);\n        assert(0\
    \ <= v and v < n);\n        int l = lca(u, v);\n        for(auto&& [a, b] : ascend(u,\
    \ l)) f(a + 1, b);\n        if(vertex) f(down[l], down[l] + 1);\n        for(auto&&\
    \ [a, b] : descend(l, v)) f(a, b + 1);\n    }\n    template <typename F>\n   \
    \ void subtree_query(int v, bool vertex, const F& f) {\n        assert(0 <= v\
    \ and v < n);\n        f(down[v] + int(!vertex), up[v]);\n    }\n\n   private:\n\
    \    Graph<T>& g;\n    int n, id;\n    vector<int> sz, dep, down, up, nex, par,\
    \ rev;\n    vector<T> co;\n    void dfs_sz(int cur) {\n        sz[cur] = 1;\n\
    \        for(Edge<T>& edge : g[cur]) {\n            if(edge.to == par[cur]) {\n\
    \                if(g[cur].size() >= 2 and edge.to == g[cur][0].to) {\n      \
    \              swap(g[cur][0], g[cur][1]);\n                } else {\n       \
    \             continue;\n                }\n            }\n            dep[edge.to]\
    \ = dep[cur] + 1;\n            co[edge.to] = co[cur] + edge.cost;\n          \
    \  par[edge.to] = cur;\n            dfs_sz(edge.to);\n            sz[cur] += sz[edge.to];\n\
    \            if(sz[edge.to] > sz[g[cur][0].to]) {\n                swap(edge,\
    \ g[cur][0]);\n            }\n        }\n    }\n    void dfs_hld(int cur) {\n\
    \        down[cur] = id++;\n        rev[down[cur]] = cur;\n        for(const Edge<T>&\
    \ edge : g[cur]) {\n            if(edge.to == par[cur]) continue;\n          \
    \  nex[edge.to] = (edge.to == g[cur][0].to ? nex[cur] : edge.to);\n          \
    \  dfs_hld(edge.to);\n        }\n        up[cur] = id;\n    }\n    vector<pair<int,\
    \ int>> ascend(int u, int v) const {\n        vector<pair<int, int>> res;\n  \
    \      while(nex[u] != nex[v]) {\n            res.emplace_back(down[u], down[nex[u]]);\n\
    \            u = par[nex[u]];\n        }\n        if(u != v) res.emplace_back(down[u],\
    \ down[v] + 1);\n        return res;\n    }\n    vector<pair<int, int>> descend(int\
    \ u, int v) const {\n        if(u == v) return {};\n        if(nex[u] == nex[v])\
    \ return {{down[u] + 1, down[v]}};\n        auto res = descend(u, par[nex[v]]);\n\
    \        res.emplace_back(down[nex[v]], down[v]);\n        return res;\n    }\n\
    };\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../graph/graph_template.hpp\"\
    \ntemplate <typename T>\nstruct HeavyLightDecomposition {\n    HeavyLightDecomposition(Graph<T>&\
    \ _g, int root = 0)\n        : g(_g), n(g.size()), id(0), sz(n, 0), dep(n, 0),\
    \ down(n, -1), up(n, -1), nex(n, root), par(n, -1), rev(n, 0), co(n, 0) {\n  \
    \      assert(0 <= root and root < n);\n        dfs_sz(root);\n        dfs_hld(root);\n\
    \    }\n    pair<int, int> idx(int i) const {\n        assert(0 <= i and i < n);\n\
    \        return make_pair(down[i], up[i]);\n    }\n    int depth(int v) const\
    \ {\n        assert(0 <= v and v < n);\n        return dep[v];\n    }\n    T cost(int\
    \ v) const {\n        assert(0 <= v and v < n);\n        return co[v];\n    }\n\
    \    int parent(int v) const {\n        assert(0 <= v and v < n);\n        return\
    \ par[v];\n    }\n    int la(int v, int x) const {\n        assert(0 <= v and\
    \ v < n);\n        assert(x >= 0);\n        if(x > dep[v]) return -1;\n      \
    \  while(true) {\n            const int u = nex[v];\n            if(down[v] -\
    \ x >= down[u]) return rev[down[v] - x];\n            x -= down[v] - down[u] +\
    \ 1;\n            v = par[u];\n        }\n    }\n    int lca(int u, int v) const\
    \ {\n        assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n  \
    \      while(nex[u] != nex[v]) {\n            if(down[u] < down[v]) swap(u, v);\n\
    \            u = par[nex[u]];\n        }\n        return dep[u] < dep[v] ? u :\
    \ v;\n    }\n    int dist(int u, int v) const {\n        assert(0 <= u and u <\
    \ n);\n        assert(0 <= v and v < n);\n        return dep[u] + dep[v] - dep[lca(u,\
    \ v)] * 2;\n    }\n    T length(int u, int v) const {\n        assert(0 <= u and\
    \ u < n);\n        assert(0 <= v and v < n);\n        return co[u] + co[v] - co[lca(u,\
    \ v)] * 2;\n    }\n    template <typename F>\n    void path_query(int u, int v,\
    \ bool vertex, const F& f) {\n        assert(0 <= u and u < n);\n        assert(0\
    \ <= v and v < n);\n        int l = lca(u, v);\n        for(auto&& [a, b] : ascend(u,\
    \ l)) f(a + 1, b);\n        if(vertex) f(down[l], down[l] + 1);\n        for(auto&&\
    \ [a, b] : descend(l, v)) f(a, b + 1);\n    }\n    template <typename F>\n   \
    \ void subtree_query(int v, bool vertex, const F& f) {\n        assert(0 <= v\
    \ and v < n);\n        f(down[v] + int(!vertex), up[v]);\n    }\n\n   private:\n\
    \    Graph<T>& g;\n    int n, id;\n    vector<int> sz, dep, down, up, nex, par,\
    \ rev;\n    vector<T> co;\n    void dfs_sz(int cur) {\n        sz[cur] = 1;\n\
    \        for(Edge<T>& edge : g[cur]) {\n            if(edge.to == par[cur]) {\n\
    \                if(g[cur].size() >= 2 and edge.to == g[cur][0].to) {\n      \
    \              swap(g[cur][0], g[cur][1]);\n                } else {\n       \
    \             continue;\n                }\n            }\n            dep[edge.to]\
    \ = dep[cur] + 1;\n            co[edge.to] = co[cur] + edge.cost;\n          \
    \  par[edge.to] = cur;\n            dfs_sz(edge.to);\n            sz[cur] += sz[edge.to];\n\
    \            if(sz[edge.to] > sz[g[cur][0].to]) {\n                swap(edge,\
    \ g[cur][0]);\n            }\n        }\n    }\n    void dfs_hld(int cur) {\n\
    \        down[cur] = id++;\n        rev[down[cur]] = cur;\n        for(const Edge<T>&\
    \ edge : g[cur]) {\n            if(edge.to == par[cur]) continue;\n          \
    \  nex[edge.to] = (edge.to == g[cur][0].to ? nex[cur] : edge.to);\n          \
    \  dfs_hld(edge.to);\n        }\n        up[cur] = id;\n    }\n    vector<pair<int,\
    \ int>> ascend(int u, int v) const {\n        vector<pair<int, int>> res;\n  \
    \      while(nex[u] != nex[v]) {\n            res.emplace_back(down[u], down[nex[u]]);\n\
    \            u = par[nex[u]];\n        }\n        if(u != v) res.emplace_back(down[u],\
    \ down[v] + 1);\n        return res;\n    }\n    vector<pair<int, int>> descend(int\
    \ u, int v) const {\n        if(u == v) return {};\n        if(nex[u] == nex[v])\
    \ return {{down[u] + 1, down[v]}};\n        auto res = descend(u, par[nex[v]]);\n\
    \        res.emplace_back(down[nex[v]], down[v]);\n        return res;\n    }\n\
    };"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/tree/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2024-08-31 23:00:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/tree/vertex_set_path_composite.test.cpp
  - verify/library_checker/tree/vertex_add_path_sum.test.cpp
  - verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  - verify/library_checker/tree/jump_on_tree.test.cpp
  - verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp
  - verify/aizu_online_judge/grl/range_query_on_a_tree.test.cpp
documentation_of: src/tree/heavy_light_decomposition.hpp
layout: document
title: HeavyLightDecomposition
---

# HeavyLightDecomposition

木をHL分解します．

## コンストラクタ

```cpp
HeavyLightDecomposition<T> hld(Graph<T>& g, int root = 0)
```

`root` を根とする $n$ 頂点の木 `g` をHL分解します．

頂点 $v$ のheavy childが `g[v][0]` に来るように `g` が変更されます．

これを呼び出した後に `a[hld.idx(i).first] = (頂点iに関する値)` という配列を作成すると，木上の $1$ つのパスクエリを，配列上の $O(\log n)$ 個の区間クエリとして処理することができます．

**制約**

- $0 \leq \mathrm{root} < n$

**制約**

- $O(n)$

## idx

```cpp
pair<int, int> hld.idx(int i)
```

頂点 $i$ のオイラーツアー順を返します．

返り値の第一要素が行き順で，第二要素が帰り順です．

**制約**

- $0 \leq i < n$

**計算量**

- $O(1)$

## depth

```cpp
int tree.depth(int v)
```

辺の重みが $1$ であると仮定したときの頂点 $v$ の深さを返します．

**制約**

- $0 \leq v < n$

**計算量**

- $O(1)$

## cost

```cpp
int tree.cost(int v)
```

根 `root` と頂点 $v$ の距離を返します．

**制約**

- $0 \leq v < n$

**計算量**

- $O(1)$

## parent

```cpp
int tree.parent(int v)
```

頂点 $v$ の親頂点のラベルを返します．

$v$ が根であるときは $-1$ を返します．

**制約**

- $0 \leq v < n$

**計算量**

- $O(1)$

## la

```cpp
int hld.la(int v, int x)
```

頂点 $v$ から根方向に $x$ 個進んだ頂点のラベルを返します．

$x$ が頂点 $v$ の深さよりも大きいときは $-1$ を返します．

**制約**

- $0 \leq v < n$
- $0 \leq x$

**計算量**

- $O(\log x)$

## lca

```cpp
int hld.lca(int u, int v)
```

頂点 $u$ と $v$ の最小共通祖先を返します．

**制約**

- $0 \leq u < n$
- $0 \leq v < n$

**計算量**

- $O(\log n)$

## dist

```cpp
int hld.dist(int u, int v)
```

辺の重みが $1$ であると仮定したときの木における頂点 $u$ と $v$ の間の距離を返します．

**制約**

- $0 \leq u < n$
- $0 \leq v < n$

**計算量**

- $O(\log n)$

## length

```cpp
T tree.length(int u, int v)
```

木における頂点 $u$ と $v$ の間の距離を返します．

**制約**

- $0 \leq u < n$
- $0 \leq v < n$

**計算量**

- $O(\log n)$

## path_query

```cpp
void hld.path_query(int u, int v, bool vertex, F f)
```

木上のパス $u - v$ に関するクエリを処理します．

`vertex = true` のとき，パス上の頂点に関するクエリを処理し， `vertex = false` のとき，パス上の辺に関するクエリを処理します．

`f` は `void f(int u, int v)` の形のラムダ式で，構築した数列の区間 $[\min(u, v), \max(u, v))$ に対する処理を書いてください． ( $u \leq v$ は保証されません！)

**制約**

- $0 \leq u < n$
- $0 \leq v < n$

**計算量**

- $O(\log^2 n)$

## subtree_query

```cpp
void hld.subtree_query(int v, bool vertex, F f)
```

$v$ を根とする部分木に関するクエリを処理します．

`vertex = true` のとき，部分木の頂点に関するクエリを処理し， `vertex = false` のとき，部分木の辺に関するクエリを処理します．

`f` は `void f(int u, int v)` の形のラムダ式で，構築した数列の区間 $[u, v)$ に対する処理を書いてください． ( $u \leq v$ が保証されます)

**制約**

- $0 \leq v < n$

**計算量**

- $O(\log n)$