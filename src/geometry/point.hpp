#pragma once
#include "cp-library/src/template/template.hpp"
const long double pi = acosl(-1);
constexpr long double eps = 1e-7;
struct Point {
    long double x, y;
    Point(long double x = 0, long double y = 0)
        : x(x), y(y) {}
    Point& operator+=(const Point& p) {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point operator+(const Point& p) const {
        return Point(*this) += p;
    }
    Point& operator-=(const Point& p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    Point operator-(const Point& p) const {
        return Point(*this) -= p;
    }
    Point& operator*=(long double s) {
        x *= s;
        y *= s;
        return *this;
    }
    Point operator*(long double s) const {
        return Point(*this) *= s;
    }
    Point& operator/=(long double s) {
        x /= s;
        y /= s;
        return *this;
    }
    Point operator/(long double s) const {
        return Point(*this) /= s;
    }
    long double dot(const Point& p) const {
        return x * p.x + y * p.y;
    }
    long double cross(const Point& p) const {
        return x * p.y - p.x * y;
    }
    long double norm2() const {
        return x * x + y * y;
    }
    long double norm() const {
        return sqrtl(x * x + y * y);
    }
    long double arg() const {
        return atan2l(y, x);
    }
    Point rotate() const {
        return Point(y, -x);
    }
    int ort() const {
        if(abs(x) < eps && abs(y) < eps) return 0;
        if(y > 0) return x > 0 ? 1 : 2;
        else return x > 0 ? 4 : 3;
    }
    inline bool operator<(const Point& p) const {
        long double theta = arg();
        long double ptheta = p.arg();
        return theta < ptheta;
    }
    // inline bool operator<(const Point& p) const {
    //     int o = ort(), po = p.ort();
    //     if(o != po) return o < po;
    //     return cross(p) > 0;
    // }
    // inline bool operator<(const Point& p) const {
    //     if(x != p.x) return x < p.x;
    //     return y < p.y;
    // }
};
vector<Point> ConvexHull(const vector<Point>& ps) {
    int n = (int)ps.size();
    if(n <= 2) return ps;
    vector<Point> res(2 * n);
    int k = 0;
    for(int i = 0; i < n; ++i) {
        while(k > 1 and (res[k - 1] - res[k - 2]).cross(ps[i] - res[k - 1]) <= 0) --k;
        res[k++] = ps[i];
    }
    for(int i = n - 2, t = k; i >= 0; --i) {
        while(k > t and (res[k - 1] - res[k - 2]).cross(ps[i] - res[k - 1]) <= 0) --k;
        res[k++] = ps[i];
    }
    res.resize(k - 1);
    return res;
}