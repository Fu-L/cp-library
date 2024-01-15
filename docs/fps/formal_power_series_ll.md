---
title: FormalPowerSeriesLL
documentation_of: ../../src/fps/formal_power_series_ll.hpp
---

# FormalPowerSeriesLL

`long long` 型の範囲で扱う形式的冪級数です．

実装されている機能が `mint` 版に比べて絞られています．<br>
計算量や使用法は `mint` 版と同じなのでそちらをご覧ください．<br>
実装されている機能は以下のとおりです．<br>

```cpp
fps = fps;

-fps;

fps += ll;
fps -= ll;
fps *= ll;
fps /= ll;

fps += fps;
fps -= fps;
fps *= fps;

fps + ll;
fps - ll;
fps * ll;
fps / ll;

fps + fps;
fps - fps;
fps * fps;

fps << int;
fps >> int;

void fps.onemul(int d, ll c, int deg = -1);
void fps.onediv(int d, ll c, int deg = -1);

void fps.shrink();
fps fps.rev();
fps fps.pre(int deg);
ll fps.eval(ll a);
```