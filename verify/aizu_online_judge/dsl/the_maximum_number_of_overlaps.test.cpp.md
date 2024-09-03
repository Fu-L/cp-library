---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/cumulative_sum_2d.hpp
    title: CumulativeSum2D
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
  bundledCode: "#line 1 \"verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/data_structure/cumulative_sum_2d.hpp\"\ntemplate <typename T>\n\
    struct CumulativeSum2D {\n    CumulativeSum2D(int H, int W)\n        : h(H), w(W),\
    \ data(H + 1, vector<T>(W + 1, 0)) {}\n    void add(int i, int j, const T& x)\
    \ {\n        assert(0 <= i and i < h);\n        assert(0 <= j and j < w);\n  \
    \      data[i + 1][j + 1] += x;\n    }\n    void init() {\n        for(int i =\
    \ 1; i < (int)data.size(); ++i) {\n            for(int j = 1; j < (int)data[i].size();\
    \ ++j) {\n                data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i\
    \ - 1][j - 1];\n            }\n        }\n    }\n    T sum(int li, int lj, int\
    \ ri, int rj) {\n        assert(0 <= li and li <= ri and ri <= h);\n        assert(0\
    \ <= lj and lj <= rj and rj <= w);\n        return data[ri][rj] - data[li][rj]\
    \ - data[ri][lj] + data[li][lj];\n    }\n    T get(int i, int j) {\n        assert(0\
    \ <= i and i < h);\n        assert(0 <= j and j < w);\n        return data[i +\
    \ 1][j + 1] - data[i][j + 1] - data[i + 1][j] + data[i][j];\n    }\n\n   private:\n\
    \    int h, w;\n    vector<vector<T>> data;\n};\n#line 4 \"verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps.test.cpp\"\
    \nint main(void) {\n    int n;\n    cin >> n;\n    CumulativeSum2D<int> cum(1001,\
    \ 1001);\n    rep(i, 0, n) {\n        int xl, yl, xr, yr;\n        cin >> xl >>\
    \ yl >> xr >> yr;\n        cum.add(xl, yl, 1);\n        cum.add(xl, yr, -1);\n\
    \        cum.add(xr, yl, -1);\n        cum.add(xr, yr, 1);\n    }\n    cum.init();\n\
    \    int ans = 0;\n    rep(i, 0, 1001) {\n        rep(j, 0, 1001) {\n        \
    \    ans = max(ans, cum.sum(0, 0, i, j));\n        }\n    }\n    cout << ans <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/data_structure/cumulative_sum_2d.hpp\"\
    \nint main(void) {\n    int n;\n    cin >> n;\n    CumulativeSum2D<int> cum(1001,\
    \ 1001);\n    rep(i, 0, n) {\n        int xl, yl, xr, yr;\n        cin >> xl >>\
    \ yl >> xr >> yr;\n        cum.add(xl, yl, 1);\n        cum.add(xl, yr, -1);\n\
    \        cum.add(xr, yl, -1);\n        cum.add(xr, yr, 1);\n    }\n    cum.init();\n\
    \    int ans = 0;\n    rep(i, 0, 1001) {\n        rep(j, 0, 1001) {\n        \
    \    ans = max(ans, cum.sum(0, 0, i, j));\n        }\n    }\n    cout << ans <<\
    \ '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/cumulative_sum_2d.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps.test.cpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps.test.cpp
- /verify/verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps.test.cpp.html
title: verify/aizu_online_judge/dsl/the_maximum_number_of_overlaps.test.cpp
---
