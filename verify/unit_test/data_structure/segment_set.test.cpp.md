---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/data_structure/segment_set.hpp
    title: SegmentSet
  - icon: ':question:'
    path: src/random/permuted_congruential_generator.hpp
    title: PermutedCongruentialGenerator
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
  bundledCode: "#line 1 \"verify/unit_test/data_structure/segment_set.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 4 \"src/template/template.hpp\"\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/random/permuted_congruential_generator.hpp\"\
    \nstruct PermutedCongruentialGenerator {\n    template <typename T>\n        requires(is_integral_v<T>\
    \ and sizeof(T) == 4) or (is_floating_point_v<T> and sizeof(T) == 8)\n    inline\
    \ T operator()(const T l, const T r) {\n        assert(l <= r);\n        if constexpr(is_integral_v<T>)\
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
    \ long long>(next32()) << 32) | next32();\n    }\n} rng;\n#line 3 \"src/data_structure/segment_set.hpp\"\
    \ntemplate <typename T>\nstruct SegmentSet {\n    SegmentSet() = default;\n  \
    \  using const_iterator = typename map<T, T>::const_iterator;\n    const_iterator\
    \ begin() const {\n        return st.begin();\n    }\n    const_iterator end()\
    \ const {\n        return st.end();\n    }\n    const_iterator find(const T& x)\
    \ const {\n        auto it = st.upper_bound(x);\n        if(it == st.begin() or\
    \ (--it)->second <= x) return st.end();\n        return it;\n    }\n    const_iterator\
    \ lower_bound(const T& x) const {\n        auto it = st.lower_bound(x);\n    \
    \    if(it == st.begin() or prev(it)->second <= x) return it;\n        return\
    \ prev(it);\n    }\n    void insert(T l, T r) {\n        auto L = st.upper_bound(l),\
    \ R = st.upper_bound(r);\n        if(L != st.begin() and l <= prev(L)->second)\
    \ --L;\n        if(L != R) {\n            l = min(l, L->first);\n            r\
    \ = max(r, prev(R)->second);\n            st.erase(L, R);\n        }\n       \
    \ st[l] = r;\n    }\n    void erase(const T& l, const T& r) {\n        auto L\
    \ = st.upper_bound(l), R = st.upper_bound(r);\n        if(L != st.begin() and\
    \ l <= prev(L)->second) --L;\n        if(L == R) return;\n        const T nl =\
    \ min(l, L->first), nr = max(r, prev(R)->second);\n        st.erase(L, R);\n \
    \       if(nl < l) st[nl] = l;\n        if(r < nr) st[r] = nr;\n    }\n    T next(const\
    \ T& x) const {\n        auto it = this->lower_bound(x);\n        if(it == this->end())\
    \ return numeric_limits<T>::max();\n        return max<T>(x, it->first);\n   \
    \ }\n    size_t size() const {\n        return st.size();\n    }\n\n   private:\n\
    \    map<T, T> st;\n};\n#line 5 \"verify/unit_test/data_structure/segment_set.test.cpp\"\
    \nvector<pair<int, int>> enumerate_segments(const vector<bool>& used) {\n    vector<pair<int,\
    \ int>> res;\n    const int n = used.size();\n    int i = 0;\n    while(i < n)\
    \ {\n        if(!used[i]) {\n            ++i;\n            continue;\n       \
    \ }\n        int j = i;\n        while(j < n and used[j]) ++j;\n        res.emplace_back(i,\
    \ j);\n        i = j;\n    }\n    return res;\n}\nvoid assert_same(const SegmentSet<int>&\
    \ st, const vector<bool>& used) {\n    const vector<pair<int, int>> expected =\
    \ enumerate_segments(used);\n    assert(st.size() == expected.size());\n    vector<pair<int,\
    \ int>> actual;\n    for(const auto& p : st) actual.push_back(p);\n    assert(actual\
    \ == expected);\n\n    const int n = used.size();\n    rep(x, 0, n) {\n      \
    \  const auto it = st.find(x);\n        if(used[x]) {\n            assert(it !=\
    \ st.end());\n            assert(it->first <= x and x < it->second);\n       \
    \ } else {\n            assert(it == st.end());\n        }\n\n        int expected_next\
    \ = numeric_limits<int>::max();\n        rep(y, x, n) {\n            if(used[y])\
    \ {\n                expected_next = y;\n                break;\n            }\n\
    \        }\n        assert(st.next(x) == expected_next);\n\n        const auto\
    \ lb = st.lower_bound(x);\n        pair<int, int> expected_lb{-1, -1};\n     \
    \   for(const auto& p : expected) {\n            if(p.second <= x) continue;\n\
    \            expected_lb = p;\n            break;\n        }\n        if(expected_lb.first\
    \ == -1) {\n            assert(lb == st.end());\n        } else {\n          \
    \  assert(lb != st.end());\n            assert(*lb == expected_lb);\n        }\n\
    \    }\n}\nvoid test_sample_like() {\n    SegmentSet<int> st;\n    vector<bool>\
    \ used(25);\n    auto insert = [&](int l, int r) {\n        st.insert(l, r);\n\
    \        rep(i, l, r) used[i] = true;\n        assert_same(st, used);\n    };\n\
    \    auto erase = [&](int l, int r) {\n        st.erase(l, r);\n        rep(i,\
    \ l, r) used[i] = false;\n        assert_same(st, used);\n    };\n    insert(3,\
    \ 7);\n    insert(10, 15);\n    insert(13, 20);\n    erase(5, 13);\n}\nvoid test_random()\
    \ {\n    constexpr int n = 80;\n    SegmentSet<int> st;\n    vector<bool> used(n);\n\
    \    const int query_num = 1000;\n    rep(_, 0, query_num) {\n        int l =\
    \ rng(0, n - 1);\n        int r = rng(l + 1, n);\n        if(rng(0, 1)) {\n  \
    \          st.insert(l, r);\n            rep(i, l, r) used[i] = true;\n      \
    \  } else {\n            st.erase(l, r);\n            rep(i, l, r) used[i] = false;\n\
    \        }\n        assert_same(st, used);\n    }\n}\nint main(void) {\n    test_sample_like();\n\
    \    constexpr int test_num = 100;\n    rep(_, 0, test_num) {\n        test_random();\n\
    \    }\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/random/permuted_congruential_generator.hpp\"\n#include\
    \ \"../../../src/data_structure/segment_set.hpp\"\nvector<pair<int, int>> enumerate_segments(const\
    \ vector<bool>& used) {\n    vector<pair<int, int>> res;\n    const int n = used.size();\n\
    \    int i = 0;\n    while(i < n) {\n        if(!used[i]) {\n            ++i;\n\
    \            continue;\n        }\n        int j = i;\n        while(j < n and\
    \ used[j]) ++j;\n        res.emplace_back(i, j);\n        i = j;\n    }\n    return\
    \ res;\n}\nvoid assert_same(const SegmentSet<int>& st, const vector<bool>& used)\
    \ {\n    const vector<pair<int, int>> expected = enumerate_segments(used);\n \
    \   assert(st.size() == expected.size());\n    vector<pair<int, int>> actual;\n\
    \    for(const auto& p : st) actual.push_back(p);\n    assert(actual == expected);\n\
    \n    const int n = used.size();\n    rep(x, 0, n) {\n        const auto it =\
    \ st.find(x);\n        if(used[x]) {\n            assert(it != st.end());\n  \
    \          assert(it->first <= x and x < it->second);\n        } else {\n    \
    \        assert(it == st.end());\n        }\n\n        int expected_next = numeric_limits<int>::max();\n\
    \        rep(y, x, n) {\n            if(used[y]) {\n                expected_next\
    \ = y;\n                break;\n            }\n        }\n        assert(st.next(x)\
    \ == expected_next);\n\n        const auto lb = st.lower_bound(x);\n        pair<int,\
    \ int> expected_lb{-1, -1};\n        for(const auto& p : expected) {\n       \
    \     if(p.second <= x) continue;\n            expected_lb = p;\n            break;\n\
    \        }\n        if(expected_lb.first == -1) {\n            assert(lb == st.end());\n\
    \        } else {\n            assert(lb != st.end());\n            assert(*lb\
    \ == expected_lb);\n        }\n    }\n}\nvoid test_sample_like() {\n    SegmentSet<int>\
    \ st;\n    vector<bool> used(25);\n    auto insert = [&](int l, int r) {\n   \
    \     st.insert(l, r);\n        rep(i, l, r) used[i] = true;\n        assert_same(st,\
    \ used);\n    };\n    auto erase = [&](int l, int r) {\n        st.erase(l, r);\n\
    \        rep(i, l, r) used[i] = false;\n        assert_same(st, used);\n    };\n\
    \    insert(3, 7);\n    insert(10, 15);\n    insert(13, 20);\n    erase(5, 13);\n\
    }\nvoid test_random() {\n    constexpr int n = 80;\n    SegmentSet<int> st;\n\
    \    vector<bool> used(n);\n    const int query_num = 1000;\n    rep(_, 0, query_num)\
    \ {\n        int l = rng(0, n - 1);\n        int r = rng(l + 1, n);\n        if(rng(0,\
    \ 1)) {\n            st.insert(l, r);\n            rep(i, l, r) used[i] = true;\n\
    \        } else {\n            st.erase(l, r);\n            rep(i, l, r) used[i]\
    \ = false;\n        }\n        assert_same(st, used);\n    }\n}\nint main(void)\
    \ {\n    test_sample_like();\n    constexpr int test_num = 100;\n    rep(_, 0,\
    \ test_num) {\n        test_random();\n    }\n    int a, b;\n    cin >> a >> b;\n\
    \    cout << a + b << '\\n';\n}\n"
  dependsOn:
  - src/template/template.hpp
  - src/random/permuted_congruential_generator.hpp
  - src/data_structure/segment_set.hpp
  isVerificationFile: true
  path: verify/unit_test/data_structure/segment_set.test.cpp
  requiredBy: []
  timestamp: '2026-07-04 02:23:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/unit_test/data_structure/segment_set.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/data_structure/segment_set.test.cpp
- /verify/verify/unit_test/data_structure/segment_set.test.cpp.html
title: verify/unit_test/data_structure/segment_set.test.cpp
---
