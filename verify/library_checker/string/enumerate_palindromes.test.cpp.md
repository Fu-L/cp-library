---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/manacher.hpp
    title: manacher
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/library_checker/string/enumerate_palindromes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\
    #line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/string/manacher.hpp\"\
    \ntemplate <typename T>\nvector<int> manacher(T s) {\n    int n = (int)s.size();\n\
    \    s.resize(2 * n - 1);\n    for(int i = n - 1; i >= 0; --i) {\n        s[2\
    \ * i] = s[i];\n    }\n    auto d = *min_element(s.begin(), s.end());\n    for(int\
    \ i = 0; i < n - 1; ++i) {\n        s[2 * i + 1] = d;\n    }\n    n = (int)s.size();\n\
    \    vector<int> res(n);\n    for(int i = 0, j = 0; i < n;) {\n        while(i\
    \ - j >= 0 and i + j < n and s[i - j] == s[i + j]) ++j;\n        res[i] = j;\n\
    \        int k = 1;\n        while(i - k >= 0 and i + k < n and k + res[i - k]\
    \ < j) {\n            res[i + k] = res[i - k];\n            ++k;\n        }\n\
    \        i += k, j -= k;\n    }\n    for(int i = 0; i < n; ++i) {\n        if(((i\
    \ ^ res[i]) & 1) == 0) res[i]--;\n    }\n    return res;\n}\n#line 4 \"verify/library_checker/string/enumerate_palindromes.test.cpp\"\
    \nint main(void) {\n    string s;\n    cin >> s;\n    vector<int> l = manacher(s);\n\
    \    rep(i, 0, (int)l.size()) {\n        cout << l[i] << \" \\n\"[i + 1 == (int)s.size()];\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/string/manacher.hpp\"\
    \nint main(void) {\n    string s;\n    cin >> s;\n    vector<int> l = manacher(s);\n\
    \    rep(i, 0, (int)l.size()) {\n        cout << l[i] << \" \\n\"[i + 1 == (int)s.size()];\n\
    \    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/string/manacher.hpp
  isVerificationFile: true
  path: verify/library_checker/string/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/string/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp.html
title: verify/library_checker/string/enumerate_palindromes.test.cpp
---
