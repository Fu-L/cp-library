---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/string/rolling_hash.hpp
    title: RollingHash
  - icon: ':x:'
    path: src/string/suffix_array.hpp
    title: suffix_array
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"verify/library_checker/string/number_of_substrings.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n#line\
    \ 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i\
    \ = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/string/rolling_hash.hpp\"\nstruct RollingHash {\n    RollingHash(const\
    \ string& s, long long BASE = 0) {\n        len = (int)s.size();\n        if(BASE\
    \ <= 0) {\n            mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \            uniform_int_distribution<int> dist(1e8, 1e9);\n            BASE =\
    \ dist(mt);\n        }\n        base = BASE;\n        pow.resize(len + 5);\n \
    \       pow[0] = 1;\n        for(int i = 1; i < len + 5; ++i) {\n            pow[i]\
    \ = calc_mod(mul(pow[i - 1], base));\n        }\n        hash.resize(len + 1);\n\
    \        for(int i = 0; i < len; ++i) {\n            hash[i + 1] = calc_mod(mul(hash[i],\
    \ base) + s[i]);\n        }\n    }\n    long long get(int lower, int upper) const\
    \ {\n        assert(0 <= lower and lower <= upper and upper <= len);\n       \
    \ return calc_mod(hash[upper] + POSITIVIZER - mul(hash[lower], pow[upper - lower]));\n\
    \    }\n    long long get_hash(const string& t) const {\n        long long res\
    \ = 0;\n        for(int i = 0; i < (int)t.size(); ++i) {\n            res = calc_mod(mul(res,\
    \ base) + t[i]);\n        }\n        return res;\n    }\n    int find(const string&\
    \ t, int lower = 0) const {\n        if((int)t.size() > len) return -1;\n    \
    \    const long long ha = get_hash(t);\n        for(int i = lower; i < len - (int)t.size()\
    \ + 1; ++i) {\n            if(ha == get(i, i + (int)t.size())) return i;\n   \
    \     }\n        return -1;\n    }\n    int lcp(const RollingHash& a, const RollingHash&\
    \ b, int al, int bl) const {\n        int ok = 0, ng = min(a.len - al, b.len -\
    \ bl) + 1;\n        while(ok + 1 < ng) {\n            const int med = (ok + ng)\
    \ / 2;\n            if(a.get(al, med + al) == b.get(bl, med + bl)) {\n       \
    \         ok = med;\n            } else {\n                ng = med;\n       \
    \     }\n        }\n        return ok;\n    }\n\n   private:\n    static constexpr\
    \ unsigned long long MASK30 = (1ull << 30) - 1;\n    static constexpr unsigned\
    \ long long MASK31 = (1ull << 31) - 1;\n    static constexpr unsigned long long\
    \ MOD = (1ull << 61) - 1;\n    static constexpr unsigned long long POSITIVIZER\
    \ = MOD * ((1ull << 3) - 1);\n    int len;\n    long long base;\n    vector<unsigned\
    \ long long> pow;\n    vector<unsigned long long> hash;\n    inline unsigned long\
    \ long mul(unsigned long long x, unsigned long long y) const {\n        const\
    \ long long xu = x >> 31;\n        const long long xd = x & MASK31;\n        const\
    \ long long yu = y >> 31;\n        const long long yd = y & MASK31;\n        const\
    \ long long middlebit = xd * yu + xu * yd;\n        return ((xu * yu) << 1) +\
    \ xd * yd + ((middlebit & MASK30) << 31) + (middlebit >> 30);\n    }\n    inline\
    \ long long calc_mod(unsigned long long val) const {\n        val = (val & MOD)\
    \ + (val >> 61);\n        if(val > MOD) val -= MOD;\n        return val;\n   \
    \ }\n};\n#line 3 \"src/string/suffix_array.hpp\"\nvector<int> suffix_array(const\
    \ vector<int>& s) {\n    const int n = (int)s.size();\n    vector<int> sa(n),\
    \ rank(n), tmp(n);\n    for(int i = 0; i < n; ++i) rank[i] = s[i];\n    iota(sa.begin(),\
    \ sa.end(), 0);\n    for(int k = 1; k < n; k *= 2) {\n        auto cmp = [&](int\
    \ x, int y) -> bool {\n            if(rank[x] != rank[y]) return rank[x] < rank[y];\n\
    \            const int rx = x + k < n ? rank[x + k] : -1;\n            const int\
    \ ry = y + k < n ? rank[y + k] : -1;\n            return rx < ry;\n        };\n\
    \        sort(sa.begin(), sa.end(), cmp);\n        tmp[sa[0]] = 0;\n        for(int\
    \ i = 1; i < n; ++i) {\n            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i -\
    \ 1], sa[i]) ? 1 : 0);\n        }\n        swap(tmp, rank);\n    }\n    return\
    \ sa;\n}\nvector<int> suffix_array(const string& s) {\n    const int n = (int)s.size();\n\
    \    vector<int> s2(n);\n    for(int i = 0; i < n; ++i) {\n        s2[i] = s[i];\n\
    \    }\n    return suffix_array(s2);\n}\nvector<int> lcp_array(const vector<int>&\
    \ s, const vector<int>& sa) {\n    const int n = (int)s.size();\n    assert(n\
    \ >= 1);\n    vector<int> rank(n);\n    for(int i = 0; i < n; ++i) {\n       \
    \ rank[sa[i]] = i;\n    }\n    vector<int> lcp(n - 1);\n    int h = 0;\n    for(int\
    \ i = 0; i < n; ++i) {\n        if(h > 0) --h;\n        if(rank[i] == 0) continue;\n\
    \        const int j = sa[rank[i] - 1];\n        for(; j + h < n and i + h < n;\
    \ ++h) {\n            if(s[j + h] != s[i + h]) break;\n        }\n        lcp[rank[i]\
    \ - 1] = h;\n    }\n    return lcp;\n}\nvector<int> lcp_array(const string& s,\
    \ const vector<int>& sa) {\n    const int n = (int)s.size();\n    vector<int>\
    \ s2(n);\n    for(int i = 0; i < n; ++i) {\n        s2[i] = s[i];\n    }\n   \
    \ return lcp_array(s2, sa);\n}\n#line 5 \"verify/library_checker/string/number_of_substrings.test.cpp\"\
    \nint main(void) {\n    string s;\n    cin >> s;\n    ll n = s.size();\n    RollingHash\
    \ rh(s);\n    ll ans = n * (n + 1) / 2;\n    vector<int> sa = suffix_array(s);\n\
    \    rep(i, 0, n - 1) {\n        ans -= rh.lcp(rh, rh, sa[i], sa[i + 1]);\n  \
    \  }\n    cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    #include \"../../../src/template/template.hpp\"\n#include \"../../../src/string/rolling_hash.hpp\"\
    \n#include \"../../../src/string/suffix_array.hpp\"\nint main(void) {\n    string\
    \ s;\n    cin >> s;\n    ll n = s.size();\n    RollingHash rh(s);\n    ll ans\
    \ = n * (n + 1) / 2;\n    vector<int> sa = suffix_array(s);\n    rep(i, 0, n -\
    \ 1) {\n        ans -= rh.lcp(rh, rh, sa[i], sa[i + 1]);\n    }\n    cout << ans\
    \ << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/string/rolling_hash.hpp
  - src/string/suffix_array.hpp
  isVerificationFile: true
  path: verify/library_checker/string/number_of_substrings.test.cpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/string/number_of_substrings.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/number_of_substrings.test.cpp
- /verify/verify/library_checker/string/number_of_substrings.test.cpp.html
title: verify/library_checker/string/number_of_substrings.test.cpp
---
