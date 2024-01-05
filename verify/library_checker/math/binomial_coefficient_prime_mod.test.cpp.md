---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/binomial.hpp
    title: Binomial
  - icon: ':heavy_check_mark:'
    path: src/template/dynamic_modint.hpp
    title: DynamicModint
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
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"verify/library_checker/math/binomial_coefficient_prime_mod.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/template/dynamic_modint.hpp\"\nstruct Barrett {\n    explicit Barrett(unsigned\
    \ int m)\n        : _m(m), im((unsigned long long)(-1) / m + 1) {}\n    inline\
    \ unsigned int umod() const {\n        return _m;\n    }\n    inline unsigned\
    \ int mul(unsigned int a, unsigned int b) const {\n        unsigned long long\
    \ z = a;\n        z *= b;\n        unsigned long long x = (unsigned long long)(((unsigned\
    \ __int128)(z)*im) >> 64);\n        unsigned int v = (unsigned int)(z - x * _m);\n\
    \        if(_m <= v) v += _m;\n        return v;\n    }\n\n   private:\n    unsigned\
    \ int _m;\n    unsigned long long im;\n};\ntemplate <int id>\nstruct DynamicModint\
    \ {\n    using mint = DynamicModint;\n    static int mod() {\n        return (int)bt.umod();\n\
    \    }\n    static void set_mod(int m) {\n        assert(1 <= m);\n        bt\
    \ = Barrett(m);\n    }\n    static mint raw(int v) {\n        mint a;\n      \
    \  a._v = v;\n        return a;\n    }\n    DynamicModint()\n        : _v(0) {}\n\
    \    template <class T>\n    DynamicModint(const T& v) {\n        static_assert(is_integral_v<T>);\n\
    \        if(is_signed_v<T>) {\n            long long x = (long long)(v % (long\
    \ long)(umod()));\n            if(x < 0) x += umod();\n            _v = (unsigned\
    \ int)(x);\n        } else _v = (unsigned int)(v % umod());\n    }\n    unsigned\
    \ int val() const {\n        return _v;\n    }\n    mint& operator++() {\n   \
    \     ++_v;\n        if(_v == umod()) _v = 0;\n        return *this;\n    }\n\
    \    mint& operator--() {\n        if(_v == 0) _v = umod();\n        --_v;\n \
    \       return *this;\n    }\n    mint operator++(int) {\n        mint res = *this;\n\
    \        ++*this;\n        return res;\n    }\n    mint operator--(int) {\n  \
    \      mint res = *this;\n        --*this;\n        return res;\n    }\n    mint&\
    \ operator+=(const mint& rhs) {\n        _v += rhs._v;\n        if(_v >= umod())\
    \ _v -= umod();\n        return *this;\n    }\n    mint& operator-=(const mint&\
    \ rhs) {\n        _v += mod() - rhs._v;\n        if(_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator*=(const mint& rhs) {\n     \
    \   _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n    mint& operator/=(const\
    \ mint& rhs) {\n        return *this *= rhs.inv();\n    }\n    mint operator+()\
    \ const {\n        return *this;\n    }\n    mint operator-() const {\n      \
    \  return mint() - *this;\n    }\n    mint pow(long long n) const {\n        assert(0\
    \ <= n);\n        if(n == 0) return 1;\n        mint x = *this, r = 1;\n     \
    \   while(1) {\n            if(n & 1) r *= x;\n            n >>= 1;\n        \
    \    if(n == 0) return r;\n            x *= x;\n        }\n    }\n    mint inv()\
    \ const {\n        auto eg = inv_gcd(_v, mod());\n        assert(eg.first == 1);\n\
    \        return eg.second;\n    }\n    friend mint operator+(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend mint\
    \ operator-(const mint& lhs, const mint& rhs) {\n        return mint(lhs) -= rhs;\n\
    \    }\n    friend mint operator*(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) *= rhs;\n    }\n    friend mint operator/(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) /= rhs;\n    }\n    friend bool\
    \ operator==(const mint& lhs, const mint& rhs) {\n        return lhs._v == rhs._v;\n\
    \    }\n    friend bool operator!=(const mint& lhs, const mint& rhs) {\n     \
    \   return lhs._v != rhs._v;\n    }\n    friend istream& operator>>(istream& in,\
    \ mint& x) {\n        long long a;\n        in >> a;\n        x = a;\n       \
    \ return in;\n    }\n    friend ostream& operator<<(ostream& out, const mint&\
    \ x) {\n        return out << x.val();\n    }\n\n   private:\n    unsigned int\
    \ _v = 0;\n    static Barrett bt;\n    inline static unsigned int umod() {\n \
    \       return bt.umod();\n    }\n    inline static pair<long long, long long>\
    \ inv_gcd(long long a, long long b) {\n        if(a == 0) return {b, 0};\n   \
    \     long long s = b, t = a, m0 = 0, m1 = 1;\n        while(t) {\n          \
    \  const long long u = s / t;\n            s -= t * u;\n            m0 -= m1 *\
    \ u;\n            swap(s, t);\n            swap(m0, m1);\n        }\n        if(m0\
    \ < 0) m0 += b / s;\n        return {s, m0};\n    }\n};\ntemplate <int id>\nBarrett\
    \ DynamicModint<id>::bt(998244353);\nusing modint = DynamicModint<-1>;\n#line\
    \ 3 \"src/math/binomial.hpp\"\ntemplate <typename mint>\nstruct Binomial {\n \
    \   Binomial(int n)\n        : fac(n + 1), ifac(n + 1) {\n        fac[0] = 1;\n\
    \        for(int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i;\n        ifac[n]\
    \ = fac[n].inv();\n        for(int i = n; i >= 1; --i) ifac[i - 1] = ifac[i] *\
    \ i;\n    }\n    mint fact(int n) {\n        if(n < 0) return 0;\n        return\
    \ fac[n];\n    }\n    mint perm(int n, int r) {\n        if(n < 0 or n < r or\
    \ r < 0) return 0;\n        return fac[n] * ifac[n - r];\n    }\n    mint comb(int\
    \ n, int r) {\n        if(n < 0 or n < r or r < 0) return 0;\n        return fac[n]\
    \ * ifac[n - r] * ifac[r];\n    }\n    mint homo(int n, int r) {\n        if(n\
    \ < 0 or r < 0) return 0;\n        if(r == 0) return 1;\n        return comb(n\
    \ + r - 1, r);\n    }\n    mint operator()(int n, int r) {\n        return comb(n,\
    \ r);\n    }\n\n   private:\n    vector<mint> fac, ifac;\n};\n#line 5 \"verify/library_checker/math/binomial_coefficient_prime_mod.test.cpp\"\
    \nusing mint = modint;\nint main(void) {\n    int t, m;\n    cin >> t >> m;\n\
    \    mint::set_mod(m);\n    Binomial<mint> binom(min(m - 1, 10000005));\n    while(t--)\
    \ {\n        int n, k;\n        cin >> n >> k;\n        cout << binom(n, k) <<\
    \ '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/template/dynamic_modint.hpp\"\
    \n#include \"../../../src/math/binomial.hpp\"\nusing mint = modint;\nint main(void)\
    \ {\n    int t, m;\n    cin >> t >> m;\n    mint::set_mod(m);\n    Binomial<mint>\
    \ binom(min(m - 1, 10000005));\n    while(t--) {\n        int n, k;\n        cin\
    \ >> n >> k;\n        cout << binom(n, k) << '\\n';\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/dynamic_modint.hpp
  - src/math/binomial.hpp
  isVerificationFile: true
  path: verify/library_checker/math/binomial_coefficient_prime_mod.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/math/binomial_coefficient_prime_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/math/binomial_coefficient_prime_mod.test.cpp
- /verify/verify/library_checker/math/binomial_coefficient_prime_mod.test.cpp.html
title: verify/library_checker/math/binomial_coefficient_prime_mod.test.cpp
---
