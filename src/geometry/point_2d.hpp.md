---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/template.hpp
    title: template
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/circle_2d.hpp
    title: src/geometry/circle_2d.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/line_and_segment_2d.hpp
    title: src/geometry/line_and_segment_2d.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/polygon_2d.hpp
    title: src/geometry/polygon_2d.hpp
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
    \ - b) == 0;\n}\n#line 4 \"src/geometry/point_2d.hpp\"\nusing Point = complex<Real>;\n\
    istream& operator>>(istream& is, Point& p) {\n    Real a, b;\n    is >> a >> b;\n\
    \    p = Point(a, b);\n    return is;\n}\nostream& operator<<(ostream& os, const\
    \ Point& p) {\n    return os << p.real() << \" \" << p.imag();\n}\nPoint operator*(const\
    \ Point& p, const Real& d) {\n    return Point(p.real() * d, p.imag() * d);\n\
    }\nPoint operator/(const Point& p, const Real& d) {\n    return Point(p.real()\
    \ / d, p.imag() / d);\n}\nPoint rot(const Point& p, Real theta) {\n    return\
    \ p * Point(cos(theta), sin(theta));\n}\nReal dot(const Point& p1, const Point&\
    \ p2) {\n    return (conj(p1) * p2).real();\n}\nReal cross(const Point& p1, const\
    \ Point& p2) {\n    return (conj(p1) * p2).imag();\n}\nReal dist(const Point&\
    \ p1, const Point& p2) {\n    return abs(p1 - p2);\n}\nbool comp_x(const Point&\
    \ p1, const Point& p2) {\n    return eq(p1.real(), p2.real()) ? p1.imag() < p2.imag()\
    \ : p1.real() < p2.real();\n}\nbool comp_y(const Point& p1, const Point& p2) {\n\
    \    return eq(p1.imag(), p2.imag()) ? p1.real() < p2.real() : p1.imag() < p2.imag();\n\
    }\nbool comp_arg(const Point& p1, const Point& p2) {\n    return arg(p1) < arg(p2);\n\
    }\nint ccw(const Point& a, Point b, Point c) {\n    b -= a;\n    c -= a;\n   \
    \ if(sign(cross(b, c)) == 1) return 1;\n    if(sign(cross(b, c)) == -1) return\
    \ -1;\n    if(sign(dot(b, c)) == -1) return +2;\n    if(norm(b) < norm(c)) return\
    \ -2;\n    return 0;\n}\nReal closest_pair(vector<Point> ps) {\n    if((int)ps.size()\
    \ <= 1) return 1e18;\n    sort(ps.begin(), ps.end(), comp_x);\n    vector<Point>\
    \ memo(ps.size());\n    auto func = [&](auto& func, int l, int r) -> Real {\n\
    \        if(r - l <= 1) return 1e18;\n        int m = (l + r) >> 1;\n        Real\
    \ x = ps[m].real();\n        Real res = min(func(func, l, m), func(func, m, r));\n\
    \        inplace_merge(ps.begin() + l, ps.begin() + m, ps.begin() + r, comp_y);\n\
    \        int cnt = 0;\n        for(int i = l; i < r; ++i) {\n            if(abs(ps[i].real()\
    \ - x) >= res) continue;\n            for(int j = 0; j < cnt; ++j) {\n       \
    \         Point d = ps[i] - memo[cnt - j - 1];\n                if(d.imag() >=\
    \ res) break;\n                res = min(res, abs(d));\n            }\n      \
    \      memo[cnt++] = ps[i];\n        }\n        return res;\n    };\n    return\
    \ func(func, 0, (int)ps.size());\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./template.hpp\"\
    \nusing Point = complex<Real>;\nistream& operator>>(istream& is, Point& p) {\n\
    \    Real a, b;\n    is >> a >> b;\n    p = Point(a, b);\n    return is;\n}\n\
    ostream& operator<<(ostream& os, const Point& p) {\n    return os << p.real()\
    \ << \" \" << p.imag();\n}\nPoint operator*(const Point& p, const Real& d) {\n\
    \    return Point(p.real() * d, p.imag() * d);\n}\nPoint operator/(const Point&\
    \ p, const Real& d) {\n    return Point(p.real() / d, p.imag() / d);\n}\nPoint\
    \ rot(const Point& p, Real theta) {\n    return p * Point(cos(theta), sin(theta));\n\
    }\nReal dot(const Point& p1, const Point& p2) {\n    return (conj(p1) * p2).real();\n\
    }\nReal cross(const Point& p1, const Point& p2) {\n    return (conj(p1) * p2).imag();\n\
    }\nReal dist(const Point& p1, const Point& p2) {\n    return abs(p1 - p2);\n}\n\
    bool comp_x(const Point& p1, const Point& p2) {\n    return eq(p1.real(), p2.real())\
    \ ? p1.imag() < p2.imag() : p1.real() < p2.real();\n}\nbool comp_y(const Point&\
    \ p1, const Point& p2) {\n    return eq(p1.imag(), p2.imag()) ? p1.real() < p2.real()\
    \ : p1.imag() < p2.imag();\n}\nbool comp_arg(const Point& p1, const Point& p2)\
    \ {\n    return arg(p1) < arg(p2);\n}\nint ccw(const Point& a, Point b, Point\
    \ c) {\n    b -= a;\n    c -= a;\n    if(sign(cross(b, c)) == 1) return 1;\n \
    \   if(sign(cross(b, c)) == -1) return -1;\n    if(sign(dot(b, c)) == -1) return\
    \ +2;\n    if(norm(b) < norm(c)) return -2;\n    return 0;\n}\nReal closest_pair(vector<Point>\
    \ ps) {\n    if((int)ps.size() <= 1) return 1e18;\n    sort(ps.begin(), ps.end(),\
    \ comp_x);\n    vector<Point> memo(ps.size());\n    auto func = [&](auto& func,\
    \ int l, int r) -> Real {\n        if(r - l <= 1) return 1e18;\n        int m\
    \ = (l + r) >> 1;\n        Real x = ps[m].real();\n        Real res = min(func(func,\
    \ l, m), func(func, m, r));\n        inplace_merge(ps.begin() + l, ps.begin()\
    \ + m, ps.begin() + r, comp_y);\n        int cnt = 0;\n        for(int i = l;\
    \ i < r; ++i) {\n            if(abs(ps[i].real() - x) >= res) continue;\n    \
    \        for(int j = 0; j < cnt; ++j) {\n                Point d = ps[i] - memo[cnt\
    \ - j - 1];\n                if(d.imag() >= res) break;\n                res =\
    \ min(res, abs(d));\n            }\n            memo[cnt++] = ps[i];\n       \
    \ }\n        return res;\n    };\n    return func(func, 0, (int)ps.size());\n}"
  dependsOn:
  - src/template/template.hpp
  - src/geometry/template.hpp
  isVerificationFile: false
  path: src/geometry/point_2d.hpp
  requiredBy:
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
documentation_of: src/geometry/point_2d.hpp
layout: document
redirect_from:
- /library/src/geometry/point_2d.hpp
- /library/src/geometry/point_2d.hpp.html
title: src/geometry/point_2d.hpp
---
