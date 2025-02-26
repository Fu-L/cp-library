---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/others/longest_increasing_sequence.hpp
    title: src/others/longest_increasing_sequence.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"verify/library_checker/other/longest_increasing_sequence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/others/longest_increasing_sequence.hpp\"\
    \ntemplate <typename T>\nvector<int> longest_increasing_sequence(const vector<T>&\
    \ a) {\n    const int n = a.size();\n    vector<pair<T, int>> dp;\n    vector<int>\
    \ p(n, -1);\n    for(int i = 0; i < n; ++i) {\n        auto it = lower_bound(begin(dp),\
    \ end(dp), make_pair(a[i], -i));\n        if(it != begin(dp)) p[i] = -prev(it)->second;\n\
    \        if(it == end(dp)) {\n            dp.emplace_back(a[i], -i);\n       \
    \ } else {\n            *it = make_pair(a[i], -i);\n        }\n    }\n    vector<int>\
    \ res;\n    for(int i = -dp.back().second; i != -1; i = p[i]) res.push_back(i);\n\
    \    reverse(begin(res), end(res));\n    return res;\n}\n#line 4 \"verify/library_checker/other/longest_increasing_sequence.test.cpp\"\
    \nint main(void) {\n    int n;\n    cin >> n;\n    vector<int> a(n);\n    rep(i,\
    \ 0, n) cin >> a[i];\n    vector<int> lis = longest_increasing_sequence(a);\n\
    \    cout << lis.size() << '\\n';\n    rep(i, 0, (int)lis.size()) cout << lis[i]\
    \ << \" \\n\"[i + 1 == (int)lis.size()];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/others/longest_increasing_sequence.hpp\"\
    \nint main(void) {\n    int n;\n    cin >> n;\n    vector<int> a(n);\n    rep(i,\
    \ 0, n) cin >> a[i];\n    vector<int> lis = longest_increasing_sequence(a);\n\
    \    cout << lis.size() << '\\n';\n    rep(i, 0, (int)lis.size()) cout << lis[i]\
    \ << \" \\n\"[i + 1 == (int)lis.size()];\n}"
  dependsOn:
  - src/template/template.hpp
  - src/others/longest_increasing_sequence.hpp
  isVerificationFile: true
  path: verify/library_checker/other/longest_increasing_sequence.test.cpp
  requiredBy: []
  timestamp: '2025-02-27 04:25:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/other/longest_increasing_sequence.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/other/longest_increasing_sequence.test.cpp
- /verify/verify/library_checker/other/longest_increasing_sequence.test.cpp.html
title: verify/library_checker/other/longest_increasing_sequence.test.cpp
---
