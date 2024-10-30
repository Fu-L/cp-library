---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/rolling_hash.hpp
    title: RollingHash
  - icon: ':heavy_check_mark:'
    path: src/string/suffix_array.hpp
    title: suffix_array
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
    \ 3 \"src/string/suffix_array.hpp\"\ntemplate <typename T>\nvector<int> suffix_array(const\
    \ vector<T>& s, const bool compress = true) {\n    auto sa_is = [&](auto& sa_is,\
    \ const vector<int>& s, const int upper) -> vector<int> {\n        const int n\
    \ = (int)s.size();\n        if(n == 0) return {};\n        if(n == 1) return {0};\n\
    \        if(n == 2) {\n            if(s[0] < s[1]) return {0, 1};\n          \
    \  else return {1, 0};\n        }\n        vector<int> sa(n);\n        vector<bool>\
    \ ls(n);\n        for(int i = n - 2; i >= 0; --i) {\n            ls[i] = (s[i]\
    \ == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);\n        }\n        vector<int>\
    \ sum_l(upper + 1), sum_s(upper + 1);\n        for(int i = 0; i < n; ++i) {\n\
    \            if(!ls[i]) {\n                ++sum_s[s[i]];\n            } else\
    \ {\n                ++sum_l[s[i] + 1];\n            }\n        }\n        for(int\
    \ i = 0; i <= upper; ++i) {\n            sum_s[i] += sum_l[i];\n            if(i\
    \ < upper) sum_l[i + 1] += sum_s[i];\n        }\n        auto induce = [&](const\
    \ vector<int>& lms) {\n            fill(sa.begin(), sa.end(), -1);\n         \
    \   vector<int> buf(upper + 1);\n            copy(sum_s.begin(), sum_s.end(),\
    \ buf.begin());\n            for(const int d : lms) {\n                if(d ==\
    \ n) continue;\n                sa[buf[s[d]]++] = d;\n            }\n        \
    \    copy(sum_l.begin(), sum_l.end(), buf.begin());\n            sa[buf[s[n -\
    \ 1]]++] = n - 1;\n            for(int i = 0; i < n; ++i) {\n                const\
    \ int v = sa[i];\n                if(v >= 1 and !ls[v - 1]) {\n              \
    \      sa[buf[s[v - 1]]++] = v - 1;\n                }\n            }\n      \
    \      copy(sum_l.begin(), sum_l.end(), buf.begin());\n            for(int i =\
    \ n - 1; i >= 0; --i) {\n                const int v = sa[i];\n              \
    \  if(v >= 1 and ls[v - 1]) {\n                    sa[--buf[s[v - 1] + 1]] = v\
    \ - 1;\n                }\n            }\n        };\n        vector<int> lms_map(n\
    \ + 1, -1);\n        int m = 0;\n        for(int i = 1; i < n; ++i) {\n      \
    \      if(!ls[i - 1] and ls[i]) {\n                lms_map[i] = m++;\n       \
    \     }\n        }\n        vector<int> lms;\n        lms.reserve(m);\n      \
    \  for(int i = 1; i < n; ++i) {\n            if(!ls[i - 1] and ls[i]) {\n    \
    \            lms.push_back(i);\n            }\n        }\n        induce(lms);\n\
    \        if(m) {\n            vector<int> sorted_lms;\n            sorted_lms.reserve(m);\n\
    \            for(const int v : sa) {\n                if(lms_map[v] != -1) sorted_lms.push_back(v);\n\
    \            }\n            vector<int> rec_s(m);\n            int rec_upper =\
    \ 0;\n            rec_s[lms_map[sorted_lms[0]]] = 0;\n            for(int i =\
    \ 1; i < m; ++i) {\n                int l = sorted_lms[i - 1], r = sorted_lms[i];\n\
    \                const int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1]\
    \ : n;\n                const int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r]\
    \ + 1] : n;\n                bool same = true;\n                if(end_l - l !=\
    \ end_r - r) {\n                    same = false;\n                } else {\n\
    \                    while(l < end_l) {\n                        if(s[l] != s[r])\
    \ {\n                            break;\n                        }\n         \
    \               ++l;\n                        ++r;\n                    }\n  \
    \                  if(l == n or s[l] != s[r]) same = false;\n                }\n\
    \                if(!same) ++rec_upper;\n                rec_s[lms_map[sorted_lms[i]]]\
    \ = rec_upper;\n            }\n            const auto rec_sa = sa_is(sa_is, rec_s,\
    \ rec_upper);\n            for(int i = 0; i < m; ++i) {\n                sorted_lms[i]\
    \ = lms[rec_sa[i]];\n            }\n            induce(sorted_lms);\n        }\n\
    \        return sa;\n    };\n    if(compress) {\n        int n = (int)s.size();\n\
    \        vector<int> idx(n);\n        iota(idx.begin(), idx.end(), 0);\n     \
    \   sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });\n\
    \        vector<int> s2(n);\n        int upper = 0;\n        for(int i = 0; i\
    \ < n; ++i) {\n            if(i and s[idx[i - 1]] != s[idx[i]]) ++upper;\n   \
    \         s2[idx[i]] = upper;\n        }\n        return sa_is(sa_is, s2, upper);\n\
    \    }\n    return sa_is(sa_is, s, *max_element(s.begin(), s.end()));\n}\nvector<int>\
    \ suffix_array(const string& s) {\n    int n = (int)s.size();\n    vector<int>\
    \ s2(n);\n    for(int i = 0; i < n; ++i) {\n        s2[i] = s[i];\n    }\n   \
    \ return suffix_array(s2, false);\n}\ntemplate <typename T>\nvector<int> lcp_array(const\
    \ vector<T>& s, const vector<int>& sa) {\n    int n = (int)s.size();\n    assert(n\
    \ >= 1);\n    vector<int> rnk(n);\n    for(int i = 0; i < n; ++i) {\n        rnk[sa[i]]\
    \ = i;\n    }\n    vector<int> lcp(n - 1);\n    int h = 0;\n    for(int i = 0;\
    \ i < n; ++i) {\n        if(h > 0) --h;\n        if(rnk[i] == 0) continue;\n \
    \       int j = sa[rnk[i] - 1];\n        for(; j + h < n and i + h < n; ++h) {\n\
    \            if(s[j + h] != s[i + h]) break;\n        }\n        lcp[rnk[i] -\
    \ 1] = h;\n    }\n    return lcp;\n}\nvector<int> lcp_array(const string& s, const\
    \ vector<int>& sa) {\n    int n = (int)s.size();\n    vector<int> s2(n);\n   \
    \ for(int i = 0; i < n; ++i) {\n        s2[i] = s[i];\n    }\n    return lcp_array(s2,\
    \ sa);\n}\n#line 5 \"verify/library_checker/string/number_of_substrings.test.cpp\"\
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
  timestamp: '2024-10-30 15:05:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/string/number_of_substrings.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/number_of_substrings.test.cpp
- /verify/verify/library_checker/string/number_of_substrings.test.cpp.html
title: verify/library_checker/string/number_of_substrings.test.cpp
---
