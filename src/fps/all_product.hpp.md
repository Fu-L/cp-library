---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/fps/all_product.hpp\"\
    \ntemplate <template <typename> typename FormalPowerSeries, typename mint>\nFormalPowerSeries<mint>\
    \ all_product(vector<FormalPowerSeries<mint>> f) {\n    if((int)f.size() == 0)\
    \ return {1};\n    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,\
    \ int>>> pq;\n    rep(i, 0, (int)f.size()) pq.push({f[i].size(), i});\n    while((int)pq.size()\
    \ > 1) {\n        auto [d1, i1] = pq.top();\n        pq.pop();\n        auto [d2,\
    \ i2] = pq.top();\n        pq.pop();\n        f[i1] *= f[i2];\n        f[i2].clear();\n\
    \        pq.push({d1 + d2, i1});\n    }\n    return f[pq.top().second];\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <template <typename>\
    \ typename FormalPowerSeries, typename mint>\nFormalPowerSeries<mint> all_product(vector<FormalPowerSeries<mint>>\
    \ f) {\n    if((int)f.size() == 0) return {1};\n    priority_queue<pair<int, int>,\
    \ vector<pair<int, int>>, greater<pair<int, int>>> pq;\n    rep(i, 0, (int)f.size())\
    \ pq.push({f[i].size(), i});\n    while((int)pq.size() > 1) {\n        auto [d1,\
    \ i1] = pq.top();\n        pq.pop();\n        auto [d2, i2] = pq.top();\n    \
    \    pq.pop();\n        f[i1] *= f[i2];\n        f[i2].clear();\n        pq.push({d1\
    \ + d2, i1});\n    }\n    return f[pq.top().second];\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/fps/all_product.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
documentation_of: src/fps/all_product.hpp
layout: document
redirect_from:
- /library/src/fps/all_product.hpp
- /library/src/fps/all_product.hpp.html
title: src/fps/all_product.hpp
---
