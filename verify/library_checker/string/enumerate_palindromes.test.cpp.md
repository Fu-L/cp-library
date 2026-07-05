---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/manacher.hpp
    title: manacher
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/library_checker/string/enumerate_palindromes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\
    #line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n#line 4 \"src/template/template.hpp\"\
    \nusing namespace std;\nusing ll = long long;\nusing P = pair<long long, long\
    \ long>;\n#define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i,\
    \ a, b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
    struct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/string/manacher.hpp\"\
    \ntemplate <typename T>\nvector<int> manacher(const T& s) {\n    const int n =\
    \ (int)s.size();\n    if(n == 0) return {};\n    vector<int> odd(n), even(n),\
    \ res(2 * n - 1);\n    for(int i = 0, l = 0, r = -1; i < n; ++i) {\n        int\
    \ k = (i > r ? 1 : min(odd[l + r - i], r - i + 1));\n        while(0 <= i - k\
    \ and i + k < n and s[i - k] == s[i + k]) ++k;\n        odd[i] = k;\n        if(i\
    \ + k - 1 > r) {\n            l = i - k + 1;\n            r = i + k - 1;\n   \
    \     }\n    }\n    for(int i = 0, l = 0, r = -1; i < n; ++i) {\n        int k\
    \ = (i > r ? 0 : min(even[l + r - i + 1], r - i + 1));\n        while(0 <= i -\
    \ k - 1 and i + k < n and s[i - k - 1] == s[i + k]) ++k;\n        even[i] = k;\n\
    \        if(i + k - 1 > r) {\n            l = i - k;\n            r = i + k -\
    \ 1;\n        }\n    }\n    for(int i = 0; i < n; ++i) {\n        res[2 * i] =\
    \ 2 * odd[i] - 1;\n        if(i) res[2 * i - 1] = 2 * even[i];\n    }\n    return\
    \ res;\n}\n#line 4 \"verify/library_checker/string/enumerate_palindromes.test.cpp\"\
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
  timestamp: '2026-07-05 23:31:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/string/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp.html
title: verify/library_checker/string/enumerate_palindromes.test.cpp
---
