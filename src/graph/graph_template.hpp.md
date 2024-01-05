---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/biconnected_components.hpp
    title: BiconnectedComponents
  - icon: ':heavy_check_mark:'
    path: src/graph/compressed_sparse_row.hpp
    title: CompressedSparseRow
  - icon: ':heavy_check_mark:'
    path: src/graph/cycle_detection.hpp
    title: cycle_detection
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: dijkstra
  - icon: ':heavy_check_mark:'
    path: src/graph/kruskal.hpp
    title: kruskal
  - icon: ':heavy_check_mark:'
    path: src/graph/low_link.hpp
    title: LowLink
  - icon: ':heavy_check_mark:'
    path: src/graph/strongly_connected_components.hpp
    title: strongly_connected_components
  - icon: ':heavy_check_mark:'
    path: src/graph/topological_sort.hpp
    title: topological_sort
  - icon: ':heavy_check_mark:'
    path: src/graph/two_edge_connected_components.hpp
    title: TwoEdgeConnectedComponents
  - icon: ':heavy_check_mark:'
    path: src/graph/two_sat.hpp
    title: TwoSAT
  - icon: ':heavy_check_mark:'
    path: src/tree/cartesian_tree.hpp
    title: cartesian_tree
  - icon: ':heavy_check_mark:'
    path: src/tree/centroid_decomposition.hpp
    title: centroid_decomposition
  - icon: ':heavy_check_mark:'
    path: src/tree/lowest_common_ancestor.hpp
    title: LowestCommonAncestor
  - icon: ':heavy_check_mark:'
    path: src/tree/tree_diameter.hpp
    title: tree_diameter
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/articulation_points.test.cpp
    title: verify/aizu_online_judge/grl/articulation_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/bridges.test.cpp
    title: verify/aizu_online_judge/grl/bridges.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/cycle_detection_for_a_directed_graph.test.cpp
    title: verify/aizu_online_judge/grl/cycle_detection_for_a_directed_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/diameter_of_a_tree.test.cpp
    title: verify/aizu_online_judge/grl/diameter_of_a_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/lowest_common_ancestor.test.cpp
    title: verify/aizu_online_judge/grl/lowest_common_ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/minimum_spanning_tree.test.cpp
    title: verify/aizu_online_judge/grl/minimum_spanning_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/single_source_shortest_path.test.cpp
    title: verify/aizu_online_judge/grl/single_source_shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/strongly_connected_components.test.cpp
    title: verify/aizu_online_judge/grl/strongly_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/biconnected_components.test.cpp
    title: verify/library_checker/graph/biconnected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/cycle_detection_directed.test.cpp
    title: verify/library_checker/graph/cycle_detection_directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/cycle_detection_undirected.test.cpp
    title: verify/library_checker/graph/cycle_detection_undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/minimum_spanning_tree.test.cpp
    title: verify/library_checker/graph/minimum_spanning_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/strongly_connected_components.test.cpp
    title: verify/library_checker/graph/strongly_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/two_edge_connected_components.test.cpp
    title: verify/library_checker/graph/two_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/math/2_sat.test.cpp
    title: verify/library_checker/math/2_sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/cartesian_tree.test.cpp
    title: verify/library_checker/tree/cartesian_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/frequency_table_of_tree_distance.test.cpp
    title: verify/library_checker/tree/frequency_table_of_tree_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/lowest_common_ancestor.test.cpp
    title: verify/library_checker/tree/lowest_common_ancestor.test.cpp
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
    \ g[k];\n    }\n};\ntemplate <typename T = int>\nusing Edges = vector<Edge<T>>;\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T\
    \ = int>\nstruct Edge {\n    int from, to;\n    T cost;\n    int idx;\n    Edge()\n\
    \        : from(-1), to(-1), cost(-1), idx(-1) {}\n    Edge(int from, int to,\
    \ T cost = 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n    operator int() const {\n        return to;\n    }\n};\ntemplate <typename\
    \ T = int>\nstruct Graph {\n    vector<vector<Edge<T>>> g;\n    int es;\n    Graph(int\
    \ n)\n        : g(n), es(0) {}\n    size_t size() const {\n        return g.size();\n\
    \    }\n    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n \
    \   void add_directed_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es++);\n    }\n    inline vector<Edge<T>>& operator[](const int& k)\
    \ {\n        return g[k];\n    }\n    inline const vector<Edge<T>>& operator[](const\
    \ int& k) const {\n        return g[k];\n    }\n};\ntemplate <typename T = int>\n\
    using Edges = vector<Edge<T>>;"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/graph/graph_template.hpp
  requiredBy:
  - src/tree/lowest_common_ancestor.hpp
  - src/tree/cartesian_tree.hpp
  - src/tree/centroid_decomposition.hpp
  - src/tree/tree_diameter.hpp
  - src/graph/biconnected_components.hpp
  - src/graph/low_link.hpp
  - src/graph/topological_sort.hpp
  - src/graph/strongly_connected_components.hpp
  - src/graph/two_edge_connected_components.hpp
  - src/graph/dijkstra.hpp
  - src/graph/two_sat.hpp
  - src/graph/compressed_sparse_row.hpp
  - src/graph/kruskal.hpp
  - src/graph/cycle_detection.hpp
  timestamp: '2024-01-05 00:27:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/grl/articulation_points.test.cpp
  - verify/aizu_online_judge/grl/single_source_shortest_path.test.cpp
  - verify/aizu_online_judge/grl/strongly_connected_components.test.cpp
  - verify/aizu_online_judge/grl/cycle_detection_for_a_directed_graph.test.cpp
  - verify/aizu_online_judge/grl/minimum_spanning_tree.test.cpp
  - verify/aizu_online_judge/grl/diameter_of_a_tree.test.cpp
  - verify/aizu_online_judge/grl/lowest_common_ancestor.test.cpp
  - verify/aizu_online_judge/grl/bridges.test.cpp
  - verify/library_checker/math/2_sat.test.cpp
  - verify/library_checker/tree/cartesian_tree.test.cpp
  - verify/library_checker/tree/tree_diameter.test.cpp
  - verify/library_checker/tree/lowest_common_ancestor.test.cpp
  - verify/library_checker/tree/frequency_table_of_tree_distance.test.cpp
  - verify/library_checker/graph/cycle_detection_directed.test.cpp
  - verify/library_checker/graph/two_edge_connected_components.test.cpp
  - verify/library_checker/graph/shortest_path.test.cpp
  - verify/library_checker/graph/biconnected_components.test.cpp
  - verify/library_checker/graph/strongly_connected_components.test.cpp
  - verify/library_checker/graph/minimum_spanning_tree.test.cpp
  - verify/library_checker/graph/cycle_detection_undirected.test.cpp
documentation_of: src/graph/graph_template.hpp
layout: document
title: Graph
---
