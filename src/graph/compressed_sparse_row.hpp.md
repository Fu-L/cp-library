---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/strongly_connected_components.hpp
    title: strongly_connected_components
  - icon: ':heavy_check_mark:'
    path: src/graph/two_sat.hpp
    title: TwoSAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/strongly_connected_components.test.cpp
    title: verify/aizu_online_judge/grl/strongly_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/strongly_connected_components.test.cpp
    title: verify/library_checker/graph/strongly_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/other/2_sat.test.cpp
    title: verify/library_checker/other/2_sat.test.cpp
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
    \ Edges = vector<Edge<T>>;\n#line 4 \"src/graph/compressed_sparse_row.hpp\"\n\
    template <typename T>\nstruct CompressedSparseRow {\n    vector<int> start, elist;\n\
    \    CompressedSparseRow(const Graph<T>& g)\n        : start(g.size() + 1), elist(g.edge_size())\
    \ {\n        const int n = g.size();\n        for(int i = 0; i < n; ++i) {\n \
    \           start[i + 1] = start[i] + g[i].size();\n            int counter =\
    \ start[i];\n            for(const Edge<T>& e : g[i]) {\n                elist[counter++]\
    \ = e.to;\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./graph_template.hpp\"\
    \ntemplate <typename T>\nstruct CompressedSparseRow {\n    vector<int> start,\
    \ elist;\n    CompressedSparseRow(const Graph<T>& g)\n        : start(g.size()\
    \ + 1), elist(g.edge_size()) {\n        const int n = g.size();\n        for(int\
    \ i = 0; i < n; ++i) {\n            start[i + 1] = start[i] + g[i].size();\n \
    \           int counter = start[i];\n            for(const Edge<T>& e : g[i])\
    \ {\n                elist[counter++] = e.to;\n            }\n        }\n    }\n\
    };"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/compressed_sparse_row.hpp
  requiredBy:
  - src/graph/two_sat.hpp
  - src/graph/strongly_connected_components.hpp
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/graph/strongly_connected_components.test.cpp
  - verify/library_checker/other/2_sat.test.cpp
  - verify/aizu_online_judge/grl/strongly_connected_components.test.cpp
documentation_of: src/graph/compressed_sparse_row.hpp
layout: document
title: CompressedSparseRow
---

# CompressedSparseRow

`vector<vector<int>>` などをアーキテクチャ的に高速化するための構造体です．<br>
基本的には内部的にしか使用しないと思うので，把握する必要はありません．