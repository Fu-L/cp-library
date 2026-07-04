---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/random/permuted_congruential_generator.hpp
    title: PermutedCongruentialGenerator
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/random/random_regression.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 4 \"src/template/template.hpp\"\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/random/permuted_congruential_generator.hpp\"\
    \nstruct PermutedCongruentialGenerator {\n    template <typename T>\n        requires(is_integral_v<T>\
    \ and sizeof(T) == 4) or (is_floating_point_v<T> and sizeof(T) == 8)\n    inline\
    \ T operator()(const T l, const T r) {\n        assert(l <= r);\n        if constexpr(is_integral_v<T>)\
    \ {\n            const unsigned int x = next32();\n            if constexpr(is_signed_v<T>)\
    \ {\n                const uint64_t range = uint64_t(int64_t(r) - int64_t(l))\
    \ + 1;\n                const uint64_t offset = range == (uint64_t(1) << 32) ?\
    \ x : x % range;\n                return T(int64_t(l) + int64_t(offset));\n  \
    \          } else {\n                const uint64_t range = uint64_t(r) - uint64_t(l)\
    \ + 1;\n                const uint64_t offset = range == (uint64_t(1) << 32) ?\
    \ x : x % range;\n                return T(l + T(offset));\n            }\n  \
    \      } else {\n            static constexpr unsigned long long denom = 1ull\
    \ << 53;\n            const unsigned long long x = next64() >> 11;\n         \
    \   const double u = static_cast<double>(x) / denom;\n            return l + (r\
    \ - l) * u;\n        }\n    }\n\n   private:\n    static constexpr unsigned long\
    \ long MULT = 6364136223846793005;\n    static inline unsigned long long state\
    \ = chrono::steady_clock::now().time_since_epoch().count();\n    inline unsigned\
    \ int next32() {\n        unsigned long long x = state;\n        state *= MULT;\n\
    \        const unsigned int count = x >> 61;\n        x ^= x >> 22;\n        return\
    \ static_cast<unsigned int>(x >> (22 + count));\n    }\n    inline unsigned long\
    \ long next64() {\n        return (static_cast<unsigned long long>(next32()) <<\
    \ 32) | next32();\n    }\n} rng;\n#line 4 \"verify/unit_test/random/random_regression.test.cpp\"\
    \nint main() {\n    rep(_, 0, 1000) {\n        int x = rng(numeric_limits<int>::min(),\
    \ numeric_limits<int>::max());\n        (void)x;\n        unsigned int y = rng(0u,\
    \ numeric_limits<unsigned int>::max());\n        (void)y;\n        int z = rng(-10,\
    \ 10);\n        assert(-10 <= z and z <= 10);\n    }\n    int a, b;\n    cin >>\
    \ a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/random/permuted_congruential_generator.hpp\"\nint main()\
    \ {\n    rep(_, 0, 1000) {\n        int x = rng(numeric_limits<int>::min(), numeric_limits<int>::max());\n\
    \        (void)x;\n        unsigned int y = rng(0u, numeric_limits<unsigned int>::max());\n\
    \        (void)y;\n        int z = rng(-10, 10);\n        assert(-10 <= z and\
    \ z <= 10);\n    }\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\\
    n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/random/permuted_congruential_generator.hpp
  isVerificationFile: true
  path: verify/unit_test/random/random_regression.test.cpp
  requiredBy: []
  timestamp: '2026-07-04 16:35:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/random/random_regression.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/random/random_regression.test.cpp
- /verify/verify/unit_test/random/random_regression.test.cpp.html
title: verify/unit_test/random/random_regression.test.cpp
---
