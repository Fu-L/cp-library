---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/set_xor_min.test.cpp
    title: verify/library_checker/data_structure/set_xor_min.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/binary_trie.hpp\"\
    \ntemplate <typename T, int MAX_LOG>\nstruct BinaryTrie {\n    BinaryTrie()\n\
    \        : root(new Node) {}\n    void insert(const T& x) {\n        assert(0\
    \ <= x and x < (T(1) << MAX_LOG));\n        if(!contains(x)) update(x, 1);\n \
    \   }\n    void erase(const T& x) {\n        assert(0 <= x and x < (T(1) << MAX_LOG));\n\
    \        if(contains(x)) update(x, -1);\n    }\n    bool contains(const T& x)\
    \ const {\n        assert(0 <= x and x < (T(1) << MAX_LOG));\n        Node* cur\
    \ = root;\n        for(int i = MAX_LOG - 1; i >= 0; --i) {\n            if(!cur)\
    \ break;\n            const int nex = (x >> i) & 1;\n            cur = cur->child[nex];\n\
    \        }\n        return cur and cur->cnt;\n    }\n    int size() const {\n\
    \        return root->cnt;\n    }\n    T min(const T& x = 0) const {\n       \
    \ assert(root->cnt > 0);\n        assert(0 <= x and x < (T(1) << MAX_LOG));\n\
    \        return kth_element(0, x);\n    }\n    T max(const T& x = 0) const {\n\
    \        assert(root->cnt > 0);\n        assert(0 <= x and x < (T(1) << MAX_LOG));\n\
    \        return kth_element(root->cnt - 1, x);\n    }\n    T kth_element(int k,\
    \ const T& x = 0) const {\n        assert(0 <= k and k < root->cnt);\n       \
    \ assert(0 <= x and x < (T(1) << MAX_LOG));\n        T res = 0;\n        Node*\
    \ cur = root;\n        for(int i = MAX_LOG - 1; i >= 0; --i) {\n            const\
    \ int nex = (x >> i) & 1;\n            const int cnt = (cur->child[nex] ? cur->child[nex]->cnt\
    \ : 0);\n            if(cnt <= k) {\n                k -= cnt;\n             \
    \   res += T(1) << i;\n                cur = cur->child[nex ^ 1];\n          \
    \  } else {\n                cur = cur->child[nex];\n            }\n        }\n\
    \        return res;\n    }\n    int lower_bound(const T& val, const T& x = 0)\
    \ const {\n        assert(0 <= val and val < (T(1) << MAX_LOG));\n        assert(0\
    \ <= x and x < (T(1) << MAX_LOG));\n        int res = 0;\n        Node* cur =\
    \ root;\n        for(int i = MAX_LOG - 1; i >= 0; --i) {\n            if(!cur)\
    \ break;\n            const int xi = (x >> i) & 1, vi = (val >> i) & 1;\n    \
    \        const int nex = xi xor vi;\n            if(vi and cur->child[xi]) {\n\
    \                res += cur->child[xi]->cnt;\n            }\n            cur =\
    \ cur->child[nex];\n        }\n        return res;\n    }\n    int upper_bound(const\
    \ T& val, const T& x = 0) const {\n        assert(0 <= val and val < (T(1) <<\
    \ MAX_LOG));\n        assert(0 <= x and x < (T(1) << MAX_LOG));\n        return\
    \ lower_bound(val + 1, x);\n    }\n\n   private:\n    struct Node {\n        Node*\
    \ child[2] = {};\n        int cnt = 0;\n        Node() {}\n    };\n    Node* root;\n\
    \    void update(const T& x, const int delta) {\n        Node* cur = root;\n \
    \       cur->cnt += delta;\n        for(int i = MAX_LOG - 1; i >= 0; --i) {\n\
    \            const int nex = (x >> i) & 1;\n            if(!cur->child[nex]) {\n\
    \                cur->child[nex] = new Node;\n            }\n            cur =\
    \ cur->child[nex];\n            cur->cnt += delta;\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T,\
    \ int MAX_LOG>\nstruct BinaryTrie {\n    BinaryTrie()\n        : root(new Node)\
    \ {}\n    void insert(const T& x) {\n        assert(0 <= x and x < (T(1) << MAX_LOG));\n\
    \        if(!contains(x)) update(x, 1);\n    }\n    void erase(const T& x) {\n\
    \        assert(0 <= x and x < (T(1) << MAX_LOG));\n        if(contains(x)) update(x,\
    \ -1);\n    }\n    bool contains(const T& x) const {\n        assert(0 <= x and\
    \ x < (T(1) << MAX_LOG));\n        Node* cur = root;\n        for(int i = MAX_LOG\
    \ - 1; i >= 0; --i) {\n            if(!cur) break;\n            const int nex\
    \ = (x >> i) & 1;\n            cur = cur->child[nex];\n        }\n        return\
    \ cur and cur->cnt;\n    }\n    int size() const {\n        return root->cnt;\n\
    \    }\n    T min(const T& x = 0) const {\n        assert(root->cnt > 0);\n  \
    \      assert(0 <= x and x < (T(1) << MAX_LOG));\n        return kth_element(0,\
    \ x);\n    }\n    T max(const T& x = 0) const {\n        assert(root->cnt > 0);\n\
    \        assert(0 <= x and x < (T(1) << MAX_LOG));\n        return kth_element(root->cnt\
    \ - 1, x);\n    }\n    T kth_element(int k, const T& x = 0) const {\n        assert(0\
    \ <= k and k < root->cnt);\n        assert(0 <= x and x < (T(1) << MAX_LOG));\n\
    \        T res = 0;\n        Node* cur = root;\n        for(int i = MAX_LOG -\
    \ 1; i >= 0; --i) {\n            const int nex = (x >> i) & 1;\n            const\
    \ int cnt = (cur->child[nex] ? cur->child[nex]->cnt : 0);\n            if(cnt\
    \ <= k) {\n                k -= cnt;\n                res += T(1) << i;\n    \
    \            cur = cur->child[nex ^ 1];\n            } else {\n              \
    \  cur = cur->child[nex];\n            }\n        }\n        return res;\n   \
    \ }\n    int lower_bound(const T& val, const T& x = 0) const {\n        assert(0\
    \ <= val and val < (T(1) << MAX_LOG));\n        assert(0 <= x and x < (T(1) <<\
    \ MAX_LOG));\n        int res = 0;\n        Node* cur = root;\n        for(int\
    \ i = MAX_LOG - 1; i >= 0; --i) {\n            if(!cur) break;\n            const\
    \ int xi = (x >> i) & 1, vi = (val >> i) & 1;\n            const int nex = xi\
    \ xor vi;\n            if(vi and cur->child[xi]) {\n                res += cur->child[xi]->cnt;\n\
    \            }\n            cur = cur->child[nex];\n        }\n        return\
    \ res;\n    }\n    int upper_bound(const T& val, const T& x = 0) const {\n   \
    \     assert(0 <= val and val < (T(1) << MAX_LOG));\n        assert(0 <= x and\
    \ x < (T(1) << MAX_LOG));\n        return lower_bound(val + 1, x);\n    }\n\n\
    \   private:\n    struct Node {\n        Node* child[2] = {};\n        int cnt\
    \ = 0;\n        Node() {}\n    };\n    Node* root;\n    void update(const T& x,\
    \ const int delta) {\n        Node* cur = root;\n        cur->cnt += delta;\n\
    \        for(int i = MAX_LOG - 1; i >= 0; --i) {\n            const int nex =\
    \ (x >> i) & 1;\n            if(!cur->child[nex]) {\n                cur->child[nex]\
    \ = new Node;\n            }\n            cur = cur->child[nex];\n           \
    \ cur->cnt += delta;\n        }\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2024-11-09 00:13:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/set_xor_min.test.cpp
documentation_of: src/data_structure/binary_trie.hpp
layout: document
title: BinaryTrie
---

# BinaryTrie

- 値の挿入・削除
- 値の検索
- 要素数の取得
- 全要素に `xor` を作用させる
- 最小値，最大値，ランダムアクセス
- lower_bound, upper_bound

を $O(d)$ で行えるデータ構造です．( $d$ は値の桁数)

## コンストラクタ

```cpp
BinaryTrie<T, MAX_LOG> trie
```

- $0$ 以上 $2^{MAX\\_LOG}$ 未満の値を格納できる空の `trie` を構築します．

**制約**

- $T$ は `int / uint / ll / ull`
- $2^{MAX\\_LOG}$ が $T$ で表現できる値に収まる

**計算量**

- $O(1)$

## insert

```cpp
void trie.insert(T x)
```

`trie` に $x$ を挿入します．<br>
すでに `trie` に $x$ が存在する場合は何もしません．

**制約**

- $0 \leq x < 2^{MAX\\_LOG}$

**計算量**

- $O(MAX\\_LOG)$

## erase

```cpp
void trie.erase(T x)
```

`trie` から $x$ を削除します．<br>
すでに `trie` に $x$ が存在しない場合は何もしません．

**制約**

- $0 \leq x < 2^{MAX\\_LOG}$

**計算量**

- $O(MAX\\_LOG)$

## contains

```cpp
bool trie.contains(T x)
```

`trie` に $x$ が含まれるかどうかを返します．

**制約**

- $0 \leq x < 2^{MAX\\_LOG}$

**計算量**

- $O(MAX\\_LOG)$

## size

```cpp
int trie.size()
```

`trie` に何個の要素が格納されているかを返します．

**計算量**

- $O(1)$

## min

```cpp
T trie.min(T x = 0)
```

`trie` に格納されている要素全てに対して $\mathrm{xor} ~ x$ を作用させたときの最小値を返します．

**制約**

- $0 \leq x < 2^{MAX\\_LOG}$

**計算量**

- $O(MAX\\_LOG)$

## max

```cpp
T trie.max(T x = 0)
```

`trie` に格納されている要素全てに対して $\mathrm{xor} ~ x$ を作用させたときの最大値を返します．

**制約**

- $0 \leq x < 2^{MAX\\_LOG}$

**計算量**

- $O(MAX\\_LOG)$

## kth_element

```cpp
T trie.kth_element(T x = 0)
```

`trie` に格納されている要素全てに対して $\mathrm{xor} ~ x$ を作用させたときの $k$ 番目に小さい値を返します．

**制約**

- $0 \leq k < \mathrm{trie.size()}$
- $0 \leq x < 2^{MAX\\_LOG}$

**計算量**

- $O(MAX\\_LOG)$

## lower_bound

```cpp
int trie.lower_bound(T val, T x = 0)
```

`trie` に格納されている要素全てに対して $\mathrm{xor} ~ x$ を作用させたときの $\mathrm{val}$ 以上の最小値が何番目に小さいかを返します．

**制約**

- $0 \leq \mathrm{val} < 2^{MAX\\_LOG}$
- $0 \leq x < 2^{MAX\\_LOG}$

**計算量**

- $O(MAX\\_LOG)$

## upper_bound

```cpp
int trie.upper_bound(T val, T x = 0)
```

`trie` に格納されている要素全てに対して $\mathrm{xor} ~ x$ を作用させたときの $\mathrm{val}$ より大きい最小値が何番目に小さいかを返します．

**制約**

- $0 \leq \mathrm{val} < 2^{MAX\\_LOG} - 1$
- $0 \leq x < 2^{MAX\\_LOG}$

**計算量**

- $O(MAX\\_LOG)$