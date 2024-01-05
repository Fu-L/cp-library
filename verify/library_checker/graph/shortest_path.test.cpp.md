---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: dijkstra
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"verify/library_checker/graph/shortest_path.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#line 2 \"\
    src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
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
    using Edges = vector<Edge<T>>;\n#line 4 \"src/graph/dijkstra.hpp\"\ntemplate <typename\
    \ T>\nvector<pair<T, int>> dijkstra(const Graph<T>& g, const int s = 0) {\n  \
    \  int n = g.size();\n    assert(0 <= s and s < n);\n    vector<pair<T, int>>\
    \ d(n, {numeric_limits<T>::max(), -1});\n    priority_queue<pair<T, int>, vector<pair<T,\
    \ int>>, greater<pair<T, int>>> pq;\n    d[s] = {0, -1};\n    pq.push({0, s});\n\
    \    while(!pq.empty()) {\n        pair<T, int> p = pq.top();\n        pq.pop();\n\
    \        T dist = p.first;\n        int cur = p.second;\n        if(d[cur].first\
    \ < dist) continue;\n        for(const Edge<T>& edge : g[cur]) {\n           \
    \ if(d[edge.to].first > d[cur].first + edge.cost) {\n                d[edge.to]\
    \ = {d[cur].first + edge.cost, cur};\n                pq.push({d[edge.to].first,\
    \ edge.to});\n            }\n        }\n    }\n    return d;\n}\n#line 5 \"verify/library_checker/graph/shortest_path.test.cpp\"\
    \nint main(void) {\n    int n, m, s, t;\n    cin >> n >> m >> s >> t;\n    Graph<ll>\
    \ g(n);\n    rep(i, 0, m) {\n        int a, b, c;\n        cin >> a >> b >> c;\n\
    \        g.add_directed_edge(a, b, c);\n    }\n    vector<pair<ll, int>> d = dijkstra(g,\
    \ s);\n    if(d[t].first == numeric_limits<ll>::max()) {\n        cout << -1 <<\
    \ '\\n';\n        return 0;\n    }\n    vector<int> path;\n    int cur = t;\n\
    \    path.push_back(cur);\n    while(d[cur].second != -1) {\n        cur = d[cur].second;\n\
    \        path.push_back(cur);\n    }\n    reverse(path.begin(), path.end());\n\
    \    cout << d[t].first << ' ' << (int)path.size() - 1 << '\\n';\n    rep(i, 0,\
    \ (int)path.size() - 1) {\n        cout << path[i] << ' ' << path[i + 1] << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/graph/dijkstra.hpp\"\nint main(void) {\n    int n, m,\
    \ s, t;\n    cin >> n >> m >> s >> t;\n    Graph<ll> g(n);\n    rep(i, 0, m) {\n\
    \        int a, b, c;\n        cin >> a >> b >> c;\n        g.add_directed_edge(a,\
    \ b, c);\n    }\n    vector<pair<ll, int>> d = dijkstra(g, s);\n    if(d[t].first\
    \ == numeric_limits<ll>::max()) {\n        cout << -1 << '\\n';\n        return\
    \ 0;\n    }\n    vector<int> path;\n    int cur = t;\n    path.push_back(cur);\n\
    \    while(d[cur].second != -1) {\n        cur = d[cur].second;\n        path.push_back(cur);\n\
    \    }\n    reverse(path.begin(), path.end());\n    cout << d[t].first << ' '\
    \ << (int)path.size() - 1 << '\\n';\n    rep(i, 0, (int)path.size() - 1) {\n \
    \       cout << path[i] << ' ' << path[i + 1] << '\\n';\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/graph/dijkstra.hpp
  isVerificationFile: true
  path: verify/library_checker/graph/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2024-01-05 04:01:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/shortest_path.test.cpp
- /verify/verify/library_checker/graph/shortest_path.test.cpp.html
title: verify/library_checker/graph/shortest_path.test.cpp
---
