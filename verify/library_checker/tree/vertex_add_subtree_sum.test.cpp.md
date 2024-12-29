---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/fenwick_tree.hpp
    title: FenwickTree
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  - icon: ':heavy_check_mark:'
    path: src/tree/heavy_light_decomposition.hpp
    title: HeavyLightDecomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"verify/library_checker/tree/vertex_add_subtree_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    #line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
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
    \ Edges = vector<Edge<T>>;\n#line 4 \"src/tree/heavy_light_decomposition.hpp\"\
    \ntemplate <typename T>\nstruct HeavyLightDecomposition {\n    HeavyLightDecomposition(Graph<T>&\
    \ _g, const int root = 0)\n        : g(_g), n(g.size()), id(0), sz(n, 0), dep(n,\
    \ 0), down(n, -1), up(n, -1), nex(n, root), par(n, -1), rev(n, 0), co(n, 0) {\n\
    \        assert(0 <= root and root < n);\n        dfs_sz(root);\n        dfs_hld(root);\n\
    \    }\n    pair<int, int> idx(const int i) const {\n        assert(0 <= i and\
    \ i < n);\n        return make_pair(down[i], up[i]);\n    }\n    int depth(const\
    \ int v) const {\n        assert(0 <= v and v < n);\n        return dep[v];\n\
    \    }\n    T cost(const int v) const {\n        assert(0 <= v and v < n);\n \
    \       return co[v];\n    }\n    int parent(const int v) const {\n        assert(0\
    \ <= v and v < n);\n        return par[v];\n    }\n    int la(int v, int x) const\
    \ {\n        assert(0 <= v and v < n);\n        assert(x >= 0);\n        if(x\
    \ > dep[v]) return -1;\n        while(true) {\n            const int u = nex[v];\n\
    \            if(down[v] - x >= down[u]) return rev[down[v] - x];\n           \
    \ x -= down[v] - down[u] + 1;\n            v = par[u];\n        }\n    }\n   \
    \ int lca(int u, int v) const {\n        assert(0 <= u and u < n);\n        assert(0\
    \ <= v and v < n);\n        while(nex[u] != nex[v]) {\n            if(down[u]\
    \ < down[v]) swap(u, v);\n            u = par[nex[u]];\n        }\n        return\
    \ dep[u] < dep[v] ? u : v;\n    }\n    int dist(const int u, const int v) const\
    \ {\n        assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n  \
    \      return dep[u] + dep[v] - dep[lca(u, v)] * 2;\n    }\n    T length(const\
    \ int u, const int v) const {\n        assert(0 <= u and u < n);\n        assert(0\
    \ <= v and v < n);\n        return co[u] + co[v] - co[lca(u, v)] * 2;\n    }\n\
    \    template <typename F>\n    void path_query(const int u, const int v, const\
    \ bool vertex, const F& f) {\n        assert(0 <= u and u < n);\n        assert(0\
    \ <= v and v < n);\n        const int l = lca(u, v);\n        for(auto&& [a, b]\
    \ : ascend(u, l)) f(a + 1, b);\n        if(vertex) f(down[l], down[l] + 1);\n\
    \        for(auto&& [a, b] : descend(l, v)) f(a, b + 1);\n    }\n    template\
    \ <typename F>\n    void subtree_query(const int v, const bool vertex, const F&\
    \ f) {\n        assert(0 <= v and v < n);\n        f(down[v] + int(!vertex), up[v]);\n\
    \    }\n\n   private:\n    Graph<T>& g;\n    int n, id;\n    vector<int> sz, dep,\
    \ down, up, nex, par, rev;\n    vector<T> co;\n    void dfs_sz(const int cur)\
    \ {\n        sz[cur] = 1;\n        for(Edge<T>& edge : g[cur]) {\n           \
    \ if(edge.to == par[cur]) {\n                if(g[cur].size() >= 2 and edge.to\
    \ == g[cur][0].to) {\n                    swap(g[cur][0], g[cur][1]);\n      \
    \          } else {\n                    continue;\n                }\n      \
    \      }\n            dep[edge.to] = dep[cur] + 1;\n            co[edge.to] =\
    \ co[cur] + edge.cost;\n            par[edge.to] = cur;\n            dfs_sz(edge.to);\n\
    \            sz[cur] += sz[edge.to];\n            if(sz[edge.to] > sz[g[cur][0].to])\
    \ {\n                swap(edge, g[cur][0]);\n            }\n        }\n    }\n\
    \    void dfs_hld(const int cur) {\n        down[cur] = id++;\n        rev[down[cur]]\
    \ = cur;\n        for(const Edge<T>& edge : g[cur]) {\n            if(edge.to\
    \ == par[cur]) continue;\n            nex[edge.to] = (edge.to == g[cur][0].to\
    \ ? nex[cur] : edge.to);\n            dfs_hld(edge.to);\n        }\n        up[cur]\
    \ = id;\n    }\n    vector<pair<int, int>> ascend(int u, int v) const {\n    \
    \    vector<pair<int, int>> res;\n        while(nex[u] != nex[v]) {\n        \
    \    res.emplace_back(down[u], down[nex[u]]);\n            u = par[nex[u]];\n\
    \        }\n        if(u != v) res.emplace_back(down[u], down[v] + 1);\n     \
    \   return res;\n    }\n    vector<pair<int, int>> descend(const int u, const\
    \ int v) const {\n        if(u == v) return {};\n        if(nex[u] == nex[v])\
    \ return {{down[u] + 1, down[v]}};\n        auto res = descend(u, par[nex[v]]);\n\
    \        res.emplace_back(down[nex[v]], down[v]);\n        return res;\n    }\n\
    };\n#line 3 \"src/data_structure/fenwick_tree.hpp\"\ntemplate <typename T>\nstruct\
    \ FenwickTree {\n    FenwickTree(const int N)\n        : n(N), data(N) {}\n  \
    \  void add(int p, const T& x) {\n        assert(0 <= p and p < n);\n        ++p;\n\
    \        while(p <= n) {\n            data[p - 1] += x;\n            p += p &\
    \ -p;\n        }\n    }\n    T sum(const int l, const int r) const {\n       \
    \ assert(0 <= l and l <= r and r <= n);\n        return sum(r) - sum(l);\n   \
    \ }\n    T get(const int x) const {\n        assert(0 <= x and x < n);\n     \
    \   return sum(x + 1) - sum(x);\n    }\n\n   private:\n    int n;\n    vector<T>\
    \ data;\n    inline T sum(int r) const {\n        T s = 0;\n        while(r >\
    \ 0) {\n            s += data[r - 1];\n            r -= r & -r;\n        }\n \
    \       return s;\n    }\n};\n#line 6 \"verify/library_checker/tree/vertex_add_subtree_sum.test.cpp\"\
    \nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    vector<ll> a(n);\n\
    \    rep(i, 0, n) {\n        cin >> a[i];\n    }\n    Graph<int> g(n);\n    rep(i,\
    \ 1, n) {\n        int p;\n        cin >> p;\n        g.add_edge(i, p);\n    }\n\
    \    HeavyLightDecomposition<int> hld(g);\n    FenwickTree<ll> fw(n);\n    rep(i,\
    \ 0, n) {\n        fw.add(hld.idx(i).first, a[i]);\n    }\n    while(q--) {\n\
    \        int t;\n        cin >> t;\n        if(t == 0) {\n            ll p, x;\n\
    \            cin >> p >> x;\n            fw.add(hld.idx(p).first, x);\n      \
    \  } else {\n            int u;\n            cin >> u;\n            ll ans = 0;\n\
    \            auto query = [&](int u, int v) -> void {\n                ans +=\
    \ fw.sum(u, v);\n            };\n            hld.subtree_query(u, true, query);\n\
    \            cout << ans << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/tree/heavy_light_decomposition.hpp\"\n#include \"../../../src/data_structure/fenwick_tree.hpp\"\
    \nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    vector<ll> a(n);\n\
    \    rep(i, 0, n) {\n        cin >> a[i];\n    }\n    Graph<int> g(n);\n    rep(i,\
    \ 1, n) {\n        int p;\n        cin >> p;\n        g.add_edge(i, p);\n    }\n\
    \    HeavyLightDecomposition<int> hld(g);\n    FenwickTree<ll> fw(n);\n    rep(i,\
    \ 0, n) {\n        fw.add(hld.idx(i).first, a[i]);\n    }\n    while(q--) {\n\
    \        int t;\n        cin >> t;\n        if(t == 0) {\n            ll p, x;\n\
    \            cin >> p >> x;\n            fw.add(hld.idx(p).first, x);\n      \
    \  } else {\n            int u;\n            cin >> u;\n            ll ans = 0;\n\
    \            auto query = [&](int u, int v) -> void {\n                ans +=\
    \ fw.sum(u, v);\n            };\n            hld.subtree_query(u, true, query);\n\
    \            cout << ans << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/tree/heavy_light_decomposition.hpp
  - src/data_structure/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 01:50:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
- /verify/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp.html
title: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
---