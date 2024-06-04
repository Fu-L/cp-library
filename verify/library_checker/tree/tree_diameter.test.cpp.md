---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  - icon: ':question:'
    path: src/tree/tree_diameter.hpp
    title: tree_diameter
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"verify/library_checker/tree/tree_diameter.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#line 2 \"src/template/template.hpp\"\
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
    \ g;\n};\ntemplate <typename T>\nusing Edges = vector<Edge<T>>;\n#line 4 \"src/tree/tree_diameter.hpp\"\
    \ntemplate <typename T>\npair<T, vector<int>> tree_diameter(const Graph<T>& g)\
    \ {\n    const int n = g.size();\n    vector<T> depth(n);\n    vector<int> par(n);\n\
    \    auto dfs = [&](auto& dfs, int v, int p, const T& d) -> void {\n        depth[v]\
    \ = d;\n        par[v] = p;\n        for(const Edge<T>& e : g[v]) {\n        \
    \    if(e.to == p) continue;\n            dfs(dfs, e.to, v, d + e.cost);\n   \
    \     }\n    };\n    int s = 0;\n    for(int i = 0; i < 2; ++i) {\n        dfs(dfs,\
    \ s, -1, 0);\n        T ma = -1;\n        for(int j = 0; j < n; ++j) {\n     \
    \       if(depth[j] > ma) {\n                ma = depth[j];\n                s\
    \ = j;\n            }\n        }\n    }\n    vector<int> path;\n    const T diameter\
    \ = depth[s];\n    while(s != -1) {\n        path.emplace_back(s);\n        s\
    \ = par[s];\n    }\n    return {diameter, path};\n}\n#line 5 \"verify/library_checker/tree/tree_diameter.test.cpp\"\
    \nint main(void) {\n    int n;\n    cin >> n;\n    Graph<ll> g(n);\n    rep(i,\
    \ 0, n - 1) {\n        int a, b, c;\n        cin >> a >> b >> c;\n        g.add_edge(a,\
    \ b, c);\n    }\n    auto [d, path] = tree_diameter(g);\n    cout << d << ' '\
    \ << path.size() << '\\n';\n    for(const auto& p : path) {\n        cout << p\
    \ << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/tree/tree_diameter.hpp\"\nint main(void) {\n    int\
    \ n;\n    cin >> n;\n    Graph<ll> g(n);\n    rep(i, 0, n - 1) {\n        int\
    \ a, b, c;\n        cin >> a >> b >> c;\n        g.add_edge(a, b, c);\n    }\n\
    \    auto [d, path] = tree_diameter(g);\n    cout << d << ' ' << path.size() <<\
    \ '\\n';\n    for(const auto& p : path) {\n        cout << p << '\\n';\n    }\n\
    }"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/tree/tree_diameter.hpp
  isVerificationFile: true
  path: verify/library_checker/tree/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/tree/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/tree_diameter.test.cpp
- /verify/verify/library_checker/tree/tree_diameter.test.cpp.html
title: verify/library_checker/tree/tree_diameter.test.cpp
---
