---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/bipartite_matching.test.cpp
    title: verify/aizu_online_judge/grl/bipartite_matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/maximum_flow.test.cpp
    title: verify/aizu_online_judge/grl/maximum_flow.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/matching_on_bipartite_graph.test.cpp
    title: verify/library_checker/graph/matching_on_bipartite_graph.test.cpp
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
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/graph/max_flow.hpp\"\
    \ntemplate <typename Cap>\nstruct MaxFlow {\n    MaxFlow(int N)\n        : n(N),\
    \ g(N) {}\n    int add_edge(const int from, const int to, const Cap& cap) {\n\
    \        assert(0 <= from and from < n);\n        assert(0 <= to and to < n);\n\
    \        assert(0 <= cap);\n        const int m = (int)pos.size();\n        pos.emplace_back(from,\
    \ (int)g[from].size());\n        const int from_id = (int)g[from].size();\n  \
    \      int to_id = (int)g[to].size();\n        if(from == to) ++to_id;\n     \
    \   g[from].push_back({to, to_id, cap});\n        g[to].push_back({from, from_id,\
    \ Cap(0)});\n        return m;\n    }\n    struct edge {\n        int from, to;\n\
    \        Cap cap, flow;\n    };\n    edge get_edge(const int i) const {\n    \
    \    const int m = (int)pos.size();\n        assert(0 <= i and i < m);\n     \
    \   const auto _e = g[pos[i].first][pos[i].second];\n        const auto _re =\
    \ g[_e.to][_e.rev];\n        return edge{pos[i].first, _e.to, _e.cap + _re.cap,\
    \ _re.cap};\n    }\n    vector<edge> edges() const {\n        const int m = (int)pos.size();\n\
    \        vector<edge> result;\n        for(int i = 0; i < m; ++i) {\n        \
    \    result.emplace_back(get_edge(i));\n        }\n        return result;\n  \
    \  }\n    void change_edge(const int i, const Cap& new_cap, const Cap& new_flow)\
    \ {\n        const int m = (int)pos.size();\n        assert(0 <= i and i < m);\n\
    \        assert(0 <= new_flow and new_flow <= new_cap);\n        auto& _e = g[pos[i].first][pos[i].second];\n\
    \        auto& _re = g[_e.to][_e.rev];\n        _e.cap = new_cap - new_flow;\n\
    \        _re.cap = new_flow;\n    }\n    Cap flow(const int s, const int t) {\n\
    \        return flow(s, t, numeric_limits<Cap>::max());\n    }\n    Cap flow(const\
    \ int s, const int t, const Cap& flow_limit) {\n        assert(0 <= s and s <\
    \ n);\n        assert(0 <= t and t < n);\n        assert(s != t);\n        vector<int>\
    \ level(n), iter(n);\n        queue<int> que;\n        auto bfs = [&]() -> void\
    \ {\n            fill(level.begin(), level.end(), -1);\n            level[s] =\
    \ 0;\n            queue<int>().swap(que);\n            que.emplace(s);\n     \
    \       while(!que.empty()) {\n                const int v = que.front();\n  \
    \              que.pop();\n                for(const auto& e : g[v]) {\n     \
    \               if(e.cap == 0 or level[e.to] >= 0) continue;\n               \
    \     level[e.to] = level[v] + 1;\n                    if(e.to == t) return;\n\
    \                    que.emplace(e.to);\n                }\n            }\n  \
    \      };\n        auto dfs = [&](const auto& dfs, const int v, const Cap& up)\
    \ -> Cap {\n            if(v == s) return up;\n            Cap res = 0;\n    \
    \        const int level_v = level[v];\n            for(int& i = iter[v]; i <\
    \ (int)g[v].size(); ++i) {\n                const _edge& e = g[v][i];\n      \
    \          if(level_v <= level[e.to] or g[e.to][e.rev].cap == 0) continue;\n \
    \               const Cap d = dfs(dfs, e.to, min(up - res, g[e.to][e.rev].cap));\n\
    \                if(d <= 0) continue;\n                g[v][i].cap += d;\n   \
    \             g[e.to][e.rev].cap -= d;\n                res += d;\n          \
    \      if(res == up) return res;\n            }\n            level[v] = n;\n \
    \           return res;\n        };\n        Cap flow = 0;\n        while(flow\
    \ < flow_limit) {\n            bfs();\n            if(level[t] == -1) break;\n\
    \            fill(iter.begin(), iter.end(), 0);\n            const Cap f = dfs(dfs,\
    \ t, flow_limit - flow);\n            if(!f) break;\n            flow += f;\n\
    \        }\n        return flow;\n    }\n    vector<bool> min_cut(const int s)\
    \ const {\n        vector<bool> visited(n);\n        queue<int> que;\n       \
    \ que.emplace(s);\n        while(!que.empty()) {\n            const int p = que.front();\n\
    \            que.pop();\n            visited[p] = true;\n            for(const\
    \ auto& e : g[p]) {\n                if(e.cap and !visited[e.to]) {\n        \
    \            visited[e.to] = true;\n                    que.emplace(e.to);\n \
    \               }\n            }\n        }\n        return visited;\n    }\n\n\
    \   private:\n    struct _edge {\n        int to, rev;\n        Cap cap;\n   \
    \ };\n    int n;\n    vector<pair<int, int>> pos;\n    vector<vector<_edge>> g;\n\
    };\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <typename Cap>\n\
    struct MaxFlow {\n    MaxFlow(int N)\n        : n(N), g(N) {}\n    int add_edge(const\
    \ int from, const int to, const Cap& cap) {\n        assert(0 <= from and from\
    \ < n);\n        assert(0 <= to and to < n);\n        assert(0 <= cap);\n    \
    \    const int m = (int)pos.size();\n        pos.emplace_back(from, (int)g[from].size());\n\
    \        const int from_id = (int)g[from].size();\n        int to_id = (int)g[to].size();\n\
    \        if(from == to) ++to_id;\n        g[from].push_back({to, to_id, cap});\n\
    \        g[to].push_back({from, from_id, Cap(0)});\n        return m;\n    }\n\
    \    struct edge {\n        int from, to;\n        Cap cap, flow;\n    };\n  \
    \  edge get_edge(const int i) const {\n        const int m = (int)pos.size();\n\
    \        assert(0 <= i and i < m);\n        const auto _e = g[pos[i].first][pos[i].second];\n\
    \        const auto _re = g[_e.to][_e.rev];\n        return edge{pos[i].first,\
    \ _e.to, _e.cap + _re.cap, _re.cap};\n    }\n    vector<edge> edges() const {\n\
    \        const int m = (int)pos.size();\n        vector<edge> result;\n      \
    \  for(int i = 0; i < m; ++i) {\n            result.emplace_back(get_edge(i));\n\
    \        }\n        return result;\n    }\n    void change_edge(const int i, const\
    \ Cap& new_cap, const Cap& new_flow) {\n        const int m = (int)pos.size();\n\
    \        assert(0 <= i and i < m);\n        assert(0 <= new_flow and new_flow\
    \ <= new_cap);\n        auto& _e = g[pos[i].first][pos[i].second];\n        auto&\
    \ _re = g[_e.to][_e.rev];\n        _e.cap = new_cap - new_flow;\n        _re.cap\
    \ = new_flow;\n    }\n    Cap flow(const int s, const int t) {\n        return\
    \ flow(s, t, numeric_limits<Cap>::max());\n    }\n    Cap flow(const int s, const\
    \ int t, const Cap& flow_limit) {\n        assert(0 <= s and s < n);\n       \
    \ assert(0 <= t and t < n);\n        assert(s != t);\n        vector<int> level(n),\
    \ iter(n);\n        queue<int> que;\n        auto bfs = [&]() -> void {\n    \
    \        fill(level.begin(), level.end(), -1);\n            level[s] = 0;\n  \
    \          queue<int>().swap(que);\n            que.emplace(s);\n            while(!que.empty())\
    \ {\n                const int v = que.front();\n                que.pop();\n\
    \                for(const auto& e : g[v]) {\n                    if(e.cap ==\
    \ 0 or level[e.to] >= 0) continue;\n                    level[e.to] = level[v]\
    \ + 1;\n                    if(e.to == t) return;\n                    que.emplace(e.to);\n\
    \                }\n            }\n        };\n        auto dfs = [&](const auto&\
    \ dfs, const int v, const Cap& up) -> Cap {\n            if(v == s) return up;\n\
    \            Cap res = 0;\n            const int level_v = level[v];\n       \
    \     for(int& i = iter[v]; i < (int)g[v].size(); ++i) {\n                const\
    \ _edge& e = g[v][i];\n                if(level_v <= level[e.to] or g[e.to][e.rev].cap\
    \ == 0) continue;\n                const Cap d = dfs(dfs, e.to, min(up - res,\
    \ g[e.to][e.rev].cap));\n                if(d <= 0) continue;\n              \
    \  g[v][i].cap += d;\n                g[e.to][e.rev].cap -= d;\n             \
    \   res += d;\n                if(res == up) return res;\n            }\n    \
    \        level[v] = n;\n            return res;\n        };\n        Cap flow\
    \ = 0;\n        while(flow < flow_limit) {\n            bfs();\n            if(level[t]\
    \ == -1) break;\n            fill(iter.begin(), iter.end(), 0);\n            const\
    \ Cap f = dfs(dfs, t, flow_limit - flow);\n            if(!f) break;\n       \
    \     flow += f;\n        }\n        return flow;\n    }\n    vector<bool> min_cut(const\
    \ int s) const {\n        vector<bool> visited(n);\n        queue<int> que;\n\
    \        que.emplace(s);\n        while(!que.empty()) {\n            const int\
    \ p = que.front();\n            que.pop();\n            visited[p] = true;\n \
    \           for(const auto& e : g[p]) {\n                if(e.cap and !visited[e.to])\
    \ {\n                    visited[e.to] = true;\n                    que.emplace(e.to);\n\
    \                }\n            }\n        }\n        return visited;\n    }\n\
    \n   private:\n    struct _edge {\n        int to, rev;\n        Cap cap;\n  \
    \  };\n    int n;\n    vector<pair<int, int>> pos;\n    vector<vector<_edge>>\
    \ g;\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/graph/max_flow.hpp
  requiredBy: []
  timestamp: '2024-11-09 00:36:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/graph/matching_on_bipartite_graph.test.cpp
  - verify/aizu_online_judge/grl/bipartite_matching.test.cpp
  - verify/aizu_online_judge/grl/maximum_flow.test.cpp
documentation_of: src/graph/max_flow.hpp
layout: document
title: MaxFlow
---

# MaxFlow

[最大流問題](https://ja.wikipedia.org/wiki/%E6%9C%80%E5%A4%A7%E3%83%95%E3%83%AD%E3%83%BC%E5%95%8F%E9%A1%8C) を解くライブラリです。

## コンストラクタ

```cpp
MaxFlow<Cap> graph(int n)
```

- `n` 頂点 $0$ 辺のグラフを作ります．
- `Cap` は容量の型です．

**計算量**

- $O(n)$

## add_edge

```cpp
int graph.add_edge(int from, int to, Cap cap);
```

`from` から `to` へ最大容量 `cap` ，流量 $0$ の辺を追加し，何番目に追加された辺かを返します．

**制約**

- $0 \leq \mathrm{from}, \mathrm{to} \lt n$
- $0 \leq \mathrm{cap}$

**計算量**

- 償却 $O(1)$

## flow

```cpp
(1) Cap graph.flow(int s, int t);
(2) Cap graph.flow(int s, int t, Cap flow_limit);
```

- (1) 頂点 $s$ から $t$ へ流せる限り流し，流せた量を返します．
- (2) 頂点 $s$ から $t$ へ流量 `flow_limit` に達するまで流せる限り流し，流せた量を返します．

複数回呼ぶことも可能です．

**制約**

- $s \neq t$
- $0 \leq s, t \lt n$
- 返り値が `Cap` に収まる．

**計算量**

$m$ を追加された辺数として

- $O((n + m) \sqrt{m})$ (辺の容量がすべて $1$ の時)
- $O(n^2 m)$
- 返り値を $F$ として $O(F(n + m))$

## min_cut

```cpp
vector<bool> graph.min_cut(int s)
```

長さ $n$ のvectorを返します．<br>
$i$ 番目の要素には，頂点 $s$ から $i$ へ残余グラフで到達可能なとき，またその時のみ `true` を返します．<br>
`flow(s, t)` をflow_limitなしでちょうど一回呼んだ後に呼ぶと，返り値は $s, t$ 間のmincutに対応します．

**制約**

- $0 \leq s < n$

**計算量**

$m$ を追加された辺数として

- $O(n + m)$

## get_edge / edges

```cpp
struct MaxFlow<Cap>::edge {
    int from, to;
    Cap cap, flow;
};

(1) MaxFlow<Cap>::edge graph.get_edge(int i);
(2) vector<MaxFlow<Cap>::edge> graph.edges();
```

- 今の内部の辺の状態を返します．
- 辺の順番はadd_edgeで追加された順番と同一です．

**制約**

- (1): $0 \leq i \lt m$

**計算量**

$m$ を追加された辺数として

- (1): $O(1)$
- (2): $O(m)$

## change_edge

```cpp
void graph.change_edge(int i, Cap new_cap, Cap new_flow);
```

$i$ 番目に追加された辺の容量，流量を`new_cap` , `new_flow`に変更します．<br>
他の辺の容量，流量は変更しません．

**制約**

- $0 \leq \mathrm{newflow} \leq \mathrm{newcap}$

**計算量**

- $O(1)$