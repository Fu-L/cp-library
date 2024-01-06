---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/point_set_range_composite.test.cpp
    title: verify/library_checker/data_structure/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/vertex_set_path_composite.test.cpp
    title: verify/library_checker/data_structure/vertex_set_path_composite.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/segment_tree.hpp\"\
    \ntemplate <typename S, auto op, auto e>\nstruct SegmentTree {\n    SegmentTree(int\
    \ N)\n        : SegmentTree(vector<S>(N, e())) {}\n    SegmentTree(const vector<S>&\
    \ v)\n        : n((int)v.size()) {\n        size = bit_ceil((unsigned int)n);\n\
    \        log = countr_zero((unsigned int)size);\n        data = vector<S>(2 *\
    \ size, e());\n        for(int i = 0; i < n; ++i) {\n            data[size + i]\
    \ = v[i];\n        }\n        for(int i = size - 1; i >= 1; --i) {\n         \
    \   update(i);\n        }\n    }\n    void set(int p, const S& x) {\n        assert(0\
    \ <= p and p < n);\n        p += size;\n        data[p] = x;\n        for(int\
    \ i = 1; i <= log; ++i) {\n            update(p >> i);\n        }\n    }\n   \
    \ S get(int p) const {\n        assert(0 <= p and p < n);\n        return data[p\
    \ + size];\n    }\n    S prod(int l, int r) const {\n        assert(0 <= l and\
    \ l <= r and r <= n);\n        S sml = e(), smr = e();\n        l += size;\n \
    \       r += size;\n        while(l < r) {\n            if(l & 1) sml = op(sml,\
    \ data[l++]);\n            if(r & 1) smr = op(data[--r], smr);\n            l\
    \ >>= 1;\n            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\
    \    S all_prod() const {\n        return data[1];\n    }\n\n    template <bool\
    \ (*f)(S)>\n    int max_right(int l) const {\n        return max_right(l, [](const\
    \ S& x) { return f(x); });\n    }\n    template <class F>\n    int max_right(int\
    \ l, const F& f) const {\n        assert(0 <= l and l <= n);\n        assert(f(e()));\n\
    \        if(l == n) return n;\n        l += size;\n        S sm = e();\n     \
    \   do {\n            while(l % 2 == 0) l >>= 1;\n            if(!f(op(sm, data[l])))\
    \ {\n                while(l < size) {\n                    l = l * 2;\n     \
    \               if(f(op(sm, data[l]))) {\n                        sm = op(sm,\
    \ data[l]);\n                        ++l;\n                    }\n           \
    \     }\n                return l - size;\n            }\n            sm = op(sm,\
    \ data[l]);\n            ++l;\n        } while((l & -l) != l);\n        return\
    \ n;\n    }\n\n    template <bool (*f)(S)>\n    int min_left(int r) const {\n\
    \        return min_left(r, [](const S& x) { return f(x); });\n    }\n    template\
    \ <class F>\n    int min_left(int r, const F& f) const {\n        assert(0 <=\
    \ r and r <= n);\n        assert(f(e()));\n        if(r == 0) return 0;\n    \
    \    r += size;\n        S sm = e();\n        do {\n            --r;\n       \
    \     while(r > 1 and (r % 2)) r >>= 1;\n            if(!f(op(data[r], sm))) {\n\
    \                while(r < size) {\n                    r = 2 * r + 1;\n     \
    \               if(f(op(data[r], sm))) {\n                        sm = op(data[r],\
    \ sm);\n                        --r;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(data[r],\
    \ sm);\n        } while((r & -r) != r);\n        return 0;\n    }\n\n   private:\n\
    \    int n, size, log;\n    vector<S> data;\n    inline void update(int k) {\n\
    \        data[k] = op(data[2 * k], data[2 * k + 1]);\n    }\n    inline unsigned\
    \ int bit_ceil(unsigned int n) {\n        unsigned int res = 1;\n        while(res\
    \ < n) res *= 2;\n        return res;\n    }\n    inline int countr_zero(unsigned\
    \ int n) {\n        return __builtin_ctz(n);\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename S,\
    \ auto op, auto e>\nstruct SegmentTree {\n    SegmentTree(int N)\n        : SegmentTree(vector<S>(N,\
    \ e())) {}\n    SegmentTree(const vector<S>& v)\n        : n((int)v.size()) {\n\
    \        size = bit_ceil((unsigned int)n);\n        log = countr_zero((unsigned\
    \ int)size);\n        data = vector<S>(2 * size, e());\n        for(int i = 0;\
    \ i < n; ++i) {\n            data[size + i] = v[i];\n        }\n        for(int\
    \ i = size - 1; i >= 1; --i) {\n            update(i);\n        }\n    }\n   \
    \ void set(int p, const S& x) {\n        assert(0 <= p and p < n);\n        p\
    \ += size;\n        data[p] = x;\n        for(int i = 1; i <= log; ++i) {\n  \
    \          update(p >> i);\n        }\n    }\n    S get(int p) const {\n     \
    \   assert(0 <= p and p < n);\n        return data[p + size];\n    }\n    S prod(int\
    \ l, int r) const {\n        assert(0 <= l and l <= r and r <= n);\n        S\
    \ sml = e(), smr = e();\n        l += size;\n        r += size;\n        while(l\
    \ < r) {\n            if(l & 1) sml = op(sml, data[l++]);\n            if(r &\
    \ 1) smr = op(data[--r], smr);\n            l >>= 1;\n            r >>= 1;\n \
    \       }\n        return op(sml, smr);\n    }\n    S all_prod() const {\n   \
    \     return data[1];\n    }\n\n    template <bool (*f)(S)>\n    int max_right(int\
    \ l) const {\n        return max_right(l, [](const S& x) { return f(x); });\n\
    \    }\n    template <class F>\n    int max_right(int l, const F& f) const {\n\
    \        assert(0 <= l and l <= n);\n        assert(f(e()));\n        if(l ==\
    \ n) return n;\n        l += size;\n        S sm = e();\n        do {\n      \
    \      while(l % 2 == 0) l >>= 1;\n            if(!f(op(sm, data[l]))) {\n   \
    \             while(l < size) {\n                    l = l * 2;\n            \
    \        if(f(op(sm, data[l]))) {\n                        sm = op(sm, data[l]);\n\
    \                        ++l;\n                    }\n                }\n    \
    \            return l - size;\n            }\n            sm = op(sm, data[l]);\n\
    \            ++l;\n        } while((l & -l) != l);\n        return n;\n    }\n\
    \n    template <bool (*f)(S)>\n    int min_left(int r) const {\n        return\
    \ min_left(r, [](const S& x) { return f(x); });\n    }\n    template <class F>\n\
    \    int min_left(int r, const F& f) const {\n        assert(0 <= r and r <= n);\n\
    \        assert(f(e()));\n        if(r == 0) return 0;\n        r += size;\n \
    \       S sm = e();\n        do {\n            --r;\n            while(r > 1 and\
    \ (r % 2)) r >>= 1;\n            if(!f(op(data[r], sm))) {\n                while(r\
    \ < size) {\n                    r = 2 * r + 1;\n                    if(f(op(data[r],\
    \ sm))) {\n                        sm = op(data[r], sm);\n                   \
    \     --r;\n                    }\n                }\n                return r\
    \ + 1 - size;\n            }\n            sm = op(data[r], sm);\n        } while((r\
    \ & -r) != r);\n        return 0;\n    }\n\n   private:\n    int n, size, log;\n\
    \    vector<S> data;\n    inline void update(int k) {\n        data[k] = op(data[2\
    \ * k], data[2 * k + 1]);\n    }\n    inline unsigned int bit_ceil(unsigned int\
    \ n) {\n        unsigned int res = 1;\n        while(res < n) res *= 2;\n    \
    \    return res;\n    }\n    inline int countr_zero(unsigned int n) {\n      \
    \  return __builtin_ctz(n);\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/point_set_range_composite.test.cpp
  - verify/library_checker/data_structure/vertex_set_path_composite.test.cpp
documentation_of: src/data_structure/segment_tree.hpp
layout: document
title: SegmentTree
---

# SegmentTree

モノイド，つまり

- 結合則: $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ for all $a, b, c \in S$
- 単位元の存在: $a \cdot e = e \cdot a = a$ for all $a \in S$

を満たす代数構造に対し使用できるデータ構造です．

長さ $N$ の $S$ の配列に対し，

- 要素の $1$ 点変更
- 区間の要素の総積の取得

を $O(\log N)$ で行うことができます．

ただし，これは二項演算 `op` と単位元取得 `e` が定数時間で動くと仮定したときの計算量です．<br>
これらが $O(f(n))$ かかる場合は，すべての計算量が $O(f(n))$ 倍となります．

## コンストラクタ

```cpp
(1) SegmentTree<S, op, e> seg(int n)
(2) SegmentTree<S, op, e> seg(vector<S> v)
```

- 型 `S`
- 二項演算 `S op(S a, S b)`
- 単位元 `S e()`

を定義する必要があります．

例として，Range Minimum Queryなら，

```cpp
int op(int a, int b) {
    return min(a, b);
}
int e() {
    return (int)1e9;
}
SegmentTree<int, op, e> seg(10);
```

のようになります．

- (1): 長さ `n` の数列 `a` を作ります．初期値は全部 `e()` です．
- (2): 長さ `n = ssize(v)` の数列 `a` を作ります．`v`の内容が初期値となります．

**計算量**

- $O(n)$

## set

```cpp
void seg.set(int p, S x)
```

`a[p]` に `x` を代入します．

**制約**

- $0 \leq p < n$

**計算量**

- $O(\log n)$

## get

```cpp
S seg.get(int p)
```

`a[p]` を返します．

**制約**

- $0 \leq p < n$

**計算量**

- $O(1)$

## prod

```cpp
S seg.prod(int l, int r)
```

`op(a[l], ..., a[r - 1])` を，モノイドの性質を満たしていると仮定して計算します．<br>
$l = r$ のときは `e()` を返します．

**制約**

- $0 \leq l \leq r \leq n$

**計算量**

- $O(\log n)$

## all_prod

```cpp
S seg.all_prod()
```

`op(a[0], ..., a[n - 1])` を計算します．<br>
$n = 0$ のときは `e()` を返します．

**計算量**

- $O(1)$

## max_right

```cpp
(1) int seg.max_right<f>(int l)
(2) int seg.max_right<F>(int l, F f)
```

- (1): 関数 `bool f(S x)` を定義する必要があります．segtreeの上で二分探索をします．
- (2): `S` を引数にとり `bool` を返す関数オブジェクトを渡して使用します．

以下の条件を両方満たす `r` を (いずれか一つ) 返します．

- `r = l` もしくは `f(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `r = n` もしくは `f(op(a[l], a[l + 1], ..., a[r])) = false`

`f` が単調だとすれば，`f(op(a[l], a[l + 1], ..., a[r - 1])) = true` となる最大の `r` ，と解釈することが可能です．

**制約**

- `f` を同じ引数で呼んだ時，返り値は等しい (=副作用はない)
- `f(e()) = true`
- $0 \leq l \leq n$

**計算量**

- $O(\log n)$

## min_left

```cpp
(1) int seg.min_left<f>(int r)
(2) int seg.min_left<F>(int r, F f)
```

- (1): 関数 `bool f(S x)` を定義する必要があります．segtreeの上で二分探索をします．
- (2): `S` を引数にとり `bool` を返す関数オブジェクトを渡して使用します．

以下の条件を両方満たす `l` を(いずれか一つ)返します．

- `l = r` もしくは `f(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `l = 0` もしくは `f(op(a[l - 1], a[l], ..., a[r - 1])) = false`

`f` が単調だとすれば，`f(op(a[l], a[l + 1], ..., a[r - 1])) = true` となる最小の `l` ，と解釈することが可能です．

**制約**

- `f` を同じ引数で呼んだ時，返り値は等しい(=副作用はない)
- `f(e()) = true`
- $0 \leq r \leq n$

**計算量**

- $O(\log n)$