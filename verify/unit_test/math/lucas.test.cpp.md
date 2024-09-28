---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/lucas.hpp
    title: Lucas
  - icon: ':heavy_check_mark:'
    path: src/math/miller_rabin.hpp
    title: miller_rabin
  - icon: ':heavy_check_mark:'
    path: src/template/dynamic_modint.hpp
    title: DynamicModint
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
  bundledCode: "#line 1 \"verify/unit_test/math/lucas.test.cpp\"\n#define PROBLEM\
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
    } rng;\n#line 3 \"src/template/dynamic_modint.hpp\"\nstruct Barrett {\n    explicit\
    \ Barrett(unsigned int m)\n        : _m(m), im((unsigned long long)(-1) / m +\
    \ 1) {}\n    inline unsigned int umod() const {\n        return _m;\n    }\n \
    \   inline unsigned int mul(unsigned int a, unsigned int b) const {\n        unsigned\
    \ long long z = a;\n        z *= b;\n        unsigned long long x = (unsigned\
    \ long long)(((unsigned __int128)(z)*im) >> 64);\n        unsigned int v = (unsigned\
    \ int)(z - x * _m);\n        if(_m <= v) v += _m;\n        return v;\n    }\n\n\
    \   private:\n    unsigned int _m;\n    unsigned long long im;\n};\ntemplate <int\
    \ id>\nstruct DynamicModint {\n    using mint = DynamicModint;\n    static int\
    \ mod() {\n        return (int)bt.umod();\n    }\n    static void set_mod(int\
    \ m) {\n        assert(1 <= m);\n        bt = Barrett(m);\n    }\n    static mint\
    \ raw(int v) {\n        mint a;\n        a._v = v;\n        return a;\n    }\n\
    \    DynamicModint()\n        : _v(0) {}\n    template <class T>\n    DynamicModint(const\
    \ T& v) {\n        static_assert(is_integral_v<T>);\n        if(is_signed_v<T>)\
    \ {\n            long long x = (long long)(v % (long long)(umod()));\n       \
    \     if(x < 0) x += umod();\n            _v = (unsigned int)(x);\n        } else\
    \ _v = (unsigned int)(v % umod());\n    }\n    unsigned int val() const {\n  \
    \      return _v;\n    }\n    mint& operator++() {\n        ++_v;\n        if(_v\
    \ == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--() {\n\
    \        if(_v == 0) _v = umod();\n        --_v;\n        return *this;\n    }\n\
    \    mint operator++(int) {\n        mint res = *this;\n        ++*this;\n   \
    \     return res;\n    }\n    mint operator--(int) {\n        mint res = *this;\n\
    \        --*this;\n        return res;\n    }\n    mint& operator+=(const mint&\
    \ rhs) {\n        _v += rhs._v;\n        if(_v >= umod()) _v -= umod();\n    \
    \    return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n        _v\
    \ += mod() - rhs._v;\n        if(_v >= umod()) _v -= umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        _v = bt.mul(_v, rhs._v);\n\
    \        return *this;\n    }\n    mint& operator/=(const mint& rhs) {\n     \
    \   return *this *= rhs.inv();\n    }\n    mint operator+() const {\n        return\
    \ *this;\n    }\n    mint operator-() const {\n        return mint() - *this;\n\
    \    }\n    mint pow(long long n) const {\n        assert(0 <= n);\n        if(n\
    \ == 0) return 1;\n        mint x = *this, r = 1;\n        while(1) {\n      \
    \      if(n & 1) r *= x;\n            n >>= 1;\n            if(n == 0) return\
    \ r;\n            x *= x;\n        }\n    }\n    mint inv() const {\n        auto\
    \ eg = inv_gcd(_v, mod());\n        assert(eg.first == 1);\n        return eg.second;\n\
    \    }\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n\
    \    }\n    friend istream& operator>>(istream& in, mint& x) {\n        long long\
    \ a;\n        in >> a;\n        x = a;\n        return in;\n    }\n    friend\
    \ ostream& operator<<(ostream& out, const mint& x) {\n        return out << x.val();\n\
    \    }\n\n   private:\n    unsigned int _v = 0;\n    static Barrett bt;\n    inline\
    \ static unsigned int umod() {\n        return bt.umod();\n    }\n    inline static\
    \ pair<long long, long long> inv_gcd(long long a, long long b) {\n        if(a\
    \ == 0) return {b, 0};\n        long long s = b, t = a, m0 = 0, m1 = 1;\n    \
    \    while(t) {\n            const long long u = s / t;\n            s -= t *\
    \ u;\n            m0 -= m1 * u;\n            swap(s, t);\n            swap(m0,\
    \ m1);\n        }\n        if(m0 < 0) m0 += b / s;\n        return {s, m0};\n\
    \    }\n};\ntemplate <int id>\nBarrett DynamicModint<id>::bt(998244353);\nusing\
    \ modint = DynamicModint<-1>;\n#line 3 \"src/math/lucas.hpp\"\ntemplate <typename\
    \ mint>\nstruct Lucas {\n    Lucas()\n        : mod(mint::mod()), fact(mint::mod()),\
    \ ifact(mint::mod()) {\n        fact[0] = 1;\n        for(int i = 1; i < mod;\
    \ ++i) fact[i] = fact[i - 1] * i;\n        ifact[mod - 1] = fact[mod - 1].inv();\n\
    \        for(int i = mod - 1; i >= 1; --i) ifact[i - 1] = ifact[i] * i;\n    }\n\
    \    mint operator()(long long n, long long k) {\n        if(n < 0 or n < k or\
    \ k < 0) return 0;\n        mint res = 1;\n        while(n > 0) {\n          \
    \  const long long n0 = n % mod, k0 = k % mod;\n            if(n0 < k0) return\
    \ 0;\n            res *= fact[n0] * ifact[k0] * ifact[n0 - k0];\n            n\
    \ /= mod;\n            k /= mod;\n        }\n        return res;\n    }\n\n  \
    \ private:\n    int mod;\n    vector<mint> fact, ifact;\n};\n#line 3 \"src/math/miller_rabin.hpp\"\
    \nconstexpr __int128_t pow_mod_128(__int128_t x, __int128_t n, const __int128_t\
    \ mod) {\n    assert(n >= 0 and mod >= 1);\n    x %= mod;\n    if(x < 0) x +=\
    \ mod;\n    __int128_t res = 1;\n    while(n > 0) {\n        if(n & 1) res = res\
    \ * x % mod;\n        x = x * x % mod;\n        n >>= 1;\n    }\n    return res;\n\
    }\nconstexpr bool miller_rabin(long long n) {\n    if(n <= 2) return n == 2;\n\
    \    if(n % 2 == 0) return false;\n    constexpr long long bases[7] = {2, 325,\
    \ 9375, 28178, 450775, 9780504, 1795265022};\n    long long d = n - 1;\n    while(d\
    \ % 2 == 0) d /= 2;\n    long long e = 1, rev = n - 1;\n    for(const long long\
    \ base : bases) {\n        if(base % n == 0) continue;\n        long long t =\
    \ d;\n        long long y = pow_mod_128(base, t, n);\n        while(t != n - 1\
    \ and y != e and y != rev) {\n            y = (__int128_t)y * y % n;\n       \
    \     t *= 2;\n        }\n        if(y != rev and t % 2 == 0) return false;\n\
    \    }\n    return true;\n}\n#line 7 \"verify/unit_test/math/lucas.test.cpp\"\n\
    using mint = modint;\nvoid test() {\n    static Lucas<mint> binom;\n    int n\
    \ = rng(1, 5000000), k = rng(0, k);\n    mint ans = 1;\n    rep(i, 1, k + 1) {\n\
    \        ans *= (n - i) / i;\n    }\n    assert(binom(n, k).val() == ans.val());\n\
    }\nint main(void) {\n    int p = 1;\n    while(!miller_rabin(p)) {\n        p\
    \ = rng(2, 1e8);\n    }\n    mint::set_mod(p);\n    constexpr int test_num = 1000;\n\
    \    rep(_, 0, test_num) {\n        test();\n    }\n    int a, b;\n    cin >>\
    \ a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/template/random_number_generator.hpp\"\n#include \"\
    ../../../src/template/dynamic_modint.hpp\"\n#include \"../../../src/math/lucas.hpp\"\
    \n#include \"../../../src/math/miller_rabin.hpp\"\nusing mint = modint;\nvoid\
    \ test() {\n    static Lucas<mint> binom;\n    int n = rng(1, 5000000), k = rng(0,\
    \ k);\n    mint ans = 1;\n    rep(i, 1, k + 1) {\n        ans *= (n - i) / i;\n\
    \    }\n    assert(binom(n, k).val() == ans.val());\n}\nint main(void) {\n   \
    \ int p = 1;\n    while(!miller_rabin(p)) {\n        p = rng(2, 1e8);\n    }\n\
    \    mint::set_mod(p);\n    constexpr int test_num = 1000;\n    rep(_, 0, test_num)\
    \ {\n        test();\n    }\n    int a, b;\n    cin >> a >> b;\n    cout << a\
    \ + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/random_number_generator.hpp
  - src/template/dynamic_modint.hpp
  - src/math/lucas.hpp
  - src/math/miller_rabin.hpp
  isVerificationFile: true
  path: verify/unit_test/math/lucas.test.cpp
  requiredBy: []
  timestamp: '2024-09-28 15:28:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math/lucas.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/lucas.test.cpp
- /verify/verify/unit_test/math/lucas.test.cpp.html
title: verify/unit_test/math/lucas.test.cpp
---
