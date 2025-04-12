---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: template/template.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include \"template/template.hpp\"\n#include \"data_structure/segment_tree.hpp\"\
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
  dependsOn: []
  isVerificationFile: true
  path: verify/library_checker/data_structure/predecessor_problem.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/predecessor_problem.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/predecessor_problem.test.cpp
- /verify/verify/library_checker/data_structure/predecessor_problem.test.cpp.html
title: verify/library_checker/data_structure/predecessor_problem.test.cpp
---
