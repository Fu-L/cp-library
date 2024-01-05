---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  - icon: ':heavy_check_mark:'
    path: src/tree/tree_diameter.hpp
    title: tree_diameter
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    #line 4 \"src/tree/tree_diameter.hpp\"\ntemplate <typename T = int>\npair<T, vector<int>>\
    \ tree_diameter(const Graph<T>& g) {\n    int n = (int)g.size();\n    vector<T>\
    \ depth(n);\n    vector<int> par(n);\n    auto dfs = [&](auto& dfs, int v, int\
    \ p, T d) -> void {\n        depth[v] = d;\n        par[v] = p;\n        for(auto&\
    \ e : g[v]) {\n            if(e.to == p) continue;\n            dfs(dfs, e.to,\
    \ v, d + e.cost);\n        }\n    };\n    int s = 0;\n    for(int i = 0; i < 2;\
    \ ++i) {\n        dfs(dfs, s, -1, 0);\n        T ma = -1;\n        for(int j =\
    \ 0; j < n; ++j) {\n            if(depth[j] > ma) {\n                ma = depth[j];\n\
    \                s = j;\n            }\n        }\n    }\n    vector<int> path;\n\
    \    T diameter = depth[s];\n    while(s != -1) {\n        path.push_back(s);\n\
    \        s = par[s];\n    }\n    return {diameter, path};\n}\n#line 5 \"verify/library_checker/tree/tree_diameter.test.cpp\"\
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
  timestamp: '2024-01-05 00:27:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/tree_diameter.test.cpp
- /verify/verify/library_checker/tree/tree_diameter.test.cpp.html
title: verify/library_checker/tree/tree_diameter.test.cpp
---