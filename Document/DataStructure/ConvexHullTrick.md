# ConvexHullTrick

複数の直線を持っておき，最小値を求めることができる．

## コンストラクタ
```cpp
ConvecHullTrick cht;
```

**計算量**
- $O(1)$

## add
```cpp
void cht.add(int a, int b)
```
- 直線$y = ax + b$を追加する

**制約**
- $a$は単調非減少

**計算量**
- ならし$O(1)$

## operator()
```cpp
void cht(int x)
```
- $x = x$での最小値を求める

**制約**
- オーバーフローしないこと

**計算量**
- ならし$O(1)$