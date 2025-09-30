---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/kth_root_integer.hpp
    title: kth_root_integer
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
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_integer
    links:
    - https://judge.yosupo.jp/problem/kth_root_integer
  bundledCode: "#line 1 \"verify/library_checker/number_theory/kth_root_integer.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\n#line\
    \ 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing P = pair<long long, long long>;\n#define rep(i, a,\
    \ b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long long\
    \ i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO {\n\
    \    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n    \
    \    cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/kth_root_integer.hpp\"\
    \nunsigned long long kth_root_integer(const unsigned long long x, const int k)\
    \ {\n    if(k <= 1) return k ? x : 1;\n    if(x <= 1) return x;\n    if(k >= 64)\
    \ return 1;\n    auto check = [&](unsigned long long a) -> bool {\n        unsigned\
    \ long long power = 1;\n        for(int i = k; i;) {\n            if(i & 1) {\n\
    \                if(power > x / a) return false;\n                power *= a;\n\
    \            }\n            if(i >>= 1) {\n                if(a > x / a) return\
    \ false;\n                a *= a;\n            }\n        }\n        return power\
    \ <= x;\n    };\n    unsigned long long res = pow(x, 1.0 / k);\n    while(!check(res))\
    \ --res;\n    while(check(res + 1)) ++res;\n    return res;\n}\n#line 4 \"verify/library_checker/number_theory/kth_root_integer.test.cpp\"\
    \nint main(void) {\n    int t;\n    cin >> t;\n    while(t--) {\n        unsigned\
    \ long long a, k;\n        cin >> a >> k;\n        cout << kth_root_integer(a,\
    \ k) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/math/kth_root_integer.hpp\"\
    \nint main(void) {\n    int t;\n    cin >> t;\n    while(t--) {\n        unsigned\
    \ long long a, k;\n        cin >> a >> k;\n        cout << kth_root_integer(a,\
    \ k) << '\\n';\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/kth_root_integer.hpp
  isVerificationFile: true
  path: verify/library_checker/number_theory/kth_root_integer.test.cpp
  requiredBy: []
  timestamp: '2025-09-30 23:32:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/number_theory/kth_root_integer.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/number_theory/kth_root_integer.test.cpp
- /verify/verify/library_checker/number_theory/kth_root_integer.test.cpp.html
title: verify/library_checker/number_theory/kth_root_integer.test.cpp
---
