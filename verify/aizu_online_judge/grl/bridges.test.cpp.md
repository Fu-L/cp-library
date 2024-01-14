---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/graph/low_link.hpp
    title: LowLink
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B
  bundledCode: "#line 1 \"verify/aizu_online_judge/grl/bridges.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i,\
    \ a, b) for(ll i = a; i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n\
    \    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n    \
    \    cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/graph/graph_template.hpp\"\
    \ntemplate <typename T = int>\nstruct Edge {\n    int from, to;\n    T cost;\n\
    \    int idx;\n    Edge()\n        : from(-1), to(-1), cost(-1), idx(-1) {}\n\
    \    Edge(int from, int to, T cost = 1, int idx = -1)\n        : from(from), to(to),\
    \ cost(cost), idx(idx) {}\n    operator int() const {\n        return to;\n  \
    \  }\n};\ntemplate <typename T = int>\nstruct Graph {\n    Graph(int N)\n    \
    \    : n(N), es(0), g(N) {}\n    int size() const {\n        return n;\n    }\n\
    \    int edge_size() const {\n        return es;\n    }\n    void add_edge(int\
    \ from, int to, T cost = 1) {\n        assert(0 <= from and from < n);\n     \
    \   assert(0 <= to and to < n);\n        g[from].emplace_back(from, to, cost,\
    \ es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n    void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n        assert(0 <= from and from < n);\n     \
    \   assert(0 <= to and to < n);\n        g[from].emplace_back(from, to, cost,\
    \ es++);\n    }\n    inline vector<Edge<T>>& operator[](const int& k) {\n    \
    \    assert(0 <= k and k < n);\n        return g[k];\n    }\n    inline const\
    \ vector<Edge<T>>& operator[](const int& k) const {\n        assert(0 <= k and\
    \ k < n);\n        return g[k];\n    }\n\n   private:\n    int n, es;\n    vector<vector<Edge<T>>>\
    \ g;\n};\ntemplate <typename T = int>\nusing Edges = vector<Edge<T>>;\n#line 4\
    \ \"src/graph/low_link.hpp\"\ntemplate <typename T>\nstruct LowLink {\n    vector<int>\
    \ ord, low, articulation;\n    vector<pair<int, int>> bridge;\n    LowLink(const\
    \ Graph<T>& g)\n        : ord(g.size(), -1), low(g.size(), -1) {\n        for(int\
    \ i = 0, k = 0; i < (int)g.size(); ++i) {\n            if(ord[i] == -1) k = dfs(g,\
    \ i, k, -1);\n        }\n    }\n\n   private:\n    int dfs(const Graph<T>& g,\
    \ int idx, int k, int par) {\n        low[idx] = (ord[idx] = k++);\n        int\
    \ cnt = 0;\n        bool arti = false, second = false;\n        for(const int\
    \ to : g[idx]) {\n            if(ord[to] == -1) {\n                ++cnt;\n  \
    \              k = dfs(g, to, k, idx);\n                low[idx] = min(low[idx],\
    \ low[to]);\n                arti |= (par != -1) and (low[to] >= ord[idx]);\n\
    \                if(ord[idx] < low[to]) {\n                    bridge.emplace_back(minmax(idx,\
    \ to));\n                }\n            } else if(to != par or second) {\n   \
    \             low[idx] = min(low[idx], ord[to]);\n            } else {\n     \
    \           second = true;\n            }\n        }\n        arti |= (par ==\
    \ -1) and (cnt > 1);\n        if(arti) articulation.push_back(idx);\n        return\
    \ k;\n    }\n};\n#line 5 \"verify/aizu_online_judge/grl/bridges.test.cpp\"\nint\
    \ main(void) {\n    int n, m;\n    cin >> n >> m;\n    Graph<int> g(n);\n    rep(i,\
    \ 0, m) {\n        int a, b;\n        cin >> a >> b;\n        g.add_edge(a, b);\n\
    \    }\n    LowLink<int> low(g);\n    sort(low.bridge.begin(), low.bridge.end());\n\
    \    for(const pair<int, int>& bri : low.bridge) {\n        cout << bri.first\
    \ << ' ' << bri.second << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/graph/low_link.hpp\"\nint main(void) {\n    int n, m;\n\
    \    cin >> n >> m;\n    Graph<int> g(n);\n    rep(i, 0, m) {\n        int a,\
    \ b;\n        cin >> a >> b;\n        g.add_edge(a, b);\n    }\n    LowLink<int>\
    \ low(g);\n    sort(low.bridge.begin(), low.bridge.end());\n    for(const pair<int,\
    \ int>& bri : low.bridge) {\n        cout << bri.first << ' ' << bri.second <<\
    \ '\\n';\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/graph/low_link.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/grl/bridges.test.cpp
  requiredBy: []
  timestamp: '2024-01-14 17:33:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/grl/bridges.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/grl/bridges.test.cpp
- /verify/verify/aizu_online_judge/grl/bridges.test.cpp.html
title: verify/aizu_online_judge/grl/bridges.test.cpp
---
