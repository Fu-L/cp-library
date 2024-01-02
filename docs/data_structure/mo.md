---
title: Mo
documentation_of: ../../src/data_structure/mo.hpp
---

# Mo

- 配列の要素が不変
- クエリの先読みができる
- 区間クエリ $[l, r)$ の結果から $[l - 1, r), [l + 1, r), [l, r - 1), [l, r + 1)$ の結果を高速に計算できる ( $O(\alpha)$ と仮定)

以上の $3$ つの条件を満たすとき， $Q$ 個のクエリの結果を $O(\alpha N \sqrt{Q} + Q \log Q)$ で計算するデータ構造です． ( $N$ は配列長)

## コンストラクタ

```cpp
Mo mo(int N, int Q)
```

配列長 $N$ ，クエリ数 $Q$ として初期化します．

**計算量**

- $O(Q)$

## insert

```cpp
void mo.insert(int l, int r)
```

区間クエリ $[l, r)$ を追加します．

**制約**

- $0 \leq l \leq r \leq N$

**計算量**

- $O(1)$

## run

```cpp
void mo.run(auto add_left, auto add_right, auto delete_left, auto delete_right, auto out)
```

全クエリの結果を計算します．<br>

`add_left` は区間クエリ $[l, r)$ の結果から $[l - 1, r)$ の結果を計算する関数です．<br>
`add_right` は区間クエリ $[l, r)$ の結果から $[l, r + 1)$ の結果を計算する関数です．<br>
`delete_left` は区間クエリ $[l, r)$ の結果から $[l + 1, r)$ の結果を計算する関数です．<br>
`delete_right` は区間クエリ $[l, r)$ の結果から $[l, r - 1)$ の結果を計算する関数です．<br>
`out` は区間を伸縮させた結果を元に，答えを格納する配列に値を書き込む関数です．

`main` 関数でラムダ式などの形で定義して引数に入れてください．

例えば `add_left` や `out` は以下のように定義できます．

```cpp
auto add_left = [&](int idx) -> void{
    // [idx + 1, r) の結果から [idx, r) の結果を計算する処理を書く
};

auto out = [&](int idx) -> void{
    // 例えば ans[idx] = hoge; など
};
```

**制約**

- `run` が呼び出される前に `insert` がちょうど $Q$ 回呼び出されている．

**計算量**

- $O(\alpha N \sqrt{Q} + Q \log Q)$