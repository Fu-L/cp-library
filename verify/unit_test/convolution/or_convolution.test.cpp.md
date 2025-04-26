---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/or_convolution.hpp
    title: or_convolution
  - icon: ':heavy_check_mark:'
    path: src/math/zeta_transform.hpp
    title: zeta_transform
  - icon: ':heavy_check_mark:'
    path: src/random/permuted_congruential_generator.hpp
    title: PermutedCongruentialGenerator
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
  bundledCode: "#line 1 \"verify/unit_test/convolution/or_convolution.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ P = pair<long long, long long>;\n#define rep(i, a, b) for(long long i = (a);\
    \ i < (b); ++i)\n#define rrep(i, a, b) for(long long i = (a); i >= (b); --i)\n\
    constexpr long long inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/random/permuted_congruential_generator.hpp\"\nstruct PermutedCongruentialGenerator\
    \ {\n    template <typename T>\n        requires(is_integral_v<T> and sizeof(T)\
    \ == 4) or (is_floating_point_v<T> and sizeof(T) == 8)\n    inline T operator()(const\
    \ T l, const T r) {\n        assert(l <= r);\n        if constexpr(is_integral_v<T>)\
    \ {\n            const unsigned int range = static_cast<unsigned int>(r - l +\
    \ 1);\n            return l + (next32() % range);\n        } else {\n        \
    \    static constexpr unsigned long long denom = 1ull << 53;\n            const\
    \ unsigned long long x = next64() >> 11;\n            const double u = static_cast<double>(x)\
    \ / denom;\n            return l + (r - l) * u;\n        }\n    }\n\n   private:\n\
    \    static constexpr unsigned long long MULT = 6364136223846793005;\n    static\
    \ inline unsigned long long state = chrono::steady_clock::now().time_since_epoch().count();\n\
    \    inline unsigned int next32() {\n        unsigned long long x = state;\n \
    \       state *= MULT;\n        const unsigned int count = x >> 61;\n        x\
    \ ^= x >> 22;\n        return static_cast<unsigned int>(x >> (22 + count));\n\
    \    }\n    inline unsigned long long next64() {\n        return (static_cast<unsigned\
    \ long long>(next32()) << 32) | next32();\n    }\n} rng;\n#line 3 \"src/math/zeta_transform.hpp\"\
    \ntemplate <typename T>\nvoid superset_zeta_transform(vector<T>& f, const bool\
    \ inv = false) {\n    const int n = (int)f.size();\n    assert((n & (n - 1)) ==\
    \ 0);\n    const int sign = inv ? -1 : 1;\n    for(int i = 1; i < n; i <<= 1)\
    \ {\n        for(int j = 0; j < n; ++j) {\n            if((j & i) == 0) {\n  \
    \              f[j] += sign * f[j | i];\n            }\n        }\n    }\n}\n\
    template <typename T>\nvoid subset_zeta_transform(vector<T>& f, const bool inv\
    \ = false) {\n    const int n = (int)f.size();\n    assert((n & (n - 1)) == 0);\n\
    \    const int sign = inv ? -1 : 1;\n    for(int i = 1; i < n; i <<= 1) {\n  \
    \      for(int j = 0; j < n; ++j) {\n            if((j & i) == 0) {\n        \
    \        f[j | i] += sign * f[j];\n            }\n        }\n    }\n}\n#line 4\
    \ \"src/convolution/or_convolution.hpp\"\ntemplate <typename T>\nvector<T> or_convolution(vector<T>\
    \ a, vector<T> b) {\n    const int n = (int)a.size(), m = (int)b.size();\n   \
    \ assert(n == m and (n & (n - 1)) == 0);\n    subset_zeta_transform(a);\n    subset_zeta_transform(b);\n\
    \    for(int i = 0; i < (int)a.size(); ++i) a[i] *= b[i];\n    subset_zeta_transform(a,\
    \ true);\n    return a;\n}\n#line 5 \"verify/unit_test/convolution/or_convolution.test.cpp\"\
    \nvoid test() {\n    int n = 1 << rng(0, 12);\n    vector<ll> a(n), b(n);\n  \
    \  rep(i, 0, n) a[i] = rng(-1000000, 1000000);\n    rep(i, 0, n) b[i] = rng(-1000000,\
    \ 1000000);\n    vector<ll> c = or_convolution(a, b);\n    if(!n) {\n        assert(c.empty());\n\
    \        return;\n    }\n    vector<ll> expected(n);\n    rep(i, 0, n) {\n   \
    \     rep(j, 0, n) {\n            expected[i | j] += a[i] * b[j];\n        }\n\
    \    }\n    rep(i, 0, n) {\n        assert(c[i] == expected[i]);\n    }\n}\nint\
    \ main(void) {\n    constexpr int test_num = 100;\n    rep(_, 0, test_num) {\n\
    \        test();\n    }\n    int a, b;\n    cin >> a >> b;\n    cout << a + b\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/random/permuted_congruential_generator.hpp\"\n#include\
    \ \"../../../src/convolution/or_convolution.hpp\"\nvoid test() {\n    int n =\
    \ 1 << rng(0, 12);\n    vector<ll> a(n), b(n);\n    rep(i, 0, n) a[i] = rng(-1000000,\
    \ 1000000);\n    rep(i, 0, n) b[i] = rng(-1000000, 1000000);\n    vector<ll> c\
    \ = or_convolution(a, b);\n    if(!n) {\n        assert(c.empty());\n        return;\n\
    \    }\n    vector<ll> expected(n);\n    rep(i, 0, n) {\n        rep(j, 0, n)\
    \ {\n            expected[i | j] += a[i] * b[j];\n        }\n    }\n    rep(i,\
    \ 0, n) {\n        assert(c[i] == expected[i]);\n    }\n}\nint main(void) {\n\
    \    constexpr int test_num = 100;\n    rep(_, 0, test_num) {\n        test();\n\
    \    }\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/random/permuted_congruential_generator.hpp
  - src/convolution/or_convolution.hpp
  - src/math/zeta_transform.hpp
  isVerificationFile: true
  path: verify/unit_test/convolution/or_convolution.test.cpp
  requiredBy: []
  timestamp: '2025-04-27 00:17:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/convolution/or_convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/convolution/or_convolution.test.cpp
- /verify/verify/unit_test/convolution/or_convolution.test.cpp.html
title: verify/unit_test/convolution/or_convolution.test.cpp
---
