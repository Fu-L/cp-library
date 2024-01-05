---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/union_find.hpp
    title: UnionFind
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/minimum_spanning_tree.test.cpp
    title: verify/aizu_online_judge/grl/minimum_spanning_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/minimum_spanning_tree.test.cpp
    title: verify/library_checker/graph/minimum_spanning_tree.test.cpp
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
    #line 3 \"src/data_structure/union_find.hpp\"\nstruct UnionFind {\n    UnionFind(int\
    \ N)\n        : n(N), data(N, -1) {}\n    int merge(int a, int b) {\n        assert(0\
    \ <= a and a < n);\n        assert(0 <= b and b < n);\n        int x = leader(a),\
    \ y = leader(b);\n        if(x == y) return x;\n        if(-data[x] < -data[y])\
    \ swap(x, y);\n        data[x] += data[y];\n        data[y] = x;\n        return\
    \ x;\n    }\n    bool same(int a, int b) {\n        assert(0 <= a and a < n);\n\
    \        assert(0 <= b and b < n);\n        return leader(a) == leader(b);\n \
    \   }\n    int leader(int a) {\n        assert(0 <= a and a < n);\n        if(data[a]\
    \ < 0) return a;\n        return data[a] = leader(data[a]);\n    }\n    int size(int\
    \ a) {\n        assert(0 <= a and a < n);\n        return -data[leader(a)];\n\
    \    }\n    vector<vector<int>> groups() {\n        vector<int> leader_buf(n),\
    \ group_size(n);\n        for(int i = 0; i < n; ++i) {\n            leader_buf[i]\
    \ = leader(i);\n            ++group_size[leader_buf[i]];\n        }\n        vector<vector<int>>\
    \ result(n);\n        for(int i = 0; i < n; ++i) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for(int i = 0; i < n; ++i) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(remove_if(result.begin(), result.end(), [&](const\
    \ vector<int>& v) { return v.empty(); }), result.end());\n        return result;\n\
    \    }\n\n   private:\n    int n;\n    vector<int> data;\n};\n#line 5 \"src/graph/kruskal.hpp\"\
    \ntemplate <typename T>\npair<T, Edges<T>> kruskal(int n, Edges<T> es) {\n   \
    \ sort(es.begin(), es.end(), [&](const Edge<T>& a, const Edge<T>& b) { return\
    \ a.cost < b.cost; });\n    UnionFind uf(n);\n    T cost = 0;\n    Edges<T> res;\n\
    \    res.reserve(n - 1);\n    for(const auto& e : es) {\n        if(uf.same(e.from,\
    \ e.to)) continue;\n        cost += e.cost;\n        uf.merge(e.from, e.to);\n\
    \        res.emplace_back(e);\n    }\n    return {cost, res};\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./graph_template.hpp\"\
    \n#include \"../data_structure/union_find.hpp\"\ntemplate <typename T>\npair<T,\
    \ Edges<T>> kruskal(int n, Edges<T> es) {\n    sort(es.begin(), es.end(), [&](const\
    \ Edge<T>& a, const Edge<T>& b) { return a.cost < b.cost; });\n    UnionFind uf(n);\n\
    \    T cost = 0;\n    Edges<T> res;\n    res.reserve(n - 1);\n    for(const auto&\
    \ e : es) {\n        if(uf.same(e.from, e.to)) continue;\n        cost += e.cost;\n\
    \        uf.merge(e.from, e.to);\n        res.emplace_back(e);\n    }\n    return\
    \ {cost, res};\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/data_structure/union_find.hpp
  isVerificationFile: false
  path: src/graph/kruskal.hpp
  requiredBy: []
  timestamp: '2024-01-05 00:27:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/grl/minimum_spanning_tree.test.cpp
  - verify/library_checker/graph/minimum_spanning_tree.test.cpp
documentation_of: src/graph/kruskal.hpp
layout: document
title: kruskal
---
