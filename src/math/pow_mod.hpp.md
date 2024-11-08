---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/convolution/convolution.hpp
    title: convolution
  - icon: ':question:'
    path: src/convolution/convolution_arbitrary.hpp
    title: convolution_arbitrary
  - icon: ':question:'
    path: src/convolution/convolution_ll.hpp
    title: convolution_ll
  - icon: ':heavy_check_mark:'
    path: src/fps/formal_power_series.hpp
    title: FormalPowerSeries
  - icon: ':x:'
    path: src/fps/formal_power_series_arbitrary.hpp
    title: FormalPowerSeriesArbitrary
  - icon: ':heavy_check_mark:'
    path: src/fps/formal_power_series_ll.hpp
    title: FormalPowerSeriesLL
  - icon: ':question:'
    path: src/math/primitive_root.hpp
    title: primitive_root
  - icon: ':heavy_check_mark:'
    path: src/string/wildcard_pattern_matching.hpp
    title: wildcard_pattern_matching
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/ntl/power.test.cpp
    title: verify/aizu_online_judge/ntl/power.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/convolution/convolution.test.cpp
    title: verify/library_checker/convolution/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/convolution/convolution_mod_1000000007.test.cpp
    title: verify/library_checker/convolution/convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/other/find_linear_recurrence.test.cpp
    title: verify/library_checker/other/find_linear_recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/other/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: verify/library_checker/other/kth_term_of_linearly_recurrent_sequence.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/wildcard_pattern_matching.test.cpp
    title: verify/library_checker/string/wildcard_pattern_matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/frequency_table_of_tree_distance.test.cpp
    title: verify/library_checker/tree/frequency_table_of_tree_distance.test.cpp
  - icon: ':x:'
    path: verify/unit_test/convolution/convolution_ll.test.cpp
    title: verify/unit_test/convolution/convolution_ll.test.cpp
  - icon: ':x:'
    path: verify/yukicoder/1559.test.cpp
    title: verify/yukicoder/1559.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n\
    #define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a,\
    \ b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
    struct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/pow_mod.hpp\"\
    \nconstexpr long long pow_mod(long long x, long long n, const long long mod) {\n\
    \    assert(n >= 0 and mod >= 1);\n    x %= mod;\n    if(x < 0) x += mod;\n  \
    \  long long res = 1;\n    while(n > 0) {\n        if(n & 1) res = res * x % mod;\n\
    \        x = x * x % mod;\n        n >>= 1;\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nconstexpr long long\
    \ pow_mod(long long x, long long n, const long long mod) {\n    assert(n >= 0\
    \ and mod >= 1);\n    x %= mod;\n    if(x < 0) x += mod;\n    long long res =\
    \ 1;\n    while(n > 0) {\n        if(n & 1) res = res * x % mod;\n        x =\
    \ x * x % mod;\n        n >>= 1;\n    }\n    return res;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/pow_mod.hpp
  requiredBy:
  - src/math/primitive_root.hpp
  - src/convolution/convolution.hpp
  - src/convolution/convolution_arbitrary.hpp
  - src/convolution/convolution_ll.hpp
  - src/string/wildcard_pattern_matching.hpp
  - src/fps/formal_power_series_arbitrary.hpp
  - src/fps/formal_power_series.hpp
  - src/fps/formal_power_series_ll.hpp
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/library_checker/convolution/convolution_mod_1000000007.test.cpp
  - verify/library_checker/convolution/convolution.test.cpp
  - verify/library_checker/string/wildcard_pattern_matching.test.cpp
  - verify/library_checker/other/kth_term_of_linearly_recurrent_sequence.test.cpp
  - verify/library_checker/other/find_linear_recurrence.test.cpp
  - verify/library_checker/tree/frequency_table_of_tree_distance.test.cpp
  - verify/library_checker/polynomial/division_of_polynomial.test.cpp
  - verify/library_checker/polynomial/inv_of_formal_power_series.test.cpp
  - verify/library_checker/polynomial/pow_of_formal_power_series.test.cpp
  - verify/library_checker/polynomial/log_of_formal_power_series.test.cpp
  - verify/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
  - verify/library_checker/polynomial/exp_of_formal_power_series.test.cpp
  - verify/library_checker/polynomial/polynomial_taylor_shift.test.cpp
  - verify/unit_test/convolution/convolution_ll.test.cpp
  - verify/aizu_online_judge/ntl/power.test.cpp
  - verify/yukicoder/1559.test.cpp
documentation_of: src/math/pow_mod.hpp
layout: document
title: pow_mod
---

## pow_mod

```cpp
ll pow_mod(ll x, ll n, ll mod)
```

$x^{n}$ を $\mathrm{mod}$ で割った余りを返します．

**制約**

- $0 \leq n$
- $1 \leq \mathrm{mod}$

**計算量**

- $O(\log n)$