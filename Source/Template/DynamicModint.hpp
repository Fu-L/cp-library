#include <bits/stdc++.h>
using namespace std;
struct barrett {
    explicit barrett(unsigned int m)
        : _m(m), im((unsigned long long)(-1) / m + 1) {}
    inline unsigned int umod() const {
        return _m;
    }
    inline unsigned int mul(unsigned int a, unsigned int b) const {
        unsigned long long z = a;
        z *= b;
        unsigned long long x = (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
        unsigned int v = (unsigned int)(z - x * _m);
        if(_m <= v) v += _m;
        return v;
    }

   private:
    unsigned int _m;
    unsigned long long im;
};
template <int id>
struct DynamicModint {
    using mint = DynamicModint;
    static int mod() {
        return (int)bt.umod();
    }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = barrett(m);
    }
    static mint raw(int v) {
        mint a;
        a._v = v;
        return a;
    }
    DynamicModint()
        : _v(0) {}
    template <class T>
    DynamicModint(T v) {
        static_assert(is_integral_v<T>);
        if(is_signed_v<T>) {
            long long x = (long long)(v % (long long)(mod()));
            if(x < 0) x += mod();
            _v = (unsigned int)(x);
        } else _v = (unsigned int)(v % mod());
    }
    unsigned int val() const {
        return _v;
    }
    mint& operator++() {
        _v++;
        if(_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if(_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint res = *this;
        ++*this;
        return res;
    }
    mint operator--(int) {
        mint res = *this;
        --*this;
        return res;
    }
    mint& operator+=(const mint& rhs) {
        if(_v >= umod() - rhs._v) _v -= umod();
        _v += rhs._v;
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        if(_v < rhs._v) _v += umod();
        _v -= rhs._v;
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) {
        return *this *= rhs.inv();
    }
    mint operator+() const {
        return *this;
    }
    mint operator-() const {
        return mint() - *this;
    }
    mint pow(long long n) const {
        assert(0 <= n);
        if(n == 0) return 1;
        mint x = *this, r = 1;
        while(1) {
            if(n & 1) r *= x;
            n >>= 1;
            if(n == 0) return r;
            x *= x;
        }
    }
    mint inv() const {
        auto eg = inv_gcd(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }
    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(mint lhs, mint rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(mint lhs, mint rhs) {
        return lhs._v != rhs._v;
    }

   private:
    int _v = 0;
    static barrett bt;
    inline static unsigned int umod() {
        return bt.umod();
    }
    inline static pair<long long, long long> inv_gcd(long long a, long long b) {
        if(a == 0) return {b, 0};
        long long s = b, t = a, m0 = 0, m1 = 1;
        while(t) {
            const long long u = s / t;
            s -= t * u;
            m0 -= m1 * u;
            swap(s, t);
            swap(m0, m1);
        }
        if(m0 < 0) m0 += b / s;
        return {s, m0};
    }
};
template <int id>
barrett DynamicModint<id>::bt(998244353);
using mint = DynamicModint<-1>;
istream& operator>>(istream& in, mint& x) {
    long long a;
    in >> a;
    x = a;
    return in;
}
ostream& operator<<(ostream& out, mint x) {
    return out << x.val();
}