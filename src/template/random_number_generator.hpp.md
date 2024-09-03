---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/convolution/convolution_ll.test.cpp
    title: verify/unit_test/convolution/convolution_ll.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/data_structure/sparse_table_2d.test.cpp
    title: verify/unit_test/data_structure/sparse_table_2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/graph/bipartite.test.cpp
    title: verify/unit_test/graph/bipartite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/tree/centroid.test.cpp
    title: verify/unit_test/tree/centroid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/template/random_number_generator.hpp\"\
    \nstruct RandomNumberGenerator {\n    mt19937_64 mt;\n    RandomNumberGenerator()\n\
    \        : mt(chrono::steady_clock::now().time_since_epoch().count()) {}\n   \
    \ inline ll operator()(const ll lower, const ll upper) {\n        assert((ll)-1e18\
    \ <= lower and lower <= upper and upper <= (ll)1e18);\n        return num(lower,\
    \ upper);\n    }\n    inline ll num(const ll lower, const ll upper) {\n      \
    \  assert((ll)-1e18 <= lower and lower <= upper and upper <= (ll)1e18);\n    \
    \    uniform_int_distribution<ll> dist(lower, upper);\n        return dist(mt);\n\
    \    }\n    inline long double rnum(const long double lower, const long double\
    \ upper) {\n        uniform_real_distribution<long double> dist(lower, upper);\n\
    \        return dist(mt);\n    }\n    inline vector<ll> vec(const int n, const\
    \ ll lower, const ll upper, const bool dup = true) {\n        assert(1 <= n and\
    \ n <= (int)2e5);\n        assert((ll)-1e18 <= lower and lower <= upper and upper\
    \ <= (ll)1e18);\n        vector<ll> res(n);\n        if(dup) {\n            for(int\
    \ i = 0; i < n; ++i) res[i] = num(lower, upper);\n        } else {\n         \
    \   assert(upper - lower + 1 >= n);\n            if(upper - lower + 1 >= 2 * n)\
    \ {\n                set<ll> used;\n                while((int)used.size() < n)\
    \ {\n                    ll a = num(lower, upper);\n                    used.insert(a);\n\
    \                }\n                int i = 0;\n                for(ll a : used)\
    \ {\n                    res[i] = a;\n                    ++i;\n             \
    \   }\n            } else {\n                vector<int> p = perm(upper - lower\
    \ + 1, false);\n                for(int i = 0; i < n; ++i) {\n               \
    \     res[i] = p[i] + lower;\n                }\n            }\n        }\n  \
    \      return res;\n    }\n    inline vector<long double> rvec(const int n, const\
    \ long double lower, const long double upper) {\n        assert(1 <= n and n <=\
    \ (int)2e5);\n        vector<long double> res(n);\n        for(int i = 0; i <\
    \ n; ++i) res[i] = rnum(lower, upper);\n        return res;\n    }\n    inline\
    \ vector<int> perm(const int n, const bool one = true) {\n        assert(1 <=\
    \ n and n <= (int)1e6);\n        vector<int> res(n);\n        for(int i = 0; i\
    \ < n; ++i) res[i] = i + one;\n        for(int i = n - 1; i > 0; --i) {\n    \
    \        swap(res[i], res[num(0, i)]);\n        }\n        return res;\n    }\n\
    \    inline pair<vector<int>, vector<int>> tree(const int n, const bool one =\
    \ true) {\n        assert(1 <= n and n <= (int)2e5);\n        if(n == 1) return\
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
    \ int upper, const bool one = true) {\n        assert(1 <= n and n <= (int)2e5);\n\
    \        assert((int)-1e9 <= lower and lower <= upper and upper <= (int)1e9);\n\
    \        auto [u, v] = tree(n, one);\n        vector<int> w(n - 1);\n        for(int\
    \ i = 0; i < n - 1; ++i) w[i] = num(lower, upper);\n        return {u, v, w};\n\
    \    }\n    inline pair<vector<int>, vector<int>> graph(const int n, const int\
    \ m, const bool one = true) {\n        assert(1 <= n and n <= (int)2e5);\n   \
    \     assert(1 <= m and m <= min((int)2e5, n * (n - 1) / 2));\n        vector<int>\
    \ u, v;\n        u.reserve(m);\n        v.reserve(m);\n        if(n * (n - 1)\
    \ / 2 >= 2e6) {\n            set<pair<int, int>> edge;\n            while((int)edge.size()\
    \ < m) {\n                int a = num(0, n - 1);\n                int b = num(0,\
    \ n - 1);\n                if(a >= b) continue;\n                edge.insert({a,\
    \ b});\n            }\n            for(auto& [a, b] : edge) {\n              \
    \  u.push_back(a + one);\n                v.push_back(b + one);\n            }\n\
    \        } else {\n            vector<pair<int, int>> edge;\n            edge.reserve(n\
    \ * (n - 1) / 2);\n            for(int i = 0; i < n; ++i) {\n                for(int\
    \ j = i + 1; j < n; ++j) {\n                    edge.push_back({i, j});\n    \
    \            }\n            }\n            vector<int> p = perm(n * (n - 1) /\
    \ 2, false);\n            for(int i = 0; i < m; ++i) {\n                u.push_back(edge[p[i]].first\
    \ + one);\n                v.push_back(edge[p[i]].second + one);\n           \
    \ }\n        }\n        return {u, v};\n    }\n    inline tuple<vector<int>, vector<int>,\
    \ vector<int>> weighted_graph(const int n, const int m, const int lower, const\
    \ int upper, const bool one = true) {\n        assert(1 <= n and n <= (int)2e5);\n\
    \        assert(1 <= m and m <= min((int)2e5, n * (n - 1) / 2));\n        assert((int)-1e9\
    \ <= lower and lower <= upper and upper <= (int)1e9);\n        auto [u, v] = graph(n,\
    \ m, one);\n        vector<int> w(m);\n        for(int i = 0; i < m; ++i) w[i]\
    \ = num(lower, upper);\n        return {u, v, w};\n    }\n    inline pair<vector<int>,\
    \ vector<int>> connected_graph(const int n, const int m, const bool one = true)\
    \ {\n        assert(1 <= n and n <= (int)2e5);\n        assert(n - 1 <= m and\
    \ m <= min((int)2e5, n * (n - 1) / 2));\n        vector<int> u, v;\n        u.reserve(m);\n\
    \        v.reserve(m);\n        auto [ut, vt] = tree(n, false);\n        if(n\
    \ * (n - 1) / 2 >= 2e6) {\n            set<pair<int, int>> edge;\n           \
    \ for(int i = 0; i < n - 1; ++i) {\n                edge.insert({min(ut[i], vt[i]),\
    \ max(ut[i], vt[i])});\n            }\n            while((int)edge.size() < m)\
    \ {\n                int a = num(0, n - 1);\n                int b = num(0, n\
    \ - 1);\n                if(a >= b) continue;\n                edge.insert({a,\
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
    \ {\n        assert(1 <= n and n <= (int)2e5);\n        assert(n - 1 <= m and\
    \ m <= min((int)2e5, n * (n - 1) / 2));\n        assert((int)-1e9 <= lower and\
    \ lower <= upper and upper <= (int)1e9);\n        auto [u, v] = connected_graph(n,\
    \ m, one);\n        vector<int> w(m);\n        for(int i = 0; i < m; ++i) w[i]\
    \ = num(lower, upper);\n        return {u, v, w};\n    }\n    inline string parenthesis(int\
    \ n) {\n        string res = \"\";\n        int N = n, M = n;\n        for(int\
    \ i = 0; i < 2 * n; ++i) {\n            if(rnum(0.0l, 1.0l) > 1.0l * (N - M) *\
    \ (N + 1) / ((N - M + 1) * (N + M))) {\n                res += \"(\";\n      \
    \          --M;\n            } else {\n                res += \")\";\n       \
    \         --N;\n            }\n        }\n        return res;\n    }\n} rng;\n"
  code: "#pragma once\n#include \"./template.hpp\"\nstruct RandomNumberGenerator {\n\
    \    mt19937_64 mt;\n    RandomNumberGenerator()\n        : mt(chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    inline ll operator()(const ll lower, const ll upper) {\n        assert((ll)-1e18\
    \ <= lower and lower <= upper and upper <= (ll)1e18);\n        return num(lower,\
    \ upper);\n    }\n    inline ll num(const ll lower, const ll upper) {\n      \
    \  assert((ll)-1e18 <= lower and lower <= upper and upper <= (ll)1e18);\n    \
    \    uniform_int_distribution<ll> dist(lower, upper);\n        return dist(mt);\n\
    \    }\n    inline long double rnum(const long double lower, const long double\
    \ upper) {\n        uniform_real_distribution<long double> dist(lower, upper);\n\
    \        return dist(mt);\n    }\n    inline vector<ll> vec(const int n, const\
    \ ll lower, const ll upper, const bool dup = true) {\n        assert(1 <= n and\
    \ n <= (int)2e5);\n        assert((ll)-1e18 <= lower and lower <= upper and upper\
    \ <= (ll)1e18);\n        vector<ll> res(n);\n        if(dup) {\n            for(int\
    \ i = 0; i < n; ++i) res[i] = num(lower, upper);\n        } else {\n         \
    \   assert(upper - lower + 1 >= n);\n            if(upper - lower + 1 >= 2 * n)\
    \ {\n                set<ll> used;\n                while((int)used.size() < n)\
    \ {\n                    ll a = num(lower, upper);\n                    used.insert(a);\n\
    \                }\n                int i = 0;\n                for(ll a : used)\
    \ {\n                    res[i] = a;\n                    ++i;\n             \
    \   }\n            } else {\n                vector<int> p = perm(upper - lower\
    \ + 1, false);\n                for(int i = 0; i < n; ++i) {\n               \
    \     res[i] = p[i] + lower;\n                }\n            }\n        }\n  \
    \      return res;\n    }\n    inline vector<long double> rvec(const int n, const\
    \ long double lower, const long double upper) {\n        assert(1 <= n and n <=\
    \ (int)2e5);\n        vector<long double> res(n);\n        for(int i = 0; i <\
    \ n; ++i) res[i] = rnum(lower, upper);\n        return res;\n    }\n    inline\
    \ vector<int> perm(const int n, const bool one = true) {\n        assert(1 <=\
    \ n and n <= (int)1e6);\n        vector<int> res(n);\n        for(int i = 0; i\
    \ < n; ++i) res[i] = i + one;\n        for(int i = n - 1; i > 0; --i) {\n    \
    \        swap(res[i], res[num(0, i)]);\n        }\n        return res;\n    }\n\
    \    inline pair<vector<int>, vector<int>> tree(const int n, const bool one =\
    \ true) {\n        assert(1 <= n and n <= (int)2e5);\n        if(n == 1) return\
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
    \ int upper, const bool one = true) {\n        assert(1 <= n and n <= (int)2e5);\n\
    \        assert((int)-1e9 <= lower and lower <= upper and upper <= (int)1e9);\n\
    \        auto [u, v] = tree(n, one);\n        vector<int> w(n - 1);\n        for(int\
    \ i = 0; i < n - 1; ++i) w[i] = num(lower, upper);\n        return {u, v, w};\n\
    \    }\n    inline pair<vector<int>, vector<int>> graph(const int n, const int\
    \ m, const bool one = true) {\n        assert(1 <= n and n <= (int)2e5);\n   \
    \     assert(1 <= m and m <= min((int)2e5, n * (n - 1) / 2));\n        vector<int>\
    \ u, v;\n        u.reserve(m);\n        v.reserve(m);\n        if(n * (n - 1)\
    \ / 2 >= 2e6) {\n            set<pair<int, int>> edge;\n            while((int)edge.size()\
    \ < m) {\n                int a = num(0, n - 1);\n                int b = num(0,\
    \ n - 1);\n                if(a >= b) continue;\n                edge.insert({a,\
    \ b});\n            }\n            for(auto& [a, b] : edge) {\n              \
    \  u.push_back(a + one);\n                v.push_back(b + one);\n            }\n\
    \        } else {\n            vector<pair<int, int>> edge;\n            edge.reserve(n\
    \ * (n - 1) / 2);\n            for(int i = 0; i < n; ++i) {\n                for(int\
    \ j = i + 1; j < n; ++j) {\n                    edge.push_back({i, j});\n    \
    \            }\n            }\n            vector<int> p = perm(n * (n - 1) /\
    \ 2, false);\n            for(int i = 0; i < m; ++i) {\n                u.push_back(edge[p[i]].first\
    \ + one);\n                v.push_back(edge[p[i]].second + one);\n           \
    \ }\n        }\n        return {u, v};\n    }\n    inline tuple<vector<int>, vector<int>,\
    \ vector<int>> weighted_graph(const int n, const int m, const int lower, const\
    \ int upper, const bool one = true) {\n        assert(1 <= n and n <= (int)2e5);\n\
    \        assert(1 <= m and m <= min((int)2e5, n * (n - 1) / 2));\n        assert((int)-1e9\
    \ <= lower and lower <= upper and upper <= (int)1e9);\n        auto [u, v] = graph(n,\
    \ m, one);\n        vector<int> w(m);\n        for(int i = 0; i < m; ++i) w[i]\
    \ = num(lower, upper);\n        return {u, v, w};\n    }\n    inline pair<vector<int>,\
    \ vector<int>> connected_graph(const int n, const int m, const bool one = true)\
    \ {\n        assert(1 <= n and n <= (int)2e5);\n        assert(n - 1 <= m and\
    \ m <= min((int)2e5, n * (n - 1) / 2));\n        vector<int> u, v;\n        u.reserve(m);\n\
    \        v.reserve(m);\n        auto [ut, vt] = tree(n, false);\n        if(n\
    \ * (n - 1) / 2 >= 2e6) {\n            set<pair<int, int>> edge;\n           \
    \ for(int i = 0; i < n - 1; ++i) {\n                edge.insert({min(ut[i], vt[i]),\
    \ max(ut[i], vt[i])});\n            }\n            while((int)edge.size() < m)\
    \ {\n                int a = num(0, n - 1);\n                int b = num(0, n\
    \ - 1);\n                if(a >= b) continue;\n                edge.insert({a,\
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
    \ {\n        assert(1 <= n and n <= (int)2e5);\n        assert(n - 1 <= m and\
    \ m <= min((int)2e5, n * (n - 1) / 2));\n        assert((int)-1e9 <= lower and\
    \ lower <= upper and upper <= (int)1e9);\n        auto [u, v] = connected_graph(n,\
    \ m, one);\n        vector<int> w(m);\n        for(int i = 0; i < m; ++i) w[i]\
    \ = num(lower, upper);\n        return {u, v, w};\n    }\n    inline string parenthesis(int\
    \ n) {\n        string res = \"\";\n        int N = n, M = n;\n        for(int\
    \ i = 0; i < 2 * n; ++i) {\n            if(rnum(0.0l, 1.0l) > 1.0l * (N - M) *\
    \ (N + 1) / ((N - M + 1) * (N + M))) {\n                res += \"(\";\n      \
    \          --M;\n            } else {\n                res += \")\";\n       \
    \         --N;\n            }\n        }\n        return res;\n    }\n} rng;"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/template/random_number_generator.hpp
  requiredBy: []
  timestamp: '2024-01-06 02:59:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/tree/centroid.test.cpp
  - verify/unit_test/convolution/convolution_ll.test.cpp
  - verify/unit_test/graph/bipartite.test.cpp
  - verify/unit_test/data_structure/sparse_table_2d.test.cpp
documentation_of: src/template/random_number_generator.hpp
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
ll rng(ll lower, ll upper)
```

$\mathrm{lower}$ 以上 $\mathrm{upper}$ 以下の整数を一様ランダムに返します．

**制約**

- $-10^{18} \leq \mathrm{lower} \leq \mathrm{upper} \leq 10^{18}$

**計算量**

- $O(1)$

# num

```cpp
ll rng.num(ll lower, ll upper)
```

$\mathrm{lower}$ 以上 $\mathrm{upper}$ 以下の整数を一様ランダムに返します．

**制約**

- $-10^{18} \leq \mathrm{lower} \leq \mathrm{upper} \leq 10^{18}$

**計算量**

- $O(1)$

# rnum

```cpp
long double rng.rnum(long double lower, long double upper)
```

$\mathrm{lower}$ 以上 $\mathrm{upper}$ 以下の実数を一様ランダムに返します．

**制約**

- $-10^{18} \leq \mathrm{lower} \leq \mathrm{upper} \leq 10^{18}$

**計算量**

- $O(1)$

# vec

```cpp
vector<ll> rng.vec(int n, ll lower, ll upper, bool dup = true)
```

$\mathrm{lower}$ 以上 $\mathrm{upper}$ 以下の整数からなる長さ $n$ の配列を一様ランダムに返します．

`dup = true` ならば要素の重複を許し，`dup = false` ならば要素の重複を許しません．

**制約**

- $1 \leq n \leq 2 \cdot 10^5$
- $-10^{18} \leq \mathrm{lower} \leq \mathrm{upper} \leq 10^{18}$

**計算量**

- 期待 $O(n)$

# rvec

```cpp
vector<long double> rng.rvec(int n, long double lower, long double upper)
```

$\mathrm{lower}$ 以上 $\mathrm{upper}$ 以下の実数からなる長さ $n$ の配列を一様ランダムに返します．

**制約**

- $1 \leq n \leq 2 \cdot 10^5$
- $-10^{18} \leq \mathrm{lower} \leq \mathrm{upper} \leq 10^{18}$

**計算量**

- 期待 $O(n)$

# perm

```cpp
vector<int> rng.perm(int n, bool one = true)
```

長さ $n$ の順列を一様ランダムに返します．

`one = true` のとき要素は $[1, n]$ で，`one = false` のとき要素は $[0, n - 1]$ です．

**制約**

- $1 \leq n \leq 10^6$

**計算量**

- $O(n)$

# tree

```cpp
pair<vector<int>, vector<int>> rng.tree(int n, bool one = true)
```

$n$ 頂点の木を一様ランダムに生成し，辺の両端の頂点ラベルを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $1 \leq n \leq 2 \cdot 10^5$

**計算量**

- $O(n \log n)$

# weighted_tree

```cpp
tuple<vector<int>, vector<int>, vector<int>> rng.weighted_tree(int n, int lower, int upper, bool one = true)
```

辺の重みが $[\mathrm{lower}, \mathrm{upper}]$ である $n$ 頂点の重み付き木を一様ランダムに生成し，辺の両端の頂点ラベルと重みを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $1 \leq n \leq 2 \cdot 10^5$
- $-10^9 \leq \mathrm{lower} \leq \mathrm{upper} \leq 10^9$

**計算量**

- $O(n \log n)$

# graph

```cpp
pair<vector<int>, vector<int>> rng.graph(int n, int m, bool one = true)
```

$n$ 頂点 $m$ 辺の単純無向グラフを一様ランダムに生成し，辺の両端の頂点ラベルを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $1 \leq n \leq 2 \cdot 10^5$
- $1 \leq m \leq \mathrm{min}(2 \cdot 10^5, \frac{n (n - 1)}{2})$

**計算量**

- 期待 $O(m \log m)$

# weighted_graph

```cpp
tuple<vector<int>, vector<int>, vector<int>> rng.weighted_graph(int n, int m, int lower, int upper, bool one = true)
```

辺の重みが $[\mathrm{lower}, \mathrm{upper}]$ である $n$ 頂点 $m$ 辺の重み付き単純無向グラフを一様ランダムに生成し，辺の両端の頂点ラベルと重みを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $1 \leq n \leq 2 \cdot 10^5$
- $1 \leq m \leq \mathrm{min}(2 \cdot 10^5, \frac{n (n - 1)}{2})$
- $-10^9 \leq \mathrm{lower} \leq \mathrm{upper} \leq 10^9$

**計算量**

- 期待 $O(m \log m)$

# connected_graph

```cpp
pair<vector<int>, vector<int>> rng.connected_graph(int n, int m, bool one = true)
```

$n$ 頂点 $m$ 辺の単純無向連結グラフをランダムに生成し，辺の両端の頂点ラベルを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $1 \leq n \leq 2 \cdot 10^5$
- $n - 1 \leq m \leq \mathrm{min}(2 \cdot 10^5, \frac{n (n - 1)}{2})$

**計算量**

- 期待 $O(m \log m)$

# weighted_connected_graph

```cpp
tuple<vector<int>, vector<int>, vector<int>> rng.weighted_connected_graph(int n, int m, int lower, int upper, bool one = true)
```

辺の重みが $[\mathrm{lower}, \mathrm{upper}]$ である $n$ 頂点 $m$ 辺の重み付き単純無向連結グラフをランダムに生成し，辺の両端の頂点ラベルと重みを返します．

`one = true` のときラベルは $[1, n]$ で，`one = false` のときラベルは $[0, n - 1]$ です．

**制約**

- $1 \leq n \leq 2 \cdot 10^5$
- $n - 1 \leq m \leq \mathrm{min}(2 \cdot 10^5, \frac{n (n - 1)}{2})$
- $-10^9 \leq \mathrm{lower} \leq \mathrm{upper} \leq 10^9$

**計算量**

- 期待 $O(m \log m)$

# parenthesis

```cpp
string rng.parenthesis(int n)
```

長さ $2n$ の括弧列を一様ランダムに返します．

**制約**

- $1 \leq n \leq 2 \cdot 10^5$

**計算量**

- $O(n)$