---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/pow_mod.hpp
    title: pow_mod
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
  bundledCode: "#line 1 \"verify/aizu_online_judge/ntl/power.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\n#line\
    \ 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i\
    \ = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/math/pow_mod.hpp\"\nconstexpr long long pow_mod(long long x, long\
    \ long n, const long long mod) {\n    assert(n >= 0 and mod >= 1);\n    x %= mod;\n\
    \    if(x < 0) x += mod;\n    long long res = 1;\n    while(n > 0) {\n       \
    \ if(n & 1) res = res * x % mod;\n        x = x * x % mod;\n        n >>= 1;\n\
    \    }\n    return res;\n}\n#line 4 \"verify/aizu_online_judge/ntl/power.test.cpp\"\
    \nint main(void) {\n    ll m, n;\n    cin >> m >> n;\n    cout << pow_mod(m, n,\
    \ 1000000007) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/math/pow_mod.hpp\"\
    \nint main(void) {\n    ll m, n;\n    cin >> m >> n;\n    cout << pow_mod(m, n,\
    \ 1000000007) << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/pow_mod.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/ntl/power.test.cpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/ntl/power.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/ntl/power.test.cpp
- /verify/verify/aizu_online_judge/ntl/power.test.cpp.html
title: verify/aizu_online_judge/ntl/power.test.cpp
---
