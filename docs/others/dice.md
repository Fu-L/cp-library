---
title: dice
documentation_of: ../../src/others/dice.hpp
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