---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/fenwick_tree.hpp
    title: FenwickTree
  - icon: ':heavy_check_mark:'
    path: src/data_structure/mo.hpp
    title: Mo
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"verify/library_checker/data_structure/static_range_inversions_query.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll\
    \ i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/data_structure/fenwick_tree.hpp\"\ntemplate <typename T>\nstruct\
    \ FenwickTree {\n    FenwickTree(int N)\n        : n(N), data(N) {}\n    void\
    \ add(int p, T x) {\n        assert(0 <= p and p < n);\n        ++p;\n       \
    \ while(p <= n) {\n            data[p - 1] += x;\n            p += p & -p;\n \
    \       }\n    }\n    T sum(int l, int r) const {\n        assert(0 <= l and l\
    \ <= r and r <= n);\n        return sum(r) - sum(l);\n    }\n    T operator[](int\
    \ x) const {\n        assert(0 <= x and x < n);\n        return sum(x + 1) - sum(x);\n\
    \    }\n\n   private:\n    int n;\n    vector<T> data;\n    inline T sum(int r)\
    \ const {\n        T s = 0;\n        while(r > 0) {\n            s += data[r -\
    \ 1];\n            r -= r & -r;\n        }\n        return s;\n    }\n};\n#line\
    \ 3 \"src/data_structure/mo.hpp\"\nstruct Mo {\n    Mo(int N, int Q)\n       \
    \ : n(N), order(Q) {\n        width = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q\
    \ * 2.0 / 3.0)));\n        iota(order.begin(), order.end(), 0);\n    }\n    void\
    \ insert(int l, int r) {\n        assert(0 <= l and l <= r and r <= n);\n    \
    \    left.push_back(l);\n        right.push_back(r);\n    }\n    template <typename\
    \ AL, typename AR, typename DL, typename DR, typename OUT>\n    void run(const\
    \ AL& add_left, const AR& add_right, const DL& delete_left, const DR& delete_right,\
    \ const OUT& out) {\n        assert(left.size() == order.size());\n        sort(order.begin(),\
    \ order.end(), [&](int i, int j) {\n            int iblock = left[i] / width,\
    \ jblock = left[j] / width;\n            if(iblock != jblock) return iblock <\
    \ jblock;\n            if(iblock & 1) return right[i] < right[j];\n          \
    \  return right[i] > right[j];\n        });\n        int nl = 0, nr = 0;\n   \
    \     for(int idx : order) {\n            while(nl > left[idx]) add_left(--nl);\n\
    \            while(nr < right[idx]) add_right(nr++);\n            while(nl < left[idx])\
    \ delete_left(nl++);\n            while(nr > right[idx]) delete_right(--nr);\n\
    \            out(idx);\n        }\n    }\n\n   private:\n    int n, width;\n \
    \   vector<int> left, right, order;\n};\n#line 5 \"verify/library_checker/data_structure/static_range_inversions_query.test.cpp\"\
    \nint main(void) {\n    int n, q;\n    cin >> n >> q;\n    Mo mo(n, q);\n    vector<int>\
    \ a(n);\n    rep(i, 0, n) cin >> a[i];\n    vector<int> comp = a;\n    sort(comp.begin(),\
    \ comp.end());\n    comp.erase(unique(comp.begin(), comp.end()), comp.end());\n\
    \    rep(i, 0, n) a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();\n\
    \    rep(i, 0, q) {\n        int l, r;\n        cin >> l >> r;\n        mo.insert(l,\
    \ r);\n    }\n    vector<ll> ans(q);\n    FenwickTree<int> fw(n);\n    ll cnt\
    \ = 0;\n    auto add_left = [&](int idx) {\n        cnt += fw.sum(0, a[idx]);\n\
    \        fw.add(a[idx], 1);\n    };\n    auto add_right = [&](int idx) {\n   \
    \     cnt += fw.sum(a[idx] + 1, n);\n        fw.add(a[idx], 1);\n    };\n    auto\
    \ delete_left = [&](int idx) {\n        cnt -= fw.sum(0, a[idx]);\n        fw.add(a[idx],\
    \ -1);\n    };\n    auto delete_right = [&](int idx) {\n        cnt -= fw.sum(a[idx]\
    \ + 1, n);\n        fw.add(a[idx], -1);\n    };\n    auto out = [&](int idx) {\n\
    \        ans[idx] = cnt;\n    };\n    mo.run(add_left, add_right, delete_left,\
    \ delete_right, out);\n    rep(i, 0, q) {\n        cout << ans[i] << '\\n';\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#include \"../../../src/template/template.hpp\"\n#include \"../../../src/data_structure/fenwick_tree.hpp\"\
    \n#include \"../../../src/data_structure/mo.hpp\"\nint main(void) {\n    int n,\
    \ q;\n    cin >> n >> q;\n    Mo mo(n, q);\n    vector<int> a(n);\n    rep(i,\
    \ 0, n) cin >> a[i];\n    vector<int> comp = a;\n    sort(comp.begin(), comp.end());\n\
    \    comp.erase(unique(comp.begin(), comp.end()), comp.end());\n    rep(i, 0,\
    \ n) a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();\n    rep(i,\
    \ 0, q) {\n        int l, r;\n        cin >> l >> r;\n        mo.insert(l, r);\n\
    \    }\n    vector<ll> ans(q);\n    FenwickTree<int> fw(n);\n    ll cnt = 0;\n\
    \    auto add_left = [&](int idx) {\n        cnt += fw.sum(0, a[idx]);\n     \
    \   fw.add(a[idx], 1);\n    };\n    auto add_right = [&](int idx) {\n        cnt\
    \ += fw.sum(a[idx] + 1, n);\n        fw.add(a[idx], 1);\n    };\n    auto delete_left\
    \ = [&](int idx) {\n        cnt -= fw.sum(0, a[idx]);\n        fw.add(a[idx],\
    \ -1);\n    };\n    auto delete_right = [&](int idx) {\n        cnt -= fw.sum(a[idx]\
    \ + 1, n);\n        fw.add(a[idx], -1);\n    };\n    auto out = [&](int idx) {\n\
    \        ans[idx] = cnt;\n    };\n    mo.run(add_left, add_right, delete_left,\
    \ delete_right, out);\n    rep(i, 0, q) {\n        cout << ans[i] << '\\n';\n\
    \    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/fenwick_tree.hpp
  - src/data_structure/mo.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 04:25:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/static_range_inversions_query.test.cpp
- /verify/verify/library_checker/data_structure/static_range_inversions_query.test.cpp.html
title: verify/library_checker/data_structure/static_range_inversions_query.test.cpp
---
