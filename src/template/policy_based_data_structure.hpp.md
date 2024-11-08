---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/data_structure/sorted_set.hpp
    title: SortedSet
  - icon: ':heavy_check_mark:'
    path: src/math/log_mod.hpp
    title: log_mod
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number_theory/discrete_logarithm.test.cpp
    title: verify/library_checker/number_theory/discrete_logarithm.test.cpp
  - icon: ':x:'
    path: verify/yukicoder/649.test.cpp
    title: verify/yukicoder/649.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 2 "src/template/policy_based_data_structure.hpp"

    #include <ext/pb_ds/assoc_container.hpp>

    #include <ext/pb_ds/tree_policy.hpp>

    #include <ext/pb_ds/tag_and_trait.hpp>

    using namespace __gnu_pbds;

    '
  code: '#pragma once

    #include <ext/pb_ds/assoc_container.hpp>

    #include <ext/pb_ds/tree_policy.hpp>

    #include <ext/pb_ds/tag_and_trait.hpp>

    using namespace __gnu_pbds;'
  dependsOn: []
  isVerificationFile: false
  path: src/template/policy_based_data_structure.hpp
  requiredBy:
  - src/math/log_mod.hpp
  - src/data_structure/sorted_set.hpp
  timestamp: '2024-01-01 14:30:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/library_checker/number_theory/discrete_logarithm.test.cpp
  - verify/yukicoder/649.test.cpp
documentation_of: src/template/policy_based_data_structure.hpp
layout: document
title: policy_based_data_structure
---

# policy_based_data_structure

gnu拡張のデータ構造などを使うためのヘッダファイルです．

`tree` や `hash_table` ， `trie` などが入っています．