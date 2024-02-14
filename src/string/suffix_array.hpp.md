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
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/string/suffix_array.hpp\"\
    \nvector<int> suffix_array(const vector<int>& s) {\n    int n = (int)s.size();\n\
    \    vector<int> sa(n), rank(n), tmp(n);\n    for(int i = 0; i < n; ++i) rank[i]\
    \ = s[i];\n    iota(sa.begin(), sa.end(), 0);\n    for(int k = 1; k < n; k *=\
    \ 2) {\n        auto cmp = [&](int x, int y) -> bool {\n            if(rank[x]\
    \ != rank[y]) return rank[x] < rank[y];\n            int rx = x + k < n ? rank[x\
    \ + k] : -1;\n            int ry = y + k < n ? rank[y + k] : -1;\n           \
    \ return rx < ry;\n        };\n        sort(sa.begin(), sa.end(), cmp);\n    \
    \    tmp[sa[0]] = 0;\n        for(int i = 1; i < n; ++i) {\n            tmp[sa[i]]\
    \ = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\n        }\n        swap(tmp,\
    \ rank);\n    }\n    return sa;\n}\nvector<int> suffix_array(const string& s)\
    \ {\n    int n = (int)s.size();\n    vector<int> s2(n);\n    for(int i = 0; i\
    \ < n; ++i) {\n        s2[i] = s[i];\n    }\n    return suffix_array(s2);\n}\n\
    vector<int> lcp_array(const vector<int>& s, const vector<int>& sa) {\n    int\
    \ n = (int)s.size();\n    assert(n >= 1);\n    vector<int> rank(n);\n    for(int\
    \ i = 0; i < n; ++i) {\n        rank[sa[i]] = i;\n    }\n    vector<int> lcp(n\
    \ - 1);\n    int h = 0;\n    for(int i = 0; i < n; ++i) {\n        if(h > 0) --h;\n\
    \        if(rank[i] == 0) continue;\n        int j = sa[rank[i] - 1];\n      \
    \  for(; j + h < n and i + h < n; ++h) {\n            if(s[j + h] != s[i + h])\
    \ break;\n        }\n        lcp[rank[i] - 1] = h;\n    }\n    return lcp;\n}\n\
    vector<int> lcp_array(const string& s, const vector<int>& sa) {\n    int n = (int)s.size();\n\
    \    vector<int> s2(n);\n    for(int i = 0; i < n; ++i) {\n        s2[i] = s[i];\n\
    \    }\n    return lcp_array(s2, sa);\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nvector<int> suffix_array(const\
    \ vector<int>& s) {\n    int n = (int)s.size();\n    vector<int> sa(n), rank(n),\
    \ tmp(n);\n    for(int i = 0; i < n; ++i) rank[i] = s[i];\n    iota(sa.begin(),\
    \ sa.end(), 0);\n    for(int k = 1; k < n; k *= 2) {\n        auto cmp = [&](int\
    \ x, int y) -> bool {\n            if(rank[x] != rank[y]) return rank[x] < rank[y];\n\
    \            int rx = x + k < n ? rank[x + k] : -1;\n            int ry = y +\
    \ k < n ? rank[y + k] : -1;\n            return rx < ry;\n        };\n       \
    \ sort(sa.begin(), sa.end(), cmp);\n        tmp[sa[0]] = 0;\n        for(int i\
    \ = 1; i < n; ++i) {\n            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1],\
    \ sa[i]) ? 1 : 0);\n        }\n        swap(tmp, rank);\n    }\n    return sa;\n\
    }\nvector<int> suffix_array(const string& s) {\n    int n = (int)s.size();\n \
    \   vector<int> s2(n);\n    for(int i = 0; i < n; ++i) {\n        s2[i] = s[i];\n\
    \    }\n    return suffix_array(s2);\n}\nvector<int> lcp_array(const vector<int>&\
    \ s, const vector<int>& sa) {\n    int n = (int)s.size();\n    assert(n >= 1);\n\
    \    vector<int> rank(n);\n    for(int i = 0; i < n; ++i) {\n        rank[sa[i]]\
    \ = i;\n    }\n    vector<int> lcp(n - 1);\n    int h = 0;\n    for(int i = 0;\
    \ i < n; ++i) {\n        if(h > 0) --h;\n        if(rank[i] == 0) continue;\n\
    \        int j = sa[rank[i] - 1];\n        for(; j + h < n and i + h < n; ++h)\
    \ {\n            if(s[j + h] != s[i + h]) break;\n        }\n        lcp[rank[i]\
    \ - 1] = h;\n    }\n    return lcp;\n}\nvector<int> lcp_array(const string& s,\
    \ const vector<int>& sa) {\n    int n = (int)s.size();\n    vector<int> s2(n);\n\
    \    for(int i = 0; i < n; ++i) {\n        s2[i] = s[i];\n    }\n    return lcp_array(s2,\
    \ sa);\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/string/suffix_array.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/string/suffix_array.test.cpp
  - verify/library_checker/string/number_of_substrings.test.cpp
  - verify/library_checker/string/number_of_substrings_2.test.cpp
documentation_of: src/string/suffix_array.hpp
layout: document
title: suffix_array
---

## suffix_array

```cpp
vector<int> suffix_array(string s)
```

長さ $n$ の文字列 `s` のSuffix Array `sa` を返します．

`sa` は， $(0, 1, ..., n - 1)$ の順列であって，各 $i = 0, 1, ..., n - 2$ について<br>
`s[sa[i], n) < s[sa[i + 1], n)` を満たすものです．

**計算量**

- $O(n \log n)$

## lcp_array

```cpp
vector<int> lcp_array(string s, vector<int> sa)
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