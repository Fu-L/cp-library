---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/longest_increasing_sequence.hpp
    title: longest_increasing_sequence
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
  bundledCode: "#line 1 \"verify/unit_test/dp/longest_increasing_sequence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 4 \"src/template/template.hpp\"\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/dp/longest_increasing_sequence.hpp\"\
    \ntemplate <typename T>\nvector<int> longest_increasing_sequence(const vector<T>&\
    \ a) {\n    const int n = a.size();\n    if(n == 0) return {};\n    vector<pair<T,\
    \ int>> dp;\n    vector<int> p(n, -1);\n    for(int i = 0; i < n; ++i) {\n   \
    \     auto it = lower_bound(begin(dp), end(dp), make_pair(a[i], -i));\n      \
    \  if(it != begin(dp)) p[i] = -prev(it)->second;\n        if(it == end(dp)) {\n\
    \            dp.emplace_back(a[i], -i);\n        } else {\n            *it = make_pair(a[i],\
    \ -i);\n        }\n    }\n    vector<int> res;\n    for(int i = -dp.back().second;\
    \ i != -1; i = p[i]) res.push_back(i);\n    reverse(begin(res), end(res));\n \
    \   return res;\n}\n#line 4 \"verify/unit_test/dp/longest_increasing_sequence.test.cpp\"\
    \nint brute_length(const vector<int>& a) {\n    const int n = (int)a.size();\n\
    \    int res = 0;\n    for(int bit = 0; bit < (1 << n); ++bit) {\n        vector<int>\
    \ b;\n        for(int i = 0; i < n; ++i) {\n            if((bit >> i) & 1) b.push_back(a[i]);\n\
    \        }\n        bool ok = true;\n        for(int i = 1; i < (int)b.size();\
    \ ++i) {\n            if(b[i - 1] >= b[i]) ok = false;\n        }\n        if(ok)\
    \ res = max(res, (int)b.size());\n    }\n    return res;\n}\nvoid check(const\
    \ vector<int>& a) {\n    const vector<int> lis = longest_increasing_sequence(a);\n\
    \    assert((int)lis.size() == brute_length(a));\n    for(int i = 0; i < (int)lis.size();\
    \ ++i) {\n        assert(0 <= lis[i] and lis[i] < (int)a.size());\n        if(i)\
    \ {\n            assert(lis[i - 1] < lis[i]);\n            assert(a[lis[i - 1]]\
    \ < a[lis[i]]);\n        }\n    }\n}\nint main() {\n    check({});\n    check({3,\
    \ 2, 1});\n    check({1, 1, 1});\n    check({3, 1, 2, 1, 4});\n    for(int n =\
    \ 0; n <= 10; ++n) {\n        const int total = 1 << n;\n        for(int bit =\
    \ 0; bit < total; ++bit) {\n            vector<int> a(n);\n            for(int\
    \ i = 0; i < n; ++i) a[i] = ((bit >> i) & 1) ? 1 : 0;\n            check(a);\n\
    \        }\n    }\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/dp/longest_increasing_sequence.hpp\"\nint brute_length(const\
    \ vector<int>& a) {\n    const int n = (int)a.size();\n    int res = 0;\n    for(int\
    \ bit = 0; bit < (1 << n); ++bit) {\n        vector<int> b;\n        for(int i\
    \ = 0; i < n; ++i) {\n            if((bit >> i) & 1) b.push_back(a[i]);\n    \
    \    }\n        bool ok = true;\n        for(int i = 1; i < (int)b.size(); ++i)\
    \ {\n            if(b[i - 1] >= b[i]) ok = false;\n        }\n        if(ok) res\
    \ = max(res, (int)b.size());\n    }\n    return res;\n}\nvoid check(const vector<int>&\
    \ a) {\n    const vector<int> lis = longest_increasing_sequence(a);\n    assert((int)lis.size()\
    \ == brute_length(a));\n    for(int i = 0; i < (int)lis.size(); ++i) {\n     \
    \   assert(0 <= lis[i] and lis[i] < (int)a.size());\n        if(i) {\n       \
    \     assert(lis[i - 1] < lis[i]);\n            assert(a[lis[i - 1]] < a[lis[i]]);\n\
    \        }\n    }\n}\nint main() {\n    check({});\n    check({3, 2, 1});\n  \
    \  check({1, 1, 1});\n    check({3, 1, 2, 1, 4});\n    for(int n = 0; n <= 10;\
    \ ++n) {\n        const int total = 1 << n;\n        for(int bit = 0; bit < total;\
    \ ++bit) {\n            vector<int> a(n);\n            for(int i = 0; i < n; ++i)\
    \ a[i] = ((bit >> i) & 1) ? 1 : 0;\n            check(a);\n        }\n    }\n\
    \    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/dp/longest_increasing_sequence.hpp
  isVerificationFile: true
  path: verify/unit_test/dp/longest_increasing_sequence.test.cpp
  requiredBy: []
  timestamp: '2026-07-05 23:31:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/dp/longest_increasing_sequence.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/dp/longest_increasing_sequence.test.cpp
- /verify/verify/unit_test/dp/longest_increasing_sequence.test.cpp.html
title: verify/unit_test/dp/longest_increasing_sequence.test.cpp
---
