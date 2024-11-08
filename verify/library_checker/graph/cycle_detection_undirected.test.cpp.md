---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/cycle_detection.hpp
    title: cycle_detection
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
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection_undirected
    links:
    - https://judge.yosupo.jp/problem/cycle_detection_undirected
  bundledCode: "#line 1 \"verify/library_checker/graph/cycle_detection_undirected.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection_undirected\"\
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
    #line 4 \"src/graph/cycle_detection.hpp\"\ntemplate <typename T>\nEdges<T> cycle_detection(const\
    \ Graph<T>& g, const bool directed = true) {\n    const int n = g.size();\n  \
    \  for(int i = 0; i < n; ++i) {\n        for(const Edge<T>& e : g[i]) {\n    \
    \        if(i == e.to) return {e};\n        }\n    }\n    Edges<T> cycle;\n  \
    \  vector<int> pre(n, -1), visited(n, 0);\n    int finish = 0;\n    auto dfs =\
    \ [&](const auto& dfs, const int cur, const int pval, const Edge<T>& par) -> int\
    \ {\n        pre[cur] = pval;\n        visited[cur] = 1;\n        for(const Edge<T>&\
    \ e : g[cur]) {\n            if(finish) return -1;\n            if(!directed and\
    \ e.idx == par.idx) continue;\n            if(pre[e.to] == pre[cur]) {\n     \
    \           cycle.emplace_back(e);\n                return e.to;\n           \
    \ }\n            if(visited[e.to]) continue;\n            const int nx = dfs(dfs,\
    \ e.to, pval, e);\n            if(nx != -1) {\n                cycle.emplace_back(e);\n\
    \                if(cur == nx) {\n                    finish = 1;\n          \
    \          return -1;\n                }\n                return nx;\n       \
    \     }\n        }\n        pre[cur] = -1;\n        return -1;\n    };\n    for(int\
    \ i = 0; i < n; ++i) {\n        if(visited[i]) continue;\n        dfs(dfs, i,\
    \ i, Edge<T>());\n        if(finish) {\n            reverse(begin(cycle), end(cycle));\n\
    \            return cycle;\n        }\n    }\n    return {};\n}\n#line 5 \"verify/library_checker/graph/cycle_detection_undirected.test.cpp\"\
    \nint main(void) {\n    int n, m;\n    cin >> n >> m;\n    Graph<int> g(n);\n\
    \    rep(i, 0, m) {\n        int a, b;\n        cin >> a >> b;\n        g.add_edge(a,\
    \ b);\n    }\n    Edges<int> cycle = cycle_detection(g, false);\n    if(cycle.empty())\
    \ {\n        cout << -1 << '\\n';\n        return 0;\n    }\n    cout << cycle.size()\
    \ << '\\n';\n    for(const Edge<int>& e : cycle) {\n        cout << e.from <<\
    \ ' ';\n    }\n    cout << '\\n';\n    for(const Edge<int>& e : cycle) {\n   \
    \     cout << e.idx << ' ';\n    }\n    cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection_undirected\"\
    \n#include \"src/template/template.hpp\"\n#include \"src/graph/graph_template.hpp\"\
    \n#include \"src/graph/cycle_detection.hpp\"\nint main(void) {\n    int n, m;\n\
    \    cin >> n >> m;\n    Graph<int> g(n);\n    rep(i, 0, m) {\n        int a,\
    \ b;\n        cin >> a >> b;\n        g.add_edge(a, b);\n    }\n    Edges<int>\
    \ cycle = cycle_detection(g, false);\n    if(cycle.empty()) {\n        cout <<\
    \ -1 << '\\n';\n        return 0;\n    }\n    cout << cycle.size() << '\\n';\n\
    \    for(const Edge<int>& e : cycle) {\n        cout << e.from << ' ';\n    }\n\
    \    cout << '\\n';\n    for(const Edge<int>& e : cycle) {\n        cout << e.idx\
    \ << ' ';\n    }\n    cout << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/graph/cycle_detection.hpp
  isVerificationFile: true
  path: verify/library_checker/graph/cycle_detection_undirected.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 00:36:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/cycle_detection_undirected.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/cycle_detection_undirected.test.cpp
- /verify/verify/library_checker/graph/cycle_detection_undirected.test.cpp.html
title: verify/library_checker/graph/cycle_detection_undirected.test.cpp
---
