#pragma once
#include "../template/template.hpp"
#include "../convolution/convolution_ll.hpp"
template <typename T>
struct FormalPowerSeries : vector<T> {
    using vector<T>::vector;
    using F = FormalPowerSeries;
    F& operator=(const vector<T>& g) {
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
    F& operator+=(const T& r) {
        if((*this).empty()) (*this).resize(1, T(0));
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
    F& operator-=(const T& r) {
        if((*this).empty()) (*this).resize(1, T(0));
        (*this)[0] -= r;
        return (*this);
    }
    F& operator*=(const F& g) {
        (*this) = convolution_ll((*this), g);
        return (*this);
    }
    F& operator*=(const T& r) {
        const int n = (*this).size();
        for(int i = 0; i < n; ++i) (*this)[i] *= r;
        return (*this);
    }
    F& operator/=(const T& r) {
        const int n = (*this).size();
        for(int i = 0; i < (int)n; ++i) (*this)[i] /= r;
        return (*this);
    }
    F operator*(const T& g) const {
        return F(*this) *= g;
    }
    F operator-(const T& g) const {
        return F(*this) -= g;
    }
    F operator+(const T& g) const {
        return F(*this) += g;
    }
    F operator/(const T& g) const {
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
    F operator<<(const int d) const {
        F ret(*this);
        ret.insert(ret.begin(), d, T(0));
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
        while((*this).size() and (*this).back() == T(0)) (*this).pop_back();
    }
    F rev() const {
        F ret(*this);
        reverse(begin(ret), end(ret));
        return ret;
    }
    F pre(const int deg) const {
        F ret(begin(*this), begin(*this) + min((int)(*this).size(), deg));
        if((int)ret.size() < deg) ret.resize(deg);
        return ret;
    }
    T eval(const T& a) const {
        const int n = (*this).size();
        T x = 1, ret = 0;
        for(int i = 0; i < n; ++i) {
            ret += (*this)[i] * x;
            x *= a;
        }
        return ret;
    }
    void onemul(const int d, const T& c, int deg = -1) {
        const int n = (*this).size();
        if(deg == -1) deg = n + d;
        if(deg > n) (*this).resize(deg);
        for(int i = deg - d - 1; i >= 0; --i) {
            (*this)[i + d] += (*this)[i] * c;
        }
    }
    void onediv(const int d, const T& c, int deg = -1) {
        const int n = (*this).size();
        if(deg == -1) deg = n;
        if(deg > n) (*this).resize(deg + 1);
        for(int i = 0; i < deg - d; ++i) {
            (*this)[i + d] -= (*this)[i] * c;
        }
    }
};