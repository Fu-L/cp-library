---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/matrix/counting_spanning_tree_directed.hpp
    title: counting_spanning_tree_directed
  - icon: ':x:'
    path: src/matrix/counting_spanning_tree_undirected.hpp
    title: counting_spanning_tree_undirected
  - icon: ':x:'
    path: src/matrix/gauss_elimination.hpp
    title: gauss_elimination
  - icon: ':x:'
    path: src/matrix/inverse.hpp
    title: inverse
  - icon: ':x:'
    path: src/matrix/linear_equation.hpp
    title: linear_equation
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/enumerative_combinatrics/counting_spanning_tree_directed.test.cpp
    title: verify/library_checker/enumerative_combinatrics/counting_spanning_tree_directed.test.cpp
  - icon: ':x:'
    path: verify/library_checker/enumerative_combinatrics/counting_spanning_tree_undirected.test.cpp
    title: verify/library_checker/enumerative_combinatrics/counting_spanning_tree_undirected.test.cpp
  - icon: ':x:'
    path: verify/library_checker/linear_algebra/determinant_of_matric.test.cpp
    title: verify/library_checker/linear_algebra/determinant_of_matric.test.cpp
  - icon: ':x:'
    path: verify/library_checker/linear_algebra/inverse_matrix.test.cpp
    title: verify/library_checker/linear_algebra/inverse_matrix.test.cpp
  - icon: ':x:'
    path: verify/library_checker/linear_algebra/matrix_product.test.cpp
    title: verify/library_checker/linear_algebra/matrix_product.test.cpp
  - icon: ':x:'
    path: verify/library_checker/linear_algebra/pow_of_matrix.test.cpp
    title: verify/library_checker/linear_algebra/pow_of_matrix.test.cpp
  - icon: ':x:'
    path: verify/library_checker/linear_algebra/rank_of_matrix.test.cpp
    title: verify/library_checker/linear_algebra/rank_of_matrix.test.cpp
  - icon: ':x:'
    path: verify/library_checker/linear_algebra/system_of_linear_equations.test.cpp
    title: verify/library_checker/linear_algebra/system_of_linear_equations.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n\
    #define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a,\
    \ b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
    struct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/matrix/matrix.hpp\"\
    \ntemplate <typename T>\nstruct Matrix {\n    Matrix(int h, int w, T val = 0)\n\
    \        : h(h), w(w), A(h, vector<T>(w, val)) {}\n    int H() const {\n     \
    \   return h;\n    }\n    int W() const {\n        return w;\n    }\n    const\
    \ vector<T>& operator[](int i) const {\n        assert(0 <= i and i < h);\n  \
    \      return A[i];\n    }\n    vector<T>& operator[](int i) {\n        assert(0\
    \ <= i and i < h);\n        return A[i];\n    }\n    static Matrix I(int n) {\n\
    \        Matrix mat(n, n);\n        for(int i = 0; i < n; ++i) mat[i][i] = 1;\n\
    \        return mat;\n    }\n    Matrix& operator+=(const Matrix& B) {\n     \
    \   assert(h == B.h and w == B.w);\n        for(int i = 0; i < h; ++i) {\n   \
    \         for(int j = 0; j < w; ++j) {\n                (*this)[i][j] += B[i][j];\n\
    \            }\n        }\n        return (*this);\n    }\n    Matrix& operator-=(const\
    \ Matrix& B) {\n        assert(h == B.h and w == B.w);\n        for(int i = 0;\
    \ i < h; ++i) {\n            for(int j = 0; j < w; ++j) {\n                (*this)[i][j]\
    \ -= B[i][j];\n            }\n        }\n        return (*this);\n    }\n    Matrix&\
    \ operator*=(const Matrix& B) {\n        assert(w == B.h);\n        vector<vector<T>>\
    \ C(h, vector<T>(B.w, 0));\n        for(int i = 0; i < h; ++i) {\n           \
    \ for(int k = 0; k < w; ++k) {\n                for(int j = 0; j < B.w; ++j) {\n\
    \                    C[i][j] += (*this)[i][k] * B[k][j];\n                }\n\
    \            }\n        }\n        A.swap(C);\n        return (*this);\n    }\n\
    \    Matrix& pow(long long t) {\n        assert(h == w);\n        assert(t >=\
    \ 0);\n        Matrix B = Matrix::I(h);\n        while(t > 0) {\n            if(t\
    \ & 1ll) B *= (*this);\n            (*this) *= (*this);\n            t >>= 1ll;\n\
    \        }\n        A.swap(B.A);\n        return (*this);\n    }\n    Matrix operator+(const\
    \ Matrix& B) const {\n        return (Matrix(*this) += B);\n    }\n    Matrix\
    \ operator-(const Matrix& B) const {\n        return (Matrix(*this) -= B);\n \
    \   }\n    Matrix operator*(const Matrix& B) const {\n        return (Matrix(*this)\
    \ *= B);\n    }\n    bool operator==(const Matrix& B) const {\n        assert(h\
    \ == B.H() and w == B.W());\n        for(int i = 0; i < h; ++i) {\n          \
    \  for(int j = 0; j < w; ++j) {\n                if(A[i][j] != B[i][j]) return\
    \ false;\n            }\n        }\n        return true;\n    }\n    bool operator!=(const\
    \ Matrix& B) const {\n        assert(h == B.H() and w == B.W());\n        for(int\
    \ i = 0; i < h; ++i) {\n            for(int j = 0; j < w; ++j) {\n           \
    \     if(A[i][j] != B[i][j]) return true;\n            }\n        }\n        return\
    \ false;\n    }\n\n   private:\n    int h, w;\n    vector<vector<T>> A;\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    struct Matrix {\n    Matrix(int h, int w, T val = 0)\n        : h(h), w(w), A(h,\
    \ vector<T>(w, val)) {}\n    int H() const {\n        return h;\n    }\n    int\
    \ W() const {\n        return w;\n    }\n    const vector<T>& operator[](int i)\
    \ const {\n        assert(0 <= i and i < h);\n        return A[i];\n    }\n  \
    \  vector<T>& operator[](int i) {\n        assert(0 <= i and i < h);\n       \
    \ return A[i];\n    }\n    static Matrix I(int n) {\n        Matrix mat(n, n);\n\
    \        for(int i = 0; i < n; ++i) mat[i][i] = 1;\n        return mat;\n    }\n\
    \    Matrix& operator+=(const Matrix& B) {\n        assert(h == B.h and w == B.w);\n\
    \        for(int i = 0; i < h; ++i) {\n            for(int j = 0; j < w; ++j)\
    \ {\n                (*this)[i][j] += B[i][j];\n            }\n        }\n   \
    \     return (*this);\n    }\n    Matrix& operator-=(const Matrix& B) {\n    \
    \    assert(h == B.h and w == B.w);\n        for(int i = 0; i < h; ++i) {\n  \
    \          for(int j = 0; j < w; ++j) {\n                (*this)[i][j] -= B[i][j];\n\
    \            }\n        }\n        return (*this);\n    }\n    Matrix& operator*=(const\
    \ Matrix& B) {\n        assert(w == B.h);\n        vector<vector<T>> C(h, vector<T>(B.w,\
    \ 0));\n        for(int i = 0; i < h; ++i) {\n            for(int k = 0; k < w;\
    \ ++k) {\n                for(int j = 0; j < B.w; ++j) {\n                   \
    \ C[i][j] += (*this)[i][k] * B[k][j];\n                }\n            }\n    \
    \    }\n        A.swap(C);\n        return (*this);\n    }\n    Matrix& pow(long\
    \ long t) {\n        assert(h == w);\n        assert(t >= 0);\n        Matrix\
    \ B = Matrix::I(h);\n        while(t > 0) {\n            if(t & 1ll) B *= (*this);\n\
    \            (*this) *= (*this);\n            t >>= 1ll;\n        }\n        A.swap(B.A);\n\
    \        return (*this);\n    }\n    Matrix operator+(const Matrix& B) const {\n\
    \        return (Matrix(*this) += B);\n    }\n    Matrix operator-(const Matrix&\
    \ B) const {\n        return (Matrix(*this) -= B);\n    }\n    Matrix operator*(const\
    \ Matrix& B) const {\n        return (Matrix(*this) *= B);\n    }\n    bool operator==(const\
    \ Matrix& B) const {\n        assert(h == B.H() and w == B.W());\n        for(int\
    \ i = 0; i < h; ++i) {\n            for(int j = 0; j < w; ++j) {\n           \
    \     if(A[i][j] != B[i][j]) return false;\n            }\n        }\n       \
    \ return true;\n    }\n    bool operator!=(const Matrix& B) const {\n        assert(h\
    \ == B.H() and w == B.W());\n        for(int i = 0; i < h; ++i) {\n          \
    \  for(int j = 0; j < w; ++j) {\n                if(A[i][j] != B[i][j]) return\
    \ true;\n            }\n        }\n        return false;\n    }\n\n   private:\n\
    \    int h, w;\n    vector<vector<T>> A;\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/matrix/matrix.hpp
  requiredBy:
  - src/matrix/counting_spanning_tree_undirected.hpp
  - src/matrix/linear_equation.hpp
  - src/matrix/gauss_elimination.hpp
  - src/matrix/inverse.hpp
  - src/matrix/counting_spanning_tree_directed.hpp
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/enumerative_combinatrics/counting_spanning_tree_directed.test.cpp
  - verify/library_checker/enumerative_combinatrics/counting_spanning_tree_undirected.test.cpp
  - verify/library_checker/linear_algebra/matrix_product.test.cpp
  - verify/library_checker/linear_algebra/system_of_linear_equations.test.cpp
  - verify/library_checker/linear_algebra/rank_of_matrix.test.cpp
  - verify/library_checker/linear_algebra/inverse_matrix.test.cpp
  - verify/library_checker/linear_algebra/pow_of_matrix.test.cpp
  - verify/library_checker/linear_algebra/determinant_of_matric.test.cpp
documentation_of: src/matrix/matrix.hpp
layout: document
title: Matrix
---

# Matrix

行列演算を行うライブラリです．

## コンストラクタ

```cpp
Matrix<T> mat(int h, int w, T val = 0)
```

- $h \times w$ 行列を構築します．
- 初期値は全て $\mathrm{val}$ となります．

**計算量**

- $O(hw)$

## H

```cpp
int mat.H()
```

行列 `mat` の行数を返します．

**計算量**

- $O(1)$

## W

```cpp
int mat.W()
```

行列 `mat` の列数を返します．

**計算量**

- $O(1)$

## I

```cpp
Matrix<T> Matrix::I(int n)
```

$n$ 次単位行列を返します．

**計算量**

- $O(n^2)$

## operator []

```cpp
vector<T> mat[int i]
```

行列 `mat` の $i$ 行目を返します．

**制約**

- $0 \leq i < h$

**計算量**

- $O(w)$

## 各種演算

```cpp
Matrix += Matrix
Matrix -= Matrix
Matrix *= Matrix

Matrix + Matrix
Matrix - Matrix
Matrix * Matrix

Matrix == Matrix
Matrix != Matrix
```

が動きます．

**制約**

`a += b` と `a -= b` と `a + b` と `a - b` と `a == b` と `a != b` を行うとき，
- $a.H() = b.H()$ かつ $a.W() = b.W()$

`a * b` を行うとき，
- $a.W() = b.H()$

**計算量**

- $O(a.H() \times a.W())$ (掛け算以外)
- $O(a.H() \times a.W() \times b.W())$ (掛け算)

## pow

```cpp
Matrix<T> mat.pow(ll n)
```

$\mathrm{mat}^n$ を返します．

**制約**

- $\mathrm{mat}$ は正方行列である
- $0 \leq n$

**計算量**

- $O(h^3 \log n)$