---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
    title: verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/slide_window_aggregation_deque.hpp\"\
    \ntemplate <typename S, auto op, auto e>\nstruct SlideWindowAggregationDeque {\n\
    \    void push_front(const S& t) {\n        push0(t);\n    }\n    void push_back(const\
    \ S& t) {\n        push1(t);\n    }\n    S front() const {\n        return a0.empty()\
    \ ? a1.front() : a0.back();\n    }\n    S back() const {\n        return a1.empty()\
    \ ? a0.front() : a1.back();\n    }\n    void pop_front() {\n        if(a0.empty())\
    \ rebalance();\n        assert(!a0.empty());\n        a0.pop_back(), r0.pop_back();\n\
    \    }\n    void pop_back() {\n        if(a1.empty()) rebalance();\n        assert(!a1.empty());\n\
    \        a1.pop_back(), r1.pop_back();\n    }\n    S query() {\n        return\
    \ op(get0(), get1());\n    }\n\n   private:\n    vector<S> a0, a1, r0, r1;\n \
    \   S get0() const {\n        return r0.empty() ? e() : r0.back();\n    }\n  \
    \  S get1() const {\n        return r1.empty() ? e() : r1.back();\n    }\n   \
    \ void push0(const S& x) {\n        a0.emplace_back(x);\n        r0.emplace_back(op(x,\
    \ get0()));\n    }\n    void push1(const S& x) {\n        a1.emplace_back(x);\n\
    \        r1.emplace_back(op(get1(), x));\n    }\n    void rebalance() {\n    \
    \    const int n = a0.size() + a1.size();\n        const int s0 = n / 2 + (a0.empty()\
    \ ? n % 2 : 0);\n        vector<S> a{a0};\n        reverse(begin(a), end(a));\n\
    \        copy(begin(a1), end(a1), back_inserter(a));\n        a0.clear(), r0.clear();\n\
    \        a1.clear(), r1.clear();\n        for(int i = s0 - 1; i >= 0; --i) push0(a[i]);\n\
    \        for(int i = s0; i < n; ++i) push1(a[i]);\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename S,\
    \ auto op, auto e>\nstruct SlideWindowAggregationDeque {\n    void push_front(const\
    \ S& t) {\n        push0(t);\n    }\n    void push_back(const S& t) {\n      \
    \  push1(t);\n    }\n    S front() const {\n        return a0.empty() ? a1.front()\
    \ : a0.back();\n    }\n    S back() const {\n        return a1.empty() ? a0.front()\
    \ : a1.back();\n    }\n    void pop_front() {\n        if(a0.empty()) rebalance();\n\
    \        assert(!a0.empty());\n        a0.pop_back(), r0.pop_back();\n    }\n\
    \    void pop_back() {\n        if(a1.empty()) rebalance();\n        assert(!a1.empty());\n\
    \        a1.pop_back(), r1.pop_back();\n    }\n    S query() {\n        return\
    \ op(get0(), get1());\n    }\n\n   private:\n    vector<S> a0, a1, r0, r1;\n \
    \   S get0() const {\n        return r0.empty() ? e() : r0.back();\n    }\n  \
    \  S get1() const {\n        return r1.empty() ? e() : r1.back();\n    }\n   \
    \ void push0(const S& x) {\n        a0.emplace_back(x);\n        r0.emplace_back(op(x,\
    \ get0()));\n    }\n    void push1(const S& x) {\n        a1.emplace_back(x);\n\
    \        r1.emplace_back(op(get1(), x));\n    }\n    void rebalance() {\n    \
    \    const int n = a0.size() + a1.size();\n        const int s0 = n / 2 + (a0.empty()\
    \ ? n % 2 : 0);\n        vector<S> a{a0};\n        reverse(begin(a), end(a));\n\
    \        copy(begin(a1), end(a1), back_inserter(a));\n        a0.clear(), r0.clear();\n\
    \        a1.clear(), r1.clear();\n        for(int i = s0 - 1; i >= 0; --i) push0(a[i]);\n\
    \        for(int i = s0; i < n; ++i) push1(a[i]);\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/slide_window_aggregation_deque.hpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
documentation_of: src/data_structure/slide_window_aggregation_deque.hpp
layout: document
title: SlideWindowAggregationDeque
---

# SlideWindowAggregationDeque

モノイド，つまり

- 結合則: $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ for all $a, b, c \in S$
- 単位元の存在: $a \cdot e = e \cdot a = a$ for all $a \in S$

を満たす代数構造に対し使用できるデータ構造です．

- dequeの操作
- deque内部の全要素の総積の取得

を償却 $O(1)$ で計算できます．

ただし，これは二項演算 `op` と単位元取得 `e` が定数時間で動くと仮定したときの計算量です．<br>
これらが $O(f(n))$ かかる場合は，すべての計算量が $O(f(n))$ 倍となります．

## コンストラクタ

```cpp
SlideWindowAggregationDeque<S, op, e> swag
```

空のデック `swag` を作ります．

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
SlideWindowAggregationDeque<int, op, e> swag;
```

のようになります．

**計算量**

- $O(1)$

## push_front

```cpp
void swag.push_front(S x)
```

`swag` の先頭に $x$ を挿入します．

**計算量**

- 償却 $O(1)$

## push_back

```cpp
void swag.push_bacl(S x)
```

`swag` の末尾に $x$ を挿入します．

**計算量**

- 償却 $O(1)$

## pop_front

```cpp
void swag.pop_front()
```

`swag` から先頭の要素を削除します．

**制約**

- `swag` が空でない

**計算量**

- 償却 $O(1)$

## pop_back

```cpp
void swag.pop_back()
```

`swag` から末尾の要素を削除します．

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