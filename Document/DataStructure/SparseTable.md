# SparseTable

更新操作がない配列に対して，区間minなどを求めることができる．

## コンストラクタ
```cpp
SparseTable<T> st(vector<T> vec);
```

**計算量**
- $O(n \log n)$

## query
```cpp
T st.query(int l, int r)
```
- $[l, r)$の区間minなどを取得する．

**制約**
- $0 \leq l \leq r \leq n$

**計算量**
- $O(1)$

## Apendix
```cpp
string s;
vector<int> sa = saffix_array(s);
vector<int> lcp = lcp_array(s, sa);
SparseTable<int> st(lcp);
```
- を求めておくと，
```cpp
int len = st.query(l, r);
```
- で，sのsa[l]からとsa[r]からの接頭辞が何文字共通しているかが求められる。