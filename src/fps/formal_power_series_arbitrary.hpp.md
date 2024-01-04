---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/convolution.hpp
    title: convolution
  - icon: ':heavy_check_mark:'
    path: src/convolution/convolution_arbitrary.hpp
    title: convolution_arbitrary
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/template/static_modint.hpp\"\
    \ntemplate <uint32_t m>\nstruct StaticModint {\n    using mint = StaticModint;\n\
    \    static constexpr uint32_t mod() {\n        return m;\n    }\n    static constexpr\
    \ mint raw(uint32_t v) {\n        mint a;\n        a._v = v;\n        return a;\n\
    \    }\n    constexpr StaticModint()\n        : _v(0) {}\n    template <class\
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
    \           auto eg = inv_gcd(_v, m);\n            assert(eg.first == 1);\n  \
    \          return eg.second;\n        }\n    }\n    friend constexpr mint operator+(mint\
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
    \    return a;\n}\n#line 5 \"src/convolution/convolution_arbitrary.hpp\"\ntemplate\
    \ <typename mint>\nvector<mint> convolution_arbitary(const vector<mint>& a, const\
    \ vector<mint>& b) {\n    int n = (int)a.size(), m = (int)b.size();\n    static\
    \ constexpr ll MOD1 = 754974721;\n    static constexpr ll MOD2 = 167772161;\n\
    \    static constexpr ll MOD3 = 469762049;\n    static constexpr ll M1_inv_M2\
    \ = 95869806;\n    static constexpr ll M12_inv_M3 = 187290749;\n    static constexpr\
    \ ll M12_mod = MOD1 * MOD2 % mint::mod();\n    using mint1 = StaticModint<(uint32_t)MOD1>;\n\
    \    using mint2 = StaticModint<(uint32_t)MOD2>;\n    using mint3 = StaticModint<(uint32_t)MOD3>;\n\
    \    vector<mint1> a1(n), b1(m);\n    vector<mint2> a2(n), b2(m);\n    vector<mint3>\
    \ a3(n), b3(m);\n    for(int i = 0; i < n; ++i) a1[i] = a[i].val();\n    for(int\
    \ i = 0; i < n; ++i) a2[i] = a[i].val();\n    for(int i = 0; i < n; ++i) a3[i]\
    \ = a[i].val();\n    for(int i = 0; i < m; ++i) b1[i] = b[i].val();\n    for(int\
    \ i = 0; i < m; ++i) b2[i] = b[i].val();\n    for(int i = 0; i < m; ++i) b3[i]\
    \ = b[i].val();\n    vector<mint1> x = convolution<mint1>(a1, b1);\n    vector<mint2>\
    \ y = convolution<mint2>(a2, b2);\n    vector<mint3> z = convolution<mint3>(a3,\
    \ b3);\n    vector<mint> c(n + m - 1);\n    for(int i = 0; i < n + m - 1; ++i)\
    \ {\n        ll v1 = ((ll)y[i].val() - (ll)x[i].val()) * M1_inv_M2 % MOD2;\n \
    \       if(v1 < 0) v1 += MOD2;\n        ll v2 = ((ll)z[i].val() - ((ll)x[i].val()\
    \ + MOD1 * v1) % MOD3) * M12_inv_M3 % MOD3;\n        if(v2 < 0) v2 += MOD3;\n\
    \        c[i] = (ll)x[i].val() + MOD1 * v1 + M12_mod * v2;\n    }\n    return\
    \ c;\n}\n#line 4 \"src/fps/formal_power_series_arbitrary.hpp\"\ntemplate <typename\
    \ mint>\nstruct FormalPowerSeries : vector<mint> {\n    using vector<mint>::vector;\n\
    \    using F = FormalPowerSeries;\n    F& operator=(const vector<mint>& g) {\n\
    \        const int n = (*this).size();\n        const int m = g.size();\n    \
    \    if(n < m) (*this).resize(m);\n        for(int i = 0; i < m; ++i) (*this)[i]\
    \ = g[i];\n        return (*this);\n    }\n    F& operator-() {\n        const\
    \ int n = (*this).size();\n        for(int i = 0; i < n; ++i) (*this)[i] *= -1;\n\
    \        return (*this);\n    }\n    F& operator+=(const F& g) {\n        const\
    \ int n = (*this).size();\n        const int m = g.size();\n        if(n < m)\
    \ (*this).resize(m);\n        for(int i = 0; i < m; ++i) (*this)[i] += g[i];\n\
    \        return (*this);\n    }\n    F& operator+=(const mint& r) {\n        if((*this).empty())\
    \ (*this).resize(1);\n        (*this)[0] += r;\n        return (*this);\n    }\n\
    \    F& operator-=(const F& g) {\n        const int n = (*this).size();\n    \
    \    const int m = g.size();\n        if(n < m) (*this).resize(m);\n        for(int\
    \ i = 0; i < m; ++i) (*this)[i] -= g[i];\n        return (*this);\n    }\n   \
    \ F& operator-=(const mint& r) {\n        if((*this).empty()) (*this).resize(1);\n\
    \        (*this)[0] -= r;\n        return (*this);\n    }\n    F& operator*=(const\
    \ F& g) {\n        (*this) = convolution_arbitary((*this), g);\n        return\
    \ (*this);\n    }\n    F& operator*=(const mint& r) {\n        const int n = (*this).size();\n\
    \        for(int i = 0; i < n; ++i) (*this)[i] *= r;\n        return (*this);\n\
    \    }\n    F& operator/=(const F& g) {\n        if((*this).size() < g.size())\
    \ {\n            (*this).clear();\n            return (*this);\n        }\n  \
    \      const int n = (*this).size() - g.size() + 1;\n        (*this) = ((*this).rev().pre(n)\
    \ * g.rev().inv(n)).pre(n).rev();\n        return (*this);\n    }\n    F& operator/=(const\
    \ mint& r) {\n        const int n = (*this).size();\n        mint inv_r = r.inv();\n\
    \        for(int i = 0; i < (int)n; ++i) (*this)[i] *= inv_r;\n        return\
    \ (*this);\n    }\n    F& operator%=(const F& g) {\n        (*this) -= (*this)\
    \ / g * g;\n        shrink();\n        return (*this);\n    }\n    F operator*(const\
    \ mint& g) const {\n        return F(*this) *= g;\n    }\n    F operator-(const\
    \ mint& g) const {\n        return F(*this) -= g;\n    }\n    F operator+(const\
    \ mint& g) const {\n        return F(*this) += g;\n    }\n    F operator/(const\
    \ mint& g) const {\n        return F(*this) /= g;\n    }\n    F operator*(const\
    \ F& g) const {\n        return F(*this) *= g;\n    }\n    F operator-(const F&\
    \ g) const {\n        return F(*this) -= g;\n    }\n    F operator+(const F& g)\
    \ const {\n        return F(*this) += g;\n    }\n    F operator/(const F& g) const\
    \ {\n        return F(*this) /= g;\n    }\n    F operator%(const F& g) const {\n\
    \        return F(*this) %= g;\n    }\n    F operator<<(const int d) const {\n\
    \        F ret(*this);\n        ret.insert(ret.begin(), d, mint(0));\n       \
    \ return ret;\n    }\n    F operator>>(const int d) const {\n        const int\
    \ n = (*this).size();\n        if(n <= d) return {};\n        F ret(*this);\n\
    \        ret.erase(ret.begin(), ret.begin() + d);\n        return ret;\n    }\n\
    \    void shrink() {\n        while((*this).size() and (*this).back() == mint(0))\
    \ (*this).pop_back();\n    }\n    F rev() const {\n        F ret(*this);\n   \
    \     reverse(begin(ret), end(ret));\n        return ret;\n    }\n    F pre(const\
    \ int deg) const {\n        F ret(begin(*this), begin(*this) + min((int)(*this).size(),\
    \ deg));\n        if((int)ret.size() < deg) ret.resize(deg);\n        return ret;\n\
    \    }\n    mint eval(const mint& a) const {\n        const int n = (*this).size();\n\
    \        mint x = 1, ret = 0;\n        for(int i = 0; i < n; ++i) {\n        \
    \    ret += (*this)[i] * x;\n            x *= a;\n        }\n        return ret;\n\
    \    }\n    void onemul(const int d, const mint& c, const int deg = -1) {\n  \
    \      const int n = (*this).size();\n        if(deg == -1) deg = n + d;\n   \
    \     if(deg > n) (*this).resize(deg);\n        for(int i = deg - d - 1; i >=\
    \ 0; --i) {\n            (*this)[i + d] += (*this)[i] * c;\n        }\n    }\n\
    \    void onediv(const int d, const mint& c, const int deg = -1) {\n        const\
    \ int n = (*this).size();\n        if(deg == -1) deg = n;\n        if(deg > n)\
    \ (*this).resize(deg + 1);\n        for(int i = 0; i < deg - d; ++i) {\n     \
    \       (*this)[i + d] -= (*this)[i] * c;\n        }\n    }\n    F diff() const\
    \ {\n        const int n = (*this).size();\n        F ret(max(0, n - 1));\n  \
    \      for(int i = 1; i < n; ++i) ret[i - 1] = (*this)[i] * i;\n        return\
    \ ret;\n    }\n    F integral() const {\n        const int n = (*this).size(),\
    \ mod = mint::mod();\n        F ret(n + 1);\n        ret[0] = mint(0);\n     \
    \   if(n > 0) ret[1] = mint(1);\n        for(int i = 2; i <= n; ++i) ret[i] =\
    \ (-ret[mod % i]) * (mod / i);\n        for(int i = 0; i < n; ++i) ret[i + 1]\
    \ *= (*this)[i];\n        return ret;\n    }\n    F inv(int deg = -1) const {\n\
    \        const int n = (*this).size();\n        assert(n > 0 and (*this)[0] !=\
    \ mint(0));\n        if(deg == -1) deg = n;\n        F ret({mint(1) / (*this)[0]});\n\
    \        for(int i = 1; i < deg; i <<= 1) {\n            ret = (ret + ret - ret\
    \ * ret * (*this).pre(i << 1)).pre(i << 1);\n        }\n        return ret.pre(deg);\n\
    \    }\n    F log(int deg = -1) const {\n        const int n = (*this).size();\n\
    \        assert(n > 0 and (*this)[0] == mint(1));\n        if(deg == -1) deg =\
    \ n;\n        return ((*this).diff() * (*this).inv(deg)).pre(deg - 1).integral();\n\
    \    }\n    F exp(int deg = -1) const {\n        const int n = (*this).size();\n\
    \        assert(n == 0 or (*this)[0] == mint(0));\n        if(deg == -1) deg =\
    \ n;\n        F ret({mint(1)});\n        for(int i = 1; i < deg; i <<= 1) {\n\
    \            ret = (ret * (pre(i << 1) + mint(1) - ret.log(i << 1))).pre(i <<\
    \ 1);\n        }\n        return ret.pre(deg);\n    }\n    F pow(const ll k, int\
    \ deg = -1) const {\n        const int n = (*this).size();\n        if(deg ==\
    \ -1) deg = n;\n        if(k == 0) {\n            F ret(deg);\n            if(deg)\
    \ ret[0] = 1;\n            return ret;\n        }\n        for(int i = 0; i <\
    \ n; ++i) {\n            if((*this)[i] != mint(0)) {\n                mint rev\
    \ = mint(1) / (*this)[i];\n                F ret = (((*this * rev) >> i).log(deg)\
    \ * k).exp(deg);\n                ret *= (*this)[i].pow(k);\n                ret\
    \ = (ret << (i * k)).pre(deg);\n                if((int)ret.size() < deg) ret.resize(deg,\
    \ mint(0));\n                return ret;\n            }\n            if(__int128_t(i\
    \ + 1) * k >= deg) return F(deg, mint(0));\n        }\n        return F(deg, mint(0));\n\
    \    }\n    F shift(const mint& c) const {\n        int n = (*this).size();\n\
    \        vector<mint> fact(n), ifact(n);\n        fact[0] = ifact[0] = mint(1);\n\
    \        for(int i = 1; i < n; ++i) fact[i] = fact[i - 1] * i;\n        ifact[n\
    \ - 1] = mint(1) / fact[n - 1];\n        for(int i = n - 1; i > 1; --i) ifact[i\
    \ - 1] = ifact[i] * i;\n        F ret(*this);\n        for(int i = 0; i < n; ++i)\
    \ ret[i] *= fact[i];\n        ret = ret.rev();\n        F bs(n, mint(1));\n  \
    \      for(int i = 1; i < n; ++i) bs[i] = bs[i - 1] * c * ifact[i] * fact[i -\
    \ 1];\n        ret = (ret * bs).pre(n);\n        ret = ret.rev();\n        for(int\
    \ i = 0; i < n; ++i) p[i] *= ifact[i];\n        return ret;\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../convolution/convolution_arbitrary.hpp\"\
    \ntemplate <typename mint>\nstruct FormalPowerSeries : vector<mint> {\n    using\
    \ vector<mint>::vector;\n    using F = FormalPowerSeries;\n    F& operator=(const\
    \ vector<mint>& g) {\n        const int n = (*this).size();\n        const int\
    \ m = g.size();\n        if(n < m) (*this).resize(m);\n        for(int i = 0;\
    \ i < m; ++i) (*this)[i] = g[i];\n        return (*this);\n    }\n    F& operator-()\
    \ {\n        const int n = (*this).size();\n        for(int i = 0; i < n; ++i)\
    \ (*this)[i] *= -1;\n        return (*this);\n    }\n    F& operator+=(const F&\
    \ g) {\n        const int n = (*this).size();\n        const int m = g.size();\n\
    \        if(n < m) (*this).resize(m);\n        for(int i = 0; i < m; ++i) (*this)[i]\
    \ += g[i];\n        return (*this);\n    }\n    F& operator+=(const mint& r) {\n\
    \        if((*this).empty()) (*this).resize(1);\n        (*this)[0] += r;\n  \
    \      return (*this);\n    }\n    F& operator-=(const F& g) {\n        const\
    \ int n = (*this).size();\n        const int m = g.size();\n        if(n < m)\
    \ (*this).resize(m);\n        for(int i = 0; i < m; ++i) (*this)[i] -= g[i];\n\
    \        return (*this);\n    }\n    F& operator-=(const mint& r) {\n        if((*this).empty())\
    \ (*this).resize(1);\n        (*this)[0] -= r;\n        return (*this);\n    }\n\
    \    F& operator*=(const F& g) {\n        (*this) = convolution_arbitary((*this),\
    \ g);\n        return (*this);\n    }\n    F& operator*=(const mint& r) {\n  \
    \      const int n = (*this).size();\n        for(int i = 0; i < n; ++i) (*this)[i]\
    \ *= r;\n        return (*this);\n    }\n    F& operator/=(const F& g) {\n   \
    \     if((*this).size() < g.size()) {\n            (*this).clear();\n        \
    \    return (*this);\n        }\n        const int n = (*this).size() - g.size()\
    \ + 1;\n        (*this) = ((*this).rev().pre(n) * g.rev().inv(n)).pre(n).rev();\n\
    \        return (*this);\n    }\n    F& operator/=(const mint& r) {\n        const\
    \ int n = (*this).size();\n        mint inv_r = r.inv();\n        for(int i =\
    \ 0; i < (int)n; ++i) (*this)[i] *= inv_r;\n        return (*this);\n    }\n \
    \   F& operator%=(const F& g) {\n        (*this) -= (*this) / g * g;\n       \
    \ shrink();\n        return (*this);\n    }\n    F operator*(const mint& g) const\
    \ {\n        return F(*this) *= g;\n    }\n    F operator-(const mint& g) const\
    \ {\n        return F(*this) -= g;\n    }\n    F operator+(const mint& g) const\
    \ {\n        return F(*this) += g;\n    }\n    F operator/(const mint& g) const\
    \ {\n        return F(*this) /= g;\n    }\n    F operator*(const F& g) const {\n\
    \        return F(*this) *= g;\n    }\n    F operator-(const F& g) const {\n \
    \       return F(*this) -= g;\n    }\n    F operator+(const F& g) const {\n  \
    \      return F(*this) += g;\n    }\n    F operator/(const F& g) const {\n   \
    \     return F(*this) /= g;\n    }\n    F operator%(const F& g) const {\n    \
    \    return F(*this) %= g;\n    }\n    F operator<<(const int d) const {\n   \
    \     F ret(*this);\n        ret.insert(ret.begin(), d, mint(0));\n        return\
    \ ret;\n    }\n    F operator>>(const int d) const {\n        const int n = (*this).size();\n\
    \        if(n <= d) return {};\n        F ret(*this);\n        ret.erase(ret.begin(),\
    \ ret.begin() + d);\n        return ret;\n    }\n    void shrink() {\n       \
    \ while((*this).size() and (*this).back() == mint(0)) (*this).pop_back();\n  \
    \  }\n    F rev() const {\n        F ret(*this);\n        reverse(begin(ret),\
    \ end(ret));\n        return ret;\n    }\n    F pre(const int deg) const {\n \
    \       F ret(begin(*this), begin(*this) + min((int)(*this).size(), deg));\n \
    \       if((int)ret.size() < deg) ret.resize(deg);\n        return ret;\n    }\n\
    \    mint eval(const mint& a) const {\n        const int n = (*this).size();\n\
    \        mint x = 1, ret = 0;\n        for(int i = 0; i < n; ++i) {\n        \
    \    ret += (*this)[i] * x;\n            x *= a;\n        }\n        return ret;\n\
    \    }\n    void onemul(const int d, const mint& c, const int deg = -1) {\n  \
    \      const int n = (*this).size();\n        if(deg == -1) deg = n + d;\n   \
    \     if(deg > n) (*this).resize(deg);\n        for(int i = deg - d - 1; i >=\
    \ 0; --i) {\n            (*this)[i + d] += (*this)[i] * c;\n        }\n    }\n\
    \    void onediv(const int d, const mint& c, const int deg = -1) {\n        const\
    \ int n = (*this).size();\n        if(deg == -1) deg = n;\n        if(deg > n)\
    \ (*this).resize(deg + 1);\n        for(int i = 0; i < deg - d; ++i) {\n     \
    \       (*this)[i + d] -= (*this)[i] * c;\n        }\n    }\n    F diff() const\
    \ {\n        const int n = (*this).size();\n        F ret(max(0, n - 1));\n  \
    \      for(int i = 1; i < n; ++i) ret[i - 1] = (*this)[i] * i;\n        return\
    \ ret;\n    }\n    F integral() const {\n        const int n = (*this).size(),\
    \ mod = mint::mod();\n        F ret(n + 1);\n        ret[0] = mint(0);\n     \
    \   if(n > 0) ret[1] = mint(1);\n        for(int i = 2; i <= n; ++i) ret[i] =\
    \ (-ret[mod % i]) * (mod / i);\n        for(int i = 0; i < n; ++i) ret[i + 1]\
    \ *= (*this)[i];\n        return ret;\n    }\n    F inv(int deg = -1) const {\n\
    \        const int n = (*this).size();\n        assert(n > 0 and (*this)[0] !=\
    \ mint(0));\n        if(deg == -1) deg = n;\n        F ret({mint(1) / (*this)[0]});\n\
    \        for(int i = 1; i < deg; i <<= 1) {\n            ret = (ret + ret - ret\
    \ * ret * (*this).pre(i << 1)).pre(i << 1);\n        }\n        return ret.pre(deg);\n\
    \    }\n    F log(int deg = -1) const {\n        const int n = (*this).size();\n\
    \        assert(n > 0 and (*this)[0] == mint(1));\n        if(deg == -1) deg =\
    \ n;\n        return ((*this).diff() * (*this).inv(deg)).pre(deg - 1).integral();\n\
    \    }\n    F exp(int deg = -1) const {\n        const int n = (*this).size();\n\
    \        assert(n == 0 or (*this)[0] == mint(0));\n        if(deg == -1) deg =\
    \ n;\n        F ret({mint(1)});\n        for(int i = 1; i < deg; i <<= 1) {\n\
    \            ret = (ret * (pre(i << 1) + mint(1) - ret.log(i << 1))).pre(i <<\
    \ 1);\n        }\n        return ret.pre(deg);\n    }\n    F pow(const ll k, int\
    \ deg = -1) const {\n        const int n = (*this).size();\n        if(deg ==\
    \ -1) deg = n;\n        if(k == 0) {\n            F ret(deg);\n            if(deg)\
    \ ret[0] = 1;\n            return ret;\n        }\n        for(int i = 0; i <\
    \ n; ++i) {\n            if((*this)[i] != mint(0)) {\n                mint rev\
    \ = mint(1) / (*this)[i];\n                F ret = (((*this * rev) >> i).log(deg)\
    \ * k).exp(deg);\n                ret *= (*this)[i].pow(k);\n                ret\
    \ = (ret << (i * k)).pre(deg);\n                if((int)ret.size() < deg) ret.resize(deg,\
    \ mint(0));\n                return ret;\n            }\n            if(__int128_t(i\
    \ + 1) * k >= deg) return F(deg, mint(0));\n        }\n        return F(deg, mint(0));\n\
    \    }\n    F shift(const mint& c) const {\n        int n = (*this).size();\n\
    \        vector<mint> fact(n), ifact(n);\n        fact[0] = ifact[0] = mint(1);\n\
    \        for(int i = 1; i < n; ++i) fact[i] = fact[i - 1] * i;\n        ifact[n\
    \ - 1] = mint(1) / fact[n - 1];\n        for(int i = n - 1; i > 1; --i) ifact[i\
    \ - 1] = ifact[i] * i;\n        F ret(*this);\n        for(int i = 0; i < n; ++i)\
    \ ret[i] *= fact[i];\n        ret = ret.rev();\n        F bs(n, mint(1));\n  \
    \      for(int i = 1; i < n; ++i) bs[i] = bs[i - 1] * c * ifact[i] * fact[i -\
    \ 1];\n        ret = (ret * bs).pre(n);\n        ret = ret.rev();\n        for(int\
    \ i = 0; i < n; ++i) p[i] *= ifact[i];\n        return ret;\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  - src/convolution/convolution_arbitrary.hpp
  - src/template/static_modint.hpp
  - src/convolution/convolution.hpp
  - src/math/primitive_root.hpp
  - src/math/pow_mod.hpp
  isVerificationFile: false
  path: src/fps/formal_power_series_arbitrary.hpp
  requiredBy: []
  timestamp: '2024-01-04 23:50:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/fps/formal_power_series_arbitrary.hpp
layout: document
redirect_from:
- /library/src/fps/formal_power_series_arbitrary.hpp
- /library/src/fps/formal_power_series_arbitrary.hpp.html
title: src/fps/formal_power_series_arbitrary.hpp
---