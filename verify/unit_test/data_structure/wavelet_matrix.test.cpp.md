---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/bit_vector.hpp
    title: BitVector
  - icon: ':heavy_check_mark:'
    path: src/data_structure/wavelet_matrix.hpp
    title: WaveletMatrix
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
  bundledCode: "#line 1 \"verify/unit_test/data_structure/wavelet_matrix.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
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
    \ w], i % w));\n    }\n};\n#line 4 \"src/data_structure/wavelet_matrix.hpp\"\n\
    template <typename T>\nstruct WaveletMatrix {\n   private:\n    using u32 = uint32_t;\n\
    \    using i64 = int64_t;\n    using u64 = uint64_t;\n    int n, lg;\n    vector<T>\
    \ a;\n    vector<BitVector> bv;\n    inline pair<u32, u32> succ0(const int l,\
    \ const int r, const int h) const {\n        return make_pair(bv[h].rank0(l),\
    \ bv[h].rank0(r));\n    }\n    inline pair<u32, u32> succ1(const int l, const\
    \ int r, const int h) const {\n        const u32 l0 = bv[h].rank0(l);\n      \
    \  const u32 r0 = bv[h].rank0(r);\n        const u32 zeros = bv[h].zeros;\n  \
    \      return make_pair(l + zeros - l0, r + zeros - r0);\n    }\n\n   public:\n\
    \    WaveletMatrix(const u32 _n)\n        : n(_n), lg(0), a(n) {}\n    WaveletMatrix(const\
    \ vector<T>& _a)\n        : n(_a.size()), lg(0), a(_a) {\n        build();\n \
    \   }\n    __attribute__((optimize(\"O3\"))) void build() {\n        if(n == 0)\
    \ {\n            lg = 0;\n            bv.clear();\n            return;\n     \
    \   }\n        for(const T& x : a) assert(x >= 0);\n        lg = __lg(max<T>(*max_element(begin(a),\
    \ end(a)), 1)) + 1;\n        bv.assign(lg, n);\n        vector<T> cur = a, nxt(n);\n\
    \        for(int h = lg - 1; h >= 0; --h) {\n            for(int i = 0; i < n;\
    \ ++i)\n                if((cur[i] >> h) & 1) bv[h].set(i);\n            bv[h].build();\n\
    \            array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n\
    \            for(int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];\n      \
    \      swap(cur, nxt);\n        }\n        return;\n    }\n    void set(const\
    \ int i, const T& x) {\n        assert(0 <= i and i < n);\n        assert(x >=\
    \ 0);\n        a[i] = x;\n    }\n    T get(u32 k) const {\n        assert(int(k)\
    \ < n);\n        T ret = 0;\n        for(int h = lg - 1; h >= 0; --h) {\n    \
    \        const u32 f = bv[h].get(k);\n            ret |= f ? T(1) << h : 0;\n\
    \            k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n        }\n\
    \        return ret;\n    }\n    T kth_smallest(u32 l, u32 r, u32 k) const {\n\
    \        assert(l <= r and int(r) <= n);\n        assert(k < r - l);\n       \
    \ T res = 0;\n        for(int h = lg - 1; h >= 0; --h) {\n            const u32\
    \ l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n            if(k < r0 - l0)\n   \
    \             l = l0, r = r0;\n            else {\n                k -= r0 - l0;\n\
    \                res |= (T)1 << h;\n                l += bv[h].zeros - l0;\n \
    \               r += bv[h].zeros - r0;\n            }\n        }\n        return\
    \ res;\n    }\n    T kth_largest(const int l, const int r, const int k) const\
    \ {\n        assert(0 <= l and l <= r and r <= n);\n        assert(0 <= k and\
    \ k < r - l);\n        return kth_smallest(l, r, r - l - k - 1);\n    }\n    int\
    \ range_freq(int l, int r, const T& upper) const {\n        assert(0 <= l and\
    \ l <= r and r <= n);\n        if(upper <= 0) return 0;\n        if(lg < (int)numeric_limits<T>::digits\
    \ and upper >= (T(1) << lg)) return r - l;\n        int ret = 0;\n        for(int\
    \ h = lg - 1; h >= 0; --h) {\n            const bool f = (upper >> h) & 1;\n \
    \           const u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n            if(f)\
    \ {\n                ret += r0 - l0;\n                l += bv[h].zeros - l0;\n\
    \                r += bv[h].zeros - r0;\n            } else {\n              \
    \  l = l0;\n                r = r0;\n            }\n        }\n        return\
    \ ret;\n    }\n    int range_freq(const int l, const int r, const T& lower, const\
    \ T& upper) const {\n        assert(0 <= l and l <= r and r <= n);\n        assert(lower\
    \ <= upper);\n        return range_freq(l, r, upper) - range_freq(l, r, lower);\n\
    \    }\n    T prev_value(const int l, const int r, const T& upper) const {\n \
    \       assert(0 <= l and l <= r and r <= n);\n        const int cnt = range_freq(l,\
    \ r, upper);\n        return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);\n\
    \    }\n    T next_value(const int l, const int r, const T& lower) const {\n \
    \       assert(0 <= l and l <= r and r <= n);\n        const int cnt = range_freq(l,\
    \ r, lower);\n        return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);\n\
    \    }\n};\n#line 4 \"verify/unit_test/data_structure/wavelet_matrix.test.cpp\"\
    \nint main() {\n    {\n        WaveletMatrix<int> wm(vector<int>{});\n       \
    \ assert(wm.range_freq(0, 0, -1) == 0);\n        assert(wm.range_freq(0, 0, 0)\
    \ == 0);\n        assert(wm.range_freq(0, 0, 10) == 0);\n        assert(wm.prev_value(0,\
    \ 0, 10) == -1);\n        assert(wm.next_value(0, 0, 0) == -1);\n    }\n    {\n\
    \        WaveletMatrix<int> wm(5);\n        for(int i = 0; i < 5; ++i) wm.set(i,\
    \ i * i % 7);\n        wm.build();\n        assert(wm.get(0) == 0);\n        assert(wm.get(1)\
    \ == 1);\n        assert(wm.get(2) == 4);\n        assert(wm.get(3) == 2);\n \
    \       assert(wm.get(4) == 2);\n    }\n    mt19937 mt(0);\n    for(int n = 0;\
    \ n <= 80; ++n) {\n        vector<int> a(n);\n        for(int& x : a) x = mt()\
    \ % 32;\n        WaveletMatrix<int> wm(a);\n        for(int l = 0; l <= n; ++l)\
    \ {\n            for(int r = l; r <= n; ++r) {\n                vector<int> b(a.begin()\
    \ + l, a.begin() + r);\n                sort(b.begin(), b.end());\n          \
    \      for(int upper = -2; upper <= 35; ++upper) {\n                    const\
    \ int freq = lower_bound(b.begin(), b.end(), upper) - b.begin();\n           \
    \         assert(wm.range_freq(l, r, upper) == freq);\n                    if(upper\
    \ >= 0) assert(wm.range_freq(l, r, 0, upper) == freq);\n                    const\
    \ int less = lower_bound(b.begin(), b.end(), upper) - b.begin();\n           \
    \         assert(wm.prev_value(l, r, upper) == (less == 0 ? -1 : b[less - 1]));\n\
    \                    assert(wm.next_value(l, r, upper) == (less == (int)b.size()\
    \ ? -1 : b[less]));\n                }\n                for(int k = 0; k < (int)b.size();\
    \ ++k) {\n                    assert(wm.kth_smallest(l, r, k) == b[k]);\n    \
    \                assert(wm.kth_largest(l, r, k) == b[(int)b.size() - 1 - k]);\n\
    \                }\n            }\n        }\n    }\n    int a, b;\n    cin >>\
    \ a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/data_structure/wavelet_matrix.hpp\"\nint main() {\n\
    \    {\n        WaveletMatrix<int> wm(vector<int>{});\n        assert(wm.range_freq(0,\
    \ 0, -1) == 0);\n        assert(wm.range_freq(0, 0, 0) == 0);\n        assert(wm.range_freq(0,\
    \ 0, 10) == 0);\n        assert(wm.prev_value(0, 0, 10) == -1);\n        assert(wm.next_value(0,\
    \ 0, 0) == -1);\n    }\n    {\n        WaveletMatrix<int> wm(5);\n        for(int\
    \ i = 0; i < 5; ++i) wm.set(i, i * i % 7);\n        wm.build();\n        assert(wm.get(0)\
    \ == 0);\n        assert(wm.get(1) == 1);\n        assert(wm.get(2) == 4);\n \
    \       assert(wm.get(3) == 2);\n        assert(wm.get(4) == 2);\n    }\n    mt19937\
    \ mt(0);\n    for(int n = 0; n <= 80; ++n) {\n        vector<int> a(n);\n    \
    \    for(int& x : a) x = mt() % 32;\n        WaveletMatrix<int> wm(a);\n     \
    \   for(int l = 0; l <= n; ++l) {\n            for(int r = l; r <= n; ++r) {\n\
    \                vector<int> b(a.begin() + l, a.begin() + r);\n              \
    \  sort(b.begin(), b.end());\n                for(int upper = -2; upper <= 35;\
    \ ++upper) {\n                    const int freq = lower_bound(b.begin(), b.end(),\
    \ upper) - b.begin();\n                    assert(wm.range_freq(l, r, upper) ==\
    \ freq);\n                    if(upper >= 0) assert(wm.range_freq(l, r, 0, upper)\
    \ == freq);\n                    const int less = lower_bound(b.begin(), b.end(),\
    \ upper) - b.begin();\n                    assert(wm.prev_value(l, r, upper) ==\
    \ (less == 0 ? -1 : b[less - 1]));\n                    assert(wm.next_value(l,\
    \ r, upper) == (less == (int)b.size() ? -1 : b[less]));\n                }\n \
    \               for(int k = 0; k < (int)b.size(); ++k) {\n                   \
    \ assert(wm.kth_smallest(l, r, k) == b[k]);\n                    assert(wm.kth_largest(l,\
    \ r, k) == b[(int)b.size() - 1 - k]);\n                }\n            }\n    \
    \    }\n    }\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n\
    }"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/wavelet_matrix.hpp
  - src/data_structure/bit_vector.hpp
  isVerificationFile: true
  path: verify/unit_test/data_structure/wavelet_matrix.test.cpp
  requiredBy: []
  timestamp: '2026-07-05 23:31:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/data_structure/wavelet_matrix.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/data_structure/wavelet_matrix.test.cpp
- /verify/verify/unit_test/data_structure/wavelet_matrix.test.cpp.html
title: verify/unit_test/data_structure/wavelet_matrix.test.cpp
---
