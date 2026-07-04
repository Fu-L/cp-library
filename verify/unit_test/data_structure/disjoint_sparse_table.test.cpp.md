---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/disjoint_sparse_table.hpp
    title: DisjointSparseTable
  - icon: ':question:'
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
  bundledCode: "#line 1 \"verify/unit_test/data_structure/disjoint_sparse_table.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 4 \"src/template/template.hpp\"\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/disjoint_sparse_table.hpp\"\
    \ntemplate <typename S, auto op, auto e>\nstruct DisjointSparseTable {\n    DisjointSparseTable(const\
    \ vector<S>& v)\n        : n((int)v.size()), internal_n(n + 2) {\n        const\
    \ int b = 32 - __builtin_clz(internal_n - 1);\n        table.assign(b, vector<S>(internal_n,\
    \ e()));\n        for(int k = 1; k < b; ++k) {\n            const int w = (1 <<\
    \ k);\n            for(int i = w; i < internal_n; i += w * 2) {\n            \
    \    for(int j = i - 1; j > i - w; --j) {\n                    table[k][j - 1]\
    \ = op(table[k][j], v[j - 1]);\n                }\n                const int m\
    \ = min(i + w - 1, internal_n - 1);\n                for(int j = i; j < m; ++j)\
    \ {\n                    table[k][j + 1] = op(table[k][j], v[j - 1]);\n      \
    \          }\n            }\n        }\n    }\n    S prod(const int l, int r)\
    \ const {\n        assert(0 <= l and l <= r and r <= n);\n        ++r;\n     \
    \   const auto& s = table[31 - __builtin_clz(l xor r)];\n        return op(s[l],\
    \ s[r]);\n    }\n\n   private:\n    int n, internal_n;\n    vector<vector<S>>\
    \ table;\n};\n#line 4 \"verify/unit_test/data_structure/disjoint_sparse_table.test.cpp\"\
    \nint op(int a, int b) {\n    return min(a, b);\n}\nint e() {\n    return (int)1e9;\n\
    }\nint main() {\n    DisjointSparseTable<int, op, e> dst(vector<int>{});\n   \
    \ assert(dst.prod(0, 0) == e());\n    DisjointSparseTable<int, op, e> dst2(vector<int>{5,\
    \ 2, 7});\n    assert(dst2.prod(0, 0) == e());\n    assert(dst2.prod(0, 3) ==\
    \ 2);\n    assert(dst2.prod(2, 3) == 7);\n    int a, b;\n    cin >> a >> b;\n\
    \    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/data_structure/disjoint_sparse_table.hpp\"\nint op(int\
    \ a, int b) {\n    return min(a, b);\n}\nint e() {\n    return (int)1e9;\n}\n\
    int main() {\n    DisjointSparseTable<int, op, e> dst(vector<int>{});\n    assert(dst.prod(0,\
    \ 0) == e());\n    DisjointSparseTable<int, op, e> dst2(vector<int>{5, 2, 7});\n\
    \    assert(dst2.prod(0, 0) == e());\n    assert(dst2.prod(0, 3) == 2);\n    assert(dst2.prod(2,\
    \ 3) == 7);\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/disjoint_sparse_table.hpp
  isVerificationFile: true
  path: verify/unit_test/data_structure/disjoint_sparse_table.test.cpp
  requiredBy: []
  timestamp: '2026-07-04 16:35:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/data_structure/disjoint_sparse_table.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/data_structure/disjoint_sparse_table.test.cpp
- /verify/verify/unit_test/data_structure/disjoint_sparse_table.test.cpp.html
title: verify/unit_test/data_structure/disjoint_sparse_table.test.cpp
---
