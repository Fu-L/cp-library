---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/prime_factorization.hpp
    title: prime_factor
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"verify/aizu_online_judge/ntl/prime_factorize.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/math/prime_factorization.hpp\"\nmap<ll, ll> prime_factor(ll n) {\n\
    \    assert(n >= 1);\n    map<ll, ll> res;\n    for(ll i = 2; i * i <= n; ++i)\
    \ {\n        while(n % i == 0) {\n            ++res[i];\n            n /= i;\n\
    \        }\n    }\n    if(n != 1) {\n        res[n] = 1;\n    }\n    return res;\n\
    }\n#line 4 \"verify/aizu_online_judge/ntl/prime_factorize.test.cpp\"\nint main(void)\
    \ {\n    ll n;\n    cin >> n;\n    map<ll, ll> mp = prime_factor(n);\n    cout\
    \ << n << ':';\n    for(auto it : mp) {\n        for(int i = 0; i < it.second;\
    \ ++i) {\n            cout << ' ' << it.first;\n        }\n    }\n    cout <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/math/prime_factorization.hpp\"\
    \nint main(void) {\n    ll n;\n    cin >> n;\n    map<ll, ll> mp = prime_factor(n);\n\
    \    cout << n << ':';\n    for(auto it : mp) {\n        for(int i = 0; i < it.second;\
    \ ++i) {\n            cout << ' ' << it.first;\n        }\n    }\n    cout <<\
    \ '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/prime_factorization.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/ntl/prime_factorize.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/ntl/prime_factorize.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/ntl/prime_factorize.test.cpp
- /verify/verify/aizu_online_judge/ntl/prime_factorize.test.cpp.html
title: verify/aizu_online_judge/ntl/prime_factorize.test.cpp
---
