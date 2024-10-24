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

`int` 型などの数値型だけでなく `pair` 型や `vector` 型や `map` 型や `set` 型や `bitset` 型や `modint` 型にも対応しています．<br>
`UnionFind` や `Graph` や `FenwickTree` などの構造体には現状では対応していません．

`make b` の際に `debug` が含まれる行が削除されます．<br>
`#include "template/debug.hpp"` や `debug(hoge)` を消す目的ですが，以下のように書いてしまうと消えるべきでない行が消えてしまうので注意が必要です．<br>
また"debug"という連続部分文字列を含む変数や関数の宣言にも気をつけてください．

```cpp
int n = 5; debug(n);
```

`modint` 型のデバッグに対応させるために，内部で `template/StaticModint.hpp` と `template/DynamicModint.hpp` をインクルードしています．<br>
`#include "template/debug.hpp"` をすると自動で `modint` 型が使えるようになりますが `make b` の際に内部インクルードが削除されるので， `main.cpp` 内でも `modint` をインクルードすることを忘れないようにしてください．