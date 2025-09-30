---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number_theory/kth_root_integer.test.cpp
    title: verify/library_checker/number_theory/kth_root_integer.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n\
    #define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a,\
    \ b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
    struct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/kth_root_integer.hpp\"\
    \nunsigned long long kth_root_integer(const unsigned long long x, const int k)\
    \ {\n    if(k <= 1) return k ? x : 1;\n    if(x <= 1) return x;\n    if(k >= 64)\
    \ return 1;\n    auto check = [&](unsigned long long a) -> bool {\n        unsigned\
    \ long long power = 1;\n        for(int i = k; i;) {\n            if(i & 1) {\n\
    \                if(power > x / a) return false;\n                power *= a;\n\
    \            }\n            if(i >>= 1) {\n                if(a > x / a) return\
    \ false;\n                a *= a;\n            }\n        }\n        return power\
    \ <= x;\n    };\n    unsigned long long res = pow(x, 1.0 / k);\n    while(!check(res))\
    \ --res;\n    while(check(res + 1)) ++res;\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nunsigned long long kth_root_integer(const\
    \ unsigned long long x, const int k) {\n    if(k <= 1) return k ? x : 1;\n   \
    \ if(x <= 1) return x;\n    if(k >= 64) return 1;\n    auto check = [&](unsigned\
    \ long long a) -> bool {\n        unsigned long long power = 1;\n        for(int\
    \ i = k; i;) {\n            if(i & 1) {\n                if(power > x / a) return\
    \ false;\n                power *= a;\n            }\n            if(i >>= 1)\
    \ {\n                if(a > x / a) return false;\n                a *= a;\n  \
    \          }\n        }\n        return power <= x;\n    };\n    unsigned long\
    \ long res = pow(x, 1.0 / k);\n    while(!check(res)) --res;\n    while(check(res\
    \ + 1)) ++res;\n    return res;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/kth_root_integer.hpp
  requiredBy: []
  timestamp: '2025-09-30 23:32:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/number_theory/kth_root_integer.test.cpp
documentation_of: src/math/kth_root_integer.hpp
layout: document
title: kth_root_integer
---

## kth_root_integer

```cpp
unsigned long long kth_root_integer(unsigned long long x, int k)
```

$\lfloor \sqrt[k]{x} \rfloor$ を返します．<br>

**計算量**

- $O(\log{x})$