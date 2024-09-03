---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/fenwick_tree_2d.hpp
    title: FenwickTree2D
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
  bundledCode: "#line 1 \"verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps_2.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/data_structure/fenwick_tree_2d.hpp\"\ntemplate <typename T>\nstruct\
    \ FenwickTree2D {\n    FenwickTree2D(int H, int W)\n        : h(H), w(W), data(H\
    \ + 1, vector<T>(W + 1, 0)) {}\n    void add(int i, int j, const T& z) {\n   \
    \     assert(0 <= i and i < h);\n        assert(0 <= j and j < w);\n        for(int\
    \ x = i + 1; x <= h; x += x & -x) {\n            for(int y = j + 1; y <= w; y\
    \ += y & -y) {\n                data[x - 1][y - 1] += z;\n            }\n    \
    \    }\n    }\n    T sum(int li, int lj, int ri, int rj) {\n        assert(0 <=\
    \ li and li <= ri and ri <= h);\n        assert(0 <= lj and lj <= rj and rj <=\
    \ w);\n        return sum(ri, rj) - sum(li, rj) - sum(ri, lj) + sum(li, lj);\n\
    \    }\n    T get(int i, int j) {\n        assert(0 <= i and i < h);\n       \
    \ assert(0 <= j and j < w);\n        return sum(i + 1, j + 1) - sum(i, j + 1)\
    \ - sum(i + 1, j) + sum(i, j);\n    }\n\n   private:\n    int h, w;\n    vector<vector<T>>\
    \ data;\n    inline T sum(int i, int j) {\n        T s = 0;\n        for(int x\
    \ = i; x > 0; x -= x & -x) {\n            for(int y = j; y > 0; y -= y & -y) {\n\
    \                s += data[x - 1][y - 1];\n            }\n        }\n        return\
    \ s;\n    }\n};\n#line 4 \"verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps_2.test.cpp\"\
    \nint main(void) {\n    int n;\n    cin >> n;\n    FenwickTree2D<int> fw(1001,\
    \ 1001);\n    rep(i, 0, n) {\n        int xl, yl, xr, yr;\n        cin >> xl >>\
    \ yl >> xr >> yr;\n        fw.add(xl, yl, 1);\n        fw.add(xl, yr, -1);\n \
    \       fw.add(xr, yl, -1);\n        fw.add(xr, yr, 1);\n    }\n    int ans =\
    \ 0;\n    rep(i, 0, 1001) {\n        rep(j, 0, 1001) {\n            ans = max(ans,\
    \ fw.sum(0, 0, i, j));\n        }\n    }\n    cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/data_structure/fenwick_tree_2d.hpp\"\
    \nint main(void) {\n    int n;\n    cin >> n;\n    FenwickTree2D<int> fw(1001,\
    \ 1001);\n    rep(i, 0, n) {\n        int xl, yl, xr, yr;\n        cin >> xl >>\
    \ yl >> xr >> yr;\n        fw.add(xl, yl, 1);\n        fw.add(xl, yr, -1);\n \
    \       fw.add(xr, yl, -1);\n        fw.add(xr, yr, 1);\n    }\n    int ans =\
    \ 0;\n    rep(i, 0, 1001) {\n        rep(j, 0, 1001) {\n            ans = max(ans,\
    \ fw.sum(0, 0, i, j));\n        }\n    }\n    cout << ans << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/fenwick_tree_2d.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps_2.test.cpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps_2.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps_2.test.cpp
- /verify/verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps_2.test.cpp.html
title: verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps_2.test.cpp
---
