---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/pow_mod.hpp
    title: pow_mod
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/convolution.hpp
    title: convolution
  - icon: ':heavy_check_mark:'
    path: src/convolution/convolution_arbitrary.hpp
    title: convolution_arbitrary
  - icon: ':heavy_check_mark:'
    path: src/fps/formal_power_series.hpp
    title: src/fps/formal_power_series.hpp
  - icon: ':warning:'
    path: src/fps/formal_power_series_arbitrary.hpp
    title: src/fps/formal_power_series_arbitrary.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/convolution/convolution.test.cpp
    title: verify/library_checker/convolution/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/convolution/convolution_mod_1000000007.test.cpp
    title: verify/library_checker/convolution/convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/math/find_linear_recurrence.test.cpp
    title: verify/library_checker/math/find_linear_recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: verify/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/polynomial/division_of_polynomial.test.cpp
    title: verify/library_checker/polynomial/division_of_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/polynomial/exp_of_formal_power_series.test.cpp
    title: verify/library_checker/polynomial/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/polynomial/inv_of_formal_power_series.test.cpp
    title: verify/library_checker/polynomial/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/polynomial/log_of_formal_power_series.test.cpp
    title: verify/library_checker/polynomial/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/polynomial/polynomial_taylor_shift.test.cpp
    title: verify/library_checker/polynomial/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/polynomial/pow_of_formal_power_series.test.cpp
    title: verify/library_checker/polynomial/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
    title: verify/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/pow_mod.hpp\"\n\
    constexpr ll pow_mod(ll x, ll n, ll mod) {\n    assert(n >= 0 and mod >= 1);\n\
    \    x %= mod;\n    if(x < 0) x += mod;\n    ll res = 1;\n    while(n > 0) {\n\
    \        if(n & 1) res = res * x % mod;\n        x = x * x % mod;\n        n >>=\
    \ 1;\n    }\n    return res;\n}\n#line 4 \"src/math/primitive_root.hpp\"\nconstexpr\
    \ int primitive_root(int m) {\n    if(m == 2) return 1;\n    if(m == 167772161)\
    \ return 3;\n    if(m == 469762049) return 3;\n    if(m == 754974721) return 11;\n\
    \    if(m == 998244353) return 3;\n    int divs[20] = {};\n    divs[0] = 2;\n\
    \    int cnt = 1;\n    int x = (m - 1) / 2;\n    while(x % 2 == 0) x /= 2;\n \
    \   for(int i = 3; (long long)(i)*i <= x; i += 2) {\n        if(x % i == 0) {\n\
    \            divs[cnt++] = i;\n            while(x % i == 0) {\n             \
    \   x /= i;\n            }\n        }\n    }\n    if(x > 1) {\n        divs[cnt++]\
    \ = x;\n    }\n    for(int g = 2;; ++g) {\n        bool ok = true;\n        for(int\
    \ i = 0; i < cnt; ++i) {\n            if(pow_mod(g, (m - 1) / divs[i], m) == 1)\
    \ {\n                ok = false;\n                break;\n            }\n    \
    \    }\n        if(ok) return g;\n    }\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./pow_mod.hpp\"\
    \nconstexpr int primitive_root(int m) {\n    if(m == 2) return 1;\n    if(m ==\
    \ 167772161) return 3;\n    if(m == 469762049) return 3;\n    if(m == 754974721)\
    \ return 11;\n    if(m == 998244353) return 3;\n    int divs[20] = {};\n    divs[0]\
    \ = 2;\n    int cnt = 1;\n    int x = (m - 1) / 2;\n    while(x % 2 == 0) x /=\
    \ 2;\n    for(int i = 3; (long long)(i)*i <= x; i += 2) {\n        if(x % i ==\
    \ 0) {\n            divs[cnt++] = i;\n            while(x % i == 0) {\n      \
    \          x /= i;\n            }\n        }\n    }\n    if(x > 1) {\n       \
    \ divs[cnt++] = x;\n    }\n    for(int g = 2;; ++g) {\n        bool ok = true;\n\
    \        for(int i = 0; i < cnt; ++i) {\n            if(pow_mod(g, (m - 1) / divs[i],\
    \ m) == 1) {\n                ok = false;\n                break;\n          \
    \  }\n        }\n        if(ok) return g;\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/pow_mod.hpp
  isVerificationFile: false
  path: src/math/primitive_root.hpp
  requiredBy:
  - src/fps/formal_power_series_arbitrary.hpp
  - src/fps/formal_power_series.hpp
  - src/convolution/convolution_arbitrary.hpp
  - src/convolution/convolution.hpp
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
  - verify/library_checker/math/find_linear_recurrence.test.cpp
  - verify/library_checker/convolution/convolution.test.cpp
  - verify/library_checker/convolution/convolution_mod_1000000007.test.cpp
  - verify/library_checker/polynomial/polynomial_taylor_shift.test.cpp
  - verify/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
  - verify/library_checker/polynomial/log_of_formal_power_series.test.cpp
  - verify/library_checker/polynomial/pow_of_formal_power_series.test.cpp
  - verify/library_checker/polynomial/division_of_polynomial.test.cpp
  - verify/library_checker/polynomial/exp_of_formal_power_series.test.cpp
  - verify/library_checker/polynomial/inv_of_formal_power_series.test.cpp
documentation_of: src/math/primitive_root.hpp
layout: document
title: primitive_root
---

## primitive_root

```cpp
int primitive_root(int m)
```

$m$ の原始根を返します．

**制約**

- $m$ は素数

**計算量**

- 期待 $O(\sqrt{m})$