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
    path: verify/library_checker/data_structure/vertex_add_path_sum.test.cpp
    title: verify/library_checker/data_structure/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/vertex_add_subtree_sum.test.cpp
    title: verify/library_checker/data_structure/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/vertex_set_path_composite.test.cpp
    title: verify/library_checker/data_structure/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/jump_on_tree.test.cpp
    title: verify/library_checker/tree/jump_on_tree.test.cpp
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
    \ntemplate <typename T = int>\nstruct Edge {\n    int from, to;\n    T cost;\n\
    \    int idx;\n    Edge()\n        : from(-1), to(-1), cost(-1), idx(-1) {}\n\
    \    Edge(int from, int to, T cost = 1, int idx = -1)\n        : from(from), to(to),\
    \ cost(cost), idx(idx) {}\n    operator int() const {\n        return to;\n  \
    \  }\n};\ntemplate <typename T = int>\nstruct Graph {\n    vector<vector<Edge<T>>>\
    \ g;\n    int es;\n    Graph(int n)\n        : g(n), es(0) {}\n    size_t size()\
    \ const {\n        return g.size();\n    }\n    void add_edge(int from, int to,\
    \ T cost = 1) {\n        g[from].emplace_back(from, to, cost, es);\n        g[to].emplace_back(to,\
    \ from, cost, es++);\n    }\n    void add_directed_edge(int from, int to, T cost\
    \ = 1) {\n        g[from].emplace_back(from, to, cost, es++);\n    }\n    inline\
    \ vector<Edge<T>>& operator[](const int& k) {\n        return g[k];\n    }\n \
    \   inline const vector<Edge<T>>& operator[](const int& k) const {\n        return\
    \ g[k];\n    }\n};\ntemplate <typename T = int>\nusing Edges = vector<Edge<T>>;\n\
    #line 4 \"src/tree/heavy_light_decomposition.hpp\"\ntemplate <typename T>\nstruct\
    \ HeavyLightDecomposition {\n    HeavyLightDecomposition(Graph<T>& _g, int root\
    \ = 0)\n        : g(_g), n(g.size()), id(0), size(n, 0), depth(n, 0), down(n,\
    \ -1), up(n, -1), nex(n, root), par(n, root), rev(n, 0) {\n        assert(0 <=\
    \ root and root < n);\n        dfs_sz(root);\n        dfs_hld(root);\n    }\n\
    \    pair<int, int> idx(int i) const {\n        assert(0 <= i and i < n);\n  \
    \      return make_pair(down[i], up[i]);\n    }\n    int la(int a, int k) const\
    \ {\n        assert(0 <= a and a < n);\n        if(k > depth[a]) return -1;\n\
    \        while(true) {\n            int b = nex[a];\n            if(down[a] -\
    \ k >= down[b]) return rev[down[a] - k];\n            k -= down[a] - down[b] +\
    \ 1;\n            a = par[b];\n        }\n    }\n    int lca(int a, int b) const\
    \ {\n        assert(0 <= a and a < n);\n        assert(0 <= b and b < n);\n  \
    \      while(nex[a] != nex[b]) {\n            if(down[a] < down[b]) swap(a, b);\n\
    \            a = par[nex[a]];\n        }\n        return depth[a] < depth[b] ?\
    \ a : b;\n    }\n    int dist(int a, int b) const {\n        assert(0 <= a and\
    \ a < n);\n        assert(0 <= b and b < n);\n        return depth[a] + depth[b]\
    \ - depth[lca(a, b)] * 2;\n    }\n    template <typename F>\n    void path_query(int\
    \ u, int v, bool vertex, const F& f) {\n        assert(0 <= u and u < n);\n  \
    \      assert(0 <= v and v < n);\n        int l = lca(u, v);\n        for(auto&&\
    \ [a, b] : ascend(u, l)) f(a + 1, b);\n        if(vertex) f(down[l], down[l] +\
    \ 1);\n        for(auto&& [a, b] : descend(l, v)) f(a, b + 1);\n    }\n    template\
    \ <typename F>\n    void subtree_query(int u, bool vertex, const F& f) {\n   \
    \     assert(0 <= u and u < n);\n        f(down[u] + int(!vertex), up[u]);\n \
    \   }\n\n   private:\n    Graph<T>& g;\n    int n, id;\n    vector<int> size,\
    \ depth, down, up, nex, par, rev;\n    void dfs_sz(int cur) {\n        size[cur]\
    \ = 1;\n        for(auto& edge : g[cur]) {\n            if(edge.to == par[cur])\
    \ {\n                if(g[cur].size() >= 2 and edge.to == g[cur][0].to) {\n  \
    \                  swap(g[cur][0], g[cur][1]);\n                } else {\n   \
    \                 continue;\n                }\n            }\n            depth[edge.to]\
    \ = depth[cur] + 1;\n            par[edge.to] = cur;\n            dfs_sz(edge.to);\n\
    \            size[cur] += size[edge.to];\n            if(size[edge.to] > size[g[cur][0].to])\
    \ {\n                swap(edge, g[cur][0]);\n            }\n        }\n    }\n\
    \    void dfs_hld(int cur) {\n        down[cur] = id++;\n        rev[down[cur]]\
    \ = cur;\n        for(const auto& edge : g[cur]) {\n            if(edge.to ==\
    \ par[cur]) continue;\n            nex[edge.to] = (edge.to == g[cur][0].to ? nex[cur]\
    \ : edge.to);\n            dfs_hld(edge.to);\n        }\n        up[cur] = id;\n\
    \    }\n    vector<pair<int, int>> ascend(int u, int v) const {\n        vector<pair<int,\
    \ int>> res;\n        while(nex[u] != nex[v]) {\n            res.emplace_back(down[u],\
    \ down[nex[u]]);\n            u = par[nex[u]];\n        }\n        if(u != v)\
    \ res.emplace_back(down[u], down[v] + 1);\n        return res;\n    }\n    vector<pair<int,\
    \ int>> descend(int u, int v) const {\n        if(u == v) return {};\n       \
    \ if(nex[u] == nex[v]) return {{down[u] + 1, down[v]}};\n        auto res = descend(u,\
    \ par[nex[v]]);\n        res.emplace_back(down[nex[v]], down[v]);\n        return\
    \ res;\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../graph/graph_template.hpp\"\
    \ntemplate <typename T>\nstruct HeavyLightDecomposition {\n    HeavyLightDecomposition(Graph<T>&\
    \ _g, int root = 0)\n        : g(_g), n(g.size()), id(0), size(n, 0), depth(n,\
    \ 0), down(n, -1), up(n, -1), nex(n, root), par(n, root), rev(n, 0) {\n      \
    \  assert(0 <= root and root < n);\n        dfs_sz(root);\n        dfs_hld(root);\n\
    \    }\n    pair<int, int> idx(int i) const {\n        assert(0 <= i and i < n);\n\
    \        return make_pair(down[i], up[i]);\n    }\n    int la(int a, int k) const\
    \ {\n        assert(0 <= a and a < n);\n        if(k > depth[a]) return -1;\n\
    \        while(true) {\n            int b = nex[a];\n            if(down[a] -\
    \ k >= down[b]) return rev[down[a] - k];\n            k -= down[a] - down[b] +\
    \ 1;\n            a = par[b];\n        }\n    }\n    int lca(int a, int b) const\
    \ {\n        assert(0 <= a and a < n);\n        assert(0 <= b and b < n);\n  \
    \      while(nex[a] != nex[b]) {\n            if(down[a] < down[b]) swap(a, b);\n\
    \            a = par[nex[a]];\n        }\n        return depth[a] < depth[b] ?\
    \ a : b;\n    }\n    int dist(int a, int b) const {\n        assert(0 <= a and\
    \ a < n);\n        assert(0 <= b and b < n);\n        return depth[a] + depth[b]\
    \ - depth[lca(a, b)] * 2;\n    }\n    template <typename F>\n    void path_query(int\
    \ u, int v, bool vertex, const F& f) {\n        assert(0 <= u and u < n);\n  \
    \      assert(0 <= v and v < n);\n        int l = lca(u, v);\n        for(auto&&\
    \ [a, b] : ascend(u, l)) f(a + 1, b);\n        if(vertex) f(down[l], down[l] +\
    \ 1);\n        for(auto&& [a, b] : descend(l, v)) f(a, b + 1);\n    }\n    template\
    \ <typename F>\n    void subtree_query(int u, bool vertex, const F& f) {\n   \
    \     assert(0 <= u and u < n);\n        f(down[u] + int(!vertex), up[u]);\n \
    \   }\n\n   private:\n    Graph<T>& g;\n    int n, id;\n    vector<int> size,\
    \ depth, down, up, nex, par, rev;\n    void dfs_sz(int cur) {\n        size[cur]\
    \ = 1;\n        for(auto& edge : g[cur]) {\n            if(edge.to == par[cur])\
    \ {\n                if(g[cur].size() >= 2 and edge.to == g[cur][0].to) {\n  \
    \                  swap(g[cur][0], g[cur][1]);\n                } else {\n   \
    \                 continue;\n                }\n            }\n            depth[edge.to]\
    \ = depth[cur] + 1;\n            par[edge.to] = cur;\n            dfs_sz(edge.to);\n\
    \            size[cur] += size[edge.to];\n            if(size[edge.to] > size[g[cur][0].to])\
    \ {\n                swap(edge, g[cur][0]);\n            }\n        }\n    }\n\
    \    void dfs_hld(int cur) {\n        down[cur] = id++;\n        rev[down[cur]]\
    \ = cur;\n        for(const auto& edge : g[cur]) {\n            if(edge.to ==\
    \ par[cur]) continue;\n            nex[edge.to] = (edge.to == g[cur][0].to ? nex[cur]\
    \ : edge.to);\n            dfs_hld(edge.to);\n        }\n        up[cur] = id;\n\
    \    }\n    vector<pair<int, int>> ascend(int u, int v) const {\n        vector<pair<int,\
    \ int>> res;\n        while(nex[u] != nex[v]) {\n            res.emplace_back(down[u],\
    \ down[nex[u]]);\n            u = par[nex[u]];\n        }\n        if(u != v)\
    \ res.emplace_back(down[u], down[v] + 1);\n        return res;\n    }\n    vector<pair<int,\
    \ int>> descend(int u, int v) const {\n        if(u == v) return {};\n       \
    \ if(nex[u] == nex[v]) return {{down[u] + 1, down[v]}};\n        auto res = descend(u,\
    \ par[nex[v]]);\n        res.emplace_back(down[nex[v]], down[v]);\n        return\
    \ res;\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/tree/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2024-01-07 06:02:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp
  - verify/aizu_online_judge/grl/range_query_on_a_tree.test.cpp
  - verify/library_checker/data_structure/vertex_add_subtree_sum.test.cpp
  - verify/library_checker/data_structure/vertex_add_path_sum.test.cpp
  - verify/library_checker/data_structure/vertex_set_path_composite.test.cpp
  - verify/library_checker/tree/jump_on_tree.test.cpp
documentation_of: src/tree/heavy_light_decomposition.hpp
layout: document
title: HeavyLightDecomposition
---

# HeavyLightDecomposition

木をHL分解します．