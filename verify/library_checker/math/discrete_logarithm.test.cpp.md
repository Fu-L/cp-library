---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/log_mod.hpp
    title: log_mod
  - icon: ':heavy_check_mark:'
    path: src/template/policy_based_data_structure.hpp
    title: policy_based_data_structure
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
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"verify/library_checker/math/discrete_logarithm.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\
    #line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 2 \"src/template/policy_based_data_structure.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n#include <ext/pb_ds/tag_and_trait.hpp>\n\
    using namespace __gnu_pbds;\n#line 4 \"src/math/log_mod.hpp\"\nlong long log_mod(long\
    \ long a, long long b, long long mod) {\n    assert(mod >= 1);\n    long long\
    \ g = 1;\n    for(long long i = mod; i; i /= 2) (g *= a) %= mod;\n    g = gcd(g,\
    \ mod);\n    long long t = 1, c = 0;\n    for(; t % g; ++c) {\n        if(t ==\
    \ b) return c;\n        (t *= a) %= mod;\n    }\n    if(b % g) return -1;\n  \
    \  t /= g;\n    b /= g;\n    long long n = mod / g, h = 0, gs = 1;\n    for(;\
    \ h * h < n; ++h) (gs *= a) %= n;\n    gp_hash_table<long long, long long> ht;\n\
    \    for(long long s = 0, e = b; s < h; ht[e] = ++s) {\n        (e *= a) %= n;\n\
    \    }\n    for(long long s = 0, e = t; s < n;) {\n        (e *= gs) %= n;\n \
    \       s += h;\n        if(ht.find(e) != ht.end()) return c + s - ht[e];\n  \
    \  }\n    return -1;\n}\n#line 4 \"verify/library_checker/math/discrete_logarithm.test.cpp\"\
    \nint main(void) {\n    int t;\n    cin >> t;\n    while(t--) {\n        ll x,\
    \ y, m;\n        cin >> x >> y >> m;\n        cout << log_mod(x, y, m) << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/math/log_mod.hpp\"\
    \nint main(void) {\n    int t;\n    cin >> t;\n    while(t--) {\n        ll x,\
    \ y, m;\n        cin >> x >> y >> m;\n        cout << log_mod(x, y, m) << '\\\
    n';\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/log_mod.hpp
  - src/template/policy_based_data_structure.hpp
  isVerificationFile: true
  path: verify/library_checker/math/discrete_logarithm.test.cpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/math/discrete_logarithm.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/math/discrete_logarithm.test.cpp
- /verify/verify/library_checker/math/discrete_logarithm.test.cpp.html
title: verify/library_checker/math/discrete_logarithm.test.cpp
---
