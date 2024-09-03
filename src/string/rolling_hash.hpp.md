---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/alds1/string_search.test.cpp
    title: verify/aizu_online_judge/alds1/string_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/number_of_substrings.test.cpp
    title: verify/library_checker/string/number_of_substrings.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/string/rolling_hash.hpp\"\
    \nstruct RollingHash {\n    RollingHash(const string& s, long long BASE = 0) {\n\
    \        len = (int)s.size();\n        if(BASE <= 0) {\n            mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \            uniform_int_distribution<int> dist(1e8, 1e9);\n            BASE =\
    \ dist(mt);\n        }\n        base = BASE;\n        pow.resize(len + 5);\n \
    \       pow[0] = 1;\n        for(int i = 1; i < len + 5; ++i) {\n            pow[i]\
    \ = calc_mod(mul(pow[i - 1], base));\n        }\n        hash.resize(len + 1);\n\
    \        for(int i = 0; i < len; ++i) {\n            hash[i + 1] = calc_mod(mul(hash[i],\
    \ base) + s[i]);\n        }\n    }\n    long long get(int lower, int upper) const\
    \ {\n        assert(0 <= lower and lower <= upper and upper <= len);\n       \
    \ return calc_mod(hash[upper] + POSITIVIZER - mul(hash[lower], pow[upper - lower]));\n\
    \    }\n    long long get_hash(const string& t) const {\n        long long res\
    \ = 0;\n        for(int i = 0; i < (int)t.size(); ++i) {\n            res = calc_mod(mul(res,\
    \ base) + t[i]);\n        }\n        return res;\n    }\n    int find(const string&\
    \ t, int lower = 0) const {\n        if((int)t.size() > len) return -1;\n    \
    \    const long long ha = get_hash(t);\n        for(int i = lower; i < len - (int)t.size()\
    \ + 1; ++i) {\n            if(ha == get(i, i + (int)t.size())) return i;\n   \
    \     }\n        return -1;\n    }\n    int lcp(const RollingHash& a, const RollingHash&\
    \ b, int al, int bl) const {\n        int ok = 0, ng = min(a.len - al, b.len -\
    \ bl) + 1;\n        while(ok + 1 < ng) {\n            const int med = (ok + ng)\
    \ / 2;\n            if(a.get(al, med + al) == b.get(bl, med + bl)) {\n       \
    \         ok = med;\n            } else {\n                ng = med;\n       \
    \     }\n        }\n        return ok;\n    }\n\n   private:\n    static constexpr\
    \ unsigned long long MASK30 = (1ull << 30) - 1;\n    static constexpr unsigned\
    \ long long MASK31 = (1ull << 31) - 1;\n    static constexpr unsigned long long\
    \ MOD = (1ull << 61) - 1;\n    static constexpr unsigned long long POSITIVIZER\
    \ = MOD * ((1ull << 3) - 1);\n    int len;\n    long long base;\n    vector<unsigned\
    \ long long> pow;\n    vector<unsigned long long> hash;\n    inline unsigned long\
    \ long mul(unsigned long long x, unsigned long long y) const {\n        const\
    \ long long xu = x >> 31;\n        const long long xd = x & MASK31;\n        const\
    \ long long yu = y >> 31;\n        const long long yd = y & MASK31;\n        const\
    \ long long middlebit = xd * yu + xu * yd;\n        return ((xu * yu) << 1) +\
    \ xd * yd + ((middlebit & MASK30) << 31) + (middlebit >> 30);\n    }\n    inline\
    \ long long calc_mod(unsigned long long val) const {\n        val = (val & MOD)\
    \ + (val >> 61);\n        if(val > MOD) val -= MOD;\n        return val;\n   \
    \ }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\nstruct RollingHash {\n\
    \    RollingHash(const string& s, long long BASE = 0) {\n        len = (int)s.size();\n\
    \        if(BASE <= 0) {\n            mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \            uniform_int_distribution<int> dist(1e8, 1e9);\n            BASE =\
    \ dist(mt);\n        }\n        base = BASE;\n        pow.resize(len + 5);\n \
    \       pow[0] = 1;\n        for(int i = 1; i < len + 5; ++i) {\n            pow[i]\
    \ = calc_mod(mul(pow[i - 1], base));\n        }\n        hash.resize(len + 1);\n\
    \        for(int i = 0; i < len; ++i) {\n            hash[i + 1] = calc_mod(mul(hash[i],\
    \ base) + s[i]);\n        }\n    }\n    long long get(int lower, int upper) const\
    \ {\n        assert(0 <= lower and lower <= upper and upper <= len);\n       \
    \ return calc_mod(hash[upper] + POSITIVIZER - mul(hash[lower], pow[upper - lower]));\n\
    \    }\n    long long get_hash(const string& t) const {\n        long long res\
    \ = 0;\n        for(int i = 0; i < (int)t.size(); ++i) {\n            res = calc_mod(mul(res,\
    \ base) + t[i]);\n        }\n        return res;\n    }\n    int find(const string&\
    \ t, int lower = 0) const {\n        if((int)t.size() > len) return -1;\n    \
    \    const long long ha = get_hash(t);\n        for(int i = lower; i < len - (int)t.size()\
    \ + 1; ++i) {\n            if(ha == get(i, i + (int)t.size())) return i;\n   \
    \     }\n        return -1;\n    }\n    int lcp(const RollingHash& a, const RollingHash&\
    \ b, int al, int bl) const {\n        int ok = 0, ng = min(a.len - al, b.len -\
    \ bl) + 1;\n        while(ok + 1 < ng) {\n            const int med = (ok + ng)\
    \ / 2;\n            if(a.get(al, med + al) == b.get(bl, med + bl)) {\n       \
    \         ok = med;\n            } else {\n                ng = med;\n       \
    \     }\n        }\n        return ok;\n    }\n\n   private:\n    static constexpr\
    \ unsigned long long MASK30 = (1ull << 30) - 1;\n    static constexpr unsigned\
    \ long long MASK31 = (1ull << 31) - 1;\n    static constexpr unsigned long long\
    \ MOD = (1ull << 61) - 1;\n    static constexpr unsigned long long POSITIVIZER\
    \ = MOD * ((1ull << 3) - 1);\n    int len;\n    long long base;\n    vector<unsigned\
    \ long long> pow;\n    vector<unsigned long long> hash;\n    inline unsigned long\
    \ long mul(unsigned long long x, unsigned long long y) const {\n        const\
    \ long long xu = x >> 31;\n        const long long xd = x & MASK31;\n        const\
    \ long long yu = y >> 31;\n        const long long yd = y & MASK31;\n        const\
    \ long long middlebit = xd * yu + xu * yd;\n        return ((xu * yu) << 1) +\
    \ xd * yd + ((middlebit & MASK30) << 31) + (middlebit >> 30);\n    }\n    inline\
    \ long long calc_mod(unsigned long long val) const {\n        val = (val & MOD)\
    \ + (val >> 61);\n        if(val > MOD) val -= MOD;\n        return val;\n   \
    \ }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-06-04 23:34:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/alds1/string_search.test.cpp
  - verify/library_checker/string/number_of_substrings.test.cpp
documentation_of: src/string/rolling_hash.hpp
layout: document
title: RollingHash
---

# RollingHash

長さ $n$ の文字列 `s` に対して，

- 部分文字列のハッシュ値の取得

を 前計算 $O(n)$ クエリ $O(1)$ で行えるアルゴリズムです．

## コンストラクタ
```cpp
RollingHash rh(string s, ll BASE = 0)
```

- 長さ $n$ の文字列 `s` に対するローリングハッシュ，`rh` を構築します．

- 法は $2^{61} - 1$ です．`BASE` を指定しないときや負の値を指定したとき，基数は乱数となります．

**計算量**

- $O(n)$

## get
```cpp
ll rh.get(int lower, int upper)
```

部分文字列 `s[lower, upper)` のハッシュ値を返します．

**制約**

- $0 \leq \mathrm{lower} \leq \mathrm{upper} \leq n$

**計算量**

- $O(1)$

## get_hash

```cpp
ll rh.get_hash(string t)
```

長さ $m$ の文字列 `t` のハッシュ値を返します．

**計算量**

- $O(m)$

## find

```cpp
int rh.find(string t, int lower = 0)
```

`s` の $\mathrm{lower}$ 文字目以降で初めて文字列 `t` が現れるインデックスを返します．<br>
(存在しない場合は $-1$ を返します．)

**計算量**

- $O(n)$

## lcp

```cpp
int rh.lcp(RollingHash a, RollingHash b, int al, int bl)
```

文字列 `a[al, a.size())` と文字列 `b[bl, b.size())` のLongest Common Prefix (先頭から何文字一致するか) を返します．<br>
$\mathrm{min} (a.\mathrm{size}() - al, b.\mathrm{size}() - bl) \geq 0$ のときは $0$ を返します．

**計算量**

- $O(\log (a.\mathrm{size}() + b.\mathrm{size}()))$