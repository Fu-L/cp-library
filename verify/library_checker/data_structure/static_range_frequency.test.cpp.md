---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/wavelet_matrix.hpp
    title: WaveletMatrix
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"verify/library_checker/data_structure/static_range_frequency.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\n\
    #line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/data_structure/wavelet_matrix.hpp\"\n#include <immintrin.h>\nstruct\
    \ BitVector {\n    using u32 = uint32_t;\n    using i64 = int64_t;\n    using\
    \ u64 = uint64_t;\n    static constexpr u32 w = 64;\n    vector<u64> block;\n\
    \    vector<u32> count;\n    u32 n, zeros;\n    inline u32 get(const u32 i) const\
    \ {\n        return u32(block[i / w] >> (i % w)) & 1u;\n    }\n    inline void\
    \ set(const u32 i) {\n        block[i / w] |= 1LL << (i % w);\n    }\n    BitVector()\
    \ {}\n    BitVector(const int _n) {\n        init(_n);\n    }\n    __attribute__((optimize(\"\
    O3,unroll-loops\"))) void init(const int _n) {\n        n = zeros = _n;\n    \
    \    block.resize(n / w + 1, 0);\n        count.resize(block.size(), 0);\n   \
    \ }\n    __attribute__((target(\"popcnt\"))) void build() {\n        for(u32 i\
    \ = 1; i < block.size(); ++i) {\n            count[i] = count[i - 1] + _mm_popcnt_u64(block[i\
    \ - 1]);\n        }\n        zeros = rank0(n);\n    }\n    inline u32 rank0(const\
    \ u32 i) const {\n        return i - rank1(i);\n    }\n    __attribute__((target(\"\
    bmi2,popcnt\"))) inline u32 rank1(const u32 i) const {\n        return count[i\
    \ / w] + _mm_popcnt_u64(_bzhi_u64(block[i / w], i % w));\n    }\n};\ntemplate\
    \ <typename T>\nstruct WaveletMatrix {\n   private:\n    using u32 = uint32_t;\n\
    \    using i64 = int64_t;\n    using u64 = uint64_t;\n    int n, lg;\n    vector<T>\
    \ a;\n    vector<BitVector> bv;\n    inline pair<u32, u32> succ0(const int l,\
    \ const int r, const int h) const {\n        return make_pair(bv[h].rank0(l),\
    \ bv[h].rank0(r));\n    }\n    inline pair<u32, u32> succ1(const int l, const\
    \ int r, const int h) const {\n        const u32 l0 = bv[h].rank0(l);\n      \
    \  const u32 r0 = bv[h].rank0(r);\n        const u32 zeros = bv[h].zeros;\n  \
    \      return make_pair(l + zeros - l0, r + zeros - r0);\n    }\n\n   public:\n\
    \    WaveletMatrix(const u32 _n)\n        : n(max<u32>(_n, 1)), a(n) {}\n    WaveletMatrix(const\
    \ vector<T>& _a)\n        : n(_a.size()), a(_a) {\n        if(n == 0) {\n    \
    \        a.push_back(0);\n            n = 1;\n        }\n        build();\n  \
    \  }\n    __attribute__((optimize(\"O3\"))) void build() {\n        lg = __lg(max<T>(*max_element(begin(a),\
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
    \ range_freq(int l, int r, const T upper) const {\n        assert(0 <= l and l\
    \ <= r and r <= n);\n        if(upper >= (T(1) << lg)) return r - l;\n       \
    \ int ret = 0;\n        for(int h = lg - 1; h >= 0; --h) {\n            const\
    \ bool f = (upper >> h) & 1;\n            const u32 l0 = bv[h].rank0(l), r0 =\
    \ bv[h].rank0(r);\n            if(f) {\n                ret += r0 - l0;\n    \
    \            l += bv[h].zeros - l0;\n                r += bv[h].zeros - r0;\n\
    \            } else {\n                l = l0;\n                r = r0;\n    \
    \        }\n        }\n        return ret;\n    }\n    int range_freq(const int\
    \ l, const int r, const T lower, const T upper) const {\n        assert(0 <= l\
    \ and l <= r and r <= n);\n        assert(lower <= upper);\n        return range_freq(l,\
    \ r, upper) - range_freq(l, r, lower);\n    }\n    T prev_value(const int l, const\
    \ int r, const T upper) const {\n        assert(0 <= l and l <= r and r <= n);\n\
    \        const int cnt = range_freq(l, r, upper);\n        return cnt == 0 ? T(-1)\
    \ : kth_smallest(l, r, cnt - 1);\n    }\n    T next_value(const int l, const int\
    \ r, const T lower) const {\n        assert(0 <= l and l <= r and r <= n);\n \
    \       const int cnt = range_freq(l, r, lower);\n        return cnt == r - l\
    \ ? T(-1) : kth_smallest(l, r, cnt);\n    }\n};\n#line 4 \"verify/library_checker/data_structure/static_range_frequency.test.cpp\"\
    \nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n\
    \    rep(i, 0, n) {\n        cin >> a[i];\n    }\n    WaveletMatrix<int> wm(a);\n\
    \    while(q--) {\n        int l, r, x;\n        cin >> l >> r >> x;\n       \
    \ cout << wm.range_freq(l, r, x + 1) - wm.range_freq(l, r, x) << '\\n';\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/data_structure/wavelet_matrix.hpp\"\
    \nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n\
    \    rep(i, 0, n) {\n        cin >> a[i];\n    }\n    WaveletMatrix<int> wm(a);\n\
    \    while(q--) {\n        int l, r, x;\n        cin >> l >> r >> x;\n       \
    \ cout << wm.range_freq(l, r, x + 1) - wm.range_freq(l, r, x) << '\\n';\n    }\n\
    }"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/wavelet_matrix.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/static_range_frequency.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 00:13:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/static_range_frequency.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/static_range_frequency.test.cpp
- /verify/verify/library_checker/data_structure/static_range_frequency.test.cpp.html
title: verify/library_checker/data_structure/static_range_frequency.test.cpp
---
