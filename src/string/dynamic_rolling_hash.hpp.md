---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data_structure/fenwick_tree.hpp
    title: FenwickTree
  - icon: ':question:'
    path: src/template/modint_2_61m1.hpp
    title: Modint_2_61m1
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/unit_test/string/dynamic_rolling_hash.test.cpp
    title: verify/unit_test/string/dynamic_rolling_hash.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n\
    #define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a,\
    \ b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
    struct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/template/modint_2_61m1.hpp\"\
    \nstruct Modint_2_61m1 {\n    using mint = Modint_2_61m1;\n    using u64 = uint64_t;\n\
    \    using u128 = __uint128_t;\n    static constexpr u64 mod() {\n        return\
    \ m;\n    }\n    static constexpr mint raw(const u64 v) {\n        mint a;\n \
    \       a._v = v;\n        return a;\n    }\n    constexpr Modint_2_61m1()\n \
    \       : _v(0) {}\n    template <class T>\n    constexpr Modint_2_61m1(const\
    \ T& v) {\n        static_assert(is_integral_v<T>);\n        if constexpr(is_signed_v<T>)\
    \ {\n            int64_t x = int64_t(v % int64_t(m));\n            if(x < 0) x\
    \ += m;\n            _v = u64(x);\n        } else _v = u64(v % m);\n    }\n  \
    \  constexpr u64 val() const {\n        return _v;\n    }\n    constexpr mint&\
    \ operator++() {\n        return *this += 1;\n    }\n    constexpr mint& operator--()\
    \ {\n        return *this -= 1;\n    }\n    constexpr mint operator++(int) {\n\
    \        mint res = *this;\n        ++*this;\n        return res;\n    }\n   \
    \ constexpr mint operator--(int) {\n        mint res = *this;\n        --*this;\n\
    \        return res;\n    }\n    constexpr mint& operator+=(mint rhs) {\n    \
    \    if(_v >= m - rhs._v) _v -= m;\n        _v += rhs._v;\n        return *this;\n\
    \    }\n    constexpr mint& operator-=(mint rhs) {\n        if(_v < rhs._v) _v\
    \ += m;\n        _v -= rhs._v;\n        return *this;\n    }\n    constexpr mint&\
    \ operator*=(mint rhs) {\n        return *this = *this * rhs;\n    }\n    constexpr\
    \ mint& operator/=(mint rhs) {\n        return *this *= rhs.inv();\n    }\n  \
    \  constexpr mint operator+() const {\n        return *this;\n    }\n    constexpr\
    \ mint operator-() const {\n        return mint{} - *this;\n    }\n    constexpr\
    \ mint pow(u64 n) const {\n        if(n == 0) return 1;\n        mint x = *this,\
    \ r = 1;\n        while(1) {\n            if(n & 1) r *= x;\n            n >>=\
    \ 1;\n            if(n == 0) return r;\n            x *= x;\n        }\n    }\n\
    \    constexpr mint inv() const {\n        assert(_v);\n        return pow(m -\
    \ 2);\n    }\n    friend constexpr mint operator+(mint lhs, mint rhs) {\n    \
    \    return lhs += rhs;\n    }\n    friend constexpr mint operator-(mint lhs,\
    \ mint rhs) {\n        return lhs -= rhs;\n    }\n    friend constexpr mint operator*(mint\
    \ lhs, mint rhs) {\n        return raw(modulo(u128(lhs._v) * rhs._v));\n    }\n\
    \    friend constexpr mint operator/(mint lhs, mint rhs) {\n        return lhs\
    \ /= rhs;\n    }\n    friend constexpr bool operator==(mint lhs, mint rhs) {\n\
    \        return lhs._v == rhs._v;\n    }\n    friend constexpr bool operator!=(mint\
    \ lhs, mint rhs) {\n        return lhs._v != rhs._v;\n    }\n    friend istream&\
    \ operator>>(istream& in, mint& x) {\n        long long a;\n        in >> a;\n\
    \        x = a;\n        return in;\n    }\n    friend ostream& operator<<(ostream&\
    \ out, const mint& x) {\n        return out << x.val();\n    }\n\n   private:\n\
    \    static constexpr u64 m = (1ull << 61) - 1;\n    u64 _v = 0;\n    inline static\
    \ constexpr u64 modulo(const u128& x) {\n        const u64 val = (x >> 61) + (x\
    \ & m);\n        return val >= m ? val - m : val;\n    }\n};\n#line 3 \"src/data_structure/fenwick_tree.hpp\"\
    \ntemplate <typename T>\nstruct FenwickTree {\n    FenwickTree(int N)\n      \
    \  : n(N), data(N) {}\n    void add(int p, const T x) {\n        assert(0 <= p\
    \ and p < n);\n        ++p;\n        while(p <= n) {\n            data[p - 1]\
    \ += x;\n            p += p & -p;\n        }\n    }\n    T sum(const int l, const\
    \ int r) const {\n        assert(0 <= l and l <= r and r <= n);\n        return\
    \ sum(r) - sum(l);\n    }\n    T get(const int x) const {\n        assert(0 <=\
    \ x and x < n);\n        return sum(x + 1) - sum(x);\n    }\n\n   private:\n \
    \   int n;\n    vector<T> data;\n    inline T sum(int r) const {\n        T s\
    \ = 0;\n        while(r > 0) {\n            s += data[r - 1];\n            r -=\
    \ r & -r;\n        }\n        return s;\n    }\n};\n#line 5 \"src/string/dynamic_rolling_hash.hpp\"\
    \nstruct DynamicRollingHash {\n    using mint = Modint_2_61m1;\n    DynamicRollingHash(const\
    \ string& s, unsigned long long BASE = 0)\n        : len((int)s.size()), pow(len\
    \ + 1), inv_pow(len + 1), hash(len) {\n        if(BASE == 0) {\n            mt19937\
    \ mt(chrono::steady_clock::now().time_since_epoch().count());\n            uniform_int_distribution<unsigned\
    \ long long> dist(1ull << 10, 1ull << 60);\n            BASE = dist(mt);\n   \
    \     }\n        base = BASE;\n        pow[0] = 1;\n        for(int i = 0; i <\
    \ len; ++i) {\n            pow[i + 1] = pow[i] * base;\n        }\n        inv\
    \ = base.inv();\n        inv_pow[0] = 1;\n        for(int i = 0; i < len; ++i)\
    \ {\n            inv_pow[i + 1] = inv_pow[i] * inv;\n        }\n        for(int\
    \ i = 0; i < len; ++i) {\n            hash.add(i, pow[i] * s[i]);\n        }\n\
    \    }\n    unsigned long long get(const int lower, const int upper) const {\n\
    \        assert(0 <= lower and lower <= upper and upper <= len);\n        return\
    \ (hash.sum(lower, upper) * inv_pow[lower]).val();\n    }\n    unsigned long long\
    \ get_hash(const string& t) const {\n        mint res = 0;\n        for(int i\
    \ = 0; i < (int)t.size(); ++i) {\n            res += pow[i] * t[i];\n        }\n\
    \        return res.val();\n    }\n    void set(const int idx, const char c) {\n\
    \        assert(0 <= idx and idx < len);\n        hash.add(idx, pow[idx] * c -\
    \ hash.get(idx));\n    }\n\n   private:\n    int len;\n    mint base, inv;\n \
    \   vector<mint> pow, inv_pow;\n    FenwickTree<mint> hash;\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../template/modint_2_61m1.hpp\"\
    \n#include \"../data_structure/fenwick_tree.hpp\"\nstruct DynamicRollingHash {\n\
    \    using mint = Modint_2_61m1;\n    DynamicRollingHash(const string& s, unsigned\
    \ long long BASE = 0)\n        : len((int)s.size()), pow(len + 1), inv_pow(len\
    \ + 1), hash(len) {\n        if(BASE == 0) {\n            mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \            uniform_int_distribution<unsigned long long> dist(1ull << 10, 1ull\
    \ << 60);\n            BASE = dist(mt);\n        }\n        base = BASE;\n   \
    \     pow[0] = 1;\n        for(int i = 0; i < len; ++i) {\n            pow[i +\
    \ 1] = pow[i] * base;\n        }\n        inv = base.inv();\n        inv_pow[0]\
    \ = 1;\n        for(int i = 0; i < len; ++i) {\n            inv_pow[i + 1] = inv_pow[i]\
    \ * inv;\n        }\n        for(int i = 0; i < len; ++i) {\n            hash.add(i,\
    \ pow[i] * s[i]);\n        }\n    }\n    unsigned long long get(const int lower,\
    \ const int upper) const {\n        assert(0 <= lower and lower <= upper and upper\
    \ <= len);\n        return (hash.sum(lower, upper) * inv_pow[lower]).val();\n\
    \    }\n    unsigned long long get_hash(const string& t) const {\n        mint\
    \ res = 0;\n        for(int i = 0; i < (int)t.size(); ++i) {\n            res\
    \ += pow[i] * t[i];\n        }\n        return res.val();\n    }\n    void set(const\
    \ int idx, const char c) {\n        assert(0 <= idx and idx < len);\n        hash.add(idx,\
    \ pow[idx] * c - hash.get(idx));\n    }\n\n   private:\n    int len;\n    mint\
    \ base, inv;\n    vector<mint> pow, inv_pow;\n    FenwickTree<mint> hash;\n};"
  dependsOn:
  - src/template/template.hpp
  - src/template/modint_2_61m1.hpp
  - src/data_structure/fenwick_tree.hpp
  isVerificationFile: false
  path: src/string/dynamic_rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/unit_test/string/dynamic_rolling_hash.test.cpp
documentation_of: src/string/dynamic_rolling_hash.hpp
layout: document
title: DynamicRollingHash
---

# DynamicRollingHash

長さ $n$ の文字列 `s` に対して，

- 部分文字列のハッシュ値の取得
- 1文字更新

を，前計算 $O(n \log n)$ クエリ $O(\log n)$ で行えるアルゴリズムです．

## コンストラクタ
```cpp
DynamicRollingHash drh(string s, ull BASE = 0)
```

- 長さ $n$ の文字列 `s` に対する動的ローリングハッシュ，`drh` を構築します．

- 法は $2^{61} - 1$ です．`BASE` を指定しないときや $0$ を指定したとき，基数は乱数となります．

**計算量**

- $O(n \log n)$

## get
```cpp
ull drh.get(int lower, int upper)
```

部分文字列 `s[lower, upper)` のハッシュ値を返します．

**制約**

- $0 \leq \mathrm{lower} \leq \mathrm{upper} \leq n$

**計算量**

- $O(\log n)$

## get_hash

```cpp
ull drh.get_hash(string t)
```

長さ $m$ の文字列 `t` のハッシュ値を返します．

**計算量**

- $O(m)$

## set

```cpp
void drh.set(int idx, char c)
```

`s[idx]` を `c` に更新します．

**制約**

- $0 \leq \mathrm{idx} < n$

**計算量**

- $O(\log n)$
