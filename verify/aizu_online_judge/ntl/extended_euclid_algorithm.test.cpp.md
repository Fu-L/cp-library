---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/math/extgcd.hpp
    title: extgcd
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
  bundledCode: "#line 1 \"verify/aizu_online_judge/ntl/extended_euclid_algorithm.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 2 \"src/math/extgcd.hpp\"\
    \nlong long extgcd(long long a, long long b, long long& x, long long& y) {\n \
    \   long long d = a;\n    if(b != 0) {\n        d = extgcd(b, a % b, y, x);\n\
    \        y -= (a / b) * x;\n    } else {\n        x = 1;\n        y = 0;\n   \
    \ }\n    return d;\n}\n#line 4 \"verify/aizu_online_judge/ntl/extended_euclid_algorithm.test.cpp\"\
    \nint main(void) {\n    ll a, b, x, y;\n    cin >> a >> b;\n    extgcd(a, b, x,\
    \ y);\n    cout << x << ' ' << y << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/math/extgcd.hpp\"\
    \nint main(void) {\n    ll a, b, x, y;\n    cin >> a >> b;\n    extgcd(a, b, x,\
    \ y);\n    cout << x << ' ' << y << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/extgcd.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/ntl/extended_euclid_algorithm.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aizu_online_judge/ntl/extended_euclid_algorithm.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/ntl/extended_euclid_algorithm.test.cpp
- /verify/verify/aizu_online_judge/ntl/extended_euclid_algorithm.test.cpp.html
title: verify/aizu_online_judge/ntl/extended_euclid_algorithm.test.cpp
---
