---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/miller_rabin.hpp
    title: miller_rabin
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
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"verify/library_checker/number_theory/primality_test.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n#line 2\
    \ \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing P = pair<long long, long long>;\n#define rep(i, a,\
    \ b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long long\
    \ i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO {\n\
    \    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n    \
    \    cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/miller_rabin.hpp\"\
    \nconstexpr __int128_t pow_mod_128(__int128_t x, __int128_t n, const __int128_t\
    \ mod) {\n    assert(n >= 0 and mod >= 1);\n    x %= mod;\n    if(x < 0) x +=\
    \ mod;\n    __int128_t res = 1;\n    while(n > 0) {\n        if(n & 1) res = res\
    \ * x % mod;\n        x = x * x % mod;\n        n >>= 1;\n    }\n    return res;\n\
    }\nconstexpr bool miller_rabin(const long long n) {\n    if(n <= 2) return n ==\
    \ 2;\n    if(n % 2 == 0) return false;\n    constexpr long long bases[7] = {2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022};\n    long long d = n - 1;\n\
    \    while(d % 2 == 0) d /= 2;\n    for(const long long base : bases) {\n    \
    \    if(base % n == 0) continue;\n        long long t = d;\n        long long\
    \ y = pow_mod_128(base, t, n);\n        while(t != n - 1 and y != 1 and y != n\
    \ - 1) {\n            y = (__int128_t)y * y % n;\n            t *= 2;\n      \
    \  }\n        if(y != n - 1 and t % 2 == 0) return false;\n    }\n    return true;\n\
    }\n#line 4 \"verify/library_checker/number_theory/primality_test.test.cpp\"\n\
    int main(void) {\n    int q;\n    cin >> q;\n    while(q--) {\n        ll n;\n\
    \        cin >> n;\n        if(miller_rabin(n)) {\n            cout << \"Yes\"\
    \ << '\\n';\n        } else {\n            cout << \"No\" << '\\n';\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/math/miller_rabin.hpp\"\
    \nint main(void) {\n    int q;\n    cin >> q;\n    while(q--) {\n        ll n;\n\
    \        cin >> n;\n        if(miller_rabin(n)) {\n            cout << \"Yes\"\
    \ << '\\n';\n        } else {\n            cout << \"No\" << '\\n';\n        }\n\
    \    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/miller_rabin.hpp
  isVerificationFile: true
  path: verify/library_checker/number_theory/primality_test.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 02:03:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/number_theory/primality_test.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/number_theory/primality_test.test.cpp
- /verify/verify/library_checker/number_theory/primality_test.test.cpp.html
title: verify/library_checker/number_theory/primality_test.test.cpp
---
