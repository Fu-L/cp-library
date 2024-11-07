#pragma once
#include "./template.hpp"
struct Modint_2_61m1 {
    using mint = Modint_2_61m1;
    using u64 = uint64_t;
    using u128 = __uint128_t;
    static constexpr u64 mod() {
        return m;
    }
    static constexpr mint raw(const u64 v) {
        mint a;
        a._v = v;
        return a;
    }
    constexpr Modint_2_61m1()
        : _v(0) {}
    template <class T>
    constexpr Modint_2_61m1(const T& v) {
        static_assert(is_integral_v<T>);
        if constexpr(is_signed_v<T>) {
            int64_t x = int64_t(v % int64_t(m));
            if(x < 0) x += m;
            _v = u64(x);
        } else _v = u64(v % m);
    }
    constexpr u64 val() const {
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
    constexpr mint pow(u64 n) const {
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
        assert(_v);
        return pow(m - 2);
    }
    friend constexpr mint operator+(mint lhs, mint rhs) {
        return lhs += rhs;
    }
    friend constexpr mint operator-(mint lhs, mint rhs) {
        return lhs -= rhs;
    }
    friend constexpr mint operator*(mint lhs, mint rhs) {
        return raw(modulo(u128(lhs._v) * rhs._v));
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
    static constexpr u64 m = (1ull << 61) - 1;
    u64 _v = 0;
    inline static constexpr u64 modulo(const u128& x) {
        const u64 val = (x >> 61) + (x & m);
        return val >= m ? val - m : val;
    }
};