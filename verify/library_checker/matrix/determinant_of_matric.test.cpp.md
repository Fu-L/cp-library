---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/matrix.hpp
    title: Matrix
  - icon: ':heavy_check_mark:'
    path: src/template/static_modint.hpp
    title: StaticModint
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"verify/library_checker/matrix/determinant_of_matric.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i,\
    \ a, b) for(ll i = a; i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n\
    \    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n    \
    \    cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/template/static_modint.hpp\"\
    \ntemplate <uint32_t m>\nstruct StaticModint {\n    using mint = StaticModint;\n\
    \    static constexpr uint32_t mod() {\n        return m;\n    }\n    static constexpr\
    \ mint raw(uint32_t v) {\n        mint a;\n        a._v = v;\n        return a;\n\
    \    }\n    constexpr StaticModint()\n        : _v(0) {}\n    template <class\
    \ T>\n    constexpr StaticModint(const T& v) {\n        static_assert(is_integral_v<T>);\n\
    \        if constexpr(is_signed_v<T>) {\n            int64_t x = int64_t(v % int64_t(m));\n\
    \            if(x < 0) x += m;\n            _v = uint32_t(x);\n        } else\
    \ _v = uint32_t(v % m);\n    }\n    constexpr uint32_t val() const {\n       \
    \ return _v;\n    }\n    constexpr mint& operator++() {\n        return *this\
    \ += 1;\n    }\n    constexpr mint& operator--() {\n        return *this -= 1;\n\
    \    }\n    constexpr mint operator++(int) {\n        mint res = *this;\n    \
    \    ++*this;\n        return res;\n    }\n    constexpr mint operator--(int)\
    \ {\n        mint res = *this;\n        --*this;\n        return res;\n    }\n\
    \    constexpr mint& operator+=(mint rhs) {\n        if(_v >= m - rhs._v) _v -=\
    \ m;\n        _v += rhs._v;\n        return *this;\n    }\n    constexpr mint&\
    \ operator-=(mint rhs) {\n        if(_v < rhs._v) _v += m;\n        _v -= rhs._v;\n\
    \        return *this;\n    }\n    constexpr mint& operator*=(mint rhs) {\n  \
    \      return *this = *this * rhs;\n    }\n    constexpr mint& operator/=(mint\
    \ rhs) {\n        return *this *= rhs.inv();\n    }\n    constexpr mint operator+()\
    \ const {\n        return *this;\n    }\n    constexpr mint operator-() const\
    \ {\n        return mint{} - *this;\n    }\n    constexpr mint pow(long long n)\
    \ const {\n        assert(0 <= n);\n        if(n == 0) return 1;\n        mint\
    \ x = *this, r = 1;\n        while(1) {\n            if(n & 1) r *= x;\n     \
    \       n >>= 1;\n            if(n == 0) return r;\n            x *= x;\n    \
    \    }\n    }\n    constexpr mint inv() const {\n        if constexpr(prime) {\n\
    \            assert(_v);\n            return pow(m - 2);\n        } else {\n \
    \           auto eg = inv_gcd(_v, m);\n            assert(eg.first == 1);\n  \
    \          return eg.second;\n        }\n    }\n    friend constexpr mint operator+(mint\
    \ lhs, mint rhs) {\n        return lhs += rhs;\n    }\n    friend constexpr mint\
    \ operator-(mint lhs, mint rhs) {\n        return lhs -= rhs;\n    }\n    friend\
    \ constexpr mint operator*(mint lhs, mint rhs) {\n        return uint64_t(lhs._v)\
    \ * rhs._v;\n    }\n    friend constexpr mint operator/(mint lhs, mint rhs) {\n\
    \        return lhs /= rhs;\n    }\n    friend constexpr bool operator==(mint\
    \ lhs, mint rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend constexpr\
    \ bool operator!=(mint lhs, mint rhs) {\n        return lhs._v != rhs._v;\n  \
    \  }\n    friend istream& operator>>(istream& in, mint& x) {\n        long long\
    \ a;\n        in >> a;\n        x = a;\n        return in;\n    }\n    friend\
    \ ostream& operator<<(ostream& out, const mint& x) {\n        return out << x.val();\n\
    \    }\n\n   private:\n    uint32_t _v = 0;\n    static constexpr bool prime =\
    \ []() -> bool {\n        if(m == 1) return 0;\n        if(m == 2 or m == 7 or\
    \ m == 61) return 1;\n        if(m % 2 == 0) return 0;\n        uint32_t d = m\
    \ - 1;\n        while(d % 2 == 0) d /= 2;\n        for(uint32_t a : {2, 7, 61})\
    \ {\n            uint32_t t = d;\n            mint y = mint(a).pow(t);\n     \
    \       while(t != m - 1 && y != 1 && y != m - 1) {\n                y *= y;\n\
    \                t <<= 1;\n            }\n            if(y != m - 1 && t % 2 ==\
    \ 0) return 0;\n        }\n        return 1;\n    }();\n    static constexpr pair<int32_t,\
    \ int32_t> inv_gcd(int32_t a, int32_t b) {\n        if(a == 0) return {b, 0};\n\
    \        int32_t s = b, t = a, m0 = 0, m1 = 1;\n        while(t) {\n         \
    \   const int32_t u = s / t;\n            s -= t * u;\n            m0 -= m1 *\
    \ u;\n            swap(s, t);\n            swap(m0, m1);\n        }\n        if(m0\
    \ < 0) m0 += b / s;\n        return {s, m0};\n    }\n};\nusing modint998244353\
    \ = StaticModint<998244353>;\nusing modint1000000007 = StaticModint<1000000007>;\n\
    #line 3 \"src/math/matrix.hpp\"\ntemplate <typename T>\nstruct Matrix {\n    Matrix(int\
    \ h, int w, T val = 0)\n        : h(h), w(w), A(h, vector<T>(w, val)) {}\n   \
    \ int H() const {\n        return h;\n    }\n    int W() const {\n        return\
    \ w;\n    }\n    inline const vector<T>& operator[](int i) const {\n        return\
    \ A[i];\n    }\n    inline vector<T>& operator[](int i) {\n        return A[i];\n\
    \    }\n    static Matrix I(int n) {\n        Matrix mat(n, n);\n        for(int\
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
    \    int h, w;\n    vector<vector<T>> A;\n};\n#line 5 \"verify/library_checker/matrix/determinant_of_matric.test.cpp\"\
    \nusing mint = modint998244353;\nint main(void) {\n    int n;\n    cin >> n;\n\
    \    Matrix<mint> a(n, n);\n    rep(i, 0, n) {\n        rep(j, 0, n) {\n     \
    \       cin >> a[i][j];\n        }\n    }\n    cout << a.determinant() << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/template/static_modint.hpp\"\
    \n#include \"../../../src/math/matrix.hpp\"\nusing mint = modint998244353;\nint\
    \ main(void) {\n    int n;\n    cin >> n;\n    Matrix<mint> a(n, n);\n    rep(i,\
    \ 0, n) {\n        rep(j, 0, n) {\n            cin >> a[i][j];\n        }\n  \
    \  }\n    cout << a.determinant() << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/static_modint.hpp
  - src/math/matrix.hpp
  isVerificationFile: true
  path: verify/library_checker/matrix/determinant_of_matric.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/matrix/determinant_of_matric.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/matrix/determinant_of_matric.test.cpp
- /verify/verify/library_checker/matrix/determinant_of_matric.test.cpp.html
title: verify/library_checker/matrix/determinant_of_matric.test.cpp
---
