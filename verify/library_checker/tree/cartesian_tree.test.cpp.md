---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_template.hpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  - icon: ':heavy_check_mark:'
    path: src/tree/cartesian_tree.hpp
    title: cartesian_tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"verify/library_checker/tree/cartesian_tree.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n#line 2 \"\
    src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i\
    \ = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/graph/graph_template.hpp\"\ntemplate <typename T = int>\nstruct\
    \ Edge {\n    int from, to;\n    T cost;\n    int idx;\n    Edge()\n        :\
    \ from(-1), to(-1), cost(-1), idx(-1) {}\n    Edge(int from, int to, T cost =\
    \ 1, int idx = -1)\n        : from(from), to(to), cost(cost), idx(idx) {}\n  \
    \  operator int() const {\n        return to;\n    }\n};\ntemplate <typename T\
    \ = int>\nstruct Graph {\n    Graph(int N)\n        : n(N), es(0), g(N) {}\n \
    \   int size() const {\n        return n;\n    }\n    int edge_size() const {\n\
    \        return es;\n    }\n    void add_edge(int from, int to, T cost = 1) {\n\
    \        assert(0 <= from and from < n);\n        assert(0 <= to and to < n);\n\
    \        g[from].emplace_back(from, to, cost, es);\n        g[to].emplace_back(to,\
    \ from, cost, es++);\n    }\n    void add_directed_edge(int from, int to, T cost\
    \ = 1) {\n        assert(0 <= from and from < n);\n        assert(0 <= to and\
    \ to < n);\n        g[from].emplace_back(from, to, cost, es++);\n    }\n    inline\
    \ vector<Edge<T>>& operator[](const int& k) {\n        assert(0 <= k and k < n);\n\
    \        return g[k];\n    }\n    inline const vector<Edge<T>>& operator[](const\
    \ int& k) const {\n        assert(0 <= k and k < n);\n        return g[k];\n \
    \   }\n\n   private:\n    int n, es;\n    vector<vector<Edge<T>>> g;\n};\ntemplate\
    \ <typename T = int>\nusing Edges = vector<Edge<T>>;\n#line 4 \"src/tree/cartesian_tree.hpp\"\
    \ntemplate <typename T>\npair<Graph<int>, int> cartesian_tree(const vector<T>&\
    \ a) {\n    int n = (int)a.size();\n    Graph<int> g(n);\n    vector<int> p(n,\
    \ -1), st;\n    st.reserve(n);\n    for(int i = 0; i < n; ++i) {\n        int\
    \ prv = -1;\n        while(!st.empty() and a[i] < a[st.back()]) {\n          \
    \  prv = st.back();\n            st.pop_back();\n        }\n        if(prv !=\
    \ -1) p[prv] = i;\n        if(!st.empty()) p[i] = st.back();\n        st.push_back(i);\n\
    \    }\n    int root = -1;\n    for(int i = 0; i < n; ++i) {\n        if(p[i]\
    \ != -1) g.add_directed_edge(p[i], i);\n        else root = i;\n    }\n    return\
    \ {g, root};\n}\n#line 4 \"verify/library_checker/tree/cartesian_tree.test.cpp\"\
    \nint main(void) {\n    int n;\n    cin >> n;\n    vector<int> a(n);\n    rep(i,\
    \ 0, n) cin >> a[i];\n    auto [tree, root] = cartesian_tree(a);\n    vector<int>\
    \ ans(n);\n    ans[root] = root;\n    rep(i, 0, n) {\n        for(const int to\
    \ : tree[i]) {\n            ans[to] = i;\n        }\n    }\n    rep(i, 0, n) {\n\
    \        cout << ans[i] << \" \\n\"[i + 1 == n];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/tree/cartesian_tree.hpp\"\
    \nint main(void) {\n    int n;\n    cin >> n;\n    vector<int> a(n);\n    rep(i,\
    \ 0, n) cin >> a[i];\n    auto [tree, root] = cartesian_tree(a);\n    vector<int>\
    \ ans(n);\n    ans[root] = root;\n    rep(i, 0, n) {\n        for(const int to\
    \ : tree[i]) {\n            ans[to] = i;\n        }\n    }\n    rep(i, 0, n) {\n\
    \        cout << ans[i] << \" \\n\"[i + 1 == n];\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/tree/cartesian_tree.hpp
  - src/graph/graph_template.hpp
  isVerificationFile: true
  path: verify/library_checker/tree/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2024-02-15 00:10:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/cartesian_tree.test.cpp
- /verify/verify/library_checker/tree/cartesian_tree.test.cpp.html
title: verify/library_checker/tree/cartesian_tree.test.cpp
---