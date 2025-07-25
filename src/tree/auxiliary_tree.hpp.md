---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  - icon: ':heavy_check_mark:'
    path: src/tree/heavy_light_decomposition.hpp
    title: HeavyLightDecomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/tree/auxiliary_tree.test.cpp
    title: verify/unit_test/tree/auxiliary_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ Edges = vector<Edge<T>>;\n#line 4 \"src/tree/heavy_light_decomposition.hpp\"\
    \ntemplate <typename T>\nstruct HeavyLightDecomposition {\n    HeavyLightDecomposition(Graph<T>&\
    \ _g, const int root = 0)\n        : g(_g), n(g.size()), id(0), sz(n, 0), dep(n,\
    \ 0), down(n, -1), up(n, -1), nex(n, root), par(n, -1), rev(n, 0), co(n, 0) {\n\
    \        assert(0 <= root and root < n);\n        dfs_sz(root);\n        dfs_hld(root);\n\
    \    }\n    pair<int, int> idx(const int i) const {\n        assert(0 <= i and\
    \ i < n);\n        return make_pair(down[i], up[i]);\n    }\n    int depth(const\
    \ int v) const {\n        assert(0 <= v and v < n);\n        return dep[v];\n\
    \    }\n    T cost(const int v) const {\n        assert(0 <= v and v < n);\n \
    \       return co[v];\n    }\n    int parent(const int v) const {\n        assert(0\
    \ <= v and v < n);\n        return par[v];\n    }\n    int la(int v, int x) const\
    \ {\n        assert(0 <= v and v < n);\n        assert(x >= 0);\n        if(x\
    \ > dep[v]) return -1;\n        while(true) {\n            const int u = nex[v];\n\
    \            if(down[v] - x >= down[u]) return rev[down[v] - x];\n           \
    \ x -= down[v] - down[u] + 1;\n            v = par[u];\n        }\n    }\n   \
    \ int lca(int u, int v) const {\n        assert(0 <= u and u < n);\n        assert(0\
    \ <= v and v < n);\n        while(nex[u] != nex[v]) {\n            if(down[u]\
    \ < down[v]) swap(u, v);\n            u = par[nex[u]];\n        }\n        return\
    \ dep[u] < dep[v] ? u : v;\n    }\n    int dist(const int u, const int v) const\
    \ {\n        assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n  \
    \      return dep[u] + dep[v] - dep[lca(u, v)] * 2;\n    }\n    T length(const\
    \ int u, const int v) const {\n        assert(0 <= u and u < n);\n        assert(0\
    \ <= v and v < n);\n        return co[u] + co[v] - co[lca(u, v)] * 2;\n    }\n\
    \    template <typename F>\n    void path_query(const int u, const int v, const\
    \ bool vertex, const F& f) {\n        assert(0 <= u and u < n);\n        assert(0\
    \ <= v and v < n);\n        const int l = lca(u, v);\n        for(auto&& [a, b]\
    \ : ascend(u, l)) f(a + 1, b);\n        if(vertex) f(down[l], down[l] + 1);\n\
    \        for(auto&& [a, b] : descend(l, v)) f(a, b + 1);\n    }\n    template\
    \ <typename F>\n    void subtree_query(const int v, const bool vertex, const F&\
    \ f) {\n        assert(0 <= v and v < n);\n        f(down[v] + int(!vertex), up[v]);\n\
    \    }\n\n   private:\n    Graph<T>& g;\n    int n, id;\n    vector<int> sz, dep,\
    \ down, up, nex, par, rev;\n    vector<T> co;\n    void dfs_sz(const int cur)\
    \ {\n        sz[cur] = 1;\n        for(Edge<T>& edge : g[cur]) {\n           \
    \ if(edge.to == par[cur]) {\n                if(g[cur].size() >= 2 and edge.to\
    \ == g[cur][0].to) {\n                    swap(g[cur][0], g[cur][1]);\n      \
    \          } else {\n                    continue;\n                }\n      \
    \      }\n            dep[edge.to] = dep[cur] + 1;\n            co[edge.to] =\
    \ co[cur] + edge.cost;\n            par[edge.to] = cur;\n            dfs_sz(edge.to);\n\
    \            sz[cur] += sz[edge.to];\n            if(sz[edge.to] > sz[g[cur][0].to])\
    \ {\n                swap(edge, g[cur][0]);\n            }\n        }\n    }\n\
    \    void dfs_hld(const int cur) {\n        down[cur] = id++;\n        rev[down[cur]]\
    \ = cur;\n        for(const Edge<T>& edge : g[cur]) {\n            if(edge.to\
    \ == par[cur]) continue;\n            nex[edge.to] = (edge.to == g[cur][0].to\
    \ ? nex[cur] : edge.to);\n            dfs_hld(edge.to);\n        }\n        up[cur]\
    \ = id;\n    }\n    vector<pair<int, int>> ascend(int u, int v) const {\n    \
    \    vector<pair<int, int>> res;\n        while(nex[u] != nex[v]) {\n        \
    \    res.emplace_back(down[u], down[nex[u]]);\n            u = par[nex[u]];\n\
    \        }\n        if(u != v) res.emplace_back(down[u], down[v] + 1);\n     \
    \   return res;\n    }\n    vector<pair<int, int>> descend(const int u, const\
    \ int v) const {\n        if(u == v) return {};\n        if(nex[u] == nex[v])\
    \ return {{down[u] + 1, down[v]}};\n        auto res = descend(u, par[nex[v]]);\n\
    \        res.emplace_back(down[nex[v]], down[v]);\n        return res;\n    }\n\
    };\n#line 5 \"src/tree/auxiliary_tree.hpp\"\ntemplate <typename T>\nstruct AuxiliaryTree\
    \ {\n    AuxiliaryTree(const Graph<T>& _g, const int root = 0)\n        : g(_g),\
    \ hld(g, root) {}\n    pair<Graph<int>, vector<int>> get(vector<int> idx) {\n\
    \        if(idx.empty()) return {Graph<int>(0), {}};\n        auto comp = [&](const\
    \ int i, const int j) {\n            return hld.idx(i).first < hld.idx(j).first;\n\
    \        };\n        sort(begin(idx), end(idx), comp);\n        for(int i = 0,\
    \ ie = idx.size(); i + 1 < ie; ++i) {\n            idx.push_back(hld.lca(idx[i],\
    \ idx[i + 1]));\n        }\n        sort(begin(idx), end(idx), comp);\n      \
    \  idx.erase(unique(begin(idx), end(idx)), end(idx));\n        Graph<int> aux(idx.size());\n\
    \        vector<int> rs;\n        rs.push_back(0);\n        for(int i = 1; i <\
    \ (int)idx.size(); ++i) {\n            const int l = hld.lca(idx[rs.back()], idx[i]);\n\
    \            while(idx[rs.back()] != l) rs.pop_back();\n            aux.add_directed_edge(rs.back(),\
    \ i);\n            rs.push_back(i);\n        }\n        return make_pair(aux,\
    \ idx);\n    }\n\n   private:\n    Graph<T> g;\n    HeavyLightDecomposition<T>\
    \ hld;\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../graph/graph_template.hpp\"\
    \n#include \"./heavy_light_decomposition.hpp\"\ntemplate <typename T>\nstruct\
    \ AuxiliaryTree {\n    AuxiliaryTree(const Graph<T>& _g, const int root = 0)\n\
    \        : g(_g), hld(g, root) {}\n    pair<Graph<int>, vector<int>> get(vector<int>\
    \ idx) {\n        if(idx.empty()) return {Graph<int>(0), {}};\n        auto comp\
    \ = [&](const int i, const int j) {\n            return hld.idx(i).first < hld.idx(j).first;\n\
    \        };\n        sort(begin(idx), end(idx), comp);\n        for(int i = 0,\
    \ ie = idx.size(); i + 1 < ie; ++i) {\n            idx.push_back(hld.lca(idx[i],\
    \ idx[i + 1]));\n        }\n        sort(begin(idx), end(idx), comp);\n      \
    \  idx.erase(unique(begin(idx), end(idx)), end(idx));\n        Graph<int> aux(idx.size());\n\
    \        vector<int> rs;\n        rs.push_back(0);\n        for(int i = 1; i <\
    \ (int)idx.size(); ++i) {\n            const int l = hld.lca(idx[rs.back()], idx[i]);\n\
    \            while(idx[rs.back()] != l) rs.pop_back();\n            aux.add_directed_edge(rs.back(),\
    \ i);\n            rs.push_back(i);\n        }\n        return make_pair(aux,\
    \ idx);\n    }\n\n   private:\n    Graph<T> g;\n    HeavyLightDecomposition<T>\
    \ hld;\n};"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/tree/heavy_light_decomposition.hpp
  isVerificationFile: false
  path: src/tree/auxiliary_tree.hpp
  requiredBy: []
  timestamp: '2025-07-25 17:08:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/tree/auxiliary_tree.test.cpp
documentation_of: src/tree/auxiliary_tree.hpp
layout: document
title: AuxiliaryTree
---

# AuxiliaryTree

$n$ 頂点の根付き木が与えられたとき，

- 与えられた頂点集合 $U$ に対して，子孫関係を保ったまま圧縮した木

を前計算 $O(n)$ クエリ $O(|U| \log n)$ で求めます．

## コンストラクタ

```cpp
AuxiliaryTree<T> aux(Graph<T> g, int root = 0)
```

- 頂点数 $n$ の木 `g` を与えると，`root` を根として前計算を行います．

**制約**

- `T` は `int / uint / ll / ull / double / long double`
- `g` は木
- $0 \leq \mathrm{root} < n$

**計算量**

- $O(n)$

## get

```cpp
pair<Graph<int>, vector<int>> aux.get(vector<int> idx)
```

頂点集合 `idx` を指定したときのAuxiliary Treeと，Auxiliary Treeと元の木の頂点番号の対応配列を返します．

**計算量**

$m$ を頂点集合 `idx` のサイズとして，

- $O(m \log n)$