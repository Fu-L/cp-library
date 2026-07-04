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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/string/manacher.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 4 \"src/template/template.hpp\"\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/string/manacher.hpp\"\
    \ntemplate <typename T>\nvector<int> manacher(T s) {\n    int n = (int)s.size();\n\
    \    if(n == 0) return {};\n    s.resize(2 * n - 1);\n    for(int i = n - 1; i\
    \ >= 0; --i) {\n        s[2 * i] = s[i];\n    }\n    const auto d = *min_element(s.begin(),\
    \ s.end());\n    for(int i = 0; i < n - 1; ++i) {\n        s[2 * i + 1] = d;\n\
    \    }\n    n = (int)s.size();\n    vector<int> res(n);\n    for(int i = 0, j\
    \ = 0; i < n;) {\n        while(i - j >= 0 and i + j < n and s[i - j] == s[i +\
    \ j]) ++j;\n        res[i] = j;\n        int k = 1;\n        while(i - k >= 0\
    \ and i + k < n and k + res[i - k] < j) {\n            res[i + k] = res[i - k];\n\
    \            ++k;\n        }\n        i += k, j -= k;\n    }\n    for(int i =\
    \ 0; i < n; ++i) {\n        if(((i ^ res[i]) & 1) == 0) --res[i];\n    }\n   \
    \ return res;\n}\n#line 4 \"verify/unit_test/string/manacher.test.cpp\"\nint main()\
    \ {\n    assert(manacher(string()).empty());\n    int a, b;\n    cin >> a >> b;\n\
    \    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/string/manacher.hpp\"\nint main() {\n    assert(manacher(string()).empty());\n\
    \    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/string/manacher.hpp
  isVerificationFile: true
  path: verify/unit_test/string/manacher.test.cpp
  requiredBy: []
  timestamp: '2026-07-04 16:35:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/string/manacher.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/string/manacher.test.cpp
- /verify/verify/unit_test/string/manacher.test.cpp.html
title: verify/unit_test/string/manacher.test.cpp
---
