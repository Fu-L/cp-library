---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/string/rolling_hash.hpp
    title: RollingHash
  - icon: ':question:'
    path: src/template/modint_2_61m1.hpp
    title: Modint_2_61m1
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
  bundledCode: "#line 1 \"verify/aizu_online_judge/alds1/string_search.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
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
    \ & m);\n        return val >= m ? val - m : val;\n    }\n};\n#line 4 \"src/string/rolling_hash.hpp\"\
    \nstruct RollingHash {\n    using mint = Modint_2_61m1;\n    RollingHash(const\
    \ string& s, unsigned long long BASE = 0)\n        : len((int)s.size()), pow(len\
    \ + 1), hash(len + 1) {\n        if(BASE == 0) {\n            mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \            uniform_int_distribution<unsigned long long> dist(1ull << 10, 1ull\
    \ << 60);\n            BASE = dist(mt);\n        }\n        base = BASE;\n   \
    \     pow[0] = 1;\n        for(int i = 0; i < len; ++i) {\n            pow[i +\
    \ 1] = pow[i] * base;\n        }\n        for(int i = 0; i < len; ++i) {\n   \
    \         hash[i + 1] = hash[i] * base + s[i];\n        }\n    }\n    unsigned\
    \ long long get(const int lower, const int upper) const {\n        assert(0 <=\
    \ lower and lower <= upper and upper <= len);\n        return (hash[upper] - hash[lower]\
    \ * pow[upper - lower]).val();\n    }\n    unsigned long long get_hash(const string&\
    \ t) const {\n        mint res = 0;\n        for(int i = 0; i < (int)t.size();\
    \ ++i) {\n            res = res * base + t[i];\n        }\n        return res.val();\n\
    \    }\n    int find(const string& t, const int lower = 0) const {\n        if((int)t.size()\
    \ > len) return -1;\n        const unsigned long long ha = get_hash(t);\n    \
    \    for(int i = lower; i < len - (int)t.size() + 1; ++i) {\n            if(ha\
    \ == get(i, i + (int)t.size())) return i;\n        }\n        return -1;\n   \
    \ }\n    int lcp(const RollingHash& a, const RollingHash& b, const int al, const\
    \ int bl) const {\n        int ok = 0, ng = min(a.len - al, b.len - bl) + 1;\n\
    \        while(ok + 1 < ng) {\n            const int med = (ok + ng) / 2;\n  \
    \          if(a.get(al, med + al) == b.get(bl, med + bl)) {\n                ok\
    \ = med;\n            } else {\n                ng = med;\n            }\n   \
    \     }\n        return ok;\n    }\n\n   private:\n    int len;\n    mint base;\n\
    \    vector<mint> pow;\n    vector<mint> hash;\n};\n#line 4 \"verify/aizu_online_judge/alds1/string_search.test.cpp\"\
    \nint main(void) {\n    string t, p;\n    cin >> t >> p;\n    int n = t.size(),\
    \ m = p.size();\n    RollingHash rh(t);\n    unsigned long long ha = rh.get_hash(p);\n\
    \    rep(i, 0, n - m + 1) {\n        if(rh.get(i, i + m) == ha) {\n          \
    \  cout << i << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/string/rolling_hash.hpp\"\
    \nint main(void) {\n    string t, p;\n    cin >> t >> p;\n    int n = t.size(),\
    \ m = p.size();\n    RollingHash rh(t);\n    unsigned long long ha = rh.get_hash(p);\n\
    \    rep(i, 0, n - m + 1) {\n        if(rh.get(i, i + m) == ha) {\n          \
    \  cout << i << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/string/rolling_hash.hpp
  - src/template/modint_2_61m1.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/alds1/string_search.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/alds1/string_search.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/alds1/string_search.test.cpp
- /verify/verify/aizu_online_judge/alds1/string_search.test.cpp.html
title: verify/aizu_online_judge/alds1/string_search.test.cpp
---
