---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/segment_tree.hpp
    title: SegmentTree
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/template/static_modint.hpp
    title: StaticModint
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"verify/library_checker/data_structure/vertex_set_path_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/template/static_modint.hpp\"\ntemplate <uint32_t m>\nstruct StaticModint\
    \ {\n    using mint = StaticModint;\n    static constexpr uint32_t mod() {\n \
    \       return m;\n    }\n    static constexpr mint raw(uint32_t v) {\n      \
    \  mint a;\n        a._v = v;\n        return a;\n    }\n    constexpr StaticModint()\n\
    \        : _v(0) {}\n    template <class T>\n    constexpr StaticModint(const\
    \ T& v) {\n        static_assert(is_integral_v<T>);\n        if constexpr(is_signed_v<T>)\
    \ {\n            int64_t x = int64_t(v % int64_t(m));\n            if(x < 0) x\
    \ += m;\n            _v = uint32_t(x);\n        } else _v = uint32_t(v % m);\n\
    \    }\n    constexpr uint32_t val() const {\n        return _v;\n    }\n    constexpr\
    \ mint& operator++() {\n        return *this += 1;\n    }\n    constexpr mint&\
    \ operator--() {\n        return *this -= 1;\n    }\n    constexpr mint operator++(int)\
    \ {\n        mint res = *this;\n        ++*this;\n        return res;\n    }\n\
    \    constexpr mint operator--(int) {\n        mint res = *this;\n        --*this;\n\
    \        return res;\n    }\n    constexpr mint& operator+=(mint rhs) {\n    \
    \    if(_v >= m - rhs._v) _v -= m;\n        _v += rhs._v;\n        return *this;\n\
    \    }\n    constexpr mint& operator-=(mint rhs) {\n        if(_v < rhs._v) _v\
    \ += m;\n        _v -= rhs._v;\n        return *this;\n    }\n    constexpr mint&\
    \ operator*=(mint rhs) {\n        return *this = *this * rhs;\n    }\n    constexpr\
    \ mint& operator/=(mint rhs) {\n        return *this *= rhs.inv();\n    }\n  \
    \  constexpr mint operator+() const {\n        return *this;\n    }\n    constexpr\
    \ mint operator-() const {\n        return mint{} - *this;\n    }\n    constexpr\
    \ mint pow(long long n) const {\n        assert(0 <= n);\n        if(n == 0) return\
    \ 1;\n        mint x = *this, r = 1;\n        while(1) {\n            if(n & 1)\
    \ r *= x;\n            n >>= 1;\n            if(n == 0) return r;\n          \
    \  x *= x;\n        }\n    }\n    constexpr mint inv() const {\n        if constexpr(prime)\
    \ {\n            assert(_v);\n            return pow(m - 2);\n        } else {\n\
    \            auto eg = inv_gcd(_v, m);\n            assert(eg.first == 1);\n \
    \           return eg.second;\n        }\n    }\n    friend constexpr mint operator+(mint\
    \ lhs, mint rhs) {\n        return lhs += rhs;\n    }\n    friend constexpr mint\
    \ operator-(mint lhs, mint rhs) {\n        return lhs -= rhs;\n    }\n    friend\
    \ constexpr mint operator*(mint lhs, mint rhs) {\n        return uint64_t(lhs._v)\
    \ * rhs._v;\n    }\n    friend constexpr mint operator/(mint lhs, mint rhs) {\n\
    \        return lhs /= rhs;\n    }\n    friend constexpr bool operator==(mint\
    \ lhs, mint rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend constexpr\
    \ bool operator!=(mint lhs, mint rhs) {\n        return lhs._v != rhs._v;\n  \
    \  }\n    friend istream& operator>>(istream& in, mint& x) {\n        long long\
    \ a;\n        in >> a;\n        x = a;\n        return in;\n    }\n    friend\
    \ ostream& operator<<(ostream& out, const mint& x) {\n        return out << x.val();\n\
    \    }\n\n   private:\n    uint32_t _v = 0;\n    static constexpr bool prime =\
    \ []() -> bool {\n        if(m == 1) return 0;\n        if(m == 2 or m == 7 or\
    \ m == 61) return 1;\n        if(m % 2 == 0) return 0;\n        uint32_t d = m\
    \ - 1;\n        while(d % 2 == 0) d /= 2;\n        for(uint32_t a : {2, 7, 61})\
    \ {\n            uint32_t t = d;\n            mint y = mint(a).pow(t);\n     \
    \       while(t != m - 1 && y != 1 && y != m - 1) {\n                y *= y;\n\
    \                t <<= 1;\n            }\n            if(y != m - 1 && t % 2 ==\
    \ 0) return 0;\n        }\n        return 1;\n    }();\n    static constexpr pair<int32_t,\
    \ int32_t> inv_gcd(int32_t a, int32_t b) {\n        if(a == 0) return {b, 0};\n\
    \        int32_t s = b, t = a, m0 = 0, m1 = 1;\n        while(t) {\n         \
    \   const int32_t u = s / t;\n            s -= t * u;\n            m0 -= m1 *\
    \ u;\n            swap(s, t);\n            swap(m0, m1);\n        }\n        if(m0\
    \ < 0) m0 += b / s;\n        return {s, m0};\n    }\n};\nusing modint998244353\
    \ = StaticModint<998244353>;\nusing modint1000000007 = StaticModint<1000000007>;\n\
    #line 3 \"src/graph/graph_template.hpp\"\ntemplate <typename T>\nstruct Edge {\n\
    \    int from, to;\n    T cost;\n    int idx;\n    Edge()\n        : from(-1),\
    \ to(-1), cost(-1), idx(-1) {}\n    Edge(int from, int to, const T& cost = 1,\
    \ int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx) {}\n    operator\
    \ int() const {\n        return to;\n    }\n};\ntemplate <typename T>\nstruct\
    \ Graph {\n    Graph(int N)\n        : n(N), es(0), g(N) {}\n    int size() const\
    \ {\n        return n;\n    }\n    int edge_size() const {\n        return es;\n\
    \    }\n    void add_edge(int from, int to, const T& cost = 1) {\n        assert(0\
    \ <= from and from < n);\n        assert(0 <= to and to < n);\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n \
    \   void add_directed_edge(int from, int to, const T& cost = 1) {\n        assert(0\
    \ <= from and from < n);\n        assert(0 <= to and to < n);\n        g[from].emplace_back(from,\
    \ to, cost, es++);\n    }\n    inline vector<Edge<T>>& operator[](const int& k)\
    \ {\n        assert(0 <= k and k < n);\n        return g[k];\n    }\n    inline\
    \ const vector<Edge<T>>& operator[](const int& k) const {\n        assert(0 <=\
    \ k and k < n);\n        return g[k];\n    }\n\n   private:\n    int n, es;\n\
    \    vector<vector<Edge<T>>> g;\n};\ntemplate <typename T>\nusing Edges = vector<Edge<T>>;\n\
    #line 4 \"src/tree/heavy_light_decomposition.hpp\"\ntemplate <typename T>\nstruct\
    \ HeavyLightDecomposition {\n    HeavyLightDecomposition(Graph<T>& _g, int root\
    \ = 0)\n        : g(_g), n(g.size()), id(0), sz(n, 0), dep(n, 0), down(n, -1),\
    \ up(n, -1), nex(n, root), par(n, root), rev(n, 0) {\n        assert(0 <= root\
    \ and root < n);\n        dfs_sz(root);\n        dfs_hld(root);\n    }\n    pair<int,\
    \ int> idx(int i) const {\n        assert(0 <= i and i < n);\n        return make_pair(down[i],\
    \ up[i]);\n    }\n    int depth(int v) const {\n        assert(0 <= v and v <\
    \ n);\n        return dep[v];\n    }\n    int parent(int v) const {\n        assert(0\
    \ <= v and v < n);\n        return par[v];\n    }\n    int la(int v, int x) const\
    \ {\n        assert(0 <= v and v < n);\n        assert(x >= 0);\n        if(x\
    \ > dep[v]) return -1;\n        while(true) {\n            const int u = nex[v];\n\
    \            if(down[v] - x >= down[u]) return rev[down[v] - x];\n           \
    \ x -= down[v] - down[u] + 1;\n            v = par[u];\n        }\n    }\n   \
    \ int lca(int u, int v) const {\n        assert(0 <= u and u < n);\n        assert(0\
    \ <= v and v < n);\n        while(nex[u] != nex[v]) {\n            if(down[u]\
    \ < down[v]) swap(u, v);\n            u = par[nex[u]];\n        }\n        return\
    \ dep[u] < dep[v] ? u : v;\n    }\n    int dist(int u, int v) const {\n      \
    \  assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n        return\
    \ dep[u] + dep[v] - dep[lca(u, v)] * 2;\n    }\n    template <typename F>\n  \
    \  void path_query(int u, int v, bool vertex, const F& f) {\n        assert(0\
    \ <= u and u < n);\n        assert(0 <= v and v < n);\n        int l = lca(u,\
    \ v);\n        for(auto&& [a, b] : ascend(u, l)) f(a + 1, b);\n        if(vertex)\
    \ f(down[l], down[l] + 1);\n        for(auto&& [a, b] : descend(l, v)) f(a, b\
    \ + 1);\n    }\n    template <typename F>\n    void subtree_query(int v, bool\
    \ vertex, const F& f) {\n        assert(0 <= v and v < n);\n        f(down[v]\
    \ + int(!vertex), up[v]);\n    }\n\n   private:\n    Graph<T>& g;\n    int n,\
    \ id;\n    vector<int> sz, dep, down, up, nex, par, rev;\n    void dfs_sz(int\
    \ cur) {\n        sz[cur] = 1;\n        for(Edge<T>& edge : g[cur]) {\n      \
    \      if(edge.to == par[cur]) {\n                if(g[cur].size() >= 2 and edge.to\
    \ == g[cur][0].to) {\n                    swap(g[cur][0], g[cur][1]);\n      \
    \          } else {\n                    continue;\n                }\n      \
    \      }\n            dep[edge.to] = dep[cur] + 1;\n            par[edge.to] =\
    \ cur;\n            dfs_sz(edge.to);\n            sz[cur] += sz[edge.to];\n  \
    \          if(sz[edge.to] > sz[g[cur][0].to]) {\n                swap(edge, g[cur][0]);\n\
    \            }\n        }\n    }\n    void dfs_hld(int cur) {\n        down[cur]\
    \ = id++;\n        rev[down[cur]] = cur;\n        for(const Edge<T>& edge : g[cur])\
    \ {\n            if(edge.to == par[cur]) continue;\n            nex[edge.to] =\
    \ (edge.to == g[cur][0].to ? nex[cur] : edge.to);\n            dfs_hld(edge.to);\n\
    \        }\n        up[cur] = id;\n    }\n    vector<pair<int, int>> ascend(int\
    \ u, int v) const {\n        vector<pair<int, int>> res;\n        while(nex[u]\
    \ != nex[v]) {\n            res.emplace_back(down[u], down[nex[u]]);\n       \
    \     u = par[nex[u]];\n        }\n        if(u != v) res.emplace_back(down[u],\
    \ down[v] + 1);\n        return res;\n    }\n    vector<pair<int, int>> descend(int\
    \ u, int v) const {\n        if(u == v) return {};\n        if(nex[u] == nex[v])\
    \ return {{down[u] + 1, down[v]}};\n        auto res = descend(u, par[nex[v]]);\n\
    \        res.emplace_back(down[nex[v]], down[v]);\n        return res;\n    }\n\
    };\n#line 3 \"src/data_structure/segment_tree.hpp\"\ntemplate <typename S, auto\
    \ op, auto e>\nstruct SegmentTree {\n    SegmentTree(int N)\n        : SegmentTree(vector<S>(N,\
    \ e())) {}\n    SegmentTree(const vector<S>& v)\n        : n((int)v.size()) {\n\
    \        size = bit_ceil((unsigned int)n);\n        log = countr_zero((unsigned\
    \ int)size);\n        data = vector<S>(2 * size, e());\n        for(int i = 0;\
    \ i < n; ++i) {\n            data[size + i] = v[i];\n        }\n        for(int\
    \ i = size - 1; i >= 1; --i) {\n            update(i);\n        }\n    }\n   \
    \ void set(int p, const S& x) {\n        assert(0 <= p and p < n);\n        p\
    \ += size;\n        data[p] = x;\n        for(int i = 1; i <= log; ++i) {\n  \
    \          update(p >> i);\n        }\n    }\n    S get(int p) const {\n     \
    \   assert(0 <= p and p < n);\n        return data[p + size];\n    }\n    S prod(int\
    \ l, int r) const {\n        assert(0 <= l and l <= r and r <= n);\n        S\
    \ sml = e(), smr = e();\n        l += size;\n        r += size;\n        while(l\
    \ < r) {\n            if(l & 1) sml = op(sml, data[l++]);\n            if(r &\
    \ 1) smr = op(data[--r], smr);\n            l >>= 1;\n            r >>= 1;\n \
    \       }\n        return op(sml, smr);\n    }\n    S all_prod() const {\n   \
    \     return data[1];\n    }\n\n    template <bool (*f)(S)>\n    int max_right(int\
    \ l) const {\n        return max_right(l, [](const S& x) { return f(x); });\n\
    \    }\n    template <class F>\n    int max_right(int l, const F& f) const {\n\
    \        assert(0 <= l and l <= n);\n        assert(f(e()));\n        if(l ==\
    \ n) return n;\n        l += size;\n        S sm = e();\n        do {\n      \
    \      while(l % 2 == 0) l >>= 1;\n            if(!f(op(sm, data[l]))) {\n   \
    \             while(l < size) {\n                    l = l * 2;\n            \
    \        if(f(op(sm, data[l]))) {\n                        sm = op(sm, data[l]);\n\
    \                        ++l;\n                    }\n                }\n    \
    \            return l - size;\n            }\n            sm = op(sm, data[l]);\n\
    \            ++l;\n        } while((l & -l) != l);\n        return n;\n    }\n\
    \n    template <bool (*f)(S)>\n    int min_left(int r) const {\n        return\
    \ min_left(r, [](const S& x) { return f(x); });\n    }\n    template <class F>\n\
    \    int min_left(int r, const F& f) const {\n        assert(0 <= r and r <= n);\n\
    \        assert(f(e()));\n        if(r == 0) return 0;\n        r += size;\n \
    \       S sm = e();\n        do {\n            --r;\n            while(r > 1 and\
    \ (r % 2)) r >>= 1;\n            if(!f(op(data[r], sm))) {\n                while(r\
    \ < size) {\n                    r = 2 * r + 1;\n                    if(f(op(data[r],\
    \ sm))) {\n                        sm = op(data[r], sm);\n                   \
    \     --r;\n                    }\n                }\n                return r\
    \ + 1 - size;\n            }\n            sm = op(data[r], sm);\n        } while((r\
    \ & -r) != r);\n        return 0;\n    }\n\n   private:\n    int n, size, log;\n\
    \    vector<S> data;\n    inline void update(int k) {\n        data[k] = op(data[2\
    \ * k], data[2 * k + 1]);\n    }\n    inline unsigned int bit_ceil(unsigned int\
    \ n) {\n        unsigned int res = 1;\n        while(res < n) res *= 2;\n    \
    \    return res;\n    }\n    inline int countr_zero(unsigned int n) {\n      \
    \  return __builtin_ctz(n);\n    }\n};\n#line 7 \"verify/library_checker/data_structure/vertex_set_path_composite.test.cpp\"\
    \nusing mint = modint998244353;\nstruct S {\n    mint a, b;\n};\nS op1(S x, S\
    \ y) {\n    return {x.a * y.a, x.b * y.a + y.b};\n}\nS op2(S x, S y) {\n    return\
    \ {x.a * y.a, y.b * x.a + x.b};\n}\nS e() {\n    return {1, 0};\n}\nint main(void)\
    \ {\n    int n, q;\n    cin >> n >> q;\n    vector<ll> a(n), b(n);\n    rep(i,\
    \ 0, n) {\n        cin >> a[i] >> b[i];\n    }\n    Graph<int> g(n);\n    rep(i,\
    \ 0, n - 1) {\n        int u, v;\n        cin >> u >> v;\n        g.add_edge(u,\
    \ v);\n    }\n    HeavyLightDecomposition<int> hld(g);\n    SegmentTree<S, op1,\
    \ e> seg1(n);\n    SegmentTree<S, op2, e> seg2(n);\n    rep(i, 0, n) {\n     \
    \   seg1.set(hld.idx(i).first, {a[i], b[i]});\n        seg2.set(hld.idx(i).first,\
    \ {a[i], b[i]});\n    }\n    while(q--) {\n        int t;\n        cin >> t;\n\
    \        if(t == 0) {\n            int p;\n            mint c, d;\n          \
    \  cin >> p >> c >> d;\n            seg1.set(hld.idx(p).first, {c, d});\n    \
    \        seg2.set(hld.idx(p).first, {c, d});\n        } else {\n            int\
    \ u, v;\n            mint x;\n            cin >> u >> v >> x;\n            mint\
    \ ans = x;\n            auto query = [&](int u, int v) -> void {\n           \
    \     if(u <= v) {\n                    S res = seg1.prod(u, v);\n           \
    \         ans = res.a * ans + res.b;\n                } else {\n             \
    \       S res = seg2.prod(v, u);\n                    ans = res.a * ans + res.b;\n\
    \                }\n            };\n            hld.path_query(u, v, true, query);\n\
    \            cout << ans << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/template/static_modint.hpp\"\
    \n#include \"../../../src/graph/graph_template.hpp\"\n#include \"../../../src/tree/heavy_light_decomposition.hpp\"\
    \n#include \"../../../src/data_structure/segment_tree.hpp\"\nusing mint = modint998244353;\n\
    struct S {\n    mint a, b;\n};\nS op1(S x, S y) {\n    return {x.a * y.a, x.b\
    \ * y.a + y.b};\n}\nS op2(S x, S y) {\n    return {x.a * y.a, y.b * x.a + x.b};\n\
    }\nS e() {\n    return {1, 0};\n}\nint main(void) {\n    int n, q;\n    cin >>\
    \ n >> q;\n    vector<ll> a(n), b(n);\n    rep(i, 0, n) {\n        cin >> a[i]\
    \ >> b[i];\n    }\n    Graph<int> g(n);\n    rep(i, 0, n - 1) {\n        int u,\
    \ v;\n        cin >> u >> v;\n        g.add_edge(u, v);\n    }\n    HeavyLightDecomposition<int>\
    \ hld(g);\n    SegmentTree<S, op1, e> seg1(n);\n    SegmentTree<S, op2, e> seg2(n);\n\
    \    rep(i, 0, n) {\n        seg1.set(hld.idx(i).first, {a[i], b[i]});\n     \
    \   seg2.set(hld.idx(i).first, {a[i], b[i]});\n    }\n    while(q--) {\n     \
    \   int t;\n        cin >> t;\n        if(t == 0) {\n            int p;\n    \
    \        mint c, d;\n            cin >> p >> c >> d;\n            seg1.set(hld.idx(p).first,\
    \ {c, d});\n            seg2.set(hld.idx(p).first, {c, d});\n        } else {\n\
    \            int u, v;\n            mint x;\n            cin >> u >> v >> x;\n\
    \            mint ans = x;\n            auto query = [&](int u, int v) -> void\
    \ {\n                if(u <= v) {\n                    S res = seg1.prod(u, v);\n\
    \                    ans = res.a * ans + res.b;\n                } else {\n  \
    \                  S res = seg2.prod(v, u);\n                    ans = res.a *\
    \ ans + res.b;\n                }\n            };\n            hld.path_query(u,\
    \ v, true, query);\n            cout << ans << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/static_modint.hpp
  - src/graph/graph_template.hpp
  - src/tree/heavy_light_decomposition.hpp
  - src/data_structure/segment_tree.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 17:21:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/vertex_set_path_composite.test.cpp
- /verify/verify/library_checker/data_structure/vertex_set_path_composite.test.cpp.html
title: verify/library_checker/data_structure/vertex_set_path_composite.test.cpp
---
