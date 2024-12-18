---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/convolution.hpp
    title: convolution
  - icon: ':heavy_check_mark:'
    path: src/math/pow_mod.hpp
    title: pow_mod
  - icon: ':heavy_check_mark:'
    path: src/math/primitive_root.hpp
    title: primitive_root
  - icon: ':heavy_check_mark:'
    path: src/template/static_modint.hpp
    title: StaticModint
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/fps/formal_power_series_ll.hpp
    title: FormalPowerSeriesLL
  - icon: ':heavy_check_mark:'
    path: src/string/wildcard_pattern_matching.hpp
    title: wildcard_pattern_matching
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/wildcard_pattern_matching.test.cpp
    title: verify/library_checker/string/wildcard_pattern_matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/frequency_table_of_tree_distance.test.cpp
    title: verify/library_checker/tree/frequency_table_of_tree_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/convolution/convolution_ll.test.cpp
    title: verify/unit_test/convolution/convolution_ll.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/template/static_modint.hpp\"\
    \ntemplate <uint32_t m>\nstruct StaticModint {\n    using mint = StaticModint;\n\
    \    static constexpr uint32_t mod() {\n        return m;\n    }\n    static constexpr\
    \ mint raw(const uint32_t v) {\n        mint a;\n        a._v = v;\n        return\
    \ a;\n    }\n    constexpr StaticModint()\n        : _v(0) {}\n    template <class\
    \ T>\n    constexpr StaticModint(const T& v) {\n        static_assert(is_integral_v<T>);\n\
    \        if constexpr(is_signed_v<T>) {\n            int64_t x = int64_t(v % int64_t(m));\n\
    \            if(x < 0) x += m;\n            _v = uint32_t(x);\n        } else\
    \ _v = uint32_t(v % m);\n    }\n    constexpr uint32_t val() const {\n       \
    \ return _v;\n    }\n    constexpr mint& operator++() {\n        return *this\
    \ += 1;\n    }\n    constexpr mint& operator--() {\n        return *this -= 1;\n\
    \    }\n    constexpr mint operator++(int) {\n        mint res = *this;\n    \
    \    ++*this;\n        return res;\n    }\n    constexpr mint operator--(int)\
    \ {\n        mint res = *this;\n        --*this;\n        return res;\n    }\n\
    \    constexpr mint& operator+=(mint rhs) {\n        if(_v >= m - rhs._v) _v -=\
    \ m;\n        _v += rhs._v;\n        return *this;\n    }\n    constexpr mint&\
    \ operator-=(mint rhs) {\n        if(_v < rhs._v) _v += m;\n        _v -= rhs._v;\n\
    \        return *this;\n    }\n    constexpr mint& operator*=(mint rhs) {\n  \
    \      return *this = *this * rhs;\n    }\n    constexpr mint& operator/=(mint\
    \ rhs) {\n        return *this *= rhs.inv();\n    }\n    constexpr mint operator+()\
    \ const {\n        return *this;\n    }\n    constexpr mint operator-() const\
    \ {\n        return mint{} - *this;\n    }\n    constexpr mint pow(long long n)\
    \ const {\n        assert(0 <= n);\n        if(n == 0) return 1;\n        mint\
    \ x = *this, r = 1;\n        while(1) {\n            if(n & 1) r *= x;\n     \
    \       n >>= 1;\n            if(n == 0) return r;\n            x *= x;\n    \
    \    }\n    }\n    constexpr mint inv() const {\n        if constexpr(prime) {\n\
    \            assert(_v);\n            return pow(m - 2);\n        } else {\n \
    \           const auto eg = inv_gcd(_v, m);\n            assert(eg.first == 1);\n\
    \            return eg.second;\n        }\n    }\n    friend constexpr mint operator+(mint\
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
    \ int32_t> inv_gcd(const int32_t a, const int32_t b) {\n        if(a == 0) return\
    \ {b, 0};\n        int32_t s = b, t = a, m0 = 0, m1 = 1;\n        while(t) {\n\
    \            const int32_t u = s / t;\n            s -= t * u;\n            m0\
    \ -= m1 * u;\n            swap(s, t);\n            swap(m0, m1);\n        }\n\
    \        if(m0 < 0) m0 += b / s;\n        return {s, m0};\n    }\n};\nusing modint998244353\
    \ = StaticModint<998244353>;\nusing modint1000000007 = StaticModint<1000000007>;\n\
    #line 3 \"src/math/pow_mod.hpp\"\nconstexpr long long pow_mod(long long x, long\
    \ long n, const long long mod) {\n    assert(n >= 0 and mod >= 1);\n    x %= mod;\n\
    \    if(x < 0) x += mod;\n    long long res = 1;\n    while(n > 0) {\n       \
    \ if(n & 1) res = res * x % mod;\n        x = x * x % mod;\n        n >>= 1;\n\
    \    }\n    return res;\n}\n#line 4 \"src/math/primitive_root.hpp\"\nconstexpr\
    \ int primitive_root(const int m) {\n    if(m == 2) return 1;\n    if(m == 167772161)\
    \ return 3;\n    if(m == 469762049) return 3;\n    if(m == 754974721) return 11;\n\
    \    if(m == 998244353) return 3;\n    int divs[20] = {};\n    divs[0] = 2;\n\
    \    int cnt = 1;\n    int x = (m - 1) / 2;\n    while(x % 2 == 0) x /= 2;\n \
    \   for(int i = 3; (long long)(i)*i <= x; i += 2) {\n        if(x % i == 0) {\n\
    \            divs[cnt++] = i;\n            while(x % i == 0) {\n             \
    \   x /= i;\n            }\n        }\n    }\n    if(x > 1) {\n        divs[cnt++]\
    \ = x;\n    }\n    for(int g = 2;; ++g) {\n        bool ok = true;\n        for(int\
    \ i = 0; i < cnt; ++i) {\n            if(pow_mod(g, (m - 1) / divs[i], m) == 1)\
    \ {\n                ok = false;\n                break;\n            }\n    \
    \    }\n        if(ok) return g;\n    }\n}\n#line 4 \"src/convolution/convolution.hpp\"\
    \nconstexpr int countr_zero(const unsigned int n) {\n    int res = 0;\n    while(!(n\
    \ & (1 << res))) ++res;\n    return res;\n}\ntemplate <typename mint, int g =\
    \ primitive_root(mint::mod())>\nstruct FFT_Info {\n    static constexpr int rank2\
    \ = countr_zero(mint::mod() - 1);\n    array<mint, rank2 + 1> root;\n    array<mint,\
    \ rank2 + 1> iroot;\n    array<mint, max(0, rank2 - 2 + 1)> rate2;\n    array<mint,\
    \ max(0, rank2 - 2 + 1)> irate2;\n    array<mint, max(0, rank2 - 3 + 1)> rate3;\n\
    \    array<mint, max(0, rank2 - 3 + 1)> irate3;\n    FFT_Info() {\n        root[rank2]\
    \ = mint(g).pow((mint::mod() - 1) >> rank2);\n        iroot[rank2] = root[rank2].inv();\n\
    \        for(int i = rank2 - 1; i >= 0; --i) {\n            root[i] = root[i +\
    \ 1] * root[i + 1];\n            iroot[i] = iroot[i + 1] * iroot[i + 1];\n   \
    \     }\n        {\n            mint prod = 1, iprod = 1;\n            for(int\
    \ i = 0; i <= rank2 - 2; ++i) {\n                rate2[i] = root[i + 2] * prod;\n\
    \                irate2[i] = iroot[i + 2] * iprod;\n                prod *= iroot[i\
    \ + 2];\n                iprod *= root[i + 2];\n            }\n        }\n   \
    \     {\n            mint prod = 1, iprod = 1;\n            for(int i = 0; i <=\
    \ rank2 - 3; ++i) {\n                rate3[i] = root[i + 3] * prod;\n        \
    \        irate3[i] = iroot[i + 3] * iprod;\n                prod *= iroot[i +\
    \ 3];\n                iprod *= root[i + 3];\n            }\n        }\n    }\n\
    };\ntemplate <typename mint>\nvoid butterfly(vector<mint>& a) {\n    const int\
    \ n = (int)a.size();\n    const int h = __builtin_ctz((unsigned int)n);\n    static\
    \ const FFT_Info<mint> info;\n    int len = 0;\n    while(len < h) {\n       \
    \ if(h - len == 1) {\n            const int p = 1 << (h - len - 1);\n        \
    \    mint rot = 1;\n            for(int s = 0; s < (1 << len); ++s) {\n      \
    \          const int offset = s << (h - len);\n                for(int i = 0;\
    \ i < p; ++i) {\n                    const auto l = a[i + offset];\n         \
    \           const auto r = a[i + offset + p] * rot;\n                    a[i +\
    \ offset] = l + r;\n                    a[i + offset + p] = l - r;\n         \
    \       }\n                if(s + 1 != (1 << len)) rot *= info.rate2[__builtin_ctz(~(unsigned\
    \ int)(s))];\n            }\n            ++len;\n        } else {\n          \
    \  const int p = 1 << (h - len - 2);\n            mint rot = 1, imag = info.root[2];\n\
    \            for(int s = 0; s < (1 << len); ++s) {\n                const mint\
    \ rot2 = rot * rot;\n                const mint rot3 = rot2 * rot;\n         \
    \       const int offset = s << (h - len);\n                for(int i = 0; i <\
    \ p; ++i) {\n                    const auto mod2 = 1ULL * mint::mod() * mint::mod();\n\
    \                    const auto a0 = 1ULL * a[i + offset].val();\n           \
    \         const auto a1 = 1ULL * a[i + offset + p].val() * rot.val();\n      \
    \              const auto a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();\n\
    \                    const auto a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();\n\
    \                    const auto a1na3imag = 1ULL * mint(a1 + mod2 - a3).val()\
    \ * imag.val();\n                    const auto na2 = mod2 - a2;\n           \
    \         a[i + offset] = a0 + a2 + a1 + a3;\n                    a[i + offset\
    \ + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n                    a[i + offset\
    \ + 2 * p] = a0 + na2 + a1na3imag;\n                    a[i + offset + 3 * p]\
    \ = a0 + na2 + (mod2 - a1na3imag);\n                }\n                if(s +\
    \ 1 != (1 << len)) rot *= info.rate3[__builtin_ctz(~(unsigned int)(s))];\n   \
    \         }\n            len += 2;\n        }\n    }\n}\ntemplate <typename mint>\n\
    void butterfly_inv(vector<mint>& a) {\n    const int n = (int)a.size();\n    const\
    \ int h = __builtin_ctz((unsigned int)n);\n    static const FFT_Info<mint> info;\n\
    \    int len = h;\n    while(len) {\n        if(len == 1) {\n            const\
    \ int p = 1 << (h - len);\n            mint irot = 1;\n            for(int s =\
    \ 0; s < (1 << (len - 1)); ++s) {\n                const int offset = s << (h\
    \ - len + 1);\n                for(int i = 0; i < p; ++i) {\n                \
    \    const auto l = a[i + offset];\n                    const auto r = a[i + offset\
    \ + p];\n                    a[i + offset] = l + r;\n                    a[i +\
    \ offset + p] = (unsigned long long)(mint::mod() + l.val() - r.val()) * irot.val();\n\
    \                }\n                if(s + 1 != (1 << (len - 1))) irot *= info.irate2[__builtin_ctz(~(unsigned\
    \ int)(s))];\n            }\n            --len;\n        } else {\n          \
    \  const int p = 1 << (h - len);\n            mint irot = 1, iimag = info.iroot[2];\n\
    \            for(int s = 0; s < (1 << (len - 2)); ++s) {\n                const\
    \ mint irot2 = irot * irot;\n                const mint irot3 = irot2 * irot;\n\
    \                const int offset = s << (h - len + 2);\n                for(int\
    \ i = 0; i < p; ++i) {\n                    const auto a0 = 1ULL * a[i + offset\
    \ + 0 * p].val();\n                    const auto a1 = 1ULL * a[i + offset + 1\
    \ * p].val();\n                    const auto a2 = 1ULL * a[i + offset + 2 * p].val();\n\
    \                    const auto a3 = 1ULL * a[i + offset + 3 * p].val();\n   \
    \                 const auto a2na3iimag = 1ULL * mint((mint::mod() + a2 - a3)\
    \ * iimag.val()).val();\n                    a[i + offset] = a0 + a1 + a2 + a3;\n\
    \                    a[i + offset + 1 * p] = (a0 + (mint::mod() - a1) + a2na3iimag)\
    \ * irot.val();\n                    a[i + offset + 2 * p] = (a0 + a1 + (mint::mod()\
    \ - a2) + (mint::mod() - a3)) * irot2.val();\n                    a[i + offset\
    \ + 3 * p] = (a0 + (mint::mod() - a1) + (mint::mod() - a2na3iimag)) * irot3.val();\n\
    \                }\n                if(s + 1 != (1 << (len - 2))) irot *= info.irate3[__builtin_ctz(~(unsigned\
    \ int)(s))];\n            }\n            len -= 2;\n        }\n    }\n}\ntemplate\
    \ <typename mint>\nvector<mint> convolution_naive(const vector<mint>& a, const\
    \ vector<mint>& b) {\n    const int n = (int)a.size(), m = (int)b.size();\n  \
    \  vector<mint> res(n + m - 1);\n    if(n < m) {\n        for(int j = 0; j < m;\
    \ ++j) {\n            for(int i = 0; i < n; ++i) {\n                res[i + j]\
    \ += a[i] * b[j];\n            }\n        }\n    } else {\n        for(int i =\
    \ 0; i < n; ++i) {\n            for(int j = 0; j < m; ++j) {\n               \
    \ res[i + j] += a[i] * b[j];\n            }\n        }\n    }\n    return res;\n\
    }\ntemplate <typename mint>\nvector<mint> convolution(vector<mint> a, vector<mint>\
    \ b) {\n    const int n = (int)a.size(), m = (int)b.size();\n    if(n == 0 or\
    \ m == 0) return {};\n    int z = 1;\n    while(z < n + m - 1) z *= 2;\n    assert((mint::mod()\
    \ - 1) % z == 0);\n    if(min(n, m) <= 60) return convolution_naive(a, b);\n \
    \   a.resize(z);\n    b.resize(z);\n    butterfly(a);\n    butterfly(b);\n   \
    \ for(int i = 0; i < z; ++i) a[i] *= b[i];\n    butterfly_inv(a);\n    a.resize(n\
    \ + m - 1);\n    const mint iz = mint(z).inv();\n    for(int i = 0; i < n + m\
    \ - 1; ++i) a[i] *= iz;\n    return a;\n}\n#line 5 \"src/convolution/convolution_ll.hpp\"\
    \nvector<long long> convolution_ll(const vector<long long>& a, const vector<long\
    \ long>& b) {\n    const int n = (int)a.size(), m = (int)b.size();\n    if(!n\
    \ or !m) return {};\n    static constexpr unsigned long long MOD1 = 754974721;\n\
    \    static constexpr unsigned long long MOD2 = 167772161;\n    static constexpr\
    \ unsigned long long MOD3 = 469762049;\n    static constexpr unsigned long long\
    \ M2M3 = MOD2 * MOD3;\n    static constexpr unsigned long long M1M3 = MOD1 * MOD3;\n\
    \    static constexpr unsigned long long M1M2 = MOD1 * MOD2;\n    static constexpr\
    \ unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;\n    static constexpr unsigned\
    \ long long i1 = 190329765;\n    static constexpr unsigned long long i2 = 58587104;\n\
    \    static constexpr unsigned long long i3 = 187290749;\n    static constexpr\
    \ int MAX_AB_BIT = 24;\n    assert(n + m - 1 <= (1 << MAX_AB_BIT));\n    using\
    \ mint1 = StaticModint<MOD1>;\n    using mint2 = StaticModint<MOD2>;\n    using\
    \ mint3 = StaticModint<MOD3>;\n    vector<mint1> a1(n), b1(m);\n    vector<mint2>\
    \ a2(n), b2(m);\n    vector<mint3> a3(n), b3(m);\n    for(int i = 0; i < n; ++i)\
    \ a1[i] = a[i];\n    for(int i = 0; i < n; ++i) a2[i] = a[i];\n    for(int i =\
    \ 0; i < n; ++i) a3[i] = a[i];\n    for(int i = 0; i < m; ++i) b1[i] = b[i];\n\
    \    for(int i = 0; i < m; ++i) b2[i] = b[i];\n    for(int i = 0; i < m; ++i)\
    \ b3[i] = b[i];\n    vector<mint1> c1 = convolution<mint1>(a1, b1);\n    vector<mint2>\
    \ c2 = convolution<mint2>(a2, b2);\n    vector<mint3> c3 = convolution<mint3>(a3,\
    \ b3);\n    vector<long long> c(n + m - 1);\n    for(int i = 0; i < n + m - 1;\
    \ ++i) {\n        unsigned long long x = 0;\n        x += (c1[i].val() * i1) %\
    \ MOD1 * M2M3;\n        x += (c2[i].val() * i2) % MOD2 * M1M3;\n        x += (c3[i].val()\
    \ * i3) % MOD3 * M1M2;\n        long long diff = c1[i].val() - ((long long)x %\
    \ (long long)MOD1 + (long long)MOD1) % (long long)MOD1;\n        if(diff < 0)\
    \ diff += MOD1;\n        static constexpr unsigned long long offset[5] = {0, 0,\
    \ M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\n        x -= offset[diff % 5];\n        c[i]\
    \ = x;\n    }\n    return c;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../template/static_modint.hpp\"\
    \n#include \"./convolution.hpp\"\nvector<long long> convolution_ll(const vector<long\
    \ long>& a, const vector<long long>& b) {\n    const int n = (int)a.size(), m\
    \ = (int)b.size();\n    if(!n or !m) return {};\n    static constexpr unsigned\
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
    \ c3 = convolution<mint3>(a3, b3);\n    vector<long long> c(n + m - 1);\n    for(int\
    \ i = 0; i < n + m - 1; ++i) {\n        unsigned long long x = 0;\n        x +=\
    \ (c1[i].val() * i1) % MOD1 * M2M3;\n        x += (c2[i].val() * i2) % MOD2 *\
    \ M1M3;\n        x += (c3[i].val() * i3) % MOD3 * M1M2;\n        long long diff\
    \ = c1[i].val() - ((long long)x % (long long)MOD1 + (long long)MOD1) % (long long)MOD1;\n\
    \        if(diff < 0) diff += MOD1;\n        static constexpr unsigned long long\
    \ offset[5] = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\n        x -= offset[diff\
    \ % 5];\n        c[i] = x;\n    }\n    return c;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/static_modint.hpp
  - src/convolution/convolution.hpp
  - src/math/primitive_root.hpp
  - src/math/pow_mod.hpp
  isVerificationFile: false
  path: src/convolution/convolution_ll.hpp
  requiredBy:
  - src/string/wildcard_pattern_matching.hpp
  - src/fps/formal_power_series_ll.hpp
  timestamp: '2024-11-09 02:16:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/convolution/convolution_ll.test.cpp
  - verify/library_checker/string/wildcard_pattern_matching.test.cpp
  - verify/library_checker/tree/frequency_table_of_tree_distance.test.cpp
documentation_of: src/convolution/convolution_ll.hpp
layout: document
title: convolution_ll
---

## convolution_ll

```cpp
vector<ll> convolution_ll(vector<ll> a, vector<ll> b)
```

長さ $N$ の配列 $a$ と長さ $M$ の配列 $b$ の畳み込みを `long long` で計算します．<br>
$N$ または $M$ の少なくとも一方が $0$ である場合は空配列を返します．

**制約**

- $N + M - 1 \leq 2^{24}$
- 計算結果が `long long` 型に収まる．

**計算量**

$n = N + M$ として，

- $O(n \log n)$