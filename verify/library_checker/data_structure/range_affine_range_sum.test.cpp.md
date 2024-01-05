---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/lazy_segment_tree.hpp
    title: LazySegmentTree
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/library_checker/data_structure/range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    #line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
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
    #line 3 \"src/data_structure/lazy_segment_tree.hpp\"\ntemplate <typename S, auto\
    \ op, auto e, typename F, auto mapping, auto composition, auto id>\nstruct LazySegmentTree\
    \ {\n    LazySegmentTree(int N)\n        : LazySegmentTree(vector<S>(N, e()))\
    \ {}\n    LazySegmentTree(const vector<S>& v)\n        : n((int)v.size()) {\n\
    \        size = bit_ceil((unsigned int)n);\n        log = countr_zero((unsigned\
    \ int)size);\n        data = vector<S>(2 * size, e());\n        lazy = vector<F>(size,\
    \ id());\n        for(int i = 0; i < n; ++i) {\n            data[size + i] = v[i];\n\
    \        }\n        for(int i = size - 1; i >= 1; --i) {\n            update(i);\n\
    \        }\n    }\n    void set(int p, const S& x) {\n        assert(0 <= p and\
    \ p < n);\n        p += size;\n        for(int i = log; i >= 1; --i) {\n     \
    \       push(p >> i);\n        }\n        data[p] = x;\n        for(int i = 1;\
    \ i <= log; ++i) {\n            update(p >> i);\n        }\n    }\n    S get(int\
    \ p) {\n        assert(0 <= p and p < n);\n        p += size;\n        for(int\
    \ i = log; i >= 1; --i) {\n            push(p >> i);\n        }\n        return\
    \ data[p];\n    }\n    S prod(int l, int r) {\n        assert(0 <= l and l <=\
    \ r and r <= n);\n        if(l == r) return e();\n        l += size;\n       \
    \ r += size;\n        for(int i = log; i >= 1; --i) {\n            if(((l >> i)\
    \ << i) != l) push(l >> i);\n            if(((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n        }\n        S sml = e(), smr = e();\n        while(l < r) {\n\
    \            if(l & 1) sml = op(sml, data[l++]);\n            if(r & 1) smr =\
    \ op(data[--r], smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n    S all_prod() {\n        return data[1];\n\
    \    }\n    void apply(int l, int r, const F& f) {\n        assert(0 <= l and\
    \ l <= r and r <= n);\n        if(l == r) return;\n        l += size;\n      \
    \  r += size;\n        for(int i = log; i >= 1; --i) {\n            if(((l >>\
    \ i) << i) != l) push(l >> i);\n            if(((r >> i) << i) != r) push((r -\
    \ 1) >> i);\n        }\n        {\n            int l2 = l, r2 = r;\n         \
    \   while(l < r) {\n                if(l & 1) all_apply(l++, f);\n           \
    \     if(r & 1) all_apply(--r, f);\n                l >>= 1;\n               \
    \ r >>= 1;\n            }\n            l = l2;\n            r = r2;\n        }\n\
    \        for(int i = 1; i <= log; ++i) {\n            if(((l >> i) << i) != l)\
    \ update(l >> i);\n            if(((r >> i) << i) != r) update((r - 1) >> i);\n\
    \        }\n    }\n\n    template <bool (*g)(S)>\n    int max_right(int l) {\n\
    \        return max_right(l, [](const S& x) { return g(x); });\n    }\n    template\
    \ <class G>\n    int max_right(int l, const G& g) {\n        assert(0 <= l and\
    \ l <= n);\n        assert(g(e()));\n        if(l == n) return n;\n        l +=\
    \ size;\n        for(int i = log; i >= 1; --i) push(l >> i);\n        S sm = e();\n\
    \        do {\n            while(l % 2 == 0) l >>= 1;\n            if(!g(op(sm,\
    \ data[l]))) {\n                while(l < size) {\n                    push(l);\n\
    \                    l = 2 * l;\n                    if(g(op(sm, data[l]))) {\n\
    \                        sm = op(sm, data[l]);\n                        ++l;\n\
    \                    }\n                }\n                return l - size;\n\
    \            }\n            sm = op(sm, data[l]);\n            ++l;\n        }\
    \ while((l & -l) != l);\n        return n;\n    }\n\n    template <bool (*g)(S)>\n\
    \    int min_left(int r) {\n        return min_left(r, [](const S& x) { return\
    \ g(x); });\n    }\n    template <class G>\n    int min_left(int r, const G& g)\
    \ {\n        assert(0 <= r and r <= n);\n        assert(g(e()));\n        if(r\
    \ == 0) return 0;\n        r += size;\n        for(int i = log; i >= 1; --i) push((r\
    \ - 1) >> i);\n        S sm = e();\n        do {\n            --r;\n         \
    \   while(r > 1 and (r % 2)) r >>= 1;\n            if(!g(op(data[r], sm))) {\n\
    \                while(r < size) {\n                    push(r);\n           \
    \         r = 2 * r + 1;\n                    if(g(op(data[r], sm))) {\n     \
    \                   sm = op(data[r], sm);\n                        --r;\n    \
    \                }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = op(data[r], sm);\n        } while((r & -r) !=\
    \ r);\n        return 0;\n    }\n\n   private:\n    int n, size, log;\n    vector<S>\
    \ data;\n    vector<F> lazy;\n    inline void update(int k) {\n        data[k]\
    \ = op(data[2 * k], data[2 * k + 1]);\n    }\n    inline void all_apply(int k,\
    \ F f) {\n        data[k] = mapping(f, data[k]);\n        if(k < size) {\n   \
    \         lazy[k] = composition(f, lazy[k]);\n        }\n    }\n    inline void\
    \ push(int k) {\n        all_apply(2 * k, lazy[k]);\n        all_apply(2 * k +\
    \ 1, lazy[k]);\n        lazy[k] = id();\n    }\n    inline unsigned int bit_ceil(unsigned\
    \ int n) {\n        unsigned int res = 1;\n        while(res < n) res *= 2;\n\
    \        return res;\n    }\n    inline int countr_zero(unsigned int n) {\n  \
    \      return __builtin_ctz(n);\n    }\n};\n#line 5 \"verify/library_checker/data_structure/range_affine_range_sum.test.cpp\"\
    \nusing mint = modint998244353;\nstruct S {\n    mint a;\n    ll size;\n};\nstruct\
    \ F {\n    mint a, b;\n};\nS op(S l, S r) {\n    return S{l.a + r.a, l.size +\
    \ r.size};\n}\nS e() {\n    return S{0, 0};\n}\nS mapping(F l, S r) {\n    return\
    \ S{r.a * l.a + r.size * l.b, r.size};\n}\nF composition(F l, F r) {\n    return\
    \ F{r.a * l.a, r.b * l.a + l.b};\n}\nF id() {\n    return F{1, 0};\n}\nint main(void)\
    \ {\n    int n, q;\n    cin >> n >> q;\n    vector<S> a(n);\n    rep(i, 0, n)\
    \ {\n        int x;\n        cin >> x;\n        a[i] = S{x, 1};\n    }\n    LazySegmentTree<S,\
    \ op, e, F, mapping, composition, id> seg(a);\n    while(q--) {\n        int t;\n\
    \        cin >> t;\n        if(t == 0) {\n            int l, r, c, d;\n      \
    \      cin >> l >> r >> c >> d;\n            seg.apply(l, r, F{c, d});\n     \
    \   } else {\n            int l, r;\n            cin >> l >> r;\n            cout\
    \ << seg.prod(l, r).a << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/template/static_modint.hpp\"\
    \n#include \"../../../src/data_structure/lazy_segment_tree.hpp\"\nusing mint =\
    \ modint998244353;\nstruct S {\n    mint a;\n    ll size;\n};\nstruct F {\n  \
    \  mint a, b;\n};\nS op(S l, S r) {\n    return S{l.a + r.a, l.size + r.size};\n\
    }\nS e() {\n    return S{0, 0};\n}\nS mapping(F l, S r) {\n    return S{r.a *\
    \ l.a + r.size * l.b, r.size};\n}\nF composition(F l, F r) {\n    return F{r.a\
    \ * l.a, r.b * l.a + l.b};\n}\nF id() {\n    return F{1, 0};\n}\nint main(void)\
    \ {\n    int n, q;\n    cin >> n >> q;\n    vector<S> a(n);\n    rep(i, 0, n)\
    \ {\n        int x;\n        cin >> x;\n        a[i] = S{x, 1};\n    }\n    LazySegmentTree<S,\
    \ op, e, F, mapping, composition, id> seg(a);\n    while(q--) {\n        int t;\n\
    \        cin >> t;\n        if(t == 0) {\n            int l, r, c, d;\n      \
    \      cin >> l >> r >> c >> d;\n            seg.apply(l, r, F{c, d});\n     \
    \   } else {\n            int l, r;\n            cin >> l >> r;\n            cout\
    \ << seg.prod(l, r).a << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/static_modint.hpp
  - src/data_structure/lazy_segment_tree.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/range_affine_range_sum.test.cpp
- /verify/verify/library_checker/data_structure/range_affine_range_sum.test.cpp.html
title: verify/library_checker/data_structure/range_affine_range_sum.test.cpp
---
