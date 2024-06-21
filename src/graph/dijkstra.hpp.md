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
    path: verify/aizu_online_judge/grl/single_source_shortest_path.test.cpp
    title: verify/aizu_online_judge/grl/single_source_shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
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
    \ g;\n};\ntemplate <typename T>\nusing Edges = vector<Edge<T>>;\n#line 4 \"src/graph/dijkstra.hpp\"\
    \ntemplate <typename T>\nvector<pair<T, int>> dijkstra(const Graph<T>& g, const\
    \ int s = 0) {\n    const int n = g.size();\n    assert(0 <= s and s < n);\n \
    \   vector<pair<T, int>> d(n, {numeric_limits<T>::max(), -1});\n    priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n    d[s] = {0, -1};\n\
    \    pq.emplace(0, s);\n    while(!pq.empty()) {\n        const auto [dist, cur]\
    \ = pq.top();\n        pq.pop();\n        if(d[cur].first < dist) continue;\n\
    \        for(const Edge<T>& e : g[cur]) {\n            if(d[e.to].first > d[cur].first\
    \ + e.cost) {\n                d[e.to] = {d[cur].first + e.cost, cur};\n     \
    \           pq.emplace(d[e.to].first, e.to);\n            }\n        }\n    }\n\
    \    return d;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./graph_template.hpp\"\
    \ntemplate <typename T>\nvector<pair<T, int>> dijkstra(const Graph<T>& g, const\
    \ int s = 0) {\n    const int n = g.size();\n    assert(0 <= s and s < n);\n \
    \   vector<pair<T, int>> d(n, {numeric_limits<T>::max(), -1});\n    priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n    d[s] = {0, -1};\n\
    \    pq.emplace(0, s);\n    while(!pq.empty()) {\n        const auto [dist, cur]\
    \ = pq.top();\n        pq.pop();\n        if(d[cur].first < dist) continue;\n\
    \        for(const Edge<T>& e : g[cur]) {\n            if(d[e.to].first > d[cur].first\
    \ + e.cost) {\n                d[e.to] = {d[cur].first + e.cost, cur};\n     \
    \           pq.emplace(d[e.to].first, e.to);\n            }\n        }\n    }\n\
    \    return d;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/grl/single_source_shortest_path.test.cpp
  - verify/library_checker/graph/shortest_path.test.cpp
documentation_of: src/graph/dijkstra.hpp
layout: document
title: dijkstra
---

## dijkstra

```cpp
vector<pair<T, int>> dijkstra(Graph<T> g, int s = 0)
```

$n$ 頂点のグラフ `g` 上で頂点 `s` を始点とした最短経路探索を行います．

返り値は長さ $n$ の `pair` 型の配列です．<br>
`pair` 型の第一要素は頂点 `s` から頂点 `i` までの最短距離を，第二要素は頂点 `i` にたどり着く直前にいた頂点番号を保持しています．

もし頂点 `i` に到達できない場合， `pair` 型の第一要素は `numeric_limits<T>::max()` で，第二要素は $-1$ です．

**制約**

- $0 \leq s < n$

**計算量**

- $O(E \log V)$