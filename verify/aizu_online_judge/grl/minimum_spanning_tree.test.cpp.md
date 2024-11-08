---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/union_find.hpp
    title: UnionFind
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/graph/kruskal.hpp
    title: kruskal
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"verify/aizu_online_judge/grl/minimum_spanning_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
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
    \ Edges = vector<Edge<T>>;\n#line 3 \"src/data_structure/union_find.hpp\"\nstruct\
    \ UnionFind {\n    UnionFind(const int N)\n        : n(N), data(N, -1) {}\n  \
    \  int merge(const int a, const int b) {\n        assert(0 <= a and a < n);\n\
    \        assert(0 <= b and b < n);\n        int x = leader(a), y = leader(b);\n\
    \        if(x == y) return x;\n        if(-data[x] < -data[y]) swap(x, y);\n \
    \       data[x] += data[y];\n        data[y] = x;\n        return x;\n    }\n\
    \    bool same(const int a, const int b) {\n        assert(0 <= a and a < n);\n\
    \        assert(0 <= b and b < n);\n        return leader(a) == leader(b);\n \
    \   }\n    int leader(const int a) {\n        assert(0 <= a and a < n);\n    \
    \    if(data[a] < 0) return a;\n        return data[a] = leader(data[a]);\n  \
    \  }\n    int size(const int a) {\n        assert(0 <= a and a < n);\n       \
    \ return -data[leader(a)];\n    }\n    vector<vector<int>> groups() {\n      \
    \  vector<int> leader_buf(n), group_size(n);\n        for(int i = 0; i < n; ++i)\
    \ {\n            leader_buf[i] = leader(i);\n            ++group_size[leader_buf[i]];\n\
    \        }\n        vector<vector<int>> result(n);\n        for(int i = 0; i <\
    \ n; ++i) {\n            result[i].reserve(group_size[i]);\n        }\n      \
    \  for(int i = 0; i < n; ++i) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(remove_if(result.begin(), result.end(), [&](const\
    \ vector<int>& v) { return v.empty(); }), result.end());\n        return result;\n\
    \    }\n\n   private:\n    int n;\n    vector<int> data;\n};\n#line 5 \"src/graph/kruskal.hpp\"\
    \ntemplate <typename T>\npair<T, Edges<T>> kruskal(const int n, Edges<T> es) {\n\
    \    sort(es.begin(), es.end(), [&](const Edge<T>& a, const Edge<T>& b) { return\
    \ a.cost < b.cost; });\n    UnionFind uf(n);\n    T cost = 0;\n    Edges<T> res;\n\
    \    res.reserve(n - 1);\n    for(const Edge<T>& e : es) {\n        if(uf.same(e.from,\
    \ e.to)) continue;\n        cost += e.cost;\n        uf.merge(e.from, e.to);\n\
    \        res.emplace_back(e);\n    }\n    return {cost, res};\n}\n#line 5 \"verify/aizu_online_judge/grl/minimum_spanning_tree.test.cpp\"\
    \nint main(void) {\n    int n, m;\n    cin >> n >> m;\n    Edges<int> e(m);\n\
    \    rep(i, 0, m) {\n        cin >> e[i].from >> e[i].to >> e[i].cost;\n     \
    \   e[i].idx = i;\n    }\n    cout << kruskal(n, e).first << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/graph/kruskal.hpp\"\nint main(void) {\n    int n, m;\n\
    \    cin >> n >> m;\n    Edges<int> e(m);\n    rep(i, 0, m) {\n        cin >>\
    \ e[i].from >> e[i].to >> e[i].cost;\n        e[i].idx = i;\n    }\n    cout <<\
    \ kruskal(n, e).first << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/graph/kruskal.hpp
  - src/data_structure/union_find.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/grl/minimum_spanning_tree.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 01:50:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/grl/minimum_spanning_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/grl/minimum_spanning_tree.test.cpp
- /verify/verify/aizu_online_judge/grl/minimum_spanning_tree.test.cpp.html
title: verify/aizu_online_judge/grl/minimum_spanning_tree.test.cpp
---
