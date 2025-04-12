---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/segment_tree.hpp
    title: SegmentTree
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
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"verify/library_checker/data_structure/predecessor_problem.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n#line\
    \ 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing P = pair<long long, long long>;\n#define rep(i, a,\
    \ b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long long\
    \ i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO {\n\
    \    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n    \
    \    cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/segment_tree.hpp\"\
    \ntemplate <typename S, auto op, auto e>\nstruct SegmentTree {\n    SegmentTree(const\
    \ int N)\n        : SegmentTree(vector<S>(N, e())) {}\n    SegmentTree(const vector<S>&\
    \ v)\n        : n((int)v.size()) {\n        size = bit_ceil((unsigned int)n);\n\
    \        log = countr_zero((unsigned int)size);\n        data = vector<S>(2 *\
    \ size, e());\n        for(int i = 0; i < n; ++i) {\n            data[size + i]\
    \ = v[i];\n        }\n        for(int i = size - 1; i >= 1; --i) {\n         \
    \   update(i);\n        }\n    }\n    void set(int p, const S& x) {\n        assert(0\
    \ <= p and p < n);\n        p += size;\n        data[p] = x;\n        for(int\
    \ i = 1; i <= log; ++i) {\n            update(p >> i);\n        }\n    }\n   \
    \ S get(const int p) const {\n        assert(0 <= p and p < n);\n        return\
    \ data[p + size];\n    }\n    S prod(int l, int r) const {\n        assert(0 <=\
    \ l and l <= r and r <= n);\n        S sml = e(), smr = e();\n        l += size;\n\
    \        r += size;\n        while(l < r) {\n            if(l & 1) sml = op(sml,\
    \ data[l++]);\n            if(r & 1) smr = op(data[--r], smr);\n            l\
    \ >>= 1;\n            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\
    \    S all_prod() const {\n        return data[1];\n    }\n\n    template <bool\
    \ (*f)(S)>\n    int max_right(const int l) const {\n        return max_right(l,\
    \ [](const S& x) { return f(x); });\n    }\n    template <class F>\n    int max_right(int\
    \ l, const F& f) const {\n        assert(0 <= l and l <= n);\n        assert(f(e()));\n\
    \        if(l == n) return n;\n        l += size;\n        S sm = e();\n     \
    \   do {\n            while(l % 2 == 0) l >>= 1;\n            if(!f(op(sm, data[l])))\
    \ {\n                while(l < size) {\n                    l = l * 2;\n     \
    \               if(f(op(sm, data[l]))) {\n                        sm = op(sm,\
    \ data[l]);\n                        ++l;\n                    }\n           \
    \     }\n                return l - size;\n            }\n            sm = op(sm,\
    \ data[l]);\n            ++l;\n        } while((l & -l) != l);\n        return\
    \ n;\n    }\n\n    template <bool (*f)(S)>\n    int min_left(const int r) const\
    \ {\n        return min_left(r, [](const S& x) { return f(x); });\n    }\n   \
    \ template <class F>\n    int min_left(int r, const F& f) const {\n        assert(0\
    \ <= r and r <= n);\n        assert(f(e()));\n        if(r == 0) return 0;\n \
    \       r += size;\n        S sm = e();\n        do {\n            --r;\n    \
    \        while(r > 1 and (r % 2)) r >>= 1;\n            if(!f(op(data[r], sm)))\
    \ {\n                while(r < size) {\n                    r = 2 * r + 1;\n \
    \                   if(f(op(data[r], sm))) {\n                        sm = op(data[r],\
    \ sm);\n                        --r;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(data[r],\
    \ sm);\n        } while((r & -r) != r);\n        return 0;\n    }\n\n   private:\n\
    \    int n, size, log;\n    vector<S> data;\n    inline void update(const int\
    \ k) {\n        data[k] = op(data[2 * k], data[2 * k + 1]);\n    }\n    inline\
    \ unsigned int bit_ceil(const unsigned int n) const {\n        unsigned int res\
    \ = 1;\n        while(res < n) res *= 2;\n        return res;\n    }\n    inline\
    \ int countr_zero(const unsigned int n) const {\n        return __builtin_ctz(n);\n\
    \    }\n};\n#line 4 \"verify/library_checker/data_structure/predecessor_problem.test.cpp\"\
    \nint op(int a, int b) {\n    return a + b;\n}\nint e() {\n    return 0;\n}\n\
    int main(void) {\n    int n, q;\n    cin >> n >> q;\n    string t;\n    cin >>\
    \ t;\n    vector<int> a(n);\n    rep(i, 0, n) {\n        a[i] = t[i] - '0';\n\
    \    }\n    SegmentTree<int, op, e> seg(a);\n    while(q--) {\n        int c,\
    \ k;\n        cin >> c >> k;\n        if(c == 0) {\n            seg.set(k, 1);\n\
    \        } else if(c == 1) {\n            seg.set(k, 0);\n        } else if(c\
    \ == 2) {\n            cout << seg.get(k) << '\\n';\n        } else if(c == 3)\
    \ {\n            auto f = [&](int v) -> bool {\n                return v == 0;\n\
    \            };\n            int ans = seg.max_right(k, f);\n            if(ans\
    \ == n) ans = -1;\n            cout << ans << '\\n';\n        } else if(c == 4)\
    \ {\n            auto f = [&](int v) -> bool {\n                return v == 0;\n\
    \            };\n            int ans = seg.min_left(k + 1, f) - 1;\n         \
    \   cout << ans << '\\n';\n        } else {\n            assert(0);\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include \"../../../src/template/template.hpp\"\n#include \"../../../src/data_structure/segment_tree.hpp\"\
    \nint op(int a, int b) {\n    return a + b;\n}\nint e() {\n    return 0;\n}\n\
    int main(void) {\n    int n, q;\n    cin >> n >> q;\n    string t;\n    cin >>\
    \ t;\n    vector<int> a(n);\n    rep(i, 0, n) {\n        a[i] = t[i] - '0';\n\
    \    }\n    SegmentTree<int, op, e> seg(a);\n    while(q--) {\n        int c,\
    \ k;\n        cin >> c >> k;\n        if(c == 0) {\n            seg.set(k, 1);\n\
    \        } else if(c == 1) {\n            seg.set(k, 0);\n        } else if(c\
    \ == 2) {\n            cout << seg.get(k) << '\\n';\n        } else if(c == 3)\
    \ {\n            auto f = [&](int v) -> bool {\n                return v == 0;\n\
    \            };\n            int ans = seg.max_right(k, f);\n            if(ans\
    \ == n) ans = -1;\n            cout << ans << '\\n';\n        } else if(c == 4)\
    \ {\n            auto f = [&](int v) -> bool {\n                return v == 0;\n\
    \            };\n            int ans = seg.min_left(k + 1, f) - 1;\n         \
    \   cout << ans << '\\n';\n        } else {\n            assert(0);\n        }\n\
    \    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/segment_tree.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/predecessor_problem.test.cpp
  requiredBy: []
  timestamp: '2025-04-12 17:56:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/predecessor_problem.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/predecessor_problem.test.cpp
- /verify/verify/library_checker/data_structure/predecessor_problem.test.cpp.html
title: verify/library_checker/data_structure/predecessor_problem.test.cpp
---
