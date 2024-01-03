---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/math/binomial_coefficient_prime_mod.test.cpp
    title: verify/library_checker/math/binomial_coefficient_prime_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/template/dynamic_modint.hpp\"\
    \nstruct Barrett {\n    explicit Barrett(unsigned int m)\n        : _m(m), im((unsigned\
    \ long long)(-1) / m + 1) {}\n    inline unsigned int umod() const {\n       \
    \ return _m;\n    }\n    inline unsigned int mul(unsigned int a, unsigned int\
    \ b) const {\n        unsigned long long z = a;\n        z *= b;\n        unsigned\
    \ long long x = (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n   \
    \     unsigned int v = (unsigned int)(z - x * _m);\n        if(_m <= v) v += _m;\n\
    \        return v;\n    }\n\n   private:\n    unsigned int _m;\n    unsigned long\
    \ long im;\n};\ntemplate <int id>\nstruct DynamicModint {\n    using mint = DynamicModint;\n\
    \    static int mod() {\n        return (int)bt.umod();\n    }\n    static void\
    \ set_mod(int m) {\n        assert(1 <= m);\n        bt = Barrett(m);\n    }\n\
    \    static mint raw(int v) {\n        mint a;\n        a._v = v;\n        return\
    \ a;\n    }\n    DynamicModint()\n        : _v(0) {}\n    template <class T>\n\
    \    DynamicModint(const T& v) {\n        static_assert(is_integral_v<T>);\n \
    \       if(is_signed_v<T>) {\n            long long x = (long long)(v % (long\
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
    \ DynamicModint<id>::bt(998244353);\nusing modint = DynamicModint<-1>;\n"
  code: "#pragma once\n#include \"./template.hpp\"\nstruct Barrett {\n    explicit\
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
    \ modint = DynamicModint<-1>;"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/template/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/math/binomial_coefficient_prime_mod.test.cpp
documentation_of: src/template/dynamic_modint.hpp
layout: document
title: DynamicModint
---

# DynamicModint

自動で $\mathrm{mod}$ をとる構造体です．

基本的には `StaticModint` と同じなので違いだけを書きます．

`StaticModint` は $\mathrm{mod}$ がコンパイル時定数である必要がありましたが， `DynamicModint` はそうでない場合でも使用できます．

## set_mod

```cpp
void modint::set_mod(int m)
```

$\mathrm{mod}$ を $m$ に設定します．<br>
最初に呼んでください．

**制約**

- $1 \leq m \leq 2 \times 10^9 + 1000$

**計算量**

- $O(1)$

## Tips (複数mod)

複数種類 $\mathrm{mod}$ を使用したい場合，以下のようにできます．

```cpp
using mint0 = DynamicModint<0>;
using mint1 = DynamicModint<1>;
int main(void){
    int p0, p1;
    cin >> p0 >> p1;
    mint0::set_mod(p0);
    mint1::set_mod(p1);
}
```

`modint` は `DynamicModint<-1>` のエイリアスになっています．