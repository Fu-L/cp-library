---
title: FormalPowerSeriesLL
documentation_of: ../../src/fps/formal_power_series_ll.hpp
---

# FormalPowerSeriesLL

`long long` 型の範囲で扱う形式的冪級数です．

実装されている機能が `mint` 版に比べて絞られています．<br>
計算量等や使用法は `mint` 版と同じなのでそちらをご覧ください．<br>
実装されている機能は以下のとおりです．<br>

```cpp
FPSLL = FPSLL

-FPSLL

FPSLL += ll
FPSLL -= ll
FPSLL *= ll
FPSLL /= ll

FPSLL += FPSLL
FPSLL -= FPSLL
FPSLL *= FPSLL

FPSLL + ll
FPSLL - ll
FPSLL * ll
FPSLL / ll

FPSLL + FPSLL
FPSLL - FPSLL
FPSLL * FPSLL

FPSLL << int
FPSLL >> int

void FPSLL.onemul(int d, ll c, int deg = -1)
void FPSLL.onediv(int d, ll c, int deg = -1)

void FPSLL.shrink()
FPSLL FPSLL.rev()
FPSLL FPSLL.pre(int deg)
ll FPSLL.eval(ll a)
```