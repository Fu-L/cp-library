---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_rmq.test.cpp
    title: verify/library_checker/data_structure/static_rmq.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/sparse_table.hpp\"\
    \ntemplate <typename S, auto op, auto e>\nstruct SparseTable {\n    SparseTable(const\
    \ vector<S>& v)\n        : n((int)v.size()) {\n        const int b = 32 - __builtin_clz(n);\n\
    \        table.assign(b, vector<S>(n, e()));\n        table[0] = v;\n        for(int\
    \ i = 1; i < b; ++i) {\n            const int w = 1 << (i - 1);\n            for(int\
    \ j = 0; j + w * 2 <= n; ++j) {\n                table[i][j] = op(table[i - 1][j],\
    \ table[i - 1][j + w]);\n            }\n        }\n    }\n    S prod(const int\
    \ l, const int r) const {\n        assert(0 <= l and l <= r and r <= n);\n   \
    \     if(l == r) return e();\n        const int b = 31 - __builtin_clz(r - l);\n\
    \        return op(table[b][l], table[b][r - (1 << b)]);\n    }\n\n   private:\n\
    \    int n;\n    vector<vector<S>> table;\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename S,\
    \ auto op, auto e>\nstruct SparseTable {\n    SparseTable(const vector<S>& v)\n\
    \        : n((int)v.size()) {\n        const int b = 32 - __builtin_clz(n);\n\
    \        table.assign(b, vector<S>(n, e()));\n        table[0] = v;\n        for(int\
    \ i = 1; i < b; ++i) {\n            const int w = 1 << (i - 1);\n            for(int\
    \ j = 0; j + w * 2 <= n; ++j) {\n                table[i][j] = op(table[i - 1][j],\
    \ table[i - 1][j + w]);\n            }\n        }\n    }\n    S prod(const int\
    \ l, const int r) const {\n        assert(0 <= l and l <= r and r <= n);\n   \
    \     if(l == r) return e();\n        const int b = 31 - __builtin_clz(r - l);\n\
    \        return op(table[b][l], table[b][r - (1 << b)]);\n    }\n\n   private:\n\
    \    int n;\n    vector<vector<S>> table;\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2025-02-05 15:45:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/static_rmq.test.cpp
documentation_of: src/data_structure/sparse_table.hpp
layout: document
title: SparseTable
---

# SparseTable

冪等モノイド，つまり

- 結合則: $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ for all $a, b, c \in S$
- 単位元の存在: $a \cdot e = e \cdot a = a$ for all $a \in S$
- 冪等性: $a \cdot a = a$ for all $a \in S$

を満たす代数構造に対し使用できるデータ構造です．

長さ $N$ の $S$ の配列に対し，

- 区間の要素の総積の取得

を $O(1)$ で行うことができます．

ただし，これは二項演算 `op` と単位元取得 `e` が定数時間で動くと仮定したときの計算量です．<br>
これらが $O(f(n))$ かかる場合は，すべての計算量が $O(f(n))$ 倍となります．

また，要素を更新することはできません．

## コンストラクタ

```cpp
SparseTable<S, op, e> st(vector<S> v)
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
SparseTable<int, op, e> st(v);
```

のようになります．

- 長さ `n = ssize(v)` の数列 `a` を作ります．<br>
`v` の内容が初期値となります．

**計算量**

- $O(n \log n)$

## prod

```cpp
S st.prod(int l, int r)
```

`op(a[l], a[l + 1], ..., a[r - 1])` を，冪等モノイドの性質を満たしていると仮定して返します．<br>
$l = r$ のときは `e()` を返します．

**制約**

- $0 \leq l \leq r \leq n$

**計算量**

- $O(1)$