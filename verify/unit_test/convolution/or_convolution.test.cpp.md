---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/or_convolution.hpp
    title: or_convolution
  - icon: ':heavy_check_mark:'
    path: src/math/zeta_transform.hpp
    title: zeta_transform
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
  bundledCode: "#line 1 \"verify/unit_test/convolution/or_convolution.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
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
    } rng;\n#line 3 \"src/math/zeta_transform.hpp\"\ntemplate <typename T>\nvoid superset_zeta_transform(vector<T>&\
    \ f, const bool inv = false) {\n    const int n = (int)f.size();\n    assert((n\
    \ & (n - 1)) == 0);\n    const int sign = inv ? -1 : 1;\n    for(int i = 1; i\
    \ < n; i <<= 1) {\n        for(int j = 0; j < n; ++j) {\n            if((j & i)\
    \ == 0) {\n                f[j] += sign * f[j | i];\n            }\n        }\n\
    \    }\n}\ntemplate <typename T>\nvoid subset_zeta_transform(vector<T>& f, const\
    \ bool inv = false) {\n    const int n = (int)f.size();\n    assert((n & (n -\
    \ 1)) == 0);\n    const int sign = inv ? -1 : 1;\n    for(int i = 1; i < n; i\
    \ <<= 1) {\n        for(int j = 0; j < n; ++j) {\n            if((j & i) == 0)\
    \ {\n                f[j | i] += sign * f[j];\n            }\n        }\n    }\n\
    }\n#line 4 \"src/convolution/or_convolution.hpp\"\ntemplate <typename T>\nvector<T>\
    \ or_convolution(vector<T> a, vector<T> b) {\n    const int n = (int)a.size(),\
    \ m = (int)b.size();\n    assert(n == m and (n & (n - 1)) == 0);\n    subset_zeta_transform(a);\n\
    \    subset_zeta_transform(b);\n    for(int i = 0; i < (int)a.size(); ++i) a[i]\
    \ *= b[i];\n    subset_zeta_transform(a, true);\n    return a;\n}\n#line 5 \"\
    verify/unit_test/convolution/or_convolution.test.cpp\"\nvoid test() {\n    int\
    \ n = 1 << rng(0, 12);\n    vector<ll> a(n), b(n);\n    rep(i, 0, n) a[i] = rng(-1000000,\
    \ 1000000);\n    rep(i, 0, n) b[i] = rng(-1000000, 1000000);\n    vector<ll> c\
    \ = or_convolution(a, b);\n    if(!n) {\n        assert(c.empty());\n        return;\n\
    \    }\n    vector<ll> expected(n);\n    rep(i, 0, n) {\n        rep(j, 0, n)\
    \ {\n            expected[i | j] += a[i] * b[j];\n        }\n    }\n    rep(i,\
    \ 0, n) {\n        assert(c[i] == expected[i]);\n    }\n}\nint main(void) {\n\
    \    constexpr int test_num = 100;\n    rep(_, 0, test_num) {\n        test();\n\
    \    }\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/template/random_number_generator.hpp\"\n#include \"\
    ../../../src/convolution/or_convolution.hpp\"\nvoid test() {\n    int n = 1 <<\
    \ rng(0, 12);\n    vector<ll> a(n), b(n);\n    rep(i, 0, n) a[i] = rng(-1000000,\
    \ 1000000);\n    rep(i, 0, n) b[i] = rng(-1000000, 1000000);\n    vector<ll> c\
    \ = or_convolution(a, b);\n    if(!n) {\n        assert(c.empty());\n        return;\n\
    \    }\n    vector<ll> expected(n);\n    rep(i, 0, n) {\n        rep(j, 0, n)\
    \ {\n            expected[i | j] += a[i] * b[j];\n        }\n    }\n    rep(i,\
    \ 0, n) {\n        assert(c[i] == expected[i]);\n    }\n}\nint main(void) {\n\
    \    constexpr int test_num = 100;\n    rep(_, 0, test_num) {\n        test();\n\
    \    }\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/random_number_generator.hpp
  - src/convolution/or_convolution.hpp
  - src/math/zeta_transform.hpp
  isVerificationFile: true
  path: verify/unit_test/convolution/or_convolution.test.cpp
  requiredBy: []
  timestamp: '2024-09-28 15:28:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/convolution/or_convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/convolution/or_convolution.test.cpp
- /verify/verify/unit_test/convolution/or_convolution.test.cpp.html
title: verify/unit_test/convolution/or_convolution.test.cpp
---
