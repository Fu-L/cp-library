---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/matrix/gauss_elimination.hpp
    title: gauss_elimination
  - icon: ':x:'
    path: src/matrix/matrix.hpp
    title: Matrix
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    \ false;\n    }\n\n   private:\n    int h, w;\n    vector<vector<T>> A;\n};\n\
    #line 4 \"src/matrix/gauss_elimination.hpp\"\ntemplate <typename T>\npair<int,\
    \ T> gauss_elimination(Matrix<T>& a, int pivot_end = -1) {\n    int h = a.H(),\
    \ w = a.W(), rank = 0;\n    assert(-1 <= pivot_end and pivot_end <= w);\n    if(pivot_end\
    \ == -1) pivot_end = w;\n    T det = 1;\n    for(int j = 0; j < pivot_end; ++j)\
    \ {\n        int idx = -1;\n        for(int i = rank; i < h; ++i) {\n        \
    \    if(a[i][j] != T(0)) {\n                idx = i;\n                break;\n\
    \            }\n        }\n        if(idx == -1) {\n            det = 0;\n   \
    \         continue;\n        }\n        if(rank != idx) det = -det, swap(a[rank],\
    \ a[idx]);\n        det *= a[rank][j];\n        if(a[rank][j] != T(1)) {\n   \
    \         const T coeff = T(1) / a[rank][j];\n            for(int k = j; k < w;\
    \ ++k) a[rank][k] *= coeff;\n        }\n        for(int i = 0; i < h; ++i) {\n\
    \            if(i == rank) continue;\n            if(a[i][j] != T(0)) {\n    \
    \            const T coeff = a[i][j] / a[rank][j];\n                for(int k\
    \ = j; k < w; ++k) a[i][k] -= a[rank][k] * coeff;\n            }\n        }\n\
    \        ++rank;\n    }\n    return {rank, det};\n}\n#line 5 \"src/matrix/linear_equation.hpp\"\
    \ntemplate <typename T>\nvector<vector<T>> linear_equation(Matrix<T> a, Matrix<T>\
    \ b) {\n    assert(a.H() == b.H() and b.W() == 1);\n    const int h = a.H(), w\
    \ = a.W();\n    Matrix<T> A(h, w + 1);\n    for(int i = 0; i < h; ++i) {\n   \
    \     for(int j = 0; j < w; ++j) {\n            A[i][j] = a[i][j];\n        }\n\
    \        A[i][w] = b[i][0];\n    }\n    auto p = gauss_elimination(A, w);\n  \
    \  const int rank = p.first;\n    for(int i = rank; i < h; ++i) {\n        if(A[i][w]\
    \ != 0) return vector<vector<T>>{};\n    }\n    vector<vector<T>> res(1, vector<T>(w));\n\
    \    vector<int> pivot(w, -1);\n    for(int i = 0, j = 0; i < rank; ++i) {\n \
    \       while(A[i][j] == 0) ++j;\n        res[0][j] = A[i][w], pivot[j] = i;\n\
    \    }\n    for(int j = 0; j < w; ++j) {\n        if(pivot[j] == -1) {\n     \
    \       vector<T> x(w);\n            x[j] = 1;\n            for(int k = 0; k <\
    \ j; ++k) {\n                if(pivot[k] != -1) x[k] = -A[pivot[k]][j];\n    \
    \        }\n            res.emplace_back(x);\n        }\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./matrix.hpp\"\
    \n#include \"./gauss_elimination.hpp\"\ntemplate <typename T>\nvector<vector<T>>\
    \ linear_equation(Matrix<T> a, Matrix<T> b) {\n    assert(a.H() == b.H() and b.W()\
    \ == 1);\n    const int h = a.H(), w = a.W();\n    Matrix<T> A(h, w + 1);\n  \
    \  for(int i = 0; i < h; ++i) {\n        for(int j = 0; j < w; ++j) {\n      \
    \      A[i][j] = a[i][j];\n        }\n        A[i][w] = b[i][0];\n    }\n    auto\
    \ p = gauss_elimination(A, w);\n    const int rank = p.first;\n    for(int i =\
    \ rank; i < h; ++i) {\n        if(A[i][w] != 0) return vector<vector<T>>{};\n\
    \    }\n    vector<vector<T>> res(1, vector<T>(w));\n    vector<int> pivot(w,\
    \ -1);\n    for(int i = 0, j = 0; i < rank; ++i) {\n        while(A[i][j] == 0)\
    \ ++j;\n        res[0][j] = A[i][w], pivot[j] = i;\n    }\n    for(int j = 0;\
    \ j < w; ++j) {\n        if(pivot[j] == -1) {\n            vector<T> x(w);\n \
    \           x[j] = 1;\n            for(int k = 0; k < j; ++k) {\n            \
    \    if(pivot[k] != -1) x[k] = -A[pivot[k]][j];\n            }\n            res.emplace_back(x);\n\
    \        }\n    }\n    return res;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/matrix/matrix.hpp
  - src/matrix/gauss_elimination.hpp
  isVerificationFile: false
  path: src/matrix/linear_equation.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/linear_algebra/system_of_linear_equations.test.cpp
documentation_of: src/matrix/linear_equation.hpp
layout: document
title: linear_equation
---

## linear_equation

```cpp
vector<vector<T>> linear_equation(Matrix<T> A, Matrix<T> b)
```

線形方程式 $Ax = b$ を解きます．

返り値は $\{v, w_1, w_2, ..., w_k\}$ という `vector<vector<T>>` です．<br>
$v$ は方程式の解のうちの $1$ つである `vector<T>` です．<br>
$w_i$ は解空間の（それぞれ独立な）基底ベクトルである `vector<T>` です．

**制約**

- $A.H() = b.H()$
- $b.W() = 1$

**計算量**

行列 $A$ のサイズを $H \times W$ として

- $O(HW^2)$