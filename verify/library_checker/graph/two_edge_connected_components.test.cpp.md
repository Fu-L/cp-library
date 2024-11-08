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
    path: src/graph/two_edge_connected_components.hpp
    title: TwoEdgeConnectedComponents
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
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"verify/library_checker/graph/two_edge_connected_components.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
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
    #line 4 \"src/graph/low_link.hpp\"\ntemplate <typename T>\nstruct LowLink {\n\
    \    vector<int> ord, low, articulation;\n    vector<pair<int, int>> bridge;\n\
    \    LowLink(const Graph<T>& g)\n        : ord(g.size(), -1), low(g.size(), -1)\
    \ {\n        for(int i = 0, k = 0; i < g.size(); ++i) {\n            if(ord[i]\
    \ == -1) k = dfs(g, i, k, -1);\n        }\n    }\n\n   private:\n    int dfs(const\
    \ Graph<T>& g, const int idx, int k, const int par) {\n        low[idx] = (ord[idx]\
    \ = k++);\n        int cnt = 0;\n        bool arti = false, second = false;\n\
    \        for(const Edge<T>& e : g[idx]) {\n            const int to = e.to;\n\
    \            if(ord[to] == -1) {\n                ++cnt;\n                k =\
    \ dfs(g, to, k, idx);\n                low[idx] = min(low[idx], low[to]);\n  \
    \              arti |= (par != -1) and (low[to] >= ord[idx]);\n              \
    \  if(ord[idx] < low[to]) {\n                    bridge.emplace_back(minmax(idx,\
    \ to));\n                }\n            } else if(to != par or second) {\n   \
    \             low[idx] = min(low[idx], ord[to]);\n            } else {\n     \
    \           second = true;\n            }\n        }\n        arti |= (par ==\
    \ -1) and (cnt > 1);\n        if(arti) articulation.emplace_back(idx);\n     \
    \   return k;\n    }\n};\n#line 5 \"src/graph/two_edge_connected_components.hpp\"\
    \ntemplate <typename T>\nstruct TwoEdgeConnectedComponents {\n    vector<vector<int>>\
    \ groups, tree;\n    TwoEdgeConnectedComponents(const Graph<T>& g)\n        :\
    \ n(g.size()), k(0), low(g), comp(n, -1) {\n        for(int i = 0; i < n; ++i)\
    \ {\n            if(comp[i] == -1) dfs(g, i, -1);\n        }\n        groups.resize(k);\n\
    \        tree.resize(k);\n        for(int i = 0; i < n; ++i) {\n            groups[comp[i]].emplace_back(i);\n\
    \        }\n        for(const pair<int, int>& e : low.bridge) {\n            int\
    \ u = comp[e.first], v = comp[e.second];\n            tree[u].emplace_back(v);\n\
    \            tree[v].emplace_back(u);\n        }\n    }\n    inline int operator[](const\
    \ int& i) const {\n        assert(0 <= i and i < n);\n        return comp[i];\n\
    \    }\n\n   private:\n    int n, k;\n    LowLink<T> low;\n    vector<int> comp;\n\
    \    void dfs(const Graph<T>& g, const int i, const int p) {\n        if(p >=\
    \ 0 and low.ord[p] >= low.low[i]) comp[i] = comp[p];\n        else comp[i] = k++;\n\
    \        for(const Edge<T>& e : g[i]) {\n            if(comp[e.to] == -1) dfs(g,\
    \ e.to, i);\n        }\n    }\n};\n#line 5 \"verify/library_checker/graph/two_edge_connected_components.test.cpp\"\
    \nint main(void) {\n    int n, m;\n    cin >> n >> m;\n    Graph<int> g(n);\n\
    \    rep(i, 0, m) {\n        int a, b;\n        cin >> a >> b;\n        g.add_edge(a,\
    \ b);\n    }\n    TwoEdgeConnectedComponents<int> low(g);\n    int k = low.groups.size();\n\
    \    cout << k << '\\n';\n    rep(i, 0, k) {\n        int l = low.groups[i].size();\n\
    \        cout << l << ' ';\n        rep(j, 0, l) {\n            cout << low.groups[i][j]\
    \ << \" \\n\"[j + 1 == l];\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/graph/two_edge_connected_components.hpp\"\nint main(void)\
    \ {\n    int n, m;\n    cin >> n >> m;\n    Graph<int> g(n);\n    rep(i, 0, m)\
    \ {\n        int a, b;\n        cin >> a >> b;\n        g.add_edge(a, b);\n  \
    \  }\n    TwoEdgeConnectedComponents<int> low(g);\n    int k = low.groups.size();\n\
    \    cout << k << '\\n';\n    rep(i, 0, k) {\n        int l = low.groups[i].size();\n\
    \        cout << l << ' ';\n        rep(j, 0, l) {\n            cout << low.groups[i][j]\
    \ << \" \\n\"[j + 1 == l];\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/graph/two_edge_connected_components.hpp
  - src/graph/low_link.hpp
  isVerificationFile: true
  path: verify/library_checker/graph/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 00:36:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/two_edge_connected_components.test.cpp
- /verify/verify/library_checker/graph/two_edge_connected_components.test.cpp.html
title: verify/library_checker/graph/two_edge_connected_components.test.cpp
---
