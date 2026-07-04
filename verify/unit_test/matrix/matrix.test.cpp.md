---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/matrix/matrix.hpp
    title: Matrix
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/matrix/matrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 4 \"src/template/template.hpp\"\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
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
    \        w = B.w;\n        return (*this);\n    }\n    Matrix& pow(long long t)\
    \ {\n        assert(h == w);\n        assert(t >= 0);\n        Matrix B = Matrix::I(h);\n\
    \        while(t > 0) {\n            if(t & 1ll) B *= (*this);\n            (*this)\
    \ *= (*this);\n            t >>= 1ll;\n        }\n        A.swap(B.A);\n     \
    \   return (*this);\n    }\n    Matrix operator+(const Matrix& B) const {\n  \
    \      return (Matrix(*this) += B);\n    }\n    Matrix operator-(const Matrix&\
    \ B) const {\n        return (Matrix(*this) -= B);\n    }\n    Matrix operator*(const\
    \ Matrix& B) const {\n        return (Matrix(*this) *= B);\n    }\n    bool operator==(const\
    \ Matrix& B) const {\n        assert(h == B.H() and w == B.W());\n        for(int\
    \ i = 0; i < h; ++i) {\n            for(int j = 0; j < w; ++j) {\n           \
    \     if(A[i][j] != B[i][j]) return false;\n            }\n        }\n       \
    \ return true;\n    }\n    bool operator!=(const Matrix& B) const {\n        assert(h\
    \ == B.H() and w == B.W());\n        for(int i = 0; i < h; ++i) {\n          \
    \  for(int j = 0; j < w; ++j) {\n                if(A[i][j] != B[i][j]) return\
    \ true;\n            }\n        }\n        return false;\n    }\n\n   private:\n\
    \    int h, w;\n    vector<vector<T>> A;\n};\n#line 4 \"verify/unit_test/matrix/matrix.test.cpp\"\
    \nint main() {\n    Matrix<int> a(2, 3), b(3, 4);\n    a[0][0] = 1;\n    a[0][1]\
    \ = 2;\n    a[0][2] = 3;\n    a[1][0] = 4;\n    a[1][1] = 5;\n    a[1][2] = 6;\n\
    \    rep(i, 0, 3) rep(j, 0, 4) b[i][j] = i + j;\n    a *= b;\n    assert(a.H()\
    \ == 2);\n    assert(a.W() == 4);\n    Matrix<int> c(4, 1, 1);\n    Matrix<int>\
    \ d = a * c;\n    assert(d.H() == 2);\n    assert(d.W() == 1);\n    int x, y;\n\
    \    cin >> x >> y;\n    cout << x + y << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/matrix/matrix.hpp\"\nint main() {\n    Matrix<int> a(2,\
    \ 3), b(3, 4);\n    a[0][0] = 1;\n    a[0][1] = 2;\n    a[0][2] = 3;\n    a[1][0]\
    \ = 4;\n    a[1][1] = 5;\n    a[1][2] = 6;\n    rep(i, 0, 3) rep(j, 0, 4) b[i][j]\
    \ = i + j;\n    a *= b;\n    assert(a.H() == 2);\n    assert(a.W() == 4);\n  \
    \  Matrix<int> c(4, 1, 1);\n    Matrix<int> d = a * c;\n    assert(d.H() == 2);\n\
    \    assert(d.W() == 1);\n    int x, y;\n    cin >> x >> y;\n    cout << x + y\
    \ << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/matrix/matrix.hpp
  isVerificationFile: true
  path: verify/unit_test/matrix/matrix.test.cpp
  requiredBy: []
  timestamp: '2026-07-04 16:35:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/matrix/matrix.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/matrix/matrix.test.cpp
- /verify/verify/unit_test/matrix/matrix.test.cpp.html
title: verify/unit_test/matrix/matrix.test.cpp
---
