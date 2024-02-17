#pragma once
#include "../template/template.hpp"
#include "./template.hpp"
#include "./point_2d.hpp"
struct Line {
    Point a, b;
    Line() = default;
    Line(const Point& a, const Point& b)
        : a(a), b(b) {}
};
using Segment = Line;
bool is_parallel(const Line& a, const Line& b) {
    return eq(cross(a.b - a.a, b.b - b.a), 0.0);
}
bool is_orthogonal(const Line& a, const Line& b) {
    return eq(dot(a.b - a.a, b.b - b.a), 0.0);
}
Point projection(const Line& l, const Point& p) {
    Real t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);
    return l.a + (l.b - l.a) * t;
}
Point reflection(const Line& l, const Point& p) {
    return p + (projection(l, p) - p) * 2.0;
}
bool is_intersect_lp(const Line& l, const Point& p) {
    return abs(ccw(l.a, l.b, p)) != 1;
}
bool is_intersect_sp(const Segment& s, const Point& p) {
    return ccw(s.a, s.b, p) == 0;
}
bool is_intersect_ll(const Line& l1, const Line& l2) {
    if(!eq(cross(l1.b - l1.a, l2.b - l2.a), 0.0)) return true;
    return eq(cross(l1.b - l1.a, l2.b - l1.a), 0.0);
}
bool is_intersect_ls(const Line& l, const Segment& s) {
    return sign(cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a)) <= 0;
}
bool is_intersect_sl(const Segment& s, const Line& l) {
    return is_intersect_ls(l, s);
}
bool is_intersect_ss(const Segment& s1, const Segment& s2) {
    if(ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b) > 0) return false;
    return ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b) <= 0;
}
vector<Point> intersection_ll(const Line& l1, const Line& l2) {
    vector<Point> res;
    if(!is_intersect_ll(l1, l2)) return res;
    Real a = cross(l1.b - l1.a, l2.b - l2.a);
    Real b = cross(l1.b - l1.a, l1.b - l2.a);
    if(eq(a, 0.0) and eq(b, 0.0)) {
        res.push_back(l2.a);
    } else {
        res.push_back(l2.a + (l2.b - l2.a) * b / a);
    }
    return res;
}
vector<Point> intersection_ss(const Segment& s1, const Segment& s2) {
    return is_intersect_ss(s1, s2) ? intersection_ll(Line(s1), Line(s2)) : vector<Point>();
}
Real dist_lp(const Line& l, const Point& p) {
    return abs(p - projection(l, p));
}
Real dist_sp(const Segment& s, const Point& p) {
    Point h = projection(s, p);
    if(is_intersect_sp(s, h)) return abs(h - p);
    return min(abs(s.a - p), abs(s.b - p));
}
Real dist_ll(const Line& l1, const Line& l2) {
    if(is_intersect_ll(l1, l2)) return 0.0;
    return dist_lp(l1, l2.a);
}
Real dist_ss(const Segment& s1, const Segment& s2) {
    if(is_intersect_ss(s1, s2)) return 0.0;
    return min({dist_sp(s1, s2.a), dist_sp(s1, s2.b), dist_sp(s2, s1.a), dist_sp(s2, s1.b)});
}
Real dist_ls(const Line& l, const Segment& s) {
    if(is_intersect_ls(l, s)) return 0.0;
    return min(dist_lp(l, s.a), dist_lp(l, s.b));
}
Real dist_sl(const Segment& s, const Line& l) {
    return dist_ls(l, s);
}