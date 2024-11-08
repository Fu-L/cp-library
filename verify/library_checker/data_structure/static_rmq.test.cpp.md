---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/sparse_table.hpp
    title: SparseTable
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
  bundledCode: "#line 1 \"verify/library_checker/data_structure/static_rmq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i,\
    \ a, b) for(ll i = a; i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n\
    \    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n    \
    \    cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/sparse_table.hpp\"\
    \ntemplate <typename S, auto op, auto e>\nstruct SparseTable {\n    SparseTable(const\
    \ vector<S>& v)\n        : n((int)v.size()) {\n        int b = 1;\n        while((1\
    \ << b) <= n) ++b;\n        table.push_back(v);\n        for(int i = 1; i < b;\
    \ ++i) {\n            table.push_back(vector<S>(n, e()));\n            for(int\
    \ j = 0; j + (1 << i) <= n; ++j) {\n                table[i][j] = op(table[i -\
    \ 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n    }\n\
    \    S prod(const int l, const int r) const {\n        assert(0 <= l and l <=\
    \ r and r <= n);\n        if(l == r) return e();\n        const int b = 31 - __builtin_clz(r\
    \ - l);\n        return op(table[b][l], table[b][r - (1 << b)]);\n    }\n\n  \
    \ private:\n    int n;\n    vector<vector<S>> table;\n};\n#line 4 \"verify/library_checker/data_structure/static_rmq.test.cpp\"\
    \nint op(int x, int y) {\n    return min(x, y);\n}\nint e() {\n    return 1e9;\n\
    }\nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n\
    \    rep(i, 0, n) {\n        cin >> a[i];\n    }\n    SparseTable<int, op, e>\
    \ st(a);\n    while(q--) {\n        int l, r;\n        cin >> l >> r;\n      \
    \  cout << st.prod(l, r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    ../../../src/template/template.hpp\"\n#include \"../../../src/data_structure/sparse_table.hpp\"\
    \nint op(int x, int y) {\n    return min(x, y);\n}\nint e() {\n    return 1e9;\n\
    }\nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n\
    \    rep(i, 0, n) {\n        cin >> a[i];\n    }\n    SparseTable<int, op, e>\
    \ st(a);\n    while(q--) {\n        int l, r;\n        cin >> l >> r;\n      \
    \  cout << st.prod(l, r) << '\\n';\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/sparse_table.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/static_rmq.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 00:13:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/static_rmq.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/static_rmq.test.cpp
- /verify/verify/library_checker/data_structure/static_rmq.test.cpp.html
title: verify/library_checker/data_structure/static_rmq.test.cpp
---
