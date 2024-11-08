---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/graph/dijkstra.hpp
    title: dijkstra
  - icon: ':question:'
    path: src/graph/graph_template.hpp
    title: Graph
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"verify/aizu_online_judge/grl/single_source_shortest_path.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/graph/graph_template.hpp\"\ntemplate <typename T>\nstruct Edge {\n\
    \    int from, to;\n    T cost;\n    int idx;\n    Edge()\n        : from(-1),\
    \ to(-1), cost(-1), idx(-1) {}\n    Edge(const int from, const int to, const T&\
    \ cost = 1, const int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n    operator int() const {\n        return to;\n    }\n};\ntemplate <typename\
    \ T>\nstruct Graph {\n    Graph(const int N)\n        : n(N), es(0), g(N) {}\n\
    \    int size() const {\n        return n;\n    }\n    int edge_size() const {\n\
    \        return es;\n    }\n    void add_edge(const int from, const int to, const\
    \ T& cost = 1) {\n        assert(0 <= from and from < n);\n        assert(0 <=\
    \ to and to < n);\n        g[from].emplace_back(from, to, cost, es);\n       \
    \ g[to].emplace_back(to, from, cost, es++);\n    }\n    void add_directed_edge(const\
    \ int from, const int to, const T& cost = 1) {\n        assert(0 <= from and from\
    \ < n);\n        assert(0 <= to and to < n);\n        g[from].emplace_back(from,\
    \ to, cost, es++);\n    }\n    inline vector<Edge<T>>& operator[](const int& k)\
    \ {\n        assert(0 <= k and k < n);\n        return g[k];\n    }\n    inline\
    \ const vector<Edge<T>>& operator[](const int& k) const {\n        assert(0 <=\
    \ k and k < n);\n        return g[k];\n    }\n\n   private:\n    int n, es;\n\
    \    vector<vector<Edge<T>>> g;\n};\ntemplate <typename T>\nusing Edges = vector<Edge<T>>;\n\
    #line 4 \"src/graph/dijkstra.hpp\"\ntemplate <typename T>\nvector<pair<T, int>>\
    \ dijkstra(const Graph<T>& g, const int s = 0) {\n    const int n = g.size();\n\
    \    assert(0 <= s and s < n);\n    vector<pair<T, int>> d(n, {numeric_limits<T>::max(),\
    \ -1});\n    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,\
    \ int>>> pq;\n    d[s] = {0, -1};\n    pq.emplace(0, s);\n    while(!pq.empty())\
    \ {\n        const auto [dist, cur] = pq.top();\n        pq.pop();\n        if(d[cur].first\
    \ < dist) continue;\n        for(const Edge<T>& e : g[cur]) {\n            if(d[e.to].first\
    \ > d[cur].first + e.cost) {\n                d[e.to] = {d[cur].first + e.cost,\
    \ cur};\n                pq.emplace(d[e.to].first, e.to);\n            }\n   \
    \     }\n    }\n    return d;\n}\n#line 5 \"verify/aizu_online_judge/grl/single_source_shortest_path.test.cpp\"\
    \nint main(void) {\n    int n, m, s;\n    cin >> n >> m >> s;\n    Graph<ll> g(n);\n\
    \    rep(i, 0, m) {\n        int a, b, c;\n        cin >> a >> b >> c;\n     \
    \   g.add_directed_edge(a, b, c);\n    }\n    vector<pair<ll, int>> d = dijkstra(g,\
    \ s);\n    rep(i, 0, n) {\n        if(d[i].first == numeric_limits<ll>::max())\
    \ {\n            cout << \"INF\" << '\\n';\n        } else {\n            cout\
    \ << d[i].first << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/graph/dijkstra.hpp\"\nint main(void) {\n    int n, m,\
    \ s;\n    cin >> n >> m >> s;\n    Graph<ll> g(n);\n    rep(i, 0, m) {\n     \
    \   int a, b, c;\n        cin >> a >> b >> c;\n        g.add_directed_edge(a,\
    \ b, c);\n    }\n    vector<pair<ll, int>> d = dijkstra(g, s);\n    rep(i, 0,\
    \ n) {\n        if(d[i].first == numeric_limits<ll>::max()) {\n            cout\
    \ << \"INF\" << '\\n';\n        } else {\n            cout << d[i].first << '\\\
    n';\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/graph/dijkstra.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/grl/single_source_shortest_path.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 00:36:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/grl/single_source_shortest_path.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/grl/single_source_shortest_path.test.cpp
- /verify/verify/aizu_online_judge/grl/single_source_shortest_path.test.cpp.html
title: verify/aizu_online_judge/grl/single_source_shortest_path.test.cpp
---
