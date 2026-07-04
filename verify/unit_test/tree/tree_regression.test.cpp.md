---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  - icon: ':heavy_check_mark:'
    path: src/tree/centroid.hpp
    title: centroid
  - icon: ':heavy_check_mark:'
    path: src/tree/centroid_decomposition.hpp
    title: centroid_decomposition
  - icon: ':heavy_check_mark:'
    path: src/tree/rerooting.hpp
    title: rerooting
  - icon: ':heavy_check_mark:'
    path: src/tree/tree_diameter.hpp
    title: tree_diameter
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/tree/tree_regression.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 4 \"src/template/template.hpp\"\nusing namespace\
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
    \ Edges = vector<Edge<T>>;\n#line 4 \"src/tree/centroid.hpp\"\ntemplate <typename\
    \ T>\nvector<int> centroid(const Graph<T>& g) {\n    const int n = g.size();\n\
    \    if(n == 0) return {};\n    stack<pair<int, int>> st;\n    st.emplace(0, -1);\n\
    \    vector<int> sz(n), par(n);\n    while(!st.empty()) {\n        const pair<int,\
    \ int> p = st.top();\n        if(sz[p.first] == 0) {\n            sz[p.first]\
    \ = 1;\n            for(const Edge<T>& e : g[p.first]) {\n                if(e.to\
    \ != p.second) {\n                    st.emplace(e.to, p.first);\n           \
    \     }\n            }\n        } else {\n            for(const Edge<T>& e : g[p.first])\
    \ {\n                if(e.to != p.second) {\n                    sz[p.first] +=\
    \ sz[e.to];\n                }\n            }\n            par[p.first] = p.second;\n\
    \            st.pop();\n        }\n    }\n    vector<int> ret;\n    int size =\
    \ n;\n    for(int i = 0; i < n; ++i) {\n        int val = n - sz[i];\n       \
    \ for(const Edge<T>& e : g[i]) {\n            if(e.to != par[i]) {\n         \
    \       val = max(val, sz[e.to]);\n            }\n        }\n        if(val <\
    \ size) size = val, ret.clear();\n        if(val == size) ret.emplace_back(i);\n\
    \    }\n    return ret;\n}\n#line 4 \"src/tree/centroid_decomposition.hpp\"\n\
    template <typename T>\npair<Graph<int>, int> centroid_decomposition(const Graph<T>&\
    \ g) {\n    const int n = g.size();\n    if(n == 0) return {Graph<int>(0), -1};\n\
    \    vector<int> sub(n);\n    vector<bool> visited(n);\n    Graph<int> tree(n);\n\
    \    auto get_size = [&](const auto& get_size, const int cur, const int par) ->\
    \ int {\n        sub[cur] = 1;\n        for(const Edge<T>& e : g[cur]) {\n   \
    \         if(e.to == par or visited[e.to]) continue;\n            sub[cur] +=\
    \ get_size(get_size, e.to, cur);\n        }\n        return sub[cur];\n    };\n\
    \    auto get_centroid = [&](const auto& get_centroid, const int cur, const int\
    \ par, const int mid) -> int {\n        for(const Edge<T>& e : g[cur]) {\n   \
    \         if(e.to == par or visited[e.to]) continue;\n            if(sub[e.to]\
    \ > mid) return get_centroid(get_centroid, e.to, cur, mid);\n        }\n     \
    \   return cur;\n    };\n    auto dfs = [&](const auto& dfs, const int cur) ->\
    \ int {\n        const int centroid = get_centroid(get_centroid, cur, -1, get_size(get_size,\
    \ cur, -1) / 2);\n        visited[centroid] = true;\n        for(const Edge<T>&\
    \ e : g[centroid]) {\n            if(visited[e.to]) continue;\n            const\
    \ int nex = dfs(dfs, e.to);\n            if(centroid != nex) tree.add_directed_edge(centroid,\
    \ nex);\n        }\n        visited[centroid] = false;\n        return centroid;\n\
    \    };\n    const int root = dfs(dfs, 0);\n    return {tree, root};\n}\n#line\
    \ 4 \"src/tree/rerooting.hpp\"\ntemplate <typename DP, typename T, typename F1,\
    \ typename F2>\nvector<DP> rerooting(const Graph<T>& g, const F1& f1, const F2&\
    \ f2, const DP& id) {\n    const int n = g.size();\n    if(n == 0) return {};\n\
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
    \ 0, -1);\n    efs(efs, 0, -1, id);\n    return dp;\n}\n#line 4 \"src/tree/tree_diameter.hpp\"\
    \ntemplate <typename T>\npair<T, vector<int>> tree_diameter(const Graph<T>& g)\
    \ {\n    const int n = g.size();\n    if(n == 0) return {T(0), {}};\n    vector<T>\
    \ depth(n);\n    vector<int> par(n);\n    auto dfs = [&](const auto& dfs, const\
    \ int v, const int p, const T& d) -> void {\n        depth[v] = d;\n        par[v]\
    \ = p;\n        for(const Edge<T>& e : g[v]) {\n            if(e.to == p) continue;\n\
    \            dfs(dfs, e.to, v, d + e.cost);\n        }\n    };\n    int s = 0;\n\
    \    for(int i = 0; i < 2; ++i) {\n        dfs(dfs, s, -1, 0);\n        T ma =\
    \ -1;\n        for(int j = 0; j < n; ++j) {\n            if(depth[j] > ma) {\n\
    \                ma = depth[j];\n                s = j;\n            }\n     \
    \   }\n    }\n    vector<int> path;\n    const T diameter = depth[s];\n    while(s\
    \ != -1) {\n        path.emplace_back(s);\n        s = par[s];\n    }\n    return\
    \ {diameter, path};\n}\n#line 8 \"verify/unit_test/tree/tree_regression.test.cpp\"\
    \nint main() {\n    Graph<int> empty(0);\n    assert(centroid(empty).empty());\n\
    \    {\n        auto [g, root] = centroid_decomposition(empty);\n        assert(g.size()\
    \ == 0);\n        assert(root == -1);\n    }\n    {\n        auto [d, path] =\
    \ tree_diameter(empty);\n        assert(d == 0);\n        assert(path.empty());\n\
    \    }\n    auto f1 = [](int a, int b) { return a + b; };\n    auto f2 = [](int\
    \ a, int, int) { return a + 1; };\n    assert((rerooting<int, int>(empty, f1,\
    \ f2, 0).empty()));\n    Graph<int> one(1);\n    assert(centroid(one) == vector<int>{0});\n\
    \    auto [d, path] = tree_diameter(one);\n    assert(d == 0);\n    assert(path\
    \ == vector<int>{0});\n    int a, b;\n    cin >> a >> b;\n    cout << a + b <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/graph/graph_template.hpp\"\n#include \"../../../src/tree/centroid.hpp\"\
    \n#include \"../../../src/tree/centroid_decomposition.hpp\"\n#include \"../../../src/tree/rerooting.hpp\"\
    \n#include \"../../../src/tree/tree_diameter.hpp\"\nint main() {\n    Graph<int>\
    \ empty(0);\n    assert(centroid(empty).empty());\n    {\n        auto [g, root]\
    \ = centroid_decomposition(empty);\n        assert(g.size() == 0);\n        assert(root\
    \ == -1);\n    }\n    {\n        auto [d, path] = tree_diameter(empty);\n    \
    \    assert(d == 0);\n        assert(path.empty());\n    }\n    auto f1 = [](int\
    \ a, int b) { return a + b; };\n    auto f2 = [](int a, int, int) { return a +\
    \ 1; };\n    assert((rerooting<int, int>(empty, f1, f2, 0).empty()));\n    Graph<int>\
    \ one(1);\n    assert(centroid(one) == vector<int>{0});\n    auto [d, path] =\
    \ tree_diameter(one);\n    assert(d == 0);\n    assert(path == vector<int>{0});\n\
    \    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/tree/centroid.hpp
  - src/tree/centroid_decomposition.hpp
  - src/tree/rerooting.hpp
  - src/tree/tree_diameter.hpp
  isVerificationFile: true
  path: verify/unit_test/tree/tree_regression.test.cpp
  requiredBy: []
  timestamp: '2026-07-04 16:35:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/tree/tree_regression.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/tree/tree_regression.test.cpp
- /verify/verify/unit_test/tree/tree_regression.test.cpp.html
title: verify/unit_test/tree/tree_regression.test.cpp
---
