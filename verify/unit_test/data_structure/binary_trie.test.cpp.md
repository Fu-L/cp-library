---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/binary_trie.hpp
    title: BinaryTrie
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
  bundledCode: "#line 1 \"verify/unit_test/data_structure/binary_trie.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 4 \"src/template/template.hpp\"\nusing namespace\
    \ std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n#define\
    \ rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a, b) for(long\
    \ long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\nstruct SetupIO\
    \ {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/data_structure/binary_trie.hpp\"\
    \ntemplate <typename T, int MAX_LOG>\nstruct BinaryTrie {\n    BinaryTrie()\n\
    \        : root(new Node) {}\n    void insert(const T& x) {\n        assert(0\
    \ <= x and x < (T(1) << MAX_LOG));\n        if(!contains(x)) update(x, 1);\n \
    \   }\n    void erase(const T& x) {\n        assert(0 <= x and x < (T(1) << MAX_LOG));\n\
    \        if(contains(x)) update(x, -1);\n    }\n    bool contains(const T& x)\
    \ const {\n        assert(0 <= x and x < (T(1) << MAX_LOG));\n        Node* cur\
    \ = root;\n        for(int i = MAX_LOG - 1; i >= 0; --i) {\n            if(!cur)\
    \ break;\n            const int nex = (x >> i) & 1;\n            cur = cur->child[nex];\n\
    \        }\n        return cur and cur->cnt;\n    }\n    int size() const {\n\
    \        return root->cnt;\n    }\n    T min(const T& x = 0) const {\n       \
    \ assert(root->cnt > 0);\n        assert(0 <= x and x < (T(1) << MAX_LOG));\n\
    \        return kth_element(0, x);\n    }\n    T max(const T& x = 0) const {\n\
    \        assert(root->cnt > 0);\n        assert(0 <= x and x < (T(1) << MAX_LOG));\n\
    \        return kth_element(root->cnt - 1, x);\n    }\n    T kth_element(int k,\
    \ const T& x = 0) const {\n        assert(0 <= k and k < root->cnt);\n       \
    \ assert(0 <= x and x < (T(1) << MAX_LOG));\n        T res = 0;\n        Node*\
    \ cur = root;\n        for(int i = MAX_LOG - 1; i >= 0; --i) {\n            const\
    \ int nex = (x >> i) & 1;\n            const int cnt = (cur->child[nex] ? cur->child[nex]->cnt\
    \ : 0);\n            if(cnt <= k) {\n                k -= cnt;\n             \
    \   res += T(1) << i;\n                cur = cur->child[nex ^ 1];\n          \
    \  } else {\n                cur = cur->child[nex];\n            }\n        }\n\
    \        return res;\n    }\n    int lower_bound(const T& val, const T& x = 0)\
    \ const {\n        assert(0 <= val and val <= (T(1) << MAX_LOG));\n        assert(0\
    \ <= x and x < (T(1) << MAX_LOG));\n        if(val == (T(1) << MAX_LOG)) return\
    \ size();\n        int res = 0;\n        Node* cur = root;\n        for(int i\
    \ = MAX_LOG - 1; i >= 0; --i) {\n            if(!cur) break;\n            const\
    \ int xi = (x >> i) & 1, vi = (val >> i) & 1;\n            const int nex = xi\
    \ xor vi;\n            if(vi and cur->child[xi]) {\n                res += cur->child[xi]->cnt;\n\
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
    \ cur->cnt += delta;\n        }\n    }\n};\n#line 4 \"verify/unit_test/data_structure/binary_trie.test.cpp\"\
    \nint main() {\n    BinaryTrie<int, 3> trie;\n    trie.insert(0);\n    trie.insert(3);\n\
    \    trie.insert(7);\n    assert(trie.lower_bound(0) == 0);\n    assert(trie.lower_bound(8)\
    \ == 3);\n    assert(trie.upper_bound(7) == 3);\n    assert(trie.kth_element(1,\
    \ 1) == 2);\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../src/template/template.hpp\"\
    \n#include \"../../../src/data_structure/binary_trie.hpp\"\nint main() {\n   \
    \ BinaryTrie<int, 3> trie;\n    trie.insert(0);\n    trie.insert(3);\n    trie.insert(7);\n\
    \    assert(trie.lower_bound(0) == 0);\n    assert(trie.lower_bound(8) == 3);\n\
    \    assert(trie.upper_bound(7) == 3);\n    assert(trie.kth_element(1, 1) == 2);\n\
    \    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - src/template/template.hpp
  - src/data_structure/binary_trie.hpp
  isVerificationFile: true
  path: verify/unit_test/data_structure/binary_trie.test.cpp
  requiredBy: []
  timestamp: '2026-07-04 16:35:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/data_structure/binary_trie.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/data_structure/binary_trie.test.cpp
- /verify/verify/unit_test/data_structure/binary_trie.test.cpp.html
title: verify/unit_test/data_structure/binary_trie.test.cpp
---
