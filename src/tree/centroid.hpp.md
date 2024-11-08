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
    path: verify/unit_test/tree/centroid.test.cpp
    title: verify/unit_test/tree/centroid.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/graph/graph_template.hpp\"\
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
    \    stack<pair<int, int>> st;\n    st.emplace(0, -1);\n    vector<int> sz(n),\
    \ par(n);\n    while(!st.empty()) {\n        const pair<int, int> p = st.top();\n\
    \        if(sz[p.first] == 0) {\n            sz[p.first] = 1;\n            for(const\
    \ Edge<T>& e : g[p.first]) {\n                if(e.to != p.second) {\n       \
    \             st.emplace(e.to, p.first);\n                }\n            }\n \
    \       } else {\n            for(const Edge<T>& e : g[p.first]) {\n         \
    \       if(e.to != p.second) {\n                    sz[p.first] += sz[e.to];\n\
    \                }\n            }\n            par[p.first] = p.second;\n    \
    \        st.pop();\n        }\n    }\n    vector<int> ret;\n    int size = n;\n\
    \    for(int i = 0; i < n; ++i) {\n        int val = n - sz[i];\n        for(const\
    \ Edge<T>& e : g[i]) {\n            if(e.to != par[i]) {\n                val\
    \ = max(val, sz[e.to]);\n            }\n        }\n        if(val < size) size\
    \ = val, ret.clear();\n        if(val == size) ret.emplace_back(i);\n    }\n \
    \   return ret;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../graph/graph_template.hpp\"\
    \ntemplate <typename T>\nvector<int> centroid(const Graph<T>& g) {\n    const\
    \ int n = g.size();\n    stack<pair<int, int>> st;\n    st.emplace(0, -1);\n \
    \   vector<int> sz(n), par(n);\n    while(!st.empty()) {\n        const pair<int,\
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
    \    }\n    return ret;\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: false
  path: src/tree/centroid.hpp
  requiredBy: []
  timestamp: '2024-11-09 00:36:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/unit_test/tree/centroid.test.cpp
documentation_of: src/tree/centroid.hpp
layout: document
title: centroid
---

## centroid

```cpp
vector<int> centroid(Graph<T> g)
```

$n$ 頂点の木 `g` の重心を全て返します．

頂点 $v$ が $n$ 頂点の木 `g` の重心であるとは，頂点 $v$ を取り除いたときにできる連結成分の大きさの最大値が $n / 2$ 以下であることを指します．<br>
任意の木には重心が $1$ つ，または $2$ つ存在します．

**制約**

- `g` は木である

**計算量**

- $O(n)$