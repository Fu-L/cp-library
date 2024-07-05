---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: matrix/gauss_elimination.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../graph/graph_template.hpp\"\
    \n#include \"./matrix.hpp\"\n#include \"./matrix/gauss_elimination.hpp\"\ntemplate\
    \ <typename T, typename U>\nT counting_spanning_tree_directed(const Graph<U>&\
    \ g, int r) {\n    const int n = g.size();\n    assert(0 <= r and r < n);\n  \
    \  Matrix<T> mat(n, n);\n    for(int i = 0; i < n; ++i) {\n        for(const auto&\
    \ e : g[i]) {\n            --mat[i][e.to];\n            ++mat[e.to][e.to];\n \
    \       }\n    }\n    Matrix<T> lap(n - 1, n - 1);\n    int h = 0, w = 0;\n  \
    \  for(int i = 0; i < n; ++i) {\n        if(i == r) {\n            h = 1;\n  \
    \          continue;\n        }\n        for(int j = 0; j < n; ++j) {\n      \
    \      if(j == r) {\n                w = 1;\n                continue;\n     \
    \       }\n            lap[i - h][j - w] = mat[i][j];\n        }\n        w =\
    \ 0;\n    }\n    return gauss_elimination(lap).second;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/matrix/counting_spanning_tree_directed.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/matrix/counting_spanning_tree_directed.hpp
layout: document
title: counting_spanning_tree_directed
---

## counting_spanning_tree_directed

```cpp
T counting_spanning_tree_directed(Graph<U> g, int r)
```

有向グラフ $G$ の頂点 $r$ を根とする有向全域木の個数を返します．

**制約**

$G$ の頂点数を $N$ として，

- $0 \leq r < N$

**計算量**

$G$ の頂点数と辺数をそれぞれ $N, M$ として，

- $O(NM + N^3)$
