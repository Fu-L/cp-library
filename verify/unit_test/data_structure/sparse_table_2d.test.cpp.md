---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/sparse_table_2d.hpp
    title: SparseTable2D
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
  bundledCode: "#line 1 \"verify/unit_test/data_structure/sparse_table_2d.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
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
    } rng;\n#line 3 \"src/data_structure/sparse_table_2d.hpp\"\ntemplate <typename\
    \ S, auto op, auto e>\nstruct SparseTable2D {\n    SparseTable2D(const vector<vector<S>>&\
    \ v)\n        : h((int)v.size()), w((int)v[0].size()), LOG(max(h, w) + 1) {\n\
    \        for(int i = 2; i < (int)LOG.size(); ++i) LOG[i] = LOG[i / 2] + 1;\n \
    \       table = vector<vector<vector<vector<S>>>>(LOG[h] + 1, vector<vector<vector<S>>>(LOG[w]\
    \ + 1, vector<vector<S>>(h, vector<S>(w, e()))));\n        for(int i = 0; i <\
    \ h; ++i) {\n            for(int j = 0; j < w; ++j) {\n                table[0][0][i][j]\
    \ = v[i][j];\n            }\n        }\n        for(int i = 0; i <= LOG[h]; ++i)\
    \ {\n            for(int j = 0; j <= LOG[w]; ++j) {\n                for(int x\
    \ = 0; x < h; ++x) {\n                    for(int y = 0; y < w; ++y) {\n     \
    \                   if(i < LOG[h]) table[i + 1][j][x][y] = op(table[i][j][x][y],\
    \ (x + (1 << i) < h) ? table[i][j][x + (1 << i)][y] : e());\n                \
    \        if(j < LOG[w]) table[i][j + 1][x][y] = op(table[i][j][x][y], (y + (1\
    \ << j) < w) ? table[i][j][x][y + (1 << j)] : e());\n                    }\n \
    \               }\n            }\n        }\n    }\n    S prod(const int lx, const\
    \ int rx, const int ly, const int ry) const {\n        assert(0 <= lx and lx <=\
    \ rx and rx <= h);\n        assert(0 <= ly and ly <= ry and ry <= w);\n      \
    \  if(lx == rx or ly == ry) return e();\n        const int kx = LOG[rx - lx];\n\
    \        const int ky = LOG[ry - ly];\n        return op(op(table[kx][ky][lx][ly],\
    \ table[kx][ky][rx - (1 << kx)][ly]), op(table[kx][ky][lx][ry - (1 << ky)], table[kx][ky][rx\
    \ - (1 << kx)][ry - (1 << ky)]));\n    }\n\n   private:\n    int h, w;\n    vector<vector<vector<vector<S>>>>\
    \ table;\n    vector<int> LOG;\n};\n#line 5 \"verify/unit_test/data_structure/sparse_table_2d.test.cpp\"\
    \nint op(int a, int b) {\n    return min(a, b);\n}\nint e() {\n    return (int)1e9;\n\
    }\nvoid test() {\n    int h = rng(10, 100), w = rng(10, 100);\n    vector<vector<int>>\
    \ a(h, vector<int>(w));\n    rep(i, 0, h) {\n        rep(j, 0, w) {\n        \
    \    a[i][j] = rng(0, (int)1e9);\n        }\n    }\n    SparseTable2D<int, op,\
    \ e> st(a);\n    int query_num = 1000;\n    while(query_num--) {\n        int\
    \ xl = rng(0, h), xr = rng(xl, h);\n        int yl = rng(0, w), yr = rng(yl, w);\n\
    \        int expected = 1e9;\n        rep(i, xl, xr) {\n            rep(j, yl,\
    \ yr) {\n                expected = min(expected, a[i][j]);\n            }\n \
    \       }\n        assert(st.prod(xl, xr, yl, yr) == expected);\n    }\n}\nint\
    \ main(void) {\n    constexpr int test_num = 100;\n    rep(i, 0, test_num) {\n\
    \        test();\n    }\n    int a, b;\n    cin >> a >> b;\n    cout << a + b\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/template/random_number_generator.hpp\"\n#include \"\
    ../../../src/data_structure/sparse_table_2d.hpp\"\nint op(int a, int b) {\n  \
    \  return min(a, b);\n}\nint e() {\n    return (int)1e9;\n}\nvoid test() {\n \
    \   int h = rng(10, 100), w = rng(10, 100);\n    vector<vector<int>> a(h, vector<int>(w));\n\
    \    rep(i, 0, h) {\n        rep(j, 0, w) {\n            a[i][j] = rng(0, (int)1e9);\n\
    \        }\n    }\n    SparseTable2D<int, op, e> st(a);\n    int query_num = 1000;\n\
    \    while(query_num--) {\n        int xl = rng(0, h), xr = rng(xl, h);\n    \
    \    int yl = rng(0, w), yr = rng(yl, w);\n        int expected = 1e9;\n     \
    \   rep(i, xl, xr) {\n            rep(j, yl, yr) {\n                expected =\
    \ min(expected, a[i][j]);\n            }\n        }\n        assert(st.prod(xl,\
    \ xr, yl, yr) == expected);\n    }\n}\nint main(void) {\n    constexpr int test_num\
    \ = 100;\n    rep(i, 0, test_num) {\n        test();\n    }\n    int a, b;\n \
    \   cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/random_number_generator.hpp
  - src/data_structure/sparse_table_2d.hpp
  isVerificationFile: true
  path: verify/unit_test/data_structure/sparse_table_2d.test.cpp
  requiredBy: []
  timestamp: '2025-02-02 23:19:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/data_structure/sparse_table_2d.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/data_structure/sparse_table_2d.test.cpp
- /verify/verify/unit_test/data_structure/sparse_table_2d.test.cpp.html
title: verify/unit_test/data_structure/sparse_table_2d.test.cpp
---
