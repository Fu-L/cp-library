#pragma once
#include "cp-library/src/template/template.hpp"
#include "cp-library/src/template/static_modint.hpp"
#include "cp-library/src/math/convolution_arbitrary.hpp"
template <typename mint>
struct FormalPowerSeries : vector<mint> {
    using vector<mint>::vector;
    using F = FormalPowerSeries;
    F& operator=(const vector<mint>& g) {
        const int n = (*this).size();
        const int m = g.size();
        if(n < m) (*this).resize(n);
        for(int i = 0; i < m; ++i) (*this)[i] = g[i];
        return (*this);
    }
    F& operator-() {
        const int n = (*this).size();
        for(int i = 0; i < n; ++i) (*this)[i] *= -1;
        return (*this);
    }
    F& operator+=(const F& g) {
        const int n = (*this).size();
        const int m = g.size();
        if(n < m) (*this).resize(m);
        for(int i = 0; i < m; ++i) (*this)[i] += g[i];
        return (*this);
    }
    F& operator+=(const mint& r) {
        if((int)(*this).size() == 0) (*this).resize(1);
        (*this)[0] += r;
        return (*this);
    }
    F& operator-=(const F& g) {
        const int n = (*this).size();
        const int m = g.size();
        if(n < m) (*this).resize(m);
        for(int i = 0; i < m; ++i) (*this)[i] -= g[i];
        return (*this);
    }
    F& operator-=(const mint& r) {
        if((int)(*this).size() == 0) (*this).resize(1);
        (*this)[0] -= r;
        return (*this);
    }
    F& operator*=(const F& g) {
        (*this) = convolution_arbitary((*this), g);
        return (*this);
    }
    F& operator*=(const mint& r) {
        const int n = (*this).size();
        for(int i = 0; i < n; ++i) (*this)[i] *= r;
        return (*this);
    }
    F& operator/=(const F& g) {
        const int n = (*this).size() - g.size() + 1;
        (*this) = ((*this).rev().pre(n) * g.rev().inv(n)).pre(n).rev();
        return (*this);
    }
    F& operator/=(const mint& r) {
        const int n = (*this).size();
        mint inv_r = r.inv();
        for(int i = 0; i < (int)n; ++i) (*this)[i] *= inv_r;
        return (*this);
    }
    F& operator<<=(const int d) {
        const int n = (*this).size();
        (*this).insert((*this).begin(), d, mint(0));
        return *this;
    }
    F& operator>>=(const int d) {
        const int n = (*this).size();
        (*this).erase((*this).begin(), (*this).begin() + min(n, d));
        return *this;
    }
    F operator*(const mint& g) const {
        return F(*this) *= g;
    }
    F operator-(const mint& g) const {
        return F(*this) -= g;
    }
    F operator+(const mint& g) const {
        return F(*this) += g;
    }
    F operator/(const mint& g) const {
        return F(*this) /= g;
    }
    F operator*(const F& g) const {
        return F(*this) *= g;
    }
    F operator-(const F& g) const {
        return F(*this) -= g;
    }
    F operator+(const F& g) const {
        return F(*this) += g;
    }
    F operator/(const F& g) const {
        return F(*this) /= g;
    }
    F operator%(const F& g) const {
        return F(*this) %= g;
    }
    F operator<<(const int d) const {
        return F(*this) <<= d;
    }
    F operator>>(const int d) const {
        return F(*this) >>= d;
    }
    F rev() const {
        F ret(*this);
        reverse(begin(ret), end(ret));
        return ret;
    }
    F pre(const int sz) const {
        F res(begin(*this), begin(*this) + min((int)(*this).size(), sz));
        if((int)res.size() < sz) res.resize(sz);
        return res;
    }
    mint eval(const mint& a) const {
        const int n = (*this).size();
        mint x = 1, ret = 0;
        for(int i = 0; i < n; ++i) {
            ret += (*this)[i] * x;
            x *= a;
        }
        return ret;
    }
    void onemul(const int d, const mint& c, const int deg = -1) {
        const int n = (*this).size();
        if(deg == -1) deg = n + d;
        if(deg > n) (*this).resize(deg);
        for(int i = deg - d - 1; i >= 0; --i) {
            (*this)[i + d] += (*this)[i] * c;
        }
    }
    void onediv(const int d, const mint& c, const int deg = -1) {
        const int n = (*this).size();
        if(deg == -1) deg = n;
        if(deg > n) (*this).resize(deg + 1);
        for(int i = 0; i < deg - d; ++i) {
            (*this)[i + d] -= (*this)[i] * c;
        }
    }
    F diff() const {
        const int n = (*this).size();
        F ret(max(0, n - 1));
        for(int i = 1; i < n; ++i) ret[i - 1] = (*this)[i] * i;
        return ret;
    }
    F integral() const {
        const int n = (*this).size(), mod = mint::mod();
        F ret(n + 1);
        ret[0] = mint(0);
        if(n > 0) ret[1] = mint(1);
        for(int i = 2; i <= n; ++i) ret[i] = (-ret[mod % i]) * (mod / i);
        for(int i = 0; i < n; ++i) ret[i + 1] *= (*this)[i];
        return ret;
    }
    F inv(int deg = -1) const {
        const int n = (*this).size();
        assert(n > 0 and (*this)[0] != mint(0));
        if(deg == -1) deg = n;
        F ret({mint(1) / (*this)[0]});
        for(int i = 1; i < deg; i <<= 1) {
            ret = (ret + ret - ret * ret * (*this).pre(i << 1)).pre(i << 1);
        }
        return ret.pre(deg);
    }
    F log(int deg = -1) const {
        const int n = (*this).size();
        assert(n > 0 and (*this)[0] == mint(1));
        if(deg == -1) deg = n;
        return ((*this).diff() * (*this).inv(deg)).pre(deg - 1).integral();
    }
    F exp(int deg = -1) const {
        const int n = (*this).size();
        assert(n == 0 or (*this)[0] == mint(0));
        if(deg == -1) deg = n;
        F ret({mint(1)});
        for(int i = 1; i < deg; i <<= 1) {
            ret = (ret * (pre(i << 1) + mint(1) - ret.log(i << 1))).pre(i << 1);
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
            if((*this)[i] != mint(0)) {
                mint rev = mint(1) / (*this)[i];
                F ret = (((*this * rev) >> i).log(deg) * k).exp(deg);
                ret *= (*this)[i].pow(k);
                ret = (ret << (i * k)).pre(deg);
                if((int)ret.size() < deg) ret.resize(deg, mint(0));
                return ret;
            }
            if(__int128_t(i + 1) * k >= deg) return F(deg, mint(0));
        }
        return F(deg, mint(0));
    }
};