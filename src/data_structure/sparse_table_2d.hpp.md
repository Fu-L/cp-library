---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/data_structure/sparse_table_2d.test.cpp
    title: verify/unit_test/data_structure/sparse_table_2d.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/sparse_table_2d.hpp\"\
    \ntemplate <typename S, auto op, auto e>\nstruct SparseTable2D {\n    SparseTable2D(const\
    \ vector<vector<S>>& v)\n        : h((int)v.size()), w((int)v[0].size()), LOG(max(h,\
    \ w) + 1) {\n        rep(i, 2, (int)LOG.size()) LOG[i] = LOG[i / 2] + 1;\n   \
    \     table = vector<vector<vector<vector<S>>>>(LOG[h] + 1, vector<vector<vector<S>>>(LOG[w]\
    \ + 1, vector<vector<S>>(h, vector<S>(w, e()))));\n        for(int i = 0; i <\
    \ h; ++i) {\n            for(int j = 0; j < w; ++j) {\n                table[0][0][i][j]\
    \ = v[i][j];\n            }\n        }\n        for(int i = 0; i <= LOG[h]; ++i)\
    \ {\n            for(int j = 0; j <= LOG[w]; ++j) {\n                for(int x\
    \ = 0; x < h; ++x) {\n                    for(int y = 0; y < w; ++y) {\n     \
    \                   if(i < LOG[h]) table[i + 1][j][x][y] = op(table[i][j][x][y],\
    \ (x + (1 << i) < h) ? table[i][j][x + (1 << i)][y] : e());\n                \
    \        if(j < LOG[w]) table[i][j + 1][x][y] = op(table[i][j][x][y], (y + (1\
    \ << j) < w) ? table[i][j][x][y + (1 << j)] : e());\n                    }\n \
    \               }\n            }\n        }\n    }\n    S query(int lx, int rx,\
    \ int ly, int ry) const {\n        assert(0 <= lx and lx <= rx and rx <= h);\n\
    \        assert(0 <= ly and ly <= ry and ry <= w);\n        if(lx == rx or ly\
    \ == ry) return e();\n        int kx = LOG[rx - lx];\n        int ky = LOG[ry\
    \ - ly];\n        return op(op(table[kx][ky][lx][ly], table[kx][ky][rx - (1 <<\
    \ kx)][ly]), op(table[kx][ky][lx][ry - (1 << ky)], table[kx][ky][rx - (1 << kx)][ry\
    \ - (1 << ky)]));\n    }\n\n   private:\n    int h, w;\n    vector<vector<vector<vector<S>>>>\
    \ table;\n    vector<int> LOG;\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename S,\
    \ auto op, auto e>\nstruct SparseTable2D {\n    SparseTable2D(const vector<vector<S>>&\
    \ v)\n        : h((int)v.size()), w((int)v[0].size()), LOG(max(h, w) + 1) {\n\
    \        rep(i, 2, (int)LOG.size()) LOG[i] = LOG[i / 2] + 1;\n        table =\
    \ vector<vector<vector<vector<S>>>>(LOG[h] + 1, vector<vector<vector<S>>>(LOG[w]\
    \ + 1, vector<vector<S>>(h, vector<S>(w, e()))));\n        for(int i = 0; i <\
    \ h; ++i) {\n            for(int j = 0; j < w; ++j) {\n                table[0][0][i][j]\
    \ = v[i][j];\n            }\n        }\n        for(int i = 0; i <= LOG[h]; ++i)\
    \ {\n            for(int j = 0; j <= LOG[w]; ++j) {\n                for(int x\
    \ = 0; x < h; ++x) {\n                    for(int y = 0; y < w; ++y) {\n     \
    \                   if(i < LOG[h]) table[i + 1][j][x][y] = op(table[i][j][x][y],\
    \ (x + (1 << i) < h) ? table[i][j][x + (1 << i)][y] : e());\n                \
    \        if(j < LOG[w]) table[i][j + 1][x][y] = op(table[i][j][x][y], (y + (1\
    \ << j) < w) ? table[i][j][x][y + (1 << j)] : e());\n                    }\n \
    \               }\n            }\n        }\n    }\n    S query(int lx, int rx,\
    \ int ly, int ry) const {\n        assert(0 <= lx and lx <= rx and rx <= h);\n\
    \        assert(0 <= ly and ly <= ry and ry <= w);\n        if(lx == rx or ly\
    \ == ry) return e();\n        int kx = LOG[rx - lx];\n        int ky = LOG[ry\
    \ - ly];\n        return op(op(table[kx][ky][lx][ly], table[kx][ky][rx - (1 <<\
    \ kx)][ly]), op(table[kx][ky][lx][ry - (1 << ky)], table[kx][ky][rx - (1 << kx)][ry\
    \ - (1 << ky)]));\n    }\n\n   private:\n    int h, w;\n    vector<vector<vector<vector<S>>>>\
    \ table;\n    vector<int> LOG;\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/sparse_table_2d.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/data_structure/sparse_table_2d.test.cpp
documentation_of: src/data_structure/sparse_table_2d.hpp
layout: document
title: SparseTable2D
---

# SparseTable2D

冪等モノイド，つまり

- 結合則: $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ for all $a, b, c \in S$
- 単位元の存在: $a \cdot e = e \cdot a = a$ for all $a \in S$
- 冪等性: $a \cdot a = a$ for all $a \in S$

を満たす代数構造に対し使用できるデータ構造です．

サイズ $N \times M$ の $S$ の二次元配列に対し，

- 長方形領域の要素の総積の取得

を $O(1)$ で行うことができます．

ただし，これは二項演算 `op` と単位元取得 `e` が定数時間で動くと仮定したときの計算量です．<br>
これらが $O(f(n))$ かかる場合は，すべての計算量が $O(f(n))$ 倍となります．

また，要素を更新することはできません．

## コンストラクタ

```cpp
SparseTable2D<S, op, e> st(vector<vector<S>> v)
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
SparseTable2D<int, op, e> st(v);
```

のようになります．

- サイズ `n * m = ssize(v) * ssize(v[0])` の二次元数列 `a` を作ります．<br>
`v` の内容が初期値となります．

**計算量**

- $O(nm \log (nm))$

## query

```cpp
S st.query(int lx, int rx, int ly, int ry)
```

`op(a[lx][ly], a[lx][ly + 1], ..., a[lx][ry - 1], a[lx + 1][ly], ..., a[rx - 1][ry - 1])` を，冪等モノイドの性質を満たしていると仮定して返します．<br>
$lx = rx$ または $ly = ry$ のときは `e()` を返します．

**制約**

- $0 \leq lx \leq rx \leq n$
- $0 \leq ly \leq ry \leq n$

**計算量**

- $O(1)$