// ベクトル(点)を扱う。
#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const long double eps = 1e-7;
struct V {
    long double x, y;
    V(long double x = 0, long double y = 0)
        : x(x), y(y) {}
    V& operator+=(const V& v) {
        x += v.x;
        y += v.y;
        return *this;
    }
    V operator+(const V& v) const {
        return V(*this) += v;
    }
    V& operator-=(const V& v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }
    V operator-(const V& v) const {
        return V(*this) -= v;
    }
    V& operator*=(long double s) {
        x *= s;
        y *= s;
        return *this;
    }
    V operator*(long double s) const {
        return V(*this) *= s;
    }
    V& operator/=(long double s) {
        x /= s;
        y /= s;
        return *this;
    }
    V operator/(long double s) const {
        return V(*this) /= s;
    }
    long double dot(const V& v) const {
        return x * v.x + y * v.y;
    }
    long double cross(const V& v) const {
        return x * v.y - v.x * y;
    }
    long double norm2() const {
        return x * x + y * y;
    }
    long double norm() const {
        return sqrt(x * x + y * y);
    }
    long double arg() const {
        return atan2(y, x);
    }
    V rotate() const {
        return V(y, -x);
    }
    int ort() const {
        if(abs(x) < eps && abs(y) < eps) return 0;
        if(y > 0) return x > 0 ? 1 : 2;
        else return x > 0 ? 4 : 3;
    }
    inline bool operator<(const V& v) const {
        long double theta = arg();
        long double vtheta = v.arg();
        return theta < vtheta;
    }
    // inline bool operator<(const V& v) const {
    //     int o = ort(), vo = v.ort();
    //     if(o != vo) return o < vo;
    //     return cross(v) > 0;
    // }
    // inline bool operator<(const V& v) const {
    //     if(x != v.x) return x < v.x;
    //     return y < v.y;
    // }
};
vector<V> ConvexHull(const vector<V>& ps) {
    int n = (int)ps.size();
    if(n <= 2) return ps;
    vector<V> res(2 * n);
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