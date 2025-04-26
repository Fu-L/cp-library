---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/biconnected_components.hpp
    title: BiconnectedComponents
  - icon: ':heavy_check_mark:'
    path: src/graph/two_edge_connected_components.hpp
    title: TwoEdgeConnectedComponents
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/articulation_points.test.cpp
    title: verify/aizu_online_judge/grl/articulation_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/bridges.test.cpp
    title: verify/aizu_online_judge/grl/bridges.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/biconnected_components.test.cpp
    title: verify/library_checker/graph/biconnected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/two_edge_connected_components.test.cpp
    title: verify/library_checker/graph/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n\
    #define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a,\
    \ b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
    struct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
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
    \ Edges = vector<Edge<T>>;\n#line 4 \"src/graph/low_link.hpp\"\ntemplate <typename\
    \ T>\nstruct LowLink {\n    vector<int> ord, low, articulation;\n    vector<pair<int,\
    \ int>> bridge;\n    LowLink(const Graph<T>& g)\n        : ord(g.size(), -1),\
    \ low(g.size(), -1) {\n        for(int i = 0, k = 0; i < g.size(); ++i) {\n  \
    \          if(ord[i] == -1) k = dfs(g, i, k, -1);\n        }\n    }\n\n   private:\n\
    \    int dfs(const Graph<T>& g, const int idx, int k, const int par) {\n     \
    \   low[idx] = (ord[idx] = k++);\n        int cnt = 0;\n        bool arti = false,\
    \ second = false;\n        for(const Edge<T>& e : g[idx]) {\n            const\
    \ int to = e.to;\n            if(ord[to] == -1) {\n                ++cnt;\n  \
    \              k = dfs(g, to, k, idx);\n                low[idx] = min(low[idx],\
    \ low[to]);\n                arti |= (par != -1) and (low[to] >= ord[idx]);\n\
    \                if(ord[idx] < low[to]) {\n                    bridge.emplace_back(minmax(idx,\
    \ to));\n                }\n            } else if(to != par or second) {\n   \
    \             low[idx] = min(low[idx], ord[to]);\n            } else {\n     \
    \           second = true;\n            }\n        }\n        arti |= (par ==\
    \ -1) and (cnt > 1);\n        if(arti) articulation.emplace_back(idx);\n     \
    \   return k;\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./graph_template.hpp\"\
    \ntemplate <typename T>\nstruct LowLink {\n    vector<int> ord, low, articulation;\n\
    \    vector<pair<int, int>> bridge;\n    LowLink(const Graph<T>& g)\n        :\
    \ ord(g.size(), -1), low(g.size(), -1) {\n        for(int i = 0, k = 0; i < g.size();\
    \ ++i) {\n            if(ord[i] == -1) k = dfs(g, i, k, -1);\n        }\n    }\n\
    \n   private:\n    int dfs(const Graph<T>& g, const int idx, int k, const int\
    \ par) {\n        low[idx] = (ord[idx] = k++);\n        int cnt = 0;\n       \
    \ bool arti = false, second = false;\n        for(const Edge<T>& e : g[idx]) {\n\
    \            const int to = e.to;\n            if(ord[to] == -1) {\n         \
    \       ++cnt;\n                k = dfs(g, to, k, idx);\n                low[idx]\
    \ = min(low[idx], low[to]);\n                arti |= (par != -1) and (low[to]\
    \ >= ord[idx]);\n                if(ord[idx] < low[to]) {\n                  \
    \  bridge.emplace_back(minmax(idx, to));\n                }\n            } else\
    \ if(to != par or second) {\n                low[idx] = min(low[idx], ord[to]);\n\
    \            } else {\n                second = true;\n            }\n       \
    \ }\n        arti |= (par == -1) and (cnt > 1);\n        if(arti) articulation.emplace_back(idx);\n\
    \        return k;\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/low_link.hpp
  requiredBy:
  - src/graph/two_edge_connected_components.hpp
  - src/graph/biconnected_components.hpp
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/grl/bridges.test.cpp
  - verify/aizu_online_judge/grl/articulation_points.test.cpp
  - verify/library_checker/graph/two_edge_connected_components.test.cpp
  - verify/library_checker/graph/biconnected_components.test.cpp
documentation_of: src/graph/low_link.hpp
layout: document
title: LowLink
---

# LowLink

無向グラフの橋や関節点を計算します．

橋とはグラフの辺であって，それを取り除くとグラフが非連結になるようなものです．<br>
関節点とはグラフの頂点であって，それを取り除くとグラフが非連結になるようなものです．

## コンストラクタ

```cpp
LowLink<T> lowlink(Graph<T> g)
```

- $n$ 頂点 $m$ 辺の無向グラフ `g` に対して `lowlink` の初期化を行います．

**計算量**

- $O(n + m)$

## メンバ変数

```cpp
(1) vector<int> lowlink.ord
(2) vector<int> lowlink.low
(3) vector<int> lowlink.articulation
(4) vector<pair<int, int>> lowlink.bridge
```

- (1): 頂点 `i` がDFS木上で何番目に訪れたかを保持しています．
- (2): 頂点 `i` から後退辺を高々 $1$ 回用いて到達できる頂点 $v$ について， `ord[v]` の最小値を保持しています．<br>
後退辺は今回の場合，DFS木に含まれない辺と一致します．
- (3): `g` の関節点の集合を保持しています．
- (4): `g` の橋の集合を保持しています．