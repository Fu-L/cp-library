---
title: line_and_segment_2d
documentation_of: ../../src/geometry/line_and_segment_2d.hpp
---

# Line, Segment

直線および線分を扱う構造体です．

## コンストラクタ

```cpp
(1) Line l(Point a, Point b)
(2) Segment s(Point a, Point b)
```

(1): $2$ 点 `a, b` を通る直線 `l` を作ります．<br>
(2): $2$ 点 `a, b` を端点とする線分 `s` を作ります．

## is_parallel, is_orthogonal

```cpp
(1) bool is_parallel(Line a, Line b)
(2) bool is_orthogonal(Line a, Line b)
```

(1): $2$ 直線 `a, b` が平行であるかどうか判定します．<br>
(2): $2$ 直線 `a, b` が直交するかどうか判定します．

## projection, reflection

```cpp
(1) Point projection(Line l, Point p)
(2) Point reflection(Line l, Point p)
```

(1): 点 `p` から直線 `l` に下ろした垂線の足の座標を返します．<br>
(2): 直線 `l` を対称軸として点 `p` と線対称の位置にある点の座標を返します．

## is_intersect_lp, is_intersect_sp, is_intersect_ll, is_intersect_ls, is_intersect_sl, is_intersect_ss

```cpp
(1) bool is_intersect_lp(Line l, Point p)
(2) bool is_intersect_sp(Segment s, Point p)
(3) bool is_intersect_ll(Line l1, Line l2)
(4) bool is_intersect_ls(Line l, Segment s)
(5) bool is_intersect_sl(Segment s, Line l)
(6) bool is_intersect_ss(Segment s1, Segment s2)
```

(1): 直線 `l` と点 `p` が交点を持つかどうか判定します．<br>
(2): 線分 `s` と点 `p` が交点を持つかどうか判定します．<br>
(3): 直線 `l1` と直線 `l2` が交点を持つかどうか判定します．<br>
(4): 直線 `l` と線分 `s` が交点を持つかどうか判定します．<br>
(5): 線分 `s` と直線 `l` が交点を持つかどうか判定します．<br>
(6): 線分 `s1` と線分 `s2` が交点を持つかどうか判定します．

## intersection_ll, intersection_ss

```cpp
(1) vector<Point> intersection_ll(Line l1, Line l2)
(2) vector<Point> intersection_ss(Segment s1, Segment s2)
```

(1): 直線 `l1` と直線 `l2` の交点を高々 $1$ つ返します．<br>
(2): 線分 `s1` と線分 `s2` の交点を高々 $1$ つ返します．

## dist_lp, dist_sp, dist_ll, dist_ss, dist_ls, dist_sl

```cpp
(1) Real dist_lp(Line l, Point p)
(2) Real dist_sp(Segment s, Point p)
(3) Real dist_ll(Line l1, Line l2)
(4) Real dist_ss(Segment s1, Segment s2)
(5) Real dist_ls(Line l, Segment s)
(6) Real dist_sl(Segment s, Line l)
```

(1): 直線 `l` と点 `p` の距離を返します．<br>
(2): 線分 `s` と点 `p` の距離を返します．<br>
(3): 直線 `l1` と直線 `l2` の距離を返します．<br>
(4): 線分 `s1` と線分 `s2` の距離を返します．<br>
(5): 直線 `l` と線分 `s` の距離を返します．<br>
(6): 線分 `s` と直線 `l` の距離を返します．