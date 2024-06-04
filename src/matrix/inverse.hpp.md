---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/matrix/gauss_elimination.hpp
    title: gauss_elimination
  - icon: ':heavy_check_mark:'
    path: src/matrix/matrix.hpp
    title: Matrix
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/matrix/inverse_matrix.test.cpp
    title: verify/library_checker/matrix/inverse_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/matrix/matrix.hpp\"\n\
    template <typename T>\nstruct Matrix {\n    Matrix(int h, int w, T val = 0)\n\
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
    \        ++rank;\n    }\n    return {rank, det};\n}\n#line 5 \"src/matrix/inverse.hpp\"\
    \ntemplate <typename T>\nMatrix<T> inverse(const Matrix<T>& a) {\n    const int\
    \ n = a.H();\n    assert(n > 0);\n    assert(n == a.W());\n    Matrix<T> m(n,\
    \ 2 * n);\n    for(int i = 0; i < n; ++i) {\n        for(int j = 0; j < n; ++j)\
    \ {\n            m[i][j] = a[i][j];\n        }\n        m[i][n + i] = 1;\n   \
    \ }\n    auto [rank, det] = gauss_elimination(m, n);\n    if(rank != n) {\n  \
    \      Matrix<T> res(0, 0);\n        return res;\n    }\n    Matrix<T> b(n, n);\n\
    \    for(int i = 0; i < n; ++i) {\n        for(int j = 0; j < n; ++j) {\n    \
    \        b[i][j] = m[i][j + n];\n        }\n    }\n    return b;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./matrix.hpp\"\
    \n#include \"./gauss_elimination.hpp\"\ntemplate <typename T>\nMatrix<T> inverse(const\
    \ Matrix<T>& a) {\n    const int n = a.H();\n    assert(n > 0);\n    assert(n\
    \ == a.W());\n    Matrix<T> m(n, 2 * n);\n    for(int i = 0; i < n; ++i) {\n \
    \       for(int j = 0; j < n; ++j) {\n            m[i][j] = a[i][j];\n       \
    \ }\n        m[i][n + i] = 1;\n    }\n    auto [rank, det] = gauss_elimination(m,\
    \ n);\n    if(rank != n) {\n        Matrix<T> res(0, 0);\n        return res;\n\
    \    }\n    Matrix<T> b(n, n);\n    for(int i = 0; i < n; ++i) {\n        for(int\
    \ j = 0; j < n; ++j) {\n            b[i][j] = m[i][j + n];\n        }\n    }\n\
    \    return b;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/matrix/matrix.hpp
  - src/matrix/gauss_elimination.hpp
  isVerificationFile: false
  path: src/matrix/inverse.hpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/matrix/inverse_matrix.test.cpp
documentation_of: src/matrix/inverse.hpp
layout: document
title: inverse
---

## inverse

```cpp
Matrix<T> inverse(Matrix<T> A)
```

$N \times N$ 行列 $A$ の逆行列を返します．

逆行列が存在しない場合は $0 \times 0$ の行列を返します．

**制約**

- $A$ は正方行列

**計算量**

- $O(N^3)$