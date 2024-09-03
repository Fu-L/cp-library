---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/enumerate_palindromes.test.cpp
    title: verify/library_checker/string/enumerate_palindromes.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/string/manacher.hpp\"\
    \ntemplate <typename T>\nvector<int> manacher(T s) {\n    int n = (int)s.size();\n\
    \    s.resize(2 * n - 1);\n    for(int i = n - 1; i >= 0; --i) {\n        s[2\
    \ * i] = s[i];\n    }\n    auto d = *min_element(s.begin(), s.end());\n    for(int\
    \ i = 0; i < n - 1; ++i) {\n        s[2 * i + 1] = d;\n    }\n    n = (int)s.size();\n\
    \    vector<int> res(n);\n    for(int i = 0, j = 0; i < n;) {\n        while(i\
    \ - j >= 0 and i + j < n and s[i - j] == s[i + j]) ++j;\n        res[i] = j;\n\
    \        int k = 1;\n        while(i - k >= 0 and i + k < n and k + res[i - k]\
    \ < j) {\n            res[i + k] = res[i - k];\n            ++k;\n        }\n\
    \        i += k, j -= k;\n    }\n    for(int i = 0; i < n; ++i) {\n        if(((i\
    \ ^ res[i]) & 1) == 0) res[i]--;\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    vector<int> manacher(T s) {\n    int n = (int)s.size();\n    s.resize(2 * n -\
    \ 1);\n    for(int i = n - 1; i >= 0; --i) {\n        s[2 * i] = s[i];\n    }\n\
    \    auto d = *min_element(s.begin(), s.end());\n    for(int i = 0; i < n - 1;\
    \ ++i) {\n        s[2 * i + 1] = d;\n    }\n    n = (int)s.size();\n    vector<int>\
    \ res(n);\n    for(int i = 0, j = 0; i < n;) {\n        while(i - j >= 0 and i\
    \ + j < n and s[i - j] == s[i + j]) ++j;\n        res[i] = j;\n        int k =\
    \ 1;\n        while(i - k >= 0 and i + k < n and k + res[i - k] < j) {\n     \
    \       res[i + k] = res[i - k];\n            ++k;\n        }\n        i += k,\
    \ j -= k;\n    }\n    for(int i = 0; i < n; ++i) {\n        if(((i ^ res[i]) &\
    \ 1) == 0) res[i]--;\n    }\n    return res;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/string/manacher.hpp
  requiredBy: []
  timestamp: '2024-06-28 15:21:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
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