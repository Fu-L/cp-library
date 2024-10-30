---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/slide_window_aggregation_deque.hpp
    title: SlideWindowAggregationDeque
  - icon: ':heavy_check_mark:'
    path: src/template/static_modint.hpp
    title: StaticModint
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
    PROBLEM: https://judge.yosupo.jp/problem/deque_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/deque_operate_all_composite
  bundledCode: "#line 1 \"verify/library_checker/data_structure/deque_operate_all_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/template/static_modint.hpp\"\ntemplate <uint32_t m>\nstruct StaticModint\
    \ {\n    using mint = StaticModint;\n    static constexpr uint32_t mod() {\n \
    \       return m;\n    }\n    static constexpr mint raw(uint32_t v) {\n      \
    \  mint a;\n        a._v = v;\n        return a;\n    }\n    constexpr StaticModint()\n\
    \        : _v(0) {}\n    template <class T>\n    constexpr StaticModint(const\
    \ T& v) {\n        static_assert(is_integral_v<T>);\n        if constexpr(is_signed_v<T>)\
    \ {\n            int64_t x = int64_t(v % int64_t(m));\n            if(x < 0) x\
    \ += m;\n            _v = uint32_t(x);\n        } else _v = uint32_t(v % m);\n\
    \    }\n    constexpr uint32_t val() const {\n        return _v;\n    }\n    constexpr\
    \ mint& operator++() {\n        return *this += 1;\n    }\n    constexpr mint&\
    \ operator--() {\n        return *this -= 1;\n    }\n    constexpr mint operator++(int)\
    \ {\n        mint res = *this;\n        ++*this;\n        return res;\n    }\n\
    \    constexpr mint operator--(int) {\n        mint res = *this;\n        --*this;\n\
    \        return res;\n    }\n    constexpr mint& operator+=(mint rhs) {\n    \
    \    if(_v >= m - rhs._v) _v -= m;\n        _v += rhs._v;\n        return *this;\n\
    \    }\n    constexpr mint& operator-=(mint rhs) {\n        if(_v < rhs._v) _v\
    \ += m;\n        _v -= rhs._v;\n        return *this;\n    }\n    constexpr mint&\
    \ operator*=(mint rhs) {\n        return *this = *this * rhs;\n    }\n    constexpr\
    \ mint& operator/=(mint rhs) {\n        return *this *= rhs.inv();\n    }\n  \
    \  constexpr mint operator+() const {\n        return *this;\n    }\n    constexpr\
    \ mint operator-() const {\n        return mint{} - *this;\n    }\n    constexpr\
    \ mint pow(long long n) const {\n        assert(0 <= n);\n        if(n == 0) return\
    \ 1;\n        mint x = *this, r = 1;\n        while(1) {\n            if(n & 1)\
    \ r *= x;\n            n >>= 1;\n            if(n == 0) return r;\n          \
    \  x *= x;\n        }\n    }\n    constexpr mint inv() const {\n        if constexpr(prime)\
    \ {\n            assert(_v);\n            return pow(m - 2);\n        } else {\n\
    \            auto eg = inv_gcd(_v, m);\n            assert(eg.first == 1);\n \
    \           return eg.second;\n        }\n    }\n    friend constexpr mint operator+(mint\
    \ lhs, mint rhs) {\n        return lhs += rhs;\n    }\n    friend constexpr mint\
    \ operator-(mint lhs, mint rhs) {\n        return lhs -= rhs;\n    }\n    friend\
    \ constexpr mint operator*(mint lhs, mint rhs) {\n        return uint64_t(lhs._v)\
    \ * rhs._v;\n    }\n    friend constexpr mint operator/(mint lhs, mint rhs) {\n\
    \        return lhs /= rhs;\n    }\n    friend constexpr bool operator==(mint\
    \ lhs, mint rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend constexpr\
    \ bool operator!=(mint lhs, mint rhs) {\n        return lhs._v != rhs._v;\n  \
    \  }\n    friend istream& operator>>(istream& in, mint& x) {\n        long long\
    \ a;\n        in >> a;\n        x = a;\n        return in;\n    }\n    friend\
    \ ostream& operator<<(ostream& out, const mint& x) {\n        return out << x.val();\n\
    \    }\n\n   private:\n    uint32_t _v = 0;\n    static constexpr bool prime =\
    \ []() -> bool {\n        if(m == 1) return 0;\n        if(m == 2 or m == 7 or\
    \ m == 61) return 1;\n        if(m % 2 == 0) return 0;\n        uint32_t d = m\
    \ - 1;\n        while(d % 2 == 0) d /= 2;\n        for(uint32_t a : {2, 7, 61})\
    \ {\n            uint32_t t = d;\n            mint y = mint(a).pow(t);\n     \
    \       while(t != m - 1 && y != 1 && y != m - 1) {\n                y *= y;\n\
    \                t <<= 1;\n            }\n            if(y != m - 1 && t % 2 ==\
    \ 0) return 0;\n        }\n        return 1;\n    }();\n    static constexpr pair<int32_t,\
    \ int32_t> inv_gcd(int32_t a, int32_t b) {\n        if(a == 0) return {b, 0};\n\
    \        int32_t s = b, t = a, m0 = 0, m1 = 1;\n        while(t) {\n         \
    \   const int32_t u = s / t;\n            s -= t * u;\n            m0 -= m1 *\
    \ u;\n            swap(s, t);\n            swap(m0, m1);\n        }\n        if(m0\
    \ < 0) m0 += b / s;\n        return {s, m0};\n    }\n};\nusing modint998244353\
    \ = StaticModint<998244353>;\nusing modint1000000007 = StaticModint<1000000007>;\n\
    #line 3 \"src/data_structure/slide_window_aggregation_deque.hpp\"\ntemplate <typename\
    \ S, auto op, auto e>\nstruct SlideWindowAggregationDeque {\n    void push_front(const\
    \ S& t) {\n        push0(t);\n    }\n    void push_back(const S& t) {\n      \
    \  push1(t);\n    }\n    S front() const {\n        return a0.empty() ? a1.front()\
    \ : a0.back();\n    }\n    S back() const {\n        return a1.empty() ? a0.front()\
    \ : a1.back();\n    }\n    void pop_front() {\n        if(a0.empty()) rebalance();\n\
    \        assert(!a0.empty());\n        a0.pop_back(), r0.pop_back();\n    }\n\
    \    void pop_back() {\n        if(a1.empty()) rebalance();\n        assert(!a1.empty());\n\
    \        a1.pop_back(), r1.pop_back();\n    }\n    S prod() {\n        return\
    \ op(get0(), get1());\n    }\n\n   private:\n    vector<S> a0, a1, r0, r1;\n \
    \   S get0() const {\n        return r0.empty() ? e() : r0.back();\n    }\n  \
    \  S get1() const {\n        return r1.empty() ? e() : r1.back();\n    }\n   \
    \ void push0(const S& x) {\n        a0.emplace_back(x);\n        r0.emplace_back(op(x,\
    \ get0()));\n    }\n    void push1(const S& x) {\n        a1.emplace_back(x);\n\
    \        r1.emplace_back(op(get1(), x));\n    }\n    void rebalance() {\n    \
    \    const int n = a0.size() + a1.size();\n        const int s0 = n / 2 + (a0.empty()\
    \ ? n % 2 : 0);\n        vector<S> a{a0};\n        reverse(begin(a), end(a));\n\
    \        copy(begin(a1), end(a1), back_inserter(a));\n        a0.clear(), r0.clear();\n\
    \        a1.clear(), r1.clear();\n        for(int i = s0 - 1; i >= 0; --i) push0(a[i]);\n\
    \        for(int i = s0; i < n; ++i) push1(a[i]);\n    }\n};\n#line 5 \"verify/library_checker/data_structure/deque_operate_all_composite.test.cpp\"\
    \nusing mint = modint998244353;\nstruct S {\n    mint a, b;\n};\nS op(S x, S y)\
    \ {\n    return {x.a * y.a, x.b * y.a + y.b};\n}\nS e() {\n    return {1, 0};\n\
    }\nint main(void) {\n    SlideWindowAggregationDeque<S, op, e> swag;\n    int\
    \ q;\n    cin >> q;\n    while(q--) {\n        int t;\n        cin >> t;\n   \
    \     if(t == 0) {\n            mint a, b;\n            cin >> a >> b;\n     \
    \       swag.push_front({a, b});\n        } else if(t == 1) {\n            mint\
    \ a, b;\n            cin >> a >> b;\n            swag.push_back({a, b});\n   \
    \     } else if(t == 2) {\n            swag.pop_front();\n        } else if(t\
    \ == 3) {\n            swag.pop_back();\n        } else {\n            mint x;\n\
    \            cin >> x;\n            S res = swag.prod();\n            cout <<\
    \ res.a * x + res.b << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/template/static_modint.hpp\"\
    \n#include \"../../../src/data_structure/slide_window_aggregation_deque.hpp\"\n\
    using mint = modint998244353;\nstruct S {\n    mint a, b;\n};\nS op(S x, S y)\
    \ {\n    return {x.a * y.a, x.b * y.a + y.b};\n}\nS e() {\n    return {1, 0};\n\
    }\nint main(void) {\n    SlideWindowAggregationDeque<S, op, e> swag;\n    int\
    \ q;\n    cin >> q;\n    while(q--) {\n        int t;\n        cin >> t;\n   \
    \     if(t == 0) {\n            mint a, b;\n            cin >> a >> b;\n     \
    \       swag.push_front({a, b});\n        } else if(t == 1) {\n            mint\
    \ a, b;\n            cin >> a >> b;\n            swag.push_back({a, b});\n   \
    \     } else if(t == 2) {\n            swag.pop_front();\n        } else if(t\
    \ == 3) {\n            swag.pop_back();\n        } else {\n            mint x;\n\
    \            cin >> x;\n            S res = swag.prod();\n            cout <<\
    \ res.a * x + res.b << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/static_modint.hpp
  - src/data_structure/slide_window_aggregation_deque.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2024-10-30 22:43:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
- /verify/verify/library_checker/data_structure/deque_operate_all_composite.test.cpp.html
title: verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
---
