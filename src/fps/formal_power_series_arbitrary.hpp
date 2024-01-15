#pragma once
#include "../template/template.hpp"
#include "../convolution/convolution_arbitrary.hpp"
template <typename mint>
struct FormalPowerSeriesArbitrary : vector<mint> {
    using vector<mint>::vector;
    using F = FormalPowerSeriesArbitrary;
    F& operator=(const vector<mint>& g) {
        const int n = (*this).size();
        const int m = g.size();
        if(n < m) (*this).resize(m);
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
        if((*this).empty()) (*this).resize(1);
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
        if((*this).empty()) (*this).resize(1);
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
        if((*this).size() < g.size()) {
            (*this).clear();
            return (*this);
        }
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
    F& operator%=(const F& g) {
        (*this) -= (*this) / g * g;
        shrink();
        return (*this);
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
        F ret(*this);
        ret.insert(ret.begin(), d, mint(0));
        return ret;
    }
    F operator>>(const int d) const {
        const int n = (*this).size();
        if(n <= d) return {};
        F ret(*this);
        ret.erase(ret.begin(), ret.begin() + d);
        return ret;
    }
    void shrink() {
        while((*this).size() and (*this).back() == mint(0)) (*this).pop_back();
    }
    F rev() const {
        F ret(*this);
        reverse(begin(ret), end(ret));
        return ret;
    }
    F pre(const int deg) const {
        assert(deg >= 0);
        F ret(begin(*this), begin(*this) + min((int)(*this).size(), deg));
        if((int)ret.size() < deg) ret.resize(deg);
        return ret;
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
    void onemul(const int d, const mint& c, int deg = -1) {
        assert(deg >= -1);
        const int n = (*this).size();
        if(deg == -1) deg = n + d;
        if(deg > n) (*this).resize(deg);
        for(int i = deg - d - 1; i >= 0; --i) {
            (*this)[i + d] += (*this)[i] * c;
        }
    }
    void onediv(const int d, const mint& c, int deg = -1) {
        assert(deg >= -1);
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
        assert(deg >= -1);
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
        assert(deg >= -1);
        const int n = (*this).size();
        assert(n > 0 and (*this)[0] == mint(1));
        if(deg == -1) deg = n;
        return ((*this).diff() * (*this).inv(deg)).pre(deg - 1).integral();
    }
    F exp(int deg = -1) const {
        assert(deg >= -1);
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
        assert(deg >= -1);
        assert(k >= 0);
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
    F shift(const mint& c) const {
        int n = (*this).size();
        vector<mint> fact(n), ifact(n);
        fact[0] = ifact[0] = mint(1);
        for(int i = 1; i < n; ++i) fact[i] = fact[i - 1] * i;
        ifact[n - 1] = mint(1) / fact[n - 1];
        for(int i = n - 1; i > 1; --i) ifact[i - 1] = ifact[i] * i;
        F ret(*this);
        for(int i = 0; i < n; ++i) ret[i] *= fact[i];
        ret = ret.rev();
        F bs(n, mint(1));
        for(int i = 1; i < n; ++i) bs[i] = bs[i - 1] * c * ifact[i] * fact[i - 1];
        ret = (ret * bs).pre(n);
        ret = ret.rev();
        for(int i = 0; i < n; ++i) ret[i] *= ifact[i];
        return ret;
    }
};