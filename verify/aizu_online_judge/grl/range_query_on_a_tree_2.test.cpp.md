---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/lazy_segment_tree.hpp
    title: LazySegmentTree
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E
  bundledCode: "#line 1 \"verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E\"\n#line\
    \ 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i\
    \ = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
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
    #line 4 \"src/tree/heavy_light_decomposition.hpp\"\ntemplate <typename T>\nstruct\
    \ HeavyLightDecomposition {\n    HeavyLightDecomposition(Graph<T>& _g, const int\
    \ root = 0)\n        : g(_g), n(g.size()), id(0), sz(n, 0), dep(n, 0), down(n,\
    \ -1), up(n, -1), nex(n, root), par(n, -1), rev(n, 0), co(n, 0) {\n        assert(0\
    \ <= root and root < n);\n        dfs_sz(root);\n        dfs_hld(root);\n    }\n\
    \    pair<int, int> idx(const int i) const {\n        assert(0 <= i and i < n);\n\
    \        return make_pair(down[i], up[i]);\n    }\n    int depth(const int v)\
    \ const {\n        assert(0 <= v and v < n);\n        return dep[v];\n    }\n\
    \    T cost(const int v) const {\n        assert(0 <= v and v < n);\n        return\
    \ co[v];\n    }\n    int parent(const int v) const {\n        assert(0 <= v and\
    \ v < n);\n        return par[v];\n    }\n    int la(int v, int x) const {\n \
    \       assert(0 <= v and v < n);\n        assert(x >= 0);\n        if(x > dep[v])\
    \ return -1;\n        while(true) {\n            const int u = nex[v];\n     \
    \       if(down[v] - x >= down[u]) return rev[down[v] - x];\n            x -=\
    \ down[v] - down[u] + 1;\n            v = par[u];\n        }\n    }\n    int lca(int\
    \ u, int v) const {\n        assert(0 <= u and u < n);\n        assert(0 <= v\
    \ and v < n);\n        while(nex[u] != nex[v]) {\n            if(down[u] < down[v])\
    \ swap(u, v);\n            u = par[nex[u]];\n        }\n        return dep[u]\
    \ < dep[v] ? u : v;\n    }\n    int dist(const int u, const int v) const {\n \
    \       assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n       \
    \ return dep[u] + dep[v] - dep[lca(u, v)] * 2;\n    }\n    T length(const int\
    \ u, const int v) const {\n        assert(0 <= u and u < n);\n        assert(0\
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
    };\n#line 3 \"src/data_structure/lazy_segment_tree.hpp\"\ntemplate <typename S,\
    \ auto op, auto e, typename F, auto mapping, auto composition, auto id>\nstruct\
    \ LazySegmentTree {\n    LazySegmentTree(const int N)\n        : LazySegmentTree(vector<S>(N,\
    \ e())) {}\n    LazySegmentTree(const vector<S>& v)\n        : n((int)v.size())\
    \ {\n        size = bit_ceil((unsigned int)n);\n        log = countr_zero((unsigned\
    \ int)size);\n        data = vector<S>(2 * size, e());\n        lazy = vector<F>(size,\
    \ id());\n        for(int i = 0; i < n; ++i) {\n            data[size + i] = v[i];\n\
    \        }\n        for(int i = size - 1; i >= 1; --i) {\n            update(i);\n\
    \        }\n    }\n    void set(int p, const S& x) {\n        assert(0 <= p and\
    \ p < n);\n        p += size;\n        for(int i = log; i >= 1; --i) {\n     \
    \       push(p >> i);\n        }\n        data[p] = x;\n        for(int i = 1;\
    \ i <= log; ++i) {\n            update(p >> i);\n        }\n    }\n    S get(int\
    \ p) {\n        assert(0 <= p and p < n);\n        p += size;\n        for(int\
    \ i = log; i >= 1; --i) {\n            push(p >> i);\n        }\n        return\
    \ data[p];\n    }\n    S prod(int l, int r) {\n        assert(0 <= l and l <=\
    \ r and r <= n);\n        if(l == r) return e();\n        l += size;\n       \
    \ r += size;\n        for(int i = log; i >= 1; --i) {\n            if(((l >> i)\
    \ << i) != l) push(l >> i);\n            if(((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n        }\n        S sml = e(), smr = e();\n        while(l < r) {\n\
    \            if(l & 1) sml = op(sml, data[l++]);\n            if(r & 1) smr =\
    \ op(data[--r], smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n    S all_prod() const {\n        return\
    \ data[1];\n    }\n    void apply(int l, int r, const F& f) {\n        assert(0\
    \ <= l and l <= r and r <= n);\n        if(l == r) return;\n        l += size;\n\
    \        r += size;\n        for(int i = log; i >= 1; --i) {\n            if(((l\
    \ >> i) << i) != l) push(l >> i);\n            if(((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n        }\n        {\n            int l2 = l, r2 = r;\n       \
    \     while(l < r) {\n                if(l & 1) all_apply(l++, f);\n         \
    \       if(r & 1) all_apply(--r, f);\n                l >>= 1;\n             \
    \   r >>= 1;\n            }\n            l = l2;\n            r = r2;\n      \
    \  }\n        for(int i = 1; i <= log; ++i) {\n            if(((l >> i) << i)\
    \ != l) update(l >> i);\n            if(((r >> i) << i) != r) update((r - 1) >>\
    \ i);\n        }\n    }\n\n    template <bool (*g)(S)>\n    int max_right(const\
    \ int l) {\n        return max_right(l, [](const S& x) { return g(x); });\n  \
    \  }\n    template <class G>\n    int max_right(int l, const G& g) {\n       \
    \ assert(0 <= l and l <= n);\n        assert(g(e()));\n        if(l == n) return\
    \ n;\n        l += size;\n        for(int i = log; i >= 1; --i) push(l >> i);\n\
    \        S sm = e();\n        do {\n            while(l % 2 == 0) l >>= 1;\n \
    \           if(!g(op(sm, data[l]))) {\n                while(l < size) {\n   \
    \                 push(l);\n                    l = 2 * l;\n                 \
    \   if(g(op(sm, data[l]))) {\n                        sm = op(sm, data[l]);\n\
    \                        ++l;\n                    }\n                }\n    \
    \            return l - size;\n            }\n            sm = op(sm, data[l]);\n\
    \            ++l;\n        } while((l & -l) != l);\n        return n;\n    }\n\
    \n    template <bool (*g)(S)>\n    int min_left(const int r) {\n        return\
    \ min_left(r, [](const S& x) { return g(x); });\n    }\n    template <class G>\n\
    \    int min_left(int r, const G& g) {\n        assert(0 <= r and r <= n);\n \
    \       assert(g(e()));\n        if(r == 0) return 0;\n        r += size;\n  \
    \      for(int i = log; i >= 1; --i) push((r - 1) >> i);\n        S sm = e();\n\
    \        do {\n            --r;\n            while(r > 1 and (r % 2)) r >>= 1;\n\
    \            if(!g(op(data[r], sm))) {\n                while(r < size) {\n  \
    \                  push(r);\n                    r = 2 * r + 1;\n            \
    \        if(g(op(data[r], sm))) {\n                        sm = op(data[r], sm);\n\
    \                        --r;\n                    }\n                }\n    \
    \            return r + 1 - size;\n            }\n            sm = op(data[r],\
    \ sm);\n        } while((r & -r) != r);\n        return 0;\n    }\n\n   private:\n\
    \    int n, size, log;\n    vector<S> data;\n    vector<F> lazy;\n    inline void\
    \ update(const int k) {\n        data[k] = op(data[2 * k], data[2 * k + 1]);\n\
    \    }\n    inline void all_apply(const int k, const F& f) {\n        data[k]\
    \ = mapping(f, data[k]);\n        if(k < size) {\n            lazy[k] = composition(f,\
    \ lazy[k]);\n        }\n    }\n    inline void push(const int k) {\n        all_apply(2\
    \ * k, lazy[k]);\n        all_apply(2 * k + 1, lazy[k]);\n        lazy[k] = id();\n\
    \    }\n    inline unsigned int bit_ceil(const unsigned int n) const {\n     \
    \   unsigned int res = 1;\n        while(res < n) res *= 2;\n        return res;\n\
    \    }\n    inline int countr_zero(const unsigned int n) const {\n        return\
    \ __builtin_ctz(n);\n    }\n};\n#line 6 \"verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp\"\
    \nstruct S {\n    long long value;\n    long long size;\n};\nusing F = long long;\n\
    S op(const S& a, const S& b) {\n    return {a.value + b.value, a.size + b.size};\n\
    }\nS e() {\n    return {0, 0};\n}\nS mapping(const F& f, const S& x) {\n    return\
    \ {x.value + f * x.size, x.size};\n}\nF composition(const F& f, const F& g) {\n\
    \    return f + g;\n}\nF id() {\n    return 0;\n}\nint main(void) {\n    int n;\n\
    \    cin >> n;\n    Graph<int> g(n);\n    rep(i, 0, n) {\n        int k;\n   \
    \     cin >> k;\n        rep(j, 0, k) {\n            int c;\n            cin >>\
    \ c;\n            g.add_edge(i, c);\n        }\n    }\n    HeavyLightDecomposition<int>\
    \ hld(g);\n    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(n);\n\
    \    rep(i, 0, n) seg.set(i, {0, 1});\n    int q;\n    cin >> q;\n    while(q--)\
    \ {\n        int t;\n        cin >> t;\n        if(t == 0) {\n            ll v,\
    \ w;\n            cin >> v >> w;\n            auto add = [&](int u, int v) ->\
    \ void {\n                seg.apply(u, v, w);\n            };\n            hld.path_query(0,\
    \ v, false, add);\n        } else {\n            int v;\n            cin >> v;\n\
    \            ll ans = 0;\n            auto query = [&](int u, int v) -> void {\n\
    \                ans += seg.prod(u, v).value;\n            };\n            hld.path_query(0,\
    \ v, false, query);\n            cout << ans << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/tree/heavy_light_decomposition.hpp\"\n#include \"../../../src/data_structure/lazy_segment_tree.hpp\"\
    \nstruct S {\n    long long value;\n    long long size;\n};\nusing F = long long;\n\
    S op(const S& a, const S& b) {\n    return {a.value + b.value, a.size + b.size};\n\
    }\nS e() {\n    return {0, 0};\n}\nS mapping(const F& f, const S& x) {\n    return\
    \ {x.value + f * x.size, x.size};\n}\nF composition(const F& f, const F& g) {\n\
    \    return f + g;\n}\nF id() {\n    return 0;\n}\nint main(void) {\n    int n;\n\
    \    cin >> n;\n    Graph<int> g(n);\n    rep(i, 0, n) {\n        int k;\n   \
    \     cin >> k;\n        rep(j, 0, k) {\n            int c;\n            cin >>\
    \ c;\n            g.add_edge(i, c);\n        }\n    }\n    HeavyLightDecomposition<int>\
    \ hld(g);\n    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(n);\n\
    \    rep(i, 0, n) seg.set(i, {0, 1});\n    int q;\n    cin >> q;\n    while(q--)\
    \ {\n        int t;\n        cin >> t;\n        if(t == 0) {\n            ll v,\
    \ w;\n            cin >> v >> w;\n            auto add = [&](int u, int v) ->\
    \ void {\n                seg.apply(u, v, w);\n            };\n            hld.path_query(0,\
    \ v, false, add);\n        } else {\n            int v;\n            cin >> v;\n\
    \            ll ans = 0;\n            auto query = [&](int u, int v) -> void {\n\
    \                ans += seg.prod(u, v).value;\n            };\n            hld.path_query(0,\
    \ v, false, query);\n            cout << ans << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/tree/heavy_light_decomposition.hpp
  - src/data_structure/lazy_segment_tree.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 00:36:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp
- /verify/verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp.html
title: verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp
---
