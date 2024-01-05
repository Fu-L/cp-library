---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/matrix/determinant_of_matric.test.cpp
    title: verify/library_checker/matrix/determinant_of_matric.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/matrix/matrix_product.test.cpp
    title: verify/library_checker/matrix/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/matrix/pow_of_matrix.test.cpp
    title: verify/library_checker/matrix/pow_of_matrix.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/matrix.hpp\"\n\
    template <typename T>\nstruct Matrix {\n    Matrix(int h, int w, T val = 0)\n\
    \        : h(h), w(w), A(h, vector<T>(w, val)) {}\n    int H() const {\n     \
    \   return h;\n    }\n    int W() const {\n        return w;\n    }\n    inline\
    \ const vector<T>& operator[](int i) const {\n        return A[i];\n    }\n  \
    \  inline vector<T>& operator[](int i) {\n        return A[i];\n    }\n    static\
    \ Matrix I(int n) {\n        Matrix mat(n, n);\n        for(int i = 0; i < n;\
    \ ++i) mat[i][i] = 1;\n        return mat;\n    }\n    Matrix& operator+=(const\
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
    \        return (*this);\n    }\n    Matrix& pow(ll t) {\n        assert(h ==\
    \ w);\n        Matrix B = Matrix::I(h);\n        while(t > 0) {\n            if(t\
    \ & 1ll) B *= (*this);\n            (*this) *= (*this);\n            t >>= 1ll;\n\
    \        }\n        A.swap(B.A);\n        return (*this);\n    }\n    Matrix operator+(const\
    \ Matrix& B) const {\n        return (Matrix(*this) += B);\n    }\n    Matrix\
    \ operator-(const Matrix& B) const {\n        return (Matrix(*this) -= B);\n \
    \   }\n    Matrix operator*(const Matrix& B) const {\n        return (Matrix(*this)\
    \ *= B);\n    }\n    bool operator==(const Matrix& B) const {\n        assert(h\
    \ == B.h and w == B.w);\n        rep(i, 0, h) {\n            rep(j, 0, w) {\n\
    \                if(A[i][j] != B[i][j]) return false;\n            }\n       \
    \ }\n        return true;\n    }\n    bool operator!=(const Matrix& B) const {\n\
    \        assert(h == B.h and w == B.w);\n        for(int i = 0; i < h; ++i) {\n\
    \            for(int j = 0; j < w; ++j) {\n                if(A[i][j] != B[i][j])\
    \ return true;\n            }\n        }\n        return false;\n    }\n    T\
    \ determinant() const {\n        assert(h == w);\n        Matrix B(*this);\n \
    \       T res = 1;\n        for(int i = 0; i < h; ++i) {\n            int idx\
    \ = -1;\n            for(int j = i; j < w; ++j) {\n                if(B[j][i]\
    \ != 0) {\n                    idx = j;\n                    break;\n        \
    \        }\n            }\n            if(idx == -1) return 0;\n            if(i\
    \ != idx) {\n                res *= T(-1);\n                swap(B[i], B[idx]);\n\
    \            }\n            res *= B[i][i];\n            T inv = T(1) / B[i][i];\n\
    \            for(int j = 0; j < w; ++j) {\n                B[i][j] *= inv;\n \
    \           }\n            for(int j = i + 1; j < h; ++j) {\n                T\
    \ a = B[j][i];\n                if(a == 0) continue;\n                for(int\
    \ k = i; k < w; ++k) {\n                    B[j][k] -= B[i][k] * a;\n        \
    \        }\n            }\n        }\n        return res;\n    }\n\n   private:\n\
    \    int h, w;\n    vector<vector<T>> A;\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename T>\n\
    struct Matrix {\n    Matrix(int h, int w, T val = 0)\n        : h(h), w(w), A(h,\
    \ vector<T>(w, val)) {}\n    int H() const {\n        return h;\n    }\n    int\
    \ W() const {\n        return w;\n    }\n    inline const vector<T>& operator[](int\
    \ i) const {\n        return A[i];\n    }\n    inline vector<T>& operator[](int\
    \ i) {\n        return A[i];\n    }\n    static Matrix I(int n) {\n        Matrix\
    \ mat(n, n);\n        for(int i = 0; i < n; ++i) mat[i][i] = 1;\n        return\
    \ mat;\n    }\n    Matrix& operator+=(const Matrix& B) {\n        assert(h ==\
    \ B.h and w == B.w);\n        for(int i = 0; i < h; ++i) {\n            for(int\
    \ j = 0; j < w; ++j) {\n                (*this)[i][j] += B[i][j];\n          \
    \  }\n        }\n        return (*this);\n    }\n    Matrix& operator-=(const\
    \ Matrix& B) {\n        assert(h == B.h and w == B.w);\n        for(int i = 0;\
    \ i < h; ++i) {\n            for(int j = 0; j < w; ++j) {\n                (*this)[i][j]\
    \ -= B[i][j];\n            }\n        }\n        return (*this);\n    }\n    Matrix&\
    \ operator*=(const Matrix& B) {\n        assert(w == B.h);\n        vector<vector<T>>\
    \ C(h, vector<T>(B.w, 0));\n        for(int i = 0; i < h; ++i) {\n           \
    \ for(int k = 0; k < w; ++k) {\n                for(int j = 0; j < B.w; ++j) {\n\
    \                    C[i][j] += (*this)[i][k] * B[k][j];\n                }\n\
    \            }\n        }\n        A.swap(C);\n        return (*this);\n    }\n\
    \    Matrix& pow(ll t) {\n        assert(h == w);\n        Matrix B = Matrix::I(h);\n\
    \        while(t > 0) {\n            if(t & 1ll) B *= (*this);\n            (*this)\
    \ *= (*this);\n            t >>= 1ll;\n        }\n        A.swap(B.A);\n     \
    \   return (*this);\n    }\n    Matrix operator+(const Matrix& B) const {\n  \
    \      return (Matrix(*this) += B);\n    }\n    Matrix operator-(const Matrix&\
    \ B) const {\n        return (Matrix(*this) -= B);\n    }\n    Matrix operator*(const\
    \ Matrix& B) const {\n        return (Matrix(*this) *= B);\n    }\n    bool operator==(const\
    \ Matrix& B) const {\n        assert(h == B.h and w == B.w);\n        rep(i, 0,\
    \ h) {\n            rep(j, 0, w) {\n                if(A[i][j] != B[i][j]) return\
    \ false;\n            }\n        }\n        return true;\n    }\n    bool operator!=(const\
    \ Matrix& B) const {\n        assert(h == B.h and w == B.w);\n        for(int\
    \ i = 0; i < h; ++i) {\n            for(int j = 0; j < w; ++j) {\n           \
    \     if(A[i][j] != B[i][j]) return true;\n            }\n        }\n        return\
    \ false;\n    }\n    T determinant() const {\n        assert(h == w);\n      \
    \  Matrix B(*this);\n        T res = 1;\n        for(int i = 0; i < h; ++i) {\n\
    \            int idx = -1;\n            for(int j = i; j < w; ++j) {\n       \
    \         if(B[j][i] != 0) {\n                    idx = j;\n                 \
    \   break;\n                }\n            }\n            if(idx == -1) return\
    \ 0;\n            if(i != idx) {\n                res *= T(-1);\n            \
    \    swap(B[i], B[idx]);\n            }\n            res *= B[i][i];\n       \
    \     T inv = T(1) / B[i][i];\n            for(int j = 0; j < w; ++j) {\n    \
    \            B[i][j] *= inv;\n            }\n            for(int j = i + 1; j\
    \ < h; ++j) {\n                T a = B[j][i];\n                if(a == 0) continue;\n\
    \                for(int k = i; k < w; ++k) {\n                    B[j][k] -=\
    \ B[i][k] * a;\n                }\n            }\n        }\n        return res;\n\
    \    }\n\n   private:\n    int h, w;\n    vector<vector<T>> A;\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/matrix.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/matrix/matrix_product.test.cpp
  - verify/library_checker/matrix/pow_of_matrix.test.cpp
  - verify/library_checker/matrix/determinant_of_matric.test.cpp
documentation_of: src/math/matrix.hpp
layout: document
title: Matrix
---
