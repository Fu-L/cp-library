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
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/matching_on_general_graph.test.cpp
    title: verify/library_checker/graph/matching_on_general_graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/max_matching.hpp\"\n#include <boost/graph/adjacency_list.hpp>\n\
    #include <boost/graph/graph_traits.hpp>\n#include <boost/graph/max_cardinality_matching.hpp>\n\
    #line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
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
    \ Edges = vector<Edge<T>>;\n#line 7 \"src/graph/max_matching.hpp\"\ntemplate <typename\
    \ T>\nEdges<T> max_matching(const int n, const Edges<T>& es) {\n    using namespace\
    \ boost;\n    using G = adjacency_list<vecS, vecS, undirectedS>;\n    using V\
    \ = graph_traits<G>::vertex_descriptor;\n    G g(n);\n    for(const Edge<T>& e\
    \ : es) {\n        assert(e.cost == 1);\n        add_edge(e.from, e.to, g);\n\
    \    }\n    vector<V> mate(n);\n    edmonds_maximum_cardinality_matching(g, &mate[0]);\n\
    \    Edges<T> res;\n    for(V v = 0; v < num_vertices(g); ++v) {\n        if(mate[v]\
    \ != graph_traits<G>::null_vertex() and v < mate[v]) {\n            res.push_back({(int)v,\
    \ (int)mate[v], 1});\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include <boost/graph/adjacency_list.hpp>\n#include <boost/graph/graph_traits.hpp>\n\
    #include <boost/graph/max_cardinality_matching.hpp>\n#include \"../template/template.hpp\"\
    \n#include \"../graph/graph_template.hpp\"\ntemplate <typename T>\nEdges<T> max_matching(const\
    \ int n, const Edges<T>& es) {\n    using namespace boost;\n    using G = adjacency_list<vecS,\
    \ vecS, undirectedS>;\n    using V = graph_traits<G>::vertex_descriptor;\n   \
    \ G g(n);\n    for(const Edge<T>& e : es) {\n        assert(e.cost == 1);\n  \
    \      add_edge(e.from, e.to, g);\n    }\n    vector<V> mate(n);\n    edmonds_maximum_cardinality_matching(g,\
    \ &mate[0]);\n    Edges<T> res;\n    for(V v = 0; v < num_vertices(g); ++v) {\n\
    \        if(mate[v] != graph_traits<G>::null_vertex() and v < mate[v]) {\n   \
    \         res.push_back({(int)v, (int)mate[v], 1});\n        }\n    }\n    return\
    \ res;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/max_matching.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/graph/matching_on_general_graph.test.cpp
documentation_of: src/graph/max_matching.hpp
layout: document
title: max_matching
---

## max_matching

```cpp
Edges<T> max_matching(int n, Edges<T> es)
```

$n$ 頂点無向グラフの辺集合 `es` からグラフの最大マッチングを計算します．<br>
返り値は採用された辺集合です．

注: `#include "graph/max_matching.hpp"` を `#include "template/template.hpp"` の上に書かないとCompile Errorが起こります．

**制約**

- 辺の重みが $1$ である．

**計算量**

頂点数，辺数をそれぞれ $V, E$ として，

- $O(VE \alpha(E, V))$