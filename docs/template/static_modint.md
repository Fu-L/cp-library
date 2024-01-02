---
title: StaticModint
documentation_of: ../../src/template/static_modint.hpp
---

# StaticModint

自動で $\mathrm{mod}$ をとる構造体です．<br>
$\mathrm{mod}$ はコンパイル時定数である必要があります．

基本的には `modint998244353` か `modint1000000007` を使えば十分で，以下のように使えます．

```cpp
#include "src/template/template.hpp"
#include "src/template/static_modint.hpp"
using mint = modint998244353;
int main(void) {
    mint sum = 0;
    for(int i = 0; i < 10000; i++) {
        sum += i;
    }
    cout << sum << '\n';  // 8828235 (= 5000050000 % 998244353)
}
```

その他の $\mathrm{mod}$ で使いたい場合はページ下部の `Tips` を参照してください．

## コンストラクタ

```cpp
mint x
```

- `mint` のデフォルトコンストラクタです．
- 初期化しない場合， $0$ が格納されます．

**制約**

- 初期化で代入する数は `ll` に収まる値であること

**計算量**

- $O(1)$

## mod

```cpp
int mint::mod()
```

$\mathrm{mod}$ を返します．

**計算量**

- $O(1)$

## val

```cpp
int x.val()
```

$x$ に格納されている値を `int` 型で返します．

**計算量**

- $O(1)$

## 各種演算

```cpp
-mint;

mint++;
mint--;
--mint;
++mint;

mint += mint;
mint -= mint;
mint *= mint;
mint /= mint;

mint + mint;
mint - mint;
mint * mint;
mint / mint;

mint == mint;
mint != mint;
```

が動きます．

```cpp
mint x = 58;
1 + x;
```

なども，

```cpp
mint(1) + x
```

と (自動で解釈されるので) 動きます．

また，

```cpp
mint x;
cin >> x;
cout << x;
```

により入出力もできます．

**制約**

- `a / b` と `a /= b` を行うとき， $gcd(b, \mathrm{mod}) = 1$

**計算量**

- $O(1)$ (割り算以外)
- $O(\log \mathrm{mod})$ (割り算)

## pow

```cpp
mint x.pow(ll n)
```

$x^n$ を返します．

**制約**

- $0 \leq n$

**計算量**

- $O(\log n)$

## inv

```cpp
mint x.inv()
```

$xy \equiv 1$ なる $y$ を返します．

**制約**

- $gcd(x, \mathrm{mod}) = 1$

**計算量**

- $O(\log \mathrm{mod})$

## raw

```cpp
mint mint::raw(int x)
```

$x$ に対して $\mathrm{mod}$ を取らずに `mint(x)` を返します．<br>
定数倍高速化のための関数です．

値が $\mathrm{mod}$ 以上になる場合の挙動は未定義です．

**制約**

- $0 \leq x < \mathrm{mod}$

**計算量**

- $O(1)$

## Tips (other mod)

$998244353$ と $1000000007$ 以外で `modint` を使いたい場合は以下のように書けます．<br>
ただし，冒頭でも述べた通り， $\mathrm{mod}$ に指定する整数はコンパイル時定数である必要があります．

```cpp
using mint = StaticModint<1234567891>;
```

`modint998244353` と `modint1000000007` はそれぞれ `StaticModint<998244353>` と `StaticModint<1000000007>` のエイリアスになっています．