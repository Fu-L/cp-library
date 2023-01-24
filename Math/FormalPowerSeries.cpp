template <typename T>
struct FPS : vector<T> {
    using vector<T>::vector;
    FPS& operator=(const vector<T>& f) {
        const int n = f.size();
        const int m = this->size();
        if(m < n) this->resize(n);
        rep(i, 0, n)(*this)[i] = f[i];
        return (*this);
    }
    T eval(T x) const {
        T res = 0, w = 1;
        for(auto& v : *this) {
            res += w * v;
            w *= x;
        }
        return res;
    }
    FPS operator-() const {
        FPS res(this->size());
        rep(i, 0, (int)this->size()) res[i] = -(*this)[i];
        return res;
    }
    FPS& operator+=(const T& r) {
        if(this->empty()) this->resize(1);
        (*this)[0] += r;
        return *this;
    }
    FPS& operator+=(const FPS& r) {
        if(r.size() > this->size()) this->resize(r.size());
        rep(i, 0, (int)r.size())(*this)[i] += r[i];
        return *this;
    }
    FPS& operator-=(const T& r) {
        if(this->empty()) this->resize(1);
        (*this)[0] -= r;
        return *this;
    }
    FPS& operator-=(const FPS& r) {
        if(r.size() > this->size()) this->resize(r.size());
        rep(i, 0, (int)r.size())(*this)[i] -= r[i];
        return *this;
    }
    FPS& operator*=(const T& k) {
        rep(i, 0, (int)this->size())(*this)[i] *= k;
        return *this;
    }
    FPS& operator*=(const FPS& r) {
        return *this = convolution(*this, r);
    }
    FPS& operator/=(const T& k) {
        T a = k.inv();
        rep(i, 0, (int)this->size())(*this)[i] *= a;
        return *this;
    }
    FPS& operator/=(const FPS& r) {
        const int n = this->size();
        *this = convolution(*this, r.inv());
        this->resize(n);
        return (*this);
    }
    FPS operator+(const T& r) const {
        return FPS(*this) += r;
    }
    FPS operator+(const FPS& r) const {
        return FPS(*this) += r;
    }
    FPS operator-(const T& r) const {
        return FPS(*this) -= r;
    }
    FPS operator-(const FPS& r) const {
        return FPS(*this) -= r;
    }
    FPS operator*(const T& k) const {
        return FPS(*this) *= k;
    }
    FPS operator*(const FPS& r) const {
        return FPS(*this) *= r;
    }
    FPS operator/(const T& k) const {
        return FPS(*this) /= k;
    }
    FPS operator/(const FPS& r) const {
        return FPS(*this) /= r;
    }
    void onemul(const int d, const T c) {
        const int n = (*this).size();
        rrep(i, n - d - 1, 0)(*this)[i + d] += (*this)[i] * c;
    }
    void onediv(const int d, const T c) {
        const int n = (*this).size();
        rep(i, 0, n - d)(*this)[i + d] -= (*this)[i] * c;
    }
    void shrink() {
        while(this->size() and this->back() == T(0)) this->pop_back();
    }
    FPS pre(const int sz) const {
        return FPS(begin(*this), begin(*this) + min((int)this->size(), sz));
    }
    FPS rev() const {
        FPS res(*this);
        reverse(begin(res), end(res));
        return res;
    }
    FPS dot(FPS r) const {
        FPS res(min(this->size(), r.size()));
        rep(i, 0, (int)res.size()) res[i] += (*this)[i] * r[i];
        return res;
    }
    FPS diff() const {
        const int n = (int)this->size();
        FPS res(max(0, n - 1));
        rep(i, 1, n) res[i - 1] = (*this)[i] * i;
        return res;
    }
    FPS integral() const {
        const int n = (int)this->size();
        FPS res(n + 1);
        res[0] = 0;
        rep(i, 0, n) res[i + 1] = (*this)[i] / (i + 1);
        return res;
    }
    FPS inv(int deg = -1) const {
        int n = (int)this->size();
        assert(n > 0 && (*this)[0] != T(0));
        if(deg == -1) deg = n;
        FPS g(1);
        g[0] = T(1) / (*this)[0];
        while((int)g.size() < deg) {
            int m = g.size();
            FPS f(2 * m), r(2 * m);
            rep(i, 0, min(deg, 2 * m)) f[i] = (*this)[i];
            rep(i, 0, m) r[i] = g[i];
            internal::butterfly(f);
            internal::butterfly(r);
            for(int i = 0; i < 2 * m; i++) f[i] *= r[i];
            internal::butterfly_inv(f);
            f.erase(f.begin(), f.begin() + m);
            f.resize(2 * m);
            internal::butterfly(f);
            for(int i = 0; i < 2 * m; i++) f[i] *= r[i];
            internal::butterfly_inv(f);
            T in = T(2 * m).inv();
            in *= -in;
            for(int i = 0; i < m; i++) f[i] *= in;
            g.insert(g.end(), f.begin(), f.begin() + m);
        }
        return g.pre(deg);
    }
    FPS log(int deg = -1) const {
        assert((*this)[0] == T(1));
        if(deg == -1) deg = (int)this->size();
        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
    }
};
