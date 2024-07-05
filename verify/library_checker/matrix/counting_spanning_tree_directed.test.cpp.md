---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: matrix/gauss_elimination.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_spanning_tree_directed\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/template/static_modint.hpp\"\
    \nusing mint = modint998244353;\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/matrix/matrix.hpp\"\n#include \"../../../src/matrix/gauss_elimination.hpp\"\
    \n#include \"../../../src/matrix/counting_spanning_tree_directed.hpp\"\nint main(void)\
    \ {\n    int n, m, r;\n    cin >> n >> m >> r;\n    Graph<int> g(n);\n    rep(i,\
    \ 0, m) {\n        int u, v;\n        cin >> u >> v;\n        g.add_directed_edge(u,\
    \ v);\n    }\n    cout << counting_spanning_tree_directed<mint>(g, r) << '\\n';\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: verify/library_checker/matrix/counting_spanning_tree_directed.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/matrix/counting_spanning_tree_directed.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/matrix/counting_spanning_tree_directed.test.cpp
- /verify/verify/library_checker/matrix/counting_spanning_tree_directed.test.cpp.html
title: verify/library_checker/matrix/counting_spanning_tree_directed.test.cpp
---
