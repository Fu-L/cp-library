---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/weighted_union_find.hpp
    title: WeightedUnionFind
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
  bundledCode: "#line 1 \"verify/aizu_online_judge/dsl/weighted_union_find_trees.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B\"\n#line\
    \ 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i\
    \ = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/data_structure/weighted_union_find.hpp\"\ntemplate <typename T>\n\
    struct WeightedUnionFind {\n    WeightedUnionFind(int N)\n        : n(N), data(N,\
    \ -1), ws(N, T()) {}\n    bool merge(int a, int b, T w) {\n        assert(0 <=\
    \ a and a < n);\n        assert(0 <= b and b < n);\n        w += weight(b) - weight(a);\n\
    \        int x = leader(a), y = leader(b);\n        if(x == y) return w == T();\n\
    \        if(-data[x] > -data[y]) swap(x, y), w = -w;\n        data[y] += data[x];\n\
    \        data[x] = y;\n        ws[x] = w;\n        return true;\n    }\n    bool\
    \ same(int a, int b) {\n        assert(0 <= a and a < n);\n        assert(0 <=\
    \ b and b < n);\n        return leader(a) == leader(b);\n    }\n    int leader(int\
    \ a) {\n        assert(0 <= a and a < n);\n        if(data[a] < 0) return a;\n\
    \        int r = leader(data[a]);\n        ws[a] += ws[data[a]];\n        return\
    \ data[a] = r;\n    }\n    int size(int a) {\n        assert(0 <= a and a < n);\n\
    \        return -data[leader(a)];\n    }\n    T weight(int a) {\n        assert(0\
    \ <= a and a < n);\n        leader(a);\n        return ws[a];\n    }\n    T diff(int\
    \ a, int b) {\n        assert(0 <= a and a < n);\n        assert(0 <= b and b\
    \ < n);\n        return weight(a) - weight(b);\n    }\n\n   private:\n    int\
    \ n;\n    vector<int> data;\n    vector<T> ws;\n};\n#line 4 \"verify/aizu_online_judge/dsl/weighted_union_find_trees.test.cpp\"\
    \nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    WeightedUnionFind<int>\
    \ uf(n);\n    while(q--) {\n        int t;\n        cin >> t;\n        if(t ==\
    \ 0) {\n            int x, y, z;\n            cin >> x >> y >> z;\n          \
    \  uf.merge(y, x, z);\n        } else {\n            int x, y;\n            cin\
    \ >> x >> y;\n            if(uf.same(x, y)) {\n                cout << uf.diff(y,\
    \ x) << '\\n';\n            } else {\n                cout << '?' << '\\n';\n\
    \            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/data_structure/weighted_union_find.hpp\"\
    \nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    WeightedUnionFind<int>\
    \ uf(n);\n    while(q--) {\n        int t;\n        cin >> t;\n        if(t ==\
    \ 0) {\n            int x, y, z;\n            cin >> x >> y >> z;\n          \
    \  uf.merge(y, x, z);\n        } else {\n            int x, y;\n            cin\
    \ >> x >> y;\n            if(uf.same(x, y)) {\n                cout << uf.diff(y,\
    \ x) << '\\n';\n            } else {\n                cout << '?' << '\\n';\n\
    \            }\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/weighted_union_find.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/dsl/weighted_union_find_trees.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 22:10:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/dsl/weighted_union_find_trees.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/dsl/weighted_union_find_trees.test.cpp
- /verify/verify/aizu_online_judge/dsl/weighted_union_find_trees.test.cpp.html
title: verify/aizu_online_judge/dsl/weighted_union_find_trees.test.cpp
---
