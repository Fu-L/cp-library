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
    \ res;\n}\n#line 4 \"verify/unit_test/string/manacher.test.cpp\"\nvector<int>\
    \ brute(const string& s) {\n    const int n = (int)s.size();\n    if(n == 0) return\
    \ {};\n    vector<int> res(2 * n - 1);\n    for(int c = 0; c < 2 * n - 1; ++c)\
    \ {\n        for(int len = (c % 2 == 0);; len += 2) {\n            const int l\
    \ = (c - len + 1) / 2;\n            const int r = (c + len + 1) / 2;\n       \
    \     if(l < 0 or n < r) break;\n            bool ok = true;\n            for(int\
    \ i = l, j = r - 1; i < j; ++i, --j) {\n                if(s[i] != s[j]) {\n \
    \                   ok = false;\n                    break;\n                }\n\
    \            }\n            if(ok) res[c] = len;\n        }\n    }\n    return\
    \ res;\n}\nint main() {\n    assert(manacher(string()).empty());\n    assert(manacher(string(\"\
    ab\")) == vector<int>({1, 0, 1}));\n    assert(manacher(string(\"aa\")) == vector<int>({1,\
    \ 2, 1}));\n    assert(manacher(string(\"abba\")) == vector<int>({1, 0, 1, 4,\
    \ 1, 0, 1}));\n    for(int n = 0; n <= 9; ++n) {\n        for(int bit = 0; bit\
    \ < (1 << n); ++bit) {\n            string s(n, 'a');\n            for(int i =\
    \ 0; i < n; ++i) {\n                if((bit >> i) & 1) s[i] = 'b';\n         \
    \   }\n            assert(manacher(s) == brute(s));\n        }\n    }\n    int\
    \ a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/string/manacher.hpp\"\nvector<int> brute(const string&\
    \ s) {\n    const int n = (int)s.size();\n    if(n == 0) return {};\n    vector<int>\
    \ res(2 * n - 1);\n    for(int c = 0; c < 2 * n - 1; ++c) {\n        for(int len\
    \ = (c % 2 == 0);; len += 2) {\n            const int l = (c - len + 1) / 2;\n\
    \            const int r = (c + len + 1) / 2;\n            if(l < 0 or n < r)\
    \ break;\n            bool ok = true;\n            for(int i = l, j = r - 1; i\
    \ < j; ++i, --j) {\n                if(s[i] != s[j]) {\n                    ok\
    \ = false;\n                    break;\n                }\n            }\n   \
    \         if(ok) res[c] = len;\n        }\n    }\n    return res;\n}\nint main()\
    \ {\n    assert(manacher(string()).empty());\n    assert(manacher(string(\"ab\"\
    )) == vector<int>({1, 0, 1}));\n    assert(manacher(string(\"aa\")) == vector<int>({1,\
    \ 2, 1}));\n    assert(manacher(string(\"abba\")) == vector<int>({1, 0, 1, 4,\
    \ 1, 0, 1}));\n    for(int n = 0; n <= 9; ++n) {\n        for(int bit = 0; bit\
    \ < (1 << n); ++bit) {\n            string s(n, 'a');\n            for(int i =\
    \ 0; i < n; ++i) {\n                if((bit >> i) & 1) s[i] = 'b';\n         \
    \   }\n            assert(manacher(s) == brute(s));\n        }\n    }\n    int\
    \ a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/string/manacher.hpp
  isVerificationFile: true
  path: verify/unit_test/string/manacher.test.cpp
  requiredBy: []
  timestamp: '2026-07-05 23:31:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/string/manacher.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/string/manacher.test.cpp
- /verify/verify/unit_test/string/manacher.test.cpp.html
title: verify/unit_test/string/manacher.test.cpp
---
