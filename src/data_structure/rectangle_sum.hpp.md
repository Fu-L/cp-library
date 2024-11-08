---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/data_structure/rectangle_sum.test.cpp
    title: verify/library_checker/data_structure/rectangle_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n\
    #define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a,\
    \ b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
    struct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/rectangle_sum.hpp\"\
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
    \ / w], i % w));\n    }\n};\ntemplate <typename S, typename T>\nstruct RectangleSum\
    \ {\n    RectangleSum() {}\n    void add_point(const S& x, const S& y, const T&\
    \ w) {\n        ps.emplace_back(make_pair(x, y), w);\n        ys.emplace_back(y);\n\
    \    }\n    __attribute__((optimize(\"O3\"))) void build() {\n        n = ps.size();\n\
    \        sort(begin(ps), end(ps));\n        sort(begin(ys), end(ys));\n      \
    \  ys.erase(unique(begin(ys), end(ys)), end(ys));\n        lg = __lg(max(n, 1))\
    \ + 1;\n        bv.assign(lg, n);\n        vector<int> cur(n), nxt(n);\n     \
    \   for(int i = 0; i < n; ++i) {\n            cur[i] = yid(ps[i].first.second);\n\
    \        }\n        for(int h = lg - 1; h >= 0; --h) {\n            for(int i\
    \ = 0; i < n; ++i)\n                if((cur[i] >> h) & 1) bv[h].set(i);\n    \
    \        bv[h].build();\n            array<decltype(begin(nxt)), 2> it{begin(nxt),\
    \ begin(nxt) + bv[h].zeros};\n            for(int i = 0; i < n; ++i) *it[bv[h].get(i)]++\
    \ = cur[i];\n            swap(cur, nxt);\n        }\n        s.assign(lg, vector<T>(n\
    \ + 1));\n        for(int _i = 0; _i < n; ++_i) {\n            int i = _i;\n \
    \           for(int h = lg - 1; h >= 0; --h) {\n                const int i0 =\
    \ bv[h].rank0(i);\n                if(bv[h].get(i)) i += bv[h].zeros - i0;\n \
    \               else i = i0;\n                s[h][i + 1] += ps[_i].second;\n\
    \            }\n        }\n        for(int h = 0; h < lg; ++h) {\n           \
    \ for(int i = 0; i < n; ++i) {\n                s[h][i + 1] += s[h][i];\n    \
    \        }\n        }\n    }\n    T sum(const S& l, const S& d, const S& r, const\
    \ S& u) const {\n        assert(l <= r and d <= u);\n        const int left =\
    \ xid(l), right = xid(r);\n        return range_sum(left, right, yid(u)) - range_sum(left,\
    \ right, yid(d));\n    }\n\n   private:\n    using u32 = uint32_t;\n    using\
    \ i64 = int64_t;\n    using u64 = uint64_t;\n    using P = pair<S, S>;\n    int\
    \ n, lg;\n    vector<BitVector> bv;\n    vector<vector<T>> s;\n    vector<pair<P,\
    \ T>> ps;\n    vector<S> ys;\n    inline int xid(const S& x) const {\n       \
    \ return lower_bound(begin(ps), end(ps), make_pair(make_pair(x, S()), T()), [](const\
    \ pair<P, T>& a, const pair<P, T>& b) { return a.first.first < b.first.first;\
    \ }) - begin(ps);\n    }\n    inline int yid(const S& y) const {\n        return\
    \ lower_bound(begin(ys), end(ys), y) - begin(ys);\n    }\n    T range_sum(int\
    \ l, int r, const int upper) const {\n        T ret = 0;\n        for(int h =\
    \ lg - 1; h >= 0; --h) {\n            const u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n\
    \            if((upper >> h) & 1) {\n                ret += s[h][r0] - s[h][l0];\n\
    \                l += bv[h].zeros - l0;\n                r += bv[h].zeros - r0;\n\
    \            } else {\n                l = l0;\n                r = r0;\n    \
    \        }\n        }\n        return ret;\n    }\n};\n"
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
    \ <typename S, typename T>\nstruct RectangleSum {\n    RectangleSum() {}\n   \
    \ void add_point(const S& x, const S& y, const T& w) {\n        ps.emplace_back(make_pair(x,\
    \ y), w);\n        ys.emplace_back(y);\n    }\n    __attribute__((optimize(\"\
    O3\"))) void build() {\n        n = ps.size();\n        sort(begin(ps), end(ps));\n\
    \        sort(begin(ys), end(ys));\n        ys.erase(unique(begin(ys), end(ys)),\
    \ end(ys));\n        lg = __lg(max(n, 1)) + 1;\n        bv.assign(lg, n);\n  \
    \      vector<int> cur(n), nxt(n);\n        for(int i = 0; i < n; ++i) {\n   \
    \         cur[i] = yid(ps[i].first.second);\n        }\n        for(int h = lg\
    \ - 1; h >= 0; --h) {\n            for(int i = 0; i < n; ++i)\n              \
    \  if((cur[i] >> h) & 1) bv[h].set(i);\n            bv[h].build();\n         \
    \   array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n\
    \            for(int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];\n      \
    \      swap(cur, nxt);\n        }\n        s.assign(lg, vector<T>(n + 1));\n \
    \       for(int _i = 0; _i < n; ++_i) {\n            int i = _i;\n           \
    \ for(int h = lg - 1; h >= 0; --h) {\n                const int i0 = bv[h].rank0(i);\n\
    \                if(bv[h].get(i)) i += bv[h].zeros - i0;\n                else\
    \ i = i0;\n                s[h][i + 1] += ps[_i].second;\n            }\n    \
    \    }\n        for(int h = 0; h < lg; ++h) {\n            for(int i = 0; i <\
    \ n; ++i) {\n                s[h][i + 1] += s[h][i];\n            }\n        }\n\
    \    }\n    T sum(const S& l, const S& d, const S& r, const S& u) const {\n  \
    \      assert(l <= r and d <= u);\n        const int left = xid(l), right = xid(r);\n\
    \        return range_sum(left, right, yid(u)) - range_sum(left, right, yid(d));\n\
    \    }\n\n   private:\n    using u32 = uint32_t;\n    using i64 = int64_t;\n \
    \   using u64 = uint64_t;\n    using P = pair<S, S>;\n    int n, lg;\n    vector<BitVector>\
    \ bv;\n    vector<vector<T>> s;\n    vector<pair<P, T>> ps;\n    vector<S> ys;\n\
    \    inline int xid(const S& x) const {\n        return lower_bound(begin(ps),\
    \ end(ps), make_pair(make_pair(x, S()), T()), [](const pair<P, T>& a, const pair<P,\
    \ T>& b) { return a.first.first < b.first.first; }) - begin(ps);\n    }\n    inline\
    \ int yid(const S& y) const {\n        return lower_bound(begin(ys), end(ys),\
    \ y) - begin(ys);\n    }\n    T range_sum(int l, int r, const int upper) const\
    \ {\n        T ret = 0;\n        for(int h = lg - 1; h >= 0; --h) {\n        \
    \    const u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n            if((upper\
    \ >> h) & 1) {\n                ret += s[h][r0] - s[h][l0];\n                l\
    \ += bv[h].zeros - l0;\n                r += bv[h].zeros - r0;\n            }\
    \ else {\n                l = l0;\n                r = r0;\n            }\n  \
    \      }\n        return ret;\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/rectangle_sum.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/data_structure/rectangle_sum.test.cpp
documentation_of: src/data_structure/rectangle_sum.hpp
layout: document
title: RectangleSum
---

# RectangleSum

矩形和クエリに高速に答えるデータ構造です．<br>
更新クエリは処理できません．

## コンストラクタ

```cpp
RectangleSum<S, T> wm;
```

点がない状態の $2$ 次元平面を作ります．

`S` は点の座標の型で， `T` は点の重みの型です．

**計算量**

- $O(1)$

## add_point

```cpp
void wm.add_point(S x, S y, T w)
```

平面上に重みが $w$ である点 $(x, y)$ を追加します．<br>
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

## sum

```cpp
T wm.sum(S l, S d, S r, S u)
```

$l \leq x < r, d \leq y < u$ を満たす点について，重みの総和を求めます．

**制約**

- $l \leq r$
- $d \leq u$

**計算量**

- $O(\log n)$