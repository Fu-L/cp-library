---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/matrix/gauss_elimination.hpp
    title: gauss_elimination
  - icon: ':heavy_check_mark:'
    path: src/matrix/matrix.hpp
    title: Matrix
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/enumerative_combinatrics/counting_spanning_tree_undirected.test.cpp
    title: verify/library_checker/enumerative_combinatrics/counting_spanning_tree_undirected.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/graph/graph_template.hpp\"\
    \ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T cost;\n    int\
    \ idx;\n    Edge()\n        : from(-1), to(-1), cost(-1), idx(-1) {}\n    Edge(const\
    \ int from, const int to, const T& cost = 1, const int idx = -1)\n        : from(from),\
    \ to(to), cost(cost), idx(idx) {}\n    operator int() const {\n        return\
    \ to;\n    }\n};\ntemplate <typename T>\nstruct Graph {\n    Graph(const int N)\n\
    \        : n(N), es(0), g(N) {}\n    int size() const {\n        return n;\n \
    \   }\n    int edge_size() const {\n        return es;\n    }\n    void add_edge(const\
    \ int from, const int to, const T& cost = 1) {\n        assert(0 <= from and from\
    \ < n);\n        assert(0 <= to and to < n);\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n \
    \   void add_directed_edge(const int from, const int to, const T& cost = 1) {\n\
    \        assert(0 <= from and from < n);\n        assert(0 <= to and to < n);\n\
    \        g[from].emplace_back(from, to, cost, es++);\n    }\n    inline vector<Edge<T>>&\
    \ operator[](const int& k) {\n        assert(0 <= k and k < n);\n        return\
    \ g[k];\n    }\n    inline const vector<Edge<T>>& operator[](const int& k) const\
    \ {\n        assert(0 <= k and k < n);\n        return g[k];\n    }\n\n   private:\n\
    \    int n, es;\n    vector<vector<Edge<T>>> g;\n};\ntemplate <typename T>\nusing\
    \ Edges = vector<Edge<T>>;\n#line 3 \"src/matrix/matrix.hpp\"\ntemplate <typename\
    \ T>\nstruct Matrix {\n    Matrix(int h, int w, T val = 0)\n        : h(h), w(w),\
    \ A(h, vector<T>(w, val)) {}\n    int H() const {\n        return h;\n    }\n\
    \    int W() const {\n        return w;\n    }\n    const vector<T>& operator[](int\
    \ i) const {\n        assert(0 <= i and i < h);\n        return A[i];\n    }\n\
    \    vector<T>& operator[](int i) {\n        assert(0 <= i and i < h);\n     \
    \   return A[i];\n    }\n    static Matrix I(int n) {\n        Matrix mat(n, n);\n\
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
    \    int h, w;\n    vector<vector<T>> A;\n};\n#line 4 \"src/matrix/gauss_elimination.hpp\"\
    \ntemplate <typename T>\npair<int, T> gauss_elimination(Matrix<T>& a, int pivot_end\
    \ = -1) {\n    int h = a.H(), w = a.W(), rank = 0;\n    assert(-1 <= pivot_end\
    \ and pivot_end <= w);\n    if(pivot_end == -1) pivot_end = w;\n    T det = 1;\n\
    \    for(int j = 0; j < pivot_end; ++j) {\n        int idx = -1;\n        for(int\
    \ i = rank; i < h; ++i) {\n            if(a[i][j] != T(0)) {\n               \
    \ idx = i;\n                break;\n            }\n        }\n        if(idx ==\
    \ -1) {\n            det = 0;\n            continue;\n        }\n        if(rank\
    \ != idx) det = -det, swap(a[rank], a[idx]);\n        det *= a[rank][j];\n   \
    \     if(a[rank][j] != T(1)) {\n            const T coeff = T(1) / a[rank][j];\n\
    \            for(int k = j; k < w; ++k) a[rank][k] *= coeff;\n        }\n    \
    \    for(int i = 0; i < h; ++i) {\n            if(i == rank) continue;\n     \
    \       if(a[i][j] != T(0)) {\n                const T coeff = a[i][j] / a[rank][j];\n\
    \                for(int k = j; k < w; ++k) a[i][k] -= a[rank][k] * coeff;\n \
    \           }\n        }\n        ++rank;\n    }\n    return {rank, det};\n}\n\
    #line 6 \"src/matrix/counting_spanning_tree_undirected.hpp\"\ntemplate <typename\
    \ T, typename U>\nT counting_spanning_tree_undirected(const Graph<U>& g) {\n \
    \   const int n = g.size();\n    Matrix<T> mat(n, n);\n    for(int i = 0; i <\
    \ n; ++i) {\n        mat[i][i] = (int)g[i].size();\n        for(const auto& e\
    \ : g[i]) {\n            --mat[i][e.to];\n        }\n    }\n    Matrix<T> lap(n\
    \ - 1, n - 1);\n    for(int i = 0; i < n - 1; ++i) {\n        for(int j = 0; j\
    \ < n - 1; ++j) {\n            lap[i][j] = mat[i][j];\n        }\n    }\n    return\
    \ gauss_elimination(lap).second;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../graph/graph_template.hpp\"\
    \n#include \"./matrix.hpp\"\n#include \"./gauss_elimination.hpp\"\ntemplate <typename\
    \ T, typename U>\nT counting_spanning_tree_undirected(const Graph<U>& g) {\n \
    \   const int n = g.size();\n    Matrix<T> mat(n, n);\n    for(int i = 0; i <\
    \ n; ++i) {\n        mat[i][i] = (int)g[i].size();\n        for(const auto& e\
    \ : g[i]) {\n            --mat[i][e.to];\n        }\n    }\n    Matrix<T> lap(n\
    \ - 1, n - 1);\n    for(int i = 0; i < n - 1; ++i) {\n        for(int j = 0; j\
    \ < n - 1; ++j) {\n            lap[i][j] = mat[i][j];\n        }\n    }\n    return\
    \ gauss_elimination(lap).second;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/matrix/matrix.hpp
  - src/matrix/gauss_elimination.hpp
  isVerificationFile: false
  path: src/matrix/counting_spanning_tree_undirected.hpp
  requiredBy: []
  timestamp: '2024-11-09 00:36:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/enumerative_combinatrics/counting_spanning_tree_undirected.test.cpp
documentation_of: src/matrix/counting_spanning_tree_undirected.hpp
layout: document
title: counting_spanning_tree_undirected
---

## counting_spanning_tree_undirected

```cpp
T counting_spanning_tree_undirected(Graph<U> g)
```

無向グラフ $G$ の全域木の個数を返します．

**制約**

- $G$ は無向グラフ

**計算量**

$G$ の頂点数と辺数をそれぞれ $N, M$ として，

- $O(NM + N^3)$
