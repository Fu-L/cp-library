---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/convex_hull_trick.hpp\"\
    \ntemplate <typename T>\nstruct ConvexHullTrick {\n    void add(const T& a, const\
    \ T& b) {\n        Linear l(a, b);\n        assert((int)ls.size() == 0 or ls.back().a\
    \ >= l.a);\n        int len = (int)ls.size();\n        while(len >= 2 and check(ls[len\
    \ - 2], ls[len - 1], l)) {\n            --len;\n            ls.pop_back();\n \
    \       }\n        ls.push_back(l);\n    }\n    T operator()(const T& x) {\n \
    \       assert(x >= x_last);\n        while((int)ls.size() >= 2 and ls[0](x) >=\
    \ ls[1](x)) {\n            ls.pop_front();\n        }\n        x_last = x;\n \
    \       return ls[0](x);\n    }\n\n   private:\n    struct Linear {\n        T\
    \ a, b;\n        Linear(const T& a = 0, const T& b = 0)\n            : a(a), b(b)\
    \ {}\n        inline T operator()(const T& x) const {\n            return a *\
    \ x + b;\n        }\n    };\n    inline bool check(const Linear& f1, const Linear&\
    \ f2, const Linear& f3) const {\n        return (f2.a - f1.a) * (f3.b - f2.b)\
    \ >= (f2.b - f1.b) * (f3.a - f2.a);\n    }\n    deque<Linear> ls;\n    T x_last\
    \ = numeric_limits<T>::min();\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    struct ConvexHullTrick {\n    void add(const T& a, const T& b) {\n        Linear\
    \ l(a, b);\n        assert((int)ls.size() == 0 or ls.back().a >= l.a);\n     \
    \   int len = (int)ls.size();\n        while(len >= 2 and check(ls[len - 2], ls[len\
    \ - 1], l)) {\n            --len;\n            ls.pop_back();\n        }\n   \
    \     ls.push_back(l);\n    }\n    T operator()(const T& x) {\n        assert(x\
    \ >= x_last);\n        while((int)ls.size() >= 2 and ls[0](x) >= ls[1](x)) {\n\
    \            ls.pop_front();\n        }\n        x_last = x;\n        return ls[0](x);\n\
    \    }\n\n   private:\n    struct Linear {\n        T a, b;\n        Linear(const\
    \ T& a = 0, const T& b = 0)\n            : a(a), b(b) {}\n        inline T operator()(const\
    \ T& x) const {\n            return a * x + b;\n        }\n    };\n    inline\
    \ bool check(const Linear& f1, const Linear& f2, const Linear& f3) const {\n \
    \       return (f2.a - f1.a) * (f3.b - f2.b) >= (f2.b - f1.b) * (f3.a - f2.a);\n\
    \    }\n    deque<Linear> ls;\n    T x_last = numeric_limits<T>::min();\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/data_structure/convex_hull_trick.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/convex_hull_trick.hpp
layout: document
title: ConvexHullTrick
---

# ConvexHullTrick

- 直線 $y = ax + b$ の追加
- 与えられた $x$ 座標における直線群の $y$ 座標の最小値の取得

をならし $O(1)$ で処理するデータ構造です．

ただし，追加される直線の $a$ は単調非増加である必要があります．<br>
また，最小値クエリの $x$ は単調非減少である必要があります．

## コンストラクタ

```cpp
ConvecHullTrick<T> cht
```

空の直線群 `cht` を構築します．

**計算量**

- $O(1)$

## add

```cpp
void cht.add(T a, T b)
```

`cht` に直線 $y = ax + b$ を追加します．

**制約**

- $a$ は単調非増加

**計算量**

- 償却 $O(1)$

## operator ()

```cpp
T cht(T x)
```

与えられた $x$ 座標における，直線群 `cht` の $y$ 座標の最小値を取得します．

**制約**

- $x$ は単調非減少

**計算量**

- 償却 $O(1)$