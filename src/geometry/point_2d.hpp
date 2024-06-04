#pragma once
#include "../template/template.hpp"
#include "./template.hpp"
using Point = complex<Real>;
istream& operator>>(istream& is, Point& p) {
    Real a, b;
    is >> a >> b;
    p = Point(a, b);
    return is;
}
ostream& operator<<(ostream& os, const Point& p) {
    return os << p.real() << " " << p.imag();
}
Point operator*(const Point& p, const Real& d) {
    return Point(p.real() * d, p.imag() * d);
}
Point operator/(const Point& p, const Real& d) {
    return Point(p.real() / d, p.imag() / d);
}
Point rot(const Point& p, const Real& theta) {
    return p * Point(cos(theta), sin(theta));
}
Real dot(const Point& p1, const Point& p2) {
    return (conj(p1) * p2).real();
}
Real cross(const Point& p1, const Point& p2) {
    return (conj(p1) * p2).imag();
}
Real dist(const Point& p1, const Point& p2) {
    return abs(p1 - p2);
}
bool comp_x(const Point& p1, const Point& p2) {
    return eq(p1.real(), p2.real()) ? p1.imag() < p2.imag() : p1.real() < p2.real();
}
bool comp_y(const Point& p1, const Point& p2) {
    return eq(p1.imag(), p2.imag()) ? p1.real() < p2.real() : p1.imag() < p2.imag();
}
bool comp_arg(const Point& p1, const Point& p2) {
    return arg(p1) < arg(p2);
}
int ccw(const Point& a, Point b, Point c) {
    b -= a;
    c -= a;
    if(sign(cross(b, c)) == 1) return 1;
    if(sign(cross(b, c)) == -1) return -1;
    if(sign(dot(b, c)) == -1) return +2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}
Real closest_pair(vector<Point> ps) {
    if((int)ps.size() <= 1) return Real(1e18);
    sort(ps.begin(), ps.end(), comp_x);
    vector<Point> memo(ps.size());
    auto func = [&](auto& func, int l, int r) -> Real {
        if(r - l <= 1) return Real(1e18);
        int m = (l + r) >> 1;
        Real x = ps[m].real();
        Real res = min(func(func, l, m), func(func, m, r));
        inplace_merge(ps.begin() + l, ps.begin() + m, ps.begin() + r, comp_y);
        int cnt = 0;
        for(int i = l; i < r; ++i) {
            if(abs(ps[i].real() - x) >= res) continue;
            for(int j = 0; j < cnt; ++j) {
                Point d = ps[i] - memo[cnt - j - 1];
                if(d.imag() >= res) break;
                res = min(res, abs(d));
            }
            memo[cnt++] = ps[i];
        }
        return res;
    };
    return func(func, 0, (int)ps.size());
}