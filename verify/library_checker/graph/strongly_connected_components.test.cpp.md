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
    path: src/graph/strongly_connected_components.hpp
    title: strongly_connected_components
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"verify/library_checker/graph/strongly_connected_components.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i,\
    \ a, b) for(ll i = a; i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n\
    \    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n    \
    \    cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/graph/graph_template.hpp\"\
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
    \ = e.to;\n            }\n        }\n    }\n};\n#line 5 \"src/graph/strongly_connected_components.hpp\"\
    \ntemplate <typename T>\npair<int, vector<int>> scc_ids(const Graph<T>& g) {\n\
    \    const int n = g.size();\n    const CompressedSparseRow<T> g_csr(g);\n   \
    \ int now_ord = 0, group_num = 0;\n    vector<int> visited, low(n), ord(n, -1),\
    \ ids(n);\n    visited.reserve(n);\n    auto dfs = [&](const auto& dfs, const\
    \ int v) -> void {\n        low[v] = ord[v] = now_ord++;\n        visited.emplace_back(v);\n\
    \        for(int i = g_csr.start[v]; i < g_csr.start[v + 1]; ++i) {\n        \
    \    const int to = g_csr.elist[i];\n            if(ord[to] == -1) {\n       \
    \         dfs(dfs, to);\n                low[v] = min(low[v], low[to]);\n    \
    \        } else {\n                low[v] = min(low[v], ord[to]);\n          \
    \  }\n        }\n        if(low[v] == ord[v]) {\n            while(true) {\n \
    \               const int u = visited.back();\n                visited.pop_back();\n\
    \                ord[u] = n;\n                ids[u] = group_num;\n          \
    \      if(u == v) break;\n            }\n            ++group_num;\n        }\n\
    \    };\n    for(int i = 0; i < n; ++i) {\n        if(ord[i] == -1) {\n      \
    \      dfs(dfs, i);\n        }\n    }\n    for(auto& x : ids) x = group_num -\
    \ 1 - x;\n    return {group_num, ids};\n}\ntemplate <typename T>\nvector<vector<int>>\
    \ strongly_connected_components(const Graph<T>& g) {\n    const auto [group_num,\
    \ ids] = scc_ids(g);\n    const int n = g.size();\n    vector<int> counts(group_num);\n\
    \    for(const int x : ids) ++counts[x];\n    vector<vector<int>> groups(group_num);\n\
    \    for(int i = 0; i < group_num; ++i) groups[i].reserve(counts[i]);\n    for(int\
    \ i = 0; i < n; ++i) groups[ids[i]].emplace_back(i);\n    return groups;\n}\n\
    #line 5 \"verify/library_checker/graph/strongly_connected_components.test.cpp\"\
    \nint main(void) {\n    int n, m;\n    cin >> n >> m;\n    Graph<int> g(n);\n\
    \    rep(i, 0, m) {\n        int a, b;\n        cin >> a >> b;\n        g.add_directed_edge(a,\
    \ b);\n    }\n    vector<vector<int>> scc = strongly_connected_components(g);\n\
    \    int k = scc.size();\n    cout << k << '\\n';\n    rep(i, 0, k) {\n      \
    \  int l = scc[i].size();\n        cout << l << ' ';\n        rep(j, 0, l) {\n\
    \            cout << scc[i][j] << \" \\n\"[j + 1 == l];\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/graph/graph_template.hpp\"\n#include \"../../../src/graph/strongly_connected_components.hpp\"\
    \nint main(void) {\n    int n, m;\n    cin >> n >> m;\n    Graph<int> g(n);\n\
    \    rep(i, 0, m) {\n        int a, b;\n        cin >> a >> b;\n        g.add_directed_edge(a,\
    \ b);\n    }\n    vector<vector<int>> scc = strongly_connected_components(g);\n\
    \    int k = scc.size();\n    cout << k << '\\n';\n    rep(i, 0, k) {\n      \
    \  int l = scc[i].size();\n        cout << l << ' ';\n        rep(j, 0, l) {\n\
    \            cout << scc[i][j] << \" \\n\"[j + 1 == l];\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/graph/strongly_connected_components.hpp
  - src/graph/compressed_sparse_row.hpp
  isVerificationFile: true
  path: verify/library_checker/graph/strongly_connected_components.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 00:36:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/strongly_connected_components.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/strongly_connected_components.test.cpp
- /verify/verify/library_checker/graph/strongly_connected_components.test.cpp.html
title: verify/library_checker/graph/strongly_connected_components.test.cpp
---
