---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
    title: verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/seive.hpp\"\npair<vector<int>,\
    \ vector<int>> seive(int n) {\n    assert(n >= 1);\n    vector<int> min_factor(n\
    \ + 1);\n    iota(min_factor.begin(), min_factor.end(), 0);\n    min_factor[0]\
    \ = min_factor[1] = -1;\n    vector<int> prime;\n    for(long long i = 2; i <=\
    \ n; ++i) {\n        if(min_factor[i] < i) continue;\n        prime.push_back(i);\n\
    \        for(long long j = i * i; j <= n; j += i) {\n            if(min_factor[j]\
    \ == j) min_factor[j] = i;\n        }\n    }\n    return {prime, min_factor};\n\
    }\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\npair<vector<int>, vector<int>>\
    \ seive(int n) {\n    assert(n >= 1);\n    vector<int> min_factor(n + 1);\n  \
    \  iota(min_factor.begin(), min_factor.end(), 0);\n    min_factor[0] = min_factor[1]\
    \ = -1;\n    vector<int> prime;\n    for(long long i = 2; i <= n; ++i) {\n   \
    \     if(min_factor[i] < i) continue;\n        prime.push_back(i);\n        for(long\
    \ long j = i * i; j <= n; j += i) {\n            if(min_factor[j] == j) min_factor[j]\
    \ = i;\n        }\n    }\n    return {prime, min_factor};\n}"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/math/seive.hpp
  requiredBy: []
  timestamp: '2024-03-02 01:11:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/alds1/prime_numbers_2.test.cpp
documentation_of: src/math/seive.hpp
layout: document
title: seive
---

## seive

```cpp
pair<vector<int>, vector<int>> seive(int n)
```

正整数 $n$ を与えると $2$ つの配列 `prime` と `min_factor` を返します．

`prime` には $n$ 以下の素数が昇順に格納されています．

`min_factor` は長さ $n + 1$ の配列です．<br>
`min_factor[i]` は $i$ の素因数の最小値が格納されています．<br>
便宜上 `min_factor[0] = min_factor[1] = -1` としています．

$i$ が素数であることと `min_factor[i] = i` であることは同値です．

また以下のようにして，前計算 $O(n \log \log n)$ クエリ $O(\log n)$ で $n$ を素因数分解できます．

```cpp
vector<int> prime_factor;
while(n > 1) {
    prime_factor.push_back(min_factor[n])
    n /= min_factor[n];
}
```

**制約**

- $1 \leq n$

**計算量**

- $O(n \log \log n)$