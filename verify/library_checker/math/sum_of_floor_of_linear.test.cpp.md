---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/floor_sum.hpp
    title: floor_sum
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"verify/library_checker/math/sum_of_floor_of_linear.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\
    #line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/math/floor_sum.hpp\"\nll floor_sum(ll n, ll m, ll a, ll b) {\n \
    \   ll res = 0;\n    if(a >= m) res += (n - 1) * n * (a / m) / 2, a %= m;\n  \
    \  if(b >= m) res += n * (b / m), b %= m;\n    ll y = (a * n + b) / m;\n    if(y\
    \ == 0) return res;\n    ll x = y * m - b;\n    res += (n - (x + a - 1) / a) *\
    \ y;\n    res += floor_sum(y, a, m, (a - x % a) % a);\n    return res;\n}\n#line\
    \ 4 \"verify/library_checker/math/sum_of_floor_of_linear.test.cpp\"\nint main(void)\
    \ {\n    int t;\n    cin >> t;\n    while(t--) {\n        ll n, m, a, b;\n   \
    \     cin >> n >> m >> a >> b;\n        cout << floor_sum(n, m, a, b) << '\\n';\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/math/floor_sum.hpp\"\
    \nint main(void) {\n    int t;\n    cin >> t;\n    while(t--) {\n        ll n,\
    \ m, a, b;\n        cin >> n >> m >> a >> b;\n        cout << floor_sum(n, m,\
    \ a, b) << '\\n';\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/floor_sum.hpp
  isVerificationFile: true
  path: verify/library_checker/math/sum_of_floor_of_linear.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/math/sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/math/sum_of_floor_of_linear.test.cpp
- /verify/verify/library_checker/math/sum_of_floor_of_linear.test.cpp.html
title: verify/library_checker/math/sum_of_floor_of_linear.test.cpp
---