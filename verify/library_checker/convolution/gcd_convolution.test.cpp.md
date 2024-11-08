---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/gcd_convolution.hpp
    title: gcd_convolution
  - icon: ':heavy_check_mark:'
    path: src/math/divisor_multiple_transform.hpp
    title: Divisor/MultipleTransform
  - icon: ':heavy_check_mark:'
    path: src/math/eratosthenes_seive.hpp
    title: EratosthenesSeive
  - icon: ':question:'
    path: src/template/static_modint.hpp
    title: StaticModint
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
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "#line 1 \"verify/library_checker/convolution/gcd_convolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n#line 2\
    \ \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i\
    \ = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
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
    #line 3 \"src/math/eratosthenes_seive.hpp\"\nstruct EratosthenesSeive {\n    vector<int>\
    \ primes, min_factor, moebius, euler;\n    EratosthenesSeive(const int n)\n  \
    \      : primes(), min_factor(n + 1), moebius(n + 1, 1), euler(n + 1) {\n    \
    \    assert(n >= 1);\n        iota(min_factor.begin(), min_factor.end(), 0);\n\
    \        min_factor[0] = min_factor[1] = -1;\n        iota(euler.begin(), euler.end(),\
    \ 0);\n        for(int i = 2; i <= n; ++i) {\n            if(min_factor[i] < i)\
    \ continue;\n            primes.emplace_back(i);\n            moebius[i] = -1;\n\
    \            euler[i] = euler[i] / i * (i - 1);\n            for(int j = i * 2;\
    \ j <= n; j += i) {\n                if(min_factor[j] == j) min_factor[j] = i;\n\
    \                if((j / i) % i == 0) moebius[j] = 0;\n                else moebius[j]\
    \ = -moebius[j];\n                euler[j] = euler[j] / i * (i - 1);\n       \
    \     }\n        }\n    }\n};\n#line 4 \"src/math/divisor_multiple_transform.hpp\"\
    \nstruct DivisorTransform {\n    template <typename T>\n    static void zeta_transform(vector<T>&\
    \ f) {\n        const int N = f.size() - 1;\n        const auto sieve = EratosthenesSeive(N).primes;\n\
    \        for(const auto& p : sieve) {\n            for(int k = 1; k * p <= N;\
    \ ++k) f[k * p] += f[k];\n        }\n    }\n    template <typename T>\n    static\
    \ void moebius_transform(vector<T>& g) {\n        const int N = g.size() - 1;\n\
    \        const auto sieve = EratosthenesSeive(N).primes;\n        for(const auto&\
    \ p : sieve) {\n            for(int k = N / p; k > 0; --k) g[k * p] -= g[k];\n\
    \        }\n    }\n};\nstruct MultipleTransform {\n    template <typename T>\n\
    \    static void zeta_transform(vector<T>& f) {\n        const int N = f.size()\
    \ - 1;\n        const auto sieve = EratosthenesSeive(N).primes;\n        for(const\
    \ auto& p : sieve) {\n            for(int k = N / p; k > 0; --k) f[k] += f[k *\
    \ p];\n        }\n    }\n    template <typename T>\n    static void moebius_transform(vector<T>&\
    \ g) {\n        const int N = g.size() - 1;\n        const auto sieve = EratosthenesSeive(N).primes;\n\
    \        for(const auto& p : sieve) {\n            for(int k = 1; k * p <= N;\
    \ ++k) g[k] -= g[k * p];\n        }\n    }\n};\n#line 4 \"src/convolution/gcd_convolution.hpp\"\
    \ntemplate <typename mint>\nvector<mint> gcd_convolution(const vector<mint>& a,\
    \ const vector<mint>& b) {\n    assert(a.size() == b.size());\n    auto s = a,\
    \ t = b;\n    MultipleTransform::zeta_transform(s);\n    MultipleTransform::zeta_transform(t);\n\
    \    for(int i = 0; i < (int)a.size(); ++i) s[i] *= t[i];\n    MultipleTransform::moebius_transform(s);\n\
    \    return s;\n}\n#line 5 \"verify/library_checker/convolution/gcd_convolution.test.cpp\"\
    \nusing mint = modint998244353;\nint main(void) {\n    int n;\n    cin >> n;\n\
    \    vector<mint> a(n + 1), b(n + 1);\n    rep(i, 1, n + 1) cin >> a[i];\n   \
    \ rep(i, 1, n + 1) cin >> b[i];\n    vector<mint> c = gcd_convolution(a, b);\n\
    \    rep(i, 1, n + 1) cout << c[i] << \" \\n\"[i == n];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/template/static_modint.hpp\"\
    \n#include \"../../../src/convolution/gcd_convolution.hpp\"\nusing mint = modint998244353;\n\
    int main(void) {\n    int n;\n    cin >> n;\n    vector<mint> a(n + 1), b(n +\
    \ 1);\n    rep(i, 1, n + 1) cin >> a[i];\n    rep(i, 1, n + 1) cin >> b[i];\n\
    \    vector<mint> c = gcd_convolution(a, b);\n    rep(i, 1, n + 1) cout << c[i]\
    \ << \" \\n\"[i == n];\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/static_modint.hpp
  - src/convolution/gcd_convolution.hpp
  - src/math/divisor_multiple_transform.hpp
  - src/math/eratosthenes_seive.hpp
  isVerificationFile: true
  path: verify/library_checker/convolution/gcd_convolution.test.cpp
  requiredBy: []
  timestamp: '2024-11-08 15:52:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/convolution/gcd_convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/convolution/gcd_convolution.test.cpp
- /verify/verify/library_checker/convolution/gcd_convolution.test.cpp.html
title: verify/library_checker/convolution/gcd_convolution.test.cpp
---
