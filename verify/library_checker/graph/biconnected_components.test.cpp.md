---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/biconnected_components.hpp
    title: BiconnectedComponents
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/graph/low_link.hpp
    title: LowLink
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
    PROBLEM: https://judge.yosupo.jp/problem/biconnected_components
    links:
    - https://judge.yosupo.jp/problem/biconnected_components
  bundledCode: "#line 1 \"verify/library_checker/graph/biconnected_components.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\n\
    #line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
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
    using Edges = vector<Edge<T>>;\n#line 4 \"src/graph/low_link.hpp\"\ntemplate <typename\
    \ T>\nstruct LowLink {\n    vector<int> ord, low, articulation;\n    vector<pair<int,\
    \ int>> bridge;\n    LowLink(const Graph<T>& g)\n        : ord(g.size(), -1),\
    \ low(g.size(), -1) {\n        for(int i = 0, k = 0; i < (int)g.size(); ++i) {\n\
    \            if(ord[i] == -1) k = dfs(g, i, k, -1);\n        }\n    }\n\n   private:\n\
    \    int dfs(const Graph<T>& g, int idx, int k, int par) {\n        low[idx] =\
    \ (ord[idx] = k++);\n        int cnt = 0;\n        bool arti = false, second =\
    \ false;\n        for(const int to : g[idx]) {\n            if(ord[to] == -1)\
    \ {\n                ++cnt;\n                k = dfs(g, to, k, idx);\n       \
    \         low[idx] = min(low[idx], low[to]);\n                arti |= (par !=\
    \ -1) and (low[to] >= ord[idx]);\n                if(ord[idx] < low[to]) {\n \
    \                   bridge.emplace_back(minmax(idx, to));\n                }\n\
    \            } else if(to != par or second) {\n                low[idx] = min(low[idx],\
    \ ord[to]);\n            } else {\n                second = true;\n          \
    \  }\n        }\n        arti |= (par == -1) and (cnt > 1);\n        if(arti)\
    \ articulation.push_back(idx);\n        return k;\n    }\n};\n#line 5 \"src/graph/biconnected_components.hpp\"\
    \ntemplate <typename T>\nstruct BiconnectedComponents {\n    vector<vector<pair<int,\
    \ int>>> bc;\n    BiconnectedComponents(const Graph<T>& g)\n        : n(g.size()),\
    \ lowlink(g), used(n) {\n        for(int i = 0; i < n; ++i) {\n            if(!used[i])\
    \ dfs(g, i, -1);\n        }\n    }\n\n   private:\n    int n;\n    LowLink<T>\
    \ lowlink;\n    vector<int> used;\n    vector<pair<int, int>> tmp;\n    void dfs(const\
    \ Graph<T>& g, int idx, int par) {\n        used[idx] = true;\n        for(const\
    \ int to : g[idx]) {\n            if(to == par) continue;\n            if(!used[to]\
    \ or lowlink.ord[to] < lowlink.ord[idx]) {\n                tmp.emplace_back(minmax(idx,\
    \ to));\n            }\n            if(!used[to]) {\n                dfs(g, to,\
    \ idx);\n                if(lowlink.low[to] >= lowlink.ord[idx]) {\n         \
    \           bc.emplace_back();\n                    while(true) {\n          \
    \              auto e = tmp.back();\n                        bc.back().emplace_back(e);\n\
    \                        tmp.pop_back();\n                        if(e.first ==\
    \ min(idx, to) and e.second == max(idx, to)) break;\n                    }\n \
    \               }\n            }\n        }\n    }\n};\n#line 5 \"verify/library_checker/graph/biconnected_components.test.cpp\"\
    \nint main(void) {\n    int n, m;\n    cin >> n >> m;\n    Graph<int> g(n);\n\
    \    rep(i, 0, m) {\n        int a, b;\n        cin >> a >> b;\n        g.add_edge(a,\
    \ b);\n    }\n    BiconnectedComponents<int> low(g);\n    vector<vector<int>>\
    \ ans;\n    vector<bool> used(n);\n    rep(i, 0, (int)low.bc.size()) {\n     \
    \   set<int> st;\n        for(const auto& e : low.bc[i]) {\n            st.insert(e.first);\n\
    \            st.insert(e.second);\n        }\n        ans.emplace_back();\n  \
    \      for(const int val : st) {\n            ans.back().push_back(val);\n   \
    \         used[val] = true;\n        }\n    }\n    rep(i, 0, n) {\n        if(!used[i])\
    \ {\n            ans.emplace_back();\n            ans.back().push_back(i);\n \
    \       }\n    }\n    int k = ans.size();\n    cout << k << '\\n';\n    rep(i,\
    \ 0, k) {\n        int l = ans[i].size();\n        cout << l << ' ';\n       \
    \ rep(j, 0, l) {\n            cout << ans[i][j] << \" \\n\"[j + 1 == l];\n   \
    \     }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/graph/graph_template.hpp\"\
    \n#include \"../../../src/graph/biconnected_components.hpp\"\nint main(void) {\n\
    \    int n, m;\n    cin >> n >> m;\n    Graph<int> g(n);\n    rep(i, 0, m) {\n\
    \        int a, b;\n        cin >> a >> b;\n        g.add_edge(a, b);\n    }\n\
    \    BiconnectedComponents<int> low(g);\n    vector<vector<int>> ans;\n    vector<bool>\
    \ used(n);\n    rep(i, 0, (int)low.bc.size()) {\n        set<int> st;\n      \
    \  for(const auto& e : low.bc[i]) {\n            st.insert(e.first);\n       \
    \     st.insert(e.second);\n        }\n        ans.emplace_back();\n        for(const\
    \ int val : st) {\n            ans.back().push_back(val);\n            used[val]\
    \ = true;\n        }\n    }\n    rep(i, 0, n) {\n        if(!used[i]) {\n    \
    \        ans.emplace_back();\n            ans.back().push_back(i);\n        }\n\
    \    }\n    int k = ans.size();\n    cout << k << '\\n';\n    rep(i, 0, k) {\n\
    \        int l = ans[i].size();\n        cout << l << ' ';\n        rep(j, 0,\
    \ l) {\n            cout << ans[i][j] << \" \\n\"[j + 1 == l];\n        }\n  \
    \  }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/graph/biconnected_components.hpp
  - src/graph/low_link.hpp
  isVerificationFile: true
  path: verify/library_checker/graph/biconnected_components.test.cpp
  requiredBy: []
  timestamp: '2024-01-05 02:58:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/biconnected_components.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/biconnected_components.test.cpp
- /verify/verify/library_checker/graph/biconnected_components.test.cpp.html
title: verify/library_checker/graph/biconnected_components.test.cpp
---
