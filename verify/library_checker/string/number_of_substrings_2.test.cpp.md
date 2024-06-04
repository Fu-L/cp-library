---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/string/suffix_array.hpp
    title: suffix_array
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"verify/library_checker/string/number_of_substrings_2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n#line\
    \ 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i\
    \ = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/string/suffix_array.hpp\"\nvector<int> suffix_array(const vector<int>&\
    \ s) {\n    const int n = (int)s.size();\n    vector<int> sa(n), rank(n), tmp(n);\n\
    \    for(int i = 0; i < n; ++i) rank[i] = s[i];\n    iota(sa.begin(), sa.end(),\
    \ 0);\n    for(int k = 1; k < n; k *= 2) {\n        auto cmp = [&](int x, int\
    \ y) -> bool {\n            if(rank[x] != rank[y]) return rank[x] < rank[y];\n\
    \            const int rx = x + k < n ? rank[x + k] : -1;\n            const int\
    \ ry = y + k < n ? rank[y + k] : -1;\n            return rx < ry;\n        };\n\
    \        sort(sa.begin(), sa.end(), cmp);\n        tmp[sa[0]] = 0;\n        for(int\
    \ i = 1; i < n; ++i) {\n            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i -\
    \ 1], sa[i]) ? 1 : 0);\n        }\n        swap(tmp, rank);\n    }\n    return\
    \ sa;\n}\nvector<int> suffix_array(const string& s) {\n    const int n = (int)s.size();\n\
    \    vector<int> s2(n);\n    for(int i = 0; i < n; ++i) {\n        s2[i] = s[i];\n\
    \    }\n    return suffix_array(s2);\n}\nvector<int> lcp_array(const vector<int>&\
    \ s, const vector<int>& sa) {\n    const int n = (int)s.size();\n    assert(n\
    \ >= 1);\n    vector<int> rank(n);\n    for(int i = 0; i < n; ++i) {\n       \
    \ rank[sa[i]] = i;\n    }\n    vector<int> lcp(n - 1);\n    int h = 0;\n    for(int\
    \ i = 0; i < n; ++i) {\n        if(h > 0) --h;\n        if(rank[i] == 0) continue;\n\
    \        const int j = sa[rank[i] - 1];\n        for(; j + h < n and i + h < n;\
    \ ++h) {\n            if(s[j + h] != s[i + h]) break;\n        }\n        lcp[rank[i]\
    \ - 1] = h;\n    }\n    return lcp;\n}\nvector<int> lcp_array(const string& s,\
    \ const vector<int>& sa) {\n    const int n = (int)s.size();\n    vector<int>\
    \ s2(n);\n    for(int i = 0; i < n; ++i) {\n        s2[i] = s[i];\n    }\n   \
    \ return lcp_array(s2, sa);\n}\n#line 4 \"verify/library_checker/string/number_of_substrings_2.test.cpp\"\
    \nint main(void) {\n    string s;\n    cin >> s;\n    vector<int> sa = suffix_array(s);\n\
    \    vector<int> lcp = lcp_array(s, sa);\n    ll sum = 0;\n    rep(i, 0, (int)lcp.size())\
    \ {\n        sum += (i + 1) - lcp[i];\n    }\n    cout << sum + (int)s.size()\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    #include \"../../../src/template/template.hpp\"\n#include \"../../../src/string/suffix_array.hpp\"\
    \nint main(void) {\n    string s;\n    cin >> s;\n    vector<int> sa = suffix_array(s);\n\
    \    vector<int> lcp = lcp_array(s, sa);\n    ll sum = 0;\n    rep(i, 0, (int)lcp.size())\
    \ {\n        sum += (i + 1) - lcp[i];\n    }\n    cout << sum + (int)s.size()\
    \ << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/string/suffix_array.hpp
  isVerificationFile: true
  path: verify/library_checker/string/number_of_substrings_2.test.cpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/string/number_of_substrings_2.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/number_of_substrings_2.test.cpp
- /verify/verify/library_checker/string/number_of_substrings_2.test.cpp.html
title: verify/library_checker/string/number_of_substrings_2.test.cpp
---
