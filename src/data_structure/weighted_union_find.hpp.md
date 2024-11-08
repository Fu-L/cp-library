---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/dsl/weighted_union_find_trees.test.cpp
    title: verify/aizu_online_judge/dsl/weighted_union_find_trees.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/unionfind_with_potential.test.cpp
    title: verify/library_checker/data_structure/unionfind_with_potential.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/weighted_union_find.hpp\"\
    \ntemplate <typename T>\nstruct WeightedUnionFind {\n    WeightedUnionFind(const\
    \ int N)\n        : n(N), data(N, -1), ws(N, T()) {}\n    bool merge(const int\
    \ a, const int b, T w) {\n        assert(0 <= a and a < n);\n        assert(0\
    \ <= b and b < n);\n        w += weight(b) - weight(a);\n        int x = leader(a),\
    \ y = leader(b);\n        if(x == y) return w == T();\n        if(-data[x] > -data[y])\
    \ swap(x, y), w = -w;\n        data[y] += data[x];\n        data[x] = y;\n   \
    \     ws[x] = w;\n        return true;\n    }\n    bool same(const int a, const\
    \ int b) {\n        assert(0 <= a and a < n);\n        assert(0 <= b and b < n);\n\
    \        return leader(a) == leader(b);\n    }\n    int leader(const int a) {\n\
    \        assert(0 <= a and a < n);\n        if(data[a] < 0) return a;\n      \
    \  const int r = leader(data[a]);\n        ws[a] += ws[data[a]];\n        return\
    \ data[a] = r;\n    }\n    int size(const int a) {\n        assert(0 <= a and\
    \ a < n);\n        return -data[leader(a)];\n    }\n    T weight(const int a)\
    \ {\n        assert(0 <= a and a < n);\n        leader(a);\n        return ws[a];\n\
    \    }\n    T diff(const int a, const int b) {\n        assert(0 <= a and a <\
    \ n);\n        assert(0 <= b and b < n);\n        return weight(a) - weight(b);\n\
    \    }\n\n   private:\n    int n;\n    vector<int> data;\n    vector<T> ws;\n\
    };\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    struct WeightedUnionFind {\n    WeightedUnionFind(const int N)\n        : n(N),\
    \ data(N, -1), ws(N, T()) {}\n    bool merge(const int a, const int b, T w) {\n\
    \        assert(0 <= a and a < n);\n        assert(0 <= b and b < n);\n      \
    \  w += weight(b) - weight(a);\n        int x = leader(a), y = leader(b);\n  \
    \      if(x == y) return w == T();\n        if(-data[x] > -data[y]) swap(x, y),\
    \ w = -w;\n        data[y] += data[x];\n        data[x] = y;\n        ws[x] =\
    \ w;\n        return true;\n    }\n    bool same(const int a, const int b) {\n\
    \        assert(0 <= a and a < n);\n        assert(0 <= b and b < n);\n      \
    \  return leader(a) == leader(b);\n    }\n    int leader(const int a) {\n    \
    \    assert(0 <= a and a < n);\n        if(data[a] < 0) return a;\n        const\
    \ int r = leader(data[a]);\n        ws[a] += ws[data[a]];\n        return data[a]\
    \ = r;\n    }\n    int size(const int a) {\n        assert(0 <= a and a < n);\n\
    \        return -data[leader(a)];\n    }\n    T weight(const int a) {\n      \
    \  assert(0 <= a and a < n);\n        leader(a);\n        return ws[a];\n    }\n\
    \    T diff(const int a, const int b) {\n        assert(0 <= a and a < n);\n \
    \       assert(0 <= b and b < n);\n        return weight(a) - weight(b);\n   \
    \ }\n\n   private:\n    int n;\n    vector<int> data;\n    vector<T> ws;\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/weighted_union_find.hpp
  requiredBy: []
  timestamp: '2024-11-09 00:13:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/unionfind_with_potential.test.cpp
  - verify/aizu_online_judge/dsl/weighted_union_find_trees.test.cpp
documentation_of: src/data_structure/weighted_union_find.hpp
layout: document
title: WeightedUnionFind
---

# WeightedUnionFind

通常のUnionFindに加えて，

- 頂点に重みを持たせる
- 頂点の重みや頂点間の重みの差の取得
- 重みの情報が矛盾しないかの判定

ができます．

## コンストラクタ

```cpp
WeightedUnionFind<T> uf(int n)
```

- $n$ 頂点 $0$ 辺の無向グラフを作ります．
- 各頂点の重み $\mathrm{weight_i}$ は $0$ で初期化されます．

**計算量**

- $O(n)$

## merge

```cpp
bool uf.merge(int a, int b, T w)
```

辺 $(a, b)$ を追加し， $\mathrm{weight_a} = \mathrm{weight_b} + w$ と設定します．

今までの情報と矛盾が生じない場合は `true` を返し，矛盾が生じる場合は `false` を返します．<br>
矛盾が生じるとは `merge` を行う前の状態において，頂点 $a$ と $b$ が連結かつ$\mathrm{weight_a} - \mathrm{weight_b} \neq w$ であることを指します．

**制約**

- $0 \leq a < n$
- $0 \leq b < n$

**計算量**

- 償却 $O(\alpha(n))$

## same

```cpp
bool uf.same(int a, int b)
```

頂点 $a$ と $b$ が連結かどうかを返します．

**制約**

- $0 \leq a < n$
- $0 \leq b < n$

**計算量**

- 償却 $O(\alpha(n))$

## leader

```cpp
int uf.leader(int a)
```

頂点 $a$ の属する連結成分の代表元を返します．

**制約**

- $0 \leq a < n$

**計算量**

- 償却 $O(\alpha(n))$

## size

```cpp
int uf.size(int a)
```

頂点 $a$ の属する連結成分のサイズを返します．

**制約**

- $0 \leq a < n$

**計算量**

- 償却 $O(\alpha(n))$

## weight

```cpp
T uf.weight(int a)
```

$\mathrm{weight_a} - \mathrm{weight_{leader(a)}}$ を返します．

**制約**

- $0 \leq a < n$

**計算量**

- 償却 $O(\alpha(n))$

## diff

```cpp
T uf.diff(int a, int b)
```

$\mathrm{weight_a} - \mathrm{weight_b}$ を返します．

**制約**

- $0 \leq a < n$
- $0 \leq b < n$

**計算量**

- 償却 $O(\alpha(n))$
