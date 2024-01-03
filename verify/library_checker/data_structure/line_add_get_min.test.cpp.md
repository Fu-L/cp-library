---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/dynamic_li_chao_tree.hpp
    title: DynamicLiChaoTree
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
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"verify/library_checker/data_structure/line_add_get_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#line\
    \ 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i\
    \ = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/data_structure/dynamic_li_chao_tree.hpp\"\ntemplate <typename T,\
    \ T x_low, T x_high>\nstruct DynamicLiChaoTree {\n    DynamicLiChaoTree()\n  \
    \      : root{nullptr} {}\n    void add_line(const T &a, const T &b) {\n     \
    \   Line x(a, b);\n        root = add_line(root, x, x_low, x_high, x.get(x_low),\
    \ x.get(x_high));\n    }\n    void add_segment(const T &l, const T &r, const T\
    \ &a, const T &b) {\n        Line x(a, b);\n        root = add_segment(root, x,\
    \ l, r - 1, x_low, x_high, x.get(x_low), x.get(x_high));\n    }\n    T operator()(const\
    \ T& x) const {\n        assert(x_low <= x and x <= x_high);\n        return query(root,\
    \ x_low, x_high, x);\n    }\n\n   private:\n    struct Line {\n        T a, b;\n\
    \        Line(const T &a, const T &b)\n            : a(a), b(b) {}\n        inline\
    \ T get(const T &x) const {\n            return a * x + b;\n        }\n    };\n\
    \    struct Node {\n        Line x;\n        Node *l, *r;\n        Node(const\
    \ Line &x)\n            : x{x}, l{nullptr}, r{nullptr} {}\n    };\n    const T\
    \ id = numeric_limits<T>::max();\n    Node *root;\n    Node *add_line(Node *t,\
    \ Line &x, const T &l, const T &r, const T &x_l, const T &x_r) {\n        if(!t)\
    \ return new Node(x);\n        T t_l = t->x.get(l), t_r = t->x.get(r);\n     \
    \   if(t_l <= x_l and t_r <= x_r) {\n            return t;\n        } else if(t_l\
    \ >= x_l and t_r >= x_r) {\n            t->x = x;\n            return t;\n   \
    \     } else {\n            T m = (l + r) / 2;\n            if(m == r) --m;\n\
    \            T t_m = t->x.get(m), x_m = x.get(m);\n            if(t_m > x_m) {\n\
    \                swap(t->x, x);\n                if(x_l >= t_l) t->l = add_line(t->l,\
    \ x, l, m, t_l, t_m);\n                else t->r = add_line(t->r, x, m + 1, r,\
    \ t_m + x.a, t_r);\n            } else {\n                if(t_l >= x_l) t->l\
    \ = add_line(t->l, x, l, m, x_l, x_m);\n                else t->r = add_line(t->r,\
    \ x, m + 1, r, x_m + x.a, x_r);\n            }\n            return t;\n      \
    \  }\n    }\n    Node *add_segment(Node *t, Line &x, const T &a, const T &b, const\
    \ T &l, const T &r, const T &x_l, const T &x_r) {\n        if(r < a or b < l)\
    \ return t;\n        if(a <= l and r <= b) {\n            Line y{x};\n       \
    \     return add_line(t, y, l, r, x_l, x_r);\n        }\n        if(t) {\n   \
    \         T t_l = t->x.get(l), t_r = t->x.get(r);\n            if(t_l <= x_l and\
    \ t_r <= x_r) return t;\n        } else {\n            t = new Node(Line(0, id));\n\
    \        }\n        T m = (l + r) / 2;\n        if(m == r) --m;\n        T x_m\
    \ = x.get(m);\n        t->l = add_segment(t->l, x, a, b, l, m, x_l, x_m);\n  \
    \      t->r = add_segment(t->r, x, a, b, m + 1, r, x_m + x.a, x_r);\n        return\
    \ t;\n    }\n    T query(const Node *t, const T &l, const T &r, const T &x) const\
    \ {\n        if(!t) return id;\n        if(l == r) return t->x.get(x);\n     \
    \   T m = (l + r) / 2;\n        if(m == r) --m;\n        if(x <= m) return min(t->x.get(x),\
    \ query(t->l, l, m, x));\n        else return min(t->x.get(x), query(t->r, m +\
    \ 1, r, x));\n    }\n};\n#line 4 \"verify/library_checker/data_structure/line_add_get_min.test.cpp\"\
    \nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    DynamicLiChaoTree<ll,\
    \ (ll)-1e9, (ll)1e9> cht;\n    rep(i, 0, n) {\n        ll a, b;\n        cin >>\
    \ a >> b;\n        cht.add_line(a, b);\n    }\n    while(q--) {\n        int t;\n\
    \        cin >> t;\n        if(t == 0) {\n            ll a, b;\n            cin\
    \ >> a >> b;\n            cht.add_line(a, b);\n        } else {\n            ll\
    \ p;\n            cin >> p;\n            cout << cht(p) << '\\n';\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/data_structure/dynamic_li_chao_tree.hpp\"\
    \nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    DynamicLiChaoTree<ll,\
    \ (ll)-1e9, (ll)1e9> cht;\n    rep(i, 0, n) {\n        ll a, b;\n        cin >>\
    \ a >> b;\n        cht.add_line(a, b);\n    }\n    while(q--) {\n        int t;\n\
    \        cin >> t;\n        if(t == 0) {\n            ll a, b;\n            cin\
    \ >> a >> b;\n            cht.add_line(a, b);\n        } else {\n            ll\
    \ p;\n            cin >> p;\n            cout << cht(p) << '\\n';\n        }\n\
    \    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/dynamic_li_chao_tree.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/line_add_get_min.test.cpp
- /verify/verify/library_checker/data_structure/line_add_get_min.test.cpp.html
title: verify/library_checker/data_structure/line_add_get_min.test.cpp
---
