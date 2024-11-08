---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/graph/min_cost_flow.hpp
    title: MinCostFlow
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B
  bundledCode: "#line 1 \"verify/aizu_online_judge/grl/minimum_cost_flow.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/graph/min_cost_flow.hpp\"\
    \nnamespace internal {\ntemplate <class E>\nstruct csr {\n    vector<int> start;\n\
    \    vector<E> elist;\n    explicit csr(const int n, const vector<pair<int, E>>&\
    \ edges)\n        : start(n + 1), elist(edges.size()) {\n        for(const auto&\
    \ e : edges) {\n            ++start[e.first + 1];\n        }\n        for(int\
    \ i = 1; i <= n; ++i) {\n            start[i] += start[i - 1];\n        }\n  \
    \      auto counter = start;\n        for(const auto& e : edges) {\n         \
    \   elist[counter[e.first]++] = e.second;\n        }\n    }\n};\ntemplate <class\
    \ T>\nstruct simple_queue {\n    vector<T> payload;\n    int pos = 0;\n    void\
    \ reserve(const int n) {\n        payload.reserve(n);\n    }\n    int size() const\
    \ {\n        return (int)payload.size() - pos;\n    }\n    bool empty() const\
    \ {\n        return pos == (int)payload.size();\n    }\n    void push(const T&\
    \ t) {\n        payload.emplace_back(t);\n    }\n    T& front() const {\n    \
    \    return payload[pos];\n    }\n    void clear() {\n        payload.clear();\n\
    \        pos = 0;\n    }\n    void pop() {\n        ++pos;\n    }\n};\n}  // namespace\
    \ internal\ntemplate <class Cap, class Cost>\nstruct MinCostFlow {\n   public:\n\
    \    MinCostFlow() {}\n    explicit MinCostFlow(const int n)\n        : _n(n)\
    \ {}\n    int add_edge(const int from, const int to, const Cap& cap, const Cost&\
    \ cost) {\n        assert(0 <= from and from < _n);\n        assert(0 <= to and\
    \ to < _n);\n        assert(0 <= cap);\n        assert(0 <= cost);\n        const\
    \ int m = (int)_edges.size();\n        _edges.push_back({from, to, cap, Cap(0),\
    \ cost});\n        return m;\n    }\n    struct edge {\n        int from, to;\n\
    \        Cap cap, flow;\n        Cost cost;\n    };\n    edge get_edge(const int\
    \ i) const {\n        const int m = (int)_edges.size();\n        assert(0 <= i\
    \ and i < m);\n        return _edges[i];\n    }\n    vector<edge> edges() const\
    \ {\n        return _edges;\n    }\n    pair<Cap, Cost> flow(const int s, const\
    \ int t) {\n        return flow(s, t, numeric_limits<Cap>::max());\n    }\n  \
    \  pair<Cap, Cost> flow(const int s, const int t, const Cap& flow_limit) {\n \
    \       return slope(s, t, flow_limit).back();\n    }\n    vector<pair<Cap, Cost>>\
    \ slope(const int s, const int t) {\n        return slope(s, t, numeric_limits<Cap>::max());\n\
    \    }\n    vector<pair<Cap, Cost>> slope(const int s, const int t, const Cap&\
    \ flow_limit) {\n        assert(0 <= s and s < _n);\n        assert(0 <= t and\
    \ t < _n);\n        assert(s != t);\n        const int m = (int)_edges.size();\n\
    \        vector<int> edge_idx(m);\n        auto g = [&]() {\n            vector<int>\
    \ degree(_n), redge_idx(m);\n            vector<pair<int, _edge>> elist;\n   \
    \         elist.reserve(2 * m);\n            for(int i = 0; i < m; ++i) {\n  \
    \              const auto e = _edges[i];\n                edge_idx[i] = degree[e.from]++;\n\
    \                redge_idx[i] = degree[e.to]++;\n                elist.push_back({e.from,\
    \ {e.to, -1, e.cap - e.flow, e.cost}});\n                elist.push_back({e.to,\
    \ {e.from, -1, e.flow, -e.cost}});\n            }\n            auto _g = internal::csr<_edge>(_n,\
    \ elist);\n            for(int i = 0; i < m; ++i) {\n                const auto\
    \ e = _edges[i];\n                edge_idx[i] += _g.start[e.from];\n         \
    \       redge_idx[i] += _g.start[e.to];\n                _g.elist[edge_idx[i]].rev\
    \ = redge_idx[i];\n                _g.elist[redge_idx[i]].rev = edge_idx[i];\n\
    \            }\n            return _g;\n        }();\n        const auto result\
    \ = slope(g, s, t, flow_limit);\n        for(int i = 0; i < m; ++i) {\n      \
    \      const auto e = g.elist[edge_idx[i]];\n            _edges[i].flow = _edges[i].cap\
    \ - e.cap;\n        }\n        return result;\n    }\n\n   private:\n    int _n;\n\
    \    vector<edge> _edges;\n    struct _edge {\n        int to, rev;\n        Cap\
    \ cap;\n        Cost cost;\n    };\n    vector<pair<Cap, Cost>> slope(internal::csr<_edge>&\
    \ g, const int s, const int t, const Cap& flow_limit) {\n        vector<pair<Cost,\
    \ Cost>> dual_dist(_n);\n        vector<int> prev_e(_n);\n        vector<bool>\
    \ vis(_n);\n        struct Q {\n            Cost key;\n            int to;\n \
    \           inline bool operator<(const Q& r) const {\n                return\
    \ key > r.key;\n            }\n        };\n        vector<int> que_min;\n    \
    \    vector<Q> que;\n        auto dual_ref = [&]() {\n            for(int i =\
    \ 0; i < _n; ++i) {\n                dual_dist[i].second = numeric_limits<Cost>::max();\n\
    \            }\n            fill(vis.begin(), vis.end(), false);\n           \
    \ que_min.clear();\n            que.clear();\n            size_t heap_r = 0;\n\
    \            dual_dist[s].second = 0;\n            que_min.emplace_back(s);\n\
    \            while(!que_min.empty() or !que.empty()) {\n                int v;\n\
    \                if(!que_min.empty()) {\n                    v = que_min.back();\n\
    \                    que_min.pop_back();\n                } else {\n         \
    \           while(heap_r < que.size()) {\n                        ++heap_r;\n\
    \                        push_heap(que.begin(), que.begin() + heap_r);\n     \
    \               }\n                    v = que.front().to;\n                 \
    \   pop_heap(que.begin(), que.end());\n                    que.pop_back();\n \
    \                   --heap_r;\n                }\n                if(vis[v]) continue;\n\
    \                vis[v] = true;\n                if(v == t) break;\n         \
    \       const Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;\n\
    \                for(int i = g.start[v]; i < g.start[v + 1]; ++i) {\n        \
    \            const auto e = g.elist[i];\n                    if(!e.cap) continue;\n\
    \                    const Cost cost = e.cost - dual_dist[e.to].first + dual_v;\n\
    \                    if(dual_dist[e.to].second - dist_v > cost) {\n          \
    \              const Cost dist_to = dist_v + cost;\n                        dual_dist[e.to].second\
    \ = dist_to;\n                        prev_e[e.to] = e.rev;\n                \
    \        if(dist_to == dist_v) {\n                            que_min.emplace_back(e.to);\n\
    \                        } else {\n                            que.push_back({dist_to,\
    \ e.to});\n                        }\n                    }\n                }\n\
    \            }\n            if(!vis[t]) {\n                return false;\n   \
    \         }\n            for(int v = 0; v < _n; ++v) {\n                if(!vis[v])\
    \ continue;\n                dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;\n\
    \            }\n            return true;\n        };\n        Cap flow = 0;\n\
    \        Cost cost = 0, prev_cost_per_flow = -1;\n        vector<pair<Cap, Cost>>\
    \ result = {{Cap(0), Cost(0)}};\n        while(flow < flow_limit) {\n        \
    \    if(!dual_ref()) break;\n            Cap c = flow_limit - flow;\n        \
    \    for(int v = t; v != s; v = g.elist[prev_e[v]].to) {\n                c =\
    \ min(c, g.elist[g.elist[prev_e[v]].rev].cap);\n            }\n            for(int\
    \ v = t; v != s; v = g.elist[prev_e[v]].to) {\n                auto& e = g.elist[prev_e[v]];\n\
    \                e.cap += c;\n                g.elist[e.rev].cap -= c;\n     \
    \       }\n            const Cost d = -dual_dist[s].first;\n            flow +=\
    \ c;\n            cost += c * d;\n            if(prev_cost_per_flow == d) {\n\
    \                result.pop_back();\n            }\n            result.emplace_back(flow,\
    \ cost);\n            prev_cost_per_flow = d;\n        }\n        return result;\n\
    \    }\n};\n#line 4 \"verify/aizu_online_judge/grl/minimum_cost_flow.test.cpp\"\
    \nint main(void) {\n    int n, m, f;\n    cin >> n >> m >> f;\n    MinCostFlow<int,\
    \ int> g(n);\n    rep(i, 0, m) {\n        int u, v, c, d;\n        cin >> u >>\
    \ v >> c >> d;\n        g.add_edge(u, v, c, d);\n    }\n    pair<int, int> ans\
    \ = g.flow(0, n - 1, f);\n    if(ans.first == f) {\n        cout << ans.second\
    \ << '\\n';\n    } else {\n        cout << -1 << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/min_cost_flow.hpp\"\
    \nint main(void) {\n    int n, m, f;\n    cin >> n >> m >> f;\n    MinCostFlow<int,\
    \ int> g(n);\n    rep(i, 0, m) {\n        int u, v, c, d;\n        cin >> u >>\
    \ v >> c >> d;\n        g.add_edge(u, v, c, d);\n    }\n    pair<int, int> ans\
    \ = g.flow(0, n - 1, f);\n    if(ans.first == f) {\n        cout << ans.second\
    \ << '\\n';\n    } else {\n        cout << -1 << '\\n';\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/min_cost_flow.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/grl/minimum_cost_flow.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/grl/minimum_cost_flow.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/grl/minimum_cost_flow.test.cpp
- /verify/verify/aizu_online_judge/grl/minimum_cost_flow.test.cpp.html
title: verify/aizu_online_judge/grl/minimum_cost_flow.test.cpp
---
