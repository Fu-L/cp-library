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
    path: src/graph/two_sat.hpp
    title: TwoSAT
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
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"verify/library_checker/other/2_sat.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/two_sat\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i,\
    \ a, b) for(ll i = a; i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n\
    \    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n    \
    \    cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/graph/graph_template.hpp\"\
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
    \ g;\n};\ntemplate <typename T>\nusing Edges = vector<Edge<T>>;\n#line 4 \"src/graph/compressed_sparse_row.hpp\"\
    \ntemplate <typename T>\nstruct CompressedSparseRow {\n    vector<int> start,\
    \ elist;\n    CompressedSparseRow(const Graph<T>& g)\n        : start(g.size()\
    \ + 1), elist(g.edge_size()) {\n        const int n = g.size();\n        for(int\
    \ i = 0; i < n; ++i) {\n            start[i + 1] = start[i] + g[i].size();\n \
    \           int counter = start[i];\n            for(const Edge<T>& e : g[i])\
    \ {\n                elist[counter++] = e.to;\n            }\n        }\n    }\n\
    };\n#line 5 \"src/graph/strongly_connected_components.hpp\"\ntemplate <typename\
    \ T>\npair<int, vector<int>> scc_ids(const Graph<T>& g) {\n    const int n = g.size();\n\
    \    CompressedSparseRow<T> g_csr(g);\n    int now_ord = 0, group_num = 0;\n \
    \   vector<int> visited, low(n), ord(n, -1), ids(n);\n    visited.reserve(n);\n\
    \    auto dfs = [&](auto& dfs, int v) -> void {\n        low[v] = ord[v] = now_ord++;\n\
    \        visited.emplace_back(v);\n        for(int i = g_csr.start[v]; i < g_csr.start[v\
    \ + 1]; ++i) {\n            const int to = g_csr.elist[i];\n            if(ord[to]\
    \ == -1) {\n                dfs(dfs, to);\n                low[v] = min(low[v],\
    \ low[to]);\n            } else {\n                low[v] = min(low[v], ord[to]);\n\
    \            }\n        }\n        if(low[v] == ord[v]) {\n            while(true)\
    \ {\n                const int u = visited.back();\n                visited.pop_back();\n\
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
    #line 5 \"src/graph/two_sat.hpp\"\nstruct TwoSAT {\n    TwoSAT(int N)\n      \
    \  : n(N), ans(N), graph(2 * N) {}\n    void add_clause(int i, bool f, int j,\
    \ bool g) {\n        graph.add_directed_edge(2 * i + (f ? 0 : 1), 2 * j + (g ?\
    \ 1 : 0));\n        graph.add_directed_edge(2 * j + (g ? 0 : 1), 2 * i + (f ?\
    \ 1 : 0));\n    }\n    bool satisfiable() {\n        const vector<int> id = scc_ids(graph).second;\n\
    \        for(int i = 0; i < n; ++i) {\n            if(id[2 * i] == id[2 * i +\
    \ 1]) return false;\n            ans[i] = id[2 * i] < id[2 * i + 1];\n       \
    \ }\n        return true;\n    }\n    vector<bool> answer() const {\n        return\
    \ ans;\n    }\n\n   private:\n    int n;\n    vector<bool> ans;\n    Graph<int>\
    \ graph;\n};\n#line 4 \"verify/library_checker/other/2_sat.test.cpp\"\nint main(void)\
    \ {\n    string p, cnf;\n    int n, m;\n    cin >> p >> cnf >> n >> m;\n    TwoSAT\
    \ ts(n);\n    rep(i, 0, m) {\n        int a, b, z;\n        cin >> a >> b >> z;\n\
    \        bool f = a > 0, g = b > 0;\n        a = abs(a) - 1;\n        b = abs(b)\
    \ - 1;\n        ts.add_clause(a, f, b, g);\n    }\n    if(ts.satisfiable()) {\n\
    \        cout << \"s SATISFIABLE\" << '\\n';\n        vector<bool> ans = ts.answer();\n\
    \        cout << \"v \";\n        rep(i, 0, n) {\n            if(!ans[i]) cout\
    \ << '-';\n            cout << i + 1 << ' ';\n        }\n        cout << 0 <<\
    \ '\\n';\n    } else {\n        cout << \"s UNSATISFIABLE\" << '\\n';\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include \"\
    ../../../src/template/template.hpp\"\n#include \"../../../src/graph/two_sat.hpp\"\
    \nint main(void) {\n    string p, cnf;\n    int n, m;\n    cin >> p >> cnf >>\
    \ n >> m;\n    TwoSAT ts(n);\n    rep(i, 0, m) {\n        int a, b, z;\n     \
    \   cin >> a >> b >> z;\n        bool f = a > 0, g = b > 0;\n        a = abs(a)\
    \ - 1;\n        b = abs(b) - 1;\n        ts.add_clause(a, f, b, g);\n    }\n \
    \   if(ts.satisfiable()) {\n        cout << \"s SATISFIABLE\" << '\\n';\n    \
    \    vector<bool> ans = ts.answer();\n        cout << \"v \";\n        rep(i,\
    \ 0, n) {\n            if(!ans[i]) cout << '-';\n            cout << i + 1 <<\
    \ ' ';\n        }\n        cout << 0 << '\\n';\n    } else {\n        cout <<\
    \ \"s UNSATISFIABLE\" << '\\n';\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/two_sat.hpp
  - src/graph/graph_template.hpp
  - src/graph/strongly_connected_components.hpp
  - src/graph/compressed_sparse_row.hpp
  isVerificationFile: true
  path: verify/library_checker/other/2_sat.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 17:49:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/other/2_sat.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/other/2_sat.test.cpp
- /verify/verify/library_checker/other/2_sat.test.cpp.html
title: verify/library_checker/other/2_sat.test.cpp
---
