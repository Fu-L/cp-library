---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/queue_operate_all_composite.test.cpp
    title: verify/library_checker/data_structure/queue_operate_all_composite.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/slide_window_aggregation.hpp\"\
    \ntemplate <typename S, auto op, auto e>\nstruct SlideWindowAggregation {\n  \
    \  SlideWindowAggregation()\n        : f0(e()), f1(e()) {}\n    void push(const\
    \ S& x) {\n        if(a0.empty()) {\n            push_s0(x);\n            transfer();\n\
    \        } else {\n            push_s1(x);\n        }\n    }\n    void pop() {\n\
    \        if(a0.empty()) transfer();\n        a0.pop_back();\n        r0.pop_back();\n\
    \        f0 = r0.empty() ? e() : r0.back();\n    }\n    S query() {\n        return\
    \ op(f0, f1);\n    }\n\n   private:\n    vector<S> a0, a1, r0, r1;\n    S f0,\
    \ f1;\n    void push_s0(const S& x) {\n        a0.emplace_back(x);\n        r0.emplace_back(f0\
    \ = op(x, f0));\n    }\n    void push_s1(const S& x) {\n        a1.emplace_back(x);\n\
    \        r1.emplace_back(f1 = op(f1, x));\n    }\n    void transfer() {\n    \
    \    while(!a1.empty()) {\n            push_s0(a1.back());\n            a1.pop_back();\n\
    \        }\n        while(!r1.empty()) r1.pop_back();\n        f1 = e();\n   \
    \ }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename S,\
    \ auto op, auto e>\nstruct SlideWindowAggregation {\n    SlideWindowAggregation()\n\
    \        : f0(e()), f1(e()) {}\n    void push(const S& x) {\n        if(a0.empty())\
    \ {\n            push_s0(x);\n            transfer();\n        } else {\n    \
    \        push_s1(x);\n        }\n    }\n    void pop() {\n        if(a0.empty())\
    \ transfer();\n        a0.pop_back();\n        r0.pop_back();\n        f0 = r0.empty()\
    \ ? e() : r0.back();\n    }\n    S query() {\n        return op(f0, f1);\n   \
    \ }\n\n   private:\n    vector<S> a0, a1, r0, r1;\n    S f0, f1;\n    void push_s0(const\
    \ S& x) {\n        a0.emplace_back(x);\n        r0.emplace_back(f0 = op(x, f0));\n\
    \    }\n    void push_s1(const S& x) {\n        a1.emplace_back(x);\n        r1.emplace_back(f1\
    \ = op(f1, x));\n    }\n    void transfer() {\n        while(!a1.empty()) {\n\
    \            push_s0(a1.back());\n            a1.pop_back();\n        }\n    \
    \    while(!r1.empty()) r1.pop_back();\n        f1 = e();\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/slide_window_aggregation.hpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/queue_operate_all_composite.test.cpp
documentation_of: src/data_structure/slide_window_aggregation.hpp
layout: document
title: SlideWindowAggregation
---

# SlideWindowAggregation

モノイド，つまり

- 結合則: $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ for all $a, b, c \in S$
- 単位元の存在: $a \cdot e = e \cdot a = a$ for all $a \in S$

を満たす代数構造に対し使用できるデータ構造です．

- queueの操作
- queue内部の全要素の総積の取得

を償却 $O(1)$ で計算できます．

ただし，これは二項演算 `op` と単位元取得 `e` が定数時間で動くと仮定したときの計算量です．<br>
これらが $O(f(n))$ かかる場合は，すべての計算量が $O(f(n))$ 倍となります．

## コンストラクタ

```cpp
SlideWindowAggregation<S, op, e> swag
```

空のキュー `swag` を作ります．

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
SlideWindowAggregation<int, op, e> swag;
```

のようになります．

**計算量**

- $O(1)$

## push

```cpp
void swag.push(S x)
```

`swag` の末尾に $x$ を挿入します．

**計算量**

- 償却 $O(1)$

## pop

```cpp
void swag.pop()
```

`swag` から先頭の要素を削除します．

**制約**

- `swag` が空でない

**計算量**

- 償却 $O(1)$

## query

```cpp
S swag.query()
```

`op(swag[0], ..., swag[|swag| - 1])` を，モノイドの性質を満たしていると仮定して計算します．

**計算量**

- $O(1)$