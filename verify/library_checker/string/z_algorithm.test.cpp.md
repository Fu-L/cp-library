---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/string/z_algorithm.hpp
    title: z_algorithm
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"verify/library_checker/string/z_algorithm.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ P = pair<long long, long long>;\n#define rep(i, a, b) for(long long i = (a);\
    \ i < (b); ++i)\n#define rrep(i, a, b) for(long long i = (a); i >= (b); --i)\n\
    constexpr long long inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/string/z_algorithm.hpp\"\ntemplate <typename T>\nvector<int> z_algorithm(const\
    \ vector<T>& s) {\n    const int n = (int)s.size();\n    if(n == 0) return {};\n\
    \    vector<int> z(n);\n    z[0] = 0;\n    for(int i = 1, j = 0; i < n; ++i) {\n\
    \        int& k = z[i];\n        k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i\
    \ - j]);\n        while(i + k < n and s[k] == s[i + k]) ++k;\n        if(j + z[j]\
    \ < i + z[i]) j = i;\n    }\n    z[0] = n;\n    return z;\n}\nvector<int> z_algorithm(const\
    \ string& s) {\n    const int n = (int)s.size();\n    vector<int> s2(n);\n   \
    \ for(int i = 0; i < n; ++i) {\n        s2[i] = s[i];\n    }\n    return z_algorithm(s2);\n\
    }\n#line 4 \"verify/library_checker/string/z_algorithm.test.cpp\"\nint main(void)\
    \ {\n    string s;\n    cin >> s;\n    int n = s.size();\n    vector<int> z =\
    \ z_algorithm(s);\n    rep(i, 0, n) {\n        cout << z[i] << \" \\n\"[i + 1\
    \ == n];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/string/z_algorithm.hpp\"\
    \nint main(void) {\n    string s;\n    cin >> s;\n    int n = s.size();\n    vector<int>\
    \ z = z_algorithm(s);\n    rep(i, 0, n) {\n        cout << z[i] << \" \\n\"[i\
    \ + 1 == n];\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/string/z_algorithm.hpp
  isVerificationFile: true
  path: verify/library_checker/string/z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/string/z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/z_algorithm.test.cpp
- /verify/verify/library_checker/string/z_algorithm.test.cpp.html
title: verify/library_checker/string/z_algorithm.test.cpp
---
