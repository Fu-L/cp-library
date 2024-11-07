---
title: Modint_2_61m1
documentation_of: ../../src/template/modint_2_61m1.hpp
---

# Modint_2_61m1

自動で $\mathrm{mod} ~( = 2^{61} - 1)$ をとる構造体です．

主にハッシュなどに用います．

基本的には `StaticModint` と同じです．<br>
一部，型が違う ( `int` → `long long` など)ので注意してください．