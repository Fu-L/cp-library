---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_B
  bundledCode: "#line 1 \"verify/aizu_online_judge/grl/height_of_a_tree.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_B\"\n#line\
    \ 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i\
    \ = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/graph/graph_template.hpp\"\ntemplate <typename T = int>\nstruct\
    \ Edge {\n    int from, to;\n    T cost;\n    int idx;\n    Edge()\n        :\
    \ from(-1), to(-1), cost(-1), idx(-1) {}\n    Edge(int from, int to, T cost =\
    \ 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx) {}\n  \
    \  operator int() const {\n        return to;\n    }\n};\ntemplate <typename T\
    \ = int>\nstruct Graph {\n    vector<vector<Edge<T>>> g;\n    int es;\n    Graph(int\
    \ n)\n        : g(n), es(0) {}\n    size_t size() const {\n        return g.size();\n\
    \    }\n    void add_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es);\n        g[to].emplace_back(to, from, cost, es++);\n    }\n \
    \   void add_directed_edge(int from, int to, T cost = 1) {\n        g[from].emplace_back(from,\
    \ to, cost, es++);\n    }\n    inline vector<Edge<T>>& operator[](const int& k)\
    \ {\n        return g[k];\n    }\n    inline const vector<Edge<T>>& operator[](const\
    \ int& k) const {\n        return g[k];\n    }\n};\ntemplate <typename T = int>\n\
    using Edges = vector<Edge<T>>;\n#line 4 \"src/tree/rerooting.hpp\"\ntemplate <typename\
    \ DP, typename T, typename F1, typename F2>\nvector<DP> rerooting(const Graph<T>&\
    \ g, const F1& f1, const F2& f2, const DP& id) {\n    const int n = (int)g.size();\n\
    \    vector<DP> memo(n, id), dp(n, id);\n    auto dfs = [&](auto& dfs, int cur,\
    \ int par) -> void {\n        for(const auto& e : g[cur]) {\n            if(e.to\
    \ == par) continue;\n            dfs(dfs, e, cur);\n            memo[cur] = f1(memo[cur],\
    \ f2(memo[e.to], e.to, cur));\n        }\n    };\n    auto efs = [&](auto& efs,\
    \ int cur, int par, const DP& pval) -> void {\n        vector<DP> buf;\n     \
    \   for(const auto& e : g[cur]) {\n            if(e.to == par) continue;\n   \
    \         buf.push_back(f2(memo[e.to], e.to, cur));\n        }\n        vector<T>\
    \ head(buf.size() + 1), tail(buf.size() + 1);\n        head[0] = tail[buf.size()]\
    \ = id;\n        for(int i = 0; i < (int)buf.size(); ++i) head[i + 1] = f1(head[i],\
    \ buf[i]);\n        for(int i = (int)buf.size() - 1; i >= 0; --i) {\n        \
    \    tail[i] = f1(tail[i + 1], buf[i]);\n        }\n        dp[cur] = par == -1\
    \ ? head.back() : f1(pval, head.back());\n        int idx = 0;\n        for(const\
    \ auto& e : g[cur]) {\n            if(e.to == par) continue;\n            efs(efs,\
    \ e.to, cur, f2(f1(pval, f1(head[idx], tail[idx + 1])), cur, e));\n          \
    \  ++idx;\n        }\n    };\n    dfs(dfs, 0, -1);\n    efs(efs, 0, -1, id);\n\
    \    return dp;\n}\n#line 5 \"verify/aizu_online_judge/grl/height_of_a_tree.test.cpp\"\
    \nint main(void) {\n    int n;\n    cin >> n;\n    Graph<int> g(n);\n    map<pair<int,\
    \ int>, int> mp;\n    rep(i, 0, n - 1) {\n        int a, b, c;\n        cin >>\
    \ a >> b >> c;\n        g.add_edge(a, b, c);\n        mp[{a, b}] = c;\n      \
    \  mp[{b, a}] = c;\n    }\n    using DP = int;\n    auto f1 = [&](DP x, DP y)\
    \ -> DP {\n        return max(x, y);\n    };\n    auto f2 = [&](DP x, int child,\
    \ int parent) -> DP {\n        return x + mp[{child, parent}];\n    };\n    DP\
    \ id = 0;\n    vector<DP> dp = rerooting(g, f1, f2, id);\n    rep(i, 0, n) {\n\
    \        cout << dp[i] << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_B\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/tree/rerooting.hpp\"\nint main(void) {\n    int n;\n\
    \    cin >> n;\n    Graph<int> g(n);\n    map<pair<int, int>, int> mp;\n    rep(i,\
    \ 0, n - 1) {\n        int a, b, c;\n        cin >> a >> b >> c;\n        g.add_edge(a,\
    \ b, c);\n        mp[{a, b}] = c;\n        mp[{b, a}] = c;\n    }\n    using DP\
    \ = int;\n    auto f1 = [&](DP x, DP y) -> DP {\n        return max(x, y);\n \
    \   };\n    auto f2 = [&](DP x, int child, int parent) -> DP {\n        return\
    \ x + mp[{child, parent}];\n    };\n    DP id = 0;\n    vector<DP> dp = rerooting(g,\
    \ f1, f2, id);\n    rep(i, 0, n) {\n        cout << dp[i] << '\\n';\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/tree/rerooting.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/grl/height_of_a_tree.test.cpp
  requiredBy: []
  timestamp: '2024-01-06 03:31:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/grl/height_of_a_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/grl/height_of_a_tree.test.cpp
- /verify/verify/aizu_online_judge/grl/height_of_a_tree.test.cpp.html
title: verify/aizu_online_judge/grl/height_of_a_tree.test.cpp
---