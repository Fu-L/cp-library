---
title: FormalPowerSeries
documentation_of: ../../src/fps/formal_power_series.hpp
---

# FormalPowerSeries

形式的冪級数の計算を行うライブラリです．

$\mathrm{mod}$ が $\mathrm{NTT-friendly}$ なときのみ使えます．<br>
そうでない $\mathrm{mod}$ や `long long` の範囲で形式的冪級数を扱いたい場合は `FormalPowerSeriesArbitrary` や `FormalPowerSeriesLL` を使ってください．

基本的な使い方としては以下のとおりです．

```cpp
#include "template/template.hpp"
#include "template/static_modint.hpp"
#include "fps/formal_power_series.hpp"
using mint = modint998244353;
using fps = FormalPowerSeries<mint>;
int main(void) {
    fps f(10), g(10);
    for(int i = 0; i < 10; i++) {
        f[i] = i;
        g[i] = i * 2;
    }
    fps h = f * g;
    for(int i = 0; i < 19; i++) {
        cout << h[i] << '\n';
    }
}
```

## コンストラクタ

```cpp
fps f(int n)
```

$n - 1$ 次の多項式 $f$ を作ります．<br>
初期値は $f(x) = 0 + 0x + 0x^2 + ... + 0x^{n - 1}$ です．

**制約**

- $0 \leq n$

**計算量**

- $O(n)$

## eval

```cpp
mint f.eval(mint a)
```

$f(a)$ を返します．

**計算量**

- $O(n)$

## shrink

```cpp
void f.shrink()
```

係数が $0$ となっている高次の項を削除します．

たとえば $f(x) = 1 + 0x + 3x^2 + 0x^3 + 0x^4$ なら $f(x) = 1 + 0x + 3x^2$ となります．

**計算量**

- $O(n)$

## pre

```cpp
fps f.pre(int deg)
```

$f(x)$ の `deg` 次以下の項を取り出します．<br>
$\mathrm{deg} > n$ の場合は多項式が拡張されます．

**制約**

- $0 \leq \mathrm{deg}$

**計算量**

- $O(\mathrm{deg})$

## rev

```cpp
fps f.rev()
```

係数を逆順にします．

たとえば $f(x) = 1 + 2x + 3x^2$ なら $f(x) = 3 + 2x + 1x^2$ となります．

**計算量**

- $O(n)$

## 各種演算

```cpp
fps = fps;

-fps;

fps += mint;
fps -= mint;
fps *= mint;
fps /= mint;

fps += fps;
fps -= fps;
fps *= fps;
fps /= fps;
fps %= fps;

fps + mint;
fps - mint;
fps * mint;
fps / mint;

fps + fps;
fps - fps;
fps * fps;
fps / fps;
fps % fps;

fps << int;
fps >> int;
```

が動きます．

サイズの調整などは適宜行なってくれます．

`fps / fps` および `fps % fps` は，多項式としての除算です．<br>
すなわち $f(x) = g(x) q(x) + r(x)$ と表せるとき，<br>
`f(x) / g(x) = q(x)` ， `f(x) % g(x) = r(x)` です．

また `fps << (int d)` は $f(x) * x^d$ です．<br>
`fps >> (int d)` は $f(x) / x^d$ です．

**制約**

- 除算・剰余演算で未定義な演算をしないこと

**計算量**

- $O(1)$ (多項式とmintの加算・減算)
- $O(n \log n)$ (多項式同士の乗算・除算・剰余演算)
- $O(n)$ (その他)

## onemul

```cpp
void f.onemul(int d, mint c, int deg = -1)
```

$f(x) = (1 + cx^d) f(x)$ とします．

`deg` で何次まで計算するかを指定できます．<br>
`deg = -1` のときは `deg = n + d` とします．<br>
$\mathrm{deg} > n + d$ のときは多項式が拡張されます．

**制約**

- $-1 \leq deg$

**計算量**

- $O(n + d)$ ( `deg = -1` のとき)

## onediv

```cpp
void f.onediv(int d, mint c, int deg = -1)
```

$f(x) = \frac{f(x)}{1 + cx^d}$ とします．

`deg` で何次まで計算するかを指定できます．<br>
`deg = -1` のときは `deg = n` とします．<br>
$\mathrm{deg} > n + d$ のときは多項式が拡張されます．

**制約**

- $-1 \leq \mathrm{deg}$

**計算量**

- $O(n)$ ( `deg = -1` のとき)

## diff

```cpp
fps f.diff()
```

$f'(x)$ を返します．

**計算量**

- $O(n)$

## integral

```cpp
fps f.integral()
```

$\int f(x) dx$ を返します．<br>
積分定数は $0$ としてあります．

**計算量**

- $O(n)$

## inv

```cpp
fps f.inv(int deg = -1)
```

$f(x) g(x) = 1 \pmod{x^n}$ を満たす $g(x)$ を返します．

`deg` で何次まで計算するかを指定できます．<br>
`deg = -1` のときは `deg = n` とします．

**制約**

- $0 \leq n$
- $f(x)$ の定数項は $0$ でない．

**計算量**

- $O(n \log n)$ ( `deg = -1` のとき)

## log

```cpp
fps f.log(int deg = -1)
```

$\log f(x)$ を返します．<br>
$\log f(x)$ とは

$$f(x) = e^{g(x)} ~ ( := \sum\limits_{k=0}^{n-1} \frac{g^k(x)}{k!} \pmod{x^n})$$

を満たす $g(x) = \sum\limits_{i=0}^{n-1} b_i x^i (b_0 = 0)$ のことです．

`deg` で何次まで計算するかを指定できます．<br>
`deg = -1` のときは `deg = n` とします．

**制約**

- $0 < n$
- $f(x)$ の定数項は $1$ である．

**計算量**

- $O(n \log n)$ ( `deg = -1` のとき)

## exp

```cpp
fps f.exp(int deg = -1)
```

$e^{f(x)} := \sum\limits_{i=0}^{n-1} \frac{f^i(x)}{i!} \pmod{x^n}$ を返します．

`deg` で何次まで計算するかを指定できます．<br>
`deg = -1` のときは `deg = n` とします．

**制約**

- $n = 0$ または $f(x)$ の定数項が $0$ である．

**計算量**

- $O(n \log n)$ ( `deg = -1` のとき)

## pow

```cpp
fps f.pow(ll k, int deg = -1)
```

$f^k(x) \pmod{x^n}$ を返します．

`deg` で何次まで計算するかを指定できます．<br>
`deg = -1` のときは `deg = n` とします．

**制約**

- $0 \leq k$
- $-1 \leq \mathrm{deg}$

**計算量**

- $O(n \log n)$ ( `deg = -1` のとき)

## shift

```cpp
fps f.shift(mint c)
```

$f(x + a)$ を返します．

**計算量**

- $O(n \log n)$
