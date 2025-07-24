---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/min_plus_convolution.hpp
    title: min_plus_convolution
  - icon: ':heavy_check_mark:'
    path: src/dp/monotone_minima.hpp
    title: monotone_minima
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
    PROBLEM: https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
    links:
    - https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
  bundledCode: "#line 1 \"verify/library_checker/convolution/min_plus_convolution(convex_and_arbitrary).test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/dp/monotone_minima.hpp\"\
    \ntemplate <class F>\nvector<int> monotone_minima(const int n, const int m, const\
    \ F& f) {\n    vector<int> res(n);\n    auto dfs = [&](const auto& dfs, const\
    \ int is, const int ie, const int l, const int r) -> void {\n        if(is ==\
    \ ie) return;\n        const int i = (is + ie) / 2;\n        int m = l;\n    \
    \    for(int k = l + 1; k < r; ++k) {\n            if(!f(i, m, k)) m = k;\n  \
    \      }\n        res[i] = m;\n        dfs(dfs, is, i, l, m + 1);\n        dfs(dfs,\
    \ i + 1, ie, m, r);\n    };\n    dfs(dfs, 0, n, 0, m);\n    return res;\n}\n#line\
    \ 4 \"src/convolution/min_plus_convolution.hpp\"\ntemplate <typename T>\nvector<T>\
    \ min_plus_convolution(const vector<T>& a, const vector<T>& b) {\n    if(a.empty()\
    \ or b.empty()) return {};\n    const int n = a.size(), m = b.size();\n    auto\
    \ f = [&](const int i, const int j, const int k) -> bool {\n        if(i < k)\
    \ return true;\n        if(i - j >= n) return false;\n        return a[i - j]\
    \ + b[j] < a[i - k] + b[k];\n    };\n    const auto argmin = monotone_minima(n\
    \ + m - 1, m, f);\n    vector<int> res(n + m - 1);\n    for(int i = 0; i < n +\
    \ m - 1; ++i) {\n        const int j = argmin[i];\n        res[i] = a[i - j] +\
    \ b[j];\n    }\n    return res;\n}\ntemplate <typename T>\nvector<T> max_plus_convolution(const\
    \ vector<T>& a, const vector<T>& b) {\n    if(a.empty() or b.empty()) return {};\n\
    \    const int n = a.size(), m = b.size();\n    auto f = [&](const int i, const\
    \ int j, const int k) -> bool {\n        if(i < k) return true;\n        if(i\
    \ - j >= n) return false;\n        return a[i - j] + b[j] > a[i - k] + b[k];\n\
    \    };\n    const auto argmax = monotone_minima(n + m - 1, m, f);\n    vector<int>\
    \ res(n + m - 1);\n    for(int i = 0; i < n + m - 1; ++i) {\n        const int\
    \ j = argmax[i];\n        res[i] = a[i - j] + b[j];\n    }\n    return res;\n\
    }\n#line 4 \"verify/library_checker/convolution/min_plus_convolution(convex_and_arbitrary).test.cpp\"\
    \nint main(void) {\n    int n, m;\n    cin >> n >> m;\n    vector<int> a(n), b(m);\n\
    \    rep(i, 0, n) cin >> a[i];\n    rep(i, 0, m) cin >> b[i];\n    vector<int>\
    \ c = min_plus_convolution(a, b);\n    rep(i, 0, n + m - 1) {\n        cout <<\
    \ c[i] << \" \\n\"[i + 1 == n + m - 1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/convolution/min_plus_convolution.hpp\"\
    \nint main(void) {\n    int n, m;\n    cin >> n >> m;\n    vector<int> a(n), b(m);\n\
    \    rep(i, 0, n) cin >> a[i];\n    rep(i, 0, m) cin >> b[i];\n    vector<int>\
    \ c = min_plus_convolution(a, b);\n    rep(i, 0, n + m - 1) {\n        cout <<\
    \ c[i] << \" \\n\"[i + 1 == n + m - 1];\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/convolution/min_plus_convolution.hpp
  - src/dp/monotone_minima.hpp
  isVerificationFile: true
  path: verify/library_checker/convolution/min_plus_convolution(convex_and_arbitrary).test.cpp
  requiredBy: []
  timestamp: '2025-07-24 13:14:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/convolution/min_plus_convolution(convex_and_arbitrary).test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/convolution/min_plus_convolution(convex_and_arbitrary).test.cpp
- /verify/verify/library_checker/convolution/min_plus_convolution(convex_and_arbitrary).test.cpp.html
title: verify/library_checker/convolution/min_plus_convolution(convex_and_arbitrary).test.cpp
---
