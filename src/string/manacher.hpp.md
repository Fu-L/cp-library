---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/enumerate_palindromes.test.cpp
    title: verify/library_checker/string/enumerate_palindromes.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/string/manacher.test.cpp
    title: verify/unit_test/string/manacher.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    #line 4 \"src/template/template.hpp\"\nusing namespace std;\nusing ll = long long;\n\
    using P = pair<long long, long long>;\n#define rep(i, a, b) for(long long i =\
    \ (a); i < (b); ++i)\n#define rrep(i, a, b) for(long long i = (a); i >= (b); --i)\n\
    constexpr long long inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/string/manacher.hpp\"\ntemplate <typename T>\nvector<int> manacher(const\
    \ T& s) {\n    const int n = (int)s.size();\n    if(n == 0) return {};\n    vector<int>\
    \ odd(n), even(n), res(2 * n - 1);\n    for(int i = 0, l = 0, r = -1; i < n; ++i)\
    \ {\n        int k = (i > r ? 1 : min(odd[l + r - i], r - i + 1));\n        while(0\
    \ <= i - k and i + k < n and s[i - k] == s[i + k]) ++k;\n        odd[i] = k;\n\
    \        if(i + k - 1 > r) {\n            l = i - k + 1;\n            r = i +\
    \ k - 1;\n        }\n    }\n    for(int i = 0, l = 0, r = -1; i < n; ++i) {\n\
    \        int k = (i > r ? 0 : min(even[l + r - i + 1], r - i + 1));\n        while(0\
    \ <= i - k - 1 and i + k < n and s[i - k - 1] == s[i + k]) ++k;\n        even[i]\
    \ = k;\n        if(i + k - 1 > r) {\n            l = i - k;\n            r = i\
    \ + k - 1;\n        }\n    }\n    for(int i = 0; i < n; ++i) {\n        res[2\
    \ * i] = 2 * odd[i] - 1;\n        if(i) res[2 * i - 1] = 2 * even[i];\n    }\n\
    \    return res;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    vector<int> manacher(const T& s) {\n    const int n = (int)s.size();\n    if(n\
    \ == 0) return {};\n    vector<int> odd(n), even(n), res(2 * n - 1);\n    for(int\
    \ i = 0, l = 0, r = -1; i < n; ++i) {\n        int k = (i > r ? 1 : min(odd[l\
    \ + r - i], r - i + 1));\n        while(0 <= i - k and i + k < n and s[i - k]\
    \ == s[i + k]) ++k;\n        odd[i] = k;\n        if(i + k - 1 > r) {\n      \
    \      l = i - k + 1;\n            r = i + k - 1;\n        }\n    }\n    for(int\
    \ i = 0, l = 0, r = -1; i < n; ++i) {\n        int k = (i > r ? 0 : min(even[l\
    \ + r - i + 1], r - i + 1));\n        while(0 <= i - k - 1 and i + k < n and s[i\
    \ - k - 1] == s[i + k]) ++k;\n        even[i] = k;\n        if(i + k - 1 > r)\
    \ {\n            l = i - k;\n            r = i + k - 1;\n        }\n    }\n  \
    \  for(int i = 0; i < n; ++i) {\n        res[2 * i] = 2 * odd[i] - 1;\n      \
    \  if(i) res[2 * i - 1] = 2 * even[i];\n    }\n    return res;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/string/manacher.hpp
  requiredBy: []
  timestamp: '2026-07-05 23:31:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/string/manacher.test.cpp
  - verify/library_checker/string/enumerate_palindromes.test.cpp
documentation_of: src/string/manacher.hpp
layout: document
title: manacher
---

## manacher

```cpp
vector<int> manacher(string s)
```

長さ $n$ の文字列 $s$ に含まれる回文の中心として考えられる位置は $2n - 1$ 個あります．<br>
それぞれの位置 $i$ について $i$ を中心とする最長の回文の長さ $l_{i}$ を並べた長さ $2n - 1$ の配列 `l` を返します．<br>
存在しない場合は $l_{i} = 0$ とします．

**計算量**

- $O(n)$