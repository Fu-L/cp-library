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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/data_structure/sparse_table.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 4 \"src/template/template.hpp\"\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/sparse_table.hpp\"\
    \ntemplate <typename S, auto op, auto e>\nstruct SparseTable {\n    SparseTable(const\
    \ vector<S>& v)\n        : n((int)v.size()) {\n        const int b = n == 0 ?\
    \ 1 : 32 - __builtin_clz(n);\n        table.assign(b, vector<S>(n, e()));\n  \
    \      table[0] = v;\n        for(int i = 1; i < b; ++i) {\n            const\
    \ int w = 1 << (i - 1);\n            for(int j = 0; j + w * 2 <= n; ++j) {\n \
    \               table[i][j] = op(table[i - 1][j], table[i - 1][j + w]);\n    \
    \        }\n        }\n    }\n    S prod(const int l, const int r) const {\n \
    \       assert(0 <= l and l <= r and r <= n);\n        if(l == r) return e();\n\
    \        const int b = 31 - __builtin_clz(r - l);\n        return op(table[b][l],\
    \ table[b][r - (1 << b)]);\n    }\n\n   private:\n    int n;\n    vector<vector<S>>\
    \ table;\n};\n#line 4 \"verify/unit_test/data_structure/sparse_table.test.cpp\"\
    \nint op(int a, int b) {\n    return min(a, b);\n}\nint e() {\n    return (int)1e9;\n\
    }\nint main() {\n    SparseTable<int, op, e> st(vector<int>{});\n    assert(st.prod(0,\
    \ 0) == e());\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/data_structure/sparse_table.hpp\"\nint op(int a, int\
    \ b) {\n    return min(a, b);\n}\nint e() {\n    return (int)1e9;\n}\nint main()\
    \ {\n    SparseTable<int, op, e> st(vector<int>{});\n    assert(st.prod(0, 0)\
    \ == e());\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/sparse_table.hpp
  isVerificationFile: true
  path: verify/unit_test/data_structure/sparse_table.test.cpp
  requiredBy: []
  timestamp: '2026-07-04 16:35:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/data_structure/sparse_table.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/data_structure/sparse_table.test.cpp
- /verify/verify/unit_test/data_structure/sparse_table.test.cpp.html
title: verify/unit_test/data_structure/sparse_table.test.cpp
---
