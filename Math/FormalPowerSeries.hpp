#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
template <class T>
struct FPS : vector<T> {
    using vector<T>::vector;
    using F = FPS;
    F &operator=(const vector<T> &g) {
        const int n = g.size();
        const int m = (*this).size();
        if(m < n) (*this).resize(n);
        for(int i = 0; i < n; ++i) (*this)[i] = g[i];
        return (*this);
    }
    F &operator-() {
        for(int i = 0; i < (int)(*this).size(); ++i) (*this)[i] *= -1;
        return (*this);
    }
    F &operator+=(const F &g) {
        const int n = (*this).size();
        const int m = g.size();
        if(n < m) (*this).resize(m);
        for(int i = 0; i < m; ++i) (*this)[i] += g[i];
        return (*this);
    }
    F &operator+=(const T &r) {
        if((int)(*this).size() == 0) (*this).resize(1);
        (*this)[0] += r;
        return (*this);
    }
    F &operator-=(const F &g) {
        const int n = (*this).size();
        const int m = g.size();
        if(n < m) (*this).resize(m);
        for(int i = 0; i < m; ++i) (*this)[i] -= g[i];
        return (*this);
    }
    F &operator-=(const T &r) {
        if((int)(*this).size() == 0) (*this).resize(1);
        (*this)[0] -= r;
        return (*this);
    }
    F &operator*=(const F &g) {
        (*this) = convolution((*this), g);
        return (*this);
    }
    F &operator*=(const T &r) {
        for(int i = 0; i < (int)(*this).size(); ++i) (*this)[i] *= r;
        return (*this);
    }
    F &operator/=(const F &g) {
        const int n = (*this).size();
        (*this) = convolution((*this), g.inv());
        (*this).resize(n);
        return (*this);
    }
    F &operator/=(const T &r) {
        T inv_r = r.inv();
        for(int i = 0; i < (int)(*this).size(); ++i) (*this)[i] *= inv_r;
        return (*this);
    }
    F &operator<<=(const int d) {
        const int n = (*this).size();
        (*this).insert((*this).begin(), d, 0);
        (*this).resize(n);
        return *this;
    }
    F &operator>>=(const int d) {
        const int n = (*this).size();
        (*this).erase((*this).begin(), (*this).begin() + min(n, d));
        (*this).resize(n);
        return *this;
    }
    F operator*(const T &g) const {
        return F(*this) *= g;
    }
    F operator-(const T &g) const {
        return F(*this) -= g;
    }
    F operator+(const T &g) const {
        return F(*this) += g;
    }
    F operator/(const T &g) const {
        return F(*this) /= g;
    }
    F operator*(const F &g) const {
        return F(*this) *= g;
    }
    F operator-(const F &g) const {
        return F(*this) -= g;
    }
    F operator+(const F &g) const {
        return F(*this) += g;
    }
    F operator/(const F &g) const {
        return F(*this) /= g;
    }
    F operator%(const F &g) const {
        return F(*this) %= g;
    }
    F operator<<(const int d) const {
        return F(*this) <<= d;
    }
    F operator>>(const int d) const {
        return F(*this) >>= d;
    }
    F pre(const int sz) const {
        return F(begin(*this), begin(*this) + min((int)this->size(), sz));
    }
    F inv(int deg = -1) const {
        const int n = (*this).size();
        if(deg == -1) deg = n;
        assert(n > 0 and (*this)[0] != T(0));
        F g(1);
        g[0] = (*this)[0].inv();
        while((int)g.size() < deg) {
            int m = g.size();
            F f(begin(*this), begin(*this) + min(n, 2 * m));
            F r(g);
            f.resize(2 * m);
            r.resize(2 * m);
            internal::butterfly(f);
            internal::butterfly(r);
            for(int i = 0; i < 2 * m; ++i) f[i] *= r[i];
            internal::butterfly_inv(f);
            f.erase(f.begin(), f.begin() + m);
            f.resize(2 * m);
            internal::butterfly(f);
            for(int i = 0; i < 2 * m; ++i) f[i] *= r[i];
            internal::butterfly_inv(f);
            T in = T(2 * m).inv();
            in *= -in;
            for(int i = 0; i < m; ++i) f[i] *= in;
            g.insert(g.end(), f.begin(), f.begin() + m);
        }
        return g.pre(deg);
    }
    T eval(const T &a) const {
        T x = 1;
        T ret = 0;
        for(int i = 0; i < (int)(*this).size(); ++i) {
            ret += (*this)[i] * x;
            x *= a;
        }
        return ret;
    }
    void onemul(const int d, const T &c) {
        const int n = (*this).size();
        for(int i = n - d - 1; i >= 0; --i) {
            (*this)[i + d] += (*this)[i] * c;
        }
    }
    void onediv(const int d, const T &c) {
        const int n = (*this).size();
        for(int i = 0; i < n - d; ++i) {
            (*this)[i + d] -= (*this)[i] * c;
        }
    }
    F diff() const {
        const int n = (*this).size();
        F ret(n);
        for(int i = 1; i < n; ++i) ret[i - 1] = (*this)[i] * i;
        ret[n - 1] = 0;
        return ret;
    }
    F integral() const {
        const int n = (*this).size(), mod = T::mod();
        vector<T> inv(n);
        inv[1] = 1;
        for(int i = 2; i < n; ++i) inv[i] = T(mod) - inv[mod % i] * (mod / i);
        F ret(n);
        for(int i = n - 2; i >= 0; --i) ret[i + 1] = (*this)[i] * inv[i + 1];
        ret[0] = 0;
        return ret;
    }
    F log(int deg = -1) const {
        const int n = (*this).size();
        if(deg == -1) deg = n;
        assert((*this)[0] == T(1));
        return ((*this).diff() * (*this).inv(deg)).pre(deg).integral();
    }
    F exp(int deg = -1) const {
        const int n = (*this).size();
        if(deg == -1) deg = n;
        assert(n == 0 or (*this)[0] == 0);
        F Inv;
        Inv.reserve(deg);
        Inv.push_back(T(0));
        Inv.push_back(T(1));
        auto inplace_integral = [&](F &f) -> void {
            const int n = (int)f.size();
            int mod = T::mod();
            while((int)Inv.size() <= n) {
                int i = Inv.size();
                Inv.push_back((-Inv[mod % i]) * (mod / i));
            }
            f.insert(begin(f), T(0));
            for(int i = 1; i <= n; ++i) f[i] *= Inv[i];
        };
        auto inplace_diff = [](F &f) -> void {
            if(f.empty()) return;
            f.erase(begin(f));
            T coeff = 1;
            for(int i = 0; i < (int)f.size(); ++i) {
                f[i] *= coeff;
                ++coeff;
            }
        };
        F b{1, 1 < (int)(*this).size() ? (*this)[1] : 0}, c{1}, z1, z2{1, 1};
        for(int m = 2; m <= deg; m <<= 1) {
            auto y = b;
            y.resize(2 * m);
            internal::butterfly(y);
            z1 = z2;
            F z(m);
            for(int i = 0; i < m; ++i) z[i] = y[i] * z1[i];
            internal::butterfly_inv(z);
            T si = T(m).inv();
            for(int i = 0; i < m; ++i) z[i] *= si;
            fill(begin(z), begin(z) + m / 2, T(0));
            internal::butterfly(z);
            for(int i = 0; i < m; ++i) z[i] *= -z1[i];
            internal::butterfly_inv(z);
            for(int i = 0; i < m; ++i) z[i] *= si;
            c.insert(end(c), begin(z) + m / 2, end(z));
            z2 = c;
            z2.resize(2 * m);
            internal::butterfly(z2);
            F x(begin((*this)), begin((*this)) + min<int>((*this).size(), m));
            x.resize(m);
            inplace_diff(x);
            x.push_back(T(0));
            internal::butterfly(x);
            for(int i = 0; i < m; ++i) x[i] *= y[i];
            internal::butterfly_inv(x);
            for(int i = 0; i < m; ++i) x[i] *= si;
            x -= b.diff();
            x.resize(2 * m);
            for(int i = 0; i < m - 1; ++i) x[m + i] = x[i], x[i] = T(0);
            internal::butterfly(x);
            for(int i = 0; i < 2 * m; ++i) x[i] *= z2[i];
            internal::butterfly_inv(x);
            T si2 = T(m << 1).inv();
            for(int i = 0; i < 2 * m; ++i) x[i] *= si2;
            x.pop_back();
            inplace_integral(x);
            for(int i = m; i < min<int>((*this).size(), 2 * m); ++i) x[i] += (*this)[i];
            fill(begin(x), begin(x) + m, T(0));
            internal::butterfly(x);
            for(int i = 0; i < 2 * m; ++i) x[i] *= y[i];
            internal::butterfly_inv(x);
            for(int i = 0; i < 2 * m; ++i) x[i] *= si2;
            b.insert(end(b), begin(x) + m, end(x));
        }
        return b.pre(deg);
    }
    F pow(const ll k, int deg = -1) const {
        const int n = (*this).size();
        if(deg == -1) deg = n;
        if(k == 0) {
            F ret(deg);
            if(deg) ret[0] = 1;
            return ret;
        }
        for(int i = 0; i < n; ++i) {
            if((*this)[i] != T(0)) {
                T rev = T(1) / (*this)[i];
                F ret = (((*this * rev) >> i).log(deg) * k).exp(deg);
                ret *= (*this)[i].pow(k);
                ret = (ret << (i * k)).pre(deg);
                if((int)ret.size() < deg) ret.resize(deg, T(0));
                return ret;
            }
            if(__int128_t(i + 1) * k >= deg) return F(deg, T(0));
        }
        return F(deg, T(0));
    }
    F shift(const T &c) {
        const int n = (*this).size();
        const int mod = T::mod();
        vector<T> inv(n + 1);
        inv[1] = 1;
        for(int i = 2; i <= n; ++i) inv[i] = mod - inv[mod % i] * (mod / i);
        T x = 1;
        for(int i = 0; i < n; ++i) {
            (*this)[i] *= x;
            x *= (i + 1);
        }
        F g(n);
        T y = 1;
        T now = 1;
        for(int i = 0; i < n; ++i) {
            g[n - i - 1] = now * y;
            now *= c;
            y *= inv[i + 1];
        }
        auto tmp = convolution(g, (*this));
        T z = 1;
        for(int i = 0; i < n; ++i) {
            (*this)[i] = tmp[n + i - 1] * z;
            z *= inv[i + 1];
        }
        return (*this);
    }
};