---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/other/longest_increasing_sequence.test.cpp
    title: verify/library_checker/other/longest_increasing_sequence.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/others/longest_increasing_sequence.hpp\"\
    \ntemplate <typename T>\nvector<int> longest_increasing_sequence(const vector<T>&\
    \ a) {\n    const int n = a.size();\n    vector<pair<T, int>> dp;\n    vector<int>\
    \ p(n, -1);\n    for(int i = 0; i < n; ++i) {\n        auto it = lower_bound(begin(dp),\
    \ end(dp), make_pair(a[i], -i));\n        if(it != begin(dp)) p[i] = -prev(it)->second;\n\
    \        if(it == end(dp)) {\n            dp.emplace_back(a[i], -i);\n       \
    \ } else {\n            *it = make_pair(a[i], -i);\n        }\n    }\n    vector<int>\
    \ res;\n    for(int i = -dp.back().second; i != -1; i = p[i]) res.push_back(i);\n\
    \    reverse(begin(res), end(res));\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    vector<int> longest_increasing_sequence(const vector<T>& a) {\n    const int n\
    \ = a.size();\n    vector<pair<T, int>> dp;\n    vector<int> p(n, -1);\n    for(int\
    \ i = 0; i < n; ++i) {\n        auto it = lower_bound(begin(dp), end(dp), make_pair(a[i],\
    \ -i));\n        if(it != begin(dp)) p[i] = -prev(it)->second;\n        if(it\
    \ == end(dp)) {\n            dp.emplace_back(a[i], -i);\n        } else {\n  \
    \          *it = make_pair(a[i], -i);\n        }\n    }\n    vector<int> res;\n\
    \    for(int i = -dp.back().second; i != -1; i = p[i]) res.push_back(i);\n   \
    \ reverse(begin(res), end(res));\n    return res;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/others/longest_increasing_sequence.hpp
  requiredBy: []
  timestamp: '2025-02-27 04:25:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/other/longest_increasing_sequence.test.cpp
documentation_of: src/others/longest_increasing_sequence.hpp
layout: document
redirect_from:
- /library/src/others/longest_increasing_sequence.hpp
- /library/src/others/longest_increasing_sequence.hpp.html
title: src/others/longest_increasing_sequence.hpp
---
