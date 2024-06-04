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
    const Real d = abs(c1.p - c2.p);
    const int a = sign(d - c1.r - c2.r);
    if(a >= 0) return a + 3;
    return sign(d - c1.r + c2.r) + 1;
}
vector<Point> intersection_cl(const Circle& c, const Line& l) {
    const Point h = projection(l, c.p);
    const Point e = (l.b - l.a) / abs(l.b - l.a);
    vector<Point> res;
    if(!is_intersect_cl(c, l)) return res;
    if(eq(dist_lp(l, c.p), c.r)) {
        res.emplace_back(h);
    } else {
        const Real b = sqrt(c.r * c.r - norm(h - c.p));
        res.emplace_back(h - e * b);
        res.emplace_back(h + e * b);
    }
    return res;
}
vector<Point> intersection_cs(const Circle& c, const Segment& s) {
    const vector<Point> cand = intersection_cl(c, Line(s));
    vector<Point> res;
    for(const Point& p : cand) {
        if(ccw(s.a, s.b, p) == 0) {
            res.emplace_back(p);
        }
    }
    return res;
}
vector<Point> intersection_cc(const Circle& c1, const Circle& c2) {
    const Real d = abs(c1.p - c2.p);
    const Real a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (Real(2.0) * c1.r * d));
    const Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
    vector<Point> res;
    if(is_intersect_cc(c1, c2) % 4 == 0) return res;
    if(eq(a, 0.0)) {
        res.emplace_back(c1.p + rot(Point(c1.r, 0.0), t));
    } else {
        res.emplace_back(c1.p + rot(Point(c1.r, 0.0), t + a));
        res.emplace_back(c1.p + rot(Point(c1.r, 0.0), t - a));
    }
    return res;
}
vector<Point> tangent_cp(const Circle& c, const Point& p) {
    return intersection_cc(c, Circle(p, sqrt(norm(p - c.p) - c.r * c.r)));
}
vector<Line> tangent_cc(Circle c1, Circle c2) {
    vector<Line> res;
    if(c1.r < c2.r) swap(c1, c2);
    const Real r = abs(c2.p - c1.p);
    if(eq(r, 0.0)) return res;
    const Point u = (c2.p - c1.p) / r;
    const Point v = rot(u, PI * 0.5);
    for(const Real s : {Real(1.0), Real(-1.0)}) {
        const Real h = (c1.r + c2.r * s) / r;
        if(eq(abs(h), Real(1.0))) {
            res.emplace_back(c1.p + u * c1.r, c1.p + (u + v) * c1.r);
        } else if(abs(h) < Real(1.0)) {
            const Point uu = u * h, vv = v * sqrt(Real(1.0) - h * h);
            res.emplace_back(c1.p + (uu + vv) * c1.r, c2.p - (uu + vv) * c2.r * s);
            res.emplace_back(c1.p + (uu - vv) * c1.r, c2.p - (uu - vv) * c2.r * s);
        }
    }
    return res;
}
Circle inscribed_circle(const Point& a, const Point& b, const Point& c) {
    const Real A = abs(b - c), B = abs(c - a), C = abs(a - b);
    const Point x = Point((a * A + b * B + c * C) / (A + B + C));
    const Real r = dist_sp(Segment(a, b), x);
    return Circle(x, r);
}
Circle circumscribed_circle(const Point& a, const Point& b, const Point& c) {
    const Point m1((a + b) / 2.0), m2((b + c) / 2.0);
    const Point v((b - a).imag(), (a - b).real()), w((b - c).imag(), (c - b).real());
    const Line s(m1, Point(m1 + v)), t(m2, Point(m2 + w));
    const Point x = intersection_ll(s, t)[0];
    return Circle(x, abs(a - x));
}
Circle appollonius(const Point& p1, const Point& p2, const Real& a, const Real& b) {
    const Point q1 = (p1 * b + p2 * a) / (a + b), q2 = (-p1 * b + p2 * a) / (a - b);
    return Circle((q1 + q2) * 0.5, abs(q1 - q2) * 0.5);
}
Real area_cc(const Circle& c1, const Circle& c2) {
    const Real d = abs(c1.p - c2.p);
    if(c1.r + c2.r <= d + EPS) return 0.0;
    if(d <= abs(c1.r - c2.r) + EPS) {
        const Real r = min(c1.r, c2.r);
        return r * r * PI;
    }
    const Real rc = (d * d + c1.r * c1.r - c2.r * c2.r) / (Real(2.0) * d);
    const Real theta = acos(rc / c1.r);
    const Real phi = acos((d - rc) / c2.r);
    return c1.r * c1.r * theta + c2.r * c2.r * phi - d * c1.r * sin(theta);
}
Real area_pc(const vector<Point>& ps, const Circle& c) {
    auto calc_element = [&](const Point& a, const Point& b, const Real& r, const bool triangle) -> Real {
        if(triangle) return cross(a, b) / 2.0;
        const Point tmp = b * Point(a.real(), -a.imag());
        const Real ang = atan2(tmp.imag(), tmp.real());
        return r * r * ang / 2.0;
    };
    auto cross_area = [&](const Circle& c, const Point& ia, const Point& ib) -> Real {
        const Point a = ia - c.p, b = ib - c.p;
        if(abs(a - b) < EPS) return 0;
        const bool isin_a = (abs(a) < c.r + EPS);
        const bool isin_b = (abs(b) < c.r + EPS);
        if(isin_a and isin_b) return calc_element(a, b, c.r, true);
        const Circle oc(Point(0.0, 0.0), c.r);
        const Segment seg(a, b);
        const vector<Point> cr = intersection_cs(oc, seg);
        if(cr.empty()) return calc_element(a, b, c.r, false);
        const Point s = cr[0], t = cr.back();
        return calc_element(s, t, c.r, true) + calc_element(a, s, c.r, isin_a) + calc_element(t, b, c.r, isin_b);
    };
    const int n = (int)ps.size();
    if(n < 3) return 0.0;
    Real S = 0;
    for(int i = 0; i < n; ++i) {
        S += cross_area(c, ps[i], ps[(i + 1) % n]);
    }
    return S;
}