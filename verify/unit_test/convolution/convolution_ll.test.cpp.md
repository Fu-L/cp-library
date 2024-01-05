---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/convolution.hpp
    title: convolution
  - icon: ':heavy_check_mark:'
    path: src/convolution/convolution_ll.hpp
    title: convolution_ll
  - icon: ':heavy_check_mark:'
    path: src/math/pow_mod.hpp
    title: pow_mod
  - icon: ':heavy_check_mark:'
    path: src/math/primitive_root.hpp
    title: primitive_root
  - icon: ':heavy_check_mark:'
    path: src/template/random_number_generator.hpp
    title: RandomNumberGenerator
  - icon: ':heavy_check_mark:'
    path: src/template/static_modint.hpp
    title: StaticModint
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
  bundledCode: "#line 1 \"verify/unit_test/convolution/convolution_ll.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i,\
    \ a, b) for(ll i = a; i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n\
    \    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n    \
    \    cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/template/random_number_generator.hpp\"\
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
    \ true) {\n        assert(1 <= n and n <= (int)2e5);\n        vector<int> u(n\
    \ - 1), v(n - 1);\n        vector<ll> pruefer = vec(n - 2, 0, n - 1);\n      \
    \  set<int> st;\n        vector<int> cnt(n);\n        for(int i = 0; i < n; ++i)\
    \ st.insert(i);\n        auto add = [&](int x) -> void {\n            if(x > n)\
    \ return;\n            if(cnt[x] == 0) st.erase(x);\n            ++cnt[x];\n \
    \       };\n        auto del = [&](int x) -> void {\n            if(x > n) return;\n\
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
    \         --N;\n            }\n        }\n        return res;\n    }\n} rng;\n\
    #line 3 \"src/template/static_modint.hpp\"\ntemplate <uint32_t m>\nstruct StaticModint\
    \ {\n    using mint = StaticModint;\n    static constexpr uint32_t mod() {\n \
    \       return m;\n    }\n    static constexpr mint raw(uint32_t v) {\n      \
    \  mint a;\n        a._v = v;\n        return a;\n    }\n    constexpr StaticModint()\n\
    \        : _v(0) {}\n    template <class T>\n    constexpr StaticModint(const\
    \ T& v) {\n        static_assert(is_integral_v<T>);\n        if constexpr(is_signed_v<T>)\
    \ {\n            int64_t x = int64_t(v % int64_t(m));\n            if(x < 0) x\
    \ += m;\n            _v = uint32_t(x);\n        } else _v = uint32_t(v % m);\n\
    \    }\n    constexpr uint32_t val() const {\n        return _v;\n    }\n    constexpr\
    \ mint& operator++() {\n        return *this += 1;\n    }\n    constexpr mint&\
    \ operator--() {\n        return *this -= 1;\n    }\n    constexpr mint operator++(int)\
    \ {\n        mint res = *this;\n        ++*this;\n        return res;\n    }\n\
    \    constexpr mint operator--(int) {\n        mint res = *this;\n        --*this;\n\
    \        return res;\n    }\n    constexpr mint& operator+=(mint rhs) {\n    \
    \    if(_v >= m - rhs._v) _v -= m;\n        _v += rhs._v;\n        return *this;\n\
    \    }\n    constexpr mint& operator-=(mint rhs) {\n        if(_v < rhs._v) _v\
    \ += m;\n        _v -= rhs._v;\n        return *this;\n    }\n    constexpr mint&\
    \ operator*=(mint rhs) {\n        return *this = *this * rhs;\n    }\n    constexpr\
    \ mint& operator/=(mint rhs) {\n        return *this *= rhs.inv();\n    }\n  \
    \  constexpr mint operator+() const {\n        return *this;\n    }\n    constexpr\
    \ mint operator-() const {\n        return mint{} - *this;\n    }\n    constexpr\
    \ mint pow(long long n) const {\n        assert(0 <= n);\n        if(n == 0) return\
    \ 1;\n        mint x = *this, r = 1;\n        while(1) {\n            if(n & 1)\
    \ r *= x;\n            n >>= 1;\n            if(n == 0) return r;\n          \
    \  x *= x;\n        }\n    }\n    constexpr mint inv() const {\n        if constexpr(prime)\
    \ {\n            assert(_v);\n            return pow(m - 2);\n        } else {\n\
    \            auto eg = inv_gcd(_v, m);\n            assert(eg.first == 1);\n \
    \           return eg.second;\n        }\n    }\n    friend constexpr mint operator+(mint\
    \ lhs, mint rhs) {\n        return lhs += rhs;\n    }\n    friend constexpr mint\
    \ operator-(mint lhs, mint rhs) {\n        return lhs -= rhs;\n    }\n    friend\
    \ constexpr mint operator*(mint lhs, mint rhs) {\n        return uint64_t(lhs._v)\
    \ * rhs._v;\n    }\n    friend constexpr mint operator/(mint lhs, mint rhs) {\n\
    \        return lhs /= rhs;\n    }\n    friend constexpr bool operator==(mint\
    \ lhs, mint rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend constexpr\
    \ bool operator!=(mint lhs, mint rhs) {\n        return lhs._v != rhs._v;\n  \
    \  }\n    friend istream& operator>>(istream& in, mint& x) {\n        long long\
    \ a;\n        in >> a;\n        x = a;\n        return in;\n    }\n    friend\
    \ ostream& operator<<(ostream& out, const mint& x) {\n        return out << x.val();\n\
    \    }\n\n   private:\n    uint32_t _v = 0;\n    static constexpr bool prime =\
    \ []() -> bool {\n        if(m == 1) return 0;\n        if(m == 2 or m == 7 or\
    \ m == 61) return 1;\n        if(m % 2 == 0) return 0;\n        uint32_t d = m\
    \ - 1;\n        while(d % 2 == 0) d /= 2;\n        for(uint32_t a : {2, 7, 61})\
    \ {\n            uint32_t t = d;\n            mint y = mint(a).pow(t);\n     \
    \       while(t != m - 1 && y != 1 && y != m - 1) {\n                y *= y;\n\
    \                t <<= 1;\n            }\n            if(y != m - 1 && t % 2 ==\
    \ 0) return 0;\n        }\n        return 1;\n    }();\n    static constexpr pair<int32_t,\
    \ int32_t> inv_gcd(int32_t a, int32_t b) {\n        if(a == 0) return {b, 0};\n\
    \        int32_t s = b, t = a, m0 = 0, m1 = 1;\n        while(t) {\n         \
    \   const int32_t u = s / t;\n            s -= t * u;\n            m0 -= m1 *\
    \ u;\n            swap(s, t);\n            swap(m0, m1);\n        }\n        if(m0\
    \ < 0) m0 += b / s;\n        return {s, m0};\n    }\n};\nusing modint998244353\
    \ = StaticModint<998244353>;\nusing modint1000000007 = StaticModint<1000000007>;\n\
    #line 3 \"src/math/pow_mod.hpp\"\nconstexpr ll pow_mod(ll x, ll n, ll mod) {\n\
    \    assert(n >= 0 and mod >= 1);\n    x %= mod;\n    if(x < 0) x += mod;\n  \
    \  ll res = 1;\n    while(n > 0) {\n        if(n & 1) res = res * x % mod;\n \
    \       x = x * x % mod;\n        n >>= 1;\n    }\n    return res;\n}\n#line 4\
    \ \"src/math/primitive_root.hpp\"\nconstexpr int primitive_root(int m) {\n   \
    \ if(m == 2) return 1;\n    if(m == 167772161) return 3;\n    if(m == 469762049)\
    \ return 3;\n    if(m == 754974721) return 11;\n    if(m == 998244353) return\
    \ 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while(x % 2 == 0) x /= 2;\n    for(int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if(x % i == 0) {\n            divs[cnt++] = i;\n  \
    \          while(x % i == 0) {\n                x /= i;\n            }\n     \
    \   }\n    }\n    if(x > 1) {\n        divs[cnt++] = x;\n    }\n    for(int g\
    \ = 2;; ++g) {\n        bool ok = true;\n        for(int i = 0; i < cnt; ++i)\
    \ {\n            if(pow_mod(g, (m - 1) / divs[i], m) == 1) {\n               \
    \ ok = false;\n                break;\n            }\n        }\n        if(ok)\
    \ return g;\n    }\n}\n#line 4 \"src/convolution/convolution.hpp\"\nconstexpr\
    \ int countr_zero(unsigned int n) {\n    int res = 0;\n    while(!(n & (1 << res)))\
    \ ++res;\n    return res;\n}\ntemplate <typename mint, int g = primitive_root(mint::mod())>\n\
    struct FFT_Info {\n    static constexpr int rank2 = countr_zero(mint::mod() -\
    \ 1);\n    array<mint, rank2 + 1> root;\n    array<mint, rank2 + 1> iroot;\n \
    \   array<mint, max(0, rank2 - 2 + 1)> rate2;\n    array<mint, max(0, rank2 -\
    \ 2 + 1)> irate2;\n    array<mint, max(0, rank2 - 3 + 1)> rate3;\n    array<mint,\
    \ max(0, rank2 - 3 + 1)> irate3;\n    FFT_Info() {\n        root[rank2] = mint(g).pow((mint::mod()\
    \ - 1) >> rank2);\n        iroot[rank2] = root[rank2].inv();\n        for(int\
    \ i = rank2 - 1; i >= 0; --i) {\n            root[i] = root[i + 1] * root[i +\
    \ 1];\n            iroot[i] = iroot[i + 1] * iroot[i + 1];\n        }\n      \
    \  {\n            mint prod = 1, iprod = 1;\n            for(int i = 0; i <= rank2\
    \ - 2; ++i) {\n                rate2[i] = root[i + 2] * prod;\n              \
    \  irate2[i] = iroot[i + 2] * iprod;\n                prod *= iroot[i + 2];\n\
    \                iprod *= root[i + 2];\n            }\n        }\n        {\n\
    \            mint prod = 1, iprod = 1;\n            for(int i = 0; i <= rank2\
    \ - 3; ++i) {\n                rate3[i] = root[i + 3] * prod;\n              \
    \  irate3[i] = iroot[i + 3] * iprod;\n                prod *= iroot[i + 3];\n\
    \                iprod *= root[i + 3];\n            }\n        }\n    }\n};\n\
    template <typename mint>\nvoid butterfly(vector<mint>& a) {\n    int n = (int)a.size();\n\
    \    int h = __builtin_ctz((unsigned int)n);\n    static const FFT_Info<mint>\
    \ info;\n    int len = 0;\n    while(len < h) {\n        if(h - len == 1) {\n\
    \            int p = 1 << (h - len - 1);\n            mint rot = 1;\n        \
    \    for(int s = 0; s < (1 << len); ++s) {\n                int offset = s <<\
    \ (h - len);\n                for(int i = 0; i < p; ++i) {\n                 \
    \   auto l = a[i + offset];\n                    auto r = a[i + offset + p] *\
    \ rot;\n                    a[i + offset] = l + r;\n                    a[i +\
    \ offset + p] = l - r;\n                }\n                if(s + 1 != (1 << len))\
    \ rot *= info.rate2[__builtin_ctz(~(unsigned int)(s))];\n            }\n     \
    \       ++len;\n        } else {\n            int p = 1 << (h - len - 2);\n  \
    \          mint rot = 1, imag = info.root[2];\n            for(int s = 0; s <\
    \ (1 << len); ++s) {\n                mint rot2 = rot * rot;\n               \
    \ mint rot3 = rot2 * rot;\n                int offset = s << (h - len);\n    \
    \            for(int i = 0; i < p; ++i) {\n                    auto mod2 = 1ULL\
    \ * mint::mod() * mint::mod();\n                    auto a0 = 1ULL * a[i + offset].val();\n\
    \                    auto a1 = 1ULL * a[i + offset + p].val() * rot.val();\n \
    \                   auto a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();\n\
    \                    auto a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();\n\
    \                    auto a1na3imag = 1ULL * mint(a1 + mod2 - a3).val() * imag.val();\n\
    \                    auto na2 = mod2 - a2;\n                    a[i + offset]\
    \ = a0 + a2 + a1 + a3;\n                    a[i + offset + 1 * p] = a0 + a2 +\
    \ (2 * mod2 - (a1 + a3));\n                    a[i + offset + 2 * p] = a0 + na2\
    \ + a1na3imag;\n                    a[i + offset + 3 * p] = a0 + na2 + (mod2 -\
    \ a1na3imag);\n                }\n                if(s + 1 != (1 << len)) rot\
    \ *= info.rate3[__builtin_ctz(~(unsigned int)(s))];\n            }\n         \
    \   len += 2;\n        }\n    }\n}\ntemplate <typename mint>\nvoid butterfly_inv(vector<mint>&\
    \ a) {\n    int n = (int)a.size();\n    int h = __builtin_ctz((unsigned int)n);\n\
    \    static const FFT_Info<mint> info;\n    int len = h;\n    while(len) {\n \
    \       if(len == 1) {\n            int p = 1 << (h - len);\n            mint\
    \ irot = 1;\n            for(int s = 0; s < (1 << (len - 1)); ++s) {\n       \
    \         int offset = s << (h - len + 1);\n                for(int i = 0; i <\
    \ p; ++i) {\n                    auto l = a[i + offset];\n                   \
    \ auto r = a[i + offset + p];\n                    a[i + offset] = l + r;\n  \
    \                  a[i + offset + p] = (unsigned long long)(mint::mod() + l.val()\
    \ - r.val()) * irot.val();\n                }\n                if(s + 1 != (1\
    \ << (len - 1))) irot *= info.irate2[__builtin_ctz(~(unsigned int)(s))];\n   \
    \         }\n            --len;\n        } else {\n            int p = 1 << (h\
    \ - len);\n            mint irot = 1, iimag = info.iroot[2];\n            for(int\
    \ s = 0; s < (1 << (len - 2)); ++s) {\n                mint irot2 = irot * irot;\n\
    \                mint irot3 = irot2 * irot;\n                int offset = s <<\
    \ (h - len + 2);\n                for(int i = 0; i < p; ++i) {\n             \
    \       auto a0 = 1ULL * a[i + offset + 0 * p].val();\n                    auto\
    \ a1 = 1ULL * a[i + offset + 1 * p].val();\n                    auto a2 = 1ULL\
    \ * a[i + offset + 2 * p].val();\n                    auto a3 = 1ULL * a[i + offset\
    \ + 3 * p].val();\n                    auto a2na3iimag = 1ULL * mint((mint::mod()\
    \ + a2 - a3) * iimag.val()).val();\n                    a[i + offset] = a0 + a1\
    \ + a2 + a3;\n                    a[i + offset + 1 * p] = (a0 + (mint::mod() -\
    \ a1) + a2na3iimag) * irot.val();\n                    a[i + offset + 2 * p] =\
    \ (a0 + a1 + (mint::mod() - a2) + (mint::mod() - a3)) * irot2.val();\n       \
    \             a[i + offset + 3 * p] = (a0 + (mint::mod() - a1) + (mint::mod()\
    \ - a2na3iimag)) * irot3.val();\n                }\n                if(s + 1 !=\
    \ (1 << (len - 2))) irot *= info.irate3[__builtin_ctz(~(unsigned int)(s))];\n\
    \            }\n            len -= 2;\n        }\n    }\n}\ntemplate <typename\
    \ mint>\nvector<mint> convolution_naive(const vector<mint>& a, const vector<mint>&\
    \ b) {\n    int n = (int)a.size(), m = (int)b.size();\n    vector<mint> res(n\
    \ + m - 1);\n    if(n < m) {\n        for(int j = 0; j < m; ++j) {\n         \
    \   for(int i = 0; i < n; ++i) {\n                res[i + j] += a[i] * b[j];\n\
    \            }\n        }\n    } else {\n        for(int i = 0; i < n; ++i) {\n\
    \            for(int j = 0; j < m; ++j) {\n                res[i + j] += a[i]\
    \ * b[j];\n            }\n        }\n    }\n    return res;\n}\ntemplate <typename\
    \ mint>\nvector<mint> convolution(vector<mint> a, vector<mint> b) {\n    int n\
    \ = (int)a.size(), m = (int)b.size();\n    if(n == 0 or m == 0) return {};\n \
    \   int z = 1;\n    while(z < n + m - 1) z *= 2;\n    assert((mint::mod() - 1)\
    \ % z == 0);\n    if(min(n, m) <= 60) return convolution_naive(a, b);\n    a.resize(z);\n\
    \    b.resize(z);\n    butterfly(a);\n    butterfly(b);\n    for(int i = 0; i\
    \ < z; ++i) a[i] *= b[i];\n    butterfly_inv(a);\n    a.resize(n + m - 1);\n \
    \   mint iz = mint(z).inv();\n    for(int i = 0; i < n + m - 1; ++i) a[i] *= iz;\n\
    \    return a;\n}\n#line 5 \"src/convolution/convolution_ll.hpp\"\nvector<ll>\
    \ convolution_ll(const vector<ll>& a, const vector<ll>& b) {\n    int n = (int)a.size(),\
    \ m = (int)b.size();\n    if(!n or !m) return {};\n    static constexpr unsigned\
    \ long long MOD1 = 754974721;\n    static constexpr unsigned long long MOD2 =\
    \ 167772161;\n    static constexpr unsigned long long MOD3 = 469762049;\n    static\
    \ constexpr unsigned long long M2M3 = MOD2 * MOD3;\n    static constexpr unsigned\
    \ long long M1M3 = MOD1 * MOD3;\n    static constexpr unsigned long long M1M2\
    \ = MOD1 * MOD2;\n    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2\
    \ * MOD3;\n    static constexpr unsigned long long i1 = 190329765;\n    static\
    \ constexpr unsigned long long i2 = 58587104;\n    static constexpr unsigned long\
    \ long i3 = 187290749;\n    static constexpr int MAX_AB_BIT = 24;\n    assert(n\
    \ + m - 1 <= (1 << MAX_AB_BIT));\n    using mint1 = StaticModint<MOD1>;\n    using\
    \ mint2 = StaticModint<MOD2>;\n    using mint3 = StaticModint<MOD3>;\n    vector<mint1>\
    \ a1(n), b1(m);\n    vector<mint2> a2(n), b2(m);\n    vector<mint3> a3(n), b3(m);\n\
    \    for(int i = 0; i < n; ++i) a1[i] = a[i];\n    for(int i = 0; i < n; ++i)\
    \ a2[i] = a[i];\n    for(int i = 0; i < n; ++i) a3[i] = a[i];\n    for(int i =\
    \ 0; i < m; ++i) b1[i] = b[i];\n    for(int i = 0; i < m; ++i) b2[i] = b[i];\n\
    \    for(int i = 0; i < m; ++i) b3[i] = b[i];\n    vector<mint1> c1 = convolution<mint1>(a1,\
    \ b1);\n    vector<mint2> c2 = convolution<mint2>(a2, b2);\n    vector<mint3>\
    \ c3 = convolution<mint3>(a3, b3);\n    vector<ll> c(n + m - 1);\n    for(int\
    \ i = 0; i < n + m - 1; ++i) {\n        unsigned long long x = 0;\n        x +=\
    \ (c1[i].val() * i1) % MOD1 * M2M3;\n        x += (c2[i].val() * i2) % MOD2 *\
    \ M1M3;\n        x += (c3[i].val() * i3) % MOD3 * M1M2;\n        ll diff = c1[i].val()\
    \ - ((ll)x % (ll)MOD1 + (ll)MOD1) % (ll)MOD1;\n        if(diff < 0) diff += MOD1;\n\
    \        static constexpr unsigned long long offset[5] = {0, 0, M1M2M3, 2 * M1M2M3,\
    \ 3 * M1M2M3};\n        x -= offset[diff % 5];\n        c[i] = x;\n    }\n   \
    \ return c;\n}\n#line 5 \"verify/unit_test/convolution/convolution_ll.test.cpp\"\
    \nvoid test() {\n    int n = rng(0, 1000), m = rng(0, 1000);\n    vector<ll> a(n),\
    \ b(m);\n    rep(i, 0, n) a[i] = rng(-1000000, 1000000);\n    rep(i, 0, m) b[i]\
    \ = rng(-1000000, 1000000);\n    vector<ll> c = convolution_ll(a, b);\n    if(!n\
    \ or !m) {\n        assert(c.empty());\n        return;\n    }\n    vector<ll>\
    \ expected(n + m - 1);\n    rep(i, 0, n + m - 1) {\n        rep(j, 0, i + 1) {\n\
    \            if(0 <= j and j < n and 0 <= i - j and i - j < m) expected[i] +=\
    \ a[j] * b[i - j];\n        }\n    }\n    rep(i, 0, n + m - 1) {\n        assert(c[i]\
    \ == expected[i]);\n    }\n}\nint main(void) {\n    constexpr int test_num = 100;\n\
    \    rep(_, 0, test_num) {\n        test();\n    }\n    int a, b;\n    cin >>\
    \ a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/template/random_number_generator.hpp\"\n#include \"\
    ../../../src/convolution/convolution_ll.hpp\"\nvoid test() {\n    int n = rng(0,\
    \ 1000), m = rng(0, 1000);\n    vector<ll> a(n), b(m);\n    rep(i, 0, n) a[i]\
    \ = rng(-1000000, 1000000);\n    rep(i, 0, m) b[i] = rng(-1000000, 1000000);\n\
    \    vector<ll> c = convolution_ll(a, b);\n    if(!n or !m) {\n        assert(c.empty());\n\
    \        return;\n    }\n    vector<ll> expected(n + m - 1);\n    rep(i, 0, n\
    \ + m - 1) {\n        rep(j, 0, i + 1) {\n            if(0 <= j and j < n and\
    \ 0 <= i - j and i - j < m) expected[i] += a[j] * b[i - j];\n        }\n    }\n\
    \    rep(i, 0, n + m - 1) {\n        assert(c[i] == expected[i]);\n    }\n}\n\
    int main(void) {\n    constexpr int test_num = 100;\n    rep(_, 0, test_num) {\n\
    \        test();\n    }\n    int a, b;\n    cin >> a >> b;\n    cout << a + b\
    \ << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/random_number_generator.hpp
  - src/convolution/convolution_ll.hpp
  - src/template/static_modint.hpp
  - src/convolution/convolution.hpp
  - src/math/primitive_root.hpp
  - src/math/pow_mod.hpp
  isVerificationFile: true
  path: verify/unit_test/convolution/convolution_ll.test.cpp
  requiredBy: []
  timestamp: '2024-01-06 00:23:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/convolution/convolution_ll.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/convolution/convolution_ll.test.cpp
- /verify/verify/unit_test/convolution/convolution_ll.test.cpp.html
title: verify/unit_test/convolution/convolution_ll.test.cpp
---
