---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/circle_2d.hpp
    title: src/geometry/circle_2d.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/line_and_segment_2d.hpp
    title: src/geometry/line_and_segment_2d.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/point_2d.hpp
    title: src/geometry/point_2d.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/template.hpp
    title: template
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D
  bundledCode: "#line 1 \"verify/aizu_online_judge/cgl/cross_points_of_a_circle_and_a_line.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D\"\
    \n#define ERROR 0.000001\n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
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
    \ func(func, 0, (int)ps.size());\n}\n#line 5 \"src/geometry/line_and_segment_2d.hpp\"\
    \nstruct Line {\n    Point a, b;\n    Line() = default;\n    Line(const Point&\
    \ a, const Point& b)\n        : a(a), b(b) {}\n};\nusing Segment = Line;\nbool\
    \ is_parallel(const Line& a, const Line& b) {\n    return eq(cross(a.b - a.a,\
    \ b.b - b.a), 0.0);\n}\nbool is_orthogonal(const Line& a, const Line& b) {\n \
    \   return eq(dot(a.b - a.a, b.b - b.a), 0.0);\n}\nPoint projection(const Line&\
    \ l, const Point& p) {\n    Real t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);\n\
    \    return l.a + (l.b - l.a) * t;\n}\nPoint reflection(const Line& l, const Point&\
    \ p) {\n    return p + (projection(l, p) - p) * 2.0;\n}\nbool is_intersect_lp(const\
    \ Line& l, const Point& p) {\n    return abs(ccw(l.a, l.b, p)) != 1;\n}\nbool\
    \ is_intersect_sp(const Segment& s, const Point& p) {\n    return ccw(s.a, s.b,\
    \ p) == 0;\n}\nbool is_intersect_ll(const Line& l1, const Line& l2) {\n    if(!eq(cross(l1.b\
    \ - l1.a, l2.b - l2.a), 0.0)) return true;\n    return eq(cross(l1.b - l1.a, l2.b\
    \ - l1.a), 0.0);\n}\nbool is_intersect_ls(const Line& l, const Segment& s) {\n\
    \    return sign(cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a)) <=\
    \ 0;\n}\nbool is_intersect_sl(const Segment& s, const Line& l) {\n    return is_intersect_ls(l,\
    \ s);\n}\nbool is_intersect_ss(const Segment& s1, const Segment& s2) {\n    if(ccw(s1.a,\
    \ s1.b, s2.a) * ccw(s1.a, s1.b, s2.b) > 0) return false;\n    return ccw(s2.a,\
    \ s2.b, s1.a) * ccw(s2.a, s2.b, s1.b) <= 0;\n}\nvector<Point> intersection_ll(const\
    \ Line& l1, const Line& l2) {\n    vector<Point> res;\n    if(!is_intersect_ll(l1,\
    \ l2)) return res;\n    Real a = cross(l1.b - l1.a, l2.b - l2.a);\n    Real b\
    \ = cross(l1.b - l1.a, l1.b - l2.a);\n    if(eq(a, 0.0) and eq(b, 0.0)) {\n  \
    \      res.push_back(l2.a);\n    } else {\n        res.push_back(l2.a + (l2.b\
    \ - l2.a) * b / a);\n    }\n    return res;\n}\nvector<Point> intersection_ss(const\
    \ Segment& s1, const Segment& s2) {\n    return is_intersect_ss(s1, s2) ? intersection_ll(Line(s1),\
    \ Line(s2)) : vector<Point>();\n}\nReal dist_lp(const Line& l, const Point& p)\
    \ {\n    return abs(p - projection(l, p));\n}\nReal dist_sp(const Segment& s,\
    \ const Point& p) {\n    Point h = projection(s, p);\n    if(is_intersect_sp(s,\
    \ h)) return abs(h - p);\n    return min(abs(s.a - p), abs(s.b - p));\n}\nReal\
    \ dist_ll(const Line& l1, const Line& l2) {\n    if(is_intersect_ll(l1, l2)) return\
    \ 0.0;\n    return dist_lp(l1, l2.a);\n}\nReal dist_ss(const Segment& s1, const\
    \ Segment& s2) {\n    if(is_intersect_ss(s1, s2)) return 0.0;\n    return min({dist_sp(s1,\
    \ s2.a), dist_sp(s1, s2.b), dist_sp(s2, s1.a), dist_sp(s2, s1.b)});\n}\nReal dist_ls(const\
    \ Line& l, const Segment& s) {\n    if(is_intersect_ls(l, s)) return 0.0;\n  \
    \  return min(dist_lp(l, s.a), dist_lp(l, s.b));\n}\nReal dist_sl(const Segment&\
    \ s, const Line& l) {\n    return dist_ls(l, s);\n}\n#line 6 \"src/geometry/circle_2d.hpp\"\
    \nstruct Circle {\n    Point p;\n    Real r;\n    Circle() = default;\n    Circle(const\
    \ Point& p, const Real& r)\n        : p(p), r(r) {}\n};\nbool is_intersect_cp(const\
    \ Circle& c, const Point& p) {\n    return eq(abs(p - c.p), c.r);\n}\nbool is_intersect_cl(const\
    \ Circle& c, const Line& l) {\n    return sign(c.r - dist_lp(l, c.p)) >= 0;\n\
    }\nint is_intersect_cc(Circle c1, Circle c2) {\n    if(c1.r < c2.r) swap(c1, c2);\n\
    \    Real d = abs(c1.p - c2.p);\n    int a = sign(d - c1.r - c2.r);\n    if(a\
    \ >= 0) return a + 3;\n    return sign(d - c1.r + c2.r) + 1;\n}\nvector<Point>\
    \ intersection_cl(const Circle& c, const Line& l) {\n    Point h = projection(l,\
    \ c.p);\n    Point e = (l.b - l.a) / abs(l.b - l.a);\n    vector<Point> res;\n\
    \    if(!is_intersect_cl(c, l)) return res;\n    if(eq(dist_lp(l, c.p), c.r))\
    \ {\n        res.push_back(h);\n    } else {\n        Real b = sqrt(c.r * c.r\
    \ - norm(h - c.p));\n        res.push_back(h - e * b);\n        res.push_back(h\
    \ + e * b);\n    }\n    return res;\n}\nvector<Point> intersection_cs(const Circle&\
    \ c, const Segment& s) {\n    vector<Point> cand = intersection_cl(c, Line(s));\n\
    \    vector<Point> res;\n    for(const Point& p : cand) {\n        if(ccw(s.a,\
    \ s.b, p) == 0) {\n            res.push_back(p);\n        }\n    }\n    return\
    \ res;\n}\nvector<Point> intersection_cc(const Circle& c1, const Circle& c2) {\n\
    \    Real d = abs(c1.p - c2.p);\n    Real a = acos((c1.r * c1.r + d * d - c2.r\
    \ * c2.r) / (2 * c1.r * d));\n    Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real()\
    \ - c1.p.real());\n    vector<Point> res;\n    if(is_intersect_cc(c1, c2) % 4\
    \ == 0) return res;\n    if(eq(a, 0.0)) {\n        res.push_back(c1.p + rot(Point(c1.r,\
    \ 0.0), t));\n    } else {\n        res.push_back(c1.p + rot(Point(c1.r, 0.0),\
    \ t + a));\n        res.push_back(c1.p + rot(Point(c1.r, 0.0), t - a));\n    }\n\
    \    return res;\n}\nvector<Point> tangent_cp(const Circle& c, const Point& p)\
    \ {\n    return intersection_cc(c, Circle(p, sqrt(norm(p - c.p) - c.r * c.r)));\n\
    }\nvector<Line> tangent_cc(Circle c1, Circle c2) {\n    vector<Line> res;\n  \
    \  if(c1.r < c2.r) swap(c1, c2);\n    Real r = abs(c2.p - c1.p);\n    if(eq(r,\
    \ 0.0)) return res;\n    Point u = (c2.p - c1.p) / r;\n    Point v = rot(u, PI\
    \ * 0.5);\n    for(Real s : {1.0, -1.0}) {\n        Real h = (c1.r + c2.r * s)\
    \ / r;\n        if(eq(abs(h), 1.0)) {\n            res.push_back({c1.p + u * c1.r,\
    \ c1.p + (u + v) * c1.r});\n        } else if(abs(h) < 1.0) {\n            Point\
    \ uu = u * h, vv = v * sqrt(1.0 - h * h);\n            res.push_back({c1.p + (uu\
    \ + vv) * c1.r, c2.p - (uu + vv) * c2.r * s});\n            res.push_back({c1.p\
    \ + (uu - vv) * c1.r, c2.p - (uu - vv) * c2.r * s});\n        }\n    }\n    return\
    \ res;\n}\nCircle inscribed_circle(const Point& a, const Point& b, const Point&\
    \ c) {\n    Real A = abs(b - c), B = abs(c - a), C = abs(a - b);\n    Point x\
    \ = Point((a * A + b * B + c * C) / (A + B + C));\n    Real r = dist_sp(Segment(a,\
    \ b), x);\n    return Circle(x, r);\n}\nCircle circumscribed_circle(const Point&\
    \ a, const Point& b, const Point& c) {\n    Point m1((a + b) / 2.0), m2((b + c)\
    \ / 2.0);\n    Point v((b - a).imag(), (a - b).real()), w((b - c).imag(), (c -\
    \ b).real());\n    Line s(m1, Point(m1 + v)), t(m2, Point(m2 + w));\n    Point\
    \ x = intersection_ll(s, t)[0];\n    return Circle(x, abs(a - x));\n}\nCircle\
    \ appollonius(const Point& p1, const Point& p2, const Real& a, const Real& b)\
    \ {\n    Point q1 = (p1 * b + p2 * a) / (a + b), q2 = (-p1 * b + p2 * a) / (a\
    \ - b);\n    return Circle((q1 + q2) * 0.5, abs(q1 - q2) * 0.5);\n}\nReal area_cc(const\
    \ Circle& c1, const Circle& c2) {\n    Real d = abs(c1.p - c2.p);\n    if(c1.r\
    \ + c2.r <= d + EPS) return 0.0;\n    if(d <= abs(c1.r - c2.r) + EPS) {\n    \
    \    Real r = min(c1.r, c2.r);\n        return r * r * PI;\n    }\n    Real rc\
    \ = (d * d + c1.r * c1.r - c2.r * c2.r) / (2.0 * d);\n    Real theta = acos(rc\
    \ / c1.r);\n    Real phi = acos((d - rc) / c2.r);\n    return c1.r * c1.r * theta\
    \ + c2.r * c2.r * phi - d * c1.r * sin(theta);\n}\nReal area_pc(const vector<Point>&\
    \ ps, const Circle& c) {\n    auto calc_element = [&](const Point& a, const Point&\
    \ b, Real r, bool triangle) -> Real {\n        if(triangle) return cross(a, b)\
    \ / 2;\n        Point tmp = b * Point(a.real(), -a.imag());\n        Real ang\
    \ = atan2(tmp.imag(), tmp.real());\n        return r * r * ang / 2;\n    };\n\
    \    auto cross_area = [&](const Circle& c, const Point& ia, const Point& ib)\
    \ -> Real {\n        Point a = ia - c.p, b = ib - c.p;\n        if(abs(a - b)\
    \ < EPS) return 0;\n        bool isin_a = (abs(a) < c.r + EPS);\n        bool\
    \ isin_b = (abs(b) < c.r + EPS);\n        if(isin_a and isin_b) return calc_element(a,\
    \ b, c.r, true);\n        Circle oc(Point(0, 0), c.r);\n        Segment seg(a,\
    \ b);\n        auto cr = intersection_cs(oc, seg);\n        if(cr.empty()) return\
    \ calc_element(a, b, c.r, false);\n        auto s = cr[0], t = cr.back();\n  \
    \      return calc_element(s, t, c.r, true) + calc_element(a, s, c.r, isin_a)\
    \ + calc_element(t, b, c.r, isin_b);\n    };\n    int n = ps.size();\n    if(n\
    \ < 3) return 0.0;\n    Real S = 0;\n    for(int i = 0; i < n; ++i) {\n      \
    \  S += cross_area(c, ps[i], ps[(i + 1) % n]);\n    }\n    return S;\n}\n#line\
    \ 8 \"verify/aizu_online_judge/cgl/cross_points_of_a_circle_and_a_line.test.cpp\"\
    \nint main(void) {\n    Circle c;\n    cin >> c.p >> c.r;\n    int q;\n    cin\
    \ >> q;\n    while(q--) {\n        Point p1, p2;\n        cin >> p1 >> p2;\n \
    \       Line l = Line(p1, p2);\n        auto cross_point = intersection_cl(c,\
    \ l);\n        assert(int(cross_point.size()) == 1 or int(cross_point.size())\
    \ == 2);\n        if(int(cross_point.size()) == 1) cross_point.push_back(cross_point[0]);\n\
    \        sort(cross_point.begin(), cross_point.end(), comp_x);\n        cout <<\
    \ cross_point[0] << ' ' << cross_point[1] << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D\"\
    \n#define ERROR 0.000001\n#include \"../../../src/template/template.hpp\"\n#include\
    \ \"../../../src/geometry/template.hpp\"\n#include \"../../../src/geometry/point_2d.hpp\"\
    \n#include \"../../../src/geometry/line_and_segment_2d.hpp\"\n#include \"../../../src/geometry/circle_2d.hpp\"\
    \nint main(void) {\n    Circle c;\n    cin >> c.p >> c.r;\n    int q;\n    cin\
    \ >> q;\n    while(q--) {\n        Point p1, p2;\n        cin >> p1 >> p2;\n \
    \       Line l = Line(p1, p2);\n        auto cross_point = intersection_cl(c,\
    \ l);\n        assert(int(cross_point.size()) == 1 or int(cross_point.size())\
    \ == 2);\n        if(int(cross_point.size()) == 1) cross_point.push_back(cross_point[0]);\n\
    \        sort(cross_point.begin(), cross_point.end(), comp_x);\n        cout <<\
    \ cross_point[0] << ' ' << cross_point[1] << '\\n';\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/geometry/template.hpp
  - src/geometry/point_2d.hpp
  - src/geometry/line_and_segment_2d.hpp
  - src/geometry/circle_2d.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/cgl/cross_points_of_a_circle_and_a_line.test.cpp
  requiredBy: []
  timestamp: '2024-02-18 04:18:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/cgl/cross_points_of_a_circle_and_a_line.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/cgl/cross_points_of_a_circle_and_a_line.test.cpp
- /verify/verify/aizu_online_judge/cgl/cross_points_of_a_circle_and_a_line.test.cpp.html
title: verify/aizu_online_judge/cgl/cross_points_of_a_circle_and_a_line.test.cpp
---
