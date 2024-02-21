---
title: point_2d
documentation_of: ../../src/geometry/point_2d.hpp
---

# Point

2次元平面上の点を扱う構造体です．

内部的には `Point` は `complex<Real>` のエイリアスです．<br>

## コンストラクタ

```cpp
Point p(Real x, Real y)
```

座標が $(x, y)$ であるような点 `p` を作ります．

`p` の $x$ 座標へのアクセスは `p.real()` で， $y$ 座標へのアクセスは `p.imag()` でできます．

演算子として以下のものが使えます．<br>
いずれも複素数の演算として扱われます．

```cpp
Point + Point
Point - Point
Point * Point
Point / Point
Point * Real
Point / Real
```

また，以下のようにして入出力も行えます．

```cpp
Point p;
cin >> p;
cout << p
```

さらにSTLに入っている `complex` 型の関数も使えます．

```cpp
Real abs(Point p)  // pの絶対値
Real norm(Point p)  // pの2乗ノルム
Real arg(Point p)  // pの偏角
Point conj(Point p)  // pの共役複素数
Point proj(Point p)  // pのリーマン球面への射影
Point polar(Real r, Real theta)  // 極座標が(r, theta)である点
```

## rot

```cpp
Point rot(Point p, Real theta)
```

点 `p` を原点中心に角 $\mathrm{theta}$ だけ回転させた点を返します．

## dot, cross

```cpp
(1) Real dot(Point p1, Point p2)
(2) Real cross(Point p1, Point p2)
```

(1) 点 `p1` と点 `p2` の内積をとった値を返します．

(2) 点 `p1` と点 `p2` の外積をとった値を返します．

## dist

```cpp
Real dist(Point p1, Point p2)
```

点 `p1` と `p2` の距離を返します．

## comp_x, comp_y, comp_arg

```cpp
(1) bool comp_x(Point p1, Point p2)
(2) bool comp_y(Point p1, Point p2)
(3) bool comp_arg(Point p1, Point p2)
```

ソート等の比較関数用の関数です．

(1)は $x$ 座標の昇順にソートしたいとき，(2)は $y$ 座標の昇順にソートしたいとき，(3)は偏角の昇順にソートしたいときに使えます．

## ccw

```cpp
int ccw(Point a, Point b, Point c)
```

点 `a, b` に対する点 `c` の位置を返します．

点 `a, b, c` が反時計回りになる (点 `c` が直線 `a, b` の左側にある) 場合は $1$ を，<br>
点 `a, b, c` が時計回りになる (点 `c` が直線 `a, b` の右側にある) 場合は $-1$ を，<br>
点 `c, a, b` がこの順で同一直線上にある場合は $2$ を，<br>
点 `a, b, c` がこの順で同一直線上にある場合は $-2$ を，<br>
点 `c` が線分 `a, b` 上にある場合は $0$ を返します．

## closest_pair

```cpp
Real closest_pair(vector<Point> ps)
```

`ps` に含まれる点のうち，最も近い $2$ 点の距離を返します．

**計算量**

`ps` に含まれる点を $N$ 個として

- $O(N \log N)$