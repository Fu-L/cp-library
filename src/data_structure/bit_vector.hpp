#pragma once
#include "../template/template.hpp"
#include <immintrin.h>
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
        block[i / w] |= 1LL << (i % w);
    }
    BitVector() {}
    BitVector(const int _n) {
        init(_n);
    }
    __attribute__((optimize("O3,unroll-loops"))) void init(const int _n) {
        n = zeros = _n;
        block.resize(n / w + 1, 0);
        count.resize(block.size(), 0);
    }
    __attribute__((target("popcnt"))) void build() {
        for(u32 i = 1; i < block.size(); ++i) {
            count[i] = count[i - 1] + _mm_popcnt_u64(block[i - 1]);
        }
        zeros = rank0(n);
    }
    inline u32 rank0(const u32 i) const {
        return i - rank1(i);
    }
    __attribute__((target("bmi2,popcnt"))) inline u32 rank1(const u32 i) const {
        return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i / w], i % w));
    }
};