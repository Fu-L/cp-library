---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/segment_set.hpp\"\
    \ntemplate <typename T>\nstruct SegmentSet {\n    SegmentSet() = default;\n  \
    \  using const_iterator = typename map<T, T>::const_iterator;\n    const_iterator\
    \ begin() const {\n        return st.begin();\n    }\n    const_iterator end()\
    \ const {\n        return st.end();\n    }\n    const_iterator find(const T x)\
    \ const {\n        auto it = st.upper_bound(x);\n        if(it == st.begin() or\
    \ (--it)->second <= x) return st.end();\n        return it;\n    }\n    const_iterator\
    \ lower_bound(const T x) const {\n        auto it = st.lower_bound(x);\n     \
    \   if(it == st.begin() or prev(it)->second <= x) return it;\n        return prev(it);\n\
    \    }\n    void insert(T l, T r) {\n        auto L = st.upper_bound(l), R = st.upper_bound(r);\n\
    \        if(L != st.begin() and l <= prev(L)->second) --L;\n        if(L != R)\
    \ {\n            l = min(l, L->first);\n            r = max(r, prev(R)->second);\n\
    \            st.erase(L, R);\n        }\n        st[l] = r;\n    }\n    void erase(const\
    \ T l, const T r) {\n        auto L = st.upper_bound(l), R = st.upper_bound(r);\n\
    \        if(L != st.begin() and l <= prev(L)->second) --L;\n        if(L == R)\
    \ return;\n        const T nl = min(l, L->first), nr = max(r, prev(R)->second);\n\
    \        st.erase(L, R);\n        if(nl < l) st[nl] = l;\n        if(r < nr) st[r]\
    \ = nr;\n    }\n    T next(const T x) const {\n        auto it = this->lower_bound(x);\n\
    \        if(it == this->end()) return numeric_limits<T>::max();\n        return\
    \ max<T>(x, it->first);\n    }\n    size_t size() const {\n        return st.size();\n\
    \    }\n\n   private:\n    map<T, T> st;\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    struct SegmentSet {\n    SegmentSet() = default;\n    using const_iterator = typename\
    \ map<T, T>::const_iterator;\n    const_iterator begin() const {\n        return\
    \ st.begin();\n    }\n    const_iterator end() const {\n        return st.end();\n\
    \    }\n    const_iterator find(const T x) const {\n        auto it = st.upper_bound(x);\n\
    \        if(it == st.begin() or (--it)->second <= x) return st.end();\n      \
    \  return it;\n    }\n    const_iterator lower_bound(const T x) const {\n    \
    \    auto it = st.lower_bound(x);\n        if(it == st.begin() or prev(it)->second\
    \ <= x) return it;\n        return prev(it);\n    }\n    void insert(T l, T r)\
    \ {\n        auto L = st.upper_bound(l), R = st.upper_bound(r);\n        if(L\
    \ != st.begin() and l <= prev(L)->second) --L;\n        if(L != R) {\n       \
    \     l = min(l, L->first);\n            r = max(r, prev(R)->second);\n      \
    \      st.erase(L, R);\n        }\n        st[l] = r;\n    }\n    void erase(const\
    \ T l, const T r) {\n        auto L = st.upper_bound(l), R = st.upper_bound(r);\n\
    \        if(L != st.begin() and l <= prev(L)->second) --L;\n        if(L == R)\
    \ return;\n        const T nl = min(l, L->first), nr = max(r, prev(R)->second);\n\
    \        st.erase(L, R);\n        if(nl < l) st[nl] = l;\n        if(r < nr) st[r]\
    \ = nr;\n    }\n    T next(const T x) const {\n        auto it = this->lower_bound(x);\n\
    \        if(it == this->end()) return numeric_limits<T>::max();\n        return\
    \ max<T>(x, it->first);\n    }\n    size_t size() const {\n        return st.size();\n\
    \    }\n\n   private:\n    map<T, T> st;\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/segment_set.hpp
  requiredBy: []
  timestamp: '2024-11-09 00:13:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/segment_set.hpp
layout: document
title: SegmentSet
---

# SegmentSet

区間の集合を管理するデータ構造です．

## コンストラクタ

```cpp
SegmentSet<T> st
```

空の集合 `st` を作成します．

**計算量**

- $O(1)$

## insert

```cpp
void st.insert(T l, T r)
```

集合 `st` に区間 $[l, r)$ を追加します．

すでに入っている区間と重なりがある場合，それらの区間はマージされます． (サンプルコードを参照)

**計算量**

- 償却 $O(\log N)$ ( $N$ は入っている区間の個数)

## erase

```cpp
void st.erase(T l, T r)
```

集合 `st` から区間 $[l, r)$ を削除します．

元から入っていない部分については何も起こりません． (サンプルコード参照)

**計算量**

- 償却 $O(\log N)$

## next

```cpp
T st.next(T x)
```

集合 `st` に入っている区間に含まれる値のうち $x$ 以上の最小値を返します．

そのような値が存在しない場合，型 $T$ の最大値を返します．

**計算量**

- $O(\log N)$

## size

```cpp
size_t st.size()
```

集合 `st` に何個の区間が含まれているかを返します．<br>
マージされた区間は $1$ つとみなします．

**計算量**

- $O(1)$

## begin(), end(), find(), lower_bound()

```cpp
(1) iterator st.begin()
(2) iterator st.end()
(3) iterator st.find()
(4) iterator st.lower_bound()
```

`std::set` などと同じです．

## サンプルコード

```cpp
#include "src/template/template.hpp"
#include "src/data_structure/segment_set.hpp"
int main(void) {
    SegmentSet<int> st;
    st.insert(3, 7);            // st: {[3, 7)}
    st.insert(10, 15);          // st: {[3, 7), [10, 15)}
    st.insert(13, 20);          // st: {[3, 7), [10, 20)}
    st.erase(5, 13);            // st: {[3, 5), [13, 20)}
    cout << st.size() << '\n';  // 2
    for(auto it : st) {
        cout << it.first << ' ' << it.second << '\n';  // (3, 5), (13, 20)
    }
    cout << st.next(10) << '\n';   // 13
    cout << st.next(17) << '\n';   // 17
    cout << st.next(5) << '\n';    // 13
    cout << st.next(100) << '\n';  // INT_MAX
}
```