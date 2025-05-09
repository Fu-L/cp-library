#pragma once
#include "./template.hpp"
template <uint32_t m>
struct StaticModint {
    using mint = StaticModint;
    static constexpr uint32_t mod() {
        return m;
    }
    static constexpr mint raw(const uint32_t v) {
        mint a;
        a._v = v;
        return a;
    }
    constexpr StaticModint()
        : _v(0) {}
    template <class T>
    constexpr StaticModint(const T& v) {
        static_assert(is_integral_v<T>);
        if constexpr(is_signed_v<T>) {
            int64_t x = int64_t(v % int64_t(m));
            if(x < 0) x += m;
            _v = uint32_t(x);
        } else _v = uint32_t(v % m);
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
            const auto eg = inv_gcd(_v, m);
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
    friend istream& operator>>(istream& in, mint& x) {
        long long a;
        in >> a;
        x = a;
        return in;
    }
    friend ostream& operator<<(ostream& out, const mint& x) {
        return out << x.val();
    }

   private:
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
    static constexpr pair<int32_t, int32_t> inv_gcd(const int32_t a, const int32_t b) {
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
};
using modint998244353 = StaticModint<998244353>;
using modint1000000007 = StaticModint<1000000007>;