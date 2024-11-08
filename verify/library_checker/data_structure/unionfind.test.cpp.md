---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/union_find.hpp
    title: UnionFind
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/library_checker/data_structure/unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i,\
    \ a, b) for(ll i = a; i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n\
    \    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n    \
    \    cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/union_find.hpp\"\
    \nstruct UnionFind {\n    UnionFind(int N)\n        : n(N), data(N, -1) {}\n \
    \   int merge(const int a, const int b) {\n        assert(0 <= a and a < n);\n\
    \        assert(0 <= b and b < n);\n        int x = leader(a), y = leader(b);\n\
    \        if(x == y) return x;\n        if(-data[x] < -data[y]) swap(x, y);\n \
    \       data[x] += data[y];\n        data[y] = x;\n        return x;\n    }\n\
    \    bool same(const int a, const int b) {\n        assert(0 <= a and a < n);\n\
    \        assert(0 <= b and b < n);\n        return leader(a) == leader(b);\n \
    \   }\n    int leader(const int a) {\n        assert(0 <= a and a < n);\n    \
    \    if(data[a] < 0) return a;\n        return data[a] = leader(data[a]);\n  \
    \  }\n    int size(const int a) {\n        assert(0 <= a and a < n);\n       \
    \ return -data[leader(a)];\n    }\n    vector<vector<int>> groups() {\n      \
    \  vector<int> leader_buf(n), group_size(n);\n        for(int i = 0; i < n; ++i)\
    \ {\n            leader_buf[i] = leader(i);\n            ++group_size[leader_buf[i]];\n\
    \        }\n        vector<vector<int>> result(n);\n        for(int i = 0; i <\
    \ n; ++i) {\n            result[i].reserve(group_size[i]);\n        }\n      \
    \  for(int i = 0; i < n; ++i) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(remove_if(result.begin(), result.end(), [&](const\
    \ vector<int>& v) { return v.empty(); }), result.end());\n        return result;\n\
    \    }\n\n   private:\n    int n;\n    vector<int> data;\n};\n#line 4 \"verify/library_checker/data_structure/unionfind.test.cpp\"\
    \nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n\
    \    while(q--) {\n        int t, u, v;\n        cin >> t >> u >> v;\n       \
    \ if(t == 0) {\n            uf.merge(u, v);\n        } else {\n            cout\
    \ << uf.same(u, v) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    ../../../src/template/template.hpp\"\n#include \"../../../src/data_structure/union_find.hpp\"\
    \nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n\
    \    while(q--) {\n        int t, u, v;\n        cin >> t >> u >> v;\n       \
    \ if(t == 0) {\n            uf.merge(u, v);\n        } else {\n            cout\
    \ << uf.same(u, v) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/union_find.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 00:13:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/unionfind.test.cpp
- /verify/verify/library_checker/data_structure/unionfind.test.cpp.html
title: verify/library_checker/data_structure/unionfind.test.cpp
---
