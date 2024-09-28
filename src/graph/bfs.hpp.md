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
    path: verify/unit_test/graph/bfs.test.cpp
    title: verify/unit_test/graph/bfs.test.cpp
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
    \ g;\n};\ntemplate <typename T>\nusing Edges = vector<Edge<T>>;\n#line 4 \"src/graph/bfs.hpp\"\
    \nvector<pair<int, int>> bfs(const Graph<int>& g, const int s = 0) {\n    const\
    \ int n = g.size();\n    assert(0 <= s and s < n);\n    vector<pair<int, int>>\
    \ d(n, {numeric_limits<int>::max(), -1});\n    queue<int> q;\n    d[s] = {0, -1};\n\
    \    q.emplace(s);\n    while(!q.empty()) {\n        const int cur = q.front();\n\
    \        q.pop();\n        for(const Edge<int>& e : g[cur]) {\n            if(d[e.to].first\
    \ == numeric_limits<int>::max()) {\n                d[e.to] = {d[cur].first +\
    \ 1, cur};\n                q.emplace(e.to);\n            }\n        }\n    }\n\
    \    return d;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./graph_template.hpp\"\
    \nvector<pair<int, int>> bfs(const Graph<int>& g, const int s = 0) {\n    const\
    \ int n = g.size();\n    assert(0 <= s and s < n);\n    vector<pair<int, int>>\
    \ d(n, {numeric_limits<int>::max(), -1});\n    queue<int> q;\n    d[s] = {0, -1};\n\
    \    q.emplace(s);\n    while(!q.empty()) {\n        const int cur = q.front();\n\
    \        q.pop();\n        for(const Edge<int>& e : g[cur]) {\n            if(d[e.to].first\
    \ == numeric_limits<int>::max()) {\n                d[e.to] = {d[cur].first +\
    \ 1, cur};\n                q.emplace(e.to);\n            }\n        }\n    }\n\
    \    return d;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/bfs.hpp
  requiredBy: []
  timestamp: '2024-09-28 15:28:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/graph/bfs.test.cpp
documentation_of: src/graph/bfs.hpp
layout: document
redirect_from:
- /library/src/graph/bfs.hpp
- /library/src/graph/bfs.hpp.html
title: src/graph/bfs.hpp
---
