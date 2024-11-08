---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_range_frequency.test.cpp
    title: verify/library_checker/data_structure/static_range_frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n\
    #define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a,\
    \ b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
    struct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/wavelet_matrix.hpp\"\
    \n#include <immintrin.h>\nstruct BitVector {\n    using u32 = uint32_t;\n    using\
    \ i64 = int64_t;\n    using u64 = uint64_t;\n    static constexpr u32 w = 64;\n\
    \    vector<u64> block;\n    vector<u32> count;\n    u32 n, zeros;\n    inline\
    \ u32 get(const u32 i) const {\n        return u32(block[i / w] >> (i % w)) &\
    \ 1u;\n    }\n    inline void set(const u32 i) {\n        block[i / w] |= 1LL\
    \ << (i % w);\n    }\n    BitVector() {}\n    BitVector(const int _n) {\n    \
    \    init(_n);\n    }\n    __attribute__((optimize(\"O3,unroll-loops\"))) void\
    \ init(const int _n) {\n        n = zeros = _n;\n        block.resize(n / w +\
    \ 1, 0);\n        count.resize(block.size(), 0);\n    }\n    __attribute__((target(\"\
    popcnt\"))) void build() {\n        for(u32 i = 1; i < block.size(); ++i) {\n\
    \            count[i] = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\n       \
    \ }\n        zeros = rank0(n);\n    }\n    inline u32 rank0(const u32 i) const\
    \ {\n        return i - rank1(i);\n    }\n    __attribute__((target(\"bmi2,popcnt\"\
    ))) inline u32 rank1(const u32 i) const {\n        return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i\
    \ / w], i % w));\n    }\n};\ntemplate <typename T>\nstruct WaveletMatrix {\n \
    \  private:\n    using u32 = uint32_t;\n    using i64 = int64_t;\n    using u64\
    \ = uint64_t;\n    int n, lg;\n    vector<T> a;\n    vector<BitVector> bv;\n \
    \   inline pair<u32, u32> succ0(const int l, const int r, const int h) const {\n\
    \        return make_pair(bv[h].rank0(l), bv[h].rank0(r));\n    }\n    inline\
    \ pair<u32, u32> succ1(const int l, const int r, const int h) const {\n      \
    \  const u32 l0 = bv[h].rank0(l);\n        const u32 r0 = bv[h].rank0(r);\n  \
    \      const u32 zeros = bv[h].zeros;\n        return make_pair(l + zeros - l0,\
    \ r + zeros - r0);\n    }\n\n   public:\n    WaveletMatrix(const u32 _n)\n   \
    \     : n(max<u32>(_n, 1)), a(n) {}\n    WaveletMatrix(const vector<T>& _a)\n\
    \        : n(_a.size()), a(_a) {\n        if(n == 0) {\n            a.push_back(0);\n\
    \            n = 1;\n        }\n        build();\n    }\n    __attribute__((optimize(\"\
    O3\"))) void build() {\n        lg = __lg(max<T>(*max_element(begin(a), end(a)),\
    \ 1)) + 1;\n        bv.assign(lg, n);\n        vector<T> cur = a, nxt(n);\n  \
    \      for(int h = lg - 1; h >= 0; --h) {\n            for(int i = 0; i < n; ++i)\n\
    \                if((cur[i] >> h) & 1) bv[h].set(i);\n            bv[h].build();\n\
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
    \ l <= r and r <= n);\n        if(upper >= (T(1) << lg)) return r - l;\n     \
    \   int ret = 0;\n        for(int h = lg - 1; h >= 0; --h) {\n            const\
    \ bool f = (upper >> h) & 1;\n            const u32 l0 = bv[h].rank0(l), r0 =\
    \ bv[h].rank0(r);\n            if(f) {\n                ret += r0 - l0;\n    \
    \            l += bv[h].zeros - l0;\n                r += bv[h].zeros - r0;\n\
    \            } else {\n                l = l0;\n                r = r0;\n    \
    \        }\n        }\n        return ret;\n    }\n    int range_freq(const int\
    \ l, const int r, const T& lower, const T& upper) const {\n        assert(0 <=\
    \ l and l <= r and r <= n);\n        assert(lower <= upper);\n        return range_freq(l,\
    \ r, upper) - range_freq(l, r, lower);\n    }\n    T prev_value(const int l, const\
    \ int r, const T& upper) const {\n        assert(0 <= l and l <= r and r <= n);\n\
    \        const int cnt = range_freq(l, r, upper);\n        return cnt == 0 ? T(-1)\
    \ : kth_smallest(l, r, cnt - 1);\n    }\n    T next_value(const int l, const int\
    \ r, const T& lower) const {\n        assert(0 <= l and l <= r and r <= n);\n\
    \        const int cnt = range_freq(l, r, lower);\n        return cnt == r - l\
    \ ? T(-1) : kth_smallest(l, r, cnt);\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include <immintrin.h>\n\
    struct BitVector {\n    using u32 = uint32_t;\n    using i64 = int64_t;\n    using\
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
    \ range_freq(int l, int r, const T& upper) const {\n        assert(0 <= l and\
    \ l <= r and r <= n);\n        if(upper >= (T(1) << lg)) return r - l;\n     \
    \   int ret = 0;\n        for(int h = lg - 1; h >= 0; --h) {\n            const\
    \ bool f = (upper >> h) & 1;\n            const u32 l0 = bv[h].rank0(l), r0 =\
    \ bv[h].rank0(r);\n            if(f) {\n                ret += r0 - l0;\n    \
    \            l += bv[h].zeros - l0;\n                r += bv[h].zeros - r0;\n\
    \            } else {\n                l = l0;\n                r = r0;\n    \
    \        }\n        }\n        return ret;\n    }\n    int range_freq(const int\
    \ l, const int r, const T& lower, const T& upper) const {\n        assert(0 <=\
    \ l and l <= r and r <= n);\n        assert(lower <= upper);\n        return range_freq(l,\
    \ r, upper) - range_freq(l, r, lower);\n    }\n    T prev_value(const int l, const\
    \ int r, const T& upper) const {\n        assert(0 <= l and l <= r and r <= n);\n\
    \        const int cnt = range_freq(l, r, upper);\n        return cnt == 0 ? T(-1)\
    \ : kth_smallest(l, r, cnt - 1);\n    }\n    T next_value(const int l, const int\
    \ r, const T& lower) const {\n        assert(0 <= l and l <= r and r <= n);\n\
    \        const int cnt = range_freq(l, r, lower);\n        return cnt == r - l\
    \ ? T(-1) : kth_smallest(l, r, cnt);\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:50:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/static_range_frequency.test.cpp
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
documentation_of: src/data_structure/wavelet_matrix.hpp
layout: document
title: WaveletMatrix
---

# WaveletMatrix

静的な非負整数列に対するさまざまな区間クエリを $O(\log n)$ で行えるデータ構造です．

## コンストラクタ

```cpp
(1) WaveletMatrix<T> wm(int n)
(2) WaveletMatrix<T> wm(vector<T> a)
```

- (1): 長さ `n` の数列 `wm` を作ります．初期値は $0$ です．
- (2): 長さ `n = ssize(v)` の数列 `wm` を作り， `v` の内容を初期値として `build` を行います．

**計算量**

- (1) $O(n)$
- (2) $O(n \log n)$

## set

```cpp
void wm.set(int i, T x)
```

`wm[i]` に $x$ を代入します．

**制約**

- $0 \leq n < n$
- $0 \leq x$
- `build` をした後に呼び出してはいけない

**計算量**

- $O(1)$

## build

```cpp
void wm.build()
```

`wm` の初期化を行います．

**計算量**

- $O(n \log n)$

## get

```cpp
T wm.get(int i)
```

`wm[i]` を返します．

**制約**

- $0 \leq i < n$

**計算量**

- $O(\log n)$

## kth_smallest

```cpp
T wm.kth_smallest(int l, int r, int k)
```

`wm[l, r)` における $k$ 番目 ( $0 \mathrm{-indexed}$ ) に小さい値を返します．

**制約**

- $0 \leq l \leq r \leq n$
- $0 \leq k < r - l$

**計算量**

- $O(\log n)$

## kth_largest

```cpp
T wm.kth_largest(int l, int r, int k)
```

`wm[l, r)` における $k$ 番目 ( $0 \mathrm{-indexed}$ ) に大きい値を返します．

**制約**

- $0 \leq l \leq r \leq n$
- $0 \leq k < r - l$

**計算量**

- $O(\log n)$

## range_freq

```cpp
(1) int range_freq(int l, int r, T upper)
(2) int range_freq(int l, int r, T lower, T upper)
```

(1) `wm[l, r)` における $\mathrm{upper}$ 未満の要素の個数を返します．<br>
(2) `wm[l, r)` における $\mathrm{lower}$ 以上 $\mathrm{upper}$ 未満の要素の個数を返します．

**制約**

- $0 \leq l \leq r \leq n$
- (2) $\mathrm{lower} \leq \mathrm{upper}$

**計算量**

- $O(\log n)$

## prev_value

```cpp
T wm.prev_value(int l, int r, T upper)
```

`wm[l, r)` における $\mathrm{upper}$ 未満の最大値を返します．<br>
そのような値が存在しない存在しない場合は $-1$ を返します．

**制約**

- $0 \leq l \leq r \leq n$

**計算量**

- $O(\log n)$

## next_value

```cpp
T wm.next_value(int l, int r, T lower)
```

`wm[l, r)` における $\mathrm{lower}$ 以上の最小値を返します．<br>
存在しない場合は $-1$ を返します．

**制約**

- $0 \leq l \leq r \leq n$

**計算量**

- $O(\log n)$