---
title: circle_2d
documentation_of: ../../src/geometry/circle_2d.hpp
---

# Circle

円を扱う構造体です．

## コンストラクタ

```cpp
Circle c(Point p, Real r)
```

点 `p` を中心とする半径 `r` の円 `c` を作ります．

## is_intersect_cp, is_intersect_cl, is_intersect_cc

```cpp
(1) bool is_intersect_cp(Circle c, Point p)
(2) bool is_intersect_cl(Circle c, Line l)
(3) int is_intersect_cc(Circle c1, Circle c2)
```

(1): 円 `c` と点 `p` が交点を持つかどうか判定します．<br>
(2): 円 `c` と直線 `l` が交点を持つかどうか判定します．<br>
(3): 円 `c1` と円 `c2` の共通接線の数を返します．

$2$ つの円 `c1, c2` について共通接線の本数は，

- 片方がもう片方を内接する場合 $0$ 本
- 内接する場合 $1$ 本
- 交わる場合 $2$ 本
- 外接する場合 $3$ 本
- 離れている場合 $4$ 本

です．

## intersection_cl, intersection_cs, intersection_cc

```cpp
(1) vector<Point> intersection_cl(Circle c, Line l)
(2) vector<Point> intersection_cs(Circle c, Segment s)
(3) vector<Point> intersection_cc(Circle c1, Circle c2)
```

(1): 円 `c` と直線 `l` の交点を全て返します．<br>
(2): 円 `c` と線分 `s` の交点を全て返します．<br>
(3): 円 `c1` と円 `c2` の交点を全て返します．

## tangent_cp, tangent_cc

```cpp
(1) vector<Point> tangent_cp(Circle c, Point p)
(2) vector<Line> tangent_cc(Circle c1, Circle c2)
```

(1): 点 `p` を通る円 `c` の接線の `c` との接点を全て返します．<br>
(2): 円 `c1` と円 `c2` の共通接線を全て返します．

## inscribed_circle, circumscribed_circle, appollonius

```cpp
(1) Circle inscribed_circle(Point a, Point b, Point c)
(2) Circle circumscribed_circle(Point a, Point b, Point c)
(3) Circle appollonius(Point p1, Point p2, Real a, Real b)
```

(1): 点 `a, b, c` が作る三角形の内接円を返します．<br>
(2): 点 `a, b, c` が作る三角形の外接円を返します．<br>
(3): $2$ 点 `p1, p2` からの距離の比が $a : b$ であるようなアポロニウスの円を返します．

## area_cc, area_pc

```cpp
(1) Real area_cc(Circle c1, Circle c2)
(2) Real area_pc(vector<Point> ps, Circle c)
```

(1): $2$ つの円 `c1, c2` の共通部分の面積を返します．<br>
(2): 多角形 `ps` と円 `c` の共通部分の面積を返します．