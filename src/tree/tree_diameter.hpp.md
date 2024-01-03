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
    path: verify/aizu_online_judge/grl/diameter_of_a_tree.test.cpp
    title: verify/aizu_online_judge/grl/diameter_of_a_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/tree_diameter.test.cpp
    title: verify/library_checker/tree/tree_diameter.test.cpp
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
    \    int idx;\n    Edge(int from, int to, T cost = 1, int idx = -1)\n        :\
    \ from(from), to(to), cost(cost), idx(idx) {}\n    operator int() const {\n  \
    \      return to;\n    }\n};\ntemplate <typename T = int>\nstruct Graph {\n  \
    \  vector<vector<Edge<T>>> g;\n    int es;\n    Graph(int n)\n        : g(n),\
    \ es(0) {}\n    size_t size() const {\n        return g.size();\n    }\n    void\
    \ add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n \
    \   void add_directed_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es++);\n    }\n    inline vector<Edge<T>>& operator[](const int& k)\
    \ {\n        return g[k];\n    }\n    inline const vector<Edge<T>>& operator[](const\
    \ int& k) const {\n        return g[k];\n    }\n};\ntemplate <typename T = int>\n\
    using Edges = vector<Edge<T>>;\n#line 4 \"src/tree/tree_diameter.hpp\"\ntemplate\
    \ <typename T = int>\npair<T, vector<int>> tree_diameter(const Graph<T>& g) {\n\
    \    int n = (int)g.size();\n    vector<T> depth(n);\n    vector<int> par(n);\n\
    \    auto dfs = [&](auto& dfs, int v, int p, T d) -> void {\n        depth[v]\
    \ = d;\n        par[v] = p;\n        for(auto& e : g[v]) {\n            if(e.to\
    \ == p) continue;\n            dfs(dfs, e.to, v, d + e.cost);\n        }\n   \
    \ };\n    int s = 0;\n    for(int i = 0; i < 2; ++i) {\n        dfs(dfs, s, -1,\
    \ 0);\n        T ma = -1;\n        for(int j = 0; j < n; ++j) {\n            if(depth[j]\
    \ > ma) {\n                ma = depth[j];\n                s = j;\n          \
    \  }\n        }\n    }\n    vector<int> path;\n    T diameter = depth[s];\n  \
    \  while(s != -1) {\n        path.push_back(s);\n        s = par[s];\n    }\n\
    \    return {diameter, path};\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../graph/graph_template.hpp\"\
    \ntemplate <typename T = int>\npair<T, vector<int>> tree_diameter(const Graph<T>&\
    \ g) {\n    int n = (int)g.size();\n    vector<T> depth(n);\n    vector<int> par(n);\n\
    \    auto dfs = [&](auto& dfs, int v, int p, T d) -> void {\n        depth[v]\
    \ = d;\n        par[v] = p;\n        for(auto& e : g[v]) {\n            if(e.to\
    \ == p) continue;\n            dfs(dfs, e.to, v, d + e.cost);\n        }\n   \
    \ };\n    int s = 0;\n    for(int i = 0; i < 2; ++i) {\n        dfs(dfs, s, -1,\
    \ 0);\n        T ma = -1;\n        for(int j = 0; j < n; ++j) {\n            if(depth[j]\
    \ > ma) {\n                ma = depth[j];\n                s = j;\n          \
    \  }\n        }\n    }\n    vector<int> path;\n    T diameter = depth[s];\n  \
    \  while(s != -1) {\n        path.push_back(s);\n        s = par[s];\n    }\n\
    \    return {diameter, path};\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/tree/tree_diameter.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/grl/diameter_of_a_tree.test.cpp
  - verify/library_checker/tree/tree_diameter.test.cpp
documentation_of: src/tree/tree_diameter.hpp
layout: document
title: tree_diameter
---

# tree_diameter

```cpp
pair<T, vector<int>> tree_diameter(Graph<T> g)
```

$n$ 頂点の木 `g` を与えると，その木の直径のうち1つを選んで，パス長と，パスの頂点を順に格納した配列を返します．<br> 
木の直径になりうるパスが複数あるとき，どのパスが選ばれるかは未定義です．

**制約**

- `T` は `int / uint / ll / ull / double / long double`
- `g` は木

**計算量**

- $O(n)$