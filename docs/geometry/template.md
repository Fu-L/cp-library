---
title: template
documentation_of: ../../src/geometry/template.hpp
---

幾何テンプレートです．

## Real, EPS, PI

`Real` は `long double` のエイリアスです．<br>
必要となる精度や速度次第で `double` に変えて使うこともできます．

`EPS` は $10^{-8}$ を表す `Real` 型の値です．<br>
問題に応じて調整してください．

`PI` は円周率を表す `Real` 型の値です．

## sign

```cpp
int sign(Real x)
```

$x$ の符号を返します．<br>
ただし， $\mathrm{-EPS} \leq x \leq \mathrm{EPS}$ のときに $0$ と判定します．

## eq

```cpp
bool eq(Real a, Real b)
```

$a = b$ であるか判定します．<br>
ただし， $|a - b| \leq \mathrm{EPS}$ であるときに等しいと判定します．