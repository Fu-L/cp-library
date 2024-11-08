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
    path: src/tree/lowest_common_ancestor.hpp
    title: LowestCommonAncestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C
  bundledCode: "#line 1 \"verify/aizu_online_judge/grl/lowest_common_ancestor.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C\"\
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
    #line 4 \"src/tree/lowest_common_ancestor.hpp\"\ntemplate <typename T>\nstruct\
    \ LowestCommonAncestor {\n    LowestCommonAncestor(const Graph<T>& g, const int\
    \ root = 0) {\n        assert(0 <= root and root < g.size());\n        init(g,\
    \ root);\n    }\n    int depth(const int v) const {\n        assert(0 <= v and\
    \ v < n);\n        return dep[v];\n    }\n    T cost(const int v) const {\n  \
    \      assert(0 <= v and v < n);\n        return co[v];\n    }\n    int parent(const\
    \ int v) const {\n        assert(0 <= v and v < n);\n        return par[0][v];\n\
    \    }\n    int la(int v, int x) const {\n        assert(0 <= v and v < n);\n\
    \        assert(x >= 0);\n        if(x > dep[v]) return -1;\n        for(int i\
    \ = 0; x > 0; ++i) {\n            if(x & 1) v = par[i][v];\n            x >>=\
    \ 1;\n        }\n        return v;\n    }\n    int lca(int u, int v) const {\n\
    \        assert(0 <= u and u < n and 0 <= v and v < n);\n        if(dep[u] > dep[v])\
    \ swap(u, v);\n        v = la(v, dep[v] - dep[u]);\n        if(u == v) return\
    \ u;\n        for(int i = (int)par.size() - 1; i >= 0; --i) {\n            if(par[i][u]\
    \ != par[i][v]) {\n                u = par[i][u];\n                v = par[i][v];\n\
    \            }\n        }\n        return par[0][u];\n    }\n    int dist(const\
    \ int u, const int v) const {\n        assert(0 <= u and u < n and 0 <= v and\
    \ v < n);\n        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n    T\
    \ length(const int u, const int v) const {\n        assert(0 <= u and u < n and\
    \ 0 <= v and v < n);\n        return co[u] + co[v] - 2 * co[lca(u, v)];\n    }\n\
    \n   private:\n    int n;\n    vector<vector<int>> par;\n    vector<int> dep;\n\
    \    vector<T> co;\n    void init(const Graph<T>& g, const int root = 0) {\n \
    \       n = g.size();\n        int h = 1;\n        while((1 << h) < n) ++h;\n\
    \        par.assign(h, vector<int>(n, -1));\n        dep.assign(n, -1);\n    \
    \    co.assign(n, -1);\n        dfs(g, root, -1, 0, 0);\n        for(int i = 0;\
    \ i + 1 < (int)par.size(); ++i) {\n            for(int v = 0; v < n; ++v) {\n\
    \                if(par[i][v] != -1) {\n                    par[i + 1][v] = par[i][par[i][v]];\n\
    \                }\n            }\n        }\n    }\n    void dfs(const Graph<T>&\
    \ g, const int v, const int p, const int d, const T& c) {\n        par[0][v] =\
    \ p;\n        dep[v] = d;\n        co[v] = c;\n        for(const Edge<T>& e :\
    \ g[v]) {\n            if(e.to == p) continue;\n            dfs(g, e.to, v, d\
    \ + 1, c + e.cost);\n        }\n    }\n};\n#line 5 \"verify/aizu_online_judge/grl/lowest_common_ancestor.test.cpp\"\
    \nint main(void) {\n    int n;\n    cin >> n;\n    Graph<int> g(n);\n    rep(i,\
    \ 0, n) {\n        int k;\n        cin >> k;\n        rep(j, 0, k) {\n       \
    \     int c;\n            cin >> c;\n            g.add_edge(i, c);\n        }\n\
    \    }\n    LowestCommonAncestor<int> tree(g);\n    int q;\n    cin >> q;\n  \
    \  while(q--) {\n        int u, v;\n        cin >> u >> v;\n        cout << tree.lca(u,\
    \ v) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/tree/lowest_common_ancestor.hpp\"\nint main(void) {\n\
    \    int n;\n    cin >> n;\n    Graph<int> g(n);\n    rep(i, 0, n) {\n       \
    \ int k;\n        cin >> k;\n        rep(j, 0, k) {\n            int c;\n    \
    \        cin >> c;\n            g.add_edge(i, c);\n        }\n    }\n    LowestCommonAncestor<int>\
    \ tree(g);\n    int q;\n    cin >> q;\n    while(q--) {\n        int u, v;\n \
    \       cin >> u >> v;\n        cout << tree.lca(u, v) << '\\n';\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/tree/lowest_common_ancestor.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/grl/lowest_common_ancestor.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 00:36:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/grl/lowest_common_ancestor.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/grl/lowest_common_ancestor.test.cpp
- /verify/verify/aizu_online_judge/grl/lowest_common_ancestor.test.cpp.html
title: verify/aizu_online_judge/grl/lowest_common_ancestor.test.cpp
---
