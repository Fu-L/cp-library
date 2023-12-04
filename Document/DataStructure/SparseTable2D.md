# SparseTable2D

更新操作がない2D配列に対して，区間minなどを求めることができる．

## コンストラクタ
```cpp
SparseTable2D<T> st(vector<vector<T>> vec);
```

**計算量**
- O(hw \log hw)

## query
```cpp
T st.query(int lx, int rx, int ly, int ry)
```
- $[lx, rx) x [ly, ry)$の区間minなどを取得する．

**制約**
- $0 \leq lx \leq rx \leq h$
- $0 \leq ly \leq ry \leq w$

**計算量**
- O(1)