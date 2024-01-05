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
    path: verify/library_checker/tree/frequency_table_of_tree_distance.test.cpp
    title: verify/library_checker/tree/frequency_table_of_tree_distance.test.cpp
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
    #line 4 \"src/tree/centroid_decomposition.hpp\"\ntemplate <typename T>\npair<Graph<int>,\
    \ int> centroid_decomposition(const Graph<T>& g) {\n    const int n = (int)g.size();\n\
    \    vector<int> sub(n);\n    vector<bool> visited(n);\n    Graph<int> tree(n);\n\
    \    auto get_size = [&](auto& get_size, int cur, int par) -> int {\n        sub[cur]\
    \ = 1;\n        for(const Edge<T>& e : g[cur]) {\n            if(e.to == par or\
    \ visited[e.to]) continue;\n            sub[cur] += get_size(get_size, e.to, cur);\n\
    \        }\n        return sub[cur];\n    };\n    auto get_centroid = [&](auto&\
    \ get_size, auto& get_centroid, int cur, int par, int mid) -> int {\n        for(const\
    \ Edge<T>& e : g[cur]) {\n            if(e.to == par or visited[e.to]) continue;\n\
    \            if(sub[e.to] > mid) return get_centroid(get_size, get_centroid, e.to,\
    \ cur, mid);\n        }\n        return cur;\n    };\n    auto dfs = [&](auto&\
    \ get_size, auto& get_centroid, auto& dfs, int cur) -> int {\n        int centroid\
    \ = get_centroid(get_size, get_centroid, cur, -1, get_size(get_size, cur, -1)\
    \ / 2);\n        visited[centroid] = true;\n        for(const Edge<T>& e : g[centroid])\
    \ {\n            if(visited[e.to]) continue;\n            int nex = dfs(get_size,\
    \ get_centroid, dfs, e.to);\n            if(centroid != nex) tree.add_directed_edge(centroid,\
    \ nex);\n        }\n        visited[centroid] = false;\n        return centroid;\n\
    \    };\n    int root = dfs(get_size, get_centroid, dfs, 0);\n    return {tree,\
    \ root};\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../graph/graph_template.hpp\"\
    \ntemplate <typename T>\npair<Graph<int>, int> centroid_decomposition(const Graph<T>&\
    \ g) {\n    const int n = (int)g.size();\n    vector<int> sub(n);\n    vector<bool>\
    \ visited(n);\n    Graph<int> tree(n);\n    auto get_size = [&](auto& get_size,\
    \ int cur, int par) -> int {\n        sub[cur] = 1;\n        for(const Edge<T>&\
    \ e : g[cur]) {\n            if(e.to == par or visited[e.to]) continue;\n    \
    \        sub[cur] += get_size(get_size, e.to, cur);\n        }\n        return\
    \ sub[cur];\n    };\n    auto get_centroid = [&](auto& get_size, auto& get_centroid,\
    \ int cur, int par, int mid) -> int {\n        for(const Edge<T>& e : g[cur])\
    \ {\n            if(e.to == par or visited[e.to]) continue;\n            if(sub[e.to]\
    \ > mid) return get_centroid(get_size, get_centroid, e.to, cur, mid);\n      \
    \  }\n        return cur;\n    };\n    auto dfs = [&](auto& get_size, auto& get_centroid,\
    \ auto& dfs, int cur) -> int {\n        int centroid = get_centroid(get_size,\
    \ get_centroid, cur, -1, get_size(get_size, cur, -1) / 2);\n        visited[centroid]\
    \ = true;\n        for(const Edge<T>& e : g[centroid]) {\n            if(visited[e.to])\
    \ continue;\n            int nex = dfs(get_size, get_centroid, dfs, e.to);\n \
    \           if(centroid != nex) tree.add_directed_edge(centroid, nex);\n     \
    \   }\n        visited[centroid] = false;\n        return centroid;\n    };\n\
    \    int root = dfs(get_size, get_centroid, dfs, 0);\n    return {tree, root};\n\
    }"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2024-01-06 02:09:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/tree/frequency_table_of_tree_distance.test.cpp
documentation_of: src/tree/centroid_decomposition.hpp
layout: document
title: centroid_decomposition
---

## centroid_decomposition

```cpp
pait<Graph<int>, int> centroid_decomposition(Graph<T> g)
```

$n$ 頂点の木 `g` を入力すると重心分解した木 `tree` と，その根 `root` を返します．

`tree[i][j]` は頂点 $i$ まで木を分解したときにできる連結成分の重心を指しています．

**制約**

- `g` は木

**計算量**

- $O(n \log n)$