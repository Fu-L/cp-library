---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/kruskal.hpp
    title: kruskal
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/minimum_spanning_tree.test.cpp
    title: verify/aizu_online_judge/grl/minimum_spanning_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/unionfind.test.cpp
    title: verify/library_checker/data_structure/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/minimum_spanning_tree.test.cpp
    title: verify/library_checker/graph/minimum_spanning_tree.test.cpp
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
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/union_find.hpp\"\
    \nstruct UnionFind {\n    UnionFind(const int N)\n        : n(N), data(N, -1)\
    \ {}\n    int merge(const int a, const int b) {\n        assert(0 <= a and a <\
    \ n);\n        assert(0 <= b and b < n);\n        int x = leader(a), y = leader(b);\n\
    \        if(x == y) return x;\n        if(-data[x] < -data[y]) swap(x, y);\n \
    \       data[x] += data[y];\n        data[y] = x;\n        return x;\n    }\n\
    \    bool same(const int a, const int b) {\n        assert(0 <= a and a < n);\n\
    \        assert(0 <= b and b < n);\n        return leader(a) == leader(b);\n \
    \   }\n    int leader(const int a) {\n        assert(0 <= a and a < n);\n    \
    \    if(data[a] < 0) return a;\n        return data[a] = leader(data[a]);\n  \
    \  }\n    int size(const int a) {\n        assert(0 <= a and a < n);\n       \
    \ return -data[leader(a)];\n    }\n    vector<vector<int>> groups() {\n      \
    \  vector<int> leader_buf(n), group_size(n);\n        for(int i = 0; i < n; ++i)\
    \ {\n            leader_buf[i] = leader(i);\n            ++group_size[leader_buf[i]];\n\
    \        }\n        vector<vector<int>> result(n);\n        for(int i = 0; i <\
    \ n; ++i) {\n            result[i].reserve(group_size[i]);\n        }\n      \
    \  for(int i = 0; i < n; ++i) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(remove_if(result.begin(), result.end(), [&](const\
    \ vector<int>& v) { return v.empty(); }), result.end());\n        return result;\n\
    \    }\n\n   private:\n    int n;\n    vector<int> data;\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nstruct UnionFind {\n\
    \    UnionFind(const int N)\n        : n(N), data(N, -1) {}\n    int merge(const\
    \ int a, const int b) {\n        assert(0 <= a and a < n);\n        assert(0 <=\
    \ b and b < n);\n        int x = leader(a), y = leader(b);\n        if(x == y)\
    \ return x;\n        if(-data[x] < -data[y]) swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n        return x;\n    }\n    bool same(const int a, const\
    \ int b) {\n        assert(0 <= a and a < n);\n        assert(0 <= b and b < n);\n\
    \        return leader(a) == leader(b);\n    }\n    int leader(const int a) {\n\
    \        assert(0 <= a and a < n);\n        if(data[a] < 0) return a;\n      \
    \  return data[a] = leader(data[a]);\n    }\n    int size(const int a) {\n   \
    \     assert(0 <= a and a < n);\n        return -data[leader(a)];\n    }\n   \
    \ vector<vector<int>> groups() {\n        vector<int> leader_buf(n), group_size(n);\n\
    \        for(int i = 0; i < n; ++i) {\n            leader_buf[i] = leader(i);\n\
    \            ++group_size[leader_buf[i]];\n        }\n        vector<vector<int>>\
    \ result(n);\n        for(int i = 0; i < n; ++i) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for(int i = 0; i < n; ++i) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(remove_if(result.begin(), result.end(), [&](const\
    \ vector<int>& v) { return v.empty(); }), result.end());\n        return result;\n\
    \    }\n\n   private:\n    int n;\n    vector<int> data;\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/union_find.hpp
  requiredBy:
  - src/graph/kruskal.hpp
  timestamp: '2024-11-09 01:50:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/unionfind.test.cpp
  - verify/library_checker/graph/minimum_spanning_tree.test.cpp
  - verify/aizu_online_judge/grl/minimum_spanning_tree.test.cpp
documentation_of: src/data_structure/union_find.hpp
layout: document
title: UnionFind
---

# UnionFind

- 頂点集合のマージ
- $2$ 頂点が連結かの判定
- 頂点集合の代表元の取得
- 頂点集合のサイズの取得
- 頂点集合の列挙

を償却 $O(\alpha(n))$ 時間で処理することができます．

## コンストラクタ

```cpp
UnionFind uf(int n)
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

## groups

```cpp
vector<vector<int>> uf.groups()
```

グラフを連結成分に分け，その情報を返します．

返り値は「「一つの連結成分の頂点番号のリスト」のリスト」です．<br>
(内側外側限らず) vector内でどの順番で頂点が格納されているかは未定義です．

**計算量**

- $O(n)$