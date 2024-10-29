---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/rolling_hash.hpp
    title: RollingHash
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
  bundledCode: "#line 1 \"verify/aizu_online_judge/alds1/string_search.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/string/rolling_hash.hpp\"\nstruct RollingHash {\n    RollingHash(const\
    \ string& s, unsigned long long BASE = 0) {\n        if(BASE == 0) {\n       \
    \     mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n  \
    \          uniform_int_distribution<unsigned long long> dist(1ull << 10, 1ull\
    \ << 60);\n            BASE = dist(mt);\n        }\n        base = BASE;\n   \
    \     len = (int)s.size();\n        pow.resize(len + 1);\n        pow[0] = 1;\n\
    \        for(int i = 1; i < len + 1; ++i) {\n            pow[i] = calc_mod(mul(pow[i\
    \ - 1], base));\n        }\n        hash.resize(len + 1);\n        for(int i =\
    \ 0; i < len; ++i) {\n            hash[i + 1] = calc_mod(mul(hash[i], base) +\
    \ s[i]);\n        }\n    }\n    long long get(const int lower, const int upper)\
    \ const {\n        assert(0 <= lower and lower <= upper and upper <= len);\n \
    \       return calc_mod(hash[upper] + POSITIVIZER - mul(hash[lower], pow[upper\
    \ - lower]));\n    }\n    long long get_hash(const string& t) const {\n      \
    \  unsigned long long res = 0;\n        for(int i = 0; i < (int)t.size(); ++i)\
    \ {\n            res = calc_mod(mul(res, base) + t[i]);\n        }\n        return\
    \ res;\n    }\n    int find(const string& t, const int lower = 0) const {\n  \
    \      if((int)t.size() > len) return -1;\n        const long long ha = get_hash(t);\n\
    \        for(int i = lower; i < len - (int)t.size() + 1; ++i) {\n            if(ha\
    \ == get(i, i + (int)t.size())) return i;\n        }\n        return -1;\n   \
    \ }\n    int lcp(const RollingHash& a, const RollingHash& b, const int al, const\
    \ int bl) const {\n        int ok = 0, ng = min(a.len - al, b.len - bl) + 1;\n\
    \        while(ok + 1 < ng) {\n            const int med = (ok + ng) / 2;\n  \
    \          if(a.get(al, med + al) == b.get(bl, med + bl)) {\n                ok\
    \ = med;\n            } else {\n                ng = med;\n            }\n   \
    \     }\n        return ok;\n    }\n\n   private:\n    static constexpr unsigned\
    \ long long MASK30 = (1ull << 30) - 1;\n    static constexpr unsigned long long\
    \ MASK31 = (1ull << 31) - 1;\n    static constexpr unsigned long long MOD = (1ull\
    \ << 61) - 1;\n    static constexpr unsigned long long POSITIVIZER = MOD * ((1ull\
    \ << 3) - 1);\n    int len;\n    unsigned long long base;\n    vector<unsigned\
    \ long long> pow;\n    vector<unsigned long long> hash;\n    inline unsigned long\
    \ long mul(const unsigned long long x, const unsigned long long y) const {\n \
    \       const unsigned long long xu = x >> 31;\n        const unsigned long long\
    \ xd = x & MASK31;\n        const unsigned long long yu = y >> 31;\n        const\
    \ unsigned long long yd = y & MASK31;\n        const unsigned long long middlebit\
    \ = xd * yu + xu * yd;\n        return ((xu * yu) << 1) + xd * yd + ((middlebit\
    \ & MASK30) << 31) + (middlebit >> 30);\n    }\n    inline unsigned long long\
    \ calc_mod(unsigned long long val) const {\n        val = (val & MOD) + (val >>\
    \ 61);\n        if(val > MOD) val -= MOD;\n        return val;\n    }\n};\n#line\
    \ 4 \"verify/aizu_online_judge/alds1/string_search.test.cpp\"\nint main(void)\
    \ {\n    string t, p;\n    cin >> t >> p;\n    int n = t.size(), m = p.size();\n\
    \    RollingHash rh(t);\n    ll ha = rh.get_hash(p);\n    rep(i, 0, n - m + 1)\
    \ {\n        if(rh.get(i, i + m) == ha) {\n            cout << i << '\\n';\n \
    \       }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/string/rolling_hash.hpp\"\
    \nint main(void) {\n    string t, p;\n    cin >> t >> p;\n    int n = t.size(),\
    \ m = p.size();\n    RollingHash rh(t);\n    ll ha = rh.get_hash(p);\n    rep(i,\
    \ 0, n - m + 1) {\n        if(rh.get(i, i + m) == ha) {\n            cout << i\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/string/rolling_hash.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/alds1/string_search.test.cpp
  requiredBy: []
  timestamp: '2024-10-30 00:12:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/alds1/string_search.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/alds1/string_search.test.cpp
- /verify/verify/aizu_online_judge/alds1/string_search.test.cpp.html
title: verify/aizu_online_judge/alds1/string_search.test.cpp
---
