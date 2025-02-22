---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/eratosthenes_sieve.hpp
    title: EratosthenesSieve
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
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/eratosthenes_sieve.hpp\"\
    \nstruct EratosthenesSieve {\n    vector<int> primes, min_factor, moebius, euler;\n\
    \    EratosthenesSieve(const int N)\n        : primes(), min_factor(N + 1), moebius(N\
    \ + 1, 1), euler(N + 1), N(N) {\n        assert(N >= 1);\n        iota(min_factor.begin(),\
    \ min_factor.end(), 0);\n        min_factor[0] = min_factor[1] = -1;\n       \
    \ iota(euler.begin(), euler.end(), 0);\n        for(int i = 2; i <= N; ++i) {\n\
    \            if(min_factor[i] < i) continue;\n            primes.emplace_back(i);\n\
    \            moebius[i] = -1;\n            euler[i] = euler[i] / i * (i - 1);\n\
    \            for(int j = i * 2; j <= N; j += i) {\n                if(min_factor[j]\
    \ == j) min_factor[j] = i;\n                if((j / i) % i == 0) moebius[j] =\
    \ 0;\n                else moebius[j] = -moebius[j];\n                euler[j]\
    \ = euler[j] / i * (i - 1);\n            }\n        }\n    }\n    vector<pair<int,\
    \ int>> prime_factors(int n) const {\n        assert(1 <= n and n <= N);\n   \
    \     vector<pair<int, int>> res;\n        while(n > 1) {\n            const int\
    \ p = min_factor[n];\n            int exp = 0;\n            while(min_factor[n]\
    \ == p) {\n                n /= p;\n                ++exp;\n            }\n  \
    \          res.emplace_back(p, exp);\n        }\n        return res;\n    }\n\
    \    vector<int> divisor(const int n) const {\n        assert(1 <= n and n <=\
    \ n);\n        vector<int> res({1});\n        const auto pf = prime_factors(n);\n\
    \        for(const auto& p : pf) {\n            const int s = (int)res.size();\n\
    \            for(int i = 0; i < s; ++i) {\n                int v = 1;\n      \
    \          for(int j = 0; j < p.second; ++j) {\n                    v *= p.first;\n\
    \                    res.push_back(res[i] * v);\n                }\n         \
    \   }\n        }\n        sort(res.begin(), res.end());\n        return res;\n\
    \    }\n\n   private:\n    int N;\n};\n#line 4 \"verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp\"\
    \nint main(void) {\n    EratosthenesSieve sieve(100000000);\n    int n;\n    cin\
    \ >> n;\n    int ans = 0;\n    rep(i, 0, n) {\n        int m;\n        cin >>\
    \ m;\n        if(sieve.min_factor[m] == m) ans++;\n    }\n    cout << ans << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/math/eratosthenes_sieve.hpp\"\
    \nint main(void) {\n    EratosthenesSieve sieve(100000000);\n    int n;\n    cin\
    \ >> n;\n    int ans = 0;\n    rep(i, 0, n) {\n        int m;\n        cin >>\
    \ m;\n        if(sieve.min_factor[m] == m) ans++;\n    }\n    cout << ans << '\\\
    n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/eratosthenes_sieve.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
  requiredBy: []
  timestamp: '2025-02-22 22:56:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
- /verify/verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp.html
title: verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
---
