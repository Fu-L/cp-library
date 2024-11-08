---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/math/prime_factors.hpp
    title: prime_factors
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"verify/aizu_online_judge/ntl/prime_factorize.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/prime_factors.hpp\"\
    \nvector<pair<long long, int>> prime_factors(long long n) {\n    assert(n >= 1);\n\
    \    vector<pair<long long, int>> res;\n    for(long long i = 2; i * i <= n; ++i)\
    \ {\n        if(n % i == 0) {\n            res.emplace_back(i, 0);\n         \
    \   while(n % i == 0) {\n                n /= i;\n                ++res.back().second;\n\
    \            }\n        }\n    }\n    if(n >= 2) res.emplace_back(n, 1);\n   \
    \ return res;\n}\n#line 4 \"verify/aizu_online_judge/ntl/prime_factorize.test.cpp\"\
    \nint main(void) {\n    ll n;\n    cin >> n;\n    vector<pair<ll, int>> p = prime_factors(n);\n\
    \    cout << n << ':';\n    for(const auto& it : p) {\n        for(int i = 0;\
    \ i < it.second; ++i) {\n            cout << ' ' << it.first;\n        }\n   \
    \ }\n    cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/math/prime_factors.hpp\"\
    \nint main(void) {\n    ll n;\n    cin >> n;\n    vector<pair<ll, int>> p = prime_factors(n);\n\
    \    cout << n << ':';\n    for(const auto& it : p) {\n        for(int i = 0;\
    \ i < it.second; ++i) {\n            cout << ' ' << it.first;\n        }\n   \
    \ }\n    cout << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/prime_factors.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/ntl/prime_factorize.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aizu_online_judge/ntl/prime_factorize.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/ntl/prime_factorize.test.cpp
- /verify/verify/aizu_online_judge/ntl/prime_factorize.test.cpp.html
title: verify/aizu_online_judge/ntl/prime_factorize.test.cpp
---
