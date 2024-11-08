---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/binary_trie.hpp
    title: BinaryTrie
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
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"verify/library_checker/data_structure/set_xor_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#line 2 \"\
    src/template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing P = pair<ll, ll>;\n#define rep(i, a, b) for(ll i\
    \ = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a; i >= b; --i)\nconstexpr\
    \ ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(30);\n    }\n} setup_io;\n\
    #line 3 \"src/data_structure/binary_trie.hpp\"\ntemplate <typename T, int MAX_LOG>\n\
    struct BinaryTrie {\n    BinaryTrie()\n        : root(new Node) {}\n    void insert(const\
    \ T& x) {\n        assert(0 <= x and x < (T(1) << MAX_LOG));\n        if(!contains(x))\
    \ update(x, 1);\n    }\n    void erase(const T& x) {\n        assert(0 <= x and\
    \ x < (T(1) << MAX_LOG));\n        if(contains(x)) update(x, -1);\n    }\n   \
    \ bool contains(const T& x) const {\n        assert(0 <= x and x < (T(1) << MAX_LOG));\n\
    \        Node* cur = root;\n        for(int i = MAX_LOG - 1; i >= 0; --i) {\n\
    \            if(!cur) break;\n            const int nex = (x >> i) & 1;\n    \
    \        cur = cur->child[nex];\n        }\n        return cur and cur->cnt;\n\
    \    }\n    int size() const {\n        return root->cnt;\n    }\n    T min(const\
    \ T& x = 0) const {\n        assert(root->cnt > 0);\n        assert(0 <= x and\
    \ x < (T(1) << MAX_LOG));\n        return kth_element(0, x);\n    }\n    T max(const\
    \ T& x = 0) const {\n        assert(root->cnt > 0);\n        assert(0 <= x and\
    \ x < (T(1) << MAX_LOG));\n        return kth_element(root->cnt - 1, x);\n   \
    \ }\n    T kth_element(int k, const T& x = 0) const {\n        assert(0 <= k and\
    \ k < root->cnt);\n        assert(0 <= x and x < (T(1) << MAX_LOG));\n       \
    \ T res = 0;\n        Node* cur = root;\n        for(int i = MAX_LOG - 1; i >=\
    \ 0; --i) {\n            const int nex = (x >> i) & 1;\n            const int\
    \ cnt = (cur->child[nex] ? cur->child[nex]->cnt : 0);\n            if(cnt <= k)\
    \ {\n                k -= cnt;\n                res += T(1) << i;\n          \
    \      cur = cur->child[nex ^ 1];\n            } else {\n                cur =\
    \ cur->child[nex];\n            }\n        }\n        return res;\n    }\n   \
    \ int lower_bound(const T& val, const T& x = 0) const {\n        assert(0 <= val\
    \ and val < (T(1) << MAX_LOG));\n        assert(0 <= x and x < (T(1) << MAX_LOG));\n\
    \        int res = 0;\n        Node* cur = root;\n        for(int i = MAX_LOG\
    \ - 1; i >= 0; --i) {\n            if(!cur) break;\n            const int xi =\
    \ (x >> i) & 1, vi = (val >> i) & 1;\n            const int nex = xi xor vi;\n\
    \            if(vi and cur->child[xi]) {\n                res += cur->child[xi]->cnt;\n\
    \            }\n            cur = cur->child[nex];\n        }\n        return\
    \ res;\n    }\n    int upper_bound(const T& val, const T& x = 0) const {\n   \
    \     assert(0 <= val and val < (T(1) << MAX_LOG));\n        assert(0 <= x and\
    \ x < (T(1) << MAX_LOG));\n        return lower_bound(val + 1, x);\n    }\n\n\
    \   private:\n    struct Node {\n        Node* child[2] = {};\n        int cnt\
    \ = 0;\n        Node() {}\n    };\n    Node* root;\n    void update(const T& x,\
    \ const int delta) {\n        Node* cur = root;\n        cur->cnt += delta;\n\
    \        for(int i = MAX_LOG - 1; i >= 0; --i) {\n            const int nex =\
    \ (x >> i) & 1;\n            if(!cur->child[nex]) {\n                cur->child[nex]\
    \ = new Node;\n            }\n            cur = cur->child[nex];\n           \
    \ cur->cnt += delta;\n        }\n    }\n};\n#line 4 \"verify/library_checker/data_structure/set_xor_min.test.cpp\"\
    \nint main(void) {\n    int q;\n    cin >> q;\n    BinaryTrie<int, 30> trie;\n\
    \    while(q--) {\n        int t, x;\n        cin >> t >> x;\n        if(t ==\
    \ 0) {\n            trie.insert(x);\n        } else if(t == 1) {\n           \
    \ trie.erase(x);\n        } else {\n            cout << trie.min(x) << '\\n';\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#include\
    \ \"../../../src/template/template.hpp\"\n#include \"../../../src/data_structure/binary_trie.hpp\"\
    \nint main(void) {\n    int q;\n    cin >> q;\n    BinaryTrie<int, 30> trie;\n\
    \    while(q--) {\n        int t, x;\n        cin >> t >> x;\n        if(t ==\
    \ 0) {\n            trie.insert(x);\n        } else if(t == 1) {\n           \
    \ trie.erase(x);\n        } else {\n            cout << trie.min(x) << '\\n';\n\
    \        }\n    }\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/binary_trie.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2024-11-09 00:13:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/set_xor_min.test.cpp
- /verify/verify/library_checker/data_structure/set_xor_min.test.cpp.html
title: verify/library_checker/data_structure/set_xor_min.test.cpp
---
