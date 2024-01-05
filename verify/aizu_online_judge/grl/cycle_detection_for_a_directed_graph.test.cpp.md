---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/graph/topological_sort.hpp
    title: topological_sort
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_A
  bundledCode: "#line 1 \"verify/aizu_online_judge/grl/cycle_detection_for_a_directed_graph.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_A\"\n#line\
    \ 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i\
    \ = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/graph/graph_template.hpp\"\ntemplate <typename T = int>\nstruct\
    \ Edge {\n    int from, to;\n    T cost;\n    int idx;\n    Edge()\n        :\
    \ from(-1), to(-1), cost(-1), idx(-1) {}\n    Edge(int from, int to, T cost =\
    \ 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx) {}\n  \
    \  operator int() const {\n        return to;\n    }\n};\ntemplate <typename T\
    \ = int>\nstruct Graph {\n    vector<vector<Edge<T>>> g;\n    int es;\n    Graph(int\
    \ n)\n        : g(n), es(0) {}\n    size_t size() const {\n        return g.size();\n\
    \    }\n    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n \
    \   void add_directed_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es++);\n    }\n    inline vector<Edge<T>>& operator[](const int& k)\
    \ {\n        return g[k];\n    }\n    inline const vector<Edge<T>>& operator[](const\
    \ int& k) const {\n        return g[k];\n    }\n};\ntemplate <typename T = int>\n\
    using Edges = vector<Edge<T>>;\n#line 4 \"src/graph/topological_sort.hpp\"\ntemplate\
    \ <typename T = int>\nvector<int> topological_sort(const Graph<T>& g) {\n    const\
    \ int n = (int)g.size();\n    vector<int> deg(n);\n    for(int i = 0; i < n; ++i)\
    \ {\n        for(const auto& to : g[i]) {\n            ++deg[to];\n        }\n\
    \    }\n    stack<int> st;\n    for(int i = 0; i < n; ++i) {\n        if(deg[i]\
    \ == 0) {\n            st.push(i);\n        }\n    }\n    vector<int> res;\n \
    \   res.reserve(n);\n    while(!st.empty()) {\n        int p = st.top();\n   \
    \     st.pop();\n        res.push_back(p);\n        for(const auto& to : g[p])\
    \ {\n            if(--deg[to] == 0) {\n                st.push(to);\n        \
    \    }\n        }\n    }\n    if((int)res.size() != n) return {};\n    return\
    \ res;\n}\n#line 5 \"verify/aizu_online_judge/grl/cycle_detection_for_a_directed_graph.test.cpp\"\
    \nint main(void) {\n    int n, m;\n    cin >> n >> m;\n    Graph g(n);\n    rep(i,\
    \ 0, m) {\n        int u, v;\n        cin >> u >> v;\n        g.add_directed_edge(u,\
    \ v);\n    }\n    vector<int> topo = topological_sort(g);\n    if((int)topo.size()\
    \ == 0) {\n        cout << 1 << '\\n';\n    } else {\n        cout << 0 << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_A\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/graph/topological_sort.hpp\"\nint main(void) {\n   \
    \ int n, m;\n    cin >> n >> m;\n    Graph g(n);\n    rep(i, 0, m) {\n       \
    \ int u, v;\n        cin >> u >> v;\n        g.add_directed_edge(u, v);\n    }\n\
    \    vector<int> topo = topological_sort(g);\n    if((int)topo.size() == 0) {\n\
    \        cout << 1 << '\\n';\n    } else {\n        cout << 0 << '\\n';\n    }\n\
    }"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/graph/topological_sort.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/grl/cycle_detection_for_a_directed_graph.test.cpp
  requiredBy: []
  timestamp: '2024-01-05 00:27:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/grl/cycle_detection_for_a_directed_graph.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/grl/cycle_detection_for_a_directed_graph.test.cpp
- /verify/verify/aizu_online_judge/grl/cycle_detection_for_a_directed_graph.test.cpp.html
title: verify/aizu_online_judge/grl/cycle_detection_for_a_directed_graph.test.cpp
---