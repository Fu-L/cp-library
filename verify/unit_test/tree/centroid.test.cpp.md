---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/template/random_number_generator.hpp
    title: RandomNumberGenerator
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  - icon: ':heavy_check_mark:'
    path: src/tree/centroid.hpp
    title: centroid
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
  bundledCode: "#line 1 \"verify/unit_test/tree/centroid.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ P = pair<long long, long long>;\n#define rep(i, a, b) for(long long i = (a);\
    \ i < (b); ++i)\n#define rrep(i, a, b) for(long long i = (a); i >= (b); --i)\n\
    constexpr long long inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/template/random_number_generator.hpp\"\nstruct RandomNumberGenerator\
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
    #line 4 \"src/tree/centroid.hpp\"\ntemplate <typename T>\nvector<int> centroid(const\
    \ Graph<T>& g) {\n    const int n = g.size();\n    stack<pair<int, int>> st;\n\
    \    st.emplace(0, -1);\n    vector<int> sz(n), par(n);\n    while(!st.empty())\
    \ {\n        const pair<int, int> p = st.top();\n        if(sz[p.first] == 0)\
    \ {\n            sz[p.first] = 1;\n            for(const Edge<T>& e : g[p.first])\
    \ {\n                if(e.to != p.second) {\n                    st.emplace(e.to,\
    \ p.first);\n                }\n            }\n        } else {\n            for(const\
    \ Edge<T>& e : g[p.first]) {\n                if(e.to != p.second) {\n       \
    \             sz[p.first] += sz[e.to];\n                }\n            }\n   \
    \         par[p.first] = p.second;\n            st.pop();\n        }\n    }\n\
    \    vector<int> ret;\n    int size = n;\n    for(int i = 0; i < n; ++i) {\n \
    \       int val = n - sz[i];\n        for(const Edge<T>& e : g[i]) {\n       \
    \     if(e.to != par[i]) {\n                val = max(val, sz[e.to]);\n      \
    \      }\n        }\n        if(val < size) size = val, ret.clear();\n       \
    \ if(val == size) ret.emplace_back(i);\n    }\n    return ret;\n}\n#line 6 \"\
    verify/unit_test/tree/centroid.test.cpp\"\nvoid test() {\n    int n = rng(2, 1000);\n\
    \    auto [u, v] = rng.tree(n, false);\n    Graph<int> g(n);\n    rep(i, 0, n\
    \ - 1) {\n        g.add_edge(u[i], v[i]);\n    }\n    vector<bool> visited(n);\n\
    \    auto dfs = [&](auto& dfs, int cur, int root, bool is_centroid) -> int {\n\
    \        visited[cur] = true;\n        vector<int> sub;\n        int sum = 1;\n\
    \        for(const auto& e : g[cur]) {\n            if(visited[e.to]) continue;\n\
    \            sub.push_back(dfs(dfs, e.to, root, is_centroid));\n            sum\
    \ += sub.back();\n        }\n        if(cur == root) {\n            if(is_centroid)\
    \ {\n                for(const int val : sub) {\n                    assert(2\
    \ * val <= n);\n                }\n            } else {\n                bool\
    \ flag = false;\n                for(const int val : sub) {\n                \
    \    if(2 * val > n) flag = true;\n                }\n                assert(flag);\n\
    \            }\n        }\n        visited[cur] = false;\n        return sum;\n\
    \    };\n    vector<int> cent = centroid(g);\n    rep(i, 0, n) {\n        bool\
    \ is_centroid = false;\n        for(const int x : cent) {\n            if(i ==\
    \ x) is_centroid = true;\n        }\n        dfs(dfs, i, i, is_centroid);\n  \
    \  }\n}\nint main(void) {\n    constexpr int test_num = 100;\n    rep(i, 0, test_num)\
    \ {\n        test();\n    }\n    int a, b;\n    cin >> a >> b;\n    cout << a\
    \ + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/template/random_number_generator.hpp\"\n#include \"\
    ../../../src/graph/graph_template.hpp\"\n#include \"../../../src/tree/centroid.hpp\"\
    \nvoid test() {\n    int n = rng(2, 1000);\n    auto [u, v] = rng.tree(n, false);\n\
    \    Graph<int> g(n);\n    rep(i, 0, n - 1) {\n        g.add_edge(u[i], v[i]);\n\
    \    }\n    vector<bool> visited(n);\n    auto dfs = [&](auto& dfs, int cur, int\
    \ root, bool is_centroid) -> int {\n        visited[cur] = true;\n        vector<int>\
    \ sub;\n        int sum = 1;\n        for(const auto& e : g[cur]) {\n        \
    \    if(visited[e.to]) continue;\n            sub.push_back(dfs(dfs, e.to, root,\
    \ is_centroid));\n            sum += sub.back();\n        }\n        if(cur ==\
    \ root) {\n            if(is_centroid) {\n                for(const int val :\
    \ sub) {\n                    assert(2 * val <= n);\n                }\n     \
    \       } else {\n                bool flag = false;\n                for(const\
    \ int val : sub) {\n                    if(2 * val > n) flag = true;\n       \
    \         }\n                assert(flag);\n            }\n        }\n       \
    \ visited[cur] = false;\n        return sum;\n    };\n    vector<int> cent = centroid(g);\n\
    \    rep(i, 0, n) {\n        bool is_centroid = false;\n        for(const int\
    \ x : cent) {\n            if(i == x) is_centroid = true;\n        }\n       \
    \ dfs(dfs, i, i, is_centroid);\n    }\n}\nint main(void) {\n    constexpr int\
    \ test_num = 100;\n    rep(i, 0, test_num) {\n        test();\n    }\n    int\
    \ a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/random_number_generator.hpp
  - src/graph/graph_template.hpp
  - src/tree/centroid.hpp
  isVerificationFile: true
  path: verify/unit_test/tree/centroid.test.cpp
  requiredBy: []
  timestamp: '2025-02-02 23:19:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/tree/centroid.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/tree/centroid.test.cpp
- /verify/verify/unit_test/tree/centroid.test.cpp.html
title: verify/unit_test/tree/centroid.test.cpp
---
