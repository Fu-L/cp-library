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
    path: verify/unit_test/graph/bipartite.test.cpp
    title: verify/unit_test/graph/bipartite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ Edges = vector<Edge<T>>;\n#line 4 \"src/graph/bipartite.hpp\"\ntemplate <typename\
    \ T>\nvector<int> bipartite(const Graph<T>& g) {\n    const int n = g.size();\n\
    \    vector<int> color(n, -1);\n    auto dfs = [&](const auto& dfs, const int\
    \ cur, const int col) -> bool {\n        color[cur] = col;\n        for(const\
    \ Edge<T>& e : g[cur]) {\n            if(color[e.to] == col) return false;\n \
    \           if(color[e.to] == -1 and !dfs(dfs, e.to, 1 - col)) return false;\n\
    \        }\n        return true;\n    };\n    for(int i = 0; i < n; ++i) {\n \
    \       if(color[i] != -1) continue;\n        if(!dfs(dfs, i, 0)) return {};\n\
    \    }\n    return color;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./graph_template.hpp\"\
    \ntemplate <typename T>\nvector<int> bipartite(const Graph<T>& g) {\n    const\
    \ int n = g.size();\n    vector<int> color(n, -1);\n    auto dfs = [&](const auto&\
    \ dfs, const int cur, const int col) -> bool {\n        color[cur] = col;\n  \
    \      for(const Edge<T>& e : g[cur]) {\n            if(color[e.to] == col) return\
    \ false;\n            if(color[e.to] == -1 and !dfs(dfs, e.to, 1 - col)) return\
    \ false;\n        }\n        return true;\n    };\n    for(int i = 0; i < n; ++i)\
    \ {\n        if(color[i] != -1) continue;\n        if(!dfs(dfs, i, 0)) return\
    \ {};\n    }\n    return color;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/bipartite.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/unit_test/graph/bipartite.test.cpp
documentation_of: src/graph/bipartite.hpp
layout: document
title: bipartite
---

## bipartite

```cpp
vector<int> bipartite(Graph<T> g)
```

$n$ 頂点 $m$ 辺の無向グラフ `g` が二部グラフかどうか判定します．

`g` が二部グラフである場合， `g` の各頂点を $0$ と $1$ で彩色した配列を返します．<br>
二部グラフでない場合は空の配列を返します．

**計算量**

- $O(n + m)$