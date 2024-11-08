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
    path: verify/library_checker/graph/cycle_detection_directed.test.cpp
    title: verify/library_checker/graph/cycle_detection_directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/cycle_detection_undirected.test.cpp
    title: verify/library_checker/graph/cycle_detection_undirected.test.cpp
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
    \ Edges = vector<Edge<T>>;\n#line 4 \"src/graph/cycle_detection.hpp\"\ntemplate\
    \ <typename T>\nEdges<T> cycle_detection(const Graph<T>& g, const bool directed\
    \ = true) {\n    const int n = g.size();\n    for(int i = 0; i < n; ++i) {\n \
    \       for(const Edge<T>& e : g[i]) {\n            if(i == e.to) return {e};\n\
    \        }\n    }\n    Edges<T> cycle;\n    vector<int> pre(n, -1), visited(n,\
    \ 0);\n    int finish = 0;\n    auto dfs = [&](const auto& dfs, const int cur,\
    \ const int pval, const Edge<T>& par) -> int {\n        pre[cur] = pval;\n   \
    \     visited[cur] = 1;\n        for(const Edge<T>& e : g[cur]) {\n          \
    \  if(finish) return -1;\n            if(!directed and e.idx == par.idx) continue;\n\
    \            if(pre[e.to] == pre[cur]) {\n                cycle.emplace_back(e);\n\
    \                return e.to;\n            }\n            if(visited[e.to]) continue;\n\
    \            const int nx = dfs(dfs, e.to, pval, e);\n            if(nx != -1)\
    \ {\n                cycle.emplace_back(e);\n                if(cur == nx) {\n\
    \                    finish = 1;\n                    return -1;\n           \
    \     }\n                return nx;\n            }\n        }\n        pre[cur]\
    \ = -1;\n        return -1;\n    };\n    for(int i = 0; i < n; ++i) {\n      \
    \  if(visited[i]) continue;\n        dfs(dfs, i, i, Edge<T>());\n        if(finish)\
    \ {\n            reverse(begin(cycle), end(cycle));\n            return cycle;\n\
    \        }\n    }\n    return {};\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./graph_template.hpp\"\
    \ntemplate <typename T>\nEdges<T> cycle_detection(const Graph<T>& g, const bool\
    \ directed = true) {\n    const int n = g.size();\n    for(int i = 0; i < n; ++i)\
    \ {\n        for(const Edge<T>& e : g[i]) {\n            if(i == e.to) return\
    \ {e};\n        }\n    }\n    Edges<T> cycle;\n    vector<int> pre(n, -1), visited(n,\
    \ 0);\n    int finish = 0;\n    auto dfs = [&](const auto& dfs, const int cur,\
    \ const int pval, const Edge<T>& par) -> int {\n        pre[cur] = pval;\n   \
    \     visited[cur] = 1;\n        for(const Edge<T>& e : g[cur]) {\n          \
    \  if(finish) return -1;\n            if(!directed and e.idx == par.idx) continue;\n\
    \            if(pre[e.to] == pre[cur]) {\n                cycle.emplace_back(e);\n\
    \                return e.to;\n            }\n            if(visited[e.to]) continue;\n\
    \            const int nx = dfs(dfs, e.to, pval, e);\n            if(nx != -1)\
    \ {\n                cycle.emplace_back(e);\n                if(cur == nx) {\n\
    \                    finish = 1;\n                    return -1;\n           \
    \     }\n                return nx;\n            }\n        }\n        pre[cur]\
    \ = -1;\n        return -1;\n    };\n    for(int i = 0; i < n; ++i) {\n      \
    \  if(visited[i]) continue;\n        dfs(dfs, i, i, Edge<T>());\n        if(finish)\
    \ {\n            reverse(begin(cycle), end(cycle));\n            return cycle;\n\
    \        }\n    }\n    return {};\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/cycle_detection.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/graph/cycle_detection_undirected.test.cpp
  - verify/library_checker/graph/cycle_detection_directed.test.cpp
documentation_of: src/graph/cycle_detection.hpp
layout: document
title: cycle_detection
---

## cycle_detection

```cpp
Edges<T> cycle_detection(Graph<T> g, bool directed = true)
```

$n$ 頂点 $m$ 辺のグラフ `g` の閉路検出を行います．

`directed = true` のとき `g` を有向グラフとして計算します．<br>
`directed = false` のとき `g` を無向グラフとして計算します．

閉路がある場合，閉路を構成する辺を返します．<br>
閉路がない場合，空の辺集合を返します．<br>

**計算量**

- $O(n + m)$