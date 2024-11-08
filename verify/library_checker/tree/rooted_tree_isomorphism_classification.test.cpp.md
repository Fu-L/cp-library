---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/template/modint_2_61m1.hpp
    title: Modint_2_61m1
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  - icon: ':heavy_check_mark:'
    path: src/tree/rooted_hash_tree.hpp
    title: src/tree/rooted_hash_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
  bundledCode: "#line 1 \"verify/library_checker/tree/rooted_tree_isomorphism_classification.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/graph/graph_template.hpp\"\ntemplate <typename T>\nstruct Edge {\n\
    \    int from, to;\n    T cost;\n    int idx;\n    Edge()\n        : from(-1),\
    \ to(-1), cost(-1), idx(-1) {}\n    Edge(int from, int to, const T& cost = 1,\
    \ int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx) {}\n    operator\
    \ int() const {\n        return to;\n    }\n};\ntemplate <typename T>\nstruct\
    \ Graph {\n    Graph(int N)\n        : n(N), es(0), g(N) {}\n    int size() const\
    \ {\n        return n;\n    }\n    int edge_size() const {\n        return es;\n\
    \    }\n    void add_edge(int from, int to, const T& cost = 1) {\n        assert(0\
    \ <= from and from < n);\n        assert(0 <= to and to < n);\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n \
    \   void add_directed_edge(int from, int to, const T& cost = 1) {\n        assert(0\
    \ <= from and from < n);\n        assert(0 <= to and to < n);\n        g[from].emplace_back(from,\
    \ to, cost, es++);\n    }\n    inline vector<Edge<T>>& operator[](const int& k)\
    \ {\n        assert(0 <= k and k < n);\n        return g[k];\n    }\n    inline\
    \ const vector<Edge<T>>& operator[](const int& k) const {\n        assert(0 <=\
    \ k and k < n);\n        return g[k];\n    }\n\n   private:\n    int n, es;\n\
    \    vector<vector<Edge<T>>> g;\n};\ntemplate <typename T>\nusing Edges = vector<Edge<T>>;\n\
    #line 3 \"src/template/modint_2_61m1.hpp\"\nstruct Modint_2_61m1 {\n    using\
    \ mint = Modint_2_61m1;\n    using u64 = uint64_t;\n    using u128 = __uint128_t;\n\
    \    static constexpr u64 mod() {\n        return m;\n    }\n    static constexpr\
    \ mint raw(const u64 v) {\n        mint a;\n        a._v = v;\n        return\
    \ a;\n    }\n    constexpr Modint_2_61m1()\n        : _v(0) {}\n    template <class\
    \ T>\n    constexpr Modint_2_61m1(const T& v) {\n        static_assert(is_integral_v<T>);\n\
    \        if constexpr(is_signed_v<T>) {\n            int64_t x = int64_t(v % int64_t(m));\n\
    \            if(x < 0) x += m;\n            _v = u64(x);\n        } else _v =\
    \ u64(v % m);\n    }\n    constexpr u64 val() const {\n        return _v;\n  \
    \  }\n    constexpr mint& operator++() {\n        return *this += 1;\n    }\n\
    \    constexpr mint& operator--() {\n        return *this -= 1;\n    }\n    constexpr\
    \ mint operator++(int) {\n        mint res = *this;\n        ++*this;\n      \
    \  return res;\n    }\n    constexpr mint operator--(int) {\n        mint res\
    \ = *this;\n        --*this;\n        return res;\n    }\n    constexpr mint&\
    \ operator+=(mint rhs) {\n        if(_v >= m - rhs._v) _v -= m;\n        _v +=\
    \ rhs._v;\n        return *this;\n    }\n    constexpr mint& operator-=(mint rhs)\
    \ {\n        if(_v < rhs._v) _v += m;\n        _v -= rhs._v;\n        return *this;\n\
    \    }\n    constexpr mint& operator*=(mint rhs) {\n        return *this = *this\
    \ * rhs;\n    }\n    constexpr mint& operator/=(mint rhs) {\n        return *this\
    \ *= rhs.inv();\n    }\n    constexpr mint operator+() const {\n        return\
    \ *this;\n    }\n    constexpr mint operator-() const {\n        return mint{}\
    \ - *this;\n    }\n    constexpr mint pow(u64 n) const {\n        if(n == 0) return\
    \ 1;\n        mint x = *this, r = 1;\n        while(1) {\n            if(n & 1)\
    \ r *= x;\n            n >>= 1;\n            if(n == 0) return r;\n          \
    \  x *= x;\n        }\n    }\n    constexpr mint inv() const {\n        assert(_v);\n\
    \        return pow(m - 2);\n    }\n    friend constexpr mint operator+(mint lhs,\
    \ mint rhs) {\n        return lhs += rhs;\n    }\n    friend constexpr mint operator-(mint\
    \ lhs, mint rhs) {\n        return lhs -= rhs;\n    }\n    friend constexpr mint\
    \ operator*(mint lhs, mint rhs) {\n        return raw(modulo(u128(lhs._v) * rhs._v));\n\
    \    }\n    friend constexpr mint operator/(mint lhs, mint rhs) {\n        return\
    \ lhs /= rhs;\n    }\n    friend constexpr bool operator==(mint lhs, mint rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend constexpr bool operator!=(mint\
    \ lhs, mint rhs) {\n        return lhs._v != rhs._v;\n    }\n    friend istream&\
    \ operator>>(istream& in, mint& x) {\n        long long a;\n        in >> a;\n\
    \        x = a;\n        return in;\n    }\n    friend ostream& operator<<(ostream&\
    \ out, const mint& x) {\n        return out << x.val();\n    }\n\n   private:\n\
    \    static constexpr u64 m = (1ull << 61) - 1;\n    u64 _v = 0;\n    inline static\
    \ constexpr u64 modulo(const u128& x) {\n        const u64 val = (x >> 61) + (x\
    \ & m);\n        return val >= m ? val - m : val;\n    }\n};\n#line 5 \"src/tree/rooted_hash_tree.hpp\"\
    \ntemplate <typename T>\nvector<ll> rooted_tree_hash(const Graph<T>& g, const\
    \ int root = 0) {\n    const int n = g.size();\n    assert(0 <= root and root\
    \ < n);\n    static mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    static vector<Modint_2_61m1> hash;\n    while((int)hash.size() < n) {\n \
    \       static uniform_int_distribution<unsigned long long> dist(0, Modint_2_61m1::mod()\
    \ - 1);\n        hash.emplace_back(dist(mt));\n    }\n    vector<ll> res(n);\n\
    \    auto dfs = [&](auto& dfs, const int cur, const int par) -> int {\n      \
    \  int depth = 0;\n        for(const auto& e : g[cur]) {\n            if(e.to\
    \ == par) continue;\n            depth = max(depth, dfs(dfs, e.to, cur) + 1);\n\
    \        }\n        Modint_2_61m1 h = 1, r = hash[depth];\n        for(const auto&\
    \ e : g[cur]) {\n            if(e.to == par) continue;\n            h *= (r +\
    \ res[e.to]);\n        }\n        res[cur] = h.val();\n        return depth;\n\
    \    };\n    dfs(dfs, root, -1);\n    return res;\n}\n#line 5 \"verify/library_checker/tree/rooted_tree_isomorphism_classification.test.cpp\"\
    \nint main(void) {\n    int n;\n    cin >> n;\n    Graph<int> g(n);\n    rep(i,\
    \ 1, n) {\n        int p;\n        cin >> p;\n        g.add_edge(i, p);\n    }\n\
    \    vector<ll> h = rooted_tree_hash(g, 0);\n    unordered_map<ll, int> mp;\n\
    \    int idx = 0;\n    rep(i, 0, n) {\n        if(mp.find(h[i]) == mp.end()) {\n\
    \            mp[h[i]] = idx++;\n        }\n    }\n    cout << idx << '\\n';\n\
    \    rep(i, 0, n) {\n        cout << mp[h[i]] << \" \\n\"[i + 1 == n];\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/tree/rooted_hash_tree.hpp\"\nint main(void) {\n    int\
    \ n;\n    cin >> n;\n    Graph<int> g(n);\n    rep(i, 1, n) {\n        int p;\n\
    \        cin >> p;\n        g.add_edge(i, p);\n    }\n    vector<ll> h = rooted_tree_hash(g,\
    \ 0);\n    unordered_map<ll, int> mp;\n    int idx = 0;\n    rep(i, 0, n) {\n\
    \        if(mp.find(h[i]) == mp.end()) {\n            mp[h[i]] = idx++;\n    \
    \    }\n    }\n    cout << idx << '\\n';\n    rep(i, 0, n) {\n        cout <<\
    \ mp[h[i]] << \" \\n\"[i + 1 == n];\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/tree/rooted_hash_tree.hpp
  - src/template/modint_2_61m1.hpp
  isVerificationFile: true
  path: verify/library_checker/tree/rooted_tree_isomorphism_classification.test.cpp
  requiredBy: []
  timestamp: '2024-11-08 23:44:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/rooted_tree_isomorphism_classification.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/rooted_tree_isomorphism_classification.test.cpp
- /verify/verify/library_checker/tree/rooted_tree_isomorphism_classification.test.cpp.html
title: verify/library_checker/tree/rooted_tree_isomorphism_classification.test.cpp
---
