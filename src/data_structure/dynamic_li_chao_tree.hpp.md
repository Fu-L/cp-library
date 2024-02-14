---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/line_add_get_min.test.cpp
    title: verify/library_checker/data_structure/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/segment_add_get_min.test.cpp
    title: verify/library_checker/data_structure/segment_add_get_min.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/dynamic_li_chao_tree.hpp\"\
    \ntemplate <typename T, T x_low, T x_high>\nstruct DynamicLiChaoTree {\n    DynamicLiChaoTree()\n\
    \        : root{nullptr} {}\n    void add_line(const T& a, const T& b) {\n   \
    \     Line x(a, b);\n        root = add_line(root, x, x_low, x_high, x.get(x_low),\
    \ x.get(x_high));\n    }\n    void add_segment(const T& l, const T& r, const T&\
    \ a, const T& b) {\n        Line x(a, b);\n        root = add_segment(root, x,\
    \ l, r - 1, x_low, x_high, x.get(x_low), x.get(x_high));\n    }\n    T operator()(const\
    \ T& x) const {\n        assert(x_low <= x and x <= x_high);\n        return query(root,\
    \ x_low, x_high, x);\n    }\n\n   private:\n    struct Line {\n        T a, b;\n\
    \        Line(const T& a, const T& b)\n            : a(a), b(b) {}\n        inline\
    \ T get(const T& x) const {\n            return a * x + b;\n        }\n    };\n\
    \    struct Node {\n        Line x;\n        Node *l, *r;\n        Node(const\
    \ Line& x)\n            : x{x}, l{nullptr}, r{nullptr} {}\n    };\n    const T\
    \ id = numeric_limits<T>::max();\n    Node* root;\n    Node* add_line(Node* t,\
    \ Line& x, const T& l, const T& r, const T& x_l, const T& x_r) {\n        if(!t)\
    \ return new Node(x);\n        T t_l = t->x.get(l), t_r = t->x.get(r);\n     \
    \   if(t_l <= x_l and t_r <= x_r) {\n            return t;\n        } else if(t_l\
    \ >= x_l and t_r >= x_r) {\n            t->x = x;\n            return t;\n   \
    \     } else {\n            T m = (l + r) / 2;\n            if(m == r) --m;\n\
    \            T t_m = t->x.get(m), x_m = x.get(m);\n            if(t_m > x_m) {\n\
    \                swap(t->x, x);\n                if(x_l >= t_l) t->l = add_line(t->l,\
    \ x, l, m, t_l, t_m);\n                else t->r = add_line(t->r, x, m + 1, r,\
    \ t_m + x.a, t_r);\n            } else {\n                if(t_l >= x_l) t->l\
    \ = add_line(t->l, x, l, m, x_l, x_m);\n                else t->r = add_line(t->r,\
    \ x, m + 1, r, x_m + x.a, x_r);\n            }\n            return t;\n      \
    \  }\n    }\n    Node* add_segment(Node* t, Line& x, const T& a, const T& b, const\
    \ T& l, const T& r, const T& x_l, const T& x_r) {\n        if(r < a or b < l)\
    \ return t;\n        if(a <= l and r <= b) {\n            Line y{x};\n       \
    \     return add_line(t, y, l, r, x_l, x_r);\n        }\n        if(t) {\n   \
    \         T t_l = t->x.get(l), t_r = t->x.get(r);\n            if(t_l <= x_l and\
    \ t_r <= x_r) return t;\n        } else {\n            t = new Node(Line(0, id));\n\
    \        }\n        T m = (l + r) / 2;\n        if(m == r) --m;\n        T x_m\
    \ = x.get(m);\n        t->l = add_segment(t->l, x, a, b, l, m, x_l, x_m);\n  \
    \      t->r = add_segment(t->r, x, a, b, m + 1, r, x_m + x.a, x_r);\n        return\
    \ t;\n    }\n    T query(const Node* t, const T& l, const T& r, const T& x) const\
    \ {\n        if(!t) return id;\n        if(l == r) return t->x.get(x);\n     \
    \   T m = (l + r) / 2;\n        if(m == r) --m;\n        if(x <= m) return min(t->x.get(x),\
    \ query(t->l, l, m, x));\n        else return min(t->x.get(x), query(t->r, m +\
    \ 1, r, x));\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T,\
    \ T x_low, T x_high>\nstruct DynamicLiChaoTree {\n    DynamicLiChaoTree()\n  \
    \      : root{nullptr} {}\n    void add_line(const T& a, const T& b) {\n     \
    \   Line x(a, b);\n        root = add_line(root, x, x_low, x_high, x.get(x_low),\
    \ x.get(x_high));\n    }\n    void add_segment(const T& l, const T& r, const T&\
    \ a, const T& b) {\n        Line x(a, b);\n        root = add_segment(root, x,\
    \ l, r - 1, x_low, x_high, x.get(x_low), x.get(x_high));\n    }\n    T operator()(const\
    \ T& x) const {\n        assert(x_low <= x and x <= x_high);\n        return query(root,\
    \ x_low, x_high, x);\n    }\n\n   private:\n    struct Line {\n        T a, b;\n\
    \        Line(const T& a, const T& b)\n            : a(a), b(b) {}\n        inline\
    \ T get(const T& x) const {\n            return a * x + b;\n        }\n    };\n\
    \    struct Node {\n        Line x;\n        Node *l, *r;\n        Node(const\
    \ Line& x)\n            : x{x}, l{nullptr}, r{nullptr} {}\n    };\n    const T\
    \ id = numeric_limits<T>::max();\n    Node* root;\n    Node* add_line(Node* t,\
    \ Line& x, const T& l, const T& r, const T& x_l, const T& x_r) {\n        if(!t)\
    \ return new Node(x);\n        T t_l = t->x.get(l), t_r = t->x.get(r);\n     \
    \   if(t_l <= x_l and t_r <= x_r) {\n            return t;\n        } else if(t_l\
    \ >= x_l and t_r >= x_r) {\n            t->x = x;\n            return t;\n   \
    \     } else {\n            T m = (l + r) / 2;\n            if(m == r) --m;\n\
    \            T t_m = t->x.get(m), x_m = x.get(m);\n            if(t_m > x_m) {\n\
    \                swap(t->x, x);\n                if(x_l >= t_l) t->l = add_line(t->l,\
    \ x, l, m, t_l, t_m);\n                else t->r = add_line(t->r, x, m + 1, r,\
    \ t_m + x.a, t_r);\n            } else {\n                if(t_l >= x_l) t->l\
    \ = add_line(t->l, x, l, m, x_l, x_m);\n                else t->r = add_line(t->r,\
    \ x, m + 1, r, x_m + x.a, x_r);\n            }\n            return t;\n      \
    \  }\n    }\n    Node* add_segment(Node* t, Line& x, const T& a, const T& b, const\
    \ T& l, const T& r, const T& x_l, const T& x_r) {\n        if(r < a or b < l)\
    \ return t;\n        if(a <= l and r <= b) {\n            Line y{x};\n       \
    \     return add_line(t, y, l, r, x_l, x_r);\n        }\n        if(t) {\n   \
    \         T t_l = t->x.get(l), t_r = t->x.get(r);\n            if(t_l <= x_l and\
    \ t_r <= x_r) return t;\n        } else {\n            t = new Node(Line(0, id));\n\
    \        }\n        T m = (l + r) / 2;\n        if(m == r) --m;\n        T x_m\
    \ = x.get(m);\n        t->l = add_segment(t->l, x, a, b, l, m, x_l, x_m);\n  \
    \      t->r = add_segment(t->r, x, a, b, m + 1, r, x_m + x.a, x_r);\n        return\
    \ t;\n    }\n    T query(const Node* t, const T& l, const T& r, const T& x) const\
    \ {\n        if(!t) return id;\n        if(l == r) return t->x.get(x);\n     \
    \   T m = (l + r) / 2;\n        if(m == r) --m;\n        if(x <= m) return min(t->x.get(x),\
    \ query(t->l, l, m, x));\n        else return min(t->x.get(x), query(t->r, m +\
    \ 1, r, x));\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/dynamic_li_chao_tree.hpp
  requiredBy: []
  timestamp: '2024-02-15 00:10:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/line_add_get_min.test.cpp
  - verify/library_checker/data_structure/segment_add_get_min.test.cpp
documentation_of: src/data_structure/dynamic_li_chao_tree.hpp
layout: document
title: DynamicLiChaoTree
---

# DynamicLiChaoTree

- 直線 $y = ax + b$ の追加
- 線分 $y = ax + b ~ (l \leq x < r)$ の追加
- 与えられた $x$ 座標における直線・線分群の $y$ 座標の最小値の取得

を処理するデータ構造です．

`ConvexHullTrick` よりやや計算量は重いですが，単調性が必要ありません．

## コンストラクタ

```cpp
DynamicLiChaoTree<T, T x_low, T x_high> cht
```

空の直線・線分群 `cht` を構築します．

$x_{low}$ には `query` で与える $x$ の最小値を， $x_{high}$ には `query` で与える $x$ の最大値を与えてください．<br>
以下， $V = x_{high} - x_{low}$ とおきます．

**計算量**

- $O(1)$

## add_line

```cpp
void cht.add_line(T a, T b)
```

`cht` に直線 $y = ax + b$ を追加します．

**計算量**

- $O(\log V)$

## add_segment

```cpp
void cht.add_segment(T l, T r, T a, T b)
```

`cht` に線分 $y = ax + b ~ (l \leq x < r)$ を追加します．

**計算量**

- $O(\log V^2)$

## operator ()

```cpp
T cht(T x)
```

与えられた $x$ 座標における，直線・線分群 `cht` の $y$ 座標の最小値を取得します．

**制約**

- $x_{low} \leq x \leq x_{high}$

**計算量**

- $O(\log V)$