---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/data_structure/sparse_table_2d.test.cpp
    title: verify/unit_test/data_structure/sparse_table_2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/graph/bfs.test.cpp
    title: verify/unit_test/graph/bfs.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/graph/bfs01.test.cpp
    title: verify/unit_test/graph/bfs01.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/graph/bipartite.test.cpp
    title: verify/unit_test/graph/bipartite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/eratosthenes_sieve.test.cpp
    title: verify/unit_test/math/eratosthenes_sieve.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/lucas.test.cpp
    title: verify/unit_test/math/lucas.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/string/dynamic_rolling_hash.test.cpp
    title: verify/unit_test/string/dynamic_rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/tree/centroid.test.cpp
    title: verify/unit_test/tree/centroid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n\
    #define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a,\
    \ b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
    struct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/random/random_number_generator.hpp\"\
    \nstruct RandomNumberGenerator {\n    RandomNumberGenerator()\n        : mt(chrono::steady_clock::now().time_since_epoch().count())\
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
    } rng;\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nstruct RandomNumberGenerator\
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
    } rng;"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/random/random_number_generator.hpp
  requiredBy: []
  timestamp: '2025-04-27 00:17:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/tree/centroid.test.cpp
  - verify/unit_test/graph/bipartite.test.cpp
  - verify/unit_test/graph/bfs01.test.cpp
  - verify/unit_test/graph/bfs.test.cpp
  - verify/unit_test/string/dynamic_rolling_hash.test.cpp
  - verify/unit_test/data_structure/sparse_table_2d.test.cpp
  - verify/unit_test/math/lucas.test.cpp
  - verify/unit_test/math/eratosthenes_sieve.test.cpp
documentation_of: src/random/random_number_generator.hpp
layout: document
title: RandomNumberGenerator
---

# RandomNumberGenerator

- 一様ランダムな整数・実数
- 一様ランダムな配列 (重複あり・なし指定可)
- 一様ランダムな順列
- 一様ランダムな木
- 一様ランダムな単純無向グラフ
- 一様ランダムな重み付き単純無向グラフ
- ランダムな単純連結無向グラフ
- ランダムな重み付き単純連結無向グラフ
- 一様ランダムな括弧列

を生成できます．

# コンストラクタ

```cpp
RandomNumberGenerator rng()
```

- 乱数生成器 `rng` を作成します．シードには実行時の時刻を用いています．

**計算量**

- $O(1)$

# operator ()

```cpp
T rng(T lower, T upper)
```

$\mathrm{lower}$ 以上 $\mathrm{upper}$ 以下の整数・実数を一様ランダムに返します．

**制約**

- $\mathrm{lower} \leq \mathrm{upper}$

**計算量**

- $O(1)$

# vec

```cpp
vector<T> rng.vec(int n, T lower, T upper, bool dup = true)
```

$\mathrm{lower}$ 以上 $\mathrm{upper}$ 以下の整数からなる長さ $n$ の配列を一様ランダムに返します．

`dup = true` ならば要素の重複を許し，`dup = false` ならば要素の重複を許しません．

**制約**

- $0 \leq n \leq 10^8$
- $\mathrm{lower} \leq \mathrm{upper}$

**計算量**

- 期待 $O(n)$

# perm

```cpp
vector<int> rng.perm(int n, bool one = true)
```

長さ $n$ の順列を一様ランダムに返します．

`one = true` のとき要素は $[1, n]$ で，`one = false` のとき要素は $[0, n - 1]$ です．

**制約**

- $0 \leq n \leq 10^8$

**計算量**

- $O(n)$

# tree

```cpp
pair<vector<int>, vector<int>> rng.tree(int n, bool one = true)
```

$n$ 頂点の木を一様ランダムに生成し，辺の両端の頂点ラベルを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $0 \leq n \leq 10^8$

**計算量**

- $O(n \log n)$

# weighted_tree

```cpp
tuple<vector<int>, vector<int>, vector<T>> rng.weighted_tree(int n, T lower, T upper, bool one = true)
```

辺の重みが $[\mathrm{lower}, \mathrm{upper}]$ である $n$ 頂点の重み付き木を一様ランダムに生成し，辺の両端の頂点ラベルと重みを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $0 \leq n \leq 10^8$
- $\mathrm{lower} \leq \mathrm{upper}$

**計算量**

- $O(n \log n)$

# graph

```cpp
pair<vector<int>, vector<int>> rng.graph(int n, int m, bool one = true)
```

$n$ 頂点 $m$ 辺の単純無向グラフを一様ランダムに生成し，辺の両端の頂点ラベルを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $0 \leq n \leq 10^8$
- $0 \leq m \leq \mathrm{min}(10^8, \frac{n (n - 1)}{2})$

**計算量**

- 期待 $O(m \log m)$

# weighted_graph

```cpp
tuple<vector<int>, vector<int>, vector<T>> rng.weighted_graph(int n, int m, T lower, T upper, bool one = true)
```

辺の重みが $[\mathrm{lower}, \mathrm{upper}]$ である $n$ 頂点 $m$ 辺の重み付き単純無向グラフを一様ランダムに生成し，辺の両端の頂点ラベルと重みを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $0 \leq n \leq 10^8$
- $0 \leq m \leq \mathrm{min}(10^8, \frac{n (n - 1)}{2})$
- $\mathrm{lower} \leq \mathrm{upper}$

**計算量**

- 期待 $O(m \log m)$

# connected_graph

```cpp
pair<vector<int>, vector<int>> rng.connected_graph(int n, int m, bool one = true)
```

$n$ 頂点 $m$ 辺の単純無向連結グラフをランダムに生成し，辺の両端の頂点ラベルを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $0 \leq n \leq 10^8$
- $\mathrm{max}(n - 1, 0) \leq m \leq \mathrm{min}(10^8, \frac{n (n - 1)}{2})$

**計算量**

- 期待 $O(m \log m)$

# weighted_connected_graph

```cpp
tuple<vector<int>, vector<int>, vector<T>> rng.weighted_connected_graph(int n, int m, T lower, T upper, bool one = true)
```

辺の重みが $[\mathrm{lower}, \mathrm{upper}]$ である $n$ 頂点 $m$ 辺の重み付き単純無向連結グラフをランダムに生成し，辺の両端の頂点ラベルと重みを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $0 \leq n \leq 10^8$
- $\mathrm{max}(n - 1, 0) \leq m \leq \mathrm{min}(10^8, \frac{n (n - 1)}{2})$
- $\mathrm{lower} \leq \mathrm{upper}$

**計算量**

- 期待 $O(m \log m)$

# parenthesis

```cpp
string rng.parenthesis(int n)
```

長さ $2n$ の括弧列を一様ランダムに返します．

**制約**

- $1 \leq n \leq 10^8$

**計算量**

- $O(n)$