#pragma once
#include "../template/template.hpp"
#if __has_include(<immintrin.h>)
#include <immintrin.h>
#define CP_LIBRARY_TARGET_POPCNT __attribute__((target("popcnt")))
#define CP_LIBRARY_TARGET_BMI __attribute__((target("bmi")))
#define CP_LIBRARY_TARGET_BMI2_POPCNT __attribute__((target("bmi2,popcnt")))
#else
#define CP_LIBRARY_TARGET_POPCNT
#define CP_LIBRARY_TARGET_BMI
#define CP_LIBRARY_TARGET_BMI2_POPCNT
#endif
CP_LIBRARY_TARGET_POPCNT inline uint32_t popcount64(const uint64_t x) {
#if __has_include(<immintrin.h>)
    return _mm_popcnt_u64(x);
#else
    return __builtin_popcountll(x);
#endif
}
CP_LIBRARY_TARGET_BMI2_POPCNT inline uint64_t low_bits(const uint64_t x, const uint32_t n) {
#if __has_include(<immintrin.h>)
    return _bzhi_u64(x, n);
#else
    return n == 64 ? x : x & ((uint64_t(1) << n) - 1);
#endif
}
CP_LIBRARY_TARGET_BMI inline uint32_t lowbit(const uint32_t x) {
#if __has_include(<immintrin.h>)
    return _blsi_u32(x);
#else
    return x & -x;
#endif
}
CP_LIBRARY_TARGET_BMI inline uint32_t clear_lowbit(const uint32_t x) {
#if __has_include(<immintrin.h>)
    return _blsr_u32(x);
#else
    return x & (x - 1);
#endif
}
struct BitVector {
    using u32 = uint32_t;
    using i64 = int64_t;
    using u64 = uint64_t;
    static constexpr u32 w = 64;
    vector<u64> block;
    vector<u32> count;
    u32 n, zeros;
    inline u32 get(const u32 i) const {
        return u32(block[i / w] >> (i % w)) & 1u;
    }
    inline void set(const u32 i) {
        block[i / w] |= 1ULL << (i % w);
    }
    BitVector() {}
    BitVector(const int _n) {
        init(_n);
    }
    __attribute__((optimize("O3,unroll-loops"))) void init(const int _n) {
        n = zeros = _n;
        block.assign(n / w + 1, 0);
        count.assign(block.size(), 0);
    }
    CP_LIBRARY_TARGET_POPCNT void build() {
        for(u32 i = 1; i < block.size(); ++i) {
            count[i] = count[i - 1] + popcount64(block[i - 1]);
        }
        zeros = rank0(n);
    }
    inline u32 rank0(const u32 i) const {
        return i - rank1(i);
    }
    CP_LIBRARY_TARGET_BMI2_POPCNT inline u32 rank1(const u32 i) const {
        return count[i / w] + popcount64(low_bits(block[i / w], i % w));
    }
};