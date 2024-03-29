#pragma once
#include "../template/template.hpp"
#include "./template.hpp"
#include "./point_2d.hpp"
#include "./line_and_segment_2d.hpp"
struct Circle {
    Point p;
    Real r;
    Circle() = default;
    Circle(const Point& p, const Real& r)
        : p(p), r(r) {}
};
bool is_intersect_cp(const Circle& c, const Point& p) {
    return eq(abs(p - c.p), c.r);
}
bool is_intersect_cl(const Circle& c, const Line& l) {
    return sign(c.r - dist_lp(l, c.p)) >= 0;
}
int is_intersect_cc(Circle c1, Circle c2) {
    if(c1.r < c2.r) swap(c1, c2);
    Real d = abs(c1.p - c2.p);
    int a = sign(d - c1.r - c2.r);
    if(a >= 0) return a + 3;
    return sign(d - c1.r + c2.r) + 1;
}
vector<Point> intersection_cl(const Circle& c, const Line& l) {
    Point h = projection(l, c.p);
    Point e = (l.b - l.a) / abs(l.b - l.a);
    vector<Point> res;
    if(!is_intersect_cl(c, l)) return res;
    if(eq(dist_lp(l, c.p), c.r)) {
        res.push_back(h);
    } else {
        Real b = sqrt(c.r * c.r - norm(h - c.p));
        res.push_back(h - e * b);
        res.push_back(h + e * b);
    }
    return res;
}
vector<Point> intersection_cs(const Circle& c, const Segment& s) {
    vector<Point> cand = intersection_cl(c, Line(s));
    vector<Point> res;
    for(const Point& p : cand) {
        if(ccw(s.a, s.b, p) == 0) {
            res.push_back(p);
        }
    }
    return res;
}
vector<Point> intersection_cc(const Circle& c1, const Circle& c2) {
    Real d = abs(c1.p - c2.p);
    Real a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
    vector<Point> res;
    if(is_intersect_cc(c1, c2) % 4 == 0) return res;
    if(eq(a, 0.0)) {
        res.push_back(c1.p + rot(Point(c1.r, 0.0), t));
    } else {
        res.push_back(c1.p + rot(Point(c1.r, 0.0), t + a));
        res.push_back(c1.p + rot(Point(c1.r, 0.0), t - a));
    }
    return res;
}
vector<Point> tangent_cp(const Circle& c, const Point& p) {
    return intersection_cc(c, Circle(p, sqrt(norm(p - c.p) - c.r * c.r)));
}
vector<Line> tangent_cc(Circle c1, Circle c2) {
    vector<Line> res;
    if(c1.r < c2.r) swap(c1, c2);
    Real r = abs(c2.p - c1.p);
    if(eq(r, 0.0)) return res;
    Point u = (c2.p - c1.p) / r;
    Point v = rot(u, PI * 0.5);
    for(Real s : {1.0, -1.0}) {
        Real h = (c1.r + c2.r * s) / r;
        if(eq(abs(h), 1.0)) {
            res.push_back({c1.p + u * c1.r, c1.p + (u + v) * c1.r});
        } else if(abs(h) < 1.0) {
            Point uu = u * h, vv = v * sqrt(1.0 - h * h);
            res.push_back({c1.p + (uu + vv) * c1.r, c2.p - (uu + vv) * c2.r * s});
            res.push_back({c1.p + (uu - vv) * c1.r, c2.p - (uu - vv) * c2.r * s});
        }
    }
    return res;
}
Circle inscribed_circle(const Point& a, const Point& b, const Point& c) {
    Real A = abs(b - c), B = abs(c - a), C = abs(a - b);
    Point x = Point((a * A + b * B + c * C) / (A + B + C));
    Real r = dist_sp(Segment(a, b), x);
    return Circle(x, r);
}
Circle circumscribed_circle(const Point& a, const Point& b, const Point& c) {
    Point m1((a + b) / 2.0), m2((b + c) / 2.0);
    Point v((b - a).imag(), (a - b).real()), w((b - c).imag(), (c - b).real());
    Line s(m1, Point(m1 + v)), t(m2, Point(m2 + w));
    Point x = intersection_ll(s, t)[0];
    return Circle(x, abs(a - x));
}
Circle appollonius(const Point& p1, const Point& p2, const Real& a, const Real& b) {
    Point q1 = (p1 * b + p2 * a) / (a + b), q2 = (-p1 * b + p2 * a) / (a - b);
    return Circle((q1 + q2) * 0.5, abs(q1 - q2) * 0.5);
}
Real area_cc(const Circle& c1, const Circle& c2) {
    Real d = abs(c1.p - c2.p);
    if(c1.r + c2.r <= d + EPS) return 0.0;
    if(d <= abs(c1.r - c2.r) + EPS) {
        Real r = min(c1.r, c2.r);
        return r * r * PI;
    }
    Real rc = (d * d + c1.r * c1.r - c2.r * c2.r) / (2.0 * d);
    Real theta = acos(rc / c1.r);
    Real phi = acos((d - rc) / c2.r);
    return c1.r * c1.r * theta + c2.r * c2.r * phi - d * c1.r * sin(theta);
}
Real area_pc(const vector<Point>& ps, const Circle& c) {
    auto calc_element = [&](const Point& a, const Point& b, Real r, bool triangle) -> Real {
        if(triangle) return cross(a, b) / 2;
        Point tmp = b * Point(a.real(), -a.imag());
        Real ang = atan2(tmp.imag(), tmp.real());
        return r * r * ang / 2;
    };
    auto cross_area = [&](const Circle& c, const Point& ia, const Point& ib) -> Real {
        Point a = ia - c.p, b = ib - c.p;
        if(abs(a - b) < EPS) return 0;
        bool isin_a = (abs(a) < c.r + EPS);
        bool isin_b = (abs(b) < c.r + EPS);
        if(isin_a and isin_b) return calc_element(a, b, c.r, true);
        Circle oc(Point(0, 0), c.r);
        Segment seg(a, b);
        auto cr = intersection_cs(oc, seg);
        if(cr.empty()) return calc_element(a, b, c.r, false);
        auto s = cr[0], t = cr.back();
        return calc_element(s, t, c.r, true) + calc_element(a, s, c.r, isin_a) + calc_element(t, b, c.r, isin_b);
    };
    int n = ps.size();
    if(n < 3) return 0.0;
    Real S = 0;
    for(int i = 0; i < n; ++i) {
        S += cross_area(c, ps[i], ps[(i + 1) % n]);
    }
    return S;
}