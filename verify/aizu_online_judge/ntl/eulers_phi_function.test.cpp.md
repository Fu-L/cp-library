---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/euler_phi.hpp
    title: euler_phi
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
  bundledCode: "#line 1 \"verify/aizu_online_judge/ntl/eulers_phi_function.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/math/euler_phi.hpp\"\nll euler_phi(ll n) {\n    ll res = max(n,\
    \ 0ll);\n    for(ll i = 2; i * i <= n; ++i) {\n        if(n % i == 0) {\n    \
    \        res -= res / i;\n            while(n % i == 0) n /= i;\n        }\n \
    \   }\n    if(n > 1) res -= res / n;\n    return res;\n}\n#line 4 \"verify/aizu_online_judge/ntl/eulers_phi_function.test.cpp\"\
    \nint main(void) {\n    ll n;\n    cin >> n;\n    cout << euler_phi(n) << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/math/euler_phi.hpp\"\
    \nint main(void) {\n    ll n;\n    cin >> n;\n    cout << euler_phi(n) << '\\\
    n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/euler_phi.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/ntl/eulers_phi_function.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/ntl/eulers_phi_function.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/ntl/eulers_phi_function.test.cpp
- /verify/verify/aizu_online_judge/ntl/eulers_phi_function.test.cpp.html
title: verify/aizu_online_judge/ntl/eulers_phi_function.test.cpp
---
