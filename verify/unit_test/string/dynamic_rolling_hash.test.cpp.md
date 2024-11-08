---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/fenwick_tree.hpp
    title: FenwickTree
  - icon: ':heavy_check_mark:'
    path: src/string/dynamic_rolling_hash.hpp
    title: DynamicRollingHash
  - icon: ':heavy_check_mark:'
    path: src/template/modint_2_61m1.hpp
    title: Modint_2_61m1
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
  bundledCode: "#line 1 \"verify/unit_test/string/dynamic_rolling_hash.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
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
    } rng;\n#line 3 \"src/template/modint_2_61m1.hpp\"\nstruct Modint_2_61m1 {\n \
    \   using mint = Modint_2_61m1;\n    using u64 = uint64_t;\n    using u128 = __uint128_t;\n\
    \    static constexpr u64 mod() {\n        return m;\n    }\n    static constexpr\
    \ mint raw(const u64 v) {\n        mint a;\n        a._v = v;\n        return\
    \ a;\n    }\n    constexpr Modint_2_61m1()\n        : _v(0) {}\n    template <class\
    \ T>\n    constexpr Modint_2_61m1(const T& v) {\n        static_assert(is_integral_v<T>);\n\
    \        if constexpr(is_signed_v<T>) {\n            int64_t x = int64_t(v % int64_t(m));\n\
    \            if(x < 0) x += m;\n            _v = u64(x);\n        } else _v =\
    \ u64(v % m);\n    }\n    constexpr u64 val() const {\n        return _v;\n  \
    \  }\n    constexpr mint& operator++() {\n        return *this += 1;\n    }\n\
    \    constexpr mint& operator--() {\n        return *this -= 1;\n    }\n    constexpr\
    \ mint operator++(int) {\n        mint res = *this;\n        ++*this;\n      \
    \  return res;\n    }\n    constexpr mint operator--(int) {\n        mint res\
    \ = *this;\n        --*this;\n        return res;\n    }\n    constexpr mint&\
    \ operator+=(mint rhs) {\n        if(_v >= m - rhs._v) _v -= m;\n        _v +=\
    \ rhs._v;\n        return *this;\n    }\n    constexpr mint& operator-=(mint rhs)\
    \ {\n        if(_v < rhs._v) _v += m;\n        _v -= rhs._v;\n        return *this;\n\
    \    }\n    constexpr mint& operator*=(mint rhs) {\n        return *this = *this\
    \ * rhs;\n    }\n    constexpr mint& operator/=(mint rhs) {\n        return *this\
    \ *= rhs.inv();\n    }\n    constexpr mint operator+() const {\n        return\
    \ *this;\n    }\n    constexpr mint operator-() const {\n        return mint{}\
    \ - *this;\n    }\n    constexpr mint pow(u64 n) const {\n        if(n == 0) return\
    \ 1;\n        mint x = *this, r = 1;\n        while(1) {\n            if(n & 1)\
    \ r *= x;\n            n >>= 1;\n            if(n == 0) return r;\n          \
    \  x *= x;\n        }\n    }\n    constexpr mint inv() const {\n        assert(_v);\n\
    \        return pow(m - 2);\n    }\n    friend constexpr mint operator+(mint lhs,\
    \ mint rhs) {\n        return lhs += rhs;\n    }\n    friend constexpr mint operator-(mint\
    \ lhs, mint rhs) {\n        return lhs -= rhs;\n    }\n    friend constexpr mint\
    \ operator*(mint lhs, mint rhs) {\n        return raw(modulo(u128(lhs._v) * rhs._v));\n\
    \    }\n    friend constexpr mint operator/(mint lhs, mint rhs) {\n        return\
    \ lhs /= rhs;\n    }\n    friend constexpr bool operator==(mint lhs, mint rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend constexpr bool operator!=(mint\
    \ lhs, mint rhs) {\n        return lhs._v != rhs._v;\n    }\n    friend istream&\
    \ operator>>(istream& in, mint& x) {\n        long long a;\n        in >> a;\n\
    \        x = a;\n        return in;\n    }\n    friend ostream& operator<<(ostream&\
    \ out, const mint& x) {\n        return out << x.val();\n    }\n\n   private:\n\
    \    static constexpr u64 m = (1ull << 61) - 1;\n    u64 _v = 0;\n    inline static\
    \ constexpr u64 modulo(const u128& x) {\n        const u64 val = (x >> 61) + (x\
    \ & m);\n        return val >= m ? val - m : val;\n    }\n};\n#line 3 \"src/data_structure/fenwick_tree.hpp\"\
    \ntemplate <typename T>\nstruct FenwickTree {\n    FenwickTree(const int N)\n\
    \        : n(N), data(N) {}\n    void add(int p, const T& x) {\n        assert(0\
    \ <= p and p < n);\n        ++p;\n        while(p <= n) {\n            data[p\
    \ - 1] += x;\n            p += p & -p;\n        }\n    }\n    T sum(const int\
    \ l, const int r) const {\n        assert(0 <= l and l <= r and r <= n);\n   \
    \     return sum(r) - sum(l);\n    }\n    T get(const int x) const {\n       \
    \ assert(0 <= x and x < n);\n        return sum(x + 1) - sum(x);\n    }\n\n  \
    \ private:\n    int n;\n    vector<T> data;\n    inline T sum(int r) const {\n\
    \        T s = 0;\n        while(r > 0) {\n            s += data[r - 1];\n   \
    \         r -= r & -r;\n        }\n        return s;\n    }\n};\n#line 5 \"src/string/dynamic_rolling_hash.hpp\"\
    \nstruct DynamicRollingHash {\n    using mint = Modint_2_61m1;\n    DynamicRollingHash(const\
    \ string& s, unsigned long long BASE = 0)\n        : len((int)s.size()), pow(len\
    \ + 1), inv_pow(len + 1), hash(len) {\n        if(BASE == 0) {\n            mt19937\
    \ mt(chrono::steady_clock::now().time_since_epoch().count());\n            uniform_int_distribution<unsigned\
    \ long long> dist(1ull << 10, 1ull << 60);\n            BASE = dist(mt);\n   \
    \     }\n        base = BASE;\n        pow[0] = 1;\n        for(int i = 0; i <\
    \ len; ++i) {\n            pow[i + 1] = pow[i] * base;\n        }\n        inv\
    \ = base.inv();\n        inv_pow[0] = 1;\n        for(int i = 0; i < len; ++i)\
    \ {\n            inv_pow[i + 1] = inv_pow[i] * inv;\n        }\n        for(int\
    \ i = 0; i < len; ++i) {\n            hash.add(i, pow[i] * s[i]);\n        }\n\
    \    }\n    unsigned long long get(const int lower, const int upper) const {\n\
    \        assert(0 <= lower and lower <= upper and upper <= len);\n        return\
    \ (hash.sum(lower, upper) * inv_pow[lower]).val();\n    }\n    unsigned long long\
    \ get_hash(const string& t) const {\n        mint res = 0;\n        for(int i\
    \ = 0; i < (int)t.size(); ++i) {\n            res += pow[i] * t[i];\n        }\n\
    \        return res.val();\n    }\n    void set(const int idx, const char c) {\n\
    \        assert(0 <= idx and idx < len);\n        hash.add(idx, pow[idx] * c -\
    \ hash.get(idx));\n    }\n\n   private:\n    int len;\n    mint base, inv;\n \
    \   vector<mint> pow, inv_pow;\n    FenwickTree<mint> hash;\n};\n#line 6 \"verify/unit_test/string/dynamic_rolling_hash.test.cpp\"\
    \nusing mint = Modint_2_61m1;\nvoid test() {\n    int n = rng(1, 2000), q = 2000;\n\
    \    string s = \"\";\n    rep(i, 0, n) {\n        s += 'a' + rng(0, 25);\n  \
    \  }\n    ll base = rng(1ll << 10, 1ll << 60);\n    DynamicRollingHash drh(s,\
    \ base);\n    while(q--) {\n        int type = rng(0, 1);\n        if(type ==\
    \ 0) {\n            int len = rng(0, n);\n            int l = rng(0, n - len),\
    \ r = l + len;\n            mint ans = 0, b = 1;\n            rep(i, l, r) {\n\
    \                ans += b * s[i];\n                b *= base;\n            }\n\
    \            assert(drh.get(l, r) == ans.val());\n        } else {\n         \
    \   int idx = rng(0, n - 1);\n            char c = 'a' + rng(0, 25);\n       \
    \     s[idx] = c;\n            drh.set(idx, c);\n        }\n    }\n}\nint main(void)\
    \ {\n    constexpr int test_num = 100;\n    rep(_, 0, test_num) {\n        test();\n\
    \    }\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/template/random_number_generator.hpp\"\n#include \"\
    ../../../src/template/modint_2_61m1.hpp\"\n#include \"../../../src/string/dynamic_rolling_hash.hpp\"\
    \nusing mint = Modint_2_61m1;\nvoid test() {\n    int n = rng(1, 2000), q = 2000;\n\
    \    string s = \"\";\n    rep(i, 0, n) {\n        s += 'a' + rng(0, 25);\n  \
    \  }\n    ll base = rng(1ll << 10, 1ll << 60);\n    DynamicRollingHash drh(s,\
    \ base);\n    while(q--) {\n        int type = rng(0, 1);\n        if(type ==\
    \ 0) {\n            int len = rng(0, n);\n            int l = rng(0, n - len),\
    \ r = l + len;\n            mint ans = 0, b = 1;\n            rep(i, l, r) {\n\
    \                ans += b * s[i];\n                b *= base;\n            }\n\
    \            assert(drh.get(l, r) == ans.val());\n        } else {\n         \
    \   int idx = rng(0, n - 1);\n            char c = 'a' + rng(0, 25);\n       \
    \     s[idx] = c;\n            drh.set(idx, c);\n        }\n    }\n}\nint main(void)\
    \ {\n    constexpr int test_num = 100;\n    rep(_, 0, test_num) {\n        test();\n\
    \    }\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/random_number_generator.hpp
  - src/template/modint_2_61m1.hpp
  - src/string/dynamic_rolling_hash.hpp
  - src/data_structure/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/unit_test/string/dynamic_rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 01:50:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/string/dynamic_rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/string/dynamic_rolling_hash.test.cpp
- /verify/verify/unit_test/string/dynamic_rolling_hash.test.cpp.html
title: verify/unit_test/string/dynamic_rolling_hash.test.cpp
---
