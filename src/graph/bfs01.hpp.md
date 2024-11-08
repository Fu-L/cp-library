---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/unit_test/graph/bfs01.test.cpp
    title: verify/unit_test/graph/bfs01.test.cpp
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
    \ Edges = vector<Edge<T>>;\n#line 4 \"src/graph/bfs01.hpp\"\ntemplate <typename\
    \ T>\nvector<pair<T, int>> bfs01(const Graph<T>& g, const int s = 0) {\n    const\
    \ int n = g.size();\n    assert(0 <= s and s < n);\n    vector<pair<T, int>> d(n,\
    \ {numeric_limits<T>::max(), -1});\n    vector<int> visited(n);\n    deque<int>\
    \ deq;\n    d[s] = {0, -1};\n    deq.emplace_back(s);\n    while(!deq.empty())\
    \ {\n        const int cur = deq.front();\n        deq.pop_front();\n        if(visited[cur])\
    \ continue;\n        visited[cur] = 1;\n        for(const Edge<T>& e : g[cur])\
    \ {\n            if(d[e.to].first != numeric_limits<T>::max() and d[e.to].first\
    \ <= d[cur].first + e.cost) continue;\n            d[e.to] = {d[cur].first + e.cost,\
    \ cur};\n            if(e.cost == 0) {\n                deq.emplace_front(e.to);\n\
    \            } else {\n                deq.emplace_back(e.to);\n            }\n\
    \        }\n    }\n    return d;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./graph_template.hpp\"\
    \ntemplate <typename T>\nvector<pair<T, int>> bfs01(const Graph<T>& g, const int\
    \ s = 0) {\n    const int n = g.size();\n    assert(0 <= s and s < n);\n    vector<pair<T,\
    \ int>> d(n, {numeric_limits<T>::max(), -1});\n    vector<int> visited(n);\n \
    \   deque<int> deq;\n    d[s] = {0, -1};\n    deq.emplace_back(s);\n    while(!deq.empty())\
    \ {\n        const int cur = deq.front();\n        deq.pop_front();\n        if(visited[cur])\
    \ continue;\n        visited[cur] = 1;\n        for(const Edge<T>& e : g[cur])\
    \ {\n            if(d[e.to].first != numeric_limits<T>::max() and d[e.to].first\
    \ <= d[cur].first + e.cost) continue;\n            d[e.to] = {d[cur].first + e.cost,\
    \ cur};\n            if(e.cost == 0) {\n                deq.emplace_front(e.to);\n\
    \            } else {\n                deq.emplace_back(e.to);\n            }\n\
    \        }\n    }\n    return d;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/graph/bfs01.hpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/unit_test/graph/bfs01.test.cpp
documentation_of: src/graph/bfs01.hpp
layout: document
title: bfs01
---

## bfs

```cpp
vector<pair<T, int>> bfs01(Graph<T> g, int s = 0)
```

重みが $0$ と $w$ の2値であるような $n$ 頂点のグラフ `g` 上で頂点 `s` を始点とした最短経路探索を行います．<br>

返り値は長さ $n$ の `pair` 型の配列です．<br>
`pair` 型の第一要素は頂点 `s` から頂点 `i` までの最短距離を，第二要素は頂点 `i` にたどり着く直前にいた頂点番号を保持しています．

もし頂点 `i` に到達できない場合， `pair` 型の第一要素は `numeric_limits<T>::max()` で，第二要素は $-1$ です．

**制約**

- $0 \leq s < n$
- 辺の重みが $0$ か $w$ かのいずれかである ( `assert` 等で検知されません)．

**計算量**

- $O(E + V)$