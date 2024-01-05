---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/cartesian_tree.test.cpp
    title: verify/library_checker/tree/cartesian_tree.test.cpp
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
    #line 4 \"src/tree/cartesian_tree.hpp\"\ntemplate <typename T>\npair<Graph<int>,\
    \ int> cartesian_tree(const vector<T> &a) {\n    int n = (int)a.size();\n    Graph<int>\
    \ g(n);\n    vector<int> p(n, -1), st;\n    st.reserve(n);\n    for(int i = 0;\
    \ i < n; ++i) {\n        int prv = -1;\n        while(!st.empty() and a[i] < a[st.back()])\
    \ {\n            prv = st.back();\n            st.pop_back();\n        }\n   \
    \     if(prv != -1) p[prv] = i;\n        if(!st.empty()) p[i] = st.back();\n \
    \       st.push_back(i);\n    }\n    int root = -1;\n    for(int i = 0; i < n;\
    \ ++i) {\n        if(p[i] != -1) g.add_directed_edge(p[i], i);\n        else root\
    \ = i;\n    }\n    return {g, root};\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../graph/graph_template.hpp\"\
    \ntemplate <typename T>\npair<Graph<int>, int> cartesian_tree(const vector<T>\
    \ &a) {\n    int n = (int)a.size();\n    Graph<int> g(n);\n    vector<int> p(n,\
    \ -1), st;\n    st.reserve(n);\n    for(int i = 0; i < n; ++i) {\n        int\
    \ prv = -1;\n        while(!st.empty() and a[i] < a[st.back()]) {\n          \
    \  prv = st.back();\n            st.pop_back();\n        }\n        if(prv !=\
    \ -1) p[prv] = i;\n        if(!st.empty()) p[i] = st.back();\n        st.push_back(i);\n\
    \    }\n    int root = -1;\n    for(int i = 0; i < n; ++i) {\n        if(p[i]\
    \ != -1) g.add_directed_edge(p[i], i);\n        else root = i;\n    }\n    return\
    \ {g, root};\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/tree/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2024-01-05 00:27:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/tree/cartesian_tree.test.cpp
documentation_of: src/tree/cartesian_tree.hpp
layout: document
title: cartesian_tree
---
