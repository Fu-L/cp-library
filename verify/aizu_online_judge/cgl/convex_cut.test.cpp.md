---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/line_and_segment_2d.hpp
    title: line_and_segment_2d
  - icon: ':heavy_check_mark:'
    path: src/geometry/point_2d.hpp
    title: point_2d
  - icon: ':heavy_check_mark:'
    path: src/geometry/polygon_2d.hpp
    title: polygon_2d
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
    ERROR: '0.00001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C
  bundledCode: "#line 1 \"verify/aizu_online_judge/cgl/convex_cut.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C\"\
    \n#define ERROR 0.00001\n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/geometry/template.hpp\"\
    \nusing Real = long double;\nconst Real EPS = Real(1e-8), PI = acos(Real(-1.0));\n\
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
    \ comp_x);\n    vector<Point> memo(ps.size());\n    auto func = [&](auto& func,\
    \ int l, int r) -> Real {\n        if(r - l <= 1) return Real(1e18);\n       \
    \ int m = (l + r) >> 1;\n        Real x = ps[m].real();\n        Real res = min(func(func,\
    \ l, m), func(func, m, r));\n        inplace_merge(ps.begin() + l, ps.begin()\
    \ + m, ps.begin() + r, comp_y);\n        int cnt = 0;\n        for(int i = l;\
    \ i < r; ++i) {\n            if(abs(ps[i].real() - x) >= res) continue;\n    \
    \        for(int j = 0; j < cnt; ++j) {\n                Point d = ps[i] - memo[cnt\
    \ - j - 1];\n                if(d.imag() >= res) break;\n                res =\
    \ min(res, abs(d));\n            }\n            memo[cnt++] = ps[i];\n       \
    \ }\n        return res;\n    };\n    return func(func, 0, (int)ps.size());\n\
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
    \ s, const Line& l) {\n    return dist_ls(l, s);\n}\n#line 6 \"src/geometry/polygon_2d.hpp\"\
    \nReal area(const vector<Point>& polygon) {\n    Real res = 0.0;\n    const int\
    \ n = (int)polygon.size();\n    for(int i = 0; i < n; ++i) {\n        res += cross(polygon[i],\
    \ polygon[(i + 1) % n]);\n    }\n    return abs(res * 0.5);\n}\nbool is_convex(const\
    \ vector<Point>& polygon) {\n    const int n = (int)polygon.size();\n    for(int\
    \ i = 0; i < n; ++i) {\n        if(ccw(polygon[(i - 1 + n) % n], polygon[i], polygon[(i\
    \ + 1) % n]) == -1) return false;\n    }\n    return true;\n}\nint in_polygon(const\
    \ vector<Point>& polygon, const Point& p) {\n    const int n = (int)polygon.size();\n\
    \    int ret = 0;\n    for(int i = 0; i < n; ++i) {\n        Point a = polygon[i]\
    \ - p, b = polygon[(i + 1) % n] - p;\n        if(eq(cross(a, b), 0.0) and sign(dot(a,\
    \ b)) <= 0) return 1;\n        if(a.imag() > b.imag()) swap(a, b);\n        if(sign(a.imag())\
    \ <= 0 and sign(b.imag()) == 1 and sign(cross(a, b)) == 1) ret ^= 2;\n    }\n\
    \    return ret;\n}\nvector<Point> convex_hull(vector<Point> ps) {\n    sort(ps.begin(),\
    \ ps.end(), comp_x);\n    ps.erase(unique(ps.begin(), ps.end()), ps.end());\n\
    \    int n = (int)ps.size(), k = 0;\n    if(n == 1) return ps;\n    vector<Point>\
    \ ch(2 * n);\n    for(int i = 0; i < n; ch[k++] = ps[i++]) {\n        while(k\
    \ >= 2 and sign(cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1])) == -1) {\n  \
    \          --k;\n        }\n    }\n    for(int i = n - 2, t = k + 1; i >= 0; ch[k++]\
    \ = ps[i--]) {\n        while(k >= t and sign(cross(ch[k - 1] - ch[k - 2], ps[i]\
    \ - ch[k - 1])) == -1) {\n            --k;\n        }\n    }\n    ch.resize(k\
    \ - 1);\n    return ch;\n}\nReal convex_diameter(const vector<Point>& polygon)\
    \ {\n    int n = (int)polygon.size(), is = 0, js = 0;\n    for(int i = 1; i <\
    \ n; ++i) {\n        if(sign(polygon[i].imag() - polygon[is].imag()) == 1) is\
    \ = i;\n        if(sign(polygon[i].imag() - polygon[js].imag()) == -1) js = i;\n\
    \    }\n    Real maxdis = norm(polygon[is] - polygon[js]);\n    int i = is, j\
    \ = js;\n    do {\n        if(sign(cross(polygon[(i + 1) % n] - polygon[i], polygon[(j\
    \ + 1) % n] - polygon[j])) >= 0) {\n            j = (j + 1) % n;\n        } else\
    \ {\n            i = (i + 1) % n;\n        }\n        if(norm(polygon[i] - polygon[j])\
    \ > maxdis) {\n            maxdis = norm(polygon[i] - polygon[j]);\n        }\n\
    \    } while(i != is or j != js);\n    return sqrt(maxdis);\n}\nvector<Point>\
    \ convex_cut(const vector<Point>& polygon, const Line& l) {\n    const int n =\
    \ (int)polygon.size();\n    vector<Point> res;\n    for(int i = 0; i < n; ++i)\
    \ {\n        const Point cur = polygon[i], nex = polygon[(i + 1) % n];\n     \
    \   if(ccw(l.a, l.b, cur) != -1) res.emplace_back(cur);\n        if(ccw(l.a, l.b,\
    \ cur) * ccw(l.a, l.b, nex) < 0) {\n            res.emplace_back(intersection_ll(Line(cur,\
    \ nex), l)[0]);\n        }\n    }\n    return res;\n}\n#line 7 \"verify/aizu_online_judge/cgl/convex_cut.test.cpp\"\
    \nint main(void) {\n    int n;\n    cin >> n;\n    vector<Point> polygon(n);\n\
    \    rep(i, 0, n) {\n        cin >> polygon[i];\n    }\n    int q;\n    cin >>\
    \ q;\n    while(q--) {\n        Point p1, p2;\n        cin >> p1 >> p2;\n    \
    \    Line l = Line(p1, p2);\n        vector<Point> cut = convex_cut(polygon, l);\n\
    \        cout << area(cut) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C\"\
    \n#define ERROR 0.00001\n#include \"../../../src/template/template.hpp\"\n#include\
    \ \"../../../src/geometry/template.hpp\"\n#include \"../../../src/geometry/point_2d.hpp\"\
    \n#include \"../../../src/geometry/polygon_2d.hpp\"\nint main(void) {\n    int\
    \ n;\n    cin >> n;\n    vector<Point> polygon(n);\n    rep(i, 0, n) {\n     \
    \   cin >> polygon[i];\n    }\n    int q;\n    cin >> q;\n    while(q--) {\n \
    \       Point p1, p2;\n        cin >> p1 >> p2;\n        Line l = Line(p1, p2);\n\
    \        vector<Point> cut = convex_cut(polygon, l);\n        cout << area(cut)\
    \ << '\\n';\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/geometry/template.hpp
  - src/geometry/point_2d.hpp
  - src/geometry/polygon_2d.hpp
  - src/geometry/line_and_segment_2d.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/cgl/convex_cut.test.cpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/cgl/convex_cut.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/cgl/convex_cut.test.cpp
- /verify/verify/aizu_online_judge/cgl/convex_cut.test.cpp.html
title: verify/aizu_online_judge/cgl/convex_cut.test.cpp
---
