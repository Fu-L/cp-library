---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/rolling_hash.hpp
    title: RollingHash
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
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/string/rolling_hash.hpp\"\nstruct RollingHash {\n    using ull =\
    \ unsigned long long;\n    RollingHash(const string &s, ll BASE = 0) {\n     \
    \   len = (int)s.size();\n        if(BASE <= 0) {\n            mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \            uniform_int_distribution<int> dist(1e8, 1e9);\n            BASE =\
    \ dist(mt);\n        }\n        base = BASE;\n        pow.resize(len + 5);\n \
    \       pow[0] = 1;\n        for(int i = 1; i < len + 5; ++i) {\n            pow[i]\
    \ = calc_mod(mul(pow[i - 1], base));\n        }\n        hash.resize(len + 1);\n\
    \        for(int i = 0; i < len; ++i) {\n            hash[i + 1] = calc_mod(mul(hash[i],\
    \ base) + s[i]);\n        }\n    }\n    ll get(int lower, int upper) const {\n\
    \        assert(0 <= lower and lower <= upper and upper <= len);\n        return\
    \ calc_mod(hash[upper] + POSITIVIZER - mul(hash[lower], pow[upper - lower]));\n\
    \    }\n    ll get_hash(const string &t) const {\n        ll res = 0;\n      \
    \  for(int i = 0; i < (int)t.size(); ++i) {\n            res = calc_mod(mul(res,\
    \ base) + t[i]);\n        }\n        return res;\n    }\n    int find(const string\
    \ &t, int lower = 0) const {\n        if((int)t.size() > len) return -1;\n   \
    \     ll ha = get_hash(t);\n        for(int i = lower; i < len - (int)t.size()\
    \ + 1; ++i) {\n            if(ha == get(i, i + (int)t.size())) return i;\n   \
    \     }\n        return -1;\n    }\n    int lcp(const RollingHash &a, const RollingHash\
    \ &b, int al, int bl) const {\n        int ok = 0, ng = min(a.len - al, b.len\
    \ - bl) + 1;\n        while(ok + 1 < ng) {\n            int med = (ok + ng) /\
    \ 2;\n            if(a.get(al, med + al) == b.get(bl, med + bl)) {\n         \
    \       ok = med;\n            } else {\n                ng = med;\n         \
    \   }\n        }\n        return ok;\n    }\n\n   private:\n    static constexpr\
    \ ull MASK30 = (1ull << 30) - 1;\n    static constexpr ull MASK31 = (1ull << 31)\
    \ - 1;\n    static constexpr ull MOD = (1ull << 61) - 1;\n    static constexpr\
    \ ull POSITIVIZER = MOD * ((1ull << 3) - 1);\n    int len;\n    ll base;\n   \
    \ vector<ull> pow;\n    vector<ull> hash;\n    inline ull mul(ull x, ull y) const\
    \ {\n        ll xu = x >> 31;\n        ll xd = x & MASK31;\n        ll yu = y\
    \ >> 31;\n        ll yd = y & MASK31;\n        ll middlebit = xd * yu + xu * yd;\n\
    \        return ((xu * yu) << 1) + xd * yd + ((middlebit & MASK30) << 31) + (middlebit\
    \ >> 30);\n    }\n    inline ll calc_mod(ull val) const {\n        val = (val\
    \ & MOD) + (val >> 61);\n        if(val > MOD) val -= MOD;\n        return val;\n\
    \    }\n};\n#line 4 \"verify/aizu_online_judge/alds1/string_search.test.cpp\"\n\
    int main(void) {\n    string t, p;\n    cin >> t >> p;\n    int n = t.size(),\
    \ m = p.size();\n    RollingHash rh(t);\n    ll ha = rh.get_hash(p);\n    rep(i,\
    \ 0, n - m + 1) {\n        if(rh.get(i, i + m) == ha) {\n            cout << i\
    \ << '\\n';\n        }\n    }\n}\n"
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
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/alds1/string_search.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/alds1/string_search.test.cpp
- /verify/verify/aizu_online_judge/alds1/string_search.test.cpp.html
title: verify/aizu_online_judge/alds1/string_search.test.cpp
---
