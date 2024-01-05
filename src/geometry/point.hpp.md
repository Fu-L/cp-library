---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/geometry/point.hpp\"\
    \nconst long double pi = acosl(-1);\nconstexpr long double eps = 1e-7;\nstruct\
    \ Point {\n    long double x, y;\n    Point(long double x = 0, long double y =\
    \ 0)\n        : x(x), y(y) {}\n    Point& operator+=(const Point& p) {\n     \
    \   x += p.x;\n        y += p.y;\n        return *this;\n    }\n    Point operator+(const\
    \ Point& p) const {\n        return Point(*this) += p;\n    }\n    Point& operator-=(const\
    \ Point& p) {\n        x -= p.x;\n        y -= p.y;\n        return *this;\n \
    \   }\n    Point operator-(const Point& p) const {\n        return Point(*this)\
    \ -= p;\n    }\n    Point& operator*=(long double s) {\n        x *= s;\n    \
    \    y *= s;\n        return *this;\n    }\n    Point operator*(long double s)\
    \ const {\n        return Point(*this) *= s;\n    }\n    Point& operator/=(long\
    \ double s) {\n        x /= s;\n        y /= s;\n        return *this;\n    }\n\
    \    Point operator/(long double s) const {\n        return Point(*this) /= s;\n\
    \    }\n    long double dot(const Point& p) const {\n        return x * p.x +\
    \ y * p.y;\n    }\n    long double cross(const Point& p) const {\n        return\
    \ x * p.y - p.x * y;\n    }\n    long double norm2() const {\n        return x\
    \ * x + y * y;\n    }\n    long double norm() const {\n        return sqrtl(x\
    \ * x + y * y);\n    }\n    long double arg() const {\n        return atan2l(y,\
    \ x);\n    }\n    Point rotate() const {\n        return Point(y, -x);\n    }\n\
    \    int ort() const {\n        if(abs(x) < eps && abs(y) < eps) return 0;\n \
    \       if(y > 0) return x > 0 ? 1 : 2;\n        else return x > 0 ? 4 : 3;\n\
    \    }\n    inline bool operator<(const Point& p) const {\n        long double\
    \ theta = arg();\n        long double ptheta = p.arg();\n        return theta\
    \ < ptheta;\n    }\n    // inline bool operator<(const Point& p) const {\n   \
    \ //     int o = ort(), po = p.ort();\n    //     if(o != po) return o < po;\n\
    \    //     return cross(p) > 0;\n    // }\n    // inline bool operator<(const\
    \ Point& p) const {\n    //     if(x != p.x) return x < p.x;\n    //     return\
    \ y < p.y;\n    // }\n};\nvector<Point> ConvexHull(const vector<Point>& ps) {\n\
    \    int n = (int)ps.size();\n    if(n <= 2) return ps;\n    vector<Point> res(2\
    \ * n);\n    int k = 0;\n    for(int i = 0; i < n; ++i) {\n        while(k > 1\
    \ and (res[k - 1] - res[k - 2]).cross(ps[i] - res[k - 1]) <= 0) --k;\n       \
    \ res[k++] = ps[i];\n    }\n    for(int i = n - 2, t = k; i >= 0; --i) {\n   \
    \     while(k > t and (res[k - 1] - res[k - 2]).cross(ps[i] - res[k - 1]) <= 0)\
    \ --k;\n        res[k++] = ps[i];\n    }\n    res.resize(k - 1);\n    return res;\n\
    }\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nconst long double pi\
    \ = acosl(-1);\nconstexpr long double eps = 1e-7;\nstruct Point {\n    long double\
    \ x, y;\n    Point(long double x = 0, long double y = 0)\n        : x(x), y(y)\
    \ {}\n    Point& operator+=(const Point& p) {\n        x += p.x;\n        y +=\
    \ p.y;\n        return *this;\n    }\n    Point operator+(const Point& p) const\
    \ {\n        return Point(*this) += p;\n    }\n    Point& operator-=(const Point&\
    \ p) {\n        x -= p.x;\n        y -= p.y;\n        return *this;\n    }\n \
    \   Point operator-(const Point& p) const {\n        return Point(*this) -= p;\n\
    \    }\n    Point& operator*=(long double s) {\n        x *= s;\n        y *=\
    \ s;\n        return *this;\n    }\n    Point operator*(long double s) const {\n\
    \        return Point(*this) *= s;\n    }\n    Point& operator/=(long double s)\
    \ {\n        x /= s;\n        y /= s;\n        return *this;\n    }\n    Point\
    \ operator/(long double s) const {\n        return Point(*this) /= s;\n    }\n\
    \    long double dot(const Point& p) const {\n        return x * p.x + y * p.y;\n\
    \    }\n    long double cross(const Point& p) const {\n        return x * p.y\
    \ - p.x * y;\n    }\n    long double norm2() const {\n        return x * x + y\
    \ * y;\n    }\n    long double norm() const {\n        return sqrtl(x * x + y\
    \ * y);\n    }\n    long double arg() const {\n        return atan2l(y, x);\n\
    \    }\n    Point rotate() const {\n        return Point(y, -x);\n    }\n    int\
    \ ort() const {\n        if(abs(x) < eps && abs(y) < eps) return 0;\n        if(y\
    \ > 0) return x > 0 ? 1 : 2;\n        else return x > 0 ? 4 : 3;\n    }\n    inline\
    \ bool operator<(const Point& p) const {\n        long double theta = arg();\n\
    \        long double ptheta = p.arg();\n        return theta < ptheta;\n    }\n\
    \    // inline bool operator<(const Point& p) const {\n    //     int o = ort(),\
    \ po = p.ort();\n    //     if(o != po) return o < po;\n    //     return cross(p)\
    \ > 0;\n    // }\n    // inline bool operator<(const Point& p) const {\n    //\
    \     if(x != p.x) return x < p.x;\n    //     return y < p.y;\n    // }\n};\n\
    vector<Point> ConvexHull(const vector<Point>& ps) {\n    int n = (int)ps.size();\n\
    \    if(n <= 2) return ps;\n    vector<Point> res(2 * n);\n    int k = 0;\n  \
    \  for(int i = 0; i < n; ++i) {\n        while(k > 1 and (res[k - 1] - res[k -\
    \ 2]).cross(ps[i] - res[k - 1]) <= 0) --k;\n        res[k++] = ps[i];\n    }\n\
    \    for(int i = n - 2, t = k; i >= 0; --i) {\n        while(k > t and (res[k\
    \ - 1] - res[k - 2]).cross(ps[i] - res[k - 1]) <= 0) --k;\n        res[k++] =\
    \ ps[i];\n    }\n    res.resize(k - 1);\n    return res;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/geometry/point.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/point.hpp
layout: document
title: Point
---
