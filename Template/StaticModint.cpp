const int mod = 998244353;
struct mint {
    ll x;
    mint(ll x = 0)
        : x((x % mod + mod) % mod) {}
    int val() const {
        return x;
    }
    mint& operator++() {
        x++;
        if(x == mod) x = 0;
        return *this;
    }
    mint& operator--() {
        if(x == 0) x = mod;
        x--;
        return *this;
    }
    mint operator-() const {
        return mint(-x);
    }
    mint& operator+=(const mint a) {
        if((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        return mint(*this) += a;
    }
    mint operator-(const mint a) const {
        return mint(*this) -= a;
    }
    mint operator*(const mint a) const {
        return mint(*this) *= a;
    }
    mint pow(ll t) const {
        if(!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if(t & 1) a *= *this;
        return a;
    }
    mint inv() const {
        return pow(mod - 2);
    }
    mint& operator/=(const mint a) {
        return *this *= a.inv();
    }
    mint operator/(const mint a) const {
        return mint(*this) /= a;
    }
    bool operator==(const mint& p) const {
        return x == p.x;
    }
    bool operator!=(const mint& p) const {
        return x != p.x;
    }
};
