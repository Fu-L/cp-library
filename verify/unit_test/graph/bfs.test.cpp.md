---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/bfs.hpp
    title: bfs
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: dijkstra
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/template/random_number_generator.hpp
    title: RandomNumberGenerator
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
  bundledCode: "#line 1 \"verify/unit_test/graph/bfs.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ P = pair<long long, long long>;\n#define rep(i, a, b) for(long long i = (a);\
    \ i < (b); ++i)\n#define rrep(i, a, b) for(long long i = (a); i >= (b); --i)\n\
    constexpr long long inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/template/random_number_generator.hpp\"\nstruct RandomNumberGenerator\
    \ {\n    mt19937_64 mt;\n    RandomNumberGenerator()\n        : mt(chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    inline ll operator()(const ll lower, const ll upper) {\n        assert(lower\
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
    #line 4 \"src/graph/bfs.hpp\"\nvector<pair<int, int>> bfs(const Graph<int>& g,\
    \ const int s = 0) {\n    const int n = g.size();\n    assert(0 <= s and s < n);\n\
    \    vector<pair<int, int>> d(n, {numeric_limits<int>::max(), -1});\n    queue<int>\
    \ q;\n    d[s] = {0, -1};\n    q.emplace(s);\n    while(!q.empty()) {\n      \
    \  const int cur = q.front();\n        q.pop();\n        for(const Edge<int>&\
    \ e : g[cur]) {\n            if(d[e.to].first == numeric_limits<int>::max()) {\n\
    \                d[e.to] = {d[cur].first + 1, cur};\n                q.emplace(e.to);\n\
    \            }\n        }\n    }\n    return d;\n}\n#line 4 \"src/graph/dijkstra.hpp\"\
    \ntemplate <typename T>\nvector<pair<T, int>> dijkstra(const Graph<T>& g, const\
    \ int s = 0) {\n    const int n = g.size();\n    assert(0 <= s and s < n);\n \
    \   vector<pair<T, int>> d(n, {numeric_limits<T>::max(), -1});\n    priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n    d[s] = {0, -1};\n\
    \    pq.emplace(0, s);\n    while(!pq.empty()) {\n        const auto [dist, cur]\
    \ = pq.top();\n        pq.pop();\n        if(d[cur].first < dist) continue;\n\
    \        for(const Edge<T>& e : g[cur]) {\n            if(d[e.to].first > d[cur].first\
    \ + e.cost) {\n                d[e.to] = {d[cur].first + e.cost, cur};\n     \
    \           pq.emplace(d[e.to].first, e.to);\n            }\n        }\n    }\n\
    \    return d;\n}\n#line 7 \"verify/unit_test/graph/bfs.test.cpp\"\nvoid undirected()\
    \ {\n    int n = rng(1, 200000), m = rng(1, min(200000ll, 1ll * n * (n - 1) /\
    \ 2));\n    auto [u, v] = rng.graph(n, m, false);\n    Graph<int> g(n);\n    rep(i,\
    \ 0, m) {\n        g.add_edge(u[i], v[i]);\n    }\n    vector<pair<int, int>>\
    \ ans = dijkstra(g, 0), res = bfs(g, 0);\n    rep(i, 0, n) {\n        assert(ans[i].first\
    \ == res[i].first);\n    }\n}\nvoid directed() {\n    int n = rng(1, 200000),\
    \ m = rng(1, min(200000ll, 1ll * n * (n - 1) / 2));\n    auto [u, v] = rng.graph(n,\
    \ m, false);\n    Graph<int> g(n);\n    rep(i, 0, m) {\n        g.add_directed_edge(u[i],\
    \ v[i]);\n    }\n    vector<pair<int, int>> ans = dijkstra(g, 0), res = bfs(g,\
    \ 0);\n    rep(i, 0, n) {\n        assert(ans[i].first == res[i].first);\n   \
    \ }\n}\nint main(void) {\n    int test_num = 50;\n    rep(i, 0, test_num) {\n\
    \        undirected();\n    }\n    rep(i, 0, test_num) {\n        directed();\n\
    \    }\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/template/random_number_generator.hpp\"\n#include \"\
    ../../../src/graph/graph_template.hpp\"\n#include \"../../../src/graph/bfs.hpp\"\
    \n#include \"../../../src/graph/dijkstra.hpp\"\nvoid undirected() {\n    int n\
    \ = rng(1, 200000), m = rng(1, min(200000ll, 1ll * n * (n - 1) / 2));\n    auto\
    \ [u, v] = rng.graph(n, m, false);\n    Graph<int> g(n);\n    rep(i, 0, m) {\n\
    \        g.add_edge(u[i], v[i]);\n    }\n    vector<pair<int, int>> ans = dijkstra(g,\
    \ 0), res = bfs(g, 0);\n    rep(i, 0, n) {\n        assert(ans[i].first == res[i].first);\n\
    \    }\n}\nvoid directed() {\n    int n = rng(1, 200000), m = rng(1, min(200000ll,\
    \ 1ll * n * (n - 1) / 2));\n    auto [u, v] = rng.graph(n, m, false);\n    Graph<int>\
    \ g(n);\n    rep(i, 0, m) {\n        g.add_directed_edge(u[i], v[i]);\n    }\n\
    \    vector<pair<int, int>> ans = dijkstra(g, 0), res = bfs(g, 0);\n    rep(i,\
    \ 0, n) {\n        assert(ans[i].first == res[i].first);\n    }\n}\nint main(void)\
    \ {\n    int test_num = 50;\n    rep(i, 0, test_num) {\n        undirected();\n\
    \    }\n    rep(i, 0, test_num) {\n        directed();\n    }\n    int a, b;\n\
    \    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/random_number_generator.hpp
  - src/graph/graph_template.hpp
  - src/graph/bfs.hpp
  - src/graph/dijkstra.hpp
  isVerificationFile: true
  path: verify/unit_test/graph/bfs.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/graph/bfs.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/graph/bfs.test.cpp
- /verify/verify/unit_test/graph/bfs.test.cpp.html
title: verify/unit_test/graph/bfs.test.cpp
---