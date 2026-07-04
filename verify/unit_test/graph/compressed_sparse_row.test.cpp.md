---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/compressed_sparse_row.hpp
    title: CompressedSparseRow
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
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
  bundledCode: "#line 1 \"verify/unit_test/graph/compressed_sparse_row.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 4 \"src/template/template.hpp\"\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/graph/graph_template.hpp\"\
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
    \ Edges = vector<Edge<T>>;\n#line 4 \"src/graph/compressed_sparse_row.hpp\"\n\
    template <typename T>\nstruct CompressedSparseRow {\n    vector<int> start, elist;\n\
    \    CompressedSparseRow(const Graph<T>& g)\n        : start(g.size() + 1) {\n\
    \        const int n = g.size();\n        for(int i = 0; i < n; ++i) {\n     \
    \       start[i + 1] = start[i] + g[i].size();\n        }\n        elist.resize(start[n]);\n\
    \        for(int i = 0; i < n; ++i) {\n            int counter = start[i];\n \
    \           for(const Edge<T>& e : g[i]) {\n                elist[counter++] =\
    \ e.to;\n            }\n        }\n    }\n};\n#line 5 \"verify/unit_test/graph/compressed_sparse_row.test.cpp\"\
    \nint main() {\n    Graph<int> undirected(4);\n    undirected.add_edge(0, 1);\n\
    \    undirected.add_edge(0, 2);\n    undirected.add_edge(2, 3);\n    CompressedSparseRow<int>\
    \ csr1(undirected);\n    assert(csr1.start == vector<int>({0, 2, 3, 5, 6}));\n\
    \    assert(csr1.elist == vector<int>({1, 2, 0, 0, 3, 2}));\n    Graph<int> directed(4);\n\
    \    directed.add_directed_edge(0, 1);\n    directed.add_directed_edge(0, 2);\n\
    \    directed.add_directed_edge(2, 3);\n    CompressedSparseRow<int> csr2(directed);\n\
    \    assert(csr2.start == vector<int>({0, 2, 2, 3, 3}));\n    assert(csr2.elist\
    \ == vector<int>({1, 2, 3}));\n    int a, b;\n    cin >> a >> b;\n    cout <<\
    \ a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/graph/graph_template.hpp\"\n#include \"../../../src/graph/compressed_sparse_row.hpp\"\
    \nint main() {\n    Graph<int> undirected(4);\n    undirected.add_edge(0, 1);\n\
    \    undirected.add_edge(0, 2);\n    undirected.add_edge(2, 3);\n    CompressedSparseRow<int>\
    \ csr1(undirected);\n    assert(csr1.start == vector<int>({0, 2, 3, 5, 6}));\n\
    \    assert(csr1.elist == vector<int>({1, 2, 0, 0, 3, 2}));\n    Graph<int> directed(4);\n\
    \    directed.add_directed_edge(0, 1);\n    directed.add_directed_edge(0, 2);\n\
    \    directed.add_directed_edge(2, 3);\n    CompressedSparseRow<int> csr2(directed);\n\
    \    assert(csr2.start == vector<int>({0, 2, 2, 3, 3}));\n    assert(csr2.elist\
    \ == vector<int>({1, 2, 3}));\n    int a, b;\n    cin >> a >> b;\n    cout <<\
    \ a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/graph/compressed_sparse_row.hpp
  isVerificationFile: true
  path: verify/unit_test/graph/compressed_sparse_row.test.cpp
  requiredBy: []
  timestamp: '2026-07-04 16:35:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/graph/compressed_sparse_row.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/graph/compressed_sparse_row.test.cpp
- /verify/verify/unit_test/graph/compressed_sparse_row.test.cpp.html
title: verify/unit_test/graph/compressed_sparse_row.test.cpp
---
