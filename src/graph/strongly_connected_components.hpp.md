---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/compressed_sparse_row.hpp
    title: CompressedSparseRow
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
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
    path: verify/library_checker/math/2_sat.test.cpp
    title: verify/library_checker/math/2_sat.test.cpp
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
    #line 4 \"src/graph/compressed_sparse_row.hpp\"\ntemplate <typename T>\nstruct\
    \ CompressedSparseRow {\n    vector<int> start, elist;\n    CompressedSparseRow(const\
    \ Graph<T>& g)\n        : start(g.size() + 1), elist(g.es) {\n        int n =\
    \ (int)g.size();\n        for(int i = 0; i < n; ++i) {\n            start[i +\
    \ 1] = start[i] + g[i].size();\n            int counter = start[i];\n        \
    \    for(const auto& to : g[i]) {\n                elist[counter++] = to;\n  \
    \          }\n        }\n    }\n};\n#line 5 \"src/graph/strongly_connected_components.hpp\"\
    \ntemplate <typename T>\npair<int, vector<int>> scc_ids(const Graph<T>& g) {\n\
    \    int n = (int)g.size();\n    CompressedSparseRow<T> g_csr(g);\n    int now_ord\
    \ = 0, group_num = 0;\n    vector<int> visited, low(n), ord(n, -1), ids(n);\n\
    \    visited.reserve(n);\n    auto dfs = [&](auto& dfs, int v) -> void {\n   \
    \     low[v] = ord[v] = now_ord++;\n        visited.push_back(v);\n        for(int\
    \ i = g_csr.start[v]; i < g_csr.start[v + 1]; ++i) {\n            int to = g_csr.elist[i];\n\
    \            if(ord[to] == -1) {\n                dfs(dfs, to);\n            \
    \    low[v] = min(low[v], low[to]);\n            } else {\n                low[v]\
    \ = min(low[v], ord[to]);\n            }\n        }\n        if(low[v] == ord[v])\
    \ {\n            while(true) {\n                int u = visited.back();\n    \
    \            visited.pop_back();\n                ord[u] = n;\n              \
    \  ids[u] = group_num;\n                if(u == v) break;\n            }\n   \
    \         ++group_num;\n        }\n    };\n    for(int i = 0; i < n; ++i) {\n\
    \        if(ord[i] == -1) {\n            dfs(dfs, i);\n        }\n    }\n    for(auto&\
    \ x : ids) x = group_num - 1 - x;\n    return {group_num, ids};\n}\ntemplate <typename\
    \ T>\nvector<vector<int>> strongly_connected_components(const Graph<T>& g) {\n\
    \    auto [group_num, ids] = scc_ids(g);\n    int n = (int)g.size();\n    vector<int>\
    \ counts(group_num);\n    for(const auto& x : ids) ++counts[x];\n    vector<vector<int>>\
    \ groups(group_num);\n    for(int i = 0; i < group_num; ++i) groups[i].reserve(counts[i]);\n\
    \    for(int i = 0; i < n; ++i) groups[ids[i]].push_back(i);\n    return groups;\n\
    }\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./graph_template.hpp\"\
    \n#include \"./compressed_sparse_row.hpp\"\ntemplate <typename T>\npair<int, vector<int>>\
    \ scc_ids(const Graph<T>& g) {\n    int n = (int)g.size();\n    CompressedSparseRow<T>\
    \ g_csr(g);\n    int now_ord = 0, group_num = 0;\n    vector<int> visited, low(n),\
    \ ord(n, -1), ids(n);\n    visited.reserve(n);\n    auto dfs = [&](auto& dfs,\
    \ int v) -> void {\n        low[v] = ord[v] = now_ord++;\n        visited.push_back(v);\n\
    \        for(int i = g_csr.start[v]; i < g_csr.start[v + 1]; ++i) {\n        \
    \    int to = g_csr.elist[i];\n            if(ord[to] == -1) {\n             \
    \   dfs(dfs, to);\n                low[v] = min(low[v], low[to]);\n          \
    \  } else {\n                low[v] = min(low[v], ord[to]);\n            }\n \
    \       }\n        if(low[v] == ord[v]) {\n            while(true) {\n       \
    \         int u = visited.back();\n                visited.pop_back();\n     \
    \           ord[u] = n;\n                ids[u] = group_num;\n               \
    \ if(u == v) break;\n            }\n            ++group_num;\n        }\n    };\n\
    \    for(int i = 0; i < n; ++i) {\n        if(ord[i] == -1) {\n            dfs(dfs,\
    \ i);\n        }\n    }\n    for(auto& x : ids) x = group_num - 1 - x;\n    return\
    \ {group_num, ids};\n}\ntemplate <typename T>\nvector<vector<int>> strongly_connected_components(const\
    \ Graph<T>& g) {\n    auto [group_num, ids] = scc_ids(g);\n    int n = (int)g.size();\n\
    \    vector<int> counts(group_num);\n    for(const auto& x : ids) ++counts[x];\n\
    \    vector<vector<int>> groups(group_num);\n    for(int i = 0; i < group_num;\
    \ ++i) groups[i].reserve(counts[i]);\n    for(int i = 0; i < n; ++i) groups[ids[i]].push_back(i);\n\
    \    return groups;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/graph/compressed_sparse_row.hpp
  isVerificationFile: false
  path: src/graph/strongly_connected_components.hpp
  requiredBy:
  - src/graph/two_sat.hpp
  timestamp: '2024-01-05 00:27:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/grl/strongly_connected_components.test.cpp
  - verify/library_checker/math/2_sat.test.cpp
  - verify/library_checker/graph/strongly_connected_components.test.cpp
documentation_of: src/graph/strongly_connected_components.hpp
layout: document
title: strongly_connected_components
---