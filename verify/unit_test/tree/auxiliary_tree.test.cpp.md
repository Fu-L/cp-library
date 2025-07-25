---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/random/random_number_generator.hpp
    title: RandomNumberGenerator
  - icon: ':heavy_check_mark:'
    path: src/template/static_modint.hpp
    title: StaticModint
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  - icon: ':heavy_check_mark:'
    path: src/tree/auxiliary_tree.hpp
    title: AuxiliaryTree
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/tree/auxiliary_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ P = pair<long long, long long>;\n#define rep(i, a, b) for(long long i = (a);\
    \ i < (b); ++i)\n#define rrep(i, a, b) for(long long i = (a); i >= (b); --i)\n\
    constexpr long long inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/random/random_number_generator.hpp\"\nstruct RandomNumberGenerator\
    \ {\n    RandomNumberGenerator()\n        : mt(chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    template <typename T>\n    inline T operator()(const T lower, const\
    \ T upper) {\n        static_assert(is_integral_v<T> or is_floating_point_v<T>);\n\
    \        assert(lower <= upper);\n        if constexpr(is_integral_v<T>) {\n \
    \           uniform_int_distribution<T> dist(lower, upper);\n            return\
    \ dist(mt);\n        } else if constexpr(is_floating_point_v<T>) {\n         \
    \   uniform_real_distribution<T> dist(lower, upper);\n            return dist(mt);\n\
    \        }\n    }\n    template <typename T>\n    inline vector<T> vec(const int\
    \ n, const T lower, const T upper, const bool dup = true) {\n        static_assert(is_integral_v<T>\
    \ or is_floating_point_v<T>);\n        assert(0 <= n and n <= (int)1e8);\n   \
    \     assert(lower <= upper);\n        if(n == 0) return {};\n        vector<T>\
    \ res(n);\n        if(dup or is_floating_point_v<T>) {\n            for(int i\
    \ = 0; i < n; ++i) res[i] = this->operator()(lower, upper);\n        } else {\n\
    \            assert(upper - lower + 1 >= n);\n            if(upper - lower + 1\
    \ >= 2 * n) {\n                set<T> used;\n                while((int)used.size()\
    \ < n) {\n                    const T a = this->operator()(lower, upper);\n  \
    \                  used.insert(a);\n                }\n                int i =\
    \ 0;\n                for(const T a : used) {\n                    res[i] = a;\n\
    \                    ++i;\n                }\n            } else {\n         \
    \       const vector<int> p = perm(upper - lower + 1, false);\n              \
    \  for(int i = 0; i < n; ++i) {\n                    res[i] = p[i] + lower;\n\
    \                }\n            }\n        }\n        return res;\n    }\n   \
    \ inline vector<int> perm(const int n, const bool one = true) {\n        assert(0\
    \ <= n and n <= (int)1e8);\n        vector<int> res(n);\n        for(int i = 0;\
    \ i < n; ++i) res[i] = i + one;\n        for(int i = n - 1; i > 0; --i) {\n  \
    \          swap(res[i], res[this->operator()(0, i)]);\n        }\n        return\
    \ res;\n    }\n    inline pair<vector<int>, vector<int>> tree(const int n, const\
    \ bool one = true) {\n        assert(0 <= n and n <= (int)1e8);\n        if(n\
    \ <= 1) return {{}, {}};\n        if(n == 2) return {{0 + one}, {1 + one}};\n\
    \        vector<int> u(n - 1), v(n - 1);\n        const vector<int> pruefer =\
    \ vec(n - 2, 0, n - 1);\n        set<int> st;\n        vector<int> cnt(n);\n \
    \       for(int i = 0; i < n; ++i) st.insert(i);\n        auto add = [&](const\
    \ int x) -> void {\n            if(x > n) return;\n            if(cnt[x] == 0)\
    \ st.erase(x);\n            ++cnt[x];\n        };\n        auto del = [&](const\
    \ int x) -> void {\n            if(x > n) return;\n            --cnt[x];\n   \
    \         if(cnt[x] == 0) st.insert(x);\n        };\n        for(int i = 0; i\
    \ < n - 2; ++i) add(pruefer[i]);\n        for(int i = 0; i < n - 2; ++i) {\n \
    \           const int a = *st.begin();\n            const int b = pruefer[i];\n\
    \            u[i] = a + one;\n            v[i] = b + one;\n            del(b);\n\
    \            add(a);\n        }\n        const int a = *st.begin();\n        add(a);\n\
    \        const int b = *st.begin();\n        u[n - 2] = a + one;\n        v[n\
    \ - 2] = b + one;\n        return {u, v};\n    }\n    template <typename T>\n\
    \    inline tuple<vector<int>, vector<int>, vector<T>> weighted_tree(const int\
    \ n, const T lower, const T upper, const bool one = true) {\n        static_assert(is_integral_v<T>\
    \ or is_floating_point_v<T>);\n        assert(0 <= n and n <= (int)1e8);\n   \
    \     assert(lower <= upper);\n        if(n == 0) return {{}, {}, {}};\n     \
    \   const auto [u, v] = tree(n, one);\n        const vector<T> w = vec(n - 1,\
    \ lower, upper, true);\n        return {u, v, w};\n    }\n    inline pair<vector<int>,\
    \ vector<int>> graph(const int n, const int m, const bool one = true) {\n    \
    \    assert(0 <= n and n <= (int)1e8);\n        assert(0 <= m and m <= (int)min((ll)1e8,\
    \ 1ll * n * (n - 1) / 2));\n        vector<int> u, v;\n        u.reserve(m);\n\
    \        v.reserve(m);\n        if(1ll * n * (n - 1) / 2 >= 2e6) {\n         \
    \   set<pair<int, int>> edge;\n            while((int)edge.size() < m) {\n   \
    \             const int a = this->operator()(0, n - 1);\n                const\
    \ int b = this->operator()(0, n - 1);\n                if(a >= b) continue;\n\
    \                edge.insert({a, b});\n            }\n            for(const auto&\
    \ [a, b] : edge) {\n                u.push_back(a + one);\n                v.push_back(b\
    \ + one);\n            }\n        } else {\n            vector<pair<int, int>>\
    \ edge;\n            edge.reserve(n * (n - 1) / 2);\n            for(int i = 0;\
    \ i < n; ++i) {\n                for(int j = i + 1; j < n; ++j) {\n          \
    \          edge.push_back({i, j});\n                }\n            }\n       \
    \     const vector<int> p = perm(n * (n - 1) / 2, false);\n            for(int\
    \ i = 0; i < m; ++i) {\n                u.push_back(edge[p[i]].first + one);\n\
    \                v.push_back(edge[p[i]].second + one);\n            }\n      \
    \  }\n        return {u, v};\n    }\n    template <typename T>\n    inline tuple<vector<int>,\
    \ vector<int>, vector<T>> weighted_graph(const int n, const int m, const T lower,\
    \ const T upper, const bool one = true) {\n        static_assert(is_integral_v<T>\
    \ or is_floating_point_v<T>);\n        assert(0 <= n and n <= (int)1e8);\n   \
    \     assert(0 <= m and m <= (int)min((ll)1e8, 1ll * n * (n - 1) / 2));\n    \
    \    assert(lower <= upper);\n        const auto [u, v] = graph(n, m, one);\n\
    \        const vector<T> w = vec(m, lower, upper, true);\n        return {u, v,\
    \ w};\n    }\n    inline pair<vector<int>, vector<int>> connected_graph(const\
    \ int n, const int m, const bool one = true) {\n        assert(0 <= n and n <=\
    \ (int)1e8);\n        assert(max(n - 1, 0) <= m and m <= (int)min((ll)1e8, 1ll\
    \ * n * (n - 1) / 2));\n        if(n <= 1) return {{}, {}};\n        vector<int>\
    \ u, v;\n        u.reserve(m);\n        v.reserve(m);\n        auto [ut, vt] =\
    \ tree(n, false);\n        if(1ll * n * (n - 1) / 2 >= 2e6) {\n            set<pair<int,\
    \ int>> edge;\n            for(int i = 0; i < n - 1; ++i) {\n                edge.insert({min(ut[i],\
    \ vt[i]), max(ut[i], vt[i])});\n            }\n            while((int)edge.size()\
    \ < m) {\n                const int a = this->operator()(0, n - 1);\n        \
    \        const int b = this->operator()(0, n - 1);\n                if(a >= b)\
    \ continue;\n                edge.insert({a, b});\n            }\n           \
    \ for(const auto& [a, b] : edge) {\n                u.push_back(a + one);\n  \
    \              v.push_back(b + one);\n            }\n        } else {\n      \
    \      set<pair<int, int>> used;\n            for(int i = 0; i < n - 1; ++i) {\n\
    \                u.push_back(ut[i] + one);\n                v.push_back(vt[i]\
    \ + one);\n                used.insert({min(ut[i], vt[i]), max(ut[i], vt[i])});\n\
    \            }\n            vector<pair<int, int>> edge;\n            edge.reserve(n\
    \ * (n - 1) / 2 - (n - 1));\n            for(int i = 0; i < n; ++i) {\n      \
    \          for(int j = i + 1; j < n; ++j) {\n                    if(used.find({i,\
    \ j}) == used.end()) edge.push_back({i, j});\n                }\n            }\n\
    \            const vector<int> p = perm(n * (n - 1) / 2 - (n - 1), false);\n \
    \           for(int i = 0; i < m - (n - 1); ++i) {\n                u.push_back(edge[p[i]].first\
    \ + one);\n                v.push_back(edge[p[i]].second + one);\n           \
    \ }\n        }\n        return {u, v};\n    }\n    template <typename T>\n   \
    \ inline tuple<vector<int>, vector<int>, vector<T>> weighted_connected_graph(const\
    \ int n, const int m, const T lower, const T upper, const bool one = true) {\n\
    \        static_assert(is_integral_v<T> or is_floating_point_v<T>);\n        assert(0\
    \ <= n and n <= (int)1e8);\n        assert(max(n - 1, 0) <= m and m <= (int)min((ll)1e8,\
    \ 1ll * n * (n - 1) / 2));\n        assert(lower <= upper);\n        const auto\
    \ [u, v] = connected_graph(n, m, one);\n        const vector<T> w = vec(m, lower,\
    \ upper, true);\n        return {u, v, w};\n    }\n    inline string parenthesis(const\
    \ int n) {\n        assert(0 <= n and n <= 1e8);\n        string res = \"\";\n\
    \        int N = n, M = n;\n        for(int i = 0; i < 2 * n; ++i) {\n       \
    \     if(this->operator()(0.0l, 1.0l) > 1.0l * (N - M) * (N + 1) / ((N - M + 1)\
    \ * (N + M))) {\n                res += \"(\";\n                --M;\n       \
    \     } else {\n                res += \")\";\n                --N;\n        \
    \    }\n        }\n        return res;\n    }\n\n   private:\n    mt19937_64 mt;\n\
    } rng;\n#line 3 \"src/template/static_modint.hpp\"\ntemplate <uint32_t m>\nstruct\
    \ StaticModint {\n    using mint = StaticModint;\n    static constexpr uint32_t\
    \ mod() {\n        return m;\n    }\n    static constexpr mint raw(const uint32_t\
    \ v) {\n        mint a;\n        a._v = v;\n        return a;\n    }\n    constexpr\
    \ StaticModint()\n        : _v(0) {}\n    template <class T>\n    constexpr StaticModint(const\
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
    \            const auto eg = inv_gcd(_v, m);\n            assert(eg.first == 1);\n\
    \            return eg.second;\n        }\n    }\n    friend constexpr mint operator+(mint\
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
    \ int32_t> inv_gcd(const int32_t a, const int32_t b) {\n        if(a == 0) return\
    \ {b, 0};\n        int32_t s = b, t = a, m0 = 0, m1 = 1;\n        while(t) {\n\
    \            const int32_t u = s / t;\n            s -= t * u;\n            m0\
    \ -= m1 * u;\n            swap(s, t);\n            swap(m0, m1);\n        }\n\
    \        if(m0 < 0) m0 += b / s;\n        return {s, m0};\n    }\n};\nusing modint998244353\
    \ = StaticModint<998244353>;\nusing modint1000000007 = StaticModint<1000000007>;\n\
    #line 5 \"verify/unit_test/tree/auxiliary_tree.test.cpp\"\nusing mint = modint998244353;\n\
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
    };\n#line 5 \"src/tree/auxiliary_tree.hpp\"\ntemplate <typename T>\nstruct AuxiliaryTree\
    \ {\n    AuxiliaryTree(const Graph<T>& _g, const int root = 0)\n        : g(_g),\
    \ hld(g, root) {}\n    pair<Graph<int>, vector<int>> get(vector<int> idx) {\n\
    \        if(idx.empty()) return {Graph<int>(0), {}};\n        auto comp = [&](const\
    \ int i, const int j) {\n            return hld.idx(i).first < hld.idx(j).first;\n\
    \        };\n        sort(begin(idx), end(idx), comp);\n        for(int i = 0,\
    \ ie = idx.size(); i + 1 < ie; ++i) {\n            idx.push_back(hld.lca(idx[i],\
    \ idx[i + 1]));\n        }\n        sort(begin(idx), end(idx), comp);\n      \
    \  idx.erase(unique(begin(idx), end(idx)), end(idx));\n        Graph<int> aux(idx.size());\n\
    \        vector<int> rs;\n        rs.push_back(0);\n        for(int i = 1; i <\
    \ (int)idx.size(); ++i) {\n            const int l = hld.lca(idx[rs.back()], idx[i]);\n\
    \            while(idx[rs.back()] != l) rs.pop_back();\n            aux.add_directed_edge(rs.back(),\
    \ i);\n            rs.push_back(i);\n        }\n        return make_pair(aux,\
    \ idx);\n    }\n\n   private:\n    Graph<T> g;\n    HeavyLightDecomposition<T>\
    \ hld;\n};\n#line 8 \"verify/unit_test/tree/auxiliary_tree.test.cpp\"\n// ABC340-G\n\
    void test() {\n    int n = rng(1, 500);\n    int ma = rng(1, n);\n    vector<int>\
    \ a = rng.vec(n, 1, ma, true);\n    auto [u, v] = rng.tree(n, true);\n    auto\
    \ brute = [&](int n, vector<int> a, vector<int> u, vector<int> v) -> mint {\n\
    \        rep(i, 0, n) {\n            a[i]--;\n        }\n        Graph<int> g(n);\n\
    \        rep(i, 0, n - 1) {\n            u[i]--;\n            v[i]--;\n      \
    \      g.add_edge(u[i], v[i]);\n        }\n        mint ans = 0;\n        rep(i,\
    \ 0, n) {\n            map<int, mint> dp1, dp2;\n            auto dfs = [&](auto&\
    \ dfs, int cur, int p) -> void {\n                dp1[cur] = 1;\n            \
    \    dp2[cur] = 1;\n                for(const auto& e : g[cur]) {\n          \
    \          if(e.to == p) continue;\n                    dfs(dfs, e.to, cur);\n\
    \                    dp1[cur] *= dp2[e.to] + 1;\n                    dp2[cur]\
    \ *= dp2[e.to] + 1;\n                }\n                if(a[cur] != i) {\n  \
    \                  for(const auto& e : g[cur]) {\n                        if(e.to\
    \ == p) continue;\n                        dp1[cur] -= dp2[e.to];\n          \
    \          }\n                    dp1[cur]--;\n                    dp2[cur]--;\n\
    \                }\n                ans += dp1[cur];\n            };\n       \
    \     dfs(dfs, 0, -1);\n        }\n        return ans;\n    };\n    auto fast\
    \ = [&](int n, vector<int> a, vector<int> u, vector<int> v) -> mint {\n      \
    \  vector<vector<int>> col(n);\n        rep(i, 0, n) {\n            a[i]--;\n\
    \            col[a[i]].push_back(i);\n        }\n        Graph<int> g(n);\n  \
    \      rep(i, 0, n - 1) {\n            u[i]--;\n            v[i]--;\n        \
    \    g.add_edge(u[i], v[i]);\n        }\n        AuxiliaryTree<int> aux(g);\n\
    \        mint ans = 0;\n        rep(i, 0, n) {\n            if(col[i].empty())\
    \ continue;\n            auto [tree, idx] = aux.get(col[i]);\n            map<int,\
    \ mint> dp1, dp2;\n            auto dfs = [&](auto& dfs, int cur, int p) -> void\
    \ {\n                dp1[cur] = 1;\n                dp2[cur] = 1;\n          \
    \      for(const auto& e : tree[cur]) {\n                    if(e.to == p) continue;\n\
    \                    dfs(dfs, e.to, cur);\n                    dp1[cur] *= dp2[e.to]\
    \ + 1;\n                    dp2[cur] *= dp2[e.to] + 1;\n                }\n  \
    \              if(a[idx[cur]] != i) {\n                    for(const auto& e :\
    \ tree[cur]) {\n                        if(e.to == p) continue;\n            \
    \            dp1[cur] -= dp2[e.to];\n                    }\n                 \
    \   dp1[cur]--;\n                    dp2[cur]--;\n                }\n        \
    \        ans += dp1[cur];\n            };\n            dfs(dfs, 0, -1);\n    \
    \    }\n        return ans;\n    };\n    assert(brute(n, a, u, v) == fast(n, a,\
    \ u, v));\n}\nint main(void) {\n    constexpr int test_num = 100;\n    rep(i,\
    \ 0, test_num) {\n        test();\n    }\n    int a, b;\n    cin >> a >> b;\n\
    \    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/random/random_number_generator.hpp\"\n#include \"../../../src/template/static_modint.hpp\"\
    \nusing mint = modint998244353;\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/tree/auxiliary_tree.hpp\"\n// ABC340-G\nvoid test()\
    \ {\n    int n = rng(1, 500);\n    int ma = rng(1, n);\n    vector<int> a = rng.vec(n,\
    \ 1, ma, true);\n    auto [u, v] = rng.tree(n, true);\n    auto brute = [&](int\
    \ n, vector<int> a, vector<int> u, vector<int> v) -> mint {\n        rep(i, 0,\
    \ n) {\n            a[i]--;\n        }\n        Graph<int> g(n);\n        rep(i,\
    \ 0, n - 1) {\n            u[i]--;\n            v[i]--;\n            g.add_edge(u[i],\
    \ v[i]);\n        }\n        mint ans = 0;\n        rep(i, 0, n) {\n         \
    \   map<int, mint> dp1, dp2;\n            auto dfs = [&](auto& dfs, int cur, int\
    \ p) -> void {\n                dp1[cur] = 1;\n                dp2[cur] = 1;\n\
    \                for(const auto& e : g[cur]) {\n                    if(e.to ==\
    \ p) continue;\n                    dfs(dfs, e.to, cur);\n                   \
    \ dp1[cur] *= dp2[e.to] + 1;\n                    dp2[cur] *= dp2[e.to] + 1;\n\
    \                }\n                if(a[cur] != i) {\n                    for(const\
    \ auto& e : g[cur]) {\n                        if(e.to == p) continue;\n     \
    \                   dp1[cur] -= dp2[e.to];\n                    }\n          \
    \          dp1[cur]--;\n                    dp2[cur]--;\n                }\n \
    \               ans += dp1[cur];\n            };\n            dfs(dfs, 0, -1);\n\
    \        }\n        return ans;\n    };\n    auto fast = [&](int n, vector<int>\
    \ a, vector<int> u, vector<int> v) -> mint {\n        vector<vector<int>> col(n);\n\
    \        rep(i, 0, n) {\n            a[i]--;\n            col[a[i]].push_back(i);\n\
    \        }\n        Graph<int> g(n);\n        rep(i, 0, n - 1) {\n           \
    \ u[i]--;\n            v[i]--;\n            g.add_edge(u[i], v[i]);\n        }\n\
    \        AuxiliaryTree<int> aux(g);\n        mint ans = 0;\n        rep(i, 0,\
    \ n) {\n            if(col[i].empty()) continue;\n            auto [tree, idx]\
    \ = aux.get(col[i]);\n            map<int, mint> dp1, dp2;\n            auto dfs\
    \ = [&](auto& dfs, int cur, int p) -> void {\n                dp1[cur] = 1;\n\
    \                dp2[cur] = 1;\n                for(const auto& e : tree[cur])\
    \ {\n                    if(e.to == p) continue;\n                    dfs(dfs,\
    \ e.to, cur);\n                    dp1[cur] *= dp2[e.to] + 1;\n              \
    \      dp2[cur] *= dp2[e.to] + 1;\n                }\n                if(a[idx[cur]]\
    \ != i) {\n                    for(const auto& e : tree[cur]) {\n            \
    \            if(e.to == p) continue;\n                        dp1[cur] -= dp2[e.to];\n\
    \                    }\n                    dp1[cur]--;\n                    dp2[cur]--;\n\
    \                }\n                ans += dp1[cur];\n            };\n       \
    \     dfs(dfs, 0, -1);\n        }\n        return ans;\n    };\n    assert(brute(n,\
    \ a, u, v) == fast(n, a, u, v));\n}\nint main(void) {\n    constexpr int test_num\
    \ = 100;\n    rep(i, 0, test_num) {\n        test();\n    }\n    int a, b;\n \
    \   cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/random/random_number_generator.hpp
  - src/template/static_modint.hpp
  - src/graph/graph_template.hpp
  - src/tree/auxiliary_tree.hpp
  - src/tree/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: verify/unit_test/tree/auxiliary_tree.test.cpp
  requiredBy: []
  timestamp: '2025-07-25 17:08:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/tree/auxiliary_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/tree/auxiliary_tree.test.cpp
- /verify/verify/unit_test/tree/auxiliary_tree.test.cpp.html
title: verify/unit_test/tree/auxiliary_tree.test.cpp
---
