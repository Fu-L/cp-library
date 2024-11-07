---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
    title: verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/eratosthenes_seive.test.cpp
    title: verify/unit_test/math/eratosthenes_seive.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/eratosthenes_seive.hpp.hpp\"\
    \nstruct EratosthenesSeive {\n    vector<int> primes, min_factor, moebius, euler;\n\
    \    EratosthenesSeive(const int n)\n        : primes(), min_factor(n + 1), moebius(n\
    \ + 1, 1), euler(n + 1) {\n        assert(n >= 1);\n        iota(min_factor.begin(),\
    \ min_factor.end(), 0);\n        min_factor[0] = min_factor[1] = -1;\n       \
    \ iota(euler.begin(), euler.end(), 0);\n        for(int i = 2; i <= n; ++i) {\n\
    \            if(min_factor[i] < i) continue;\n            primes.emplace_back(i);\n\
    \            moebius[i] = -1;\n            euler[i] = euler[i] / i * (i - 1);\n\
    \            for(int j = i * 2; j <= n; j += i) {\n                if(min_factor[j]\
    \ == j) min_factor[j] = i;\n                if((j / i) % i == 0) moebius[j] =\
    \ 0;\n                else moebius[j] = -moebius[j];\n                euler[j]\
    \ = euler[j] / i * (i - 1);\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nstruct EratosthenesSeive\
    \ {\n    vector<int> primes, min_factor, moebius, euler;\n    EratosthenesSeive(const\
    \ int n)\n        : primes(), min_factor(n + 1), moebius(n + 1, 1), euler(n +\
    \ 1) {\n        assert(n >= 1);\n        iota(min_factor.begin(), min_factor.end(),\
    \ 0);\n        min_factor[0] = min_factor[1] = -1;\n        iota(euler.begin(),\
    \ euler.end(), 0);\n        for(int i = 2; i <= n; ++i) {\n            if(min_factor[i]\
    \ < i) continue;\n            primes.emplace_back(i);\n            moebius[i]\
    \ = -1;\n            euler[i] = euler[i] / i * (i - 1);\n            for(int j\
    \ = i * 2; j <= n; j += i) {\n                if(min_factor[j] == j) min_factor[j]\
    \ = i;\n                if((j / i) % i == 0) moebius[j] = 0;\n               \
    \ else moebius[j] = -moebius[j];\n                euler[j] = euler[j] / i * (i\
    \ - 1);\n            }\n        }\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/eratosthenes_seive.hpp.hpp
  requiredBy: []
  timestamp: '2024-11-07 20:55:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/eratosthenes_seive.test.cpp
  - verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
documentation_of: src/math/eratosthenes_seive.hpp.hpp
layout: document
redirect_from:
- /library/src/math/eratosthenes_seive.hpp.hpp
- /library/src/math/eratosthenes_seive.hpp.hpp.html
title: src/math/eratosthenes_seive.hpp.hpp
---
