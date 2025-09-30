---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/number_of_substrings.test.cpp
    title: verify/library_checker/string/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/number_of_substrings_2.test.cpp
    title: verify/library_checker/string/number_of_substrings_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/suffix_array.test.cpp
    title: verify/library_checker/string/suffix_array.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/string/suffix_array.hpp\"\
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
    \ return lcp_array(s2, sa);\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    vector<int> suffix_array(const vector<T>& s, const bool compress = true) {\n \
    \   auto sa_is = [&](auto& sa_is, const vector<int>& s, const int upper) -> vector<int>\
    \ {\n        const int n = (int)s.size();\n        if(n == 0) return {};\n   \
    \     if(n == 1) return {0};\n        if(n == 2) {\n            if(s[0] < s[1])\
    \ return {0, 1};\n            else return {1, 0};\n        }\n        vector<int>\
    \ sa(n);\n        vector<bool> ls(n);\n        for(int i = n - 2; i >= 0; --i)\
    \ {\n            ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);\n\
    \        }\n        vector<int> sum_l(upper + 1), sum_s(upper + 1);\n        for(int\
    \ i = 0; i < n; ++i) {\n            if(!ls[i]) {\n                ++sum_s[s[i]];\n\
    \            } else {\n                ++sum_l[s[i] + 1];\n            }\n   \
    \     }\n        for(int i = 0; i <= upper; ++i) {\n            sum_s[i] += sum_l[i];\n\
    \            if(i < upper) sum_l[i + 1] += sum_s[i];\n        }\n        auto\
    \ induce = [&](const vector<int>& lms) {\n            fill(sa.begin(), sa.end(),\
    \ -1);\n            vector<int> buf(upper + 1);\n            copy(sum_s.begin(),\
    \ sum_s.end(), buf.begin());\n            for(const int d : lms) {\n         \
    \       if(d == n) continue;\n                sa[buf[s[d]]++] = d;\n         \
    \   }\n            copy(sum_l.begin(), sum_l.end(), buf.begin());\n          \
    \  sa[buf[s[n - 1]]++] = n - 1;\n            for(int i = 0; i < n; ++i) {\n  \
    \              const int v = sa[i];\n                if(v >= 1 and !ls[v - 1])\
    \ {\n                    sa[buf[s[v - 1]]++] = v - 1;\n                }\n   \
    \         }\n            copy(sum_l.begin(), sum_l.end(), buf.begin());\n    \
    \        for(int i = n - 1; i >= 0; --i) {\n                const int v = sa[i];\n\
    \                if(v >= 1 and ls[v - 1]) {\n                    sa[--buf[s[v\
    \ - 1] + 1]] = v - 1;\n                }\n            }\n        };\n        vector<int>\
    \ lms_map(n + 1, -1);\n        int m = 0;\n        for(int i = 1; i < n; ++i)\
    \ {\n            if(!ls[i - 1] and ls[i]) {\n                lms_map[i] = m++;\n\
    \            }\n        }\n        vector<int> lms;\n        lms.reserve(m);\n\
    \        for(int i = 1; i < n; ++i) {\n            if(!ls[i - 1] and ls[i]) {\n\
    \                lms.push_back(i);\n            }\n        }\n        induce(lms);\n\
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
    \ return lcp_array(s2, sa);\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/string/suffix_array.hpp
  requiredBy: []
  timestamp: '2024-11-09 02:46:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/string/number_of_substrings.test.cpp
  - verify/library_checker/string/suffix_array.test.cpp
  - verify/library_checker/string/number_of_substrings_2.test.cpp
documentation_of: src/string/suffix_array.hpp
layout: document
title: suffix_array
---

## suffix_array

```cpp
(1) vector<int> suffix_array(string s)
(2) vector<int> suffix_array(vector<T> s, bool compress = true)
```

長さ $n$ の文字列 `s` のSuffix Array `sa` を返します．

`sa` は， $(0, 1, ..., n - 1)$ の順列であって，各 $i = 0, 1, ..., n - 2$ について<br>
`s[sa[i], n) < s[sa[i + 1], n)` を満たすものです．

(2)を呼んだ際， `compress` が真のときは `s` に対して座標圧縮を行います．

**計算量**

- (1) $O(n)$
- (2) `compress` が真のとき$O(n \log n)$， `compress` が偽のとき `s` の最大値を $m$ として$O(n + m)$

## lcp_array

```cpp
(1) vector<int> lcp_array(string s, vector<int> sa)
(2) vector<int> lcp_array(vector<T> s, vector<int> sa)
```

`s` のLCP Array `lcp` を返します．

`lcp` は以下で定義される，長さ $n - 1$ の配列です．<br>
`lcp[i] = LCP(s[sa[i], n), s[sa[i + 1], n))`

**計算量**

- $O(n)$

## チートシート
```cpp
int op(int a, int b) {
    return min(a, b);
}
int e() {
    return (int)1e9;
}
string s;
vector<int> sa = saffix_array(s);
vector<int> lcp = lcp_array(s, sa);
SparseTable<int, op, e> st(lcp);
int len = st.query(l, r)
```
により，`LCP(s[sa[l], n), s[sa[r], n))` を前計算 $O(n \log n)$ クエリ $O(1)$ で計算できます．