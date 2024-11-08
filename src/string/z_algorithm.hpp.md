---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/string/z_algorithm.test.cpp
    title: verify/library_checker/string/z_algorithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n\
    #define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a,\
    \ b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
    struct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/string/z_algorithm.hpp\"\
    \ntemplate <typename T>\nvector<int> z_algorithm(const vector<T>& s) {\n    const\
    \ int n = (int)s.size();\n    if(n == 0) return {};\n    vector<int> z(n);\n \
    \   z[0] = 0;\n    for(int i = 1, j = 0; i < n; ++i) {\n        int& k = z[i];\n\
    \        k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i - j]);\n        while(i\
    \ + k < n and s[k] == s[i + k]) ++k;\n        if(j + z[j] < i + z[i]) j = i;\n\
    \    }\n    z[0] = n;\n    return z;\n}\nvector<int> z_algorithm(const string&\
    \ s) {\n    const int n = (int)s.size();\n    vector<int> s2(n);\n    for(int\
    \ i = 0; i < n; ++i) {\n        s2[i] = s[i];\n    }\n    return z_algorithm(s2);\n\
    }\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    vector<int> z_algorithm(const vector<T>& s) {\n    const int n = (int)s.size();\n\
    \    if(n == 0) return {};\n    vector<int> z(n);\n    z[0] = 0;\n    for(int\
    \ i = 1, j = 0; i < n; ++i) {\n        int& k = z[i];\n        k = (j + z[j] <=\
    \ i) ? 0 : min(j + z[j] - i, z[i - j]);\n        while(i + k < n and s[k] == s[i\
    \ + k]) ++k;\n        if(j + z[j] < i + z[i]) j = i;\n    }\n    z[0] = n;\n \
    \   return z;\n}\nvector<int> z_algorithm(const string& s) {\n    const int n\
    \ = (int)s.size();\n    vector<int> s2(n);\n    for(int i = 0; i < n; ++i) {\n\
    \        s2[i] = s[i];\n    }\n    return z_algorithm(s2);\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/string/z_algorithm.test.cpp
documentation_of: src/string/z_algorithm.hpp
layout: document
title: z_algorithm
---

## z_algorithm

```cpp
(1) vector<int> z_algorithm(string s)
(2) vector<int> z_algorithm(vector<T> s)
```

`s` の長さを $n$ として，長さ $n$ の配列 `z` を返します．<br>
`z[i] = LCP(s, s[i, n))` です．<br>
(LCPとは，Longest Common Prefix (先頭から何文字一致しているか) の略です．)

**計算量**

- $O(n)$