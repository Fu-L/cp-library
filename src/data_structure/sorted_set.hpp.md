---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/template/policy_based_data_structure.hpp
    title: policy_based_data_structure
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yukicoder/649.test.cpp
    title: verify/yukicoder/649.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n\
    #define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a,\
    \ b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
    struct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 2 \"src/template/policy_based_data_structure.hpp\"\
    \n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    #include <ext/pb_ds/tag_and_trait.hpp>\nusing namespace __gnu_pbds;\n#line 4 \"\
    src/data_structure/sorted_set.hpp\"\nusing SortedSet = tree<ll, null_type, less<ll>,\
    \ rb_tree_tag, tree_order_statistics_node_update>;\nusing SortedMultiSet = tree<ll,\
    \ null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;\n"
  code: '#pragma once

    #include "../template/template.hpp"

    #include "../template/policy_based_data_structure.hpp"

    using SortedSet = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;

    using SortedMultiSet = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;'
  dependsOn:
  - src/template/template.hpp
  - src/template/policy_based_data_structure.hpp
  isVerificationFile: false
  path: src/data_structure/sorted_set.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yukicoder/649.test.cpp
documentation_of: src/data_structure/sorted_set.hpp
layout: document
title: SortedSet
---

# SortedSet

- 要素の挿入・削除
- 要素の検索
- 要素の個数の取得
- $k$ 番目に小さい値の取得
- $x$ 以上の最小値の取得

を $O(\log n)$ 時間で処理できます．

## コンストラクタ

```cpp
(1) SortedSet st
(2) SortedMultiSet mst
```

- (1): 空の平衡二分探索木 `st` を構築します．
- (2): 要素の重複をゆるした空の平衡二分探索木 `mst` を構築します．

**計算量**

- $O(1)$

## insert

```cpp
(1) pair<iterator, bool> st.insert(int x)
(2) pair<iterator, bool> mst.insert(int x)
```

`st` および `mst` に要素 $x$ を追加します．<br>
`st` にすでに $x$ が入っている場合は何もしません．

返り値として，イテレータと挿入が成功したかを示すフラグが得られます．

**計算量**

- $O(\log n)$

## erase

```cpp
(1) pair<iterator, bool> st.erase(int x)
(2) pair<iterator, bool> mst.erase(st.find_by_order(st.order_of_key(6)))
```

`st` および `mst` から要素 $x$ を削除します．<br>
すでに $x$ が入っていない場合は何もしません．<br>
`mst` に複数の $x$ が入っている場合，要素は $1$ つだけ削除されます．

返り値として，イテレータと削除が成功したかを示すフラグが得られます．

**計算量**

- $O(\log n)$

## find

```cpp
(1) iterator st.find(int x)
(2) iterator mst.find(int x)
```

要素 $x$ のイテレータを返します．<br>
要素がない場合，`st.end()` および `mst.end()` を返します．

**計算量**

- $O(\log n)$

## size

```cpp
(1) int st.size()
(2) int mst.size()
```

`st` や `mst` の中に入っている要素の個数を返します．

**計算量**

- $O(1)$

## find_by_order

```cpp
(1) iterator st.find_by_order(int k)
(2) iterator mst.find_by_order(int k)
```

$k$ 番目に小さい値のイテレータを返します．

**計算量**

- $O(\log n)$

## order_of_key

```cpp
(1) int st.order_of_key(int x)
(2) int mst.order_of_key(int x)
```

$x$ 以上の最小値が何番目に小さいかを返します．

**計算量**

- $O(\log n)$