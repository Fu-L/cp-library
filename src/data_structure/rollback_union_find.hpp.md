---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/others/1645.test.cpp
    title: verify/aizu_online_judge/others/1645.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/rollback_union_find.hpp\"\
    \nstruct RollbackUnionFind {\n    RollbackUnionFind(const int N)\n        : n(N),\
    \ data(N, -1), inner_snap(0) {\n    }\n    int merge(const int a, const int b)\
    \ {\n        assert(0 <= a and a < n);\n        assert(0 <= b and b < n);\n  \
    \      int x = leader(a), y = leader(b);\n        history.emplace(x, data[x]);\n\
    \        history.emplace(y, data[y]);\n        if(x == y) return x;\n        if(-data[x]\
    \ < -data[y]) swap(x, y);\n        data[x] += data[y];\n        data[y] = x;\n\
    \        return x;\n    }\n    bool same(const int a, const int b) const {\n \
    \       assert(0 <= a and a < n);\n        assert(0 <= b and b < n);\n       \
    \ return leader(a) == leader(b);\n    }\n    int leader(const int a) const {\n\
    \        assert(0 <= a and a < n);\n        if(data[a] < 0) return a;\n      \
    \  return leader(data[a]);\n    }\n    int size(const int a) const {\n       \
    \ assert(0 <= a and a < n);\n        return (-data[leader(a)]);\n    }\n    void\
    \ undo() {\n        assert((int)history.size() >= 2);\n        data[history.top().first]\
    \ = history.top().second;\n        history.pop();\n        data[history.top().first]\
    \ = history.top().second;\n        history.pop();\n    }\n    void snapshot()\
    \ {\n        inner_snap = (int)history.size() / 2;\n    }\n    int get_state()\
    \ const {\n        return (int)history.size() / 2;\n    }\n    void rollback(int\
    \ state = -1) {\n        if(state == -1) state = inner_snap;\n        state *=\
    \ 2;\n        assert(state <= (int)history.size());\n        while(state < (int)history.size())\
    \ undo();\n    }\n\n   private:\n    int n;\n    vector<int> data;\n    stack<pair<int,\
    \ int>> history;\n    int inner_snap;\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nstruct RollbackUnionFind\
    \ {\n    RollbackUnionFind(const int N)\n        : n(N), data(N, -1), inner_snap(0)\
    \ {\n    }\n    int merge(const int a, const int b) {\n        assert(0 <= a and\
    \ a < n);\n        assert(0 <= b and b < n);\n        int x = leader(a), y = leader(b);\n\
    \        history.emplace(x, data[x]);\n        history.emplace(y, data[y]);\n\
    \        if(x == y) return x;\n        if(-data[x] < -data[y]) swap(x, y);\n \
    \       data[x] += data[y];\n        data[y] = x;\n        return x;\n    }\n\
    \    bool same(const int a, const int b) const {\n        assert(0 <= a and a\
    \ < n);\n        assert(0 <= b and b < n);\n        return leader(a) == leader(b);\n\
    \    }\n    int leader(const int a) const {\n        assert(0 <= a and a < n);\n\
    \        if(data[a] < 0) return a;\n        return leader(data[a]);\n    }\n \
    \   int size(const int a) const {\n        assert(0 <= a and a < n);\n       \
    \ return (-data[leader(a)]);\n    }\n    void undo() {\n        assert((int)history.size()\
    \ >= 2);\n        data[history.top().first] = history.top().second;\n        history.pop();\n\
    \        data[history.top().first] = history.top().second;\n        history.pop();\n\
    \    }\n    void snapshot() {\n        inner_snap = (int)history.size() / 2;\n\
    \    }\n    int get_state() const {\n        return (int)history.size() / 2;\n\
    \    }\n    void rollback(int state = -1) {\n        if(state == -1) state = inner_snap;\n\
    \        state *= 2;\n        assert(state <= (int)history.size());\n        while(state\
    \ < (int)history.size()) undo();\n    }\n\n   private:\n    int n;\n    vector<int>\
    \ data;\n    stack<pair<int, int>> history;\n    int inner_snap;\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/rollback_union_find.hpp
  requiredBy: []
  timestamp: '2024-11-09 00:13:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/others/1645.test.cpp
documentation_of: src/data_structure/rollback_union_find.hpp
layout: document
title: RollbackUnionFind
---

# RollbackUnionFind

通常のUnionFindに加えて，

- 直前の `merge` の操作の取り消し
- グラフの状態を記憶
- 記憶した状態への巻き戻し

ができます．

## コンストラクタ

```cpp
RollbackUnionFind uf(int n)
```

- $n$ 頂点 $0$ 辺の無向グラフを作ります．

**計算量**

- $O(n)$

## merge

```cpp
int uf.merge(int a, int b)
```

辺 $(a, b)$ を足します．

頂点 $a$ と $b$ が連結だった場合はその代表元，非連結だった場合は新たな代表元を返します．

**制約**

- $0 \leq a < n$
- $0 \leq b < n$

**計算量**

- $O(\log n)$

## same

```cpp
bool uf.same(int a, int b)
```

頂点 $a$ と $b$ が連結かどうかを返します．

**制約**

- $0 \leq a < n$
- $0 \leq b < n$

**計算量**

- $O(\log n)$

## leader

```cpp
int uf.leader(int a)
```

頂点 $a$ の属する連結成分の代表元を返します．

**制約**

- $0 \leq a < n$

**計算量**

- $O(\log n)$

## size

```cpp
int uf.size(int a)
```

頂点 $a$ の属する連結成分のサイズを返します．

**制約**

- $0 \leq a < n$

**計算量**

- $O(\log n)$

## undo

```cpp
void uf.undo()
```

直前の `merge` の操作を取り消します．

**制約**

- 少なくとも一回の `merge` を行なっていること

**計算量**

- $O(1)$

## get_state

```cpp
int uf.get_state()
```

`merge` を何回行った状態であるかを返します．

**計算量**

- $O(1)$

## snapshot

```cpp
int uf.snapshot()
```

現在のグラフの状態を記憶します．

複数の状態を記憶することはできません．<br>
最後に呼び出したときの状態のみを記憶します．

**計算量**

- $O(1)$

## rollback

```cpp
void uf.rollback(int state = -1)
```

$\mathrm{state = -1}$ のとき，最新の `snapshot` で記憶した状態までグラフを巻き戻します．<br>
それ以外のとき， `merge` が $\mathrm{state}$ 回行われた状態へ戻します．

**制約**

- $\mathrm{state = -1}$ または $0 \leq \mathrm{state} \leq$ `merge` が呼び出された階数

**計算量**

- 償却 $O(1)$