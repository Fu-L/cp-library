---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/string/dynamic_rolling_hash.hpp
    title: DynamicRollingHash
  - icon: ':heavy_check_mark:'
    path: src/string/rolling_hash.hpp
    title: RollingHash
  - icon: ':heavy_check_mark:'
    path: src/tree/rooted_tree_hash.hpp
    title: rooted_tree_hash
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/alds1/string_search.test.cpp
    title: verify/aizu_online_judge/alds1/string_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/number_of_substrings.test.cpp
    title: verify/library_checker/string/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/rooted_tree_isomorphism_classification.test.cpp
    title: verify/library_checker/tree/rooted_tree_isomorphism_classification.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/string/dynamic_rolling_hash.test.cpp
    title: verify/unit_test/string/dynamic_rolling_hash.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/template/modint_2_61m1.hpp\"\
    \nstruct Modint_2_61m1 {\n    using mint = Modint_2_61m1;\n    using u64 = uint64_t;\n\
    \    using u128 = __uint128_t;\n    static constexpr u64 mod() {\n        return\
    \ m;\n    }\n    static constexpr mint raw(const u64 v) {\n        mint a;\n \
    \       a._v = v;\n        return a;\n    }\n    constexpr Modint_2_61m1()\n \
    \       : _v(0) {}\n    template <class T>\n    constexpr Modint_2_61m1(const\
    \ T& v) {\n        static_assert(is_integral_v<T>);\n        if constexpr(is_signed_v<T>)\
    \ {\n            int64_t x = int64_t(v % int64_t(m));\n            if(x < 0) x\
    \ += m;\n            _v = u64(x);\n        } else _v = u64(v % m);\n    }\n  \
    \  constexpr u64 val() const {\n        return _v;\n    }\n    constexpr mint&\
    \ operator++() {\n        return *this += 1;\n    }\n    constexpr mint& operator--()\
    \ {\n        return *this -= 1;\n    }\n    constexpr mint operator++(int) {\n\
    \        mint res = *this;\n        ++*this;\n        return res;\n    }\n   \
    \ constexpr mint operator--(int) {\n        mint res = *this;\n        --*this;\n\
    \        return res;\n    }\n    constexpr mint& operator+=(mint rhs) {\n    \
    \    if(_v >= m - rhs._v) _v -= m;\n        _v += rhs._v;\n        return *this;\n\
    \    }\n    constexpr mint& operator-=(mint rhs) {\n        if(_v < rhs._v) _v\
    \ += m;\n        _v -= rhs._v;\n        return *this;\n    }\n    constexpr mint&\
    \ operator*=(mint rhs) {\n        return *this = *this * rhs;\n    }\n    constexpr\
    \ mint& operator/=(mint rhs) {\n        return *this *= rhs.inv();\n    }\n  \
    \  constexpr mint operator+() const {\n        return *this;\n    }\n    constexpr\
    \ mint operator-() const {\n        return mint{} - *this;\n    }\n    constexpr\
    \ mint pow(u64 n) const {\n        if(n == 0) return 1;\n        mint x = *this,\
    \ r = 1;\n        while(1) {\n            if(n & 1) r *= x;\n            n >>=\
    \ 1;\n            if(n == 0) return r;\n            x *= x;\n        }\n    }\n\
    \    constexpr mint inv() const {\n        assert(_v);\n        return pow(m -\
    \ 2);\n    }\n    friend constexpr mint operator+(mint lhs, mint rhs) {\n    \
    \    return lhs += rhs;\n    }\n    friend constexpr mint operator-(mint lhs,\
    \ mint rhs) {\n        return lhs -= rhs;\n    }\n    friend constexpr mint operator*(mint\
    \ lhs, mint rhs) {\n        return raw(modulo(u128(lhs._v) * rhs._v));\n    }\n\
    \    friend constexpr mint operator/(mint lhs, mint rhs) {\n        return lhs\
    \ /= rhs;\n    }\n    friend constexpr bool operator==(mint lhs, mint rhs) {\n\
    \        return lhs._v == rhs._v;\n    }\n    friend constexpr bool operator!=(mint\
    \ lhs, mint rhs) {\n        return lhs._v != rhs._v;\n    }\n    friend istream&\
    \ operator>>(istream& in, mint& x) {\n        long long a;\n        in >> a;\n\
    \        x = a;\n        return in;\n    }\n    friend ostream& operator<<(ostream&\
    \ out, const mint& x) {\n        return out << x.val();\n    }\n\n   private:\n\
    \    static constexpr u64 m = (1ull << 61) - 1;\n    u64 _v = 0;\n    inline static\
    \ constexpr u64 modulo(const u128& x) {\n        const u64 val = (x >> 61) + (x\
    \ & m);\n        return val >= m ? val - m : val;\n    }\n};\n"
  code: "#pragma once\n#include \"./template.hpp\"\nstruct Modint_2_61m1 {\n    using\
    \ mint = Modint_2_61m1;\n    using u64 = uint64_t;\n    using u128 = __uint128_t;\n\
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
    \ & m);\n        return val >= m ? val - m : val;\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/template/modint_2_61m1.hpp
  requiredBy:
  - src/string/dynamic_rolling_hash.hpp
  - src/string/rolling_hash.hpp
  - src/tree/rooted_tree_hash.hpp
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/string/number_of_substrings.test.cpp
  - verify/library_checker/tree/rooted_tree_isomorphism_classification.test.cpp
  - verify/aizu_online_judge/alds1/string_search.test.cpp
  - verify/unit_test/string/dynamic_rolling_hash.test.cpp
documentation_of: src/template/modint_2_61m1.hpp
layout: document
title: Modint_2_61m1
---

# Modint_2_61m1

自動で $\mathrm{mod} ~( = 2^{61} - 1)$ をとる構造体です．

主にハッシュなどに用います．

基本的には `StaticModint` と同じです．<br>
一部，型が違う ( `int` → `long long` など)ので注意してください．