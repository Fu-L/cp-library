---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/fenwick_tree_on_wavelet_matrix.hpp
    title: FenwickTreeonWaveletMatrix
  - icon: ':heavy_check_mark:'
    path: src/data_structure/rectangle_sum.hpp
    title: RectangleSum
  - icon: ':heavy_check_mark:'
    path: src/data_structure/wavelet_matrix.hpp
    title: WaveletMatrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/rectangle_sum.test.cpp
    title: verify/library_checker/data_structure/rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_range_frequency.test.cpp
    title: verify/library_checker/data_structure/static_range_frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    #line 4 \"src/template/template.hpp\"\nusing namespace std;\nusing ll = long long;\n\
    using P = pair<long long, long long>;\n#define rep(i, a, b) for(long long i =\
    \ (a); i < (b); ++i)\n#define rrep(i, a, b) for(long long i = (a); i >= (b); --i)\n\
    constexpr long long inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/data_structure/bit_vector.hpp\"\n#if __has_include(<immintrin.h>)\n\
    #include <immintrin.h>\n#define CP_LIBRARY_TARGET_POPCNT __attribute__((target(\"\
    popcnt\")))\n#define CP_LIBRARY_TARGET_BMI __attribute__((target(\"bmi\")))\n\
    #define CP_LIBRARY_TARGET_BMI2_POPCNT __attribute__((target(\"bmi2,popcnt\")))\n\
    #else\n#define CP_LIBRARY_TARGET_POPCNT\n#define CP_LIBRARY_TARGET_BMI\n#define\
    \ CP_LIBRARY_TARGET_BMI2_POPCNT\n#endif\nCP_LIBRARY_TARGET_POPCNT inline uint32_t\
    \ popcount64(const uint64_t x) {\n#if __has_include(<immintrin.h>)\n    return\
    \ _mm_popcnt_u64(x);\n#else\n    return __builtin_popcountll(x);\n#endif\n}\n\
    CP_LIBRARY_TARGET_BMI2_POPCNT inline uint64_t low_bits(const uint64_t x, const\
    \ uint32_t n) {\n#if __has_include(<immintrin.h>)\n    return _bzhi_u64(x, n);\n\
    #else\n    return n == 64 ? x : x & ((uint64_t(1) << n) - 1);\n#endif\n}\nCP_LIBRARY_TARGET_BMI\
    \ inline uint32_t lowbit(const uint32_t x) {\n#if __has_include(<immintrin.h>)\n\
    \    return _blsi_u32(x);\n#else\n    return x & -x;\n#endif\n}\nCP_LIBRARY_TARGET_BMI\
    \ inline uint32_t clear_lowbit(const uint32_t x) {\n#if __has_include(<immintrin.h>)\n\
    \    return _blsr_u32(x);\n#else\n    return x & (x - 1);\n#endif\n}\nstruct BitVector\
    \ {\n    using u32 = uint32_t;\n    using i64 = int64_t;\n    using u64 = uint64_t;\n\
    \    static constexpr u32 w = 64;\n    vector<u64> block;\n    vector<u32> count;\n\
    \    u32 n, zeros;\n    inline u32 get(const u32 i) const {\n        return u32(block[i\
    \ / w] >> (i % w)) & 1u;\n    }\n    inline void set(const u32 i) {\n        block[i\
    \ / w] |= 1ULL << (i % w);\n    }\n    BitVector() {}\n    BitVector(const int\
    \ _n) {\n        init(_n);\n    }\n    __attribute__((optimize(\"O3,unroll-loops\"\
    ))) void init(const int _n) {\n        n = zeros = _n;\n        block.assign(n\
    \ / w + 1, 0);\n        count.assign(block.size(), 0);\n    }\n    CP_LIBRARY_TARGET_POPCNT\
    \ void build() {\n        for(u32 i = 1; i < block.size(); ++i) {\n          \
    \  count[i] = count[i - 1] + popcount64(block[i - 1]);\n        }\n        zeros\
    \ = rank0(n);\n    }\n    inline u32 rank0(const u32 i) const {\n        return\
    \ i - rank1(i);\n    }\n    CP_LIBRARY_TARGET_BMI2_POPCNT inline u32 rank1(const\
    \ u32 i) const {\n        return count[i / w] + popcount64(low_bits(block[i /\
    \ w], i % w));\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#if __has_include(<immintrin.h>)\n\
    #include <immintrin.h>\n#define CP_LIBRARY_TARGET_POPCNT __attribute__((target(\"\
    popcnt\")))\n#define CP_LIBRARY_TARGET_BMI __attribute__((target(\"bmi\")))\n\
    #define CP_LIBRARY_TARGET_BMI2_POPCNT __attribute__((target(\"bmi2,popcnt\")))\n\
    #else\n#define CP_LIBRARY_TARGET_POPCNT\n#define CP_LIBRARY_TARGET_BMI\n#define\
    \ CP_LIBRARY_TARGET_BMI2_POPCNT\n#endif\nCP_LIBRARY_TARGET_POPCNT inline uint32_t\
    \ popcount64(const uint64_t x) {\n#if __has_include(<immintrin.h>)\n    return\
    \ _mm_popcnt_u64(x);\n#else\n    return __builtin_popcountll(x);\n#endif\n}\n\
    CP_LIBRARY_TARGET_BMI2_POPCNT inline uint64_t low_bits(const uint64_t x, const\
    \ uint32_t n) {\n#if __has_include(<immintrin.h>)\n    return _bzhi_u64(x, n);\n\
    #else\n    return n == 64 ? x : x & ((uint64_t(1) << n) - 1);\n#endif\n}\nCP_LIBRARY_TARGET_BMI\
    \ inline uint32_t lowbit(const uint32_t x) {\n#if __has_include(<immintrin.h>)\n\
    \    return _blsi_u32(x);\n#else\n    return x & -x;\n#endif\n}\nCP_LIBRARY_TARGET_BMI\
    \ inline uint32_t clear_lowbit(const uint32_t x) {\n#if __has_include(<immintrin.h>)\n\
    \    return _blsr_u32(x);\n#else\n    return x & (x - 1);\n#endif\n}\nstruct BitVector\
    \ {\n    using u32 = uint32_t;\n    using i64 = int64_t;\n    using u64 = uint64_t;\n\
    \    static constexpr u32 w = 64;\n    vector<u64> block;\n    vector<u32> count;\n\
    \    u32 n, zeros;\n    inline u32 get(const u32 i) const {\n        return u32(block[i\
    \ / w] >> (i % w)) & 1u;\n    }\n    inline void set(const u32 i) {\n        block[i\
    \ / w] |= 1ULL << (i % w);\n    }\n    BitVector() {}\n    BitVector(const int\
    \ _n) {\n        init(_n);\n    }\n    __attribute__((optimize(\"O3,unroll-loops\"\
    ))) void init(const int _n) {\n        n = zeros = _n;\n        block.assign(n\
    \ / w + 1, 0);\n        count.assign(block.size(), 0);\n    }\n    CP_LIBRARY_TARGET_POPCNT\
    \ void build() {\n        for(u32 i = 1; i < block.size(); ++i) {\n          \
    \  count[i] = count[i - 1] + popcount64(block[i - 1]);\n        }\n        zeros\
    \ = rank0(n);\n    }\n    inline u32 rank0(const u32 i) const {\n        return\
    \ i - rank1(i);\n    }\n    CP_LIBRARY_TARGET_BMI2_POPCNT inline u32 rank1(const\
    \ u32 i) const {\n        return count[i / w] + popcount64(low_bits(block[i /\
    \ w], i % w));\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/bit_vector.hpp
  requiredBy:
  - src/data_structure/wavelet_matrix.hpp
  - src/data_structure/rectangle_sum.hpp
  - src/data_structure/fenwick_tree_on_wavelet_matrix.hpp
  timestamp: '2026-07-04 15:44:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/static_range_frequency.test.cpp
  - verify/library_checker/data_structure/rectangle_sum.test.cpp
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
documentation_of: src/data_structure/bit_vector.hpp
layout: document
title: BitVector
---

# BitVector

`WaveletMatrix` などのための補助データ構造です．<br>
基本的には内部的にしか使用しないと思うので，把握する必要はありません．