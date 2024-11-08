---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/graph/bipartite.hpp
    title: bipartite
  - icon: ':question:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':question:'
    path: src/template/random_number_generator.hpp
    title: RandomNumberGenerator
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  - icon: ':question:'
    path: src/tree/lowest_common_ancestor.hpp
    title: LowestCommonAncestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/graph/bipartite.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i,\
    \ a, b) for(ll i = a; i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n\
    \    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n    \
    \    cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/template/random_number_generator.hpp\"\
    \nstruct RandomNumberGenerator {\n    mt19937_64 mt;\n    RandomNumberGenerator()\n\
    \        : mt(chrono::steady_clock::now().time_since_epoch().count()) {}\n   \
    \ inline ll operator()(const ll lower, const ll upper) {\n        assert(lower\
    \ <= upper);\n        return num(lower, upper);\n    }\n    inline ll num(const\
    \ ll lower, const ll upper) {\n        assert(lower <= upper);\n        uniform_int_distribution<ll>\
    \ dist(lower, upper);\n        return dist(mt);\n    }\n    inline long double\
    \ rnum(const long double lower, const long double upper) {\n        uniform_real_distribution<long\
    \ double> dist(lower, upper);\n        return dist(mt);\n    }\n    inline vector<ll>\
    \ vec(const int n, const ll lower, const ll upper, const bool dup = true) {\n\
    \        assert(1 <= n and n <= (int)1e8);\n        assert(lower <= upper);\n\
    \        vector<ll> res(n);\n        if(dup) {\n            for(int i = 0; i <\
    \ n; ++i) res[i] = num(lower, upper);\n        } else {\n            assert(upper\
    \ - lower + 1 >= n);\n            if(upper - lower + 1 >= 2 * n) {\n         \
    \       set<ll> used;\n                while((int)used.size() < n) {\n       \
    \             ll a = num(lower, upper);\n                    used.insert(a);\n\
    \                }\n                int i = 0;\n                for(ll a : used)\
    \ {\n                    res[i] = a;\n                    ++i;\n             \
    \   }\n            } else {\n                vector<int> p = perm(upper - lower\
    \ + 1, false);\n                for(int i = 0; i < n; ++i) {\n               \
    \     res[i] = p[i] + lower;\n                }\n            }\n        }\n  \
    \      return res;\n    }\n    inline vector<long double> rvec(const int n, const\
    \ long double lower, const long double upper) {\n        assert(1 <= n and n <=\
    \ (int)1e8);\n        vector<long double> res(n);\n        for(int i = 0; i <\
    \ n; ++i) res[i] = rnum(lower, upper);\n        return res;\n    }\n    inline\
    \ vector<int> perm(const int n, const bool one = true) {\n        assert(1 <=\
    \ n and n <= (int)1e8);\n        vector<int> res(n);\n        for(int i = 0; i\
    \ < n; ++i) res[i] = i + one;\n        for(int i = n - 1; i > 0; --i) {\n    \
    \        swap(res[i], res[num(0, i)]);\n        }\n        return res;\n    }\n\
    \    inline pair<vector<int>, vector<int>> tree(const int n, const bool one =\
    \ true) {\n        assert(1 <= n and n <= (int)1e8);\n        if(n == 1) return\
    \ {{}, {}};\n        if(n == 2) return {{0 + one}, {1 + one}};\n        vector<int>\
    \ u(n - 1), v(n - 1);\n        vector<ll> pruefer = vec(n - 2, 0, n - 1);\n  \
    \      set<int> st;\n        vector<int> cnt(n);\n        for(int i = 0; i < n;\
    \ ++i) st.insert(i);\n        auto add = [&](int x) -> void {\n            if(x\
    \ > n) return;\n            if(cnt[x] == 0) st.erase(x);\n            ++cnt[x];\n\
    \        };\n        auto del = [&](int x) -> void {\n            if(x > n) return;\n\
    \            --cnt[x];\n            if(cnt[x] == 0) st.insert(x);\n        };\n\
    \        for(int i = 0; i < n - 2; ++i) add(pruefer[i]);\n        for(int i =\
    \ 0; i < n - 2; ++i) {\n            int a = *st.begin();\n            int b =\
    \ pruefer[i];\n            u[i] = a + one;\n            v[i] = b + one;\n    \
    \        del(b);\n            add(a);\n        }\n        int a = *st.begin();\n\
    \        add(a);\n        int b = *st.begin();\n        u[n - 2] = a + one;\n\
    \        v[n - 2] = b + one;\n        return {u, v};\n    }\n    inline tuple<vector<int>,\
    \ vector<int>, vector<int>> weighted_tree(const int n, const int lower, const\
    \ int upper, const bool one = true) {\n        assert(1 <= n and n <= (int)1e8);\n\
    \        assert(lower <= upper);\n        auto [u, v] = tree(n, one);\n      \
    \  vector<int> w(n - 1);\n        for(int i = 0; i < n - 1; ++i) w[i] = num(lower,\
    \ upper);\n        return {u, v, w};\n    }\n    inline pair<vector<int>, vector<int>>\
    \ graph(const int n, const int m, const bool one = true) {\n        assert(1 <=\
    \ n and n <= (int)1e8);\n        assert(1 <= m and m <= (int)min((ll)1e8, 1ll\
    \ * n * (n - 1) / 2));\n        vector<int> u, v;\n        u.reserve(m);\n   \
    \     v.reserve(m);\n        if(1ll * n * (n - 1) / 2 >= 2e6) {\n            set<pair<int,\
    \ int>> edge;\n            while((int)edge.size() < m) {\n                int\
    \ a = num(0, n - 1);\n                int b = num(0, n - 1);\n               \
    \ if(a >= b) continue;\n                edge.insert({a, b});\n            }\n\
    \            for(auto& [a, b] : edge) {\n                u.push_back(a + one);\n\
    \                v.push_back(b + one);\n            }\n        } else {\n    \
    \        vector<pair<int, int>> edge;\n            edge.reserve(n * (n - 1) /\
    \ 2);\n            for(int i = 0; i < n; ++i) {\n                for(int j = i\
    \ + 1; j < n; ++j) {\n                    edge.push_back({i, j});\n          \
    \      }\n            }\n            vector<int> p = perm(n * (n - 1) / 2, false);\n\
    \            for(int i = 0; i < m; ++i) {\n                u.push_back(edge[p[i]].first\
    \ + one);\n                v.push_back(edge[p[i]].second + one);\n           \
    \ }\n        }\n        return {u, v};\n    }\n    inline tuple<vector<int>, vector<int>,\
    \ vector<int>> weighted_graph(const int n, const int m, const int lower, const\
    \ int upper, const bool one = true) {\n        assert(1 <= n and n <= (int)1e8);\n\
    \        assert(1 <= m and m <= (int)min((ll)1e8, 1ll * n * (n - 1) / 2));\n \
    \       assert(lower <= upper);\n        auto [u, v] = graph(n, m, one);\n   \
    \     vector<int> w(m);\n        for(int i = 0; i < m; ++i) w[i] = num(lower,\
    \ upper);\n        return {u, v, w};\n    }\n    inline pair<vector<int>, vector<int>>\
    \ connected_graph(const int n, const int m, const bool one = true) {\n       \
    \ assert(1 <= n and n <= (int)1e8);\n        assert(n - 1 <= m and m <= (int)min((ll)1e8,\
    \ 1ll * n * (n - 1) / 2));\n        vector<int> u, v;\n        u.reserve(m);\n\
    \        v.reserve(m);\n        auto [ut, vt] = tree(n, false);\n        if(1ll\
    \ * n * (n - 1) / 2 >= 2e6) {\n            set<pair<int, int>> edge;\n       \
    \     for(int i = 0; i < n - 1; ++i) {\n                edge.insert({min(ut[i],\
    \ vt[i]), max(ut[i], vt[i])});\n            }\n            while((int)edge.size()\
    \ < m) {\n                int a = num(0, n - 1);\n                int b = num(0,\
    \ n - 1);\n                if(a >= b) continue;\n                edge.insert({a,\
    \ b});\n            }\n            for(auto& [a, b] : edge) {\n              \
    \  u.push_back(a + one);\n                v.push_back(b + one);\n            }\n\
    \        } else {\n            set<pair<int, int>> used;\n            for(int\
    \ i = 0; i < n - 1; ++i) {\n                u.push_back(ut[i] + one);\n      \
    \          v.push_back(vt[i] + one);\n                used.insert({min(ut[i],\
    \ vt[i]), max(ut[i], vt[i])});\n            }\n            vector<pair<int, int>>\
    \ edge;\n            edge.reserve(n * (n - 1) / 2 - (n - 1));\n            for(int\
    \ i = 0; i < n; ++i) {\n                for(int j = i + 1; j < n; ++j) {\n   \
    \                 if(used.find({i, j}) == used.end()) edge.push_back({i, j});\n\
    \                }\n            }\n            vector<int> p = perm(n * (n - 1)\
    \ / 2 - (n - 1), false);\n            for(int i = 0; i < m - (n - 1); ++i) {\n\
    \                u.push_back(edge[p[i]].first + one);\n                v.push_back(edge[p[i]].second\
    \ + one);\n            }\n        }\n        return {u, v};\n    }\n    inline\
    \ tuple<vector<int>, vector<int>, vector<int>> weighted_connected_graph(const\
    \ int n, const int m, const int lower, const int upper, const bool one = true)\
    \ {\n        assert(1 <= n and n <= (int)1e8);\n        assert(n - 1 <= m and\
    \ m <= (int)min((ll)1e8, 1ll * n * (n - 1) / 2));\n        assert(lower <= upper);\n\
    \        auto [u, v] = connected_graph(n, m, one);\n        vector<int> w(m);\n\
    \        for(int i = 0; i < m; ++i) w[i] = num(lower, upper);\n        return\
    \ {u, v, w};\n    }\n    inline string parenthesis(int n) {\n        assert(1\
    \ <= n and n <= 1e8);\n        string res = \"\";\n        int N = n, M = n;\n\
    \        for(int i = 0; i < 2 * n; ++i) {\n            if(rnum(0.0l, 1.0l) > 1.0l\
    \ * (N - M) * (N + 1) / ((N - M + 1) * (N + M))) {\n                res += \"\
    (\";\n                --M;\n            } else {\n                res += \")\"\
    ;\n                --N;\n            }\n        }\n        return res;\n    }\n\
    } rng;\n#line 3 \"src/graph/graph_template.hpp\"\ntemplate <typename T>\nstruct\
    \ Edge {\n    int from, to;\n    T cost;\n    int idx;\n    Edge()\n        :\
    \ from(-1), to(-1), cost(-1), idx(-1) {}\n    Edge(const int from, const int to,\
    \ const T& cost = 1, const int idx = -1)\n        : from(from), to(to), cost(cost),\
    \ idx(idx) {}\n    operator int() const {\n        return to;\n    }\n};\ntemplate\
    \ <typename T>\nstruct Graph {\n    Graph(const int N)\n        : n(N), es(0),\
    \ g(N) {}\n    int size() const {\n        return n;\n    }\n    int edge_size()\
    \ const {\n        return es;\n    }\n    void add_edge(const int from, const\
    \ int to, const T& cost = 1) {\n        assert(0 <= from and from < n);\n    \
    \    assert(0 <= to and to < n);\n        g[from].emplace_back(from, to, cost,\
    \ es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n    void add_directed_edge(const\
    \ int from, const int to, const T& cost = 1) {\n        assert(0 <= from and from\
    \ < n);\n        assert(0 <= to and to < n);\n        g[from].emplace_back(from,\
    \ to, cost, es++);\n    }\n    inline vector<Edge<T>>& operator[](const int& k)\
    \ {\n        assert(0 <= k and k < n);\n        return g[k];\n    }\n    inline\
    \ const vector<Edge<T>>& operator[](const int& k) const {\n        assert(0 <=\
    \ k and k < n);\n        return g[k];\n    }\n\n   private:\n    int n, es;\n\
    \    vector<vector<Edge<T>>> g;\n};\ntemplate <typename T>\nusing Edges = vector<Edge<T>>;\n\
    #line 4 \"src/graph/bipartite.hpp\"\ntemplate <typename T>\nvector<int> bipartite(const\
    \ Graph<T>& g) {\n    const int n = g.size();\n    vector<int> color(n, -1);\n\
    \    auto dfs = [&](const auto& dfs, const int cur, const int col) -> bool {\n\
    \        color[cur] = col;\n        for(const Edge<T>& e : g[cur]) {\n       \
    \     if(color[e.to] == col) return false;\n            if(color[e.to] == -1 and\
    \ !dfs(dfs, e.to, 1 - col)) return false;\n        }\n        return true;\n \
    \   };\n    for(int i = 0; i < n; ++i) {\n        if(color[i] != -1) continue;\n\
    \        if(!dfs(dfs, i, 0)) return {};\n    }\n    return color;\n}\n#line 4\
    \ \"src/tree/lowest_common_ancestor.hpp\"\ntemplate <typename T>\nstruct LowestCommonAncestor\
    \ {\n    LowestCommonAncestor(const Graph<T>& g, const int root = 0) {\n     \
    \   assert(0 <= root and root < g.size());\n        init(g, root);\n    }\n  \
    \  int depth(const int v) const {\n        assert(0 <= v and v < n);\n       \
    \ return dep[v];\n    }\n    T cost(const int v) const {\n        assert(0 <=\
    \ v and v < n);\n        return co[v];\n    }\n    int parent(const int v) const\
    \ {\n        assert(0 <= v and v < n);\n        return par[0][v];\n    }\n   \
    \ int la(int v, int x) const {\n        assert(0 <= v and v < n);\n        assert(x\
    \ >= 0);\n        if(x > dep[v]) return -1;\n        for(int i = 0; x > 0; ++i)\
    \ {\n            if(x & 1) v = par[i][v];\n            x >>= 1;\n        }\n \
    \       return v;\n    }\n    int lca(int u, int v) const {\n        assert(0\
    \ <= u and u < n and 0 <= v and v < n);\n        if(dep[u] > dep[v]) swap(u, v);\n\
    \        v = la(v, dep[v] - dep[u]);\n        if(u == v) return u;\n        for(int\
    \ i = (int)par.size() - 1; i >= 0; --i) {\n            if(par[i][u] != par[i][v])\
    \ {\n                u = par[i][u];\n                v = par[i][v];\n        \
    \    }\n        }\n        return par[0][u];\n    }\n    int dist(const int u,\
    \ const int v) const {\n        assert(0 <= u and u < n and 0 <= v and v < n);\n\
    \        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n    T length(const\
    \ int u, const int v) const {\n        assert(0 <= u and u < n and 0 <= v and\
    \ v < n);\n        return co[u] + co[v] - 2 * co[lca(u, v)];\n    }\n\n   private:\n\
    \    int n;\n    vector<vector<int>> par;\n    vector<int> dep;\n    vector<T>\
    \ co;\n    void init(const Graph<T>& g, const int root = 0) {\n        n = g.size();\n\
    \        int h = 1;\n        while((1 << h) < n) ++h;\n        par.assign(h, vector<int>(n,\
    \ -1));\n        dep.assign(n, -1);\n        co.assign(n, -1);\n        dfs(g,\
    \ root, -1, 0, 0);\n        for(int i = 0; i + 1 < (int)par.size(); ++i) {\n \
    \           for(int v = 0; v < n; ++v) {\n                if(par[i][v] != -1)\
    \ {\n                    par[i + 1][v] = par[i][par[i][v]];\n                }\n\
    \            }\n        }\n    }\n    void dfs(const Graph<T>& g, const int v,\
    \ const int p, const int d, const T& c) {\n        par[0][v] = p;\n        dep[v]\
    \ = d;\n        co[v] = c;\n        for(const Edge<T>& e : g[v]) {\n         \
    \   if(e.to == p) continue;\n            dfs(g, e.to, v, d + 1, c + e.cost);\n\
    \        }\n    }\n};\n#line 7 \"verify/unit_test/graph/bipartite.test.cpp\"\n\
    void random_yes() {\n    int n = rng(1, 100000);\n    vector<vector<int>> color(2);\n\
    \    rep(i, 0, n) {\n        color[rng(0, 1)].push_back(i);\n    }\n    Graph<int>\
    \ g(n);\n    if(color[0].empty() or color[1].empty()) {\n        vector<int> col\
    \ = bipartite(g);\n        assert(!col.empty());\n        rep(i, 0, n) assert(col[i]\
    \ == 0 or col[i] == 1);\n        return;\n    }\n    int m = rng(0, 200000);\n\
    \    rep(i, 0, m) {\n        int a = rng(0, (int)color[0].size() - 1);\n     \
    \   int b = rng(0, (int)color[1].size() - 1);\n        g.add_edge(color[0][a],\
    \ color[1][b]);\n    }\n    vector<int> col = bipartite(g);\n    assert(!col.empty());\n\
    \    rep(i, 0, n) {\n        assert(col[i] == 0 or col[i] == 1);\n        for(const\
    \ int to : g[i]) {\n            assert(col[to] == 1 - col[i]);\n        }\n  \
    \  }\n}\nvoid namori() {\n    int n = rng(1, 100000);\n    auto [u, v] = rng.tree(n,\
    \ false);\n    Graph<int> g(n);\n    rep(i, 0, n - 1) {\n        g.add_edge(u[i],\
    \ v[i]);\n    }\n    LowestCommonAncestor<int> tree(g);\n    int a = rng(0, n\
    \ - 1);\n    int b = a;\n    while(b == a) b = rng(0, n - 1);\n    g.add_edge(a,\
    \ b);\n    vector<int> color = bipartite(g);\n    if(tree.dist(a, b) % 2 == 0)\
    \ {\n        assert(color.empty());\n    } else {\n        assert(!color.empty());\n\
    \        rep(i, 0, n) {\n            assert(color[i] == 0 or color[i] == 1);\n\
    \            for(const int to : g[i]) {\n                assert(color[to] == 1\
    \ - color[i]);\n            }\n        }\n    }\n}\nvoid tree() {\n    int n =\
    \ rng(1, 100000);\n    auto [u, v] = rng.tree(n, false);\n    Graph<int> g(n);\n\
    \    rep(i, 0, n - 1) {\n        g.add_edge(u[i], v[i]);\n    }\n    vector<int>\
    \ color = bipartite(g);\n    assert(!color.empty());\n    rep(i, 0, n) {\n   \
    \     assert(color[i] == 0 or color[i] == 1);\n        for(const int to : g[i])\
    \ {\n            assert(color[to] == 1 - color[i]);\n        }\n    }\n}\nint\
    \ main(void) {\n    int test_num = 33;\n    rep(i, 0, test_num) {\n        random_yes();\n\
    \    }\n    rep(i, 0, test_num) {\n        namori();\n    }\n    rep(i, 0, test_num)\
    \ {\n        tree();\n    }\n    int a, b;\n    cin >> a >> b;\n    cout << a\
    \ + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/template/random_number_generator.hpp\"\n#include \"\
    ../../../src/graph/graph_template.hpp\"\n#include \"../../../src/graph/bipartite.hpp\"\
    \n#include \"../../../src/tree/lowest_common_ancestor.hpp\"\nvoid random_yes()\
    \ {\n    int n = rng(1, 100000);\n    vector<vector<int>> color(2);\n    rep(i,\
    \ 0, n) {\n        color[rng(0, 1)].push_back(i);\n    }\n    Graph<int> g(n);\n\
    \    if(color[0].empty() or color[1].empty()) {\n        vector<int> col = bipartite(g);\n\
    \        assert(!col.empty());\n        rep(i, 0, n) assert(col[i] == 0 or col[i]\
    \ == 1);\n        return;\n    }\n    int m = rng(0, 200000);\n    rep(i, 0, m)\
    \ {\n        int a = rng(0, (int)color[0].size() - 1);\n        int b = rng(0,\
    \ (int)color[1].size() - 1);\n        g.add_edge(color[0][a], color[1][b]);\n\
    \    }\n    vector<int> col = bipartite(g);\n    assert(!col.empty());\n    rep(i,\
    \ 0, n) {\n        assert(col[i] == 0 or col[i] == 1);\n        for(const int\
    \ to : g[i]) {\n            assert(col[to] == 1 - col[i]);\n        }\n    }\n\
    }\nvoid namori() {\n    int n = rng(1, 100000);\n    auto [u, v] = rng.tree(n,\
    \ false);\n    Graph<int> g(n);\n    rep(i, 0, n - 1) {\n        g.add_edge(u[i],\
    \ v[i]);\n    }\n    LowestCommonAncestor<int> tree(g);\n    int a = rng(0, n\
    \ - 1);\n    int b = a;\n    while(b == a) b = rng(0, n - 1);\n    g.add_edge(a,\
    \ b);\n    vector<int> color = bipartite(g);\n    if(tree.dist(a, b) % 2 == 0)\
    \ {\n        assert(color.empty());\n    } else {\n        assert(!color.empty());\n\
    \        rep(i, 0, n) {\n            assert(color[i] == 0 or color[i] == 1);\n\
    \            for(const int to : g[i]) {\n                assert(color[to] == 1\
    \ - color[i]);\n            }\n        }\n    }\n}\nvoid tree() {\n    int n =\
    \ rng(1, 100000);\n    auto [u, v] = rng.tree(n, false);\n    Graph<int> g(n);\n\
    \    rep(i, 0, n - 1) {\n        g.add_edge(u[i], v[i]);\n    }\n    vector<int>\
    \ color = bipartite(g);\n    assert(!color.empty());\n    rep(i, 0, n) {\n   \
    \     assert(color[i] == 0 or color[i] == 1);\n        for(const int to : g[i])\
    \ {\n            assert(color[to] == 1 - color[i]);\n        }\n    }\n}\nint\
    \ main(void) {\n    int test_num = 33;\n    rep(i, 0, test_num) {\n        random_yes();\n\
    \    }\n    rep(i, 0, test_num) {\n        namori();\n    }\n    rep(i, 0, test_num)\
    \ {\n        tree();\n    }\n    int a, b;\n    cin >> a >> b;\n    cout << a\
    \ + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/random_number_generator.hpp
  - src/graph/graph_template.hpp
  - src/graph/bipartite.hpp
  - src/tree/lowest_common_ancestor.hpp
  isVerificationFile: true
  path: verify/unit_test/graph/bipartite.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 00:36:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/unit_test/graph/bipartite.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/graph/bipartite.test.cpp
- /verify/verify/unit_test/graph/bipartite.test.cpp.html
title: verify/unit_test/graph/bipartite.test.cpp
---
