---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/eratosthenes_seive.hpp.hpp
    title: src/math/eratosthenes_seive.hpp.hpp
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
  bundledCode: "#line 1 \"verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/math/eratosthenes_seive.hpp.hpp\"\nstruct EratosthenesSeive {\n\
    \    vector<int> primes, min_factor, moebius, euler;\n    EratosthenesSeive(const\
    \ int n)\n        : primes(), min_factor(n + 1), moebius(n + 1, 1), euler(n +\
    \ 1) {\n        assert(n >= 1);\n        iota(min_factor.begin(), min_factor.end(),\
    \ 0);\n        min_factor[0] = min_factor[1] = -1;\n        iota(euler.begin(),\
    \ euler.end(), 0);\n        for(int i = 2; i <= n; ++i) {\n            if(min_factor[i]\
    \ < i) continue;\n            primes.emplace_back(i);\n            moebius[i]\
    \ = -1;\n            euler[i] = euler[i] / i * (i - 1);\n            for(int j\
    \ = i * 2; j <= n; j += i) {\n                if(min_factor[j] == j) min_factor[j]\
    \ = i;\n                if((j / i) % i == 0) moebius[j] = 0;\n               \
    \ else moebius[j] = -moebius[j];\n                euler[j] = euler[j] / i * (i\
    \ - 1);\n            }\n        }\n    }\n};\n#line 4 \"verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp\"\
    \nint main(void) {\n    EratosthenesSeive seive(100000000);\n    int n;\n    cin\
    \ >> n;\n    int ans = 0;\n    rep(i, 0, n) {\n        int m;\n        cin >>\
    \ m;\n        if(seive.min_factor[m] == m) ans++;\n    }\n    cout << ans << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/math/eratosthenes_seive.hpp.hpp\"\
    \nint main(void) {\n    EratosthenesSeive seive(100000000);\n    int n;\n    cin\
    \ >> n;\n    int ans = 0;\n    rep(i, 0, n) {\n        int m;\n        cin >>\
    \ m;\n        if(seive.min_factor[m] == m) ans++;\n    }\n    cout << ans << '\\\
    n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/eratosthenes_seive.hpp.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
  requiredBy: []
  timestamp: '2024-11-07 20:55:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
- /verify/verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp.html
title: verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
---
