---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/divisor.hpp
    title: divisor
  - icon: ':heavy_check_mark:'
    path: src/math/eratosthenes_sieve.hpp
    title: EratosthenesSieve
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
  - icon: ':heavy_check_mark:'
    path: src/random/random_number_generator.hpp
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
  bundledCode: "#line 1 \"verify/unit_test/math/eratosthenes_sieve.test.cpp\"\n#define\
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
    } rng;\n#line 3 \"src/math/eratosthenes_sieve.hpp\"\nstruct EratosthenesSieve\
    \ {\n    vector<int> primes, min_factor, moebius, euler;\n    EratosthenesSieve(const\
    \ int N)\n        : primes(), min_factor(N + 1), moebius(N + 1, 1), euler(N +\
    \ 1), N(N) {\n        assert(N >= 1);\n        iota(min_factor.begin(), min_factor.end(),\
    \ 0);\n        min_factor[0] = min_factor[1] = -1;\n        iota(euler.begin(),\
    \ euler.end(), 0);\n        for(int i = 2; i <= N; ++i) {\n            if(min_factor[i]\
    \ < i) continue;\n            primes.emplace_back(i);\n            moebius[i]\
    \ = -1;\n            euler[i] = euler[i] / i * (i - 1);\n            for(int j\
    \ = i * 2; j <= N; j += i) {\n                if(min_factor[j] == j) min_factor[j]\
    \ = i;\n                if((j / i) % i == 0) moebius[j] = 0;\n               \
    \ else moebius[j] = -moebius[j];\n                euler[j] = euler[j] / i * (i\
    \ - 1);\n            }\n        }\n    }\n    vector<pair<int, int>> prime_factors(int\
    \ n) const {\n        assert(1 <= n and n <= N);\n        vector<pair<int, int>>\
    \ res;\n        while(n > 1) {\n            const int p = min_factor[n];\n   \
    \         int exp = 0;\n            while(min_factor[n] == p) {\n            \
    \    n /= p;\n                ++exp;\n            }\n            res.emplace_back(p,\
    \ exp);\n        }\n        return res;\n    }\n    vector<int> divisor(const\
    \ int n) const {\n        assert(1 <= n and n <= n);\n        vector<int> res({1});\n\
    \        const auto pf = prime_factors(n);\n        for(const auto& p : pf) {\n\
    \            const int s = (int)res.size();\n            for(int i = 0; i < s;\
    \ ++i) {\n                int v = 1;\n                for(int j = 0; j < p.second;\
    \ ++j) {\n                    v *= p.first;\n                    res.push_back(res[i]\
    \ * v);\n                }\n            }\n        }\n        sort(res.begin(),\
    \ res.end());\n        return res;\n    }\n\n   private:\n    int N;\n};\n#line\
    \ 3 \"src/math/is_prime.hpp\"\nconstexpr bool is_prime(const long long n) {\n\
    \    if(n <= 1) return false;\n    for(long long i = 2; i * i <= n; ++i) {\n \
    \       if(n % i == 0) return false;\n    }\n    return true;\n}\n#line 3 \"src/math/euler_phi.hpp\"\
    \nconstexpr long long euler_phi(long long n) {\n    long long res = max(n, 0ll);\n\
    \    for(long long i = 2; i * i <= n; ++i) {\n        if(n % i == 0) {\n     \
    \       res -= res / i;\n            while(n % i == 0) n /= i;\n        }\n  \
    \  }\n    if(n > 1) res -= res / n;\n    return res;\n}\n#line 3 \"src/math/prime_factors.hpp\"\
    \nvector<pair<long long, int>> prime_factors(long long n) {\n    assert(n >= 1);\n\
    \    vector<pair<long long, int>> res;\n    for(long long i = 2; i * i <= n; ++i)\
    \ {\n        if(n % i == 0) {\n            res.emplace_back(i, 0);\n         \
    \   while(n % i == 0) {\n                n /= i;\n                ++res.back().second;\n\
    \            }\n        }\n    }\n    if(n >= 2) res.emplace_back(n, 1);\n   \
    \ return res;\n}\n#line 4 \"src/math/moebius.hpp\"\nint moebius(const long long\
    \ n) {\n    assert(n >= 1);\n    if(n == 1) return 1;\n    const vector<pair<long\
    \ long, int>> p = prime_factors(n);\n    int res = 1;\n    for(const auto& it\
    \ : p) {\n        if(it.second >= 2) return 0;\n        res = -res;\n    }\n \
    \   return res;\n}\n#line 3 \"src/math/divisor.hpp\"\nvector<long long> divisor(const\
    \ long long n) {\n    assert(n >= 1);\n    vector<long long> res;\n    for(long\
    \ long i = 1; i * i <= n; ++i) {\n        if(n % i == 0) {\n            res.push_back(i);\n\
    \            if(i * i != n) res.emplace_back(n / i);\n        }\n    }\n    sort(res.begin(),\
    \ res.end());\n    return res;\n}\n#line 10 \"verify/unit_test/math/eratosthenes_sieve.test.cpp\"\
    \nvoid test() {\n    EratosthenesSieve sieve(10000000);\n    rep(i, 0, 10000)\
    \ {\n        int n = rng(1, 10000000);\n        if(is_prime(n)) {\n          \
    \  assert(sieve.min_factor[n] == n);\n        } else {\n            assert(sieve.min_factor[n]\
    \ != n);\n        }\n        if(is_prime(i)) {\n            assert(sieve.min_factor[i]\
    \ == i);\n        } else {\n            assert(sieve.min_factor[i] != i);\n  \
    \      }\n        assert(euler_phi(n) == sieve.euler[n]);\n        assert(moebius(n)\
    \ == sieve.moebius[n]);\n    }\n    rep(i, 1, 100) {\n        if(is_prime(i))\
    \ {\n            assert(sieve.min_factor[i] == i);\n        } else {\n       \
    \     assert(sieve.min_factor[i] != i);\n        }\n        assert(euler_phi(i)\
    \ == sieve.euler[i]);\n        assert(moebius(i) == sieve.moebius[i]);\n    }\n\
    \    rep(i, 1, 10000) {\n        int n = rng(1, 10000000);\n        vector<pair<int,\
    \ int>> pf1 = sieve.prime_factors(n);\n        vector<pair<long long, int>> pf2\
    \ = prime_factors(n);\n        assert(pf1.size() == pf2.size());\n        for(int\
    \ i = 0; i < (int)pf1.size(); ++i) {\n            assert(pf1[i].first == pf2[i].first);\n\
    \            assert(pf1[i].second == pf2[i].second);\n        }\n        vector<int>\
    \ d1 = sieve.divisor(n);\n        vector<ll> d2 = divisor(n);\n        assert(d1.size()\
    \ == d2.size());\n        for(int i = 0; i < (int)d1.size(); ++i) {\n        \
    \    assert(d1[i] == d2[i]);\n        }\n    }\n}\nint main(void) {\n    test();\n\
    \    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/random/random_number_generator.hpp\"\n#include \"../../../src/math/eratosthenes_sieve.hpp\"\
    \n#include \"../../../src/math/is_prime.hpp\"\n#include \"../../../src/math/euler_phi.hpp\"\
    \n#include \"../../../src/math/moebius.hpp\"\n#include \"../../../src/math/divisor.hpp\"\
    \n#include \"../../../src/math/prime_factors.hpp\"\nvoid test() {\n    EratosthenesSieve\
    \ sieve(10000000);\n    rep(i, 0, 10000) {\n        int n = rng(1, 10000000);\n\
    \        if(is_prime(n)) {\n            assert(sieve.min_factor[n] == n);\n  \
    \      } else {\n            assert(sieve.min_factor[n] != n);\n        }\n  \
    \      if(is_prime(i)) {\n            assert(sieve.min_factor[i] == i);\n    \
    \    } else {\n            assert(sieve.min_factor[i] != i);\n        }\n    \
    \    assert(euler_phi(n) == sieve.euler[n]);\n        assert(moebius(n) == sieve.moebius[n]);\n\
    \    }\n    rep(i, 1, 100) {\n        if(is_prime(i)) {\n            assert(sieve.min_factor[i]\
    \ == i);\n        } else {\n            assert(sieve.min_factor[i] != i);\n  \
    \      }\n        assert(euler_phi(i) == sieve.euler[i]);\n        assert(moebius(i)\
    \ == sieve.moebius[i]);\n    }\n    rep(i, 1, 10000) {\n        int n = rng(1,\
    \ 10000000);\n        vector<pair<int, int>> pf1 = sieve.prime_factors(n);\n \
    \       vector<pair<long long, int>> pf2 = prime_factors(n);\n        assert(pf1.size()\
    \ == pf2.size());\n        for(int i = 0; i < (int)pf1.size(); ++i) {\n      \
    \      assert(pf1[i].first == pf2[i].first);\n            assert(pf1[i].second\
    \ == pf2[i].second);\n        }\n        vector<int> d1 = sieve.divisor(n);\n\
    \        vector<ll> d2 = divisor(n);\n        assert(d1.size() == d2.size());\n\
    \        for(int i = 0; i < (int)d1.size(); ++i) {\n            assert(d1[i] ==\
    \ d2[i]);\n        }\n    }\n}\nint main(void) {\n    test();\n    int a, b;\n\
    \    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/random/random_number_generator.hpp
  - src/math/eratosthenes_sieve.hpp
  - src/math/is_prime.hpp
  - src/math/euler_phi.hpp
  - src/math/moebius.hpp
  - src/math/prime_factors.hpp
  - src/math/divisor.hpp
  isVerificationFile: true
  path: verify/unit_test/math/eratosthenes_sieve.test.cpp
  requiredBy: []
  timestamp: '2025-04-27 00:17:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math/eratosthenes_sieve.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/eratosthenes_sieve.test.cpp
- /verify/verify/unit_test/math/eratosthenes_sieve.test.cpp.html
title: verify/unit_test/math/eratosthenes_sieve.test.cpp
---
