---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp
    title: verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/range_affine_point_get.test.cpp
    title: verify/library_checker/data_structure/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/range_affine_range_sum.test.cpp
    title: verify/library_checker/data_structure/range_affine_range_sum.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/lazy_segment_tree.hpp\"\
    \ntemplate <typename S, auto op, auto e, typename F, auto mapping, auto composition,\
    \ auto id>\nstruct LazySegmentTree {\n    LazySegmentTree(const int N)\n     \
    \   : LazySegmentTree(vector<S>(N, e())) {}\n    LazySegmentTree(const vector<S>&\
    \ v)\n        : n((int)v.size()) {\n        size = bit_ceil((unsigned int)n);\n\
    \        log = countr_zero((unsigned int)size);\n        data = vector<S>(2 *\
    \ size, e());\n        lazy = vector<F>(size, id());\n        for(int i = 0; i\
    \ < n; ++i) {\n            data[size + i] = v[i];\n        }\n        for(int\
    \ i = size - 1; i >= 1; --i) {\n            update(i);\n        }\n    }\n   \
    \ void set(int p, const S& x) {\n        assert(0 <= p and p < n);\n        p\
    \ += size;\n        for(int i = log; i >= 1; --i) {\n            push(p >> i);\n\
    \        }\n        data[p] = x;\n        for(int i = 1; i <= log; ++i) {\n  \
    \          update(p >> i);\n        }\n    }\n    S get(int p) {\n        assert(0\
    \ <= p and p < n);\n        p += size;\n        for(int i = log; i >= 1; --i)\
    \ {\n            push(p >> i);\n        }\n        return data[p];\n    }\n  \
    \  S prod(int l, int r) {\n        assert(0 <= l and l <= r and r <= n);\n   \
    \     if(l == r) return e();\n        l += size;\n        r += size;\n       \
    \ for(int i = log; i >= 1; --i) {\n            if(((l >> i) << i) != l) push(l\
    \ >> i);\n            if(((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \        S sml = e(), smr = e();\n        while(l < r) {\n            if(l & 1)\
    \ sml = op(sml, data[l++]);\n            if(r & 1) smr = op(data[--r], smr);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return op(sml,\
    \ smr);\n    }\n    S all_prod() const {\n        return data[1];\n    }\n   \
    \ void apply(int l, int r, const F& f) {\n        assert(0 <= l and l <= r and\
    \ r <= n);\n        if(l == r) return;\n        l += size;\n        r += size;\n\
    \        for(int i = log; i >= 1; --i) {\n            if(((l >> i) << i) != l)\
    \ push(l >> i);\n            if(((r >> i) << i) != r) push((r - 1) >> i);\n  \
    \      }\n        {\n            int l2 = l, r2 = r;\n            while(l < r)\
    \ {\n                if(l & 1) all_apply(l++, f);\n                if(r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2;\n            r = r2;\n        }\n        for(int i = 1; i <=\
    \ log; ++i) {\n            if(((l >> i) << i) != l) update(l >> i);\n        \
    \    if(((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n    template\
    \ <bool (*g)(S)>\n    int max_right(const int l) {\n        return max_right(l,\
    \ [](const S& x) { return g(x); });\n    }\n    template <class G>\n    int max_right(int\
    \ l, const G& g) {\n        assert(0 <= l and l <= n);\n        assert(g(e()));\n\
    \        if(l == n) return n;\n        l += size;\n        for(int i = log; i\
    \ >= 1; --i) push(l >> i);\n        S sm = e();\n        do {\n            while(l\
    \ % 2 == 0) l >>= 1;\n            if(!g(op(sm, data[l]))) {\n                while(l\
    \ < size) {\n                    push(l);\n                    l = 2 * l;\n  \
    \                  if(g(op(sm, data[l]))) {\n                        sm = op(sm,\
    \ data[l]);\n                        ++l;\n                    }\n           \
    \     }\n                return l - size;\n            }\n            sm = op(sm,\
    \ data[l]);\n            ++l;\n        } while((l & -l) != l);\n        return\
    \ n;\n    }\n\n    template <bool (*g)(S)>\n    int min_left(const int r) {\n\
    \        return min_left(r, [](const S& x) { return g(x); });\n    }\n    template\
    \ <class G>\n    int min_left(int r, const G& g) {\n        assert(0 <= r and\
    \ r <= n);\n        assert(g(e()));\n        if(r == 0) return 0;\n        r +=\
    \ size;\n        for(int i = log; i >= 1; --i) push((r - 1) >> i);\n        S\
    \ sm = e();\n        do {\n            --r;\n            while(r > 1 and (r %\
    \ 2)) r >>= 1;\n            if(!g(op(data[r], sm))) {\n                while(r\
    \ < size) {\n                    push(r);\n                    r = 2 * r + 1;\n\
    \                    if(g(op(data[r], sm))) {\n                        sm = op(data[r],\
    \ sm);\n                        --r;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(data[r],\
    \ sm);\n        } while((r & -r) != r);\n        return 0;\n    }\n\n   private:\n\
    \    int n, size, log;\n    vector<S> data;\n    vector<F> lazy;\n    inline void\
    \ update(const int k) {\n        data[k] = op(data[2 * k], data[2 * k + 1]);\n\
    \    }\n    inline void all_apply(const int k, const F& f) {\n        data[k]\
    \ = mapping(f, data[k]);\n        if(k < size) {\n            lazy[k] = composition(f,\
    \ lazy[k]);\n        }\n    }\n    inline void push(const int k) {\n        all_apply(2\
    \ * k, lazy[k]);\n        all_apply(2 * k + 1, lazy[k]);\n        lazy[k] = id();\n\
    \    }\n    inline unsigned int bit_ceil(const unsigned int n) const {\n     \
    \   unsigned int res = 1;\n        while(res < n) res *= 2;\n        return res;\n\
    \    }\n    inline int countr_zero(const unsigned int n) const {\n        return\
    \ __builtin_ctz(n);\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename S,\
    \ auto op, auto e, typename F, auto mapping, auto composition, auto id>\nstruct\
    \ LazySegmentTree {\n    LazySegmentTree(const int N)\n        : LazySegmentTree(vector<S>(N,\
    \ e())) {}\n    LazySegmentTree(const vector<S>& v)\n        : n((int)v.size())\
    \ {\n        size = bit_ceil((unsigned int)n);\n        log = countr_zero((unsigned\
    \ int)size);\n        data = vector<S>(2 * size, e());\n        lazy = vector<F>(size,\
    \ id());\n        for(int i = 0; i < n; ++i) {\n            data[size + i] = v[i];\n\
    \        }\n        for(int i = size - 1; i >= 1; --i) {\n            update(i);\n\
    \        }\n    }\n    void set(int p, const S& x) {\n        assert(0 <= p and\
    \ p < n);\n        p += size;\n        for(int i = log; i >= 1; --i) {\n     \
    \       push(p >> i);\n        }\n        data[p] = x;\n        for(int i = 1;\
    \ i <= log; ++i) {\n            update(p >> i);\n        }\n    }\n    S get(int\
    \ p) {\n        assert(0 <= p and p < n);\n        p += size;\n        for(int\
    \ i = log; i >= 1; --i) {\n            push(p >> i);\n        }\n        return\
    \ data[p];\n    }\n    S prod(int l, int r) {\n        assert(0 <= l and l <=\
    \ r and r <= n);\n        if(l == r) return e();\n        l += size;\n       \
    \ r += size;\n        for(int i = log; i >= 1; --i) {\n            if(((l >> i)\
    \ << i) != l) push(l >> i);\n            if(((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n        }\n        S sml = e(), smr = e();\n        while(l < r) {\n\
    \            if(l & 1) sml = op(sml, data[l++]);\n            if(r & 1) smr =\
    \ op(data[--r], smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n    S all_prod() const {\n        return\
    \ data[1];\n    }\n    void apply(int l, int r, const F& f) {\n        assert(0\
    \ <= l and l <= r and r <= n);\n        if(l == r) return;\n        l += size;\n\
    \        r += size;\n        for(int i = log; i >= 1; --i) {\n            if(((l\
    \ >> i) << i) != l) push(l >> i);\n            if(((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n        }\n        {\n            int l2 = l, r2 = r;\n       \
    \     while(l < r) {\n                if(l & 1) all_apply(l++, f);\n         \
    \       if(r & 1) all_apply(--r, f);\n                l >>= 1;\n             \
    \   r >>= 1;\n            }\n            l = l2;\n            r = r2;\n      \
    \  }\n        for(int i = 1; i <= log; ++i) {\n            if(((l >> i) << i)\
    \ != l) update(l >> i);\n            if(((r >> i) << i) != r) update((r - 1) >>\
    \ i);\n        }\n    }\n\n    template <bool (*g)(S)>\n    int max_right(const\
    \ int l) {\n        return max_right(l, [](const S& x) { return g(x); });\n  \
    \  }\n    template <class G>\n    int max_right(int l, const G& g) {\n       \
    \ assert(0 <= l and l <= n);\n        assert(g(e()));\n        if(l == n) return\
    \ n;\n        l += size;\n        for(int i = log; i >= 1; --i) push(l >> i);\n\
    \        S sm = e();\n        do {\n            while(l % 2 == 0) l >>= 1;\n \
    \           if(!g(op(sm, data[l]))) {\n                while(l < size) {\n   \
    \                 push(l);\n                    l = 2 * l;\n                 \
    \   if(g(op(sm, data[l]))) {\n                        sm = op(sm, data[l]);\n\
    \                        ++l;\n                    }\n                }\n    \
    \            return l - size;\n            }\n            sm = op(sm, data[l]);\n\
    \            ++l;\n        } while((l & -l) != l);\n        return n;\n    }\n\
    \n    template <bool (*g)(S)>\n    int min_left(const int r) {\n        return\
    \ min_left(r, [](const S& x) { return g(x); });\n    }\n    template <class G>\n\
    \    int min_left(int r, const G& g) {\n        assert(0 <= r and r <= n);\n \
    \       assert(g(e()));\n        if(r == 0) return 0;\n        r += size;\n  \
    \      for(int i = log; i >= 1; --i) push((r - 1) >> i);\n        S sm = e();\n\
    \        do {\n            --r;\n            while(r > 1 and (r % 2)) r >>= 1;\n\
    \            if(!g(op(data[r], sm))) {\n                while(r < size) {\n  \
    \                  push(r);\n                    r = 2 * r + 1;\n            \
    \        if(g(op(data[r], sm))) {\n                        sm = op(data[r], sm);\n\
    \                        --r;\n                    }\n                }\n    \
    \            return r + 1 - size;\n            }\n            sm = op(data[r],\
    \ sm);\n        } while((r & -r) != r);\n        return 0;\n    }\n\n   private:\n\
    \    int n, size, log;\n    vector<S> data;\n    vector<F> lazy;\n    inline void\
    \ update(const int k) {\n        data[k] = op(data[2 * k], data[2 * k + 1]);\n\
    \    }\n    inline void all_apply(const int k, const F& f) {\n        data[k]\
    \ = mapping(f, data[k]);\n        if(k < size) {\n            lazy[k] = composition(f,\
    \ lazy[k]);\n        }\n    }\n    inline void push(const int k) {\n        all_apply(2\
    \ * k, lazy[k]);\n        all_apply(2 * k + 1, lazy[k]);\n        lazy[k] = id();\n\
    \    }\n    inline unsigned int bit_ceil(const unsigned int n) const {\n     \
    \   unsigned int res = 1;\n        while(res < n) res *= 2;\n        return res;\n\
    \    }\n    inline int countr_zero(const unsigned int n) const {\n        return\
    \ __builtin_ctz(n);\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/range_affine_range_sum.test.cpp
  - verify/library_checker/data_structure/range_affine_point_get.test.cpp
  - verify/aizu_online_judge/grl/range_query_on_a_tree_2.test.cpp
documentation_of: src/data_structure/lazy_segment_tree.hpp
layout: document
title: LazySegmentTree
---

# LazySegmentTree

モノイド $(S, \cdot: S \times S \to S, e \in S)$と，$S$ から $S$ への写像の集合 $F$ であって，以下の条件を満たすようなものについて使用できるデータ構造です．

- $F$ は恒等写像 $\mathrm{id}$ を含む．つまり，任意の $x \in S$ に対し $\mathrm{id}(x) = x$ をみたす．
- $F$ は写像の合成について閉じている．つまり，任意の $f, g \in F$ に対し $f \circ g \in F$ である．
- 任意の $f \in F, x, y \in S$ に対し $f(x \cdot y) = f(x) \cdot f(y)$ をみたす．

長さ $N$ の $S$ の配列に対し，

- 区間の要素に一括で $F$ の要素 $f$ を作用 ( $x = f(x)$ )
- 区間の要素の総積の取得

を $O(\log N)$ で行うことが出来ます．

また，このライブラリはオラクルとして `op, e, mapping, composition, id` を使用しますが，これらが定数時間で動くものと仮定したときの計算量を記述します．<br>
オラクル内部の計算量が $O(f(n))$ である場合はすべての計算量が $O(f(n))$ 倍となります．

## コンストラクタ

```cpp
(1) lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);
(2) lazy_segtree<S, op, e, F, mapping, composition, id> seg(vector<S> v);
```

- モノイドの型 `S`
- $\cdot: S \times S \to S$ を計算する関数 `S op(S a, S b)`
- $e$ を返す関数 `S e()`
- 写像の型 `F`
- $f(x)$ を返す関数 `S mapping(F f, S x)`
- $f \circ g$ を返す関数 `F composition(F f, F g)`
- $id$ を返す関数 `F id()`

を定義する必要があります．

- (1): 長さ `n` の数列 `a` を作ります．初期値は全部 `e()` です．
- (2): 長さ `n = ssize(v)` の数列 `a` を作ります．`v` の内容が初期値となります．

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

- $O(\log n)$

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

## apply

```cpp
(1) void seg.apply(int p, F f)
(2) void seg.apply(int l, int r, F f)
```

- (1) `a[p] = f(a[p])`
- (2) `i = l, ..., r - 1` について `a[i] = f(a[i])`

**制約**

- (1) $0 \leq p < n$
- (2) $0 \leq l \leq r \leq n$

**計算量**

- $O(\log n)$

## max_right

```cpp
(1) int seg.max_right<g>(int l)
(2) int seg.max_right<G>(int l, G g)
```

- (1): 関数 `bool g(S x)` を定義する必要があります．segtreeの上で二分探索をします．  
- (2): `S` を引数にとり `bool` を返す関数オブジェクトを渡して使用します．  

以下の条件を両方満たす `r` を(いずれか一つ)返します．

- `r = l` もしくは `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `r = n` もしくは `g(op(a[l], a[l + 1], ..., a[r])) = false`

`g` が単調だとすれば，`g(op(a[l], a[l + 1], ..., a[r - 1])) = true` となる最大の `r` ，と解釈することが可能です．

**制約**

- `g` を同じ引数で呼んだ時，返り値は等しい (=副作用はない)
- `g(e()) = true`
- $0 \leq l \leq n$

**計算量**

- $O(\log n)$

## min_left

```cpp
(1) int seg.min_left<g>(int r)
(2) int seg.min_left<G>(int r, G g)
```

- (1): 関数 `bool g(S x)` を定義する必要があります．segtreeの上で二分探索をします．  
- (2): `S` を引数にとり `bool` を返す関数オブジェクトを渡して使用します．  

以下の条件を両方満たす `l` を(いずれか一つ)返します．

- `l = r` もしくは `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `l = 0` もしくは `g(op(a[l - 1], a[l], ..., a[r - 1])) = false`

`g` が単調だとすれば，`g(op(a[l], a[l + 1], ..., a[r - 1])) = true` となる最小の `l` ，と解釈することが可能です．

**制約**

- `g` を同じ引数で呼んだ時，返り値は等しい (=副作用はない)
- `g(e()) = true`
- $0 \leq r \leq n$

**計算量**

- $O(\log n)$

## チートシート

よく使う遅延セグ木を置いておきます．

**区間加算区間最大値取得**

```cpp
using S = long long;
using F = long long;
constexpr S INF = 8e18;
S op(const S& a, const S& b) {
    return max(a, b);
}
S e() {
    return -INF;
}
S mapping(const F& f, const S& x) {
    return f + x;
}
F composition(const F& f, const F& g) {
    return f + g;
}
F id() {
    return 0;
}
```

**区間更新区間最大値取得**

```cpp
using S = long long;
using F = long long;
constexpr S INF = 8e18;
constexpr F ID = 8e18;
S op(const S& a, const S& b) {
    return max(a, b);
}
S e() {
    return -INF;
}
S mapping(const F& f, const S& x) {
    return (f == ID ? x : f);
}
F composition(const F& f, const F& g) {
    return (f == ID ? g : f);
}
F id() {
    return ID;
}
```

**区間加算区間最小値取得**

```cpp
using S = long long;
using F = long long;
constexpr S INF = 8e18;
S op(const S& a, const S& b) {
    return min(a, b);
}
S e() {
    return INF;
}
S mapping(const F& f, const S& x) {
    return f + x;
}
F composition(const F& f, const F& g) {
    return f + g;
}
F id() {
    return 0;
}
```

**区間更新区間最小値取得**

```cpp
using S = long long;
using F = long long;
constexpr S INF = 8e18;
constexpr F ID = 8e18;
S op(const S& a, const S& b) {
    return min(a, b);
}
S e() {
    return INF;
}
S mapping(const F& f, const S& x) {
    return (f == ID ? x : f);
}
F composition(const F& f, const F& g) {
    return (f == ID ? g : f);
}
F id() {
    return ID;
}
```

**区間加算区間和取得**

```cpp
struct S {
    long long value;
    long long size;
};
using F = long long;
S op(const S& a, const S& b) {
    return {a.value + b.value, a.size + b.size};
}
S e() {
    return {0, 0};
}
S mapping(const F& f, const S& x) {
    return {x.value + f * x.size, x.size};
}
F composition(const F& f, const F& g) {
    return f + g;
}
F id() {
    return 0;
}
```

**区間更新区間和取得**

```cpp
struct S {
    long long value;
    long long size;
};
using F = long long;
constexpr F ID = 8e18;
S op(const S& a, const S& b) {
    return {a.value + b.value, a.size + b.size};
}
S e() {
    return {0, 0};
}
S mapping(const F& f, const S& x) {
    if(f == ID) return x;
    return {f * x.size, x.size};
}
F composition(const F& f, const F& g) {
    return (f == ID ? g : f);
}
F id() {
    return ID;
}
```

**区間アフィン区間和取得**

```cpp
struct S {
    mint a;
    long long size;
};
struct F {
    mint a, b;
};
S op(const S& l, const S& r) {
    return S{l.a + r.a, l.size + r.size};
}
S e() {
    return S{0, 0};
}
S mapping(const F& l, const S& r) {
    return S{r.a * l.a + r.size * l.b, r.size};
}
F composition(const F& l, const F& r) {
    return F{r.a * l.a, r.b * l.a + l.b};
}
F id() {
    return F{1, 0};
}
```

**区間等差数列加算区間和取得**

- 切片に注意してください．例えば `{0, 0, 0, 0, 0, 0, 0}` に `seg.apply(2, 6, {2, 3})` とすると `{0, 0, 7, 9, 11, 13, 0}` になります．

```cpp
struct S {
    long long value_sum, index_sum, length;
};
struct F {
    long long a, b;
};
S op(const S& a, const S& b) {
    return {a.value_sum + b.value_sum, a.index_sum + b.index_sum, a.length + b.length};
}
S e() {
    return {0, 0, 0};
}
S mapping(const F& f, const S& x) {
    return {x.value_sum + f.a * x.index_sum + f.b * x.length, x.index_sum, x.length};
}
F composition(const F& f, const F& g) {
    return {f.a + g.a, f.b + g.b};
}
F id() {
    return {0, 0};
}
```