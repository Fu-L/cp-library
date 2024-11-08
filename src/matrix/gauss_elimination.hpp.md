---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/matrix/matrix.hpp
    title: Matrix
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/matrix/counting_spanning_tree_directed.hpp
    title: counting_spanning_tree_directed
  - icon: ':heavy_check_mark:'
    path: src/matrix/counting_spanning_tree_undirected.hpp
    title: counting_spanning_tree_undirected
  - icon: ':heavy_check_mark:'
    path: src/matrix/inverse.hpp
    title: inverse
  - icon: ':heavy_check_mark:'
    path: src/matrix/linear_equation.hpp
    title: linear_equation
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/enumerative_combinatrics/counting_spanning_tree_directed.test.cpp
    title: verify/library_checker/enumerative_combinatrics/counting_spanning_tree_directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/enumerative_combinatrics/counting_spanning_tree_undirected.test.cpp
    title: verify/library_checker/enumerative_combinatrics/counting_spanning_tree_undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/linear_algebra/determinant_of_matric.test.cpp
    title: verify/library_checker/linear_algebra/determinant_of_matric.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/linear_algebra/inverse_matrix.test.cpp
    title: verify/library_checker/linear_algebra/inverse_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/linear_algebra/rank_of_matrix.test.cpp
    title: verify/library_checker/linear_algebra/rank_of_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/linear_algebra/system_of_linear_equations.test.cpp
    title: verify/library_checker/linear_algebra/system_of_linear_equations.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n\
    #define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a,\
    \ b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
    struct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/matrix/matrix.hpp\"\
    \ntemplate <typename T>\nstruct Matrix {\n    Matrix(const int h, const int w,\
    \ const T& val = 0)\n        : h(h), w(w), A(h, vector<T>(w, val)) {}\n    int\
    \ H() const {\n        return h;\n    }\n    int W() const {\n        return w;\n\
    \    }\n    const vector<T>& operator[](const int i) const {\n        assert(0\
    \ <= i and i < h);\n        return A[i];\n    }\n    vector<T>& operator[](const\
    \ int i) {\n        assert(0 <= i and i < h);\n        return A[i];\n    }\n \
    \   static Matrix I(const int n) {\n        Matrix mat(n, n);\n        for(int\
    \ i = 0; i < n; ++i) mat[i][i] = 1;\n        return mat;\n    }\n    Matrix& operator+=(const\
    \ Matrix& B) {\n        assert(h == B.h and w == B.w);\n        for(int i = 0;\
    \ i < h; ++i) {\n            for(int j = 0; j < w; ++j) {\n                (*this)[i][j]\
    \ += B[i][j];\n            }\n        }\n        return (*this);\n    }\n    Matrix&\
    \ operator-=(const Matrix& B) {\n        assert(h == B.h and w == B.w);\n    \
    \    for(int i = 0; i < h; ++i) {\n            for(int j = 0; j < w; ++j) {\n\
    \                (*this)[i][j] -= B[i][j];\n            }\n        }\n       \
    \ return (*this);\n    }\n    Matrix& operator*=(const Matrix& B) {\n        assert(w\
    \ == B.h);\n        vector<vector<T>> C(h, vector<T>(B.w, 0));\n        for(int\
    \ i = 0; i < h; ++i) {\n            for(int k = 0; k < w; ++k) {\n           \
    \     for(int j = 0; j < B.w; ++j) {\n                    C[i][j] += (*this)[i][k]\
    \ * B[k][j];\n                }\n            }\n        }\n        A.swap(C);\n\
    \        return (*this);\n    }\n    Matrix& pow(long long t) {\n        assert(h\
    \ == w);\n        assert(t >= 0);\n        Matrix B = Matrix::I(h);\n        while(t\
    \ > 0) {\n            if(t & 1ll) B *= (*this);\n            (*this) *= (*this);\n\
    \            t >>= 1ll;\n        }\n        A.swap(B.A);\n        return (*this);\n\
    \    }\n    Matrix operator+(const Matrix& B) const {\n        return (Matrix(*this)\
    \ += B);\n    }\n    Matrix operator-(const Matrix& B) const {\n        return\
    \ (Matrix(*this) -= B);\n    }\n    Matrix operator*(const Matrix& B) const {\n\
    \        return (Matrix(*this) *= B);\n    }\n    bool operator==(const Matrix&\
    \ B) const {\n        assert(h == B.H() and w == B.W());\n        for(int i =\
    \ 0; i < h; ++i) {\n            for(int j = 0; j < w; ++j) {\n               \
    \ if(A[i][j] != B[i][j]) return false;\n            }\n        }\n        return\
    \ true;\n    }\n    bool operator!=(const Matrix& B) const {\n        assert(h\
    \ == B.H() and w == B.W());\n        for(int i = 0; i < h; ++i) {\n          \
    \  for(int j = 0; j < w; ++j) {\n                if(A[i][j] != B[i][j]) return\
    \ true;\n            }\n        }\n        return false;\n    }\n\n   private:\n\
    \    int h, w;\n    vector<vector<T>> A;\n};\n#line 4 \"src/matrix/gauss_elimination.hpp\"\
    \ntemplate <typename T>\npair<int, T> gauss_elimination(Matrix<T>& a, int pivot_end\
    \ = -1) {\n    const int h = a.H(), w = a.W();\n    int rank = 0;\n    assert(-1\
    \ <= pivot_end and pivot_end <= w);\n    if(pivot_end == -1) pivot_end = w;\n\
    \    T det = 1;\n    for(int j = 0; j < pivot_end; ++j) {\n        int idx = -1;\n\
    \        for(int i = rank; i < h; ++i) {\n            if(a[i][j] != T(0)) {\n\
    \                idx = i;\n                break;\n            }\n        }\n\
    \        if(idx == -1) {\n            det = 0;\n            continue;\n      \
    \  }\n        if(rank != idx) det = -det, swap(a[rank], a[idx]);\n        det\
    \ *= a[rank][j];\n        if(a[rank][j] != T(1)) {\n            const T coeff\
    \ = T(1) / a[rank][j];\n            for(int k = j; k < w; ++k) a[rank][k] *= coeff;\n\
    \        }\n        for(int i = 0; i < h; ++i) {\n            if(i == rank) continue;\n\
    \            if(a[i][j] != T(0)) {\n                const T coeff = a[i][j] /\
    \ a[rank][j];\n                for(int k = j; k < w; ++k) a[i][k] -= a[rank][k]\
    \ * coeff;\n            }\n        }\n        ++rank;\n    }\n    return {rank,\
    \ det};\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./matrix.hpp\"\
    \ntemplate <typename T>\npair<int, T> gauss_elimination(Matrix<T>& a, int pivot_end\
    \ = -1) {\n    const int h = a.H(), w = a.W();\n    int rank = 0;\n    assert(-1\
    \ <= pivot_end and pivot_end <= w);\n    if(pivot_end == -1) pivot_end = w;\n\
    \    T det = 1;\n    for(int j = 0; j < pivot_end; ++j) {\n        int idx = -1;\n\
    \        for(int i = rank; i < h; ++i) {\n            if(a[i][j] != T(0)) {\n\
    \                idx = i;\n                break;\n            }\n        }\n\
    \        if(idx == -1) {\n            det = 0;\n            continue;\n      \
    \  }\n        if(rank != idx) det = -det, swap(a[rank], a[idx]);\n        det\
    \ *= a[rank][j];\n        if(a[rank][j] != T(1)) {\n            const T coeff\
    \ = T(1) / a[rank][j];\n            for(int k = j; k < w; ++k) a[rank][k] *= coeff;\n\
    \        }\n        for(int i = 0; i < h; ++i) {\n            if(i == rank) continue;\n\
    \            if(a[i][j] != T(0)) {\n                const T coeff = a[i][j] /\
    \ a[rank][j];\n                for(int k = j; k < w; ++k) a[i][k] -= a[rank][k]\
    \ * coeff;\n            }\n        }\n        ++rank;\n    }\n    return {rank,\
    \ det};\n}"
  dependsOn:
  - src/template/template.hpp
  - src/matrix/matrix.hpp
  isVerificationFile: false
  path: src/matrix/gauss_elimination.hpp
  requiredBy:
  - src/matrix/counting_spanning_tree_undirected.hpp
  - src/matrix/linear_equation.hpp
  - src/matrix/inverse.hpp
  - src/matrix/counting_spanning_tree_directed.hpp
  timestamp: '2024-11-09 02:30:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/enumerative_combinatrics/counting_spanning_tree_directed.test.cpp
  - verify/library_checker/enumerative_combinatrics/counting_spanning_tree_undirected.test.cpp
  - verify/library_checker/linear_algebra/system_of_linear_equations.test.cpp
  - verify/library_checker/linear_algebra/rank_of_matrix.test.cpp
  - verify/library_checker/linear_algebra/inverse_matrix.test.cpp
  - verify/library_checker/linear_algebra/determinant_of_matric.test.cpp
documentation_of: src/matrix/gauss_elimination.hpp
layout: document
title: gauss_elimination
---

## gauss_elimination

```cpp
pair<int, T> gauss_elimination(Matrix<T>& A, int pivot_end = -1)
```

$H \times W$ 行列 $A$ の階数と行列式を返します．<br>
副作用として $A$ は簡約階段系になります．

$A$ が正方行列でないとき，返り値の行列式の値は未定義です．

$\mathrm{pivot\\_end}$ で行列の何列目までを見て欲しいかを指定することができます．(実質的に内部用の変数)<br>
$\mathrm{pivot\\_end} = -1$ のときは $W$ 列目まで見ます．

**制約**

- $-1 \leq \mathrm{pivot\\_end} \leq W$

**計算量**

- $O(HW^2)$
