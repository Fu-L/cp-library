---
title: debug
documentation_of: ../../src/template/debug.hpp
---

## debug

```cpp
debug(hoge)
```

変数 `hoge` の行数，名前，中身を表示するデバッグマクロです．<br>

```cpp
debug(hoge, fuga, piyo)
```

などのように複数入力しても大丈夫です．

`int` 型などの数値型だけでなく `pair` 型や `tuple` 型や `vector` 型や `map` 型や `set` 型や `bitset` 型などにも対応しています．<br>
また `optional` 型や `variant` 型， `stack` 型や `queue` 型や `priority_queue` 型， `operator<<` で出力できる型にも対応しています．<br>
`UnionFind` や `Graph` や `FenwickTree` などの構造体には現状では対応していません．

`make b` の際に `debug` が含まれる行が削除されます．<br>
`#include "template/debug.hpp"` や `debug(hoge)` を消す目的ですが，以下のように書いてしまうと消えるべきでない行が消えてしまうので注意が必要です．<br>
また"debug"という連続部分文字列を含む変数や関数の宣言にも気をつけてください．

```cpp
int n = 5; debug(n);
```

`modint` 型は `operator<<` で出力できるため， `modint/static_modint.hpp` や `modint/dynamic_modint.hpp` を明示的にインクルードしていればデバッグできます．<br>
`debug.hpp` 自体は `modint` をインクルードしないので， `debug.hpp` を入れただけで `modint` 型が使えるようにはなりません．