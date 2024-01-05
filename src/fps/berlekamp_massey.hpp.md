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
    path: verify/library_checker/math/find_linear_recurrence.test.cpp
    title: verify/library_checker/math/find_linear_recurrence.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/fps/berlekamp_massey.hpp\"\
    \ntemplate <template <typename> typename FormalPowerSeries, typename mint>\nFormalPowerSeries<mint>\
    \ berlekamp_massey(const FormalPowerSeries<mint>& s) {\n    const int n = (int)s.size();\n\
    \    FormalPowerSeries<mint> b = {mint(-1)}, c = {mint(-1)};\n    mint y = mint(1);\n\
    \    for(int ed = 1; ed <= n; ++ed) {\n        int l = (int)c.size(), m = (int)b.size();\n\
    \        mint x = 0;\n        for(int i = 0; i < l; ++i) x += c[i] * s[ed - l\
    \ + i];\n        b.emplace_back(0);\n        ++m;\n        if(x == mint(0)) continue;\n\
    \        mint freq = x / y;\n        if(l < m) {\n            auto tmp = c;\n\
    \            c.insert(begin(c), m - l, mint(0));\n            for(int i = 0; i\
    \ < m; ++i) c[m - 1 - i] -= freq * b[m - 1 - i];\n            b = tmp;\n     \
    \       y = x;\n        } else {\n            for(int i = 0; i < m; ++i) c[l -\
    \ 1 - i] -= freq * b[m - 1 - i];\n        }\n    }\n    c.pop_back();\n    c =\
    \ c.rev();\n    return c;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <template <typename>\
    \ typename FormalPowerSeries, typename mint>\nFormalPowerSeries<mint> berlekamp_massey(const\
    \ FormalPowerSeries<mint>& s) {\n    const int n = (int)s.size();\n    FormalPowerSeries<mint>\
    \ b = {mint(-1)}, c = {mint(-1)};\n    mint y = mint(1);\n    for(int ed = 1;\
    \ ed <= n; ++ed) {\n        int l = (int)c.size(), m = (int)b.size();\n      \
    \  mint x = 0;\n        for(int i = 0; i < l; ++i) x += c[i] * s[ed - l + i];\n\
    \        b.emplace_back(0);\n        ++m;\n        if(x == mint(0)) continue;\n\
    \        mint freq = x / y;\n        if(l < m) {\n            auto tmp = c;\n\
    \            c.insert(begin(c), m - l, mint(0));\n            for(int i = 0; i\
    \ < m; ++i) c[m - 1 - i] -= freq * b[m - 1 - i];\n            b = tmp;\n     \
    \       y = x;\n        } else {\n            for(int i = 0; i < m; ++i) c[l -\
    \ 1 - i] -= freq * b[m - 1 - i];\n        }\n    }\n    c.pop_back();\n    c =\
    \ c.rev();\n    return c;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/fps/berlekamp_massey.hpp
  requiredBy:
  - src/fps/nth_term.hpp
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/math/find_linear_recurrence.test.cpp
documentation_of: src/fps/berlekamp_massey.hpp
layout: document
redirect_from:
- /library/src/fps/berlekamp_massey.hpp
- /library/src/fps/berlekamp_massey.hpp.html
title: src/fps/berlekamp_massey.hpp
---
