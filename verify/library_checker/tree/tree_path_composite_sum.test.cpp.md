---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/template/static_modint.hpp
    title: StaticModint
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  - icon: ':heavy_check_mark:'
    path: src/tree/rerooting.hpp
    title: rerooting
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/tree_path_composite_sum
  bundledCode: "#line 1 \"verify/library_checker/tree/tree_path_composite_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\n\
    #line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/graph/graph_template.hpp\"\
    \ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T cost;\n    int\
    \ idx;\n    Edge()\n        : from(-1), to(-1), cost(-1), idx(-1) {}\n    Edge(const\
    \ int from, const int to, const T& cost = 1, const int idx = -1)\n        : from(from),\
    \ to(to), cost(cost), idx(idx) {}\n    operator int() const {\n        return\
    \ to;\n    }\n};\ntemplate <typename T>\nstruct Graph {\n    Graph(const int N)\n\
    \        : n(N), es(0), g(N) {}\n    int size() const {\n        return n;\n \
    \   }\n    int edge_size() const {\n        return es;\n    }\n    void add_edge(const\
    \ int from, const int to, const T& cost = 1) {\n        assert(0 <= from and from\
    \ < n);\n        assert(0 <= to and to < n);\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n \
    \   void add_directed_edge(const int from, const int to, const T& cost = 1) {\n\
    \        assert(0 <= from and from < n);\n        assert(0 <= to and to < n);\n\
    \        g[from].emplace_back(from, to, cost, es++);\n    }\n    inline vector<Edge<T>>&\
    \ operator[](const int& k) {\n        assert(0 <= k and k < n);\n        return\
    \ g[k];\n    }\n    inline const vector<Edge<T>>& operator[](const int& k) const\
    \ {\n        assert(0 <= k and k < n);\n        return g[k];\n    }\n\n   private:\n\
    \    int n, es;\n    vector<vector<Edge<T>>> g;\n};\ntemplate <typename T>\nusing\
    \ Edges = vector<Edge<T>>;\n#line 4 \"src/tree/rerooting.hpp\"\ntemplate <typename\
    \ DP, typename T, typename F1, typename F2>\nvector<DP> rerooting(const Graph<T>&\
    \ g, const F1& f1, const F2& f2, const DP& id) {\n    const int n = g.size();\n\
    \    vector<DP> memo(n, id), dp(n, id);\n    auto dfs = [&](const auto& dfs, const\
    \ int cur, const int par) -> void {\n        for(const Edge<T>& e : g[cur]) {\n\
    \            if(e.to == par) continue;\n            dfs(dfs, e.to, cur);\n   \
    \         memo[cur] = f1(memo[cur], f2(memo[e.to], e.to, cur));\n        }\n \
    \   };\n    auto efs = [&](const auto& efs, const int cur, const int par, const\
    \ DP& pval) -> void {\n        vector<DP> buf;\n        for(const Edge<T>& e :\
    \ g[cur]) {\n            if(e.to == par) continue;\n            buf.emplace_back(f2(memo[e.to],\
    \ e.to, cur));\n        }\n        vector<DP> head(buf.size() + 1), tail(buf.size()\
    \ + 1);\n        head[0] = tail[buf.size()] = id;\n        for(int i = 0; i <\
    \ (int)buf.size(); ++i) head[i + 1] = f1(head[i], buf[i]);\n        for(int i\
    \ = (int)buf.size() - 1; i >= 0; --i) {\n            tail[i] = f1(tail[i + 1],\
    \ buf[i]);\n        }\n        dp[cur] = par == -1 ? head.back() : f1(pval, head.back());\n\
    \        int idx = 0;\n        for(const Edge<T>& e : g[cur]) {\n            if(e.to\
    \ == par) continue;\n            efs(efs, e.to, cur, f2(f1(pval, f1(head[idx],\
    \ tail[idx + 1])), cur, e));\n            ++idx;\n        }\n    };\n    dfs(dfs,\
    \ 0, -1);\n    efs(efs, 0, -1, id);\n    return dp;\n}\n#line 3 \"src/template/static_modint.hpp\"\
    \ntemplate <uint32_t m>\nstruct StaticModint {\n    using mint = StaticModint;\n\
    \    static constexpr uint32_t mod() {\n        return m;\n    }\n    static constexpr\
    \ mint raw(const uint32_t v) {\n        mint a;\n        a._v = v;\n        return\
    \ a;\n    }\n    constexpr StaticModint()\n        : _v(0) {}\n    template <class\
    \ T>\n    constexpr StaticModint(const T& v) {\n        static_assert(is_integral_v<T>);\n\
    \        if constexpr(is_signed_v<T>) {\n            int64_t x = int64_t(v % int64_t(m));\n\
    \            if(x < 0) x += m;\n            _v = uint32_t(x);\n        } else\
    \ _v = uint32_t(v % m);\n    }\n    constexpr uint32_t val() const {\n       \
    \ return _v;\n    }\n    constexpr mint& operator++() {\n        return *this\
    \ += 1;\n    }\n    constexpr mint& operator--() {\n        return *this -= 1;\n\
    \    }\n    constexpr mint operator++(int) {\n        mint res = *this;\n    \
    \    ++*this;\n        return res;\n    }\n    constexpr mint operator--(int)\
    \ {\n        mint res = *this;\n        --*this;\n        return res;\n    }\n\
    \    constexpr mint& operator+=(mint rhs) {\n        if(_v >= m - rhs._v) _v -=\
    \ m;\n        _v += rhs._v;\n        return *this;\n    }\n    constexpr mint&\
    \ operator-=(mint rhs) {\n        if(_v < rhs._v) _v += m;\n        _v -= rhs._v;\n\
    \        return *this;\n    }\n    constexpr mint& operator*=(mint rhs) {\n  \
    \      return *this = *this * rhs;\n    }\n    constexpr mint& operator/=(mint\
    \ rhs) {\n        return *this *= rhs.inv();\n    }\n    constexpr mint operator+()\
    \ const {\n        return *this;\n    }\n    constexpr mint operator-() const\
    \ {\n        return mint{} - *this;\n    }\n    constexpr mint pow(long long n)\
    \ const {\n        assert(0 <= n);\n        if(n == 0) return 1;\n        mint\
    \ x = *this, r = 1;\n        while(1) {\n            if(n & 1) r *= x;\n     \
    \       n >>= 1;\n            if(n == 0) return r;\n            x *= x;\n    \
    \    }\n    }\n    constexpr mint inv() const {\n        if constexpr(prime) {\n\
    \            assert(_v);\n            return pow(m - 2);\n        } else {\n \
    \           const auto eg = inv_gcd(_v, m);\n            assert(eg.first == 1);\n\
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
    #line 6 \"verify/library_checker/tree/tree_path_composite_sum.test.cpp\"\nusing\
    \ mint = modint998244353;\nint main(void) {\n    int n;\n    cin >> n;\n    vector<mint>\
    \ a(n);\n    rep(i, 0, n) cin >> a[i];\n    Graph<int> g(n);\n    map<pair<int,\
    \ int>, pair<mint, mint>> mp;\n    rep(i, 0, n - 1) {\n        int u, v, b, c;\n\
    \        cin >> u >> v >> b >> c;\n        g.add_edge(u, v);\n        mp[minmax(u,\
    \ v)] = {b, c};\n    }\n    using DP = pair<mint, int>;\n    auto f1 = [&](const\
    \ DP& x, const DP& y) -> DP {\n        return {x.first + y.first, x.second + y.second};\n\
    \    };\n    auto f2 = [&](const DP& x, const int child, const int parent) ->\
    \ DP {\n        auto [b, c] = mp[minmax(child, parent)];\n        return {(x.first\
    \ + a[child]) * b + c * (x.second + 1), x.second + 1};\n    };\n    const DP id\
    \ = {0, 0};\n    vector<DP> dp = rerooting(g, f1, f2, id);\n    rep(i, 0, n) {\n\
    \        cout << dp[i].first + a[i] << \" \\n\"[i + 1 == n];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/tree/rerooting.hpp\"\n#include \"../../../src/template/static_modint.hpp\"\
    \nusing mint = modint998244353;\nint main(void) {\n    int n;\n    cin >> n;\n\
    \    vector<mint> a(n);\n    rep(i, 0, n) cin >> a[i];\n    Graph<int> g(n);\n\
    \    map<pair<int, int>, pair<mint, mint>> mp;\n    rep(i, 0, n - 1) {\n     \
    \   int u, v, b, c;\n        cin >> u >> v >> b >> c;\n        g.add_edge(u, v);\n\
    \        mp[minmax(u, v)] = {b, c};\n    }\n    using DP = pair<mint, int>;\n\
    \    auto f1 = [&](const DP& x, const DP& y) -> DP {\n        return {x.first\
    \ + y.first, x.second + y.second};\n    };\n    auto f2 = [&](const DP& x, const\
    \ int child, const int parent) -> DP {\n        auto [b, c] = mp[minmax(child,\
    \ parent)];\n        return {(x.first + a[child]) * b + c * (x.second + 1), x.second\
    \ + 1};\n    };\n    const DP id = {0, 0};\n    vector<DP> dp = rerooting(g, f1,\
    \ f2, id);\n    rep(i, 0, n) {\n        cout << dp[i].first + a[i] << \" \\n\"\
    [i + 1 == n];\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/tree/rerooting.hpp
  - src/template/static_modint.hpp
  isVerificationFile: true
  path: verify/library_checker/tree/tree_path_composite_sum.test.cpp
  requiredBy: []
  timestamp: '2025-02-24 20:07:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/tree_path_composite_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/tree_path_composite_sum.test.cpp
- /verify/verify/library_checker/tree/tree_path_composite_sum.test.cpp.html
title: verify/library_checker/tree/tree_path_composite_sum.test.cpp
---
