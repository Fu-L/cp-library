---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/fenwick_tree.hpp
    title: FenwickTree
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/library_checker/data_structure/point_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line\
    \ 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i\
    \ = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/data_structure/fenwick_tree.hpp\"\ntemplate <typename T>\nstruct\
    \ FenwickTree {\n    FenwickTree(int N)\n        : n(N), data(N) {}\n    void\
    \ add(int p, T x) {\n        assert(0 <= p and p < n);\n        ++p;\n       \
    \ while(p <= n) {\n            data[p - 1] += x;\n            p += p & -p;\n \
    \       }\n    }\n    T sum(int l, int r) const {\n        assert(0 <= l and l\
    \ <= r and r <= n);\n        return sum(r) - sum(l);\n    }\n    T operator[](int\
    \ x) const {\n        assert(0 <= x and x < n);\n        return sum(x + 1) - sum(x);\n\
    \    }\n\n   private:\n    int n;\n    vector<T> data;\n    inline T sum(int r)\
    \ const {\n        T s = 0;\n        while(r > 0) {\n            s += data[r -\
    \ 1];\n            r -= r & -r;\n        }\n        return s;\n    }\n};\n#line\
    \ 4 \"verify/library_checker/data_structure/point_add_range_sum.test.cpp\"\nint\
    \ main(void) {\n    int n, q;\n    cin >> n >> q;\n    FenwickTree<ll> fw(n);\n\
    \    rep(i, 0, n) {\n        ll a;\n        cin >> a;\n        fw.add(i, a);\n\
    \    }\n    while(q--) {\n        int t;\n        cin >> t;\n        if(t == 0)\
    \ {\n            int p, x;\n            cin >> p >> x;\n            fw.add(p,\
    \ x);\n        } else {\n            int l, r;\n            cin >> l >> r;\n \
    \           cout << fw.sum(l, r) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../../../src/template/template.hpp\"\n#include \"../../../src/data_structure/fenwick_tree.hpp\"\
    \nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    FenwickTree<ll> fw(n);\n\
    \    rep(i, 0, n) {\n        ll a;\n        cin >> a;\n        fw.add(i, a);\n\
    \    }\n    while(q--) {\n        int t;\n        cin >> t;\n        if(t == 0)\
    \ {\n            int p, x;\n            cin >> p >> x;\n            fw.add(p,\
    \ x);\n        } else {\n            int l, r;\n            cin >> l >> r;\n \
    \           cout << fw.sum(l, r) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/point_add_range_sum.test.cpp
- /verify/verify/library_checker/data_structure/point_add_range_sum.test.cpp.html
title: verify/library_checker/data_structure/point_add_range_sum.test.cpp
---
