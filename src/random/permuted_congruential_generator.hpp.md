---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/convolution/convolution_ll.test.cpp
    title: verify/unit_test/convolution/convolution_ll.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/convolution/or_convolution.test.cpp
    title: verify/unit_test/convolution/or_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/data_structure/convex_hull_trick.test.cpp
    title: verify/unit_test/data_structure/convex_hull_trick.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/data_structure/segment_set.test.cpp
    title: verify/unit_test/data_structure/segment_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/random/random_regression.test.cpp
    title: verify/unit_test/random/random_regression.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    #line 4 \"src/template/template.hpp\"\nusing namespace std;\nusing ll = long long;\n\
    using P = pair<long long, long long>;\n#define rep(i, a, b) for(long long i =\
    \ (a); i < (b); ++i)\n#define rrep(i, a, b) for(long long i = (a); i >= (b); --i)\n\
    constexpr long long inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/random/permuted_congruential_generator.hpp\"\nstruct PermutedCongruentialGenerator\
    \ {\n    template <typename T>\n        requires(is_integral_v<T> and sizeof(T)\
    \ == 4) or (is_floating_point_v<T> and sizeof(T) == 8)\n    inline T operator()(const\
    \ T l, const T r) {\n        assert(l <= r);\n        if constexpr(is_integral_v<T>)\
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
    \ 32) | next32();\n    }\n} rng;\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nstruct PermutedCongruentialGenerator\
    \ {\n    template <typename T>\n        requires(is_integral_v<T> and sizeof(T)\
    \ == 4) or (is_floating_point_v<T> and sizeof(T) == 8)\n    inline T operator()(const\
    \ T l, const T r) {\n        assert(l <= r);\n        if constexpr(is_integral_v<T>)\
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
    \ 32) | next32();\n    }\n} rng;"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/random/permuted_congruential_generator.hpp
  requiredBy: []
  timestamp: '2026-07-04 16:35:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/convolution/convolution_ll.test.cpp
  - verify/unit_test/convolution/or_convolution.test.cpp
  - verify/unit_test/data_structure/convex_hull_trick.test.cpp
  - verify/unit_test/data_structure/segment_set.test.cpp
  - verify/unit_test/random/random_regression.test.cpp
documentation_of: src/random/permuted_congruential_generator.hpp
layout: document
title: PermutedCongruentialGenerator
---

# PermutedCongruentialGenerator

- 一様ランダムな整数・実数

を生成します．

メルセンヌツイスタを用いた `RandomNumberGenerator` よりやや質が悪いですが，かなり高速です．
アルゴリズムコンテストでは `RandomNumberGenerator` を使い，ヒューリスティックコンテストでは `PermutedCongruentialGenerator` を使うことを推奨します．

# コンストラクタ

```cpp
PermutedCongruentialGenerator rng()
```

- 乱数生成器 `rng` を作成します．シードには実行時の時刻を用いています．

**計算量**

- $O(1)$

# operator ()

```cpp
T rng(T l, T r)
```

$[l, r]$ の範囲の整数・実数を一様ランダムに返します．

**制約**

- $l \leq r$
- `T` は `int` か `unsigned int` か `double`

**計算量**

- $O(1)$