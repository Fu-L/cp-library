---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data_structure/fenwick_tree.hpp
    title: FenwickTree
  - icon: ':question:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  - icon: ':question:'
    path: src/tree/heavy_light_decomposition.hpp
    title: HeavyLightDecomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/jump_on_tree
    links:
    - https://judge.yosupo.jp/problem/jump_on_tree
  bundledCode: "#line 1 \"verify/library_checker/tree/jump_on_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i,\
    \ a, b) for(ll i = a; i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n\
    \    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n    \
    \    cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/graph/graph_template.hpp\"\
    \ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T cost;\n    int\
    \ idx;\n    Edge()\n        : from(-1), to(-1), cost(-1), idx(-1) {}\n    Edge(int\
    \ from, int to, const T& cost = 1, int idx = -1)\n        : from(from), to(to),\
    \ cost(cost), idx(idx) {}\n    operator int() const {\n        return to;\n  \
    \  }\n};\ntemplate <typename T>\nstruct Graph {\n    Graph(int N)\n        : n(N),\
    \ es(0), g(N) {}\n    int size() const {\n        return n;\n    }\n    int edge_size()\
    \ const {\n        return es;\n    }\n    void add_edge(int from, int to, const\
    \ T& cost = 1) {\n        assert(0 <= from and from < n);\n        assert(0 <=\
    \ to and to < n);\n        g[from].emplace_back(from, to, cost, es);\n       \
    \ g[to].emplace_back(to, from, cost, es++);\n    }\n    void add_directed_edge(int\
    \ from, int to, const T& cost = 1) {\n        assert(0 <= from and from < n);\n\
    \        assert(0 <= to and to < n);\n        g[from].emplace_back(from, to, cost,\
    \ es++);\n    }\n    inline vector<Edge<T>>& operator[](const int& k) {\n    \
    \    assert(0 <= k and k < n);\n        return g[k];\n    }\n    inline const\
    \ vector<Edge<T>>& operator[](const int& k) const {\n        assert(0 <= k and\
    \ k < n);\n        return g[k];\n    }\n\n   private:\n    int n, es;\n    vector<vector<Edge<T>>>\
    \ g;\n};\ntemplate <typename T>\nusing Edges = vector<Edge<T>>;\n#line 4 \"src/tree/heavy_light_decomposition.hpp\"\
    \ntemplate <typename T>\nstruct HeavyLightDecomposition {\n    HeavyLightDecomposition(Graph<T>&\
    \ _g, int root = 0)\n        : g(_g), n(g.size()), id(0), size(n, 0), depth(n,\
    \ 0), down(n, -1), up(n, -1), nex(n, root), par(n, root), rev(n, 0) {\n      \
    \  assert(0 <= root and root < n);\n        dfs_sz(root);\n        dfs_hld(root);\n\
    \    }\n    pair<int, int> idx(int i) const {\n        assert(0 <= i and i < n);\n\
    \        return make_pair(down[i], up[i]);\n    }\n    int la(int v, int x = 1)\
    \ const {\n        assert(0 <= v and v < n);\n        assert(x >= 0);\n      \
    \  if(x > depth[v]) return -1;\n        while(true) {\n            const int u\
    \ = nex[v];\n            if(down[v] - x >= down[u]) return rev[down[v] - x];\n\
    \            x -= down[v] - down[u] + 1;\n            v = par[u];\n        }\n\
    \    }\n    int lca(int u, int v) const {\n        assert(0 <= u and u < n);\n\
    \        assert(0 <= v and v < n);\n        while(nex[u] != nex[v]) {\n      \
    \      if(down[u] < down[v]) swap(u, v);\n            u = par[nex[u]];\n     \
    \   }\n        return depth[u] < depth[v] ? u : v;\n    }\n    int dist(int u,\
    \ int v) const {\n        assert(0 <= u and u < n);\n        assert(0 <= v and\
    \ v < n);\n        return depth[u] + depth[v] - depth[lca(u, v)] * 2;\n    }\n\
    \    template <typename F>\n    void path_query(int u, int v, bool vertex, const\
    \ F& f) {\n        assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n\
    \        int l = lca(u, v);\n        for(auto&& [a, b] : ascend(u, l)) f(a + 1,\
    \ b);\n        if(vertex) f(down[l], down[l] + 1);\n        for(auto&& [a, b]\
    \ : descend(l, v)) f(a, b + 1);\n    }\n    template <typename F>\n    void subtree_query(int\
    \ v, bool vertex, const F& f) {\n        assert(0 <= v and v < n);\n        f(down[v]\
    \ + int(!vertex), up[v]);\n    }\n\n   private:\n    Graph<T>& g;\n    int n,\
    \ id;\n    vector<int> size, depth, down, up, nex, par, rev;\n    void dfs_sz(int\
    \ cur) {\n        size[cur] = 1;\n        for(Edge<T>& edge : g[cur]) {\n    \
    \        if(edge.to == par[cur]) {\n                if(g[cur].size() >= 2 and\
    \ edge.to == g[cur][0].to) {\n                    swap(g[cur][0], g[cur][1]);\n\
    \                } else {\n                    continue;\n                }\n\
    \            }\n            depth[edge.to] = depth[cur] + 1;\n            par[edge.to]\
    \ = cur;\n            dfs_sz(edge.to);\n            size[cur] += size[edge.to];\n\
    \            if(size[edge.to] > size[g[cur][0].to]) {\n                swap(edge,\
    \ g[cur][0]);\n            }\n        }\n    }\n    void dfs_hld(int cur) {\n\
    \        down[cur] = id++;\n        rev[down[cur]] = cur;\n        for(const Edge<T>&\
    \ edge : g[cur]) {\n            if(edge.to == par[cur]) continue;\n          \
    \  nex[edge.to] = (edge.to == g[cur][0].to ? nex[cur] : edge.to);\n          \
    \  dfs_hld(edge.to);\n        }\n        up[cur] = id;\n    }\n    vector<pair<int,\
    \ int>> ascend(int u, int v) const {\n        vector<pair<int, int>> res;\n  \
    \      while(nex[u] != nex[v]) {\n            res.emplace_back(down[u], down[nex[u]]);\n\
    \            u = par[nex[u]];\n        }\n        if(u != v) res.emplace_back(down[u],\
    \ down[v] + 1);\n        return res;\n    }\n    vector<pair<int, int>> descend(int\
    \ u, int v) const {\n        if(u == v) return {};\n        if(nex[u] == nex[v])\
    \ return {{down[u] + 1, down[v]}};\n        auto res = descend(u, par[nex[v]]);\n\
    \        res.emplace_back(down[nex[v]], down[v]);\n        return res;\n    }\n\
    };\n#line 3 \"src/data_structure/fenwick_tree.hpp\"\ntemplate <typename T>\nstruct\
    \ FenwickTree {\n    FenwickTree(int N)\n        : n(N), data(N) {}\n    void\
    \ add(int p, T x) {\n        assert(0 <= p and p < n);\n        ++p;\n       \
    \ while(p <= n) {\n            data[p - 1] += x;\n            p += p & -p;\n \
    \       }\n    }\n    T sum(int l, int r) const {\n        assert(0 <= l and l\
    \ <= r and r <= n);\n        return sum(r) - sum(l);\n    }\n    T operator[](int\
    \ x) const {\n        assert(0 <= x and x < n);\n        return sum(x + 1) - sum(x);\n\
    \    }\n\n   private:\n    int n;\n    vector<T> data;\n    inline T sum(int r)\
    \ const {\n        T s = 0;\n        while(r > 0) {\n            s += data[r -\
    \ 1];\n            r -= r & -r;\n        }\n        return s;\n    }\n};\n#line\
    \ 6 \"verify/library_checker/tree/jump_on_tree.test.cpp\"\nint main(void) {\n\
    \    int n, q;\n    cin >> n >> q;\n    Graph<int> g(n);\n    rep(i, 0, n - 1)\
    \ {\n        int u, v;\n        cin >> u >> v;\n        g.add_edge(u, v);\n  \
    \  }\n    HeavyLightDecomposition<int> hld(g);\n    while(q--) {\n        int\
    \ s, t, i;\n        cin >> s >> t >> i;\n        int dist = hld.dist(s, t);\n\
    \        if(i > dist) {\n            cout << -1 << '\\n';\n            continue;\n\
    \        }\n        int l = hld.lca(s, t);\n        int d1 = hld.dist(s, l);\n\
    \        if(i <= d1) {\n            cout << hld.la(s, i) << '\\n';\n        }\
    \ else {\n            cout << hld.la(t, dist - i) << '\\n';\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/tree/heavy_light_decomposition.hpp\"\n#include \"../../../src/data_structure/fenwick_tree.hpp\"\
    \nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    Graph<int> g(n);\n\
    \    rep(i, 0, n - 1) {\n        int u, v;\n        cin >> u >> v;\n        g.add_edge(u,\
    \ v);\n    }\n    HeavyLightDecomposition<int> hld(g);\n    while(q--) {\n   \
    \     int s, t, i;\n        cin >> s >> t >> i;\n        int dist = hld.dist(s,\
    \ t);\n        if(i > dist) {\n            cout << -1 << '\\n';\n            continue;\n\
    \        }\n        int l = hld.lca(s, t);\n        int d1 = hld.dist(s, l);\n\
    \        if(i <= d1) {\n            cout << hld.la(s, i) << '\\n';\n        }\
    \ else {\n            cout << hld.la(t, dist - i) << '\\n';\n        }\n    }\n\
    }"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/tree/heavy_light_decomposition.hpp
  - src/data_structure/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/library_checker/tree/jump_on_tree.test.cpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/tree/jump_on_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/jump_on_tree.test.cpp
- /verify/verify/library_checker/tree/jump_on_tree.test.cpp.html
title: verify/library_checker/tree/jump_on_tree.test.cpp
---
