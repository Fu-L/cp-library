---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/biconnected_components.hpp
    title: BiconnectedComponents
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/graph/biconnected_components.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 4 \"src/template/template.hpp\"\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/graph/graph_template.hpp\"\
    \ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T cost;\n    int\
    \ idx;\n    Edge()\n        : from(-1), to(-1), cost(-1), idx(-1) {}\n    Edge(const\
    \ int from, const int to, const T& cost = 1, const int idx = -1)\n        : from(from),\
    \ to(to), cost(cost), idx(idx) {}\n    operator int() const {\n        return\
    \ to;\n    }\n};\ntemplate <typename T>\nstruct Graph {\n    Graph(const int N)\n\
    \        : n(N), es(0), g(N) {}\n    int size() const {\n        return n;\n \
    \   }\n    int edge_size() const {\n        return es;\n    }\n    void add_edge(const\
    \ int from, const int to, const T& cost = 1) {\n        assert(0 <= from and from\
    \ < n);\n        assert(0 <= to and to < n);\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n \
    \   void add_directed_edge(const int from, const int to, const T& cost = 1) {\n\
    \        assert(0 <= from and from < n);\n        assert(0 <= to and to < n);\n\
    \        g[from].emplace_back(from, to, cost, es++);\n    }\n    inline vector<Edge<T>>&\
    \ operator[](const int& k) {\n        assert(0 <= k and k < n);\n        return\
    \ g[k];\n    }\n    inline const vector<Edge<T>>& operator[](const int& k) const\
    \ {\n        assert(0 <= k and k < n);\n        return g[k];\n    }\n\n   private:\n\
    \    int n, es;\n    vector<vector<Edge<T>>> g;\n};\ntemplate <typename T>\nusing\
    \ Edges = vector<Edge<T>>;\n#line 4 \"src/graph/low_link.hpp\"\ntemplate <typename\
    \ T>\nstruct LowLink {\n    vector<int> ord, low, articulation;\n    vector<pair<int,\
    \ int>> bridge;\n    LowLink(const Graph<T>& g)\n        : ord(g.size(), -1),\
    \ low(g.size(), -1) {\n        for(int i = 0, k = 0; i < g.size(); ++i) {\n  \
    \          if(ord[i] == -1) k = dfs(g, i, k, -1);\n        }\n    }\n\n   private:\n\
    \    int dfs(const Graph<T>& g, const int idx, int k, const int par) {\n     \
    \   low[idx] = (ord[idx] = k++);\n        int cnt = 0;\n        bool arti = false,\
    \ second = false;\n        for(const Edge<T>& e : g[idx]) {\n            const\
    \ int to = e.to;\n            if(ord[to] == -1) {\n                ++cnt;\n  \
    \              k = dfs(g, to, k, idx);\n                low[idx] = min(low[idx],\
    \ low[to]);\n                arti |= (par != -1) and (low[to] >= ord[idx]);\n\
    \                if(ord[idx] < low[to]) {\n                    bridge.emplace_back(minmax(idx,\
    \ to));\n                }\n            } else if(to != par or second) {\n   \
    \             low[idx] = min(low[idx], ord[to]);\n            } else {\n     \
    \           second = true;\n            }\n        }\n        arti |= (par ==\
    \ -1) and (cnt > 1);\n        if(arti) articulation.emplace_back(idx);\n     \
    \   return k;\n    }\n};\n#line 5 \"src/graph/biconnected_components.hpp\"\ntemplate\
    \ <typename T>\nstruct BiconnectedComponents {\n    vector<vector<pair<int, int>>>\
    \ bc;\n    BiconnectedComponents(const Graph<T>& g)\n        : n(g.size()), lowlink(g),\
    \ used(n) {\n        for(int i = 0; i < n; ++i) {\n            if(!used[i]) dfs(g,\
    \ i, -1);\n        }\n    }\n\n   private:\n    struct edge_key {\n        int\
    \ u, v, idx;\n    };\n    int n;\n    LowLink<T> lowlink;\n    vector<int> used;\n\
    \    vector<edge_key> tmp;\n    void dfs(const Graph<T>& g, const int idx, const\
    \ int par_edge_idx) {\n        used[idx] = true;\n        for(const Edge<T>& e\
    \ : g[idx]) {\n            const int to = e.to;\n            if(e.idx == par_edge_idx)\
    \ continue;\n            if(!used[to] or lowlink.ord[to] < lowlink.ord[idx]) {\n\
    \                const auto [u, v] = minmax(idx, to);\n                tmp.push_back({u,\
    \ v, e.idx});\n            }\n            if(!used[to]) {\n                dfs(g,\
    \ to, e.idx);\n                if(lowlink.low[to] >= lowlink.ord[idx]) {\n   \
    \                 bc.emplace_back();\n                    while(true) {\n    \
    \                    const edge_key ed = tmp.back();\n                       \
    \ bc.back().emplace_back(ed.u, ed.v);\n                        tmp.pop_back();\n\
    \                        if(ed.idx == e.idx) break;\n                    }\n \
    \               }\n            }\n        }\n    }\n};\n#line 5 \"verify/unit_test/graph/biconnected_components.test.cpp\"\
    \nint main() {\n    Graph<int> g(2);\n    g.add_edge(0, 1);\n    g.add_edge(0,\
    \ 1);\n    BiconnectedComponents<int> bc(g);\n    assert(bc.bc.size() == 1);\n\
    \    assert(bc.bc[0].size() == 2);\n    Graph<int> h(3);\n    h.add_edge(0, 1);\n\
    \    h.add_edge(1, 2);\n    BiconnectedComponents<int> bc2(h);\n    assert(bc2.bc.size()\
    \ == 2);\n    for(const auto& comp : bc2.bc) assert(comp.size() == 1);\n    int\
    \ a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/graph/graph_template.hpp\"\n#include \"../../../src/graph/biconnected_components.hpp\"\
    \nint main() {\n    Graph<int> g(2);\n    g.add_edge(0, 1);\n    g.add_edge(0,\
    \ 1);\n    BiconnectedComponents<int> bc(g);\n    assert(bc.bc.size() == 1);\n\
    \    assert(bc.bc[0].size() == 2);\n    Graph<int> h(3);\n    h.add_edge(0, 1);\n\
    \    h.add_edge(1, 2);\n    BiconnectedComponents<int> bc2(h);\n    assert(bc2.bc.size()\
    \ == 2);\n    for(const auto& comp : bc2.bc) assert(comp.size() == 1);\n    int\
    \ a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/graph/biconnected_components.hpp
  - src/graph/low_link.hpp
  isVerificationFile: true
  path: verify/unit_test/graph/biconnected_components.test.cpp
  requiredBy: []
  timestamp: '2026-07-04 16:35:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/graph/biconnected_components.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/graph/biconnected_components.test.cpp
- /verify/verify/unit_test/graph/biconnected_components.test.cpp.html
title: verify/unit_test/graph/biconnected_components.test.cpp
---
