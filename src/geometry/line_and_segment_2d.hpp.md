---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/point_2d.hpp
    title: point_2d
  - icon: ':heavy_check_mark:'
    path: src/geometry/template.hpp
    title: template
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/circle_2d.hpp
    title: circle_2d
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
    path: verify/aizu_online_judge/cgl/common_tangent.test.cpp
    title: verify/aizu_online_judge/cgl/common_tangent.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/convex_cut.test.cpp
    title: verify/aizu_online_judge/cgl/convex_cut.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/cgl/convex_hull.test.cpp
    title: verify/aizu_online_judge/cgl/convex_hull.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/geometry/template.hpp\"\
    \nusing Real = long double;\nconstexpr Real EPS = Real(1e-8), PI = 3.141592653589793238462643383279L;\n\
    int sign(const Real& r) {\n    if(r <= -EPS) return -1;\n    if(r >= +EPS) return\
    \ +1;\n    return 0;\n}\nbool eq(const Real& a, const Real& b) {\n    return sign(a\
    \ - b) == 0;\n}\n#line 4 \"src/geometry/point_2d.hpp\"\nusing Point = complex<Real>;\n\
    istream& operator>>(istream& is, Point& p) {\n    Real a, b;\n    is >> a >> b;\n\
    \    p = Point(a, b);\n    return is;\n}\nostream& operator<<(ostream& os, const\
    \ Point& p) {\n    return os << p.real() << \" \" << p.imag();\n}\nPoint operator*(const\
    \ Point& p, const Real& d) {\n    return Point(p.real() * d, p.imag() * d);\n\
    }\nPoint operator/(const Point& p, const Real& d) {\n    return Point(p.real()\
    \ / d, p.imag() / d);\n}\nPoint rot(const Point& p, const Real& theta) {\n   \
    \ return p * Point(cos(theta), sin(theta));\n}\nReal dot(const Point& p1, const\
    \ Point& p2) {\n    return (conj(p1) * p2).real();\n}\nReal cross(const Point&\
    \ p1, const Point& p2) {\n    return (conj(p1) * p2).imag();\n}\nReal dist(const\
    \ Point& p1, const Point& p2) {\n    return abs(p1 - p2);\n}\nbool comp_x(const\
    \ Point& p1, const Point& p2) {\n    return eq(p1.real(), p2.real()) ? p1.imag()\
    \ < p2.imag() : p1.real() < p2.real();\n}\nbool comp_y(const Point& p1, const\
    \ Point& p2) {\n    return eq(p1.imag(), p2.imag()) ? p1.real() < p2.real() :\
    \ p1.imag() < p2.imag();\n}\nbool comp_arg(const Point& p1, const Point& p2) {\n\
    \    return arg(p1) < arg(p2);\n}\nint ccw(const Point& a, Point b, Point c) {\n\
    \    b -= a;\n    c -= a;\n    if(sign(cross(b, c)) == 1) return 1;\n    if(sign(cross(b,\
    \ c)) == -1) return -1;\n    if(sign(dot(b, c)) == -1) return +2;\n    if(norm(b)\
    \ < norm(c)) return -2;\n    return 0;\n}\nReal closest_pair(vector<Point> ps)\
    \ {\n    if((int)ps.size() <= 1) return Real(1e18);\n    sort(ps.begin(), ps.end(),\
    \ comp_x);\n    vector<Point> memo(ps.size());\n    auto func = [&](const auto&\
    \ func, const int l, const int r) -> Real {\n        if(r - l <= 1) return Real(1e18);\n\
    \        const int m = (l + r) >> 1;\n        const Real x = ps[m].real();\n \
    \       Real res = min(func(func, l, m), func(func, m, r));\n        inplace_merge(ps.begin()\
    \ + l, ps.begin() + m, ps.begin() + r, comp_y);\n        int cnt = 0;\n      \
    \  for(int i = l; i < r; ++i) {\n            if(abs(ps[i].real() - x) >= res)\
    \ continue;\n            for(int j = 0; j < cnt; ++j) {\n                const\
    \ Point d = ps[i] - memo[cnt - j - 1];\n                if(d.imag() >= res) break;\n\
    \                res = min(res, abs(d));\n            }\n            memo[cnt++]\
    \ = ps[i];\n        }\n        return res;\n    };\n    return func(func, 0, (int)ps.size());\n\
    }\n#line 5 \"src/geometry/line_and_segment_2d.hpp\"\nstruct Line {\n    Point\
    \ a, b;\n    Line() = default;\n    Line(const Point& a, const Point& b)\n   \
    \     : a(a), b(b) {}\n};\nusing Segment = Line;\nbool is_parallel(const Line&\
    \ a, const Line& b) {\n    return eq(cross(a.b - a.a, b.b - b.a), 0.0);\n}\nbool\
    \ is_orthogonal(const Line& a, const Line& b) {\n    return eq(dot(a.b - a.a,\
    \ b.b - b.a), 0.0);\n}\nPoint projection(const Line& l, const Point& p) {\n  \
    \  Real t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);\n    return l.a + (l.b\
    \ - l.a) * t;\n}\nPoint reflection(const Line& l, const Point& p) {\n    return\
    \ p + (projection(l, p) - p) * 2.0;\n}\nbool is_intersect_lp(const Line& l, const\
    \ Point& p) {\n    return abs(ccw(l.a, l.b, p)) != 1;\n}\nbool is_intersect_sp(const\
    \ Segment& s, const Point& p) {\n    return ccw(s.a, s.b, p) == 0;\n}\nbool is_intersect_ll(const\
    \ Line& l1, const Line& l2) {\n    if(!eq(cross(l1.b - l1.a, l2.b - l2.a), 0.0))\
    \ return true;\n    return eq(cross(l1.b - l1.a, l2.b - l1.a), 0.0);\n}\nbool\
    \ is_intersect_ls(const Line& l, const Segment& s) {\n    return sign(cross(l.b\
    \ - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a)) <= 0;\n}\nbool is_intersect_sl(const\
    \ Segment& s, const Line& l) {\n    return is_intersect_ls(l, s);\n}\nbool is_intersect_ss(const\
    \ Segment& s1, const Segment& s2) {\n    if(ccw(s1.a, s1.b, s2.a) * ccw(s1.a,\
    \ s1.b, s2.b) > 0) return false;\n    return ccw(s2.a, s2.b, s1.a) * ccw(s2.a,\
    \ s2.b, s1.b) <= 0;\n}\nvector<Point> intersection_ll(const Line& l1, const Line&\
    \ l2) {\n    vector<Point> res;\n    if(!is_intersect_ll(l1, l2)) return res;\n\
    \    Real a = cross(l1.b - l1.a, l2.b - l2.a);\n    Real b = cross(l1.b - l1.a,\
    \ l1.b - l2.a);\n    if(eq(a, 0.0) and eq(b, 0.0)) {\n        res.emplace_back(l2.a);\n\
    \    } else {\n        res.emplace_back(l2.a + (l2.b - l2.a) * b / a);\n    }\n\
    \    return res;\n}\nvector<Point> intersection_ss(const Segment& s1, const Segment&\
    \ s2) {\n    return is_intersect_ss(s1, s2) ? intersection_ll(Line(s1), Line(s2))\
    \ : vector<Point>();\n}\nReal dist_lp(const Line& l, const Point& p) {\n    return\
    \ abs(p - projection(l, p));\n}\nReal dist_sp(const Segment& s, const Point& p)\
    \ {\n    const Point h = projection(s, p);\n    if(is_intersect_sp(s, h)) return\
    \ abs(h - p);\n    return min(abs(s.a - p), abs(s.b - p));\n}\nReal dist_ll(const\
    \ Line& l1, const Line& l2) {\n    if(is_intersect_ll(l1, l2)) return 0.0;\n \
    \   return dist_lp(l1, l2.a);\n}\nReal dist_ss(const Segment& s1, const Segment&\
    \ s2) {\n    if(is_intersect_ss(s1, s2)) return 0.0;\n    return min({dist_sp(s1,\
    \ s2.a), dist_sp(s1, s2.b), dist_sp(s2, s1.a), dist_sp(s2, s1.b)});\n}\nReal dist_ls(const\
    \ Line& l, const Segment& s) {\n    if(is_intersect_ls(l, s)) return 0.0;\n  \
    \  return min(dist_lp(l, s.a), dist_lp(l, s.b));\n}\nReal dist_sl(const Segment&\
    \ s, const Line& l) {\n    return dist_ls(l, s);\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./template.hpp\"\
    \n#include \"./point_2d.hpp\"\nstruct Line {\n    Point a, b;\n    Line() = default;\n\
    \    Line(const Point& a, const Point& b)\n        : a(a), b(b) {}\n};\nusing\
    \ Segment = Line;\nbool is_parallel(const Line& a, const Line& b) {\n    return\
    \ eq(cross(a.b - a.a, b.b - b.a), 0.0);\n}\nbool is_orthogonal(const Line& a,\
    \ const Line& b) {\n    return eq(dot(a.b - a.a, b.b - b.a), 0.0);\n}\nPoint projection(const\
    \ Line& l, const Point& p) {\n    Real t = dot(p - l.a, l.b - l.a) / norm(l.b\
    \ - l.a);\n    return l.a + (l.b - l.a) * t;\n}\nPoint reflection(const Line&\
    \ l, const Point& p) {\n    return p + (projection(l, p) - p) * 2.0;\n}\nbool\
    \ is_intersect_lp(const Line& l, const Point& p) {\n    return abs(ccw(l.a, l.b,\
    \ p)) != 1;\n}\nbool is_intersect_sp(const Segment& s, const Point& p) {\n   \
    \ return ccw(s.a, s.b, p) == 0;\n}\nbool is_intersect_ll(const Line& l1, const\
    \ Line& l2) {\n    if(!eq(cross(l1.b - l1.a, l2.b - l2.a), 0.0)) return true;\n\
    \    return eq(cross(l1.b - l1.a, l2.b - l1.a), 0.0);\n}\nbool is_intersect_ls(const\
    \ Line& l, const Segment& s) {\n    return sign(cross(l.b - l.a, s.a - l.a) *\
    \ cross(l.b - l.a, s.b - l.a)) <= 0;\n}\nbool is_intersect_sl(const Segment& s,\
    \ const Line& l) {\n    return is_intersect_ls(l, s);\n}\nbool is_intersect_ss(const\
    \ Segment& s1, const Segment& s2) {\n    if(ccw(s1.a, s1.b, s2.a) * ccw(s1.a,\
    \ s1.b, s2.b) > 0) return false;\n    return ccw(s2.a, s2.b, s1.a) * ccw(s2.a,\
    \ s2.b, s1.b) <= 0;\n}\nvector<Point> intersection_ll(const Line& l1, const Line&\
    \ l2) {\n    vector<Point> res;\n    if(!is_intersect_ll(l1, l2)) return res;\n\
    \    Real a = cross(l1.b - l1.a, l2.b - l2.a);\n    Real b = cross(l1.b - l1.a,\
    \ l1.b - l2.a);\n    if(eq(a, 0.0) and eq(b, 0.0)) {\n        res.emplace_back(l2.a);\n\
    \    } else {\n        res.emplace_back(l2.a + (l2.b - l2.a) * b / a);\n    }\n\
    \    return res;\n}\nvector<Point> intersection_ss(const Segment& s1, const Segment&\
    \ s2) {\n    return is_intersect_ss(s1, s2) ? intersection_ll(Line(s1), Line(s2))\
    \ : vector<Point>();\n}\nReal dist_lp(const Line& l, const Point& p) {\n    return\
    \ abs(p - projection(l, p));\n}\nReal dist_sp(const Segment& s, const Point& p)\
    \ {\n    const Point h = projection(s, p);\n    if(is_intersect_sp(s, h)) return\
    \ abs(h - p);\n    return min(abs(s.a - p), abs(s.b - p));\n}\nReal dist_ll(const\
    \ Line& l1, const Line& l2) {\n    if(is_intersect_ll(l1, l2)) return 0.0;\n \
    \   return dist_lp(l1, l2.a);\n}\nReal dist_ss(const Segment& s1, const Segment&\
    \ s2) {\n    if(is_intersect_ss(s1, s2)) return 0.0;\n    return min({dist_sp(s1,\
    \ s2.a), dist_sp(s1, s2.b), dist_sp(s2, s1.a), dist_sp(s2, s1.b)});\n}\nReal dist_ls(const\
    \ Line& l, const Segment& s) {\n    if(is_intersect_ls(l, s)) return 0.0;\n  \
    \  return min(dist_lp(l, s.a), dist_lp(l, s.b));\n}\nReal dist_sl(const Segment&\
    \ s, const Line& l) {\n    return dist_ls(l, s);\n}"
  dependsOn:
  - src/template/template.hpp
  - src/geometry/template.hpp
  - src/geometry/point_2d.hpp
  isVerificationFile: false
  path: src/geometry/line_and_segment_2d.hpp
  requiredBy:
  - src/geometry/polygon_2d.hpp
  - src/geometry/circle_2d.hpp
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/cgl/reflection.test.cpp
  - verify/aizu_online_judge/cgl/cross_points_of_circles.test.cpp
  - verify/aizu_online_judge/cgl/area_of_intersection_between_two_circles.test.cpp
  - verify/aizu_online_judge/cgl/convex_cut.test.cpp
  - verify/aizu_online_judge/cgl/cross_point.test.cpp
  - verify/aizu_online_judge/cgl/is_convex.test.cpp
  - verify/aizu_online_judge/cgl/intersection_circle.test.cpp
  - verify/aizu_online_judge/cgl/intersection_of_a_circle_and_a_polygon.test.cpp
  - verify/aizu_online_judge/cgl/projection.test.cpp
  - verify/aizu_online_judge/cgl/cross_points_of_a_circle_and_a_line.test.cpp
  - verify/aizu_online_judge/cgl/tangent_to_a_circle.test.cpp
  - verify/aizu_online_judge/cgl/polygon_point_containment.test.cpp
  - verify/aizu_online_judge/cgl/incircle_of_a_triangle.test.cpp
  - verify/aizu_online_judge/cgl/area.test.cpp
  - verify/aizu_online_judge/cgl/convex_hull.test.cpp
  - verify/aizu_online_judge/cgl/diameter_of_a_convex_polygon.test.cpp
  - verify/aizu_online_judge/cgl/parallel_orthogonal.test.cpp
  - verify/aizu_online_judge/cgl/common_tangent.test.cpp
  - verify/aizu_online_judge/cgl/distance.test.cpp
  - verify/aizu_online_judge/cgl/intersection.test.cpp
  - verify/aizu_online_judge/cgl/circumscribed_circle_of_a_triangle.test.cpp
documentation_of: src/geometry/line_and_segment_2d.hpp
layout: document
title: line_and_segment_2d
---

# Line, Segment

直線および線分を扱う構造体です．

## コンストラクタ

```cpp
(1) Line l(Point a, Point b)
(2) Segment s(Point a, Point b)
```

(1): $2$ 点 `a, b` を通る直線 `l` を作ります．<br>
(2): $2$ 点 `a, b` を端点とする線分 `s` を作ります．

## is_parallel, is_orthogonal

```cpp
(1) bool is_parallel(Line a, Line b)
(2) bool is_orthogonal(Line a, Line b)
```

(1): $2$ 直線 `a, b` が平行であるかどうか判定します．<br>
(2): $2$ 直線 `a, b` が直交するかどうか判定します．

## projection, reflection

```cpp
(1) Point projection(Line l, Point p)
(2) Point reflection(Line l, Point p)
```

(1): 点 `p` から直線 `l` に下ろした垂線の足の座標を返します．<br>
(2): 直線 `l` を対称軸として点 `p` と線対称の位置にある点の座標を返します．

## is_intersect_lp, is_intersect_sp, is_intersect_ll, is_intersect_ls, is_intersect_sl, is_intersect_ss

```cpp
(1) bool is_intersect_lp(Line l, Point p)
(2) bool is_intersect_sp(Segment s, Point p)
(3) bool is_intersect_ll(Line l1, Line l2)
(4) bool is_intersect_ls(Line l, Segment s)
(5) bool is_intersect_sl(Segment s, Line l)
(6) bool is_intersect_ss(Segment s1, Segment s2)
```

(1): 直線 `l` と点 `p` が交点を持つかどうか判定します．<br>
(2): 線分 `s` と点 `p` が交点を持つかどうか判定します．<br>
(3): 直線 `l1` と直線 `l2` が交点を持つかどうか判定します．<br>
(4): 直線 `l` と線分 `s` が交点を持つかどうか判定します．<br>
(5): 線分 `s` と直線 `l` が交点を持つかどうか判定します．<br>
(6): 線分 `s1` と線分 `s2` が交点を持つかどうか判定します．

## intersection_ll, intersection_ss

```cpp
(1) vector<Point> intersection_ll(Line l1, Line l2)
(2) vector<Point> intersection_ss(Segment s1, Segment s2)
```

(1): 直線 `l1` と直線 `l2` の交点を高々 $1$ つ返します．<br>
(2): 線分 `s1` と線分 `s2` の交点を高々 $1$ つ返します．

## dist_lp, dist_sp, dist_ll, dist_ss, dist_ls, dist_sl

```cpp
(1) Real dist_lp(Line l, Point p)
(2) Real dist_sp(Segment s, Point p)
(3) Real dist_ll(Line l1, Line l2)
(4) Real dist_ss(Segment s1, Segment s2)
(5) Real dist_ls(Line l, Segment s)
(6) Real dist_sl(Segment s, Line l)
```

(1): 直線 `l` と点 `p` の距離を返します．<br>
(2): 線分 `s` と点 `p` の距離を返します．<br>
(3): 直線 `l1` と直線 `l2` の距離を返します．<br>
(4): 線分 `s1` と線分 `s2` の距離を返します．<br>
(5): 直線 `l` と線分 `s` の距離を返します．<br>
(6): 線分 `s` と直線 `l` の距離を返します．