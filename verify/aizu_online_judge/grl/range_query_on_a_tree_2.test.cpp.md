---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/lazy_segment_tree.hpp
    title: LazySegmentTree
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
    using Edges = vector<Edge<T>>;\n#line 4 \"src/tree/heavy_light_decomposition.hpp\"\
    \ntemplate <typename T>\nstruct HeavyLightDecomposition {\n    HeavyLightDecomposition(Graph<T>&\
    \ _g, int root = 0)\n        : g(_g), n(g.size()), id(0), size(n, 0), depth(n,\
    \ 0), down(n, -1), up(n, -1), nex(n, root), par(n, root), rev(n, 0) {\n      \
    \  assert(0 <= root and root < n);\n        dfs_sz(root);\n        dfs_hld(root);\n\
    \    }\n    pair<int, int> idx(int i) const {\n        assert(0 <= i and i < n);\n\
    \        return make_pair(down[i], up[i]);\n    }\n    int la(int a, int k) const\
    \ {\n        assert(0 <= a and a < n);\n        if(k > depth[a]) return -1;\n\
    \        while(true) {\n            int b = nex[a];\n            if(down[a] -\
    \ k >= down[b]) return rev[down[a] - k];\n            k -= down[a] - down[b] +\
    \ 1;\n            a = par[b];\n        }\n    }\n    int lca(int a, int b) const\
    \ {\n        assert(0 <= a and a < n);\n        assert(0 <= b and b < n);\n  \
    \      while(nex[a] != nex[b]) {\n            if(down[a] < down[b]) swap(a, b);\n\
    \            a = par[nex[a]];\n        }\n        return depth[a] < depth[b] ?\
    \ a : b;\n    }\n    int dist(int a, int b) const {\n        assert(0 <= a and\
    \ a < n);\n        assert(0 <= b and b < n);\n        return depth[a] + depth[b]\
    \ - depth[lca(a, b)] * 2;\n    }\n    template <typename F>\n    void path_query(int\
    \ u, int v, bool vertex, const F& f) {\n        assert(0 <= u and u < n);\n  \
    \      assert(0 <= v and v < n);\n        int l = lca(u, v);\n        for(auto&&\
    \ [a, b] : ascend(u, l)) f(a + 1, b);\n        if(vertex) f(down[l], down[l] +\
    \ 1);\n        for(auto&& [a, b] : descend(l, v)) f(a, b + 1);\n    }\n    template\
    \ <typename F>\n    void subtree_query(int u, bool vertex, const F& f) {\n   \
    \     assert(0 <= u and u < n);\n        f(down[u] + int(!vertex), up[u]);\n \
    \   }\n\n   private:\n    Graph<T>& g;\n    int n, id;\n    vector<int> size,\
    \ depth, down, up, nex, par, rev;\n    void dfs_sz(int cur) {\n        size[cur]\
    \ = 1;\n        for(auto& edge : g[cur]) {\n            if(edge.to == par[cur])\
    \ {\n                if(g[cur].size() >= 2 and edge.to == g[cur][0].to) {\n  \
    \                  swap(g[cur][0], g[cur][1]);\n                } else {\n   \
    \                 continue;\n                }\n            }\n            depth[edge.to]\
    \ = depth[cur] + 1;\n            par[edge.to] = cur;\n            dfs_sz(edge.to);\n\
    \            size[cur] += size[edge.to];\n            if(size[edge.to] > size[g[cur][0].to])\
    \ {\n                swap(edge, g[cur][0]);\n            }\n        }\n    }\n\
    \    void dfs_hld(int cur) {\n        down[cur] = id++;\n        rev[down[cur]]\
    \ = cur;\n        for(const auto& edge : g[cur]) {\n            if(edge.to ==\
    \ par[cur]) continue;\n            nex[edge.to] = (edge.to == g[cur][0].to ? nex[cur]\
    \ : edge.to);\n            dfs_hld(edge.to);\n        }\n        up[cur] = id;\n\
    \    }\n    vector<pair<int, int>> ascend(int u, int v) const {\n        vector<pair<int,\
    \ int>> res;\n        while(nex[u] != nex[v]) {\n            res.emplace_back(down[u],\
    \ down[nex[u]]);\n            u = par[nex[u]];\n        }\n        if(u != v)\
    \ res.emplace_back(down[u], down[v] + 1);\n        return res;\n    }\n    vector<pair<int,\
    \ int>> descend(int u, int v) const {\n        if(u == v) return {};\n       \
    \ if(nex[u] == nex[v]) return {{down[u] + 1, down[v]}};\n        auto res = descend(u,\
    \ par[nex[v]]);\n        res.emplace_back(down[nex[v]], down[v]);\n        return\
    \ res;\n    }\n};\n#line 3 \"src/data_structure/lazy_segment_tree.hpp\"\ntemplate\
    \ <typename S, auto op, auto e, typename F, auto mapping, auto composition, auto\
    \ id>\nstruct LazySegmentTree {\n    LazySegmentTree(int N)\n        : LazySegmentTree(vector<S>(N,\
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
    \        return op(sml, smr);\n    }\n    S all_prod() {\n        return data[1];\n\
    \    }\n    void apply(int l, int r, const F& f) {\n        assert(0 <= l and\
    \ l <= r and r <= n);\n        if(l == r) return;\n        l += size;\n      \
    \  r += size;\n        for(int i = log; i >= 1; --i) {\n            if(((l >>\
    \ i) << i) != l) push(l >> i);\n            if(((r >> i) << i) != r) push((r -\
    \ 1) >> i);\n        }\n        {\n            int l2 = l, r2 = r;\n         \
    \   while(l < r) {\n                if(l & 1) all_apply(l++, f);\n           \
    \     if(r & 1) all_apply(--r, f);\n                l >>= 1;\n               \
    \ r >>= 1;\n            }\n            l = l2;\n            r = r2;\n        }\n\
    \        for(int i = 1; i <= log; ++i) {\n            if(((l >> i) << i) != l)\
    \ update(l >> i);\n            if(((r >> i) << i) != r) update((r - 1) >> i);\n\
    \        }\n    }\n\n    template <bool (*g)(S)>\n    int max_right(int l) {\n\
    \        return max_right(l, [](const S& x) { return g(x); });\n    }\n    template\
    \ <class G>\n    int max_right(int l, const G& g) {\n        assert(0 <= l and\
    \ l <= n);\n        assert(g(e()));\n        if(l == n) return n;\n        l +=\
    \ size;\n        for(int i = log; i >= 1; --i) push(l >> i);\n        S sm = e();\n\
    \        do {\n            while(l % 2 == 0) l >>= 1;\n            if(!g(op(sm,\
    \ data[l]))) {\n                while(l < size) {\n                    push(l);\n\
    \                    l = 2 * l;\n                    if(g(op(sm, data[l]))) {\n\
    \                        sm = op(sm, data[l]);\n                        ++l;\n\
    \                    }\n                }\n                return l - size;\n\
    \            }\n            sm = op(sm, data[l]);\n            ++l;\n        }\
    \ while((l & -l) != l);\n        return n;\n    }\n\n    template <bool (*g)(S)>\n\
    \    int min_left(int r) {\n        return min_left(r, [](const S& x) { return\
    \ g(x); });\n    }\n    template <class G>\n    int min_left(int r, const G& g)\
    \ {\n        assert(0 <= r and r <= n);\n        assert(g(e()));\n        if(r\
    \ == 0) return 0;\n        r += size;\n        for(int i = log; i >= 1; --i) push((r\
    \ - 1) >> i);\n        S sm = e();\n        do {\n            --r;\n         \
    \   while(r > 1 and (r % 2)) r >>= 1;\n            if(!g(op(data[r], sm))) {\n\
    \                while(r < size) {\n                    push(r);\n           \
    \         r = 2 * r + 1;\n                    if(g(op(data[r], sm))) {\n     \
    \                   sm = op(data[r], sm);\n                        --r;\n    \
    \                }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = op(data[r], sm);\n        } while((r & -r) !=\
    \ r);\n        return 0;\n    }\n\n   private:\n    int n, size, log;\n    vector<S>\
    \ data;\n    vector<F> lazy;\n    inline void update(int k) {\n        data[k]\
    \ = op(data[2 * k], data[2 * k + 1]);\n    }\n    inline void all_apply(int k,\
    \ F f) {\n        data[k] = mapping(f, data[k]);\n        if(k < size) {\n   \
    \         lazy[k] = composition(f, lazy[k]);\n        }\n    }\n    inline void\
    \ push(int k) {\n        all_apply(2 * k, lazy[k]);\n        all_apply(2 * k +\
    \ 1, lazy[k]);\n        lazy[k] = id();\n    }\n    inline unsigned int bit_ceil(unsigned\
    \ int n) {\n        unsigned int res = 1;\n        while(res < n) res *= 2;\n\
    \        return res;\n    }\n    inline int countr_zero(unsigned int n) {\n  \
    \      return __builtin_ctz(n);\n    }\n};\n#line 6 \"verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp\"\
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
  timestamp: '2024-01-07 06:02:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp
- /verify/verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp.html
title: verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp
---