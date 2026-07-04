---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/log_mod.hpp
    title: log_mod
  - icon: ':question:'
    path: src/template/policy_based_data_structure.hpp
    title: policy_based_data_structure
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/math/log_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 4 \"src/template/template.hpp\"\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 2 \"src/template/policy_based_data_structure.hpp\"\
    \n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    #include <ext/pb_ds/tag_and_trait.hpp>\nusing namespace __gnu_pbds;\n#line 4 \"\
    src/math/log_mod.hpp\"\nlong long log_mod(const long long a, long long b, const\
    \ long long mod) {\n    assert(mod >= 1);\n    long long g = 1;\n    for(long\
    \ long i = mod; i; i /= 2) (g *= a) %= mod;\n    g = gcd(g, mod);\n    long long\
    \ t = 1, c = 0;\n    for(; t % g; ++c) {\n        if(t == b) return c;\n     \
    \   (t *= a) %= mod;\n    }\n    if(b % g) return -1;\n    t /= g;\n    b /= g;\n\
    \    const long long n = mod / g;\n    long long h = 0, gs = 1;\n    for(; h *\
    \ h < n; ++h) (gs *= a) %= n;\n    gp_hash_table<long long, long long> ht;\n \
    \   for(long long s = 0, e = b; s < h; ht[e] = ++s) {\n        (e *= a) %= n;\n\
    \    }\n    for(long long s = 0, e = t; s < n;) {\n        (e *= gs) %= n;\n \
    \       s += h;\n        if(ht.find(e) != ht.end()) return c + s - ht[e];\n  \
    \  }\n    return -1;\n}\n#line 4 \"verify/unit_test/math/log_mod.test.cpp\"\n\
    ll brute(ll a, ll b, ll mod) {\n    a %= mod;\n    b %= mod;\n    if(a < 0) a\
    \ += mod;\n    if(b < 0) b += mod;\n    ll cur = 1 % mod;\n    rep(k, 0, 100)\
    \ {\n        if(cur == b) return k;\n        cur = cur * a % mod;\n    }\n   \
    \ return -1;\n}\nint main() {\n    rep(mod, 1, 50) {\n        rep(a, -50, 50)\
    \ {\n            rep(b, -50, 50) {\n                assert(log_mod(a, b, mod)\
    \ == brute(a, b, mod));\n            }\n        }\n    }\n    int a, b;\n    cin\
    \ >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/math/log_mod.hpp\"\nll brute(ll a, ll b, ll mod) {\n\
    \    a %= mod;\n    b %= mod;\n    if(a < 0) a += mod;\n    if(b < 0) b += mod;\n\
    \    ll cur = 1 % mod;\n    rep(k, 0, 100) {\n        if(cur == b) return k;\n\
    \        cur = cur * a % mod;\n    }\n    return -1;\n}\nint main() {\n    rep(mod,\
    \ 1, 50) {\n        rep(a, -50, 50) {\n            rep(b, -50, 50) {\n       \
    \         assert(log_mod(a, b, mod) == brute(a, b, mod));\n            }\n   \
    \     }\n    }\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n\
    }"
  dependsOn:
  - src/template/template.hpp
  - src/math/log_mod.hpp
  - src/template/policy_based_data_structure.hpp
  isVerificationFile: true
  path: verify/unit_test/math/log_mod.test.cpp
  requiredBy: []
  timestamp: '2026-07-04 16:35:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/unit_test/math/log_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/log_mod.test.cpp
- /verify/verify/unit_test/math/log_mod.test.cpp.html
title: verify/unit_test/math/log_mod.test.cpp
---
