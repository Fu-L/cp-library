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
    #line 4 \"src/graph/dijkstra.hpp\"\ntemplate <typename T>\nvector<pair<T, int>>\
    \ dijkstra(const Graph<T>& g, const int s = 0) {\n    int n = g.size();\n    assert(0\
    \ <= s and s < n);\n    vector<pair<T, int>> d(n, {numeric_limits<T>::max(), -1});\n\
    \    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>>\
    \ pq;\n    d[s] = {0, -1};\n    pq.push({0, s});\n    while(!pq.empty()) {\n \
    \       pair<T, int> p = pq.top();\n        pq.pop();\n        T dist = p.first;\n\
    \        int cur = p.second;\n        if(d[cur].first < dist) continue;\n    \
    \    for(const Edge<T>& edge : g[cur]) {\n            if(d[edge.to].first > d[cur].first\
    \ + edge.cost) {\n                d[edge.to] = {d[cur].first + edge.cost, cur};\n\
    \                pq.push({d[edge.to].first, edge.to});\n            }\n      \
    \  }\n    }\n    return d;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./graph_template.hpp\"\
    \ntemplate <typename T>\nvector<pair<T, int>> dijkstra(const Graph<T>& g, const\
    \ int s = 0) {\n    int n = g.size();\n    assert(0 <= s and s < n);\n    vector<pair<T,\
    \ int>> d(n, {numeric_limits<T>::max(), -1});\n    priority_queue<pair<T, int>,\
    \ vector<pair<T, int>>, greater<pair<T, int>>> pq;\n    d[s] = {0, -1};\n    pq.push({0,\
    \ s});\n    while(!pq.empty()) {\n        pair<T, int> p = pq.top();\n       \
    \ pq.pop();\n        T dist = p.first;\n        int cur = p.second;\n        if(d[cur].first\
    \ < dist) continue;\n        for(const Edge<T>& edge : g[cur]) {\n           \
    \ if(d[edge.to].first > d[cur].first + edge.cost) {\n                d[edge.to]\
    \ = {d[cur].first + edge.cost, cur};\n                pq.push({d[edge.to].first,\
    \ edge.to});\n            }\n        }\n    }\n    return d;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2024-01-05 04:01:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/grl/single_source_shortest_path.test.cpp
  - verify/library_checker/graph/shortest_path.test.cpp
documentation_of: src/graph/dijkstra.hpp
layout: document
title: dijkstra
---