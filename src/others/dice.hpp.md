---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/others/0502.test.cpp
    title: verify/aizu_online_judge/others/0502.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/others/dice.hpp\"\n\
    #define roll_swap(x, a, b, c, d) swap(x.a, x.b), swap(x.b, x.c), swap(x.c, x.d);\n\
    struct Dice {\n    int top, front, right, left, back, bottom;\n    Dice(int to\
    \ = 1, int fr = 2, int ri = 3, int le = 4, int ba = 5, int bo = 6)\n        :\
    \ top(to), front(fr), right(ri), left(le), back(ba), bottom(bo) {}\n    void roll_right()\
    \ {\n        roll_swap((*this), top, left, bottom, right);\n    }\n    void roll_left()\
    \ {\n        roll_swap((*this), top, right, bottom, left);\n    }\n    void roll_front()\
    \ {\n        roll_swap((*this), top, back, bottom, front);\n    }\n    void roll_back()\
    \ {\n        roll_swap((*this), top, front, bottom, back);\n    }\n    void roll_cw()\
    \ {\n        roll_swap((*this), back, left, front, right);\n    }\n    void roll_ccw()\
    \ {\n        roll_swap((*this), back, right, front, left);\n    }\n    void roll(int\
    \ dir) {\n        if(dir == 0) (*this).roll_front();\n        if(dir == 1) (*this).roll_right();\n\
    \        if(dir == 2) (*this).roll_back();\n        if(dir == 3) (*this).roll_left();\n\
    \    }\n    friend bool operator<(const Dice& d1, const Dice& d2) {\n        int\
    \ vd1[] = {d1.top, d1.front, d1.right, d1.left, d1.back, d1.bottom};\n       \
    \ int vd2[] = {d2.top, d2.front, d2.right, d2.left, d2.back, d2.bottom};\n   \
    \     return vector<int>(vd1, vd1 + 6) < vector<int>(vd2, vd2 + 6);\n    }\n};\n\
    \nvector<Dice> all_rotate() {\n    vector<Dice> res;\n    res.reserve(24);\n \
    \   Dice d;\n    for(int i = 0; i < 6; ++i) {\n        for(int j = 0; j < 4; ++j)\
    \ {\n            res.emplace_back(d);\n            d.roll_cw();\n        }\n \
    \       if(i & 1) d.roll_front();\n        else d.roll_right();\n    }\n    return\
    \ res;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#define roll_swap(x,\
    \ a, b, c, d) swap(x.a, x.b), swap(x.b, x.c), swap(x.c, x.d);\nstruct Dice {\n\
    \    int top, front, right, left, back, bottom;\n    Dice(int to = 1, int fr =\
    \ 2, int ri = 3, int le = 4, int ba = 5, int bo = 6)\n        : top(to), front(fr),\
    \ right(ri), left(le), back(ba), bottom(bo) {}\n    void roll_right() {\n    \
    \    roll_swap((*this), top, left, bottom, right);\n    }\n    void roll_left()\
    \ {\n        roll_swap((*this), top, right, bottom, left);\n    }\n    void roll_front()\
    \ {\n        roll_swap((*this), top, back, bottom, front);\n    }\n    void roll_back()\
    \ {\n        roll_swap((*this), top, front, bottom, back);\n    }\n    void roll_cw()\
    \ {\n        roll_swap((*this), back, left, front, right);\n    }\n    void roll_ccw()\
    \ {\n        roll_swap((*this), back, right, front, left);\n    }\n    void roll(int\
    \ dir) {\n        if(dir == 0) (*this).roll_front();\n        if(dir == 1) (*this).roll_right();\n\
    \        if(dir == 2) (*this).roll_back();\n        if(dir == 3) (*this).roll_left();\n\
    \    }\n    friend bool operator<(const Dice& d1, const Dice& d2) {\n        int\
    \ vd1[] = {d1.top, d1.front, d1.right, d1.left, d1.back, d1.bottom};\n       \
    \ int vd2[] = {d2.top, d2.front, d2.right, d2.left, d2.back, d2.bottom};\n   \
    \     return vector<int>(vd1, vd1 + 6) < vector<int>(vd2, vd2 + 6);\n    }\n};\n\
    \nvector<Dice> all_rotate() {\n    vector<Dice> res;\n    res.reserve(24);\n \
    \   Dice d;\n    for(int i = 0; i < 6; ++i) {\n        for(int j = 0; j < 4; ++j)\
    \ {\n            res.emplace_back(d);\n            d.roll_cw();\n        }\n \
    \       if(i & 1) d.roll_front();\n        else d.roll_right();\n    }\n    return\
    \ res;\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/others/dice.hpp
  requiredBy: []
  timestamp: '2024-02-29 18:54:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/others/0502.test.cpp
documentation_of: src/others/dice.hpp
layout: document
title: dice
---

# Dice

サイコロ (乱数ではなく立体) を扱うライブラリです．

## コンストラクタ

```cpp
Dice d(int top, int front, int right, int left, int back, int bottom)
```

以下のようなサイコロを作ります．
- 上面が `top`
- 正面が `front`
- 右面が `right`
- 左面が `left`
- 背面が `back`
- 底面が `bottom`

## roll_right, roll_left, roll_front, roll_back, roll_cw, roll_ccw, roll

```cpp
(1) void d.roll_right()
(2) void d.roll_left()
(3) void d.roll_front()
(4) void d.roll_back()
(5) void d.roll_cw()
(6) void d.roll_ccw()
(7) void d.roll(int dir)
```

(1) サイコロを右方向に転がします．<br>
(2) サイコロを左方向に転がします．<br>
(3) サイコロを正面方向に転がします．<br>
(4) サイコロを後ろ方向に転がします．<br>
(5) サイコロを時計回りに回します．<br>
(6) サイコロを反時計回りに回します．<br>
(7) サイコロを以下の方向に転がします．<br>
- `dir = 1` のとき正面
- `dir = 2` のとき右
- `dir = 3` のとき後ろ
- `dir = 4` のとき左

## all_rotate

```cpp
vector<Dice> all_rotate()
```

24通りの全ての置き方のサイコロを生成します．