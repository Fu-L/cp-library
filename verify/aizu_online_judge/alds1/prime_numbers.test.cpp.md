---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/is_prime.hpp
    title: is_prime
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
  bundledCode: "#line 1 \"verify/aizu_online_judge/alds1/prime_numbers.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/math/is_prime.hpp\"\nconstexpr bool is_prime(long long n) {\n  \
    \  if(n <= 1) return false;\n    for(long long i = 2; i * i <= n; ++i) {\n   \
    \     if(n % i == 0) return false;\n    }\n    return true;\n}\n#line 4 \"verify/aizu_online_judge/alds1/prime_numbers.test.cpp\"\
    \nint main(void) {\n    int n;\n    cin >> n;\n    int ans = 0;\n    while(n--)\
    \ {\n        int m;\n        cin >> m;\n        if(is_prime(m)) {\n          \
    \  ans++;\n        }\n    }\n    cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/math/is_prime.hpp\"\
    \nint main(void) {\n    int n;\n    cin >> n;\n    int ans = 0;\n    while(n--)\
    \ {\n        int m;\n        cin >> m;\n        if(is_prime(m)) {\n          \
    \  ans++;\n        }\n    }\n    cout << ans << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/is_prime.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/alds1/prime_numbers.test.cpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/alds1/prime_numbers.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/alds1/prime_numbers.test.cpp
- /verify/verify/aizu_online_judge/alds1/prime_numbers.test.cpp.html
title: verify/aizu_online_judge/alds1/prime_numbers.test.cpp
---
