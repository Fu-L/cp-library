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