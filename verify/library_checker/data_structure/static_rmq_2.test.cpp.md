---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/disjoint_sparse_table.hpp
    title: DisjointSparseTable
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/library_checker/data_structure/static_rmq_2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ P = pair<long long, long long>;\n#define rep(i, a, b) for(long long i = (a);\
    \ i < (b); ++i)\n#define rrep(i, a, b) for(long long i = (a); i >= (b); --i)\n\
    constexpr long long inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/data_structure/disjoint_sparse_table.hpp\"\ntemplate <typename S,\
    \ auto op, auto e>\nstruct DisjointSparseTable {\n    DisjointSparseTable(const\
    \ vector<S>& v)\n        : n((int)v.size() + 2) {\n        const int b = 32 -\
    \ __builtin_clz(n - 1);\n        table.assign(b, vector<S>(n, e()));\n       \
    \ for(int k = 1; k < b; ++k) {\n            const int w = (1 << k);\n        \
    \    for(int i = w; i < n; i += w * 2) {\n                for(int j = i - 1; j\
    \ > i - w; --j) {\n                    table[k][j - 1] = op(table[k][j], v[j -\
    \ 1]);\n                }\n                const int m = min(i + w - 1, n - 1);\n\
    \                for(int j = i; j < m; ++j) {\n                    table[k][j\
    \ + 1] = op(table[k][j], v[j - 1]);\n                }\n            }\n      \
    \  }\n    }\n    S prod(const int l, int r) const {\n        assert(0 <= l and\
    \ l <= r and r <= n);\n        ++r;\n        const auto& s = table[31 - __builtin_clz(l\
    \ xor r)];\n        return op(s[l], s[r]);\n    }\n\n   private:\n    int n;\n\
    \    vector<vector<S>> table;\n};\n#line 4 \"verify/library_checker/data_structure/static_rmq_2.test.cpp\"\
    \nint op(int x, int y) {\n    return min(x, y);\n}\nint e() {\n    return 1e9;\n\
    }\nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n\
    \    rep(i, 0, n) {\n        cin >> a[i];\n    }\n    DisjointSparseTable<int,\
    \ op, e> dst(a);\n    while(q--) {\n        int l, r;\n        cin >> l >> r;\n\
    \        cout << dst.prod(l, r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    ../../../src/template/template.hpp\"\n#include \"../../../src/data_structure/disjoint_sparse_table.hpp\"\
    \nint op(int x, int y) {\n    return min(x, y);\n}\nint e() {\n    return 1e9;\n\
    }\nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n\
    \    rep(i, 0, n) {\n        cin >> a[i];\n    }\n    DisjointSparseTable<int,\
    \ op, e> dst(a);\n    while(q--) {\n        int l, r;\n        cin >> l >> r;\n\
    \        cout << dst.prod(l, r) << '\\n';\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/disjoint_sparse_table.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/static_rmq_2.test.cpp
  requiredBy: []
  timestamp: '2025-02-05 15:45:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/static_rmq_2.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/static_rmq_2.test.cpp
- /verify/verify/library_checker/data_structure/static_rmq_2.test.cpp.html
title: verify/library_checker/data_structure/static_rmq_2.test.cpp
---
