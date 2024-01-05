---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/divisor.hpp
    title: divisor
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D
  bundledCode: "#line 1 \"verify/aizu_online_judge/itp1/how_many_divisors.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/math/divisor.hpp\"\nvector<ll> divisor(ll n) {\n    assert(n >=\
    \ 1);\n    vector<ll> res;\n    for(ll i = 1; i * i <= n; ++i) {\n        if(n\
    \ % i == 0) {\n            res.push_back(i);\n            if(i * i != n) res.push_back(n\
    \ / i);\n        }\n    }\n    sort(res.begin(), res.end());\n    return res;\n\
    }\n#line 4 \"verify/aizu_online_judge/itp1/how_many_divisors.test.cpp\"\nint main(void)\
    \ {\n    int a, b, c;\n    cin >> a >> b >> c;\n    vector<ll> d = divisor(c);\n\
    \    int ans = 0;\n    for(int i = 0; i < (int)d.size(); i++) {\n        if(a\
    \ <= d[i] and d[i] <= b) {\n            ans++;\n        }\n    }\n    cout <<\
    \ ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/math/divisor.hpp\"\
    \nint main(void) {\n    int a, b, c;\n    cin >> a >> b >> c;\n    vector<ll>\
    \ d = divisor(c);\n    int ans = 0;\n    for(int i = 0; i < (int)d.size(); i++)\
    \ {\n        if(a <= d[i] and d[i] <= b) {\n            ans++;\n        }\n  \
    \  }\n    cout << ans << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/divisor.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/itp1/how_many_divisors.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/itp1/how_many_divisors.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/itp1/how_many_divisors.test.cpp
- /verify/verify/aizu_online_judge/itp1/how_many_divisors.test.cpp.html
title: verify/aizu_online_judge/itp1/how_many_divisors.test.cpp
---
