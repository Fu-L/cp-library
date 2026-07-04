---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/convex_hull_trick.hpp
    title: ConvexHullTrick
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
  bundledCode: "#line 1 \"verify/unit_test/data_structure/convex_hull_trick.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
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
    \ 32) | next32();\n    }\n} rng;\n#line 3 \"src/data_structure/convex_hull_trick.hpp\"\
    \ntemplate <typename T>\nstruct ConvexHullTrick {\n    void add(const T& a, const\
    \ T& b) {\n        Linear l(a, b);\n        assert(ls.empty() or ls.back().a >=\
    \ l.a);\n        if(!ls.empty() and ls.back().a == l.a) {\n            if(ls.back().b\
    \ <= l.b) return;\n            ls.pop_back();\n        }\n        int len = (int)ls.size();\n\
    \        while(len >= 2 and check(ls[len - 2], ls[len - 1], l)) {\n          \
    \  --len;\n            ls.pop_back();\n        }\n        ls.emplace_back(l);\n\
    \    }\n    T operator()(const T& x) {\n        assert(x >= x_last);\n       \
    \ while((int)ls.size() >= 2 and ls[0](x) >= ls[1](x)) {\n            ls.pop_front();\n\
    \        }\n        x_last = x;\n        return ls[0](x);\n    }\n\n   private:\n\
    \    struct Linear {\n        T a, b;\n        Linear(const T& a = 0, const T&\
    \ b = 0)\n            : a(a), b(b) {}\n        inline T operator()(const T& x)\
    \ const {\n            return a * x + b;\n        }\n    };\n    inline bool check(const\
    \ Linear& f1, const Linear& f2, const Linear& f3) const {\n        return (f2.a\
    \ - f1.a) * (f3.b - f2.b) >= (f2.b - f1.b) * (f3.a - f2.a);\n    }\n    deque<Linear>\
    \ ls;\n    T x_last = numeric_limits<T>::min();\n};\n#line 5 \"verify/unit_test/data_structure/convex_hull_trick.test.cpp\"\
    \nvoid test_random() {\n    const int n = rng(1, 200);\n    vector<pair<ll, ll>>\
    \ lines;\n    ConvexHullTrick<ll> cht;\n    ll a = rng(-1000, 1000);\n    rep(i,\
    \ 0, n) {\n        a -= rng(0, 5);\n        const ll b = rng(-1000000, 1000000);\n\
    \        lines.emplace_back(a, b);\n        cht.add(a, b);\n    }\n    ll x =\
    \ rng(-1000, 1000);\n    const int query_num = 200;\n    rep(_, 0, query_num)\
    \ {\n        x += rng(0, 10);\n        ll expected = inf;\n        for(const auto&\
    \ [a, b] : lines) {\n            expected = min(expected, a * x + b);\n      \
    \  }\n        assert(cht(x) == expected);\n    }\n}\nvoid test_sample_like() {\n\
    \    ConvexHullTrick<ll> cht;\n    vector<pair<ll, ll>> lines{{5, 3}, {2, 10},\
    \ {-1, 20}, {-4, 100}};\n    for(const auto& [a, b] : lines) cht.add(a, b);\n\
    \    rep(x, -10, 31) {\n        ll expected = inf;\n        for(const auto& [a,\
    \ b] : lines) {\n            expected = min(expected, a * x + b);\n        }\n\
    \        assert(cht(x) == expected);\n    }\n}\nint main(void) {\n    test_sample_like();\n\
    \    constexpr int test_num = 100;\n    rep(_, 0, test_num) {\n        test_random();\n\
    \    }\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/random/permuted_congruential_generator.hpp\"\n#include\
    \ \"../../../src/data_structure/convex_hull_trick.hpp\"\nvoid test_random() {\n\
    \    const int n = rng(1, 200);\n    vector<pair<ll, ll>> lines;\n    ConvexHullTrick<ll>\
    \ cht;\n    ll a = rng(-1000, 1000);\n    rep(i, 0, n) {\n        a -= rng(0,\
    \ 5);\n        const ll b = rng(-1000000, 1000000);\n        lines.emplace_back(a,\
    \ b);\n        cht.add(a, b);\n    }\n    ll x = rng(-1000, 1000);\n    const\
    \ int query_num = 200;\n    rep(_, 0, query_num) {\n        x += rng(0, 10);\n\
    \        ll expected = inf;\n        for(const auto& [a, b] : lines) {\n     \
    \       expected = min(expected, a * x + b);\n        }\n        assert(cht(x)\
    \ == expected);\n    }\n}\nvoid test_sample_like() {\n    ConvexHullTrick<ll>\
    \ cht;\n    vector<pair<ll, ll>> lines{{5, 3}, {2, 10}, {-1, 20}, {-4, 100}};\n\
    \    for(const auto& [a, b] : lines) cht.add(a, b);\n    rep(x, -10, 31) {\n \
    \       ll expected = inf;\n        for(const auto& [a, b] : lines) {\n      \
    \      expected = min(expected, a * x + b);\n        }\n        assert(cht(x)\
    \ == expected);\n    }\n}\nint main(void) {\n    test_sample_like();\n    constexpr\
    \ int test_num = 100;\n    rep(_, 0, test_num) {\n        test_random();\n   \
    \ }\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/random/permuted_congruential_generator.hpp
  - src/data_structure/convex_hull_trick.hpp
  isVerificationFile: true
  path: verify/unit_test/data_structure/convex_hull_trick.test.cpp
  requiredBy: []
  timestamp: '2026-07-04 16:35:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/data_structure/convex_hull_trick.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/data_structure/convex_hull_trick.test.cpp
- /verify/verify/unit_test/data_structure/convex_hull_trick.test.cpp.html
title: verify/unit_test/data_structure/convex_hull_trick.test.cpp
---
