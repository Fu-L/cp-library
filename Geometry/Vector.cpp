// ベクトル(点)を扱う。
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
    bool operator<(const V& v) const {
        long double theta = arg();
        long double vtheta = v.arg();
        return theta < vtheta;
    }
    // bool operator<(const V& v) const {
    //     int o = ort(), vo = v.ort();
    //     if(o != vo) return o < vo;
    //     return cross(v) > 0;
    // }
    // bool operator<(const V& v) const {
    //     if(x != v.x) return x < v.x;
    //     return y < v.y;
    // }
};
