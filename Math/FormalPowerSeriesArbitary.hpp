#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
template <class mint, internal::is_static_modint_t<mint> * = nullptr>
vector<mint> convolution_arbitary(const vector<mint> &a, const vector<mint> &b) {
    int n = (int)a.size(), m = (int)b.size();
    static constexpr ll MOD1 = 754974721;
    static constexpr ll MOD2 = 167772161;
    static constexpr ll MOD3 = 469762049;
    static constexpr ll M1_inv_M2 = internal::inv_gcd(MOD1, MOD2).second;
    static constexpr ll M12_inv_M3 = internal::inv_gcd(MOD1 * MOD2, MOD3).second;
    static constexpr ll M12_mod = (MOD1 * MOD2) % mint::mod();
    vector<ll> a_(n), b_(m);
    for(int i = 0; i < n; ++i) a_[i] = a[i].val();
    for(int i = 0; i < m; ++i) b_[i] = b[i].val();
    vector<ll> x = convolution<MOD1>(a_, b_);
    vector<ll> y = convolution<MOD2>(a_, b_);
    vector<ll> z = convolution<MOD3>(a_, b_);
    vector<mint> c(n + m - 1);
    for(int i = 0; i < n + m - 1; ++i) {
        ll v1 = (y[i] - x[i]) * M1_inv_M2 % MOD2;
        if(v1 < 0) v1 += MOD2;
        ll v2 = (z[i] - (x[i] + MOD1 * v1) % MOD3) * M12_inv_M3 % MOD3;
        if(v2 < 0) v2 += MOD3;
        c[i] = x[i] + MOD1 * v1 + M12_mod * v2;
    }
    return c;
}
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
        (*this) = convolution_arbitary((*this), g);
        return (*this);
    }
    F &operator*=(const T &r) {
        for(int i = 0; i < (int)(*this).size(); ++i) (*this)[i] *= r;
        return (*this);
    }
    F &operator/=(const F &g) {
        const int n = (*this).size();
        (*this) = convolution_arbitary((*this), g.inv());
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
        F ret({T(1) / (*this)[0]});
        for(int i = 1; i < deg; i <<= 1) {
            ret = (ret + ret - ret * ret * (*this).pre(i << 1)).pre(i << 1);
        }
        return ret.pre(deg);
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
        assert(n == 0 or (*this)[0] == T(0));
        F ret({T(1)});
        for(int i = 1; i < deg; i <<= 1) {
            ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i << 1);
        }
        return ret.pre(deg);
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
        auto tmp = convolution_arbitary(g, (*this));
        T z = 1;
        for(int i = 0; i < n; ++i) {
            (*this)[i] = tmp[n + i - 1] * z;
            z *= inv[i + 1];
        }
        return (*this);
    }
};