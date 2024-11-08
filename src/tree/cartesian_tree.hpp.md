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
    \ Edges = vector<Edge<T>>;\n#line 4 \"src/tree/cartesian_tree.hpp\"\ntemplate\
    \ <typename T>\npair<Graph<int>, int> cartesian_tree(const vector<T>& a) {\n \
    \   const int n = (int)a.size();\n    Graph<int> g(n);\n    vector<int> p(n, -1),\
    \ st;\n    st.reserve(n);\n    for(int i = 0; i < n; ++i) {\n        int prv =\
    \ -1;\n        while(!st.empty() and a[i] < a[st.back()]) {\n            prv =\
    \ st.back();\n            st.pop_back();\n        }\n        if(prv != -1) p[prv]\
    \ = i;\n        if(!st.empty()) p[i] = st.back();\n        st.emplace_back(i);\n\
    \    }\n    int root = -1;\n    for(int i = 0; i < n; ++i) {\n        if(p[i]\
    \ != -1) g.add_directed_edge(p[i], i);\n        else root = i;\n    }\n    return\
    \ {g, root};\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../graph/graph_template.hpp\"\
    \ntemplate <typename T>\npair<Graph<int>, int> cartesian_tree(const vector<T>&\
    \ a) {\n    const int n = (int)a.size();\n    Graph<int> g(n);\n    vector<int>\
    \ p(n, -1), st;\n    st.reserve(n);\n    for(int i = 0; i < n; ++i) {\n      \
    \  int prv = -1;\n        while(!st.empty() and a[i] < a[st.back()]) {\n     \
    \       prv = st.back();\n            st.pop_back();\n        }\n        if(prv\
    \ != -1) p[prv] = i;\n        if(!st.empty()) p[i] = st.back();\n        st.emplace_back(i);\n\
    \    }\n    int root = -1;\n    for(int i = 0; i < n; ++i) {\n        if(p[i]\
    \ != -1) g.add_directed_edge(p[i], i);\n        else root = i;\n    }\n    return\
    \ {g, root};\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/tree/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2024-11-09 00:36:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/tree/cartesian_tree.test.cpp
documentation_of: src/tree/cartesian_tree.hpp
layout: document
title: cartesian_tree
---

## cartesian_tree

```cpp
pair<Graph<int>, int> cartesian_tree(vector<T> a)
```

数列 `a` から導かれるCartesian Treeとその根のインデックスを返します．

Cartesian Treeとは，長さ $n$ の数列 `a` の区間 $[0, n)$ に対して次の操作を再帰的に繰り返すことにより得られる二分木のことです．

- 区間 $[l, r)$ について， $i \in [l, r)$ のうち $a_i$ が最小であるような $i$ (のうちの最小値) を $m$ とおく．
- 頂点 $m$ を根，区間 $[l, m)$ から得られる二分木を左の子，区間 $[m + 1, r)$ から得られる二分木を右の子とした木を返す．

Cartesian Treeの $2$ つの頂点 $(u, v)$ の LCA は 区間 $[u, v]$ の最小値に対応します．

**計算量**

- $O(n)$