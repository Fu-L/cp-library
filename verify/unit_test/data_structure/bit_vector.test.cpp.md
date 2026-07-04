---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/bit_vector.hpp
    title: BitVector
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/data_structure/bit_vector.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 4 \"src/template/template.hpp\"\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/bit_vector.hpp\"\
    \n#if __has_include(<immintrin.h>)\n#include <immintrin.h>\n#define CP_LIBRARY_TARGET_POPCNT\
    \ __attribute__((target(\"popcnt\")))\n#define CP_LIBRARY_TARGET_BMI __attribute__((target(\"\
    bmi\")))\n#define CP_LIBRARY_TARGET_BMI2_POPCNT __attribute__((target(\"bmi2,popcnt\"\
    )))\n#else\n#define CP_LIBRARY_TARGET_POPCNT\n#define CP_LIBRARY_TARGET_BMI\n\
    #define CP_LIBRARY_TARGET_BMI2_POPCNT\n#endif\nCP_LIBRARY_TARGET_POPCNT inline\
    \ uint32_t popcount64(const uint64_t x) {\n#if __has_include(<immintrin.h>)\n\
    \    return _mm_popcnt_u64(x);\n#else\n    return __builtin_popcountll(x);\n#endif\n\
    }\nCP_LIBRARY_TARGET_BMI2_POPCNT inline uint64_t low_bits(const uint64_t x, const\
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
    \ w], i % w));\n    }\n};\n#line 4 \"verify/unit_test/data_structure/bit_vector.test.cpp\"\
    \nint main() {\n    BitVector bv(130);\n    bv.set(0);\n    bv.set(63);\n    bv.set(64);\n\
    \    bv.set(129);\n    bv.build();\n    assert(bv.get(0) == 1);\n    assert(bv.get(1)\
    \ == 0);\n    assert(bv.get(63) == 1);\n    assert(bv.get(64) == 1);\n    assert(bv.get(129)\
    \ == 1);\n    assert(bv.rank1(0) == 0);\n    assert(bv.rank1(64) == 2);\n    assert(bv.rank1(65)\
    \ == 3);\n    assert(bv.rank1(130) == 4);\n    assert(bv.rank0(130) == 126);\n\
    \    bv.init(4);\n    bv.build();\n    assert(bv.rank1(4) == 0);\n    assert(bv.rank0(4)\
    \ == 4);\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/data_structure/bit_vector.hpp\"\nint main() {\n    BitVector\
    \ bv(130);\n    bv.set(0);\n    bv.set(63);\n    bv.set(64);\n    bv.set(129);\n\
    \    bv.build();\n    assert(bv.get(0) == 1);\n    assert(bv.get(1) == 0);\n \
    \   assert(bv.get(63) == 1);\n    assert(bv.get(64) == 1);\n    assert(bv.get(129)\
    \ == 1);\n    assert(bv.rank1(0) == 0);\n    assert(bv.rank1(64) == 2);\n    assert(bv.rank1(65)\
    \ == 3);\n    assert(bv.rank1(130) == 4);\n    assert(bv.rank0(130) == 126);\n\
    \    bv.init(4);\n    bv.build();\n    assert(bv.rank1(4) == 0);\n    assert(bv.rank0(4)\
    \ == 4);\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/bit_vector.hpp
  isVerificationFile: true
  path: verify/unit_test/data_structure/bit_vector.test.cpp
  requiredBy: []
  timestamp: '2026-07-04 16:35:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/data_structure/bit_vector.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/data_structure/bit_vector.test.cpp
- /verify/verify/unit_test/data_structure/bit_vector.test.cpp.html
title: verify/unit_test/data_structure/bit_vector.test.cpp
---
