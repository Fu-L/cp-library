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
    ll size;
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