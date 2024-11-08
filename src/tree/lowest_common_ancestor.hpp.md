---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/lowest_common_ancestor.test.cpp
    title: verify/aizu_online_judge/grl/lowest_common_ancestor.test.cpp
  - icon: ':x:'
    path: verify/library_checker/tree/jump_on_tree_2.test.cpp
    title: verify/library_checker/tree/jump_on_tree_2.test.cpp
  - icon: ':x:'
    path: verify/library_checker/tree/lowest_common_ancestor.test.cpp
    title: verify/library_checker/tree/lowest_common_ancestor.test.cpp
  - icon: ':x:'
    path: verify/unit_test/graph/bipartite.test.cpp
    title: verify/unit_test/graph/bipartite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n\
    #define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a,\
    \ b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
    struct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/graph/graph_template.hpp\"\
    \ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T cost;\n    int\
    \ idx;\n    Edge()\n        : from(-1), to(-1), cost(-1), idx(-1) {}\n    Edge(const\
    \ int from, const int to, const T& cost = 1, const int idx = -1)\n        : from(from),\
    \ to(to), cost(cost), idx(idx) {}\n    operator int() const {\n        return\
    \ to;\n    }\n};\ntemplate <typename T>\nstruct Graph {\n    Graph(const int N)\n\
    \        : n(N), es(0), g(N) {}\n    int size() const {\n        return n;\n \
    \   }\n    int edge_size() const {\n        return es;\n    }\n    void add_edge(const\
    \ int from, const int to, const T& cost = 1) {\n        assert(0 <= from and from\
    \ < n);\n        assert(0 <= to and to < n);\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n \
    \   void add_directed_edge(const int from, const int to, const T& cost = 1) {\n\
    \        assert(0 <= from and from < n);\n        assert(0 <= to and to < n);\n\
    \        g[from].emplace_back(from, to, cost, es++);\n    }\n    inline vector<Edge<T>>&\
    \ operator[](const int& k) {\n        assert(0 <= k and k < n);\n        return\
    \ g[k];\n    }\n    inline const vector<Edge<T>>& operator[](const int& k) const\
    \ {\n        assert(0 <= k and k < n);\n        return g[k];\n    }\n\n   private:\n\
    \    int n, es;\n    vector<vector<Edge<T>>> g;\n};\ntemplate <typename T>\nusing\
    \ Edges = vector<Edge<T>>;\n#line 4 \"src/tree/lowest_common_ancestor.hpp\"\n\
    template <typename T>\nstruct LowestCommonAncestor {\n    LowestCommonAncestor(const\
    \ Graph<T>& g, const int root = 0) {\n        assert(0 <= root and root < g.size());\n\
    \        init(g, root);\n    }\n    int depth(const int v) const {\n        assert(0\
    \ <= v and v < n);\n        return dep[v];\n    }\n    T cost(const int v) const\
    \ {\n        assert(0 <= v and v < n);\n        return co[v];\n    }\n    int\
    \ parent(const int v) const {\n        assert(0 <= v and v < n);\n        return\
    \ par[0][v];\n    }\n    int la(int v, int x) const {\n        assert(0 <= v and\
    \ v < n);\n        assert(x >= 0);\n        if(x > dep[v]) return -1;\n      \
    \  for(int i = 0; x > 0; ++i) {\n            if(x & 1) v = par[i][v];\n      \
    \      x >>= 1;\n        }\n        return v;\n    }\n    int lca(int u, int v)\
    \ const {\n        assert(0 <= u and u < n and 0 <= v and v < n);\n        if(dep[u]\
    \ > dep[v]) swap(u, v);\n        v = la(v, dep[v] - dep[u]);\n        if(u ==\
    \ v) return u;\n        for(int i = (int)par.size() - 1; i >= 0; --i) {\n    \
    \        if(par[i][u] != par[i][v]) {\n                u = par[i][u];\n      \
    \          v = par[i][v];\n            }\n        }\n        return par[0][u];\n\
    \    }\n    int dist(const int u, const int v) const {\n        assert(0 <= u\
    \ and u < n and 0 <= v and v < n);\n        return dep[u] + dep[v] - 2 * dep[lca(u,\
    \ v)];\n    }\n    T length(const int u, const int v) const {\n        assert(0\
    \ <= u and u < n and 0 <= v and v < n);\n        return co[u] + co[v] - 2 * co[lca(u,\
    \ v)];\n    }\n\n   private:\n    int n;\n    vector<vector<int>> par;\n    vector<int>\
    \ dep;\n    vector<T> co;\n    void init(const Graph<T>& g, const int root = 0)\
    \ {\n        n = g.size();\n        int h = 1;\n        while((1 << h) < n) ++h;\n\
    \        par.assign(h, vector<int>(n, -1));\n        dep.assign(n, -1);\n    \
    \    co.assign(n, -1);\n        dfs(g, root, -1, 0, 0);\n        for(int i = 0;\
    \ i + 1 < (int)par.size(); ++i) {\n            for(int v = 0; v < n; ++v) {\n\
    \                if(par[i][v] != -1) {\n                    par[i + 1][v] = par[i][par[i][v]];\n\
    \                }\n            }\n        }\n    }\n    void dfs(const Graph<T>&\
    \ g, const int v, const int p, const int d, const T& c) {\n        par[0][v] =\
    \ p;\n        dep[v] = d;\n        co[v] = c;\n        for(const Edge<T>& e :\
    \ g[v]) {\n            if(e.to == p) continue;\n            dfs(g, e.to, v, d\
    \ + 1, c + e.cost);\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../graph/graph_template.hpp\"\
    \ntemplate <typename T>\nstruct LowestCommonAncestor {\n    LowestCommonAncestor(const\
    \ Graph<T>& g, const int root = 0) {\n        assert(0 <= root and root < g.size());\n\
    \        init(g, root);\n    }\n    int depth(const int v) const {\n        assert(0\
    \ <= v and v < n);\n        return dep[v];\n    }\n    T cost(const int v) const\
    \ {\n        assert(0 <= v and v < n);\n        return co[v];\n    }\n    int\
    \ parent(const int v) const {\n        assert(0 <= v and v < n);\n        return\
    \ par[0][v];\n    }\n    int la(int v, int x) const {\n        assert(0 <= v and\
    \ v < n);\n        assert(x >= 0);\n        if(x > dep[v]) return -1;\n      \
    \  for(int i = 0; x > 0; ++i) {\n            if(x & 1) v = par[i][v];\n      \
    \      x >>= 1;\n        }\n        return v;\n    }\n    int lca(int u, int v)\
    \ const {\n        assert(0 <= u and u < n and 0 <= v and v < n);\n        if(dep[u]\
    \ > dep[v]) swap(u, v);\n        v = la(v, dep[v] - dep[u]);\n        if(u ==\
    \ v) return u;\n        for(int i = (int)par.size() - 1; i >= 0; --i) {\n    \
    \        if(par[i][u] != par[i][v]) {\n                u = par[i][u];\n      \
    \          v = par[i][v];\n            }\n        }\n        return par[0][u];\n\
    \    }\n    int dist(const int u, const int v) const {\n        assert(0 <= u\
    \ and u < n and 0 <= v and v < n);\n        return dep[u] + dep[v] - 2 * dep[lca(u,\
    \ v)];\n    }\n    T length(const int u, const int v) const {\n        assert(0\
    \ <= u and u < n and 0 <= v and v < n);\n        return co[u] + co[v] - 2 * co[lca(u,\
    \ v)];\n    }\n\n   private:\n    int n;\n    vector<vector<int>> par;\n    vector<int>\
    \ dep;\n    vector<T> co;\n    void init(const Graph<T>& g, const int root = 0)\
    \ {\n        n = g.size();\n        int h = 1;\n        while((1 << h) < n) ++h;\n\
    \        par.assign(h, vector<int>(n, -1));\n        dep.assign(n, -1);\n    \
    \    co.assign(n, -1);\n        dfs(g, root, -1, 0, 0);\n        for(int i = 0;\
    \ i + 1 < (int)par.size(); ++i) {\n            for(int v = 0; v < n; ++v) {\n\
    \                if(par[i][v] != -1) {\n                    par[i + 1][v] = par[i][par[i][v]];\n\
    \                }\n            }\n        }\n    }\n    void dfs(const Graph<T>&\
    \ g, const int v, const int p, const int d, const T& c) {\n        par[0][v] =\
    \ p;\n        dep[v] = d;\n        co[v] = c;\n        for(const Edge<T>& e :\
    \ g[v]) {\n            if(e.to == p) continue;\n            dfs(g, e.to, v, d\
    \ + 1, c + e.cost);\n        }\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/tree/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/library_checker/tree/jump_on_tree_2.test.cpp
  - verify/library_checker/tree/lowest_common_ancestor.test.cpp
  - verify/unit_test/graph/bipartite.test.cpp
  - verify/aizu_online_judge/grl/lowest_common_ancestor.test.cpp
documentation_of: src/tree/lowest_common_ancestor.hpp
layout: document
title: LowestCommonAncestor
---

# LowestCommonAncestor

$n$ 頂点の根付き木が与えられたとき，

- $2$ 頂点の最小共通祖先の取得
- $2$ 頂点間の距離の取得

を前計算 $O(n \log n)$ クエリ $O(\log n)$ でできるアルゴリズムです．

内部はダブリングで実装されています．

## コンストラクタ

```cpp
LowestCommonAncestor<T> tree(Graph<T> g, int root = 0)
```

- 頂点数 $n$ の木 `g` を与えると，`root` を根として前計算を行います．

**制約**

- `T` は `int / uint / ll / ull / double / long double`
- `g` は木
- $0 \leq \mathrm{root} < n$

**計算量**

- $O(n \log n)$

## depth

```cpp
int tree.depth(int v)
```

辺の重みが $1$ であると仮定したときの根付き木 `tree` における頂点 $v$ の深さを返します．

**制約**

- $0 \leq v < n$

**計算量**

- $O(1)$

## cost

```cpp
T tree.cost(int v)
```

根付き木 `tree` における根 `root` と頂点 $v$ の距離を返します．

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
int tree.la(int v, int x)
```

頂点 $v$ から根方向に $x$ 個進んだ頂点のラベルを返します．

$x$ が 頂点 $v$ の深さよりも大きいときは $-1$ を返します．

**制約**

- $0 \leq v < n$
- $0 \leq x$

**計算量**

- $O(\log x)$

## lca

```cpp
int tree.lca(int u, int v)
```

根付き木 `tree` における頂点 $u$ と $v$ の最小共通祖先を返します．

**制約**

- $0 \leq u < n$
- $0 \leq v < n$

**計算量**

- $O(\log n)$

## dist

```cpp
int tree.dist(int u, int v)
```

辺の重みが $1$ であると仮定したときの根付き木 `tree` における頂点 $u$ と $v$ の間の距離を返します．

**制約**

- $0 \leq u < n$
- $0 \leq v < n$

**計算量**

- $O(\log n)$

## length

```cpp
T tree.length(int u, int v)
```

根付き木 `tree` における頂点 $u$ と $v$ の間の距離を返します．

**制約**

- $0 \leq u < n$
- $0 \leq v < n$

**計算量**

- $O(\log n)$