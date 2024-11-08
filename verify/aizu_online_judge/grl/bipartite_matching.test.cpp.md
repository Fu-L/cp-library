---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/max_flow.hpp
    title: MaxFlow
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_7_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_7_A
  bundledCode: "#line 1 \"verify/aizu_online_judge/grl/bipartite_matching.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_7_A\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/graph/max_flow.hpp\"\
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
    };\n#line 4 \"verify/aizu_online_judge/grl/bipartite_matching.test.cpp\"\nint\
    \ main(void) {\n    int n, m, e;\n    cin >> n >> m >> e;\n    MaxFlow<int> g(n\
    \ + m + 2);\n    rep(i, 0, e) {\n        int x, y;\n        cin >> x >> y;\n \
    \       g.add_edge(x, n + y, 1);\n    }\n    rep(i, 0, n) g.add_edge(n + m, i,\
    \ 1);\n    rep(i, 0, m) g.add_edge(n + i, n + m + 1, 1);\n    cout << g.flow(n\
    \ + m, n + m + 1) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_7_A\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/max_flow.hpp\"\
    \nint main(void) {\n    int n, m, e;\n    cin >> n >> m >> e;\n    MaxFlow<int>\
    \ g(n + m + 2);\n    rep(i, 0, e) {\n        int x, y;\n        cin >> x >> y;\n\
    \        g.add_edge(x, n + y, 1);\n    }\n    rep(i, 0, n) g.add_edge(n + m, i,\
    \ 1);\n    rep(i, 0, m) g.add_edge(n + i, n + m + 1, 1);\n    cout << g.flow(n\
    \ + m, n + m + 1) << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/max_flow.hpp
  isVerificationFile: true
  path: verify/aizu_online_judge/grl/bipartite_matching.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 01:34:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu_online_judge/grl/bipartite_matching.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu_online_judge/grl/bipartite_matching.test.cpp
- /verify/verify/aizu_online_judge/grl/bipartite_matching.test.cpp.html
title: verify/aizu_online_judge/grl/bipartite_matching.test.cpp
---
