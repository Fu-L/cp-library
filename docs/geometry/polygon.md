---
title: polygon_2d
documentation_of: ../../src/geometry/polygon_2d.hpp
---

多角形を扱うライブラリです．

## area

```cpp
Real area(vector<Point> polygon)
```

多角形 `polygon` の面積を返します．

`polygon` は多角形の隣り合う点を反時計回りに訪問するような順番で格納してある必要があります．

## is_convex

```cpp
bool is_convex(vector<Point> polygon)
```

多角形 `polygon` が凸多角形であるかどうか判定します．

`polygon` は多角形の隣り合う点を反時計回りに訪問するような順番で格納してある必要があります．

## in_polygon

```cpp
int in_polygon(vector<Point> polygon, Point p)
```

多角形 `polygon` と点 `p` の包含関係を返します．

`p` が `polygon` に含まれる場合は $2$ を，<br>
`p` が `polygon` の辺上にある場合は $1$ を，<br>
`p` が `polygon` の外部にある場合は $0$ を返します．

`polygon` は多角形の隣り合う点を反時計回りに訪問するような順番で格納してある必要があります．

## convex_hull

```cpp
vector<Point> convex_hull(vector<Point> ps)
```

点集合 `ps` の凸包を返します．<br>
ここでは，凸包の辺上にある点も省略せずに返します．

**計算量**

`ps` に含まれる点を $N$ 個として

- $O(N \log N)$

## convex_diameter

```cpp
Real convex_diameter(vector<Point> polygon)
```

凸多角形 `polygon` の直径を返します．<br>
凸多角形の直径とは，その最遠頂点対間距離のことです．

`polygon` は凸多角形の隣り合う点を反時計回りに訪問するような順番で格納してある必要があります．

## convex_cut

```cpp
vector<Point> convex_cut(vector<Point> polygon, Line l)
```

凸多角形 `polygon` を直線 `l` で切断したときにできる左側の凸多角形を返します．

`polygon` は凸多角形の隣り合う点を反時計回りに訪問するような順番で格納してある必要があります．