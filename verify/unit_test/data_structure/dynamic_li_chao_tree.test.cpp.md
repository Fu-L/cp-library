---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/dynamic_li_chao_tree.hpp
    title: DynamicLiChaoTree
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
  bundledCode: "#line 1 \"verify/unit_test/data_structure/dynamic_li_chao_tree.test.cpp\"\
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
    \ 32) | next32();\n    }\n} rng;\n#line 3 \"src/data_structure/dynamic_li_chao_tree.hpp\"\
    \ntemplate <typename T, T x_low, T x_high>\nstruct DynamicLiChaoTree {\n    DynamicLiChaoTree()\n\
    \        : root{nullptr} {}\n    void add_line(const T& a, const T& b) {\n   \
    \     Line x(a, b);\n        root = add_line(root, x, x_low, x_high, x.get(x_low),\
    \ x.get(x_high));\n    }\n    void add_segment(const T& l, const T& r, const T&\
    \ a, const T& b) {\n        assert(l <= r);\n        if(l == r) return;\n    \
    \    Line x(a, b);\n        root = add_segment(root, x, l, r - 1, x_low, x_high,\
    \ x.get(x_low), x.get(x_high));\n    }\n    T operator()(const T& x) const {\n\
    \        assert(x_low <= x and x <= x_high);\n        return query(root, x_low,\
    \ x_high, x);\n    }\n\n   private:\n    struct Line {\n        T a, b;\n    \
    \    Line(const T& a, const T& b)\n            : a(a), b(b) {}\n        inline\
    \ T get(const T& x) const {\n            return a * x + b;\n        }\n    };\n\
    \    struct Node {\n        Line x;\n        Node *l, *r;\n        Node(const\
    \ Line& x)\n            : x{x}, l{nullptr}, r{nullptr} {}\n    };\n    const T\
    \ id = numeric_limits<T>::max();\n    Node* root;\n    Node* add_line(Node* t,\
    \ Line& x, const T& l, const T& r, const T& x_l, const T& x_r) {\n        if(!t)\
    \ return new Node(x);\n        T t_l = t->x.get(l), t_r = t->x.get(r);\n     \
    \   if(t_l <= x_l and t_r <= x_r) {\n            return t;\n        } else if(t_l\
    \ >= x_l and t_r >= x_r) {\n            t->x = x;\n            return t;\n   \
    \     } else {\n            T m = (l + r) / 2;\n            if(m == r) --m;\n\
    \            T t_m = t->x.get(m), x_m = x.get(m);\n            if(t_m > x_m) {\n\
    \                swap(t->x, x);\n                if(x_l >= t_l) t->l = add_line(t->l,\
    \ x, l, m, t_l, t_m);\n                else t->r = add_line(t->r, x, m + 1, r,\
    \ t_m + x.a, t_r);\n            } else {\n                if(t_l >= x_l) t->l\
    \ = add_line(t->l, x, l, m, x_l, x_m);\n                else t->r = add_line(t->r,\
    \ x, m + 1, r, x_m + x.a, x_r);\n            }\n            return t;\n      \
    \  }\n    }\n    Node* add_segment(Node* t, Line& x, const T& a, const T& b, const\
    \ T& l, const T& r, const T& x_l, const T& x_r) {\n        if(r < a or b < l)\
    \ return t;\n        if(a <= l and r <= b) {\n            Line y{x};\n       \
    \     return add_line(t, y, l, r, x_l, x_r);\n        }\n        if(t) {\n   \
    \         T t_l = t->x.get(l), t_r = t->x.get(r);\n            if(t_l <= x_l and\
    \ t_r <= x_r) return t;\n        } else {\n            t = new Node(Line(0, id));\n\
    \        }\n        T m = (l + r) / 2;\n        if(m == r) --m;\n        T x_m\
    \ = x.get(m);\n        t->l = add_segment(t->l, x, a, b, l, m, x_l, x_m);\n  \
    \      t->r = add_segment(t->r, x, a, b, m + 1, r, x_m + x.a, x_r);\n        return\
    \ t;\n    }\n    T query(const Node* t, const T& l, const T& r, const T& x) const\
    \ {\n        if(!t) return id;\n        if(l == r) return t->x.get(x);\n     \
    \   T m = (l + r) / 2;\n        if(m == r) --m;\n        if(x <= m) return min(t->x.get(x),\
    \ query(t->l, l, m, x));\n        else return min(t->x.get(x), query(t->r, m +\
    \ 1, r, x));\n    }\n};\n#line 5 \"verify/unit_test/data_structure/dynamic_li_chao_tree.test.cpp\"\
    \nvoid test_empty_segment() {\n    DynamicLiChaoTree<ll, -10, 10> cht;\n    cht.add_segment(0,\
    \ 0, -100, -100);\n    rep(x, -10, 11) assert(cht(x) == numeric_limits<ll>::max());\n\
    }\nvoid test_random_segments() {\n    constexpr int low = -20, high = 20;\n  \
    \  DynamicLiChaoTree<ll, low, high> cht;\n    vector<tuple<ll, ll, ll, ll>> segments;\n\
    \    rep(_, 0, 200) {\n        int l = rng(low, high);\n        int r = rng(l,\
    \ high + 1);\n        int a = rng(-20, 20);\n        int b = rng(-100, 100);\n\
    \        cht.add_segment(l, r, a, b);\n        segments.emplace_back(l, r, a,\
    \ b);\n        rep(x, low, high + 1) {\n            ll expected = numeric_limits<ll>::max();\n\
    \            for(const auto& [sl, sr, sa, sb] : segments) {\n                if(sl\
    \ <= x and x < sr) expected = min(expected, sa * x + sb);\n            }\n   \
    \         assert(cht(x) == expected);\n        }\n    }\n}\nint main() {\n   \
    \ test_empty_segment();\n    rep(_, 0, 50) test_random_segments();\n    int a,\
    \ b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/random/permuted_congruential_generator.hpp\"\n#include\
    \ \"../../../src/data_structure/dynamic_li_chao_tree.hpp\"\nvoid test_empty_segment()\
    \ {\n    DynamicLiChaoTree<ll, -10, 10> cht;\n    cht.add_segment(0, 0, -100,\
    \ -100);\n    rep(x, -10, 11) assert(cht(x) == numeric_limits<ll>::max());\n}\n\
    void test_random_segments() {\n    constexpr int low = -20, high = 20;\n    DynamicLiChaoTree<ll,\
    \ low, high> cht;\n    vector<tuple<ll, ll, ll, ll>> segments;\n    rep(_, 0,\
    \ 200) {\n        int l = rng(low, high);\n        int r = rng(l, high + 1);\n\
    \        int a = rng(-20, 20);\n        int b = rng(-100, 100);\n        cht.add_segment(l,\
    \ r, a, b);\n        segments.emplace_back(l, r, a, b);\n        rep(x, low, high\
    \ + 1) {\n            ll expected = numeric_limits<ll>::max();\n            for(const\
    \ auto& [sl, sr, sa, sb] : segments) {\n                if(sl <= x and x < sr)\
    \ expected = min(expected, sa * x + sb);\n            }\n            assert(cht(x)\
    \ == expected);\n        }\n    }\n}\nint main() {\n    test_empty_segment();\n\
    \    rep(_, 0, 50) test_random_segments();\n    int a, b;\n    cin >> a >> b;\n\
    \    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/random/permuted_congruential_generator.hpp
  - src/data_structure/dynamic_li_chao_tree.hpp
  isVerificationFile: true
  path: verify/unit_test/data_structure/dynamic_li_chao_tree.test.cpp
  requiredBy: []
  timestamp: '2026-07-05 23:31:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/data_structure/dynamic_li_chao_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/data_structure/dynamic_li_chao_tree.test.cpp
- /verify/verify/unit_test/data_structure/dynamic_li_chao_tree.test.cpp.html
title: verify/unit_test/data_structure/dynamic_li_chao_tree.test.cpp
---
