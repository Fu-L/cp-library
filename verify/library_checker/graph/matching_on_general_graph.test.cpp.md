---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/graph/max_matching.hpp
    title: max_matching
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
    PROBLEM: https://judge.yosupo.jp/problem/general_matching
    links:
    - https://judge.yosupo.jp/problem/general_matching
  bundledCode: "#line 1 \"verify/library_checker/graph/matching_on_general_graph.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/general_matching\"\n#line\
    \ 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n#line 4 \"src/template/template.hpp\"\
    \nusing namespace std;\nusing ll = long long;\nusing P = pair<long long, long\
    \ long>;\n#define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i,\
    \ a, b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
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
    \ Edges = vector<Edge<T>>;\n#line 4 \"src/graph/max_matching.hpp\"\ntemplate <typename\
    \ T>\nEdges<T> max_matching(const int n, const Edges<T>& es) {\n    struct GabowEdmonds\
    \ {\n        struct AdjEdge {\n            int to, id;\n        };\n        int\
    \ n, offset;\n        vector<vector<AdjEdge>> g;\n        vector<pair<int, int>>\
    \ edges;\n        vector<int> mate, label, first, que;\n        GabowEdmonds(const\
    \ int n)\n            : n(n), offset(n + 1), g(n + 1), mate(n + 1), label(n +\
    \ 1, -1), first(n + 1) {\n            que.reserve(n + 1);\n        }\n       \
    \ void add_edge(int u, int v) {\n            ++u;\n            ++v;\n        \
    \    const int id = offset + (int)edges.size();\n            g[u].push_back({v,\
    \ id});\n            g[v].push_back({u, id});\n            edges.emplace_back(u,\
    \ v);\n        }\n        int find(const int v) {\n            if(label[first[v]]\
    \ < 0) return first[v];\n            return first[v] = find(first[v]);\n     \
    \   }\n        void rematch(const int v, const int w) {\n            const int\
    \ t = mate[v];\n            mate[v] = w;\n            if(mate[t] != v) return;\n\
    \            if(label[v] < offset) {\n                mate[t] = label[v];\n  \
    \              rematch(label[v], t);\n            } else {\n                const\
    \ auto& [x, y] = edges[label[v] - offset];\n                rematch(x, y);\n \
    \               rematch(y, x);\n            }\n        }\n        void assign_label(const\
    \ int x, const int y, const int id) {\n            int r = find(x), s = find(y);\n\
    \            if(r == s) return;\n            int join = 0;\n            label[r]\
    \ = label[s] = -id;\n            while(true) {\n                if(s != 0) swap(r,\
    \ s);\n                r = find(label[mate[r]]);\n                if(label[r]\
    \ == -id) {\n                    join = r;\n                    break;\n     \
    \           }\n                label[r] = -id;\n            }\n            int\
    \ v = first[x];\n            while(v != join) {\n                que.push_back(v);\n\
    \                label[v] = id;\n                first[v] = join;\n          \
    \      v = first[label[mate[v]]];\n            }\n            v = first[y];\n\
    \            while(v != join) {\n                que.push_back(v);\n         \
    \       label[v] = id;\n                first[v] = join;\n                v =\
    \ first[label[mate[v]]];\n            }\n        }\n        bool augment(const\
    \ int root) {\n            int head = 0;\n            que.clear();\n         \
    \   first[root] = 0;\n            label[root] = 0;\n            que.push_back(root);\n\
    \            while(head < (int)que.size()) {\n                const int v = que[head++];\n\
    \                for(const AdjEdge& e : g[v]) {\n                    const int\
    \ u = e.to;\n                    if(mate[u] == 0 and u != root) {\n          \
    \              mate[u] = v;\n                        rematch(v, u);\n        \
    \                return true;\n                    }\n                    if(label[u]\
    \ >= 0) {\n                        assign_label(v, u, e.id);\n               \
    \     } else if(label[mate[u]] < 0) {\n                        label[mate[u]]\
    \ = v;\n                        first[mate[u]] = u;\n                        que.push_back(mate[u]);\n\
    \                    }\n                }\n            }\n            return false;\n\
    \        }\n        vector<pair<int, int>> solve() {\n            for(int i =\
    \ 1; i <= n; ++i) {\n                if(mate[i] != 0) continue;\n            \
    \    if(augment(i)) fill(label.begin(), label.end(), -1);\n            }\n   \
    \         vector<pair<int, int>> res;\n            res.reserve(n / 2);\n     \
    \       for(int i = 1; i <= n; ++i) {\n                if(i < mate[i]) res.emplace_back(i\
    \ - 1, mate[i] - 1);\n            }\n            return res;\n        }\n    };\n\
    \    GabowEdmonds matching(n);\n    vector<int> deg(n);\n    for(const Edge<T>&\
    \ e : es) {\n        assert(e.cost == 1);\n        assert(0 <= e.from and e.from\
    \ < n);\n        assert(0 <= e.to and e.to < n);\n        if(e.from == e.to) continue;\n\
    \        ++deg[e.from];\n        ++deg[e.to];\n    }\n    for(int i = 0; i < n;\
    \ ++i) {\n        matching.g[i + 1].reserve(deg[i]);\n    }\n    for(const Edge<T>&\
    \ e : es) {\n        if(e.from != e.to) matching.add_edge(e.from, e.to);\n   \
    \ }\n    const vector<pair<int, int>> pairs = matching.solve();\n    Edges<T>\
    \ res;\n    res.reserve(pairs.size());\n    for(const auto& [u, v] : pairs) {\n\
    \        res.emplace_back(u, v, T(1));\n    }\n    return res;\n}\n#line 5 \"\
    verify/library_checker/graph/matching_on_general_graph.test.cpp\"\nint main(void)\
    \ {\n    int n, m;\n    cin >> n >> m;\n    Edges<int> e(m);\n    rep(i, 0, m)\
    \ {\n        cin >> e[i].from >> e[i].to;\n        e[i].cost = 1;\n    }\n   \
    \ Edges<int> ans = max_matching(n, e);\n    cout << ans.size() << '\\n';\n   \
    \ for(const auto& e : ans) {\n        cout << e.from << ' ' << e.to << '\\n';\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/general_matching\"\n#include\
    \ \"../../../src/graph/max_matching.hpp\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/graph/graph_template.hpp\"\nint main(void) {\n    int\
    \ n, m;\n    cin >> n >> m;\n    Edges<int> e(m);\n    rep(i, 0, m) {\n      \
    \  cin >> e[i].from >> e[i].to;\n        e[i].cost = 1;\n    }\n    Edges<int>\
    \ ans = max_matching(n, e);\n    cout << ans.size() << '\\n';\n    for(const auto&\
    \ e : ans) {\n        cout << e.from << ' ' << e.to << '\\n';\n    }\n}"
  dependsOn:
  - src/graph/max_matching.hpp
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: true
  path: verify/library_checker/graph/matching_on_general_graph.test.cpp
  requiredBy: []
  timestamp: '2026-07-04 16:19:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/matching_on_general_graph.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/matching_on_general_graph.test.cpp
- /verify/verify/library_checker/graph/matching_on_general_graph.test.cpp.html
title: verify/library_checker/graph/matching_on_general_graph.test.cpp
---
