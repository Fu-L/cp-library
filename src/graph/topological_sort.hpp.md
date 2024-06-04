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
    path: verify/aizu_online_judge/grl/cycle_detection_for_a_directed_graph.test.cpp
    title: verify/aizu_online_judge/grl/cycle_detection_for_a_directed_graph.test.cpp
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
    \ g;\n};\ntemplate <typename T>\nusing Edges = vector<Edge<T>>;\n#line 4 \"src/graph/topological_sort.hpp\"\
    \ntemplate <typename T>\nvector<int> topological_sort(const Graph<T>& g) {\n \
    \   const int n = g.size();\n    vector<int> deg(n);\n    for(int i = 0; i < n;\
    \ ++i) {\n        for(const auto& to : g[i]) {\n            ++deg[to];\n     \
    \   }\n    }\n    stack<int> st;\n    for(int i = 0; i < n; ++i) {\n        if(deg[i]\
    \ == 0) {\n            st.emplace(i);\n        }\n    }\n    vector<int> res;\n\
    \    res.reserve(n);\n    while(!st.empty()) {\n        const int p = st.top();\n\
    \        st.pop();\n        res.emplace_back(p);\n        for(const Edge<T>& e\
    \ : g[p]) {\n            if(--deg[e.to] == 0) {\n                st.emplace(e.to);\n\
    \            }\n        }\n    }\n    if((int)res.size() != n) return {};\n  \
    \  return res;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./graph_template.hpp\"\
    \ntemplate <typename T>\nvector<int> topological_sort(const Graph<T>& g) {\n \
    \   const int n = g.size();\n    vector<int> deg(n);\n    for(int i = 0; i < n;\
    \ ++i) {\n        for(const auto& to : g[i]) {\n            ++deg[to];\n     \
    \   }\n    }\n    stack<int> st;\n    for(int i = 0; i < n; ++i) {\n        if(deg[i]\
    \ == 0) {\n            st.emplace(i);\n        }\n    }\n    vector<int> res;\n\
    \    res.reserve(n);\n    while(!st.empty()) {\n        const int p = st.top();\n\
    \        st.pop();\n        res.emplace_back(p);\n        for(const Edge<T>& e\
    \ : g[p]) {\n            if(--deg[e.to] == 0) {\n                st.emplace(e.to);\n\
    \            }\n        }\n    }\n    if((int)res.size() != n) return {};\n  \
    \  return res;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/grl/cycle_detection_for_a_directed_graph.test.cpp
documentation_of: src/graph/topological_sort.hpp
layout: document
title: topological_sort
---

## topological_sort

```cpp
vector<int> topological_sort(Graph<T> g)
```

$n$ 頂点 $m$ 辺の有向グラフ `g` をトポロジカルソートしたときの頂点順序を返します．

`g` がDAGでない場合は空の配列を返します．

**計算量**

- $O(n + m)$