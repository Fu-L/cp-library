---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/graph/max_matching.hpp
    title: max_matching
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/graph/max_matching.test.cpp\"\n#define\
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
    verify/unit_test/graph/max_matching.test.cpp\"\nint brute_max_matching(const int\
    \ n, const vector<pair<int, int>>& es) {\n    const int m = es.size();\n    int\
    \ res = 0;\n    for(int bit = 0; bit < (1 << m); ++bit) {\n        vector<int>\
    \ used(n, false);\n        int cnt = 0;\n        bool ok = true;\n        for(int\
    \ i = 0; i < m; ++i) {\n            if(!(bit >> i & 1)) continue;\n          \
    \  const auto& [u, v] = es[i];\n            if(used[u] or used[v]) {\n       \
    \         ok = false;\n                break;\n            }\n            used[u]\
    \ = used[v] = true;\n            ++cnt;\n        }\n        if(ok) res = max(res,\
    \ cnt);\n    }\n    return res;\n}\nint main() {\n    int a, b;\n    cin >> a\
    \ >> b;\n    cout << a + b << '\\n';\n    mt19937 rng(12345);\n    rep(n, 1, 9)\
    \ {\n        vector<pair<int, int>> all_edges;\n        rep(i, 0, n) rep(j, i\
    \ + 1, n) all_edges.emplace_back(i, j);\n        rep(_, 0, 200) {\n          \
    \  Edges<int> input;\n            vector<pair<int, int>> es;\n            for(const\
    \ auto& [u, v] : all_edges) {\n                if((rng() & 1) == 0) continue;\n\
    \                input.emplace_back(u, v, 1);\n                es.emplace_back(u,\
    \ v);\n            }\n            const auto got = max_matching(n, input);\n \
    \           assert((int)got.size() == brute_max_matching(n, es));\n          \
    \  vector<int> used(n, false);\n            for(const auto& e : got) {\n     \
    \           assert(0 <= e.from and e.from < n);\n                assert(0 <= e.to\
    \ and e.to < n);\n                assert(!used[e.from]);\n                assert(!used[e.to]);\n\
    \                used[e.from] = used[e.to] = true;\n            }\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/graph/graph_template.hpp\"\n#include \"../../../src/graph/max_matching.hpp\"\
    \nint brute_max_matching(const int n, const vector<pair<int, int>>& es) {\n  \
    \  const int m = es.size();\n    int res = 0;\n    for(int bit = 0; bit < (1 <<\
    \ m); ++bit) {\n        vector<int> used(n, false);\n        int cnt = 0;\n  \
    \      bool ok = true;\n        for(int i = 0; i < m; ++i) {\n            if(!(bit\
    \ >> i & 1)) continue;\n            const auto& [u, v] = es[i];\n            if(used[u]\
    \ or used[v]) {\n                ok = false;\n                break;\n       \
    \     }\n            used[u] = used[v] = true;\n            ++cnt;\n        }\n\
    \        if(ok) res = max(res, cnt);\n    }\n    return res;\n}\nint main() {\n\
    \    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n    mt19937 rng(12345);\n\
    \    rep(n, 1, 9) {\n        vector<pair<int, int>> all_edges;\n        rep(i,\
    \ 0, n) rep(j, i + 1, n) all_edges.emplace_back(i, j);\n        rep(_, 0, 200)\
    \ {\n            Edges<int> input;\n            vector<pair<int, int>> es;\n \
    \           for(const auto& [u, v] : all_edges) {\n                if((rng() &\
    \ 1) == 0) continue;\n                input.emplace_back(u, v, 1);\n         \
    \       es.emplace_back(u, v);\n            }\n            const auto got = max_matching(n,\
    \ input);\n            assert((int)got.size() == brute_max_matching(n, es));\n\
    \            vector<int> used(n, false);\n            for(const auto& e : got)\
    \ {\n                assert(0 <= e.from and e.from < n);\n                assert(0\
    \ <= e.to and e.to < n);\n                assert(!used[e.from]);\n           \
    \     assert(!used[e.to]);\n                used[e.from] = used[e.to] = true;\n\
    \            }\n        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/graph/graph_template.hpp
  - src/graph/max_matching.hpp
  isVerificationFile: true
  path: verify/unit_test/graph/max_matching.test.cpp
  requiredBy: []
  timestamp: '2026-07-04 16:35:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/graph/max_matching.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/graph/max_matching.test.cpp
- /verify/verify/unit_test/graph/max_matching.test.cpp.html
title: verify/unit_test/graph/max_matching.test.cpp
---
