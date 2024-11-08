---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/template/debug.hpp
    title: debug
  - icon: ':question:'
    path: src/template/dynamic_modint.hpp
    title: DynamicModint
  - icon: ':question:'
    path: src/template/static_modint.hpp
    title: StaticModint
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
  bundledCode: "#line 1 \"verify/unit_test/template/debug.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ P = pair<long long, long long>;\n#define rep(i, a, b) for(long long i = (a);\
    \ i < (b); ++i)\n#define rrep(i, a, b) for(long long i = (a); i >= (b); --i)\n\
    constexpr long long inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/template/static_modint.hpp\"\ntemplate <uint32_t m>\nstruct StaticModint\
    \ {\n    using mint = StaticModint;\n    static constexpr uint32_t mod() {\n \
    \       return m;\n    }\n    static constexpr mint raw(const uint32_t v) {\n\
    \        mint a;\n        a._v = v;\n        return a;\n    }\n    constexpr StaticModint()\n\
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
    \            const auto eg = inv_gcd(_v, m);\n            assert(eg.first == 1);\n\
    \            return eg.second;\n        }\n    }\n    friend constexpr mint operator+(mint\
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
    \ int32_t> inv_gcd(const int32_t a, const int32_t b) {\n        if(a == 0) return\
    \ {b, 0};\n        int32_t s = b, t = a, m0 = 0, m1 = 1;\n        while(t) {\n\
    \            const int32_t u = s / t;\n            s -= t * u;\n            m0\
    \ -= m1 * u;\n            swap(s, t);\n            swap(m0, m1);\n        }\n\
    \        if(m0 < 0) m0 += b / s;\n        return {s, m0};\n    }\n};\nusing modint998244353\
    \ = StaticModint<998244353>;\nusing modint1000000007 = StaticModint<1000000007>;\n\
    #line 3 \"src/template/dynamic_modint.hpp\"\nstruct Barrett {\n    explicit Barrett(const\
    \ unsigned int m)\n        : _m(m), im((unsigned long long)(-1) / m + 1) {}\n\
    \    inline unsigned int umod() const {\n        return _m;\n    }\n    inline\
    \ unsigned int mul(const unsigned int a, const unsigned int b) const {\n     \
    \   unsigned long long z = a;\n        z *= b;\n        const unsigned long long\
    \ x = (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n        unsigned\
    \ int v = (unsigned int)(z - x * _m);\n        if(_m <= v) v += _m;\n        return\
    \ v;\n    }\n\n   private:\n    unsigned int _m;\n    unsigned long long im;\n\
    };\ntemplate <int id>\nstruct DynamicModint {\n    using mint = DynamicModint;\n\
    \    static int mod() {\n        return (int)bt.umod();\n    }\n    static void\
    \ set_mod(const int m) {\n        assert(1 <= m);\n        bt = Barrett(m);\n\
    \    }\n    static mint raw(const int v) {\n        mint a;\n        a._v = v;\n\
    \        return a;\n    }\n    DynamicModint()\n        : _v(0) {}\n    template\
    \ <class T>\n    DynamicModint(const T& v) {\n        static_assert(is_integral_v<T>);\n\
    \        if(is_signed_v<T>) {\n            long long x = (long long)(v % (long\
    \ long)(umod()));\n            if(x < 0) x += umod();\n            _v = (unsigned\
    \ int)(x);\n        } else _v = (unsigned int)(v % umod());\n    }\n    unsigned\
    \ int val() const {\n        return _v;\n    }\n    mint& operator++() {\n   \
    \     ++_v;\n        if(_v == umod()) _v = 0;\n        return *this;\n    }\n\
    \    mint& operator--() {\n        if(_v == 0) _v = umod();\n        --_v;\n \
    \       return *this;\n    }\n    mint operator++(int) {\n        mint res = *this;\n\
    \        ++*this;\n        return res;\n    }\n    mint operator--(int) {\n  \
    \      mint res = *this;\n        --*this;\n        return res;\n    }\n    mint&\
    \ operator+=(const mint& rhs) {\n        _v += rhs._v;\n        if(_v >= umod())\
    \ _v -= umod();\n        return *this;\n    }\n    mint& operator-=(const mint&\
    \ rhs) {\n        _v += mod() - rhs._v;\n        if(_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator*=(const mint& rhs) {\n     \
    \   _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n    mint& operator/=(const\
    \ mint& rhs) {\n        return *this *= rhs.inv();\n    }\n    mint operator+()\
    \ const {\n        return *this;\n    }\n    mint operator-() const {\n      \
    \  return mint() - *this;\n    }\n    mint pow(long long n) const {\n        assert(0\
    \ <= n);\n        if(n == 0) return 1;\n        mint x = *this, r = 1;\n     \
    \   while(1) {\n            if(n & 1) r *= x;\n            n >>= 1;\n        \
    \    if(n == 0) return r;\n            x *= x;\n        }\n    }\n    mint inv()\
    \ const {\n        const auto eg = inv_gcd(_v, mod());\n        assert(eg.first\
    \ == 1);\n        return eg.second;\n    }\n    friend mint operator+(const mint&\
    \ lhs, const mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend\
    \ mint operator-(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ -= rhs;\n    }\n    friend mint operator*(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) *= rhs;\n    }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) /= rhs;\n    }\n   \
    \ friend bool operator==(const mint& lhs, const mint& rhs) {\n        return lhs._v\
    \ == rhs._v;\n    }\n    friend bool operator!=(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v != rhs._v;\n    }\n    friend istream& operator>>(istream&\
    \ in, mint& x) {\n        long long a;\n        in >> a;\n        x = a;\n   \
    \     return in;\n    }\n    friend ostream& operator<<(ostream& out, const mint&\
    \ x) {\n        return out << x.val();\n    }\n\n   private:\n    unsigned int\
    \ _v = 0;\n    static Barrett bt;\n    inline static unsigned int umod() {\n \
    \       return bt.umod();\n    }\n    inline static pair<long long, long long>\
    \ inv_gcd(const long long a, const long long b) {\n        if(a == 0) return {b,\
    \ 0};\n        long long s = b, t = a, m0 = 0, m1 = 1;\n        while(t) {\n \
    \           const long long u = s / t;\n            s -= t * u;\n            m0\
    \ -= m1 * u;\n            swap(s, t);\n            swap(m0, m1);\n        }\n\
    \        if(m0 < 0) m0 += b / s;\n        return {s, m0};\n    }\n};\ntemplate\
    \ <int id>\nBarrett DynamicModint<id>::bt(998244353);\nusing modint = DynamicModint<-1>;\n\
    #line 5 \"src/template/debug.hpp\"\nnamespace dbg {\ntemplate <typename A, typename\
    \ B>\nstring to_string(pair<A, B> p);\ntemplate <typename A, typename B, typename\
    \ C>\nstring to_string(tuple<A, B, C> p);\ntemplate <typename A, typename B, typename\
    \ C, typename D>\nstring to_string(tuple<A, B, C, D> p);\nstring to_string(const\
    \ string& s) {\n    return \"\\\"\" + s + \"\\\"\";\n}\nstring to_string(const\
    \ char& c) {\n    return \"'\" + string(1, c) + \"'\";\n}\nstring to_string(bool\
    \ b) {\n    return (b ? \"true\" : \"false\");\n}\ntemplate <typename T, enable_if_t<is_arithmetic<T>::value,\
    \ nullptr_t> = nullptr>\nstring to_string(T t) {\n    return std::to_string(t);\n\
    }\ntemplate <uint32_t m>\nstring to_string(StaticModint<m> x) {\n    return std::to_string(x.val());\n\
    }\ntemplate <int id>\nstring to_string(DynamicModint<id> x) {\n    return std::to_string(x.val());\n\
    }\nstring to_string(vector<bool> v) {\n    bool first = true;\n    string res\
    \ = \"{\";\n    for(int i = 0; i < static_cast<int>(v.size()); i++) {\n      \
    \  if(!first) {\n            res += \", \";\n        }\n        first = false;\n\
    \        res += dbg::to_string(v[i]);\n    }\n    res += \"}\";\n    return res;\n\
    }\ntemplate <size_t N>\nstring to_string(bitset<N> v) {\n    string res = \"\"\
    ;\n    for(size_t i = 0; i < N; i++) {\n        res += static_cast<char>('0' +\
    \ v[i]);\n    }\n    return res;\n}\ntemplate <typename A, enable_if_t<!is_arithmetic<A>::value,\
    \ nullptr_t> = nullptr>\nstring to_string(A v) {\n    bool first = true;\n   \
    \ string res = \"{\";\n    for(const auto& x : v) {\n        if(!first) {\n  \
    \          res += \", \";\n        }\n        first = false;\n        res += dbg::to_string(x);\n\
    \    }\n    res += \"}\";\n    return res;\n}\ntemplate <typename A, typename\
    \ B>\nstring to_string(pair<A, B> p) {\n    return \"(\" + dbg::to_string(p.first)\
    \ + \", \" + dbg::to_string(p.second) + \")\";\n}\ntemplate <typename A, typename\
    \ B, typename C>\nstring to_string(tuple<A, B, C> p) {\n    return \"(\" + dbg::to_string(get<0>(p))\
    \ + \", \" + dbg::to_string(get<1>(p)) + \", \" + dbg::to_string(get<2>(p)) +\
    \ \")\";\n}\ntemplate <typename A, typename B, typename C, typename D>\nstring\
    \ to_string(tuple<A, B, C, D> p) {\n    return \"(\" + dbg::to_string(get<0>(p))\
    \ + \", \" + dbg::to_string(get<1>(p)) + \", \" + dbg::to_string(get<2>(p)) +\
    \ \", \" + dbg::to_string(get<3>(p)) + \")\";\n}\nvoid debug_out() {\n    cerr\
    \ << endl;\n}\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head\
    \ H, Tail... T) {\n    cerr << \" \" << dbg::to_string(H);\n    if(sizeof...(T)\
    \ != 0) cerr << \",\";\n    debug_out(T...);\n}\n}  // namespace dbg\n#define\
    \ debug(...) cerr << \"Line \" << __LINE__ << \", \"  \\\n                   \
    \     << \"[\" << #__VA_ARGS__ << \"]:\", \\\n                   dbg::debug_out(__VA_ARGS__)\n\
    #line 4 \"verify/unit_test/template/debug.test.cpp\"\nusing mint = modint998244353;\n\
    using Mint = modint;\nvoid test() {\n    int a = 5, b = 7, c = -1;\n    debug(a,\
    \ b, c);\n    pair<int, int> p = {3, 4};\n    pair<pair<int, int>, pair<pair<int,\
    \ bool>, int>> q;\n    debug(p);\n    debug(q);\n    debug(p, q);\n    pair<string,\
    \ char> ps;\n    ps.second = 'f';\n    debug(ps);\n    vector<vector<pair<string,\
    \ char>>> v(3, vector<pair<string, char>>(4));\n    debug(v);\n    map<int, int>\
    \ mp;\n    mp[4] = 7;\n    mp[-2] = 9;\n    debug(mp);\n    set<double> st;\n\
    \    st.insert(4.1);\n    st.insert(3173.4178);\n    debug(st);\n    map<long\
    \ double, set<pair<string, vector<bool>>>> ms;\n    debug(ms);\n    map<string,\
    \ vector<pair<int, long double>>> mp2;\n    mp2[\"hello\"] = {{2, 3}, {4, 5}};\n\
    \    mp2[\"hoge\"] = {{4, 1}, {3, 8}, {7, 10}};\n    debug(mp2);\n    vector<pair<vector<ll>,\
    \ vector<string>>> v2 = {{{2, 3, 4, 5}, {\"hello\", \"hoge\"}}, {{3, 1, 4}, {\"\
    hfo\", \"fah\"}}};\n    debug(v2);\n    mint ma = 998244352, mb = 2, mc = ma *\
    \ mb;\n    debug(mc);\n    Mint::set_mod(1000000007);\n    Mint dma = 500000004,\
    \ dmb = 6, dmc = dma * dmb;\n    debug(dmc);\n}\nint main(void) {\n    test();\n\
    \    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/template/debug.hpp\"\nusing mint = modint998244353;\n\
    using Mint = modint;\nvoid test() {\n    int a = 5, b = 7, c = -1;\n    debug(a,\
    \ b, c);\n    pair<int, int> p = {3, 4};\n    pair<pair<int, int>, pair<pair<int,\
    \ bool>, int>> q;\n    debug(p);\n    debug(q);\n    debug(p, q);\n    pair<string,\
    \ char> ps;\n    ps.second = 'f';\n    debug(ps);\n    vector<vector<pair<string,\
    \ char>>> v(3, vector<pair<string, char>>(4));\n    debug(v);\n    map<int, int>\
    \ mp;\n    mp[4] = 7;\n    mp[-2] = 9;\n    debug(mp);\n    set<double> st;\n\
    \    st.insert(4.1);\n    st.insert(3173.4178);\n    debug(st);\n    map<long\
    \ double, set<pair<string, vector<bool>>>> ms;\n    debug(ms);\n    map<string,\
    \ vector<pair<int, long double>>> mp2;\n    mp2[\"hello\"] = {{2, 3}, {4, 5}};\n\
    \    mp2[\"hoge\"] = {{4, 1}, {3, 8}, {7, 10}};\n    debug(mp2);\n    vector<pair<vector<ll>,\
    \ vector<string>>> v2 = {{{2, 3, 4, 5}, {\"hello\", \"hoge\"}}, {{3, 1, 4}, {\"\
    hfo\", \"fah\"}}};\n    debug(v2);\n    mint ma = 998244352, mb = 2, mc = ma *\
    \ mb;\n    debug(mc);\n    Mint::set_mod(1000000007);\n    Mint dma = 500000004,\
    \ dmb = 6, dmc = dma * dmb;\n    debug(dmc);\n}\nint main(void) {\n    test();\n\
    \    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/template/debug.hpp
  - src/template/static_modint.hpp
  - src/template/dynamic_modint.hpp
  isVerificationFile: true
  path: verify/unit_test/template/debug.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/unit_test/template/debug.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/template/debug.test.cpp
- /verify/verify/unit_test/template/debug.test.cpp.html
title: verify/unit_test/template/debug.test.cpp
---
