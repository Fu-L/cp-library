#include <bits/stdc++.h>
using namespace std;
template <uint32_t m>
class StaticModint {
    using mint = StaticModint;
    uint32_t _v = 0;
    static constexpr bool prime = []() -> bool {
        if(m == 1) return 0;
        if(m == 2 or m == 7 or m == 61) return 1;
        if(m % 2 == 0) return 0;
        uint32_t d = m - 1;
        while(d % 2 == 0) d /= 2;
        for(uint32_t a : {2, 7, 61}) {
            uint32_t t = d;
            mint y = mint(a).pow(t);
            while(t != m - 1 && y != 1 && y != m - 1) {
                y *= y;
                t <<= 1;
            }
            if(y != m - 1 && t % 2 == 0) return 0;
        }
        return 1;
    }();
    static constexpr pair<int32_t, int32_t> inv_gcd(int32_t a, int32_t b) {
        if(a == 0) return {b, 0};
        int32_t s = b, t = a, m0 = 0, m1 = 1;
        while(t) {
            const int32_t u = s / t;
            s -= t * u;
            m0 -= m1 * u;
            swap(s, t);
            swap(m0, m1);
        }
        if(m0 < 0) m0 += b / s;
        return {s, m0};
    }

   public:
    static constexpr mint raw(uint32_t v) {
        mint a;
        a._v = v;
        return a;
    }
    constexpr StaticModint() {}
    template <class T>
    constexpr StaticModint(T v) {
        static_assert(is_integral_v<T>, "T is not integral type.");
        if constexpr(is_signed_v<T>) {
            int64_t x = int64_t(v % int64_t(m));
            if(x < 0) x += m;
            _v = uint32_t(x);
        } else _v = uint32_t(v % m);
    }
    static constexpr uint32_t mod() {
        return m;
    }
    constexpr uint32_t val() const {
        return _v;
    }
    constexpr mint& operator++() {
        return *this += 1;
    }
    constexpr mint& operator--() {
        return *this -= 1;
    }
    constexpr mint operator++(int) {
        mint res = *this;
        ++*this;
        return res;
    }
    constexpr mint operator--(int) {
        mint res = *this;
        --*this;
        return res;
    }
    constexpr mint& operator+=(mint rhs) {
        if(_v >= m - rhs._v) _v -= m;
        _v += rhs._v;
        return *this;
    }
    constexpr mint& operator-=(mint rhs) {
        if(_v < rhs._v) _v += m;
        _v -= rhs._v;
        return *this;
    }
    constexpr mint& operator*=(mint rhs) {
        return *this = *this * rhs;
    }
    constexpr mint& operator/=(mint rhs) {
        return *this *= rhs.inv();
    }
    constexpr mint operator+() const {
        return *this;
    }
    constexpr mint operator-() const {
        return mint{} - *this;
    }
    constexpr mint pow(long long n) const {
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
    constexpr mint inv() const {
        if constexpr(prime) {
            assert(_v);
            return pow(m - 2);
        } else {
            auto eg = inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }
    friend constexpr mint operator+(mint lhs, mint rhs) {
        return lhs += rhs;
    }
    friend constexpr mint operator-(mint lhs, mint rhs) {
        return lhs -= rhs;
    }
    friend constexpr mint operator*(mint lhs, mint rhs) {
        return uint64_t(lhs._v) * rhs._v;
    }
    friend constexpr mint operator/(mint lhs, mint rhs) {
        return lhs /= rhs;
    }
    friend constexpr bool operator==(mint lhs, mint rhs) {
        return lhs._v == rhs._v;
    }
    friend constexpr bool operator!=(mint lhs, mint rhs) {
        return lhs._v != rhs._v;
    }
};
using mint = StaticModint<998244353>;
istream& operator>>(istream& in, mint& x) {
    long long a;
    in >> a;
    x = a;
    return in;
}
ostream& operator<<(ostream& out, mint x) {
    return out << x.val();
}