---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/circle_2d.hpp
    title: src/geometry/circle_2d.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/line_and_segment_2d.hpp
    title: src/geometry/line_and_segment_2d.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/point_2d.hpp
    title: src/geometry/point_2d.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/polygon_2d.hpp
    title: src/geometry/polygon_2d.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/area.test.cpp
    title: verify/aizu_online_judge/cgl/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/counter_clockwise.test.cpp
    title: verify/aizu_online_judge/cgl/counter_clockwise.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/cross_point.test.cpp
    title: verify/aizu_online_judge/cgl/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/distance.test.cpp
    title: verify/aizu_online_judge/cgl/distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/intersection.test.cpp
    title: verify/aizu_online_judge/cgl/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/is_convex.test.cpp
    title: verify/aizu_online_judge/cgl/is_convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/parallel_orthogonal.test.cpp
    title: verify/aizu_online_judge/cgl/parallel_orthogonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/polygon_point_containment.test.cpp
    title: verify/aizu_online_judge/cgl/polygon_point_containment.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/projection.test.cpp
    title: verify/aizu_online_judge/cgl/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/refrection.test.cpp
    title: verify/aizu_online_judge/cgl/refrection.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/geometry/template.hpp\"\
    \nusing Real = long double;\nconst Real EPS = 1e-7, PI = acos(Real(-1.0));\nint\
    \ sign(const Real& r) {\n    if(r <= -EPS) return -1;\n    if(r >= +EPS) return\
    \ +1;\n    return 0;\n}\nbool eq(const Real& a, const Real& b) {\n    return sign(a\
    \ - b) == 0;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nusing Real = long double;\n\
    const Real EPS = 1e-7, PI = acos(Real(-1.0));\nint sign(const Real& r) {\n   \
    \ if(r <= -EPS) return -1;\n    if(r >= +EPS) return +1;\n    return 0;\n}\nbool\
    \ eq(const Real& a, const Real& b) {\n    return sign(a - b) == 0;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/geometry/template.hpp
  requiredBy:
  - src/geometry/point_2d.hpp
  - src/geometry/polygon_2d.hpp
  - src/geometry/circle_2d.hpp
  - src/geometry/line_and_segment_2d.hpp
  timestamp: '2024-02-18 00:45:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/cgl/refrection.test.cpp
  - verify/aizu_online_judge/cgl/polygon_point_containment.test.cpp
  - verify/aizu_online_judge/cgl/is_convex.test.cpp
  - verify/aizu_online_judge/cgl/counter_clockwise.test.cpp
  - verify/aizu_online_judge/cgl/intersection.test.cpp
  - verify/aizu_online_judge/cgl/projection.test.cpp
  - verify/aizu_online_judge/cgl/parallel_orthogonal.test.cpp
  - verify/aizu_online_judge/cgl/cross_point.test.cpp
  - verify/aizu_online_judge/cgl/area.test.cpp
  - verify/aizu_online_judge/cgl/distance.test.cpp
documentation_of: src/geometry/template.hpp
layout: document
redirect_from:
- /library/src/geometry/template.hpp
- /library/src/geometry/template.hpp.html
title: src/geometry/template.hpp
---
