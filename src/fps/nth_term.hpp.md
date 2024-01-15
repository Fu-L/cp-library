---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/fps/berlekamp_massey.hpp
    title: berlekamp_massey
  - icon: ':heavy_check_mark:'
    path: src/fps/bostan_mori.hpp
    title: src/fps/bostan_mori.hpp
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/1559.test.cpp
    title: verify/yukicoder/1559.test.cpp
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
    \ c.rev();\n    return c;\n}\n#line 3 \"src/fps/bostan_mori.hpp\"\ntemplate <template\
    \ <typename> typename FormalPowerSeries, typename mint>\nmint bostan_mori(const\
    \ FormalPowerSeries<mint>& a, const FormalPowerSeries<mint>& c, ll k) {\n    if(k\
    \ < (int)a.size()) return a[k];\n    assert(a.size() >= c.size());\n    FormalPowerSeries<mint>\
    \ q = FormalPowerSeries<mint>{1} - (c << 1);\n    FormalPowerSeries<mint> p =\
    \ (a * q).pre((int)c.size());\n    while(k > 0) {\n        auto q2 = q;\n    \
    \    for(int i = 1; i < (int)q2.size(); i += 2) q2[i] = -q2[i];\n        auto\
    \ s = p * q2;\n        auto t = q * q2;\n        if(k & 1) {\n            for(int\
    \ i = 1; i < (int)s.size(); i += 2) p[i >> 1] = s[i];\n            for(int i =\
    \ 0; i < (int)t.size(); i += 2) q[i >> 1] = t[i];\n        } else {\n        \
    \    for(int i = 0; i < (int)s.size(); i += 2) p[i >> 1] = s[i];\n           \
    \ for(int i = 0; i < (int)t.size(); i += 2) q[i >> 1] = t[i];\n        }\n   \
    \     k >>= 1;\n    }\n    return p[0];\n}\n#line 5 \"src/fps/nth_term.hpp\"\n\
    template <template <typename> typename FormalPowerSeries, typename mint>\nmint\
    \ nth_term(const FormalPowerSeries<mint>& s, ll n) {\n    FormalPowerSeries<mint>\
    \ c = berlekamp_massey(s);\n    return bostan_mori(s, c, n);\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./berlekamp_massey.hpp\"\
    \n#include \"./bostan_mori.hpp\"\ntemplate <template <typename> typename FormalPowerSeries,\
    \ typename mint>\nmint nth_term(const FormalPowerSeries<mint>& s, ll n) {\n  \
    \  FormalPowerSeries<mint> c = berlekamp_massey(s);\n    return bostan_mori(s,\
    \ c, n);\n}"
  dependsOn:
  - src/template/template.hpp
  - src/fps/berlekamp_massey.hpp
  - src/fps/bostan_mori.hpp
  isVerificationFile: false
  path: src/fps/nth_term.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/1559.test.cpp
documentation_of: src/fps/nth_term.hpp
layout: document
redirect_from:
- /library/src/fps/nth_term.hpp
- /library/src/fps/nth_term.hpp.html
title: src/fps/nth_term.hpp
---
