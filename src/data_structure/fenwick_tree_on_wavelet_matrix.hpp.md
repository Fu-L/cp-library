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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
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
    \ / w] |= 1LL << (i % w);\n    }\n    BitVector() {}\n    BitVector(const int\
    \ _n) {\n        init(_n);\n    }\n    __attribute__((optimize(\"O3,unroll-loops\"\
    ))) void init(const int _n) {\n        n = zeros = _n;\n        block.resize(n\
    \ / w + 1, 0);\n        count.resize(block.size(), 0);\n    }\n    CP_LIBRARY_TARGET_POPCNT\
    \ void build() {\n        for(u32 i = 1; i < block.size(); ++i) {\n          \
    \  count[i] = count[i - 1] + popcount64(block[i - 1]);\n        }\n        zeros\
    \ = rank0(n);\n    }\n    inline u32 rank0(const u32 i) const {\n        return\
    \ i - rank1(i);\n    }\n    CP_LIBRARY_TARGET_BMI2_POPCNT inline u32 rank1(const\
    \ u32 i) const {\n        return count[i / w] + popcount64(low_bits(block[i /\
    \ w], i % w));\n    }\n};\n#line 4 \"src/data_structure/fenwick_tree_on_wavelet_matrix.hpp\"\
    \ntemplate <typename S, typename T>\nstruct FenwickTreeonWaveletMatrix {\n   private:\n\
    \    using u32 = uint32_t;\n    using i64 = int64_t;\n    using u64 = uint64_t;\n\
    \    struct FenwickTree {\n        u32 N;\n        vector<T> data;\n        FenwickTree()\
    \ = default;\n        FenwickTree(const int size) {\n            init(size);\n\
    \        }\n        void init(const int size) {\n            N = size;\n     \
    \       data.assign(N + 1, 0);\n        }\n        CP_LIBRARY_TARGET_BMI void\
    \ add(u32 k, const T& x) {\n            for(++k; k <= N; k += lowbit(k)) data[k]\
    \ += x;\n        }\n        CP_LIBRARY_TARGET_BMI T sum(u32 k) const {\n     \
    \       T ret = T();\n            for(; k; k = clear_lowbit(k)) ret += data[k];\n\
    \            return ret;\n        }\n        CP_LIBRARY_TARGET_BMI T sum(int l,\
    \ int r) const {\n            T ret = T();\n            while(l != r) {\n    \
    \            if(l < r) {\n                    ret += data[r];\n              \
    \      r = clear_lowbit(r);\n                } else {\n                    ret\
    \ -= data[l];\n                    l = clear_lowbit(l);\n                }\n \
    \           }\n            return ret;\n        }\n    };\n    using P = pair<S,\
    \ S>;\n    int n, lg;\n    vector<BitVector> bv;\n    vector<FenwickTree> bit;\n\
    \    vector<P> ps;\n    vector<S> ys;\n    inline int xid(const S& x) const {\n\
    \        return lower_bound(begin(ps), end(ps), make_pair(x, S()), [](const P&\
    \ a, const P& b) { return a.first < b.first; }) - begin(ps);\n    }\n    inline\
    \ int yid(const S& y) const {\n        return lower_bound(begin(ys), end(ys),\
    \ y) - begin(ys);\n    }\n    T sum(int l, int r, const u32 upper) const {\n \
    \       T res = 0;\n        for(int h = lg; h--;) {\n            const int l0\
    \ = bv[h].rank0(l), r0 = bv[h].rank0(r);\n            if((upper >> h) & 1) {\n\
    \                res += bit[h].sum(l0, r0);\n                l += bv[h].zeros\
    \ - l0;\n                r += bv[h].zeros - r0;\n            } else {\n      \
    \          l = l0, r = r0;\n            }\n        }\n        return res;\n  \
    \  }\n\n   public:\n    FenwickTreeonWaveletMatrix() {}\n    void add_point(const\
    \ S& x, const S& y) {\n        ps.emplace_back(x, y);\n        ys.emplace_back(y);\n\
    \    }\n    __attribute__((optimize(\"O3\"))) void build() {\n        sort(begin(ps),\
    \ end(ps));\n        ps.erase(unique(begin(ps), end(ps)), end(ps));\n        n\
    \ = ps.size();\n        sort(begin(ys), end(ys));\n        ys.erase(unique(begin(ys),\
    \ end(ys)), end(ys));\n        vector<u32> cur(n), nxt(n);\n        for(int i\
    \ = 0; i < n; ++i) cur[i] = yid(ps[i].second);\n        lg = __lg(max(n, 1)) +\
    \ 1;\n        bv.assign(lg, n);\n        bit.assign(lg, n);\n        for(int h\
    \ = lg - 1; h >= 0; --h) {\n            for(int i = 0; i < n; ++i) {\n       \
    \         if((cur[i] >> h) & 1) bv[h].set(i);\n            }\n            bv[h].build();\n\
    \            array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n\
    \            for(int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];\n      \
    \      swap(cur, nxt);\n        }\n    }\n    void add(const S& x, const S& y,\
    \ const T& val) {\n        int i = lower_bound(begin(ps), end(ps), P{x, y}) -\
    \ begin(ps);\n        for(int h = lg - 1; h >= 0; --h) {\n            const int\
    \ i0 = bv[h].rank0(i);\n            if(bv[h].get(i)) i += bv[h].zeros - i0;\n\
    \            else i = i0;\n            bit[h].add(i, val);\n        }\n    }\n\
    \    T sum(const S& l, const S& d, const S& r, const S& u) const {\n        assert(l\
    \ <= r and d <= u);\n        const int left = xid(l), right = xid(r);\n      \
    \  return sum(left, right, yid(u)) - sum(left, right, yid(d));\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./bit_vector.hpp\"\
    \ntemplate <typename S, typename T>\nstruct FenwickTreeonWaveletMatrix {\n   private:\n\
    \    using u32 = uint32_t;\n    using i64 = int64_t;\n    using u64 = uint64_t;\n\
    \    struct FenwickTree {\n        u32 N;\n        vector<T> data;\n        FenwickTree()\
    \ = default;\n        FenwickTree(const int size) {\n            init(size);\n\
    \        }\n        void init(const int size) {\n            N = size;\n     \
    \       data.assign(N + 1, 0);\n        }\n        CP_LIBRARY_TARGET_BMI void\
    \ add(u32 k, const T& x) {\n            for(++k; k <= N; k += lowbit(k)) data[k]\
    \ += x;\n        }\n        CP_LIBRARY_TARGET_BMI T sum(u32 k) const {\n     \
    \       T ret = T();\n            for(; k; k = clear_lowbit(k)) ret += data[k];\n\
    \            return ret;\n        }\n        CP_LIBRARY_TARGET_BMI T sum(int l,\
    \ int r) const {\n            T ret = T();\n            while(l != r) {\n    \
    \            if(l < r) {\n                    ret += data[r];\n              \
    \      r = clear_lowbit(r);\n                } else {\n                    ret\
    \ -= data[l];\n                    l = clear_lowbit(l);\n                }\n \
    \           }\n            return ret;\n        }\n    };\n    using P = pair<S,\
    \ S>;\n    int n, lg;\n    vector<BitVector> bv;\n    vector<FenwickTree> bit;\n\
    \    vector<P> ps;\n    vector<S> ys;\n    inline int xid(const S& x) const {\n\
    \        return lower_bound(begin(ps), end(ps), make_pair(x, S()), [](const P&\
    \ a, const P& b) { return a.first < b.first; }) - begin(ps);\n    }\n    inline\
    \ int yid(const S& y) const {\n        return lower_bound(begin(ys), end(ys),\
    \ y) - begin(ys);\n    }\n    T sum(int l, int r, const u32 upper) const {\n \
    \       T res = 0;\n        for(int h = lg; h--;) {\n            const int l0\
    \ = bv[h].rank0(l), r0 = bv[h].rank0(r);\n            if((upper >> h) & 1) {\n\
    \                res += bit[h].sum(l0, r0);\n                l += bv[h].zeros\
    \ - l0;\n                r += bv[h].zeros - r0;\n            } else {\n      \
    \          l = l0, r = r0;\n            }\n        }\n        return res;\n  \
    \  }\n\n   public:\n    FenwickTreeonWaveletMatrix() {}\n    void add_point(const\
    \ S& x, const S& y) {\n        ps.emplace_back(x, y);\n        ys.emplace_back(y);\n\
    \    }\n    __attribute__((optimize(\"O3\"))) void build() {\n        sort(begin(ps),\
    \ end(ps));\n        ps.erase(unique(begin(ps), end(ps)), end(ps));\n        n\
    \ = ps.size();\n        sort(begin(ys), end(ys));\n        ys.erase(unique(begin(ys),\
    \ end(ys)), end(ys));\n        vector<u32> cur(n), nxt(n);\n        for(int i\
    \ = 0; i < n; ++i) cur[i] = yid(ps[i].second);\n        lg = __lg(max(n, 1)) +\
    \ 1;\n        bv.assign(lg, n);\n        bit.assign(lg, n);\n        for(int h\
    \ = lg - 1; h >= 0; --h) {\n            for(int i = 0; i < n; ++i) {\n       \
    \         if((cur[i] >> h) & 1) bv[h].set(i);\n            }\n            bv[h].build();\n\
    \            array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n\
    \            for(int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];\n      \
    \      swap(cur, nxt);\n        }\n    }\n    void add(const S& x, const S& y,\
    \ const T& val) {\n        int i = lower_bound(begin(ps), end(ps), P{x, y}) -\
    \ begin(ps);\n        for(int h = lg - 1; h >= 0; --h) {\n            const int\
    \ i0 = bv[h].rank0(i);\n            if(bv[h].get(i)) i += bv[h].zeros - i0;\n\
    \            else i = i0;\n            bit[h].add(i, val);\n        }\n    }\n\
    \    T sum(const S& l, const S& d, const S& r, const S& u) const {\n        assert(l\
    \ <= r and d <= u);\n        const int left = xid(l), right = xid(r);\n      \
    \  return sum(left, right, yid(u)) - sum(left, right, yid(d));\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/bit_vector.hpp
  isVerificationFile: false
  path: src/data_structure/fenwick_tree_on_wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2026-07-04 01:44:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
documentation_of: src/data_structure/fenwick_tree_on_wavelet_matrix.hpp
layout: document
title: FenwickTreeonWaveletMatrix
---

# FenwickTreeonWaveletMatrix

矩形和クエリに高速に答えるデータ構造です．<br>
更新クエリがある場合，クエリが先読みできる必要があります．

## コンストラクタ

```cpp
FenwickTreeonWaveletMatrix<S, T> wm;
```

点がない状態の $2$ 次元平面を作ります．

`S` は点の座標の型で， `T` は点の重みの型です．

**計算量**

- $O(1)$

## add_point

```cpp
void wm.add_point(S x, S y)
```

平面上に点 $(x, y)$ を追加します．<br>
重なりがあっても構いません．

**制約**

- `build` をした後に呼び出してはいけない

**計算量**

- $O(1)$

## build

```cpp
void wm.build()
```

`wm` の初期化を行います．

**計算量**

点の数を $n$ 個として

- $O(n \log n)$

## add

```cpp
void wm.add(S x, S y, T w)
```

点 $(x, y)$ の重みを $w$ 増加させます．

`add_point` で登録していない点を呼び出した場合の動作は未定義です． (assertなどはないので要注意！)

**制約**

- `add_point` で登録していない点を呼ばない

**計算量**

- $O(\log^2 n)$

## sum

```cpp
T wm.sum(S l, S d, S r, S u)
```

$l \leq x < r, d \leq y < u$ を満たす点について，重みの総和を求めます．

**制約**

- $l \leq r$
- $d \leq u$

**計算量**

- $O(\log^2 n)$