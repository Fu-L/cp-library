#pragma once
#include "../template/template.hpp"
struct PermutedCongruentialGenerator {
    template <typename T>
        requires(is_integral_v<T> and sizeof(T) == 4) or (is_floating_point_v<T> and sizeof(T) == 8)
    inline T operator()(const T l, const T r) {
        assert(l <= r);
        if constexpr(is_integral_v<T>) {
            const unsigned int x = next32();
            if constexpr(is_signed_v<T>) {
                const uint64_t range = uint64_t(int64_t(r) - int64_t(l)) + 1;
                const uint64_t offset = range == (uint64_t(1) << 32) ? x : x % range;
                return T(int64_t(l) + int64_t(offset));
            } else {
                const uint64_t range = uint64_t(r) - uint64_t(l) + 1;
                const uint64_t offset = range == (uint64_t(1) << 32) ? x : x % range;
                return T(l + T(offset));
            }
        } else {
            static constexpr unsigned long long denom = 1ull << 53;
            const unsigned long long x = next64() >> 11;
            const double u = static_cast<double>(x) / denom;
            return l + (r - l) * u;
        }
    }

   private:
    static constexpr unsigned long long MULT = 6364136223846793005;
    static inline unsigned long long state = chrono::steady_clock::now().time_since_epoch().count();
    inline unsigned int next32() {
        unsigned long long x = state;
        state *= MULT;
        const unsigned int count = x >> 61;
        x ^= x >> 22;
        return static_cast<unsigned int>(x >> (22 + count));
    }
    inline unsigned long long next64() {
        return (static_cast<unsigned long long>(next32()) << 32) | next32();
    }
} rng;