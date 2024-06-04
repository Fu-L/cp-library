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
  - icon: ':x:'
    path: verify/library_checker/tree/frequency_table_of_tree_distance.test.cpp
    title: verify/library_checker/tree/frequency_table_of_tree_distance.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ g;\n};\ntemplate <typename T>\nusing Edges = vector<Edge<T>>;\n#line 4 \"src/tree/centroid_decomposition.hpp\"\
    \ntemplate <typename T>\npair<Graph<int>, int> centroid_decomposition(const Graph<T>&\
    \ g) {\n    const int n = g.size();\n    vector<int> sub(n);\n    vector<bool>\
    \ visited(n);\n    Graph<int> tree(n);\n    auto get_size = [&](auto& get_size,\
    \ int cur, int par) -> int {\n        sub[cur] = 1;\n        for(const Edge<T>&\
    \ e : g[cur]) {\n            if(e.to == par or visited[e.to]) continue;\n    \
    \        sub[cur] += get_size(get_size, e.to, cur);\n        }\n        return\
    \ sub[cur];\n    };\n    auto get_centroid = [&](auto& get_centroid, int cur,\
    \ int par, int mid) -> int {\n        for(const Edge<T>& e : g[cur]) {\n     \
    \       if(e.to == par or visited[e.to]) continue;\n            if(sub[e.to] >\
    \ mid) return get_centroid(get_centroid, e.to, cur, mid);\n        }\n       \
    \ return cur;\n    };\n    auto dfs = [&](auto& dfs, int cur) -> int {\n     \
    \   const int centroid = get_centroid(get_centroid, cur, -1, get_size(get_size,\
    \ cur, -1) / 2);\n        visited[centroid] = true;\n        for(const Edge<T>&\
    \ e : g[centroid]) {\n            if(visited[e.to]) continue;\n            const\
    \ int nex = dfs(dfs, e.to);\n            if(centroid != nex) tree.add_directed_edge(centroid,\
    \ nex);\n        }\n        visited[centroid] = false;\n        return centroid;\n\
    \    };\n    const int root = dfs(dfs, 0);\n    return {tree, root};\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../graph/graph_template.hpp\"\
    \ntemplate <typename T>\npair<Graph<int>, int> centroid_decomposition(const Graph<T>&\
    \ g) {\n    const int n = g.size();\n    vector<int> sub(n);\n    vector<bool>\
    \ visited(n);\n    Graph<int> tree(n);\n    auto get_size = [&](auto& get_size,\
    \ int cur, int par) -> int {\n        sub[cur] = 1;\n        for(const Edge<T>&\
    \ e : g[cur]) {\n            if(e.to == par or visited[e.to]) continue;\n    \
    \        sub[cur] += get_size(get_size, e.to, cur);\n        }\n        return\
    \ sub[cur];\n    };\n    auto get_centroid = [&](auto& get_centroid, int cur,\
    \ int par, int mid) -> int {\n        for(const Edge<T>& e : g[cur]) {\n     \
    \       if(e.to == par or visited[e.to]) continue;\n            if(sub[e.to] >\
    \ mid) return get_centroid(get_centroid, e.to, cur, mid);\n        }\n       \
    \ return cur;\n    };\n    auto dfs = [&](auto& dfs, int cur) -> int {\n     \
    \   const int centroid = get_centroid(get_centroid, cur, -1, get_size(get_size,\
    \ cur, -1) / 2);\n        visited[centroid] = true;\n        for(const Edge<T>&\
    \ e : g[centroid]) {\n            if(visited[e.to]) continue;\n            const\
    \ int nex = dfs(dfs, e.to);\n            if(centroid != nex) tree.add_directed_edge(centroid,\
    \ nex);\n        }\n        visited[centroid] = false;\n        return centroid;\n\
    \    };\n    const int root = dfs(dfs, 0);\n    return {tree, root};\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: LIBRARY_ALL_WA
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

`tree[i][j]` は頂点 $i$ まで木を分解したときにできる $i$ に隣接した連結成分の重心を指しています．

**制約**

- `g` は木

**計算量**

- $O(n \log n)$