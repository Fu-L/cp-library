---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/convolution/convolution.hpp
    title: convolution
  - icon: ':question:'
    path: src/math/pow_mod.hpp
    title: pow_mod
  - icon: ':question:'
    path: src/math/primitive_root.hpp
    title: primitive_root
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/math/find_linear_recurrence.test.cpp
    title: verify/library_checker/math/find_linear_recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: verify/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':x:'
    path: verify/library_checker/polynomial/division_of_polynomial.test.cpp
    title: verify/library_checker/polynomial/division_of_polynomial.test.cpp
  - icon: ':x:'
    path: verify/library_checker/polynomial/exp_of_formal_power_series.test.cpp
    title: verify/library_checker/polynomial/exp_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/library_checker/polynomial/inv_of_formal_power_series.test.cpp
    title: verify/library_checker/polynomial/inv_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/library_checker/polynomial/log_of_formal_power_series.test.cpp
    title: verify/library_checker/polynomial/log_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/library_checker/polynomial/polynomial_taylor_shift.test.cpp
    title: verify/library_checker/polynomial/polynomial_taylor_shift.test.cpp
  - icon: ':x:'
    path: verify/library_checker/polynomial/pow_of_formal_power_series.test.cpp
    title: verify/library_checker/polynomial/pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
    title: verify/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/pow_mod.hpp\"\n\
    constexpr long long pow_mod(long long x, long long n, const long long mod) {\n\
    \    assert(n >= 0 and mod >= 1);\n    x %= mod;\n    if(x < 0) x += mod;\n  \
    \  long long res = 1;\n    while(n > 0) {\n        if(n & 1) res = res * x % mod;\n\
    \        x = x * x % mod;\n        n >>= 1;\n    }\n    return res;\n}\n#line\
    \ 4 \"src/math/primitive_root.hpp\"\nconstexpr int primitive_root(int m) {\n \
    \   if(m == 2) return 1;\n    if(m == 167772161) return 3;\n    if(m == 469762049)\
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
    \ mint>\nvector<mint> convolution(vector<mint> a, vector<mint> b) {\n    const\
    \ int n = (int)a.size(), m = (int)b.size();\n    if(n == 0 or m == 0) return {};\n\
    \    int z = 1;\n    while(z < n + m - 1) z *= 2;\n    assert((mint::mod() - 1)\
    \ % z == 0);\n    if(min(n, m) <= 60) return convolution_naive(a, b);\n    a.resize(z);\n\
    \    b.resize(z);\n    butterfly(a);\n    butterfly(b);\n    for(int i = 0; i\
    \ < z; ++i) a[i] *= b[i];\n    butterfly_inv(a);\n    a.resize(n + m - 1);\n \
    \   const mint iz = mint(z).inv();\n    for(int i = 0; i < n + m - 1; ++i) a[i]\
    \ *= iz;\n    return a;\n}\n#line 4 \"src/fps/formal_power_series.hpp\"\ntemplate\
    \ <typename mint>\nstruct FormalPowerSeries : vector<mint> {\n    using vector<mint>::vector;\n\
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
    \        const mint inv_r = r.inv();\n        for(int i = 0; i < n; ++i) (*this)[i]\
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
    \   return ret;\n    }\n    void shrink() {\n        while(!(*this).empty() and\
    \ (*this).back() == mint(0)) (*this).pop_back();\n    }\n    F rev() const {\n\
    \        F ret(*this);\n        reverse(begin(ret), end(ret));\n        return\
    \ ret;\n    }\n    F pre(const int deg) const {\n        assert(deg >= 0);\n \
    \       F ret(begin(*this), begin(*this) + min((int)(*this).size(), deg));\n \
    \       if((int)ret.size() < deg) ret.resize(deg);\n        return ret;\n    }\n\
    \    mint eval(const mint& a) const {\n        const int n = (*this).size();\n\
    \        mint x = 1, ret = 0;\n        for(int i = 0; i < n; ++i) {\n        \
    \    ret += (*this)[i] * x;\n            x *= a;\n        }\n        return ret;\n\
    \    }\n    void onemul(const int d, const mint& c, int deg = -1) {\n        assert(deg\
    \ >= -1);\n        const int n = (*this).size();\n        if(deg == -1) deg =\
    \ n + d;\n        if(deg > n) (*this).resize(deg);\n        for(int i = deg -\
    \ d - 1; i >= 0; --i) {\n            (*this)[i + d] += (*this)[i] * c;\n     \
    \   }\n    }\n    void onediv(const int d, const mint& c, int deg = -1) {\n  \
    \      assert(deg >= -1);\n        const int n = (*this).size();\n        if(deg\
    \ == -1) deg = n;\n        if(deg > n) (*this).resize(deg + 1);\n        for(int\
    \ i = 0; i < deg - d; ++i) {\n            (*this)[i + d] -= (*this)[i] * c;\n\
    \        }\n    }\n    F diff() const {\n        const int n = (*this).size();\n\
    \        F ret(max(0, n - 1));\n        for(int i = 1; i < n; ++i) ret[i - 1]\
    \ = (*this)[i] * i;\n        return ret;\n    }\n    F integral() const {\n  \
    \      const int n = (*this).size();\n        static constexpr int mod = mint::mod();\n\
    \        F ret(n + 1);\n        ret[0] = mint(0);\n        if(n > 0) ret[1] =\
    \ mint(1);\n        for(int i = 2; i <= n; ++i) ret[i] = (-ret[mod % i]) * (mod\
    \ / i);\n        for(int i = 0; i < n; ++i) ret[i + 1] *= (*this)[i];\n      \
    \  return ret;\n    }\n    F inv(int deg = -1) const {\n        assert(deg >=\
    \ -1);\n        const int n = (*this).size();\n        assert(n > 0 and (*this)[0]\
    \ != mint(0));\n        if(deg == -1) deg = n;\n        F g(1);\n        g[0]\
    \ = (*this)[0].inv();\n        while((int)g.size() < deg) {\n            const\
    \ int m = g.size();\n            F f(begin(*this), begin(*this) + min(n, 2 * m));\n\
    \            F r(g);\n            f.resize(2 * m);\n            r.resize(2 * m);\n\
    \            butterfly(f);\n            butterfly(r);\n            for(int i =\
    \ 0; i < 2 * m; ++i) f[i] *= r[i];\n            butterfly_inv(f);\n          \
    \  f.erase(f.begin(), f.begin() + m);\n            f.resize(2 * m);\n        \
    \    butterfly(f);\n            for(int i = 0; i < 2 * m; ++i) f[i] *= r[i];\n\
    \            butterfly_inv(f);\n            mint in = mint(2 * m).inv();\n   \
    \         in *= -in;\n            for(int i = 0; i < m; ++i) f[i] *= in;\n   \
    \         g.insert(g.end(), f.begin(), f.begin() + m);\n        }\n        return\
    \ g.pre(deg);\n    }\n    F log(int deg = -1) const {\n        assert(deg >= -1);\n\
    \        const int n = (*this).size();\n        assert(n > 0 and (*this)[0] ==\
    \ mint(1));\n        if(deg == -1) deg = n;\n        return ((*this).diff() *\
    \ (*this).inv(deg)).pre(deg - 1).integral();\n    }\n    F exp(int deg = -1) const\
    \ {\n        assert(deg >= -1);\n        const int n = (*this).size();\n     \
    \   assert(n == 0 or (*this)[0] == 0);\n        if(deg == -1) deg = n;\n     \
    \   F Inv;\n        Inv.reserve(deg + 1);\n        Inv.emplace_back(mint(0));\n\
    \        Inv.emplace_back(mint(1));\n        auto inplace_integral = [&](F& f)\
    \ -> void {\n            const int n = (int)f.size();\n            static constexpr\
    \ int mod = mint::mod();\n            while((int)Inv.size() <= n) {\n        \
    \        const int i = Inv.size();\n                Inv.emplace_back((-Inv[mod\
    \ % i]) * (mod / i));\n            }\n            f.insert(begin(f), mint(0));\n\
    \            for(int i = 1; i <= n; ++i) f[i] *= Inv[i];\n        };\n       \
    \ auto inplace_diff = [](F& f) -> void {\n            if(f.empty()) return;\n\
    \            f.erase(begin(f));\n            mint coeff = 1;\n            for(int\
    \ i = 0; i < (int)f.size(); ++i) {\n                f[i] *= coeff;\n         \
    \       ++coeff;\n            }\n        };\n        F b{1, 1 < (int)(*this).size()\
    \ ? (*this)[1] : 0}, c{1}, z1, z2{1, 1};\n        for(int m = 2; m < deg; m <<=\
    \ 1) {\n            auto y = b;\n            y.resize(2 * m);\n            butterfly(y);\n\
    \            z1 = z2;\n            F z(m);\n            for(int i = 0; i < m;\
    \ ++i) z[i] = y[i] * z1[i];\n            butterfly_inv(z);\n            const\
    \ mint si = mint(m).inv();\n            for(int i = 0; i < m; ++i) z[i] *= si;\n\
    \            fill(begin(z), begin(z) + m / 2, mint(0));\n            butterfly(z);\n\
    \            for(int i = 0; i < m; ++i) z[i] *= -z1[i];\n            butterfly_inv(z);\n\
    \            for(int i = 0; i < m; ++i) z[i] *= si;\n            c.insert(end(c),\
    \ begin(z) + m / 2, end(z));\n            z2 = c;\n            z2.resize(2 * m);\n\
    \            butterfly(z2);\n            F x(begin((*this)), begin((*this)) +\
    \ min<int>((*this).size(), m));\n            x.resize(m);\n            inplace_diff(x);\n\
    \            x.emplace_back(mint(0));\n            butterfly(x);\n           \
    \ for(int i = 0; i < m; ++i) x[i] *= y[i];\n            butterfly_inv(x);\n  \
    \          for(int i = 0; i < m; ++i) x[i] *= si;\n            x -= b.diff();\n\
    \            x.resize(2 * m);\n            for(int i = 0; i < m - 1; ++i) x[m\
    \ + i] = x[i], x[i] = mint(0);\n            butterfly(x);\n            for(int\
    \ i = 0; i < 2 * m; ++i) x[i] *= z2[i];\n            butterfly_inv(x);\n     \
    \       const mint si2 = mint(m << 1).inv();\n            for(int i = 0; i < 2\
    \ * m; ++i) x[i] *= si2;\n            x.pop_back();\n            inplace_integral(x);\n\
    \            for(int i = m; i < min<int>((*this).size(), 2 * m); ++i) x[i] +=\
    \ (*this)[i];\n            fill(begin(x), begin(x) + m, mint(0));\n          \
    \  butterfly(x);\n            for(int i = 0; i < 2 * m; ++i) x[i] *= y[i];\n \
    \           butterfly_inv(x);\n            for(int i = 0; i < 2 * m; ++i) x[i]\
    \ *= si2;\n            b.insert(end(b), begin(x) + m, end(x));\n        }\n  \
    \      return b.pre(deg);\n    }\n    F pow(const long long k, int deg = -1) const\
    \ {\n        assert(deg >= -1);\n        assert(k >= 0);\n        const int n\
    \ = (*this).size();\n        if(deg == -1) deg = n;\n        if(k == 0) {\n  \
    \          F ret(deg);\n            if(deg) ret[0] = 1;\n            return ret;\n\
    \        }\n        for(int i = 0; i < n; ++i) {\n            if((*this)[i] !=\
    \ mint(0)) {\n                mint rev = mint(1) / (*this)[i];\n             \
    \   F ret = (((*this * rev) >> i).log(deg) * k).exp(deg);\n                ret\
    \ *= (*this)[i].pow(k);\n                ret = (ret << (i * k)).pre(deg);\n  \
    \              if((int)ret.size() < deg) ret.resize(deg, mint(0));\n         \
    \       return ret;\n            }\n            if(__int128_t(i + 1) * k >= deg)\
    \ return F(deg, mint(0));\n        }\n        return F(deg, mint(0));\n    }\n\
    \    F shift(const mint& c) const {\n        const int n = (*this).size();\n \
    \       vector<mint> fact(n), ifact(n);\n        fact[0] = ifact[0] = mint(1);\n\
    \        for(int i = 1; i < n; ++i) fact[i] = fact[i - 1] * i;\n        ifact[n\
    \ - 1] = mint(1) / fact[n - 1];\n        for(int i = n - 1; i > 1; --i) ifact[i\
    \ - 1] = ifact[i] * i;\n        F ret(*this);\n        for(int i = 0; i < n; ++i)\
    \ ret[i] *= fact[i];\n        ret = ret.rev();\n        F bs(n, mint(1));\n  \
    \      for(int i = 1; i < n; ++i) bs[i] = bs[i - 1] * c * ifact[i] * fact[i -\
    \ 1];\n        ret = (ret * bs).pre(n);\n        ret = ret.rev();\n        for(int\
    \ i = 0; i < n; ++i) ret[i] *= ifact[i];\n        return ret;\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../convolution/convolution.hpp\"\
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
    \        if((*this).empty()) (*this).resize(1, mint(0));\n        (*this)[0] +=\
    \ r;\n        return (*this);\n    }\n    F& operator-=(const F& g) {\n      \
    \  const int n = (*this).size();\n        const int m = g.size();\n        if(n\
    \ < m) (*this).resize(m);\n        for(int i = 0; i < m; ++i) (*this)[i] -= g[i];\n\
    \        return (*this);\n    }\n    F& operator-=(const mint& r) {\n        if((*this).empty())\
    \ (*this).resize(1, mint(0));\n        (*this)[0] -= r;\n        return (*this);\n\
    \    }\n    F& operator*=(const F& g) {\n        (*this) = convolution((*this),\
    \ g);\n        return (*this);\n    }\n    F& operator*=(const mint& r) {\n  \
    \      const int n = (*this).size();\n        for(int i = 0; i < n; ++i) (*this)[i]\
    \ *= r;\n        return (*this);\n    }\n    F& operator/=(const F& g) {\n   \
    \     if((*this).size() < g.size()) {\n            (*this).clear();\n        \
    \    return (*this);\n        }\n        const int n = (*this).size() - g.size()\
    \ + 1;\n        (*this) = ((*this).rev().pre(n) * g.rev().inv(n)).pre(n).rev();\n\
    \        return (*this);\n    }\n    F& operator/=(const mint& r) {\n        const\
    \ int n = (*this).size();\n        const mint inv_r = r.inv();\n        for(int\
    \ i = 0; i < n; ++i) (*this)[i] *= inv_r;\n        return (*this);\n    }\n  \
    \  F& operator%=(const F& g) {\n        (*this) -= (*this) / g * g;\n        shrink();\n\
    \        return (*this);\n    }\n    F operator*(const mint& g) const {\n    \
    \    return F(*this) *= g;\n    }\n    F operator-(const mint& g) const {\n  \
    \      return F(*this) -= g;\n    }\n    F operator+(const mint& g) const {\n\
    \        return F(*this) += g;\n    }\n    F operator/(const mint& g) const {\n\
    \        return F(*this) /= g;\n    }\n    F operator*(const F& g) const {\n \
    \       return F(*this) *= g;\n    }\n    F operator-(const F& g) const {\n  \
    \      return F(*this) -= g;\n    }\n    F operator+(const F& g) const {\n   \
    \     return F(*this) += g;\n    }\n    F operator/(const F& g) const {\n    \
    \    return F(*this) /= g;\n    }\n    F operator%(const F& g) const {\n     \
    \   return F(*this) %= g;\n    }\n    F operator<<(const int d) const {\n    \
    \    F ret(*this);\n        ret.insert(ret.begin(), d, mint(0));\n        return\
    \ ret;\n    }\n    F operator>>(const int d) const {\n        const int n = (*this).size();\n\
    \        if(n <= d) return {};\n        F ret(*this);\n        ret.erase(ret.begin(),\
    \ ret.begin() + d);\n        return ret;\n    }\n    void shrink() {\n       \
    \ while(!(*this).empty() and (*this).back() == mint(0)) (*this).pop_back();\n\
    \    }\n    F rev() const {\n        F ret(*this);\n        reverse(begin(ret),\
    \ end(ret));\n        return ret;\n    }\n    F pre(const int deg) const {\n \
    \       assert(deg >= 0);\n        F ret(begin(*this), begin(*this) + min((int)(*this).size(),\
    \ deg));\n        if((int)ret.size() < deg) ret.resize(deg);\n        return ret;\n\
    \    }\n    mint eval(const mint& a) const {\n        const int n = (*this).size();\n\
    \        mint x = 1, ret = 0;\n        for(int i = 0; i < n; ++i) {\n        \
    \    ret += (*this)[i] * x;\n            x *= a;\n        }\n        return ret;\n\
    \    }\n    void onemul(const int d, const mint& c, int deg = -1) {\n        assert(deg\
    \ >= -1);\n        const int n = (*this).size();\n        if(deg == -1) deg =\
    \ n + d;\n        if(deg > n) (*this).resize(deg);\n        for(int i = deg -\
    \ d - 1; i >= 0; --i) {\n            (*this)[i + d] += (*this)[i] * c;\n     \
    \   }\n    }\n    void onediv(const int d, const mint& c, int deg = -1) {\n  \
    \      assert(deg >= -1);\n        const int n = (*this).size();\n        if(deg\
    \ == -1) deg = n;\n        if(deg > n) (*this).resize(deg + 1);\n        for(int\
    \ i = 0; i < deg - d; ++i) {\n            (*this)[i + d] -= (*this)[i] * c;\n\
    \        }\n    }\n    F diff() const {\n        const int n = (*this).size();\n\
    \        F ret(max(0, n - 1));\n        for(int i = 1; i < n; ++i) ret[i - 1]\
    \ = (*this)[i] * i;\n        return ret;\n    }\n    F integral() const {\n  \
    \      const int n = (*this).size();\n        static constexpr int mod = mint::mod();\n\
    \        F ret(n + 1);\n        ret[0] = mint(0);\n        if(n > 0) ret[1] =\
    \ mint(1);\n        for(int i = 2; i <= n; ++i) ret[i] = (-ret[mod % i]) * (mod\
    \ / i);\n        for(int i = 0; i < n; ++i) ret[i + 1] *= (*this)[i];\n      \
    \  return ret;\n    }\n    F inv(int deg = -1) const {\n        assert(deg >=\
    \ -1);\n        const int n = (*this).size();\n        assert(n > 0 and (*this)[0]\
    \ != mint(0));\n        if(deg == -1) deg = n;\n        F g(1);\n        g[0]\
    \ = (*this)[0].inv();\n        while((int)g.size() < deg) {\n            const\
    \ int m = g.size();\n            F f(begin(*this), begin(*this) + min(n, 2 * m));\n\
    \            F r(g);\n            f.resize(2 * m);\n            r.resize(2 * m);\n\
    \            butterfly(f);\n            butterfly(r);\n            for(int i =\
    \ 0; i < 2 * m; ++i) f[i] *= r[i];\n            butterfly_inv(f);\n          \
    \  f.erase(f.begin(), f.begin() + m);\n            f.resize(2 * m);\n        \
    \    butterfly(f);\n            for(int i = 0; i < 2 * m; ++i) f[i] *= r[i];\n\
    \            butterfly_inv(f);\n            mint in = mint(2 * m).inv();\n   \
    \         in *= -in;\n            for(int i = 0; i < m; ++i) f[i] *= in;\n   \
    \         g.insert(g.end(), f.begin(), f.begin() + m);\n        }\n        return\
    \ g.pre(deg);\n    }\n    F log(int deg = -1) const {\n        assert(deg >= -1);\n\
    \        const int n = (*this).size();\n        assert(n > 0 and (*this)[0] ==\
    \ mint(1));\n        if(deg == -1) deg = n;\n        return ((*this).diff() *\
    \ (*this).inv(deg)).pre(deg - 1).integral();\n    }\n    F exp(int deg = -1) const\
    \ {\n        assert(deg >= -1);\n        const int n = (*this).size();\n     \
    \   assert(n == 0 or (*this)[0] == 0);\n        if(deg == -1) deg = n;\n     \
    \   F Inv;\n        Inv.reserve(deg + 1);\n        Inv.emplace_back(mint(0));\n\
    \        Inv.emplace_back(mint(1));\n        auto inplace_integral = [&](F& f)\
    \ -> void {\n            const int n = (int)f.size();\n            static constexpr\
    \ int mod = mint::mod();\n            while((int)Inv.size() <= n) {\n        \
    \        const int i = Inv.size();\n                Inv.emplace_back((-Inv[mod\
    \ % i]) * (mod / i));\n            }\n            f.insert(begin(f), mint(0));\n\
    \            for(int i = 1; i <= n; ++i) f[i] *= Inv[i];\n        };\n       \
    \ auto inplace_diff = [](F& f) -> void {\n            if(f.empty()) return;\n\
    \            f.erase(begin(f));\n            mint coeff = 1;\n            for(int\
    \ i = 0; i < (int)f.size(); ++i) {\n                f[i] *= coeff;\n         \
    \       ++coeff;\n            }\n        };\n        F b{1, 1 < (int)(*this).size()\
    \ ? (*this)[1] : 0}, c{1}, z1, z2{1, 1};\n        for(int m = 2; m < deg; m <<=\
    \ 1) {\n            auto y = b;\n            y.resize(2 * m);\n            butterfly(y);\n\
    \            z1 = z2;\n            F z(m);\n            for(int i = 0; i < m;\
    \ ++i) z[i] = y[i] * z1[i];\n            butterfly_inv(z);\n            const\
    \ mint si = mint(m).inv();\n            for(int i = 0; i < m; ++i) z[i] *= si;\n\
    \            fill(begin(z), begin(z) + m / 2, mint(0));\n            butterfly(z);\n\
    \            for(int i = 0; i < m; ++i) z[i] *= -z1[i];\n            butterfly_inv(z);\n\
    \            for(int i = 0; i < m; ++i) z[i] *= si;\n            c.insert(end(c),\
    \ begin(z) + m / 2, end(z));\n            z2 = c;\n            z2.resize(2 * m);\n\
    \            butterfly(z2);\n            F x(begin((*this)), begin((*this)) +\
    \ min<int>((*this).size(), m));\n            x.resize(m);\n            inplace_diff(x);\n\
    \            x.emplace_back(mint(0));\n            butterfly(x);\n           \
    \ for(int i = 0; i < m; ++i) x[i] *= y[i];\n            butterfly_inv(x);\n  \
    \          for(int i = 0; i < m; ++i) x[i] *= si;\n            x -= b.diff();\n\
    \            x.resize(2 * m);\n            for(int i = 0; i < m - 1; ++i) x[m\
    \ + i] = x[i], x[i] = mint(0);\n            butterfly(x);\n            for(int\
    \ i = 0; i < 2 * m; ++i) x[i] *= z2[i];\n            butterfly_inv(x);\n     \
    \       const mint si2 = mint(m << 1).inv();\n            for(int i = 0; i < 2\
    \ * m; ++i) x[i] *= si2;\n            x.pop_back();\n            inplace_integral(x);\n\
    \            for(int i = m; i < min<int>((*this).size(), 2 * m); ++i) x[i] +=\
    \ (*this)[i];\n            fill(begin(x), begin(x) + m, mint(0));\n          \
    \  butterfly(x);\n            for(int i = 0; i < 2 * m; ++i) x[i] *= y[i];\n \
    \           butterfly_inv(x);\n            for(int i = 0; i < 2 * m; ++i) x[i]\
    \ *= si2;\n            b.insert(end(b), begin(x) + m, end(x));\n        }\n  \
    \      return b.pre(deg);\n    }\n    F pow(const long long k, int deg = -1) const\
    \ {\n        assert(deg >= -1);\n        assert(k >= 0);\n        const int n\
    \ = (*this).size();\n        if(deg == -1) deg = n;\n        if(k == 0) {\n  \
    \          F ret(deg);\n            if(deg) ret[0] = 1;\n            return ret;\n\
    \        }\n        for(int i = 0; i < n; ++i) {\n            if((*this)[i] !=\
    \ mint(0)) {\n                mint rev = mint(1) / (*this)[i];\n             \
    \   F ret = (((*this * rev) >> i).log(deg) * k).exp(deg);\n                ret\
    \ *= (*this)[i].pow(k);\n                ret = (ret << (i * k)).pre(deg);\n  \
    \              if((int)ret.size() < deg) ret.resize(deg, mint(0));\n         \
    \       return ret;\n            }\n            if(__int128_t(i + 1) * k >= deg)\
    \ return F(deg, mint(0));\n        }\n        return F(deg, mint(0));\n    }\n\
    \    F shift(const mint& c) const {\n        const int n = (*this).size();\n \
    \       vector<mint> fact(n), ifact(n);\n        fact[0] = ifact[0] = mint(1);\n\
    \        for(int i = 1; i < n; ++i) fact[i] = fact[i - 1] * i;\n        ifact[n\
    \ - 1] = mint(1) / fact[n - 1];\n        for(int i = n - 1; i > 1; --i) ifact[i\
    \ - 1] = ifact[i] * i;\n        F ret(*this);\n        for(int i = 0; i < n; ++i)\
    \ ret[i] *= fact[i];\n        ret = ret.rev();\n        F bs(n, mint(1));\n  \
    \      for(int i = 1; i < n; ++i) bs[i] = bs[i - 1] * c * ifact[i] * fact[i -\
    \ 1];\n        ret = (ret * bs).pre(n);\n        ret = ret.rev();\n        for(int\
    \ i = 0; i < n; ++i) ret[i] *= ifact[i];\n        return ret;\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  - src/convolution/convolution.hpp
  - src/math/primitive_root.hpp
  - src/math/pow_mod.hpp
  isVerificationFile: false
  path: src/fps/formal_power_series.hpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/library_checker/polynomial/log_of_formal_power_series.test.cpp
  - verify/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
  - verify/library_checker/polynomial/polynomial_taylor_shift.test.cpp
  - verify/library_checker/polynomial/pow_of_formal_power_series.test.cpp
  - verify/library_checker/polynomial/inv_of_formal_power_series.test.cpp
  - verify/library_checker/polynomial/division_of_polynomial.test.cpp
  - verify/library_checker/polynomial/exp_of_formal_power_series.test.cpp
  - verify/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
  - verify/library_checker/math/find_linear_recurrence.test.cpp
documentation_of: src/fps/formal_power_series.hpp
layout: document
title: FormalPowerSeries
---

# FormalPowerSeries

形式的冪級数の計算を行うライブラリです．

$\mathrm{mod}$ が $\mathrm{NTT-friendly}$ なときのみ使えます．<br>
そうでない $\mathrm{mod}$ や `long long` の範囲で形式的冪級数を扱いたい場合は `FormalPowerSeriesArbitrary` や `FormalPowerSeriesLL` を使ってください．

基本的な使い方としては以下のとおりです．

```cpp
#include "template/template.hpp"
#include "template/static_modint.hpp"
#include "fps/formal_power_series.hpp"
using mint = modint998244353;
using fps = FormalPowerSeries<mint>;
int main(void) {
    fps f(10), g(10);
    for(int i = 0; i < 10; i++) {
        f[i] = i;
        g[i] = i * 2;
    }
    fps h = f * g;
    for(int i = 0; i < 19; i++) {
        cout << h[i] << '\n';
    }
}
```

## コンストラクタ

```cpp
fps f(int n)
```

$n - 1$ 次の多項式 $f$ を作ります．<br>
初期値は $f(x) = 0 + 0x + 0x^2 + ... + 0x^{n - 1}$ です．

**制約**

- $0 \leq n$

**計算量**

- $O(n)$

## eval

```cpp
mint f.eval(mint a)
```

$f(a)$ を返します．

**計算量**

- $O(n)$

## shrink

```cpp
void f.shrink()
```

係数が $0$ となっている高次の項を削除します．

たとえば $f(x) = 1 + 0x + 3x^2 + 0x^3 + 0x^4$ なら $f(x) = 1 + 0x + 3x^2$ となります．

**計算量**

- $O(n)$

## pre

```cpp
fps f.pre(int deg)
```

$f(x)$ の `deg` 次以下の項を取り出します．<br>
$\mathrm{deg} > n$ の場合は多項式が拡張されます．

**制約**

- $0 \leq \mathrm{deg}$

**計算量**

- $O(\mathrm{deg})$

## rev

```cpp
fps f.rev()
```

係数を逆順にします．

たとえば $f(x) = 1 + 2x + 3x^2$ なら $f(x) = 3 + 2x + 1x^2$ となります．

**計算量**

- $O(n)$

## 各種演算

```cpp
fps = fps;

-fps;

fps += mint;
fps -= mint;
fps *= mint;
fps /= mint;

fps += fps;
fps -= fps;
fps *= fps;
fps /= fps;
fps %= fps;

fps + mint;
fps - mint;
fps * mint;
fps / mint;

fps + fps;
fps - fps;
fps * fps;
fps / fps;
fps % fps;

fps << int;
fps >> int;
```

が動きます．

サイズの調整などは適宜行なってくれます．

`fps / fps` および `fps % fps` は，多項式としての除算です．<br>
すなわち $f(x) = g(x) q(x) + r(x)$ と表せるとき，<br>
`f(x) / g(x) = q(x)` ， `f(x) % g(x) = r(x)` です．

また `fps << (int d)` は $f(x) * x^d$ です．<br>
`fps >> (int d)` は $f(x) / x^d$ です．

**制約**

- 除算・剰余演算で未定義な演算をしないこと

**計算量**

- $O(1)$ (多項式とmintの加算・減算)
- $O(n \log n)$ (多項式同士の乗算・除算・剰余演算)
- $O(n)$ (その他)

## onemul

```cpp
void f.onemul(int d, mint c, int deg = -1)
```

$f(x) = (1 + cx^d) f(x)$ とします．

`deg` で何次まで計算するかを指定できます．<br>
`deg = -1` のときは `deg = n + d` とします．<br>
$\mathrm{deg} > n + d$ のときは多項式が拡張されます．

**制約**

- $-1 \leq deg$

**計算量**

- $O(n + d)$ ( `deg = -1` のとき)

## onediv

```cpp
void f.onediv(int d, mint c, int deg = -1)
```

$f(x) = \frac{f(x)}{1 + cx^d}$ とします．

`deg` で何次まで計算するかを指定できます．<br>
`deg = -1` のときは `deg = n` とします．<br>
$\mathrm{deg} > n + d$ のときは多項式が拡張されます．

**制約**

- $-1 \leq \mathrm{deg}$

**計算量**

- $O(n)$ ( `deg = -1` のとき)

## diff

```cpp
fps f.diff()
```

$f'(x)$ を返します．

**計算量**

- $O(n)$

## integral

```cpp
fps f.integral()
```

$\int f(x) dx$ を返します．<br>
積分定数は $0$ としてあります．

**計算量**

- $O(n)$

## inv

```cpp
fps f.inv(int deg = -1)
```

$f(x) g(x) = 1 \pmod{x^n}$ を満たす $g(x)$ を返します．

`deg` で何次まで計算するかを指定できます．<br>
`deg = -1` のときは `deg = n` とします．

**制約**

- $0 \leq n$
- $f(x)$ の定数項は $0$ でない．

**計算量**

- $O(n \log n)$ ( `deg = -1` のとき)

## log

```cpp
fps f.log(int deg = -1)
```

$\log f(x)$ を返します．<br>
$\log f(x)$ とは

$$f(x) = e^{g(x)} ~ ( := \sum\limits_{k=0}^{n-1} \frac{g^k(x)}{k!} \pmod{x^n})$$

を満たす $g(x) = \sum\limits_{i=0}^{n-1} b_i x^i (b_0 = 0)$ のことです．

`deg` で何次まで計算するかを指定できます．<br>
`deg = -1` のときは `deg = n` とします．

**制約**

- $0 < n$
- $f(x)$ の定数項は $1$ である．

**計算量**

- $O(n \log n)$ ( `deg = -1` のとき)

## exp

```cpp
fps f.exp(int deg = -1)
```

$e^{f(x)} := \sum\limits_{i=0}^{n-1} \frac{f^i(x)}{i!} \pmod{x^n}$ を返します．

`deg` で何次まで計算するかを指定できます．<br>
`deg = -1` のときは `deg = n` とします．

**制約**

- $n = 0$ または $f(x)$ の定数項が $0$ である．

**計算量**

- $O(n \log n)$ ( `deg = -1` のとき)

## pow

```cpp
fps f.pow(ll k, int deg = -1)
```

$f^k(x) \pmod{x^n}$ を返します．

`deg` で何次まで計算するかを指定できます．<br>
`deg = -1` のときは `deg = n` とします．

**制約**

- $0 \leq k$
- $-1 \leq \mathrm{deg}$

**計算量**

- $O(n \log n)$ ( `deg = -1` のとき)

## shift

```cpp
fps f.shift(mint c)
```

$f(x + a)$ を返します．

**計算量**

- $O(n \log n)$
