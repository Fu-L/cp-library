---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/graph/low_link.hpp
    title: LowLink
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A
  bundledCode: "#line 1 \"verify/aizu_online_judge/grl/articulation_points.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A\"\n#line\
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
    using Edges = vector<Edge<T>>;\n#line 4 \"src/graph/low_link.hpp\"\ntemplate <typename\
    \ T>\nstruct LowLink {\n    vector<int> ord, low, articulation;\n    vector<pair<int,\
    \ int>> bridge;\n    LowLink(const Graph<T>& g)\n        : ord(g.size(), -1),\
    \ low(g.size(), -1) {\n        for(int i = 0, k = 0; i < (int)g.size(); ++i) {\n\
    \            if(ord[i] == -1) k = dfs(g, i, k, -1);\n        }\n    }\n\n   private:\n\
    \    int dfs(const Graph<T>& g, int idx, int k, int par) {\n        low[idx] =\
    \ (ord[idx] = k++);\n        int cnt = 0;\n        bool arti = false, second =\
    \ false;\n        for(const int to : g[idx]) {\n            if(ord[to] == -1)\
    \ {\n                ++cnt;\n                k = dfs(g, to, k, idx);\n       \
    \         low[idx] = min(low[idx], low[to]);\n                arti |= (par !=\
    \ -1) and (low[to] >= ord[idx]);\n                if(ord[idx] < low[to]) {\n \
    \                   bridge.emplace_back(minmax(idx, to));\n                }\n\
    \            } else if(to != par or second) {\n                low[idx] = min(low[idx],\
    \ ord[to]);\n            } else {\n                second = true;\n          \
    \  }\n        }\n        arti |= (par == -1) and (cnt > 1);\n        if(arti)\
    \ articulation.push_back(idx);\n        return k;\n    }\n};\n#line 5 \"verify/aizu_online_judge/grl/articulation_points.test.cpp\"\
    \nint main(void) {\n    int n, m;\n    cin >> n >> m;\n    Graph<int> g(n);\n\
    \    rep(i, 0, m) {\n        int a, b;\n        cin >> a >> b;\n        g.add_edge(a,\
    \ b);\n    }\n    LowLink<int> low(g);\n    sort(low.articulation.begin(), low.articulation.end());\n\
    \    for(const int arti : low.articulation) {\n        cout << arti << '\\n';\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/graph/low_link.hpp\"\nint main(void) {\n    int n, m;\n\
    \    cin >> n >> m;\n    Graph<int> g(n);\n    rep(i, 0, m) {\n        int a,\
    \ b;\n        cin >> a >> b;\n        g.add_edge(a, b);\n    }\n    LowLink<int>\
    \ low(g);\n    sort(low.articulation.begin(), low.articulation.end());\n    for(const\
    \ int arti : low.articulation) {\n        cout << arti << '\\n';\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/graph/low_link.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/grl/articulation_points.test.cpp
  requiredBy: []
  timestamp: '2024-01-05 02:58:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/grl/articulation_points.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/grl/articulation_points.test.cpp
- /verify/verify/aizu_online_judge/grl/articulation_points.test.cpp.html
title: verify/aizu_online_judge/grl/articulation_points.test.cpp
---
