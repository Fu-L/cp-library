---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/convolution.hpp
    title: convolution
  - icon: ':heavy_check_mark:'
    path: src/fps/formal_power_series.hpp
    title: src/fps/formal_power_series.hpp
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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/pow_of_formal_power_series
  bundledCode: "#line 1 \"verify/library_checker/polynomial/pow_of_formal_power_series.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
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
    \    return a;\n}\n#line 4 \"src/fps/formal_power_series.hpp\"\ntemplate <typename\
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
    \ (*this).resize(1, mint(0));\n        (*this)[0] += r;\n        return (*this);\n\
    \    }\n    F& operator-=(const F& g) {\n        const int n = (*this).size();\n\
    \        const int m = g.size();\n        if(n < m) (*this).resize(m);\n     \
    \   for(int i = 0; i < m; ++i) (*this)[i] -= g[i];\n        return (*this);\n\
    \    }\n    F& operator-=(const mint& r) {\n        if((*this).empty()) (*this).resize(1,\
    \ mint(0));\n        (*this)[0] -= r;\n        return (*this);\n    }\n    F&\
    \ operator*=(const F& g) {\n        (*this) = convolution((*this), g);\n     \
    \   return (*this);\n    }\n    F& operator*=(const mint& r) {\n        const\
    \ int n = (*this).size();\n        for(int i = 0; i < n; ++i) (*this)[i] *= r;\n\
    \        return (*this);\n    }\n    F& operator/=(const F& g) {\n        if((*this).size()\
    \ < g.size()) {\n            (*this).clear();\n            return (*this);\n \
    \       }\n        const int n = (*this).size() - g.size() + 1;\n        (*this)\
    \ = ((*this).rev().pre(n) * g.rev().inv(n)).pre(n).rev();\n        return (*this);\n\
    \    }\n    F& operator/=(const mint& r) {\n        const int n = (*this).size();\n\
    \        mint inv_r = r.inv();\n        for(int i = 0; i < (int)n; ++i) (*this)[i]\
    \ *= inv_r;\n        return (*this);\n    }\n    F& operator%=(const F& g) {\n\
    \        (*this) -= (*this) / g * g;\n        shrink();\n        return (*this);\n\
    \    }\n    F operator*(const mint& g) const {\n        return F(*this) *= g;\n\
    \    }\n    F operator-(const mint& g) const {\n        return F(*this) -= g;\n\
    \    }\n    F operator+(const mint& g) const {\n        return F(*this) += g;\n\
    \    }\n    F operator/(const mint& g) const {\n        return F(*this) /= g;\n\
    \    }\n    F operator*(const F& g) const {\n        return F(*this) *= g;\n \
    \   }\n    F operator-(const F& g) const {\n        return F(*this) -= g;\n  \
    \  }\n    F operator+(const F& g) const {\n        return F(*this) += g;\n   \
    \ }\n    F operator/(const F& g) const {\n        return F(*this) /= g;\n    }\n\
    \    F operator%(const F& g) const {\n        return F(*this) %= g;\n    }\n \
    \   F operator<<(const int d) const {\n        F ret(*this);\n        ret.insert(ret.begin(),\
    \ d, mint(0));\n        return ret;\n    }\n    F operator>>(const int d) const\
    \ {\n        const int n = (*this).size();\n        if(n <= d) return {};\n  \
    \      F ret(*this);\n        ret.erase(ret.begin(), ret.begin() + d);\n     \
    \   return ret;\n    }\n    void shrink() {\n        while((*this).size() and\
    \ (*this).back() == mint(0)) (*this).pop_back();\n    }\n    F rev() const {\n\
    \        F ret(*this);\n        reverse(begin(ret), end(ret));\n        return\
    \ ret;\n    }\n    F pre(const int deg) const {\n        F ret(begin(*this), begin(*this)\
    \ + min((int)(*this).size(), deg));\n        if((int)ret.size() < deg) ret.resize(deg);\n\
    \        return ret;\n    }\n    mint eval(const mint& a) const {\n        const\
    \ int n = (*this).size();\n        mint x = 1, ret = 0;\n        for(int i = 0;\
    \ i < n; ++i) {\n            ret += (*this)[i] * x;\n            x *= a;\n   \
    \     }\n        return ret;\n    }\n    void onemul(const int d, const mint&\
    \ c, int deg = -1) {\n        const int n = (*this).size();\n        if(deg ==\
    \ -1) deg = n + d;\n        if(deg > n) (*this).resize(deg);\n        for(int\
    \ i = deg - d - 1; i >= 0; --i) {\n            (*this)[i + d] += (*this)[i] *\
    \ c;\n        }\n    }\n    void onediv(const int d, const mint& c, int deg =\
    \ -1) {\n        const int n = (*this).size();\n        if(deg == -1) deg = n;\n\
    \        if(deg > n) (*this).resize(deg + 1);\n        for(int i = 0; i < deg\
    \ - d; ++i) {\n            (*this)[i + d] -= (*this)[i] * c;\n        }\n    }\n\
    \    F diff() const {\n        const int n = (*this).size();\n        F ret(max(0,\
    \ n - 1));\n        for(int i = 1; i < n; ++i) ret[i - 1] = (*this)[i] * i;\n\
    \        return ret;\n    }\n    F integral() const {\n        const int n = (*this).size(),\
    \ mod = mint::mod();\n        F ret(n + 1);\n        ret[0] = mint(0);\n     \
    \   if(n > 0) ret[1] = mint(1);\n        for(int i = 2; i <= n; ++i) ret[i] =\
    \ (-ret[mod % i]) * (mod / i);\n        for(int i = 0; i < n; ++i) ret[i + 1]\
    \ *= (*this)[i];\n        return ret;\n    }\n    F inv(int deg = -1) const {\n\
    \        const int n = (*this).size();\n        assert(n > 0 and (*this)[0] !=\
    \ mint(0));\n        if(deg == -1) deg = n;\n        F g(1);\n        g[0] = (*this)[0].inv();\n\
    \        while((int)g.size() < deg) {\n            int m = g.size();\n       \
    \     F f(begin(*this), begin(*this) + min(n, 2 * m));\n            F r(g);\n\
    \            f.resize(2 * m);\n            r.resize(2 * m);\n            butterfly(f);\n\
    \            butterfly(r);\n            for(int i = 0; i < 2 * m; ++i) f[i] *=\
    \ r[i];\n            butterfly_inv(f);\n            f.erase(f.begin(), f.begin()\
    \ + m);\n            f.resize(2 * m);\n            butterfly(f);\n           \
    \ for(int i = 0; i < 2 * m; ++i) f[i] *= r[i];\n            butterfly_inv(f);\n\
    \            mint in = mint(2 * m).inv();\n            in *= -in;\n          \
    \  for(int i = 0; i < m; ++i) f[i] *= in;\n            g.insert(g.end(), f.begin(),\
    \ f.begin() + m);\n        }\n        return g.pre(deg);\n    }\n    F log(int\
    \ deg = -1) const {\n        const int n = (*this).size();\n        assert(n >\
    \ 0 and (*this)[0] == mint(1));\n        if(deg == -1) deg = n;\n        return\
    \ ((*this).diff() * (*this).inv(deg)).pre(deg - 1).integral();\n    }\n    F exp(int\
    \ deg = -1) const {\n        const int n = (*this).size();\n        assert(n ==\
    \ 0 or (*this)[0] == 0);\n        if(deg == -1) deg = n;\n        F Inv;\n   \
    \     Inv.reserve(deg + 1);\n        Inv.push_back(mint(0));\n        Inv.push_back(mint(1));\n\
    \        auto inplace_integral = [&](F& f) -> void {\n            const int n\
    \ = (int)f.size(), mod = mint::mod();\n            while((int)Inv.size() <= n)\
    \ {\n                int i = Inv.size();\n                Inv.push_back((-Inv[mod\
    \ % i]) * (mod / i));\n            }\n            f.insert(begin(f), mint(0));\n\
    \            for(int i = 1; i <= n; ++i) f[i] *= Inv[i];\n        };\n       \
    \ auto inplace_diff = [](F& f) -> void {\n            if(f.empty()) return;\n\
    \            f.erase(begin(f));\n            mint coeff = 1;\n            for(int\
    \ i = 0; i < (int)f.size(); ++i) {\n                f[i] *= coeff;\n         \
    \       ++coeff;\n            }\n        };\n        F b{1, 1 < (int)(*this).size()\
    \ ? (*this)[1] : 0}, c{1}, z1, z2{1, 1};\n        for(int m = 2; m < deg; m <<=\
    \ 1) {\n            auto y = b;\n            y.resize(2 * m);\n            butterfly(y);\n\
    \            z1 = z2;\n            F z(m);\n            for(int i = 0; i < m;\
    \ ++i) z[i] = y[i] * z1[i];\n            butterfly_inv(z);\n            mint si\
    \ = mint(m).inv();\n            for(int i = 0; i < m; ++i) z[i] *= si;\n     \
    \       fill(begin(z), begin(z) + m / 2, mint(0));\n            butterfly(z);\n\
    \            for(int i = 0; i < m; ++i) z[i] *= -z1[i];\n            butterfly_inv(z);\n\
    \            for(int i = 0; i < m; ++i) z[i] *= si;\n            c.insert(end(c),\
    \ begin(z) + m / 2, end(z));\n            z2 = c;\n            z2.resize(2 * m);\n\
    \            butterfly(z2);\n            F x(begin((*this)), begin((*this)) +\
    \ min<int>((*this).size(), m));\n            x.resize(m);\n            inplace_diff(x);\n\
    \            x.push_back(mint(0));\n            butterfly(x);\n            for(int\
    \ i = 0; i < m; ++i) x[i] *= y[i];\n            butterfly_inv(x);\n          \
    \  for(int i = 0; i < m; ++i) x[i] *= si;\n            x -= b.diff();\n      \
    \      x.resize(2 * m);\n            for(int i = 0; i < m - 1; ++i) x[m + i] =\
    \ x[i], x[i] = mint(0);\n            butterfly(x);\n            for(int i = 0;\
    \ i < 2 * m; ++i) x[i] *= z2[i];\n            butterfly_inv(x);\n            mint\
    \ si2 = mint(m << 1).inv();\n            for(int i = 0; i < 2 * m; ++i) x[i] *=\
    \ si2;\n            x.pop_back();\n            inplace_integral(x);\n        \
    \    for(int i = m; i < min<int>((*this).size(), 2 * m); ++i) x[i] += (*this)[i];\n\
    \            fill(begin(x), begin(x) + m, mint(0));\n            butterfly(x);\n\
    \            for(int i = 0; i < 2 * m; ++i) x[i] *= y[i];\n            butterfly_inv(x);\n\
    \            for(int i = 0; i < 2 * m; ++i) x[i] *= si2;\n            b.insert(end(b),\
    \ begin(x) + m, end(x));\n        }\n        return b.pre(deg);\n    }\n    F\
    \ pow(const ll k, int deg = -1) const {\n        const int n = (*this).size();\n\
    \        if(deg == -1) deg = n;\n        if(k == 0) {\n            F ret(deg);\n\
    \            if(deg) ret[0] = 1;\n            return ret;\n        }\n       \
    \ for(int i = 0; i < n; ++i) {\n            if((*this)[i] != mint(0)) {\n    \
    \            mint rev = mint(1) / (*this)[i];\n                F ret = (((*this\
    \ * rev) >> i).log(deg) * k).exp(deg);\n                ret *= (*this)[i].pow(k);\n\
    \                ret = (ret << (i * k)).pre(deg);\n                if((int)ret.size()\
    \ < deg) ret.resize(deg, mint(0));\n                return ret;\n            }\n\
    \            if(__int128_t(i + 1) * k >= deg) return F(deg, mint(0));\n      \
    \  }\n        return F(deg, mint(0));\n    }\n    F shift(const mint& c) const\
    \ {\n        int n = (*this).size();\n        vector<mint> fact(n), ifact(n);\n\
    \        fact[0] = ifact[0] = mint(1);\n        for(int i = 1; i < n; ++i) fact[i]\
    \ = fact[i - 1] * i;\n        ifact[n - 1] = mint(1) / fact[n - 1];\n        for(int\
    \ i = n - 1; i > 1; --i) ifact[i - 1] = ifact[i] * i;\n        F ret(*this);\n\
    \        for(int i = 0; i < n; ++i) ret[i] *= fact[i];\n        ret = ret.rev();\n\
    \        F bs(n, mint(1));\n        for(int i = 1; i < n; ++i) bs[i] = bs[i -\
    \ 1] * c * ifact[i] * fact[i - 1];\n        ret = (ret * bs).pre(n);\n       \
    \ ret = ret.rev();\n        for(int i = 0; i < n; ++i) ret[i] *= ifact[i];\n \
    \       return ret;\n    }\n};\n#line 5 \"verify/library_checker/polynomial/pow_of_formal_power_series.test.cpp\"\
    \nusing mint = modint998244353;\nint main(void) {\n    int n;\n    ll m;\n   \
    \ cin >> n >> m;\n    FormalPowerSeries<mint> f(n);\n    rep(i, 0, n) cin >> f[i];\n\
    \    FormalPowerSeries<mint> g = f.pow(m);\n    rep(i, 0, n) cout << g[i] << \"\
    \ \\n\"[i + 1 == n];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/template/static_modint.hpp\"\
    \n#include \"../../../src/fps/formal_power_series.hpp\"\nusing mint = modint998244353;\n\
    int main(void) {\n    int n;\n    ll m;\n    cin >> n >> m;\n    FormalPowerSeries<mint>\
    \ f(n);\n    rep(i, 0, n) cin >> f[i];\n    FormalPowerSeries<mint> g = f.pow(m);\n\
    \    rep(i, 0, n) cout << g[i] << \" \\n\"[i + 1 == n];\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/static_modint.hpp
  - src/fps/formal_power_series.hpp
  - src/convolution/convolution.hpp
  - src/math/primitive_root.hpp
  - src/math/pow_mod.hpp
  isVerificationFile: true
  path: verify/library_checker/polynomial/pow_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 00:57:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/polynomial/pow_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/polynomial/pow_of_formal_power_series.test.cpp
- /verify/verify/library_checker/polynomial/pow_of_formal_power_series.test.cpp.html
title: verify/library_checker/polynomial/pow_of_formal_power_series.test.cpp
---
