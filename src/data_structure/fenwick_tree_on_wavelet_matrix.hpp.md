---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/rectangle_sum.test.cpp
    title: verify/library_checker/data_structure/rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/fenwick_tree_on_wavelet_matrix.hpp\"\
    \n#include <immintrin.h>\nstruct BitVector {\n    using u32 = uint32_t;\n    using\
    \ i64 = int64_t;\n    using u64 = uint64_t;\n    static constexpr u32 w = 64;\n\
    \    vector<u64> block;\n    vector<u32> count;\n    u32 n, zeros;\n    inline\
    \ u32 get(u32 i) const {\n        return u32(block[i / w] >> (i % w)) & 1u;\n\
    \    }\n    inline void set(u32 i) {\n        block[i / w] |= 1LL << (i % w);\n\
    \    }\n    BitVector() {}\n    BitVector(int _n) {\n        init(_n);\n    }\n\
    \    __attribute__((optimize(\"O3,unroll-loops\"))) void init(int _n) {\n    \
    \    n = zeros = _n;\n        block.resize(n / w + 1, 0);\n        count.resize(block.size(),\
    \ 0);\n    }\n    __attribute__((target(\"popcnt\"))) void build() {\n       \
    \ for(u32 i = 1; i < block.size(); ++i) {\n            count[i] = count[i - 1]\
    \ + _mm_popcnt_u64(block[i - 1]);\n        }\n        zeros = rank0(n);\n    }\n\
    \    inline u32 rank0(u32 i) const {\n        return i - rank1(i);\n    }\n  \
    \  __attribute__((target(\"bmi2,popcnt\"))) inline u32 rank1(u32 i) const {\n\
    \        return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i / w], i % w));\n\
    \    }\n};\ntemplate <typename S, typename T>\nstruct FenwickTreeonWaveletMatrix\
    \ {\n   private:\n    using u32 = uint32_t;\n    using i64 = int64_t;\n    using\
    \ u64 = uint64_t;\n    struct FenwickTree {\n        u32 N;\n        vector<T>\
    \ data;\n        FenwickTree() = default;\n        FenwickTree(int size) {\n \
    \           init(size);\n        }\n        void init(int size) {\n          \
    \  N = size;\n            data.assign(N + 1, 0);\n        }\n        __attribute__((target(\"\
    bmi\"))) void add(u32 k, T x) {\n            for(++k; k <= N; k += _blsi_u32(k))\
    \ data[k] += x;\n        }\n        __attribute__((target(\"bmi\"))) T sum(u32\
    \ k) const {\n            T ret = T();\n            for(; k; k = _blsr_u32(k))\
    \ ret += data[k];\n            return ret;\n        }\n        __attribute__((target(\"\
    bmi\"))) T sum(int l, int r) const {\n            T ret = T();\n            while(l\
    \ != r) {\n                if(l < r) {\n                    ret += data[r];\n\
    \                    r = _blsr_u32(r);\n                } else {\n           \
    \         ret -= data[l];\n                    l = _blsr_u32(l);\n           \
    \     }\n            }\n            return ret;\n        }\n    };\n    using\
    \ P = pair<S, S>;\n    int n, lg;\n    vector<BitVector> bv;\n    vector<FenwickTree>\
    \ bit;\n    vector<P> ps;\n    vector<S> ys;\n    inline int xid(const S& x) const\
    \ {\n        return lower_bound(begin(ps), end(ps), make_pair(x, S()), [](const\
    \ P& a, const P& b) { return a.first < b.first; }) - begin(ps);\n    }\n    inline\
    \ int yid(const S& y) const {\n        return lower_bound(begin(ys), end(ys),\
    \ y) - begin(ys);\n    }\n    T sum(int l, int r, u32 upper) const {\n       \
    \ T res = 0;\n        for(int h = lg; h--;) {\n            int l0 = bv[h].rank0(l),\
    \ r0 = bv[h].rank0(r);\n            if((upper >> h) & 1) {\n                res\
    \ += bit[h].sum(l0, r0);\n                l += bv[h].zeros - l0;\n           \
    \     r += bv[h].zeros - r0;\n            } else {\n                l = l0, r\
    \ = r0;\n            }\n        }\n        return res;\n    }\n\n   public:\n\
    \    FenwickTreeonWaveletMatrix() {}\n    void add_point(S x, S y) {\n       \
    \ ps.emplace_back(x, y);\n        ys.emplace_back(y);\n    }\n    __attribute__((optimize(\"\
    O3\"))) void build() {\n        sort(begin(ps), end(ps));\n        ps.erase(unique(begin(ps),\
    \ end(ps)), end(ps));\n        n = ps.size();\n        sort(begin(ys), end(ys));\n\
    \        ys.erase(unique(begin(ys), end(ys)), end(ys));\n        vector<u32> cur(n),\
    \ nxt(n);\n        for(int i = 0; i < n; ++i) cur[i] = yid(ps[i].second);\n  \
    \      lg = __lg(max(n, 1)) + 1;\n        bv.assign(lg, n);\n        bit.assign(lg,\
    \ n);\n        for(int h = lg - 1; h >= 0; --h) {\n            for(int i = 0;\
    \ i < n; ++i) {\n                if((cur[i] >> h) & 1) bv[h].set(i);\n       \
    \     }\n            bv[h].build();\n            array<decltype(begin(nxt)), 2>\
    \ it{begin(nxt), begin(nxt) + bv[h].zeros};\n            for(int i = 0; i < n;\
    \ ++i) *it[bv[h].get(i)]++ = cur[i];\n            swap(cur, nxt);\n        }\n\
    \    }\n    void add(S x, S y, T val) {\n        int i = lower_bound(begin(ps),\
    \ end(ps), P{x, y}) - begin(ps);\n        for(int h = lg - 1; h >= 0; --h) {\n\
    \            int i0 = bv[h].rank0(i);\n            if(bv[h].get(i)) i += bv[h].zeros\
    \ - i0;\n            else i = i0;\n            bit[h].add(i, val);\n        }\n\
    \    }\n    T sum(S l, S d, S r, S u) const {\n        assert(l <= r and d <=\
    \ u);\n        int left = xid(l), right = xid(r);\n        return sum(left, right,\
    \ yid(u)) - sum(left, right, yid(d));\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include <immintrin.h>\n\
    struct BitVector {\n    using u32 = uint32_t;\n    using i64 = int64_t;\n    using\
    \ u64 = uint64_t;\n    static constexpr u32 w = 64;\n    vector<u64> block;\n\
    \    vector<u32> count;\n    u32 n, zeros;\n    inline u32 get(u32 i) const {\n\
    \        return u32(block[i / w] >> (i % w)) & 1u;\n    }\n    inline void set(u32\
    \ i) {\n        block[i / w] |= 1LL << (i % w);\n    }\n    BitVector() {}\n \
    \   BitVector(int _n) {\n        init(_n);\n    }\n    __attribute__((optimize(\"\
    O3,unroll-loops\"))) void init(int _n) {\n        n = zeros = _n;\n        block.resize(n\
    \ / w + 1, 0);\n        count.resize(block.size(), 0);\n    }\n    __attribute__((target(\"\
    popcnt\"))) void build() {\n        for(u32 i = 1; i < block.size(); ++i) {\n\
    \            count[i] = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\n       \
    \ }\n        zeros = rank0(n);\n    }\n    inline u32 rank0(u32 i) const {\n \
    \       return i - rank1(i);\n    }\n    __attribute__((target(\"bmi2,popcnt\"\
    ))) inline u32 rank1(u32 i) const {\n        return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i\
    \ / w], i % w));\n    }\n};\ntemplate <typename S, typename T>\nstruct FenwickTreeonWaveletMatrix\
    \ {\n   private:\n    using u32 = uint32_t;\n    using i64 = int64_t;\n    using\
    \ u64 = uint64_t;\n    struct FenwickTree {\n        u32 N;\n        vector<T>\
    \ data;\n        FenwickTree() = default;\n        FenwickTree(int size) {\n \
    \           init(size);\n        }\n        void init(int size) {\n          \
    \  N = size;\n            data.assign(N + 1, 0);\n        }\n        __attribute__((target(\"\
    bmi\"))) void add(u32 k, T x) {\n            for(++k; k <= N; k += _blsi_u32(k))\
    \ data[k] += x;\n        }\n        __attribute__((target(\"bmi\"))) T sum(u32\
    \ k) const {\n            T ret = T();\n            for(; k; k = _blsr_u32(k))\
    \ ret += data[k];\n            return ret;\n        }\n        __attribute__((target(\"\
    bmi\"))) T sum(int l, int r) const {\n            T ret = T();\n            while(l\
    \ != r) {\n                if(l < r) {\n                    ret += data[r];\n\
    \                    r = _blsr_u32(r);\n                } else {\n           \
    \         ret -= data[l];\n                    l = _blsr_u32(l);\n           \
    \     }\n            }\n            return ret;\n        }\n    };\n    using\
    \ P = pair<S, S>;\n    int n, lg;\n    vector<BitVector> bv;\n    vector<FenwickTree>\
    \ bit;\n    vector<P> ps;\n    vector<S> ys;\n    inline int xid(const S& x) const\
    \ {\n        return lower_bound(begin(ps), end(ps), make_pair(x, S()), [](const\
    \ P& a, const P& b) { return a.first < b.first; }) - begin(ps);\n    }\n    inline\
    \ int yid(const S& y) const {\n        return lower_bound(begin(ys), end(ys),\
    \ y) - begin(ys);\n    }\n    T sum(int l, int r, u32 upper) const {\n       \
    \ T res = 0;\n        for(int h = lg; h--;) {\n            int l0 = bv[h].rank0(l),\
    \ r0 = bv[h].rank0(r);\n            if((upper >> h) & 1) {\n                res\
    \ += bit[h].sum(l0, r0);\n                l += bv[h].zeros - l0;\n           \
    \     r += bv[h].zeros - r0;\n            } else {\n                l = l0, r\
    \ = r0;\n            }\n        }\n        return res;\n    }\n\n   public:\n\
    \    FenwickTreeonWaveletMatrix() {}\n    void add_point(S x, S y) {\n       \
    \ ps.emplace_back(x, y);\n        ys.emplace_back(y);\n    }\n    __attribute__((optimize(\"\
    O3\"))) void build() {\n        sort(begin(ps), end(ps));\n        ps.erase(unique(begin(ps),\
    \ end(ps)), end(ps));\n        n = ps.size();\n        sort(begin(ys), end(ys));\n\
    \        ys.erase(unique(begin(ys), end(ys)), end(ys));\n        vector<u32> cur(n),\
    \ nxt(n);\n        for(int i = 0; i < n; ++i) cur[i] = yid(ps[i].second);\n  \
    \      lg = __lg(max(n, 1)) + 1;\n        bv.assign(lg, n);\n        bit.assign(lg,\
    \ n);\n        for(int h = lg - 1; h >= 0; --h) {\n            for(int i = 0;\
    \ i < n; ++i) {\n                if((cur[i] >> h) & 1) bv[h].set(i);\n       \
    \     }\n            bv[h].build();\n            array<decltype(begin(nxt)), 2>\
    \ it{begin(nxt), begin(nxt) + bv[h].zeros};\n            for(int i = 0; i < n;\
    \ ++i) *it[bv[h].get(i)]++ = cur[i];\n            swap(cur, nxt);\n        }\n\
    \    }\n    void add(S x, S y, T val) {\n        int i = lower_bound(begin(ps),\
    \ end(ps), P{x, y}) - begin(ps);\n        for(int h = lg - 1; h >= 0; --h) {\n\
    \            int i0 = bv[h].rank0(i);\n            if(bv[h].get(i)) i += bv[h].zeros\
    \ - i0;\n            else i = i0;\n            bit[h].add(i, val);\n        }\n\
    \    }\n    T sum(S l, S d, S r, S u) const {\n        assert(l <= r and d <=\
    \ u);\n        int left = xid(l), right = xid(r);\n        return sum(left, right,\
    \ yid(u)) - sum(left, right, yid(d));\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/fenwick_tree_on_wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2024-02-15 01:51:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/rectangle_sum.test.cpp
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