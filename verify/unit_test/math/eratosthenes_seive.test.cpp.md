---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/eratosthenes_seive.hpp
    title: EratosthenesSeive
  - icon: ':heavy_check_mark:'
    path: src/math/euler_phi.hpp
    title: euler_phi
  - icon: ':heavy_check_mark:'
    path: src/math/is_prime.hpp
    title: is_prime
  - icon: ':heavy_check_mark:'
    path: src/math/moebius.hpp
    title: moebius
  - icon: ':heavy_check_mark:'
    path: src/math/prime_factors.hpp
    title: prime_factors
  - icon: ':question:'
    path: src/template/random_number_generator.hpp
    title: RandomNumberGenerator
  - icon: ':question:'
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
  bundledCode: "#line 1 \"verify/unit_test/math/eratosthenes_seive.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
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
    } rng;\n#line 3 \"src/math/eratosthenes_seive.hpp\"\nstruct EratosthenesSeive\
    \ {\n    vector<int> primes, min_factor, moebius, euler;\n    EratosthenesSeive(const\
    \ int n)\n        : primes(), min_factor(n + 1), moebius(n + 1, 1), euler(n +\
    \ 1) {\n        assert(n >= 1);\n        iota(min_factor.begin(), min_factor.end(),\
    \ 0);\n        min_factor[0] = min_factor[1] = -1;\n        iota(euler.begin(),\
    \ euler.end(), 0);\n        for(int i = 2; i <= n; ++i) {\n            if(min_factor[i]\
    \ < i) continue;\n            primes.emplace_back(i);\n            moebius[i]\
    \ = -1;\n            euler[i] = euler[i] / i * (i - 1);\n            for(int j\
    \ = i * 2; j <= n; j += i) {\n                if(min_factor[j] == j) min_factor[j]\
    \ = i;\n                if((j / i) % i == 0) moebius[j] = 0;\n               \
    \ else moebius[j] = -moebius[j];\n                euler[j] = euler[j] / i * (i\
    \ - 1);\n            }\n        }\n    }\n};\n#line 3 \"src/math/is_prime.hpp\"\
    \nconstexpr bool is_prime(long long n) {\n    if(n <= 1) return false;\n    for(long\
    \ long i = 2; i * i <= n; ++i) {\n        if(n % i == 0) return false;\n    }\n\
    \    return true;\n}\n#line 3 \"src/math/euler_phi.hpp\"\nlong long euler_phi(long\
    \ long n) {\n    long long res = max(n, 0ll);\n    for(long long i = 2; i * i\
    \ <= n; ++i) {\n        if(n % i == 0) {\n            res -= res / i;\n      \
    \      while(n % i == 0) n /= i;\n        }\n    }\n    if(n > 1) res -= res /\
    \ n;\n    return res;\n}\n#line 3 \"src/math/prime_factors.hpp\"\nvector<pair<long\
    \ long, int>> prime_factors(long long n) {\n    assert(n >= 1);\n    vector<pair<long\
    \ long, int>> res;\n    for(long long i = 2; i * i <= n; ++i) {\n        if(n\
    \ % i == 0) {\n            res.emplace_back(i, 0);\n            while(n % i ==\
    \ 0) {\n                n /= i;\n                ++res.back().second;\n      \
    \      }\n        }\n    }\n    if(n >= 2) res.emplace_back(n, 1);\n    return\
    \ res;\n}\n#line 4 \"src/math/moebius.hpp\"\nint moebius(const long long n) {\n\
    \    assert(n >= 1);\n    if(n == 1) return 1;\n    vector<pair<long long, int>>\
    \ p = prime_factors(n);\n    int res = 1;\n    for(const auto& it : p) {\n   \
    \     if(it.second >= 2) return 0;\n        res = -res;\n    }\n    return res;\n\
    }\n#line 8 \"verify/unit_test/math/eratosthenes_seive.test.cpp\"\nvoid test()\
    \ {\n    EratosthenesSeive seive(10000000);\n    rep(i, 0, 10000) {\n        int\
    \ n = rng(1, 10000000);\n        if(is_prime(n)) {\n            assert(seive.min_factor[n]\
    \ == n);\n        } else {\n            assert(seive.min_factor[n] != n);\n  \
    \      }\n        if(is_prime(i)) {\n            assert(seive.min_factor[i] ==\
    \ i);\n        } else {\n            assert(seive.min_factor[i] != i);\n     \
    \   }\n        assert(euler_phi(n) == seive.euler[n]);\n        assert(moebius(n)\
    \ == seive.moebius[n]);\n    }\n    rep(i, 1, 100) {\n        if(is_prime(i))\
    \ {\n            assert(seive.min_factor[i] == i);\n        } else {\n       \
    \     assert(seive.min_factor[i] != i);\n        }\n        assert(euler_phi(i)\
    \ == seive.euler[i]);\n        assert(moebius(i) == seive.moebius[i]);\n    }\n\
    }\nint main(void) {\n    test();\n    int a, b;\n    cin >> a >> b;\n    cout\
    \ << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/template/random_number_generator.hpp\"\n#include \"\
    ../../../src/math/eratosthenes_seive.hpp\"\n#include \"../../../src/math/is_prime.hpp\"\
    \n#include \"../../../src/math/euler_phi.hpp\"\n#include \"../../../src/math/moebius.hpp\"\
    \nvoid test() {\n    EratosthenesSeive seive(10000000);\n    rep(i, 0, 10000)\
    \ {\n        int n = rng(1, 10000000);\n        if(is_prime(n)) {\n          \
    \  assert(seive.min_factor[n] == n);\n        } else {\n            assert(seive.min_factor[n]\
    \ != n);\n        }\n        if(is_prime(i)) {\n            assert(seive.min_factor[i]\
    \ == i);\n        } else {\n            assert(seive.min_factor[i] != i);\n  \
    \      }\n        assert(euler_phi(n) == seive.euler[n]);\n        assert(moebius(n)\
    \ == seive.moebius[n]);\n    }\n    rep(i, 1, 100) {\n        if(is_prime(i))\
    \ {\n            assert(seive.min_factor[i] == i);\n        } else {\n       \
    \     assert(seive.min_factor[i] != i);\n        }\n        assert(euler_phi(i)\
    \ == seive.euler[i]);\n        assert(moebius(i) == seive.moebius[i]);\n    }\n\
    }\nint main(void) {\n    test();\n    int a, b;\n    cin >> a >> b;\n    cout\
    \ << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/random_number_generator.hpp
  - src/math/eratosthenes_seive.hpp
  - src/math/is_prime.hpp
  - src/math/euler_phi.hpp
  - src/math/moebius.hpp
  - src/math/prime_factors.hpp
  isVerificationFile: true
  path: verify/unit_test/math/eratosthenes_seive.test.cpp
  requiredBy: []
  timestamp: '2024-11-07 21:02:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math/eratosthenes_seive.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/eratosthenes_seive.test.cpp
- /verify/verify/unit_test/math/eratosthenes_seive.test.cpp.html
title: verify/unit_test/math/eratosthenes_seive.test.cpp
---
