---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/fps/nth_term.hpp
    title: src/fps/nth_term.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: verify/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/fps/bostan_mori.hpp\"\
    \ntemplate <template <typename> typename FormalPowerSeries, typename mint>\nmint\
    \ bostan_mori(const FormalPowerSeries<mint>& a, const FormalPowerSeries<mint>&\
    \ c, ll k) {\n    if(k < (int)a.size()) return a[k];\n    assert(a.size() >= c.size());\n\
    \    FormalPowerSeries<mint> q = FormalPowerSeries<mint>{1} - (c << 1);\n    FormalPowerSeries<mint>\
    \ p = (a * q).pre((int)c.size());\n    while(k > 0) {\n        auto q2 = q;\n\
    \        for(int i = 1; i < (int)q2.size(); i += 2) q2[i] = -q2[i];\n        auto\
    \ s = p * q2;\n        auto t = q * q2;\n        if(k & 1) {\n            for(int\
    \ i = 1; i < (int)s.size(); i += 2) p[i >> 1] = s[i];\n            for(int i =\
    \ 0; i < (int)t.size(); i += 2) q[i >> 1] = t[i];\n        } else {\n        \
    \    for(int i = 0; i < (int)s.size(); i += 2) p[i >> 1] = s[i];\n           \
    \ for(int i = 0; i < (int)t.size(); i += 2) q[i >> 1] = t[i];\n        }\n   \
    \     k >>= 1;\n    }\n    return p[0];\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <template <typename>\
    \ typename FormalPowerSeries, typename mint>\nmint bostan_mori(const FormalPowerSeries<mint>&\
    \ a, const FormalPowerSeries<mint>& c, ll k) {\n    if(k < (int)a.size()) return\
    \ a[k];\n    assert(a.size() >= c.size());\n    FormalPowerSeries<mint> q = FormalPowerSeries<mint>{1}\
    \ - (c << 1);\n    FormalPowerSeries<mint> p = (a * q).pre((int)c.size());\n \
    \   while(k > 0) {\n        auto q2 = q;\n        for(int i = 1; i < (int)q2.size();\
    \ i += 2) q2[i] = -q2[i];\n        auto s = p * q2;\n        auto t = q * q2;\n\
    \        if(k & 1) {\n            for(int i = 1; i < (int)s.size(); i += 2) p[i\
    \ >> 1] = s[i];\n            for(int i = 0; i < (int)t.size(); i += 2) q[i >>\
    \ 1] = t[i];\n        } else {\n            for(int i = 0; i < (int)s.size();\
    \ i += 2) p[i >> 1] = s[i];\n            for(int i = 0; i < (int)t.size(); i +=\
    \ 2) q[i >> 1] = t[i];\n        }\n        k >>= 1;\n    }\n    return p[0];\n\
    }"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/fps/bostan_mori.hpp
  requiredBy:
  - src/fps/nth_term.hpp
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: src/fps/bostan_mori.hpp
layout: document
redirect_from:
- /library/src/fps/bostan_mori.hpp
- /library/src/fps/bostan_mori.hpp.html
title: src/fps/bostan_mori.hpp
---
