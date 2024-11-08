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
    path: src/template/modint_2_61m1.hpp
    title: Modint_2_61m1
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
    using ll = long long;\nusing P = pair<long long, long long>;\n#define rep(i, a,\
    \ b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long long\
    \ i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO {\n\
    \    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n    \
    \    cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/template/modint_2_61m1.hpp\"\
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
    \    vector<mint> pow;\n    vector<mint> hash;\n};\n#line 3 \"src/string/suffix_array.hpp\"\
    \ntemplate <typename T>\nvector<int> suffix_array(const vector<T>& s, const bool\
    \ compress = true) {\n    auto sa_is = [&](auto& sa_is, const vector<int>& s,\
    \ const int upper) -> vector<int> {\n        const int n = (int)s.size();\n  \
    \      if(n == 0) return {};\n        if(n == 1) return {0};\n        if(n ==\
    \ 2) {\n            if(s[0] < s[1]) return {0, 1};\n            else return {1,\
    \ 0};\n        }\n        vector<int> sa(n);\n        vector<bool> ls(n);\n  \
    \      for(int i = n - 2; i >= 0; --i) {\n            ls[i] = (s[i] == s[i + 1])\
    \ ? ls[i + 1] : (s[i] < s[i + 1]);\n        }\n        vector<int> sum_l(upper\
    \ + 1), sum_s(upper + 1);\n        for(int i = 0; i < n; ++i) {\n            if(!ls[i])\
    \ {\n                ++sum_s[s[i]];\n            } else {\n                ++sum_l[s[i]\
    \ + 1];\n            }\n        }\n        for(int i = 0; i <= upper; ++i) {\n\
    \            sum_s[i] += sum_l[i];\n            if(i < upper) sum_l[i + 1] +=\
    \ sum_s[i];\n        }\n        auto induce = [&](const vector<int>& lms) {\n\
    \            fill(sa.begin(), sa.end(), -1);\n            vector<int> buf(upper\
    \ + 1);\n            copy(sum_s.begin(), sum_s.end(), buf.begin());\n        \
    \    for(const int d : lms) {\n                if(d == n) continue;\n        \
    \        sa[buf[s[d]]++] = d;\n            }\n            copy(sum_l.begin(),\
    \ sum_l.end(), buf.begin());\n            sa[buf[s[n - 1]]++] = n - 1;\n     \
    \       for(int i = 0; i < n; ++i) {\n                const int v = sa[i];\n \
    \               if(v >= 1 and !ls[v - 1]) {\n                    sa[buf[s[v -\
    \ 1]]++] = v - 1;\n                }\n            }\n            copy(sum_l.begin(),\
    \ sum_l.end(), buf.begin());\n            for(int i = n - 1; i >= 0; --i) {\n\
    \                const int v = sa[i];\n                if(v >= 1 and ls[v - 1])\
    \ {\n                    sa[--buf[s[v - 1] + 1]] = v - 1;\n                }\n\
    \            }\n        };\n        vector<int> lms_map(n + 1, -1);\n        int\
    \ m = 0;\n        for(int i = 1; i < n; ++i) {\n            if(!ls[i - 1] and\
    \ ls[i]) {\n                lms_map[i] = m++;\n            }\n        }\n    \
    \    vector<int> lms;\n        lms.reserve(m);\n        for(int i = 1; i < n;\
    \ ++i) {\n            if(!ls[i - 1] and ls[i]) {\n                lms.push_back(i);\n\
    \            }\n        }\n        induce(lms);\n        if(m) {\n           \
    \ vector<int> sorted_lms;\n            sorted_lms.reserve(m);\n            for(const\
    \ int v : sa) {\n                if(lms_map[v] != -1) sorted_lms.push_back(v);\n\
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
    \        return sa;\n    };\n    if(compress) {\n        const int n = (int)s.size();\n\
    \        vector<int> idx(n);\n        iota(idx.begin(), idx.end(), 0);\n     \
    \   sort(idx.begin(), idx.end(), [&](const int l, const int r) { return s[l] <\
    \ s[r]; });\n        vector<int> s2(n);\n        int upper = 0;\n        for(int\
    \ i = 0; i < n; ++i) {\n            if(i and s[idx[i - 1]] != s[idx[i]]) ++upper;\n\
    \            s2[idx[i]] = upper;\n        }\n        return sa_is(sa_is, s2, upper);\n\
    \    }\n    return sa_is(sa_is, s, *max_element(s.begin(), s.end()));\n}\nvector<int>\
    \ suffix_array(const string& s) {\n    const int n = (int)s.size();\n    vector<int>\
    \ s2(n);\n    for(int i = 0; i < n; ++i) {\n        s2[i] = s[i];\n    }\n   \
    \ return suffix_array(s2, false);\n}\ntemplate <typename T>\nvector<int> lcp_array(const\
    \ vector<T>& s, const vector<int>& sa) {\n    const int n = (int)s.size();\n \
    \   assert(n >= 1);\n    vector<int> rnk(n);\n    for(int i = 0; i < n; ++i) {\n\
    \        rnk[sa[i]] = i;\n    }\n    vector<int> lcp(n - 1);\n    int h = 0;\n\
    \    for(int i = 0; i < n; ++i) {\n        if(h > 0) --h;\n        if(rnk[i] ==\
    \ 0) continue;\n        const int j = sa[rnk[i] - 1];\n        for(; j + h < n\
    \ and i + h < n; ++h) {\n            if(s[j + h] != s[i + h]) break;\n       \
    \ }\n        lcp[rnk[i] - 1] = h;\n    }\n    return lcp;\n}\nvector<int> lcp_array(const\
    \ string& s, const vector<int>& sa) {\n    const int n = (int)s.size();\n    vector<int>\
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
  - src/template/modint_2_61m1.hpp
  - src/string/suffix_array.hpp
  isVerificationFile: true
  path: verify/library_checker/string/number_of_substrings.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 02:46:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/string/number_of_substrings.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/number_of_substrings.test.cpp
- /verify/verify/library_checker/string/number_of_substrings.test.cpp.html
title: verify/library_checker/string/number_of_substrings.test.cpp
---
