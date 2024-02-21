---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/circle_2d.hpp
    title: circle_2d
  - icon: ':heavy_check_mark:'
    path: src/geometry/line_and_segment_2d.hpp
    title: src/geometry/line_and_segment_2d.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/point_2d.hpp
    title: point_2d
  - icon: ':heavy_check_mark:'
    path: src/geometry/polygon_2d.hpp
    title: polygon_2d
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/area.test.cpp
    title: verify/aizu_online_judge/cgl/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/area_of_intersection_between_two_circles.test.cpp
    title: verify/aizu_online_judge/cgl/area_of_intersection_between_two_circles.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/circumscribed_circle_of_a_triangle.test.cpp
    title: verify/aizu_online_judge/cgl/circumscribed_circle_of_a_triangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/closest_pair.test.cpp
    title: verify/aizu_online_judge/cgl/closest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/common_tangent.test.cpp
    title: verify/aizu_online_judge/cgl/common_tangent.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/convex_cut.test.cpp
    title: verify/aizu_online_judge/cgl/convex_cut.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/convex_hull.test.cpp
    title: verify/aizu_online_judge/cgl/convex_hull.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/counter_clockwise.test.cpp
    title: verify/aizu_online_judge/cgl/counter_clockwise.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/cross_point.test.cpp
    title: verify/aizu_online_judge/cgl/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/cross_points_of_a_circle_and_a_line.test.cpp
    title: verify/aizu_online_judge/cgl/cross_points_of_a_circle_and_a_line.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/cross_points_of_circles.test.cpp
    title: verify/aizu_online_judge/cgl/cross_points_of_circles.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/diameter_of_a_convex_polygon.test.cpp
    title: verify/aizu_online_judge/cgl/diameter_of_a_convex_polygon.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/distance.test.cpp
    title: verify/aizu_online_judge/cgl/distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/incircle_of_a_triangle.test.cpp
    title: verify/aizu_online_judge/cgl/incircle_of_a_triangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/intersection.test.cpp
    title: verify/aizu_online_judge/cgl/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/intersection_circle.test.cpp
    title: verify/aizu_online_judge/cgl/intersection_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/intersection_of_a_circle_and_a_polygon.test.cpp
    title: verify/aizu_online_judge/cgl/intersection_of_a_circle_and_a_polygon.test.cpp
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
    path: verify/aizu_online_judge/cgl/reflection.test.cpp
    title: verify/aizu_online_judge/cgl/reflection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/tangent_to_a_circle.test.cpp
    title: verify/aizu_online_judge/cgl/tangent_to_a_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/geometry/sort_points_by_argument.test.cpp
    title: verify/library_checker/geometry/sort_points_by_argument.test.cpp
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
    \nusing Real = long double;\nconst Real EPS = 1e-8, PI = acos(Real(-1.0));\nint\
    \ sign(const Real& r) {\n    if(r <= -EPS) return -1;\n    if(r >= +EPS) return\
    \ +1;\n    return 0;\n}\nbool eq(const Real& a, const Real& b) {\n    return sign(a\
    \ - b) == 0;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nusing Real = long double;\n\
    const Real EPS = 1e-8, PI = acos(Real(-1.0));\nint sign(const Real& r) {\n   \
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
  timestamp: '2024-02-18 04:18:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/cgl/convex_hull.test.cpp
  - verify/aizu_online_judge/cgl/polygon_point_containment.test.cpp
  - verify/aizu_online_judge/cgl/is_convex.test.cpp
  - verify/aizu_online_judge/cgl/incircle_of_a_triangle.test.cpp
  - verify/aizu_online_judge/cgl/circumscribed_circle_of_a_triangle.test.cpp
  - verify/aizu_online_judge/cgl/closest_pair.test.cpp
  - verify/aizu_online_judge/cgl/reflection.test.cpp
  - verify/aizu_online_judge/cgl/counter_clockwise.test.cpp
  - verify/aizu_online_judge/cgl/intersection_of_a_circle_and_a_polygon.test.cpp
  - verify/aizu_online_judge/cgl/intersection.test.cpp
  - verify/aizu_online_judge/cgl/intersection_circle.test.cpp
  - verify/aizu_online_judge/cgl/cross_points_of_circles.test.cpp
  - verify/aizu_online_judge/cgl/projection.test.cpp
  - verify/aizu_online_judge/cgl/parallel_orthogonal.test.cpp
  - verify/aizu_online_judge/cgl/common_tangent.test.cpp
  - verify/aizu_online_judge/cgl/cross_point.test.cpp
  - verify/aizu_online_judge/cgl/diameter_of_a_convex_polygon.test.cpp
  - verify/aizu_online_judge/cgl/tangent_to_a_circle.test.cpp
  - verify/aizu_online_judge/cgl/area_of_intersection_between_two_circles.test.cpp
  - verify/aizu_online_judge/cgl/cross_points_of_a_circle_and_a_line.test.cpp
  - verify/aizu_online_judge/cgl/convex_cut.test.cpp
  - verify/aizu_online_judge/cgl/area.test.cpp
  - verify/aizu_online_judge/cgl/distance.test.cpp
  - verify/library_checker/geometry/sort_points_by_argument.test.cpp
documentation_of: src/geometry/template.hpp
layout: document
title: template
---

幾何テンプレートです．

## Real, EPS, PI

`Real` は `long double` のエイリアスです．<br>
必要となる精度や速度次第で `double` に変えて使うこともできます．

`EPS` は $10^{-8}$ を表す `Real` 型の値です．<br>
問題に応じて調整してください．

`PI` は円周率を表す `Real` 型の値です．

## sign

```cpp
int sign(Real x)
```

$x$ の符号を返します．<br>
ただし， $\mathrm{-EPS} \leq x \leq \mathrm{EPS}$ のときに $0$ と判定します．

## eq

```cpp
bool eq(Real a, Real b)
```

$a = b$ であるか判定します．<br>
ただし， $|a - b| \leq \mathrm{EPS}$ であるときに等しいと判定します．