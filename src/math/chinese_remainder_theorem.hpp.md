---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/inv_gcd.hpp
    title: inv_gcd
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/186.test.cpp
    title: verify/yukicoder/186.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/math/inv_gcd.hpp\"\n\
    constexpr pair<ll, ll> inv_gcd(ll a, ll b) {\n    a %= b;\n    if(a < 0) a +=\
    \ b;\n    if(a == 0) return {b, 0};\n    ll s = b, t = a, m0 = 0, m1 = 1;\n  \
    \  while(t) {\n        const ll u = s / t;\n        s -= t * u;\n        m0 -=\
    \ m1 * u;\n        ll tmp = s;\n        s = t;\n        t = tmp;\n        tmp\
    \ = m0;\n        m0 = m1;\n        m1 = tmp;\n    }\n    if(m0 < 0) m0 += b /\
    \ s;\n    return {s, m0};\n}\n#line 4 \"src/math/chinese_remainder_theorem.hpp\"\
    \npair<ll, ll> chinese_remainder_theorem(const vector<ll>& r, const vector<ll>&\
    \ m) {\n    assert(r.size() == m.size());\n    int n = (int)r.size();\n    ll\
    \ r0 = 0, m0 = 1;\n    for(int i = 0; i < n; ++i) {\n        assert(m[i] >= 1);\n\
    \        ll r1 = r[i] % m[i], m1 = m[i];\n        if(r1 < 0) r1 += m[i];\n   \
    \     if(m0 < m1) {\n            swap(r0, r1);\n            swap(m0, m1);\n  \
    \      }\n        if(m0 % m1 == 0) {\n            if(r0 % m1 != r1) return {0,\
    \ 0};\n            continue;\n        }\n        auto [g, im] = inv_gcd(m0, m1);\n\
    \        ll u1 = m1 / g;\n        if((r1 - r0) % g) return {0, 0};\n        ll\
    \ x = (r1 - r0) / g % u1 * im % u1;\n        r0 += x * m0;\n        m0 *= u1;\n\
    \        if(r0 < 0) r0 += m0;\n    }\n    return {r0, m0};\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./inv_gcd.hpp\"\
    \npair<ll, ll> chinese_remainder_theorem(const vector<ll>& r, const vector<ll>&\
    \ m) {\n    assert(r.size() == m.size());\n    int n = (int)r.size();\n    ll\
    \ r0 = 0, m0 = 1;\n    for(int i = 0; i < n; ++i) {\n        assert(m[i] >= 1);\n\
    \        ll r1 = r[i] % m[i], m1 = m[i];\n        if(r1 < 0) r1 += m[i];\n   \
    \     if(m0 < m1) {\n            swap(r0, r1);\n            swap(m0, m1);\n  \
    \      }\n        if(m0 % m1 == 0) {\n            if(r0 % m1 != r1) return {0,\
    \ 0};\n            continue;\n        }\n        auto [g, im] = inv_gcd(m0, m1);\n\
    \        ll u1 = m1 / g;\n        if((r1 - r0) % g) return {0, 0};\n        ll\
    \ x = (r1 - r0) / g % u1 * im % u1;\n        r0 += x * m0;\n        m0 *= u1;\n\
    \        if(r0 < 0) r0 += m0;\n    }\n    return {r0, m0};\n}"
  dependsOn:
  - src/template/template.hpp
  - src/math/inv_gcd.hpp
  isVerificationFile: false
  path: src/math/chinese_remainder_theorem.hpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/186.test.cpp
documentation_of: src/math/chinese_remainder_theorem.hpp
layout: document
title: chinese_remainder_theorem
---

## chinese_remainder_theorem

```cpp
pair<ll, ll> chinese_remainder_theorem(vectpr<ll> r, vector<ll> m)
```

同じ長さの配列 $r, m$ を渡します．<br>
この配列の長さを $n$ としたとき，

$$x \equiv r[i] \pmod{m[i]}, \forall i \in \lbrace 0,1,\cdots, n - 1 \rbrace$$

を解きます．<br>
答えは (存在するならば) $y, z (0 \leq y < z = \mathrm{lcm}(m[i]))$ を用いて $x \equiv y \pmod z$ の形で書けることが知られており，この $(y, z)$ をpairとして返します．<br>
答えがない場合は $(0, 0)$ を返します．<br>
$n = 0$ の時は $(0, 1)$ を返します．

**制約**

- $r.\mathrm{size}() = m.\mathrm{size}()$
- $1 \le m[i]$
- $\mathrm{lcm} (m[i])$ が `ll` に収まる．

**計算量**

- $O(n \log \mathrm{lcm} (m[i]))$