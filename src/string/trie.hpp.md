---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/string/aho_corasick.hpp
    title: AhoCorasick
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/430.test.cpp
    title: verify/yukicoder/430.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing P = pair<long long, long long>;\n\
    #define rep(i, a, b) for(long long i = (a); i < (b); ++i)\n#define rrep(i, a,\
    \ b) for(long long i = (a); i >= (b); --i)\nconstexpr long long inf = 4e18;\n\
    struct SetupIO {\n    SetupIO() {\n        ios::sync_with_stdio(0);\n        cin.tie(0);\n\
    \        cout << fixed << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/string/trie.hpp\"\
    \ntemplate <size_t X = 26, char margin = 'a'>\nstruct Trie {\n    struct Node\
    \ {\n        array<int, X> nxt;\n        vector<int> idxs;\n        int idx, count,\
    \ parent;\n        char key;\n        Node(const char c, const int par)\n    \
    \        : idx(-1), count(0), parent(par), key(c) {\n            fill(nxt.begin(),\
    \ nxt.end(), -1);\n        }\n    };\n    vector<Node> st;\n    Trie(const char\
    \ c = '$', const int p = -1) {\n        st.emplace_back(c, p);\n    }\n    inline\
    \ int& next(const int i, const int j) {\n        assert(0 <= i and i < (int)st.size());\n\
    \        assert(0 <= j and j < (int)X);\n        return st[i].nxt[j];\n    }\n\
    \    void insert(const string& s, const int x) {\n        int pos = 0;\n     \
    \   for(int i = 0; i < (int)s.size(); ++i) {\n            ++st[pos].count;\n \
    \           const int k = s[i] - margin;\n            if(~next(pos, k)) {\n  \
    \              pos = next(pos, k);\n                continue;\n            }\n\
    \            const int npos = st.size();\n            next(pos, k) = npos;\n \
    \           st.emplace_back(s[i], pos);\n            pos = npos;\n        }\n\
    \        ++st[pos].count;\n        st[pos].idx = x;\n        st[pos].idxs.emplace_back(x);\n\
    \    }\n    int find(const string& s) {\n        int pos = 0;\n        for(int\
    \ i = 0; i < (int)s.size(); ++i) {\n            const int k = s[i] - margin;\n\
    \            if(next(pos, k) < 0) return -1;\n            pos = next(pos, k);\n\
    \        }\n        return pos;\n    }\n    int move(const int pos, const char\
    \ c) {\n        assert(0 <= pos and pos < (int)st.size());\n        return next(pos,\
    \ c - margin);\n    }\n    int size() const {\n        return st.size();\n   \
    \ }\n    int idx(const int pos) const {\n        assert(0 <= pos and pos < (int)st.size());\n\
    \        return st[pos].idx;\n    }\n    int count(const int pos) const {\n  \
    \      assert(0 <= pos and pos < (int)st.size());\n        return st[pos].count;\n\
    \    }\n    int par(const int pos) const {\n        assert(0 <= pos and pos <\
    \ (int)st.size());\n        return st[pos].parent;\n    }\n    vector<int> idxs(const\
    \ int pos) const {\n        assert(0 <= pos and pos < (int)st.size());\n     \
    \   return st[pos].idxs;\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <size_t X =\
    \ 26, char margin = 'a'>\nstruct Trie {\n    struct Node {\n        array<int,\
    \ X> nxt;\n        vector<int> idxs;\n        int idx, count, parent;\n      \
    \  char key;\n        Node(const char c, const int par)\n            : idx(-1),\
    \ count(0), parent(par), key(c) {\n            fill(nxt.begin(), nxt.end(), -1);\n\
    \        }\n    };\n    vector<Node> st;\n    Trie(const char c = '$', const int\
    \ p = -1) {\n        st.emplace_back(c, p);\n    }\n    inline int& next(const\
    \ int i, const int j) {\n        assert(0 <= i and i < (int)st.size());\n    \
    \    assert(0 <= j and j < (int)X);\n        return st[i].nxt[j];\n    }\n   \
    \ void insert(const string& s, const int x) {\n        int pos = 0;\n        for(int\
    \ i = 0; i < (int)s.size(); ++i) {\n            ++st[pos].count;\n           \
    \ const int k = s[i] - margin;\n            if(~next(pos, k)) {\n            \
    \    pos = next(pos, k);\n                continue;\n            }\n         \
    \   const int npos = st.size();\n            next(pos, k) = npos;\n          \
    \  st.emplace_back(s[i], pos);\n            pos = npos;\n        }\n        ++st[pos].count;\n\
    \        st[pos].idx = x;\n        st[pos].idxs.emplace_back(x);\n    }\n    int\
    \ find(const string& s) {\n        int pos = 0;\n        for(int i = 0; i < (int)s.size();\
    \ ++i) {\n            const int k = s[i] - margin;\n            if(next(pos, k)\
    \ < 0) return -1;\n            pos = next(pos, k);\n        }\n        return\
    \ pos;\n    }\n    int move(const int pos, const char c) {\n        assert(0 <=\
    \ pos and pos < (int)st.size());\n        return next(pos, c - margin);\n    }\n\
    \    int size() const {\n        return st.size();\n    }\n    int idx(const int\
    \ pos) const {\n        assert(0 <= pos and pos < (int)st.size());\n        return\
    \ st[pos].idx;\n    }\n    int count(const int pos) const {\n        assert(0\
    \ <= pos and pos < (int)st.size());\n        return st[pos].count;\n    }\n  \
    \  int par(const int pos) const {\n        assert(0 <= pos and pos < (int)st.size());\n\
    \        return st[pos].parent;\n    }\n    vector<int> idxs(const int pos) const\
    \ {\n        assert(0 <= pos and pos < (int)st.size());\n        return st[pos].idxs;\n\
    \    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/string/trie.hpp
  requiredBy:
  - src/string/aho_corasick.hpp
  timestamp: '2024-11-09 02:46:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/430.test.cpp
documentation_of: src/string/trie.hpp
layout: document
title: Trie
---

# Trie

集合に対する文字列の追加や検索を効率的に行うデータ構造です．

## コンストラクタ
```cpp
Trie<size_t X = 26, char margin = 'a'> trie(char c = '$', int p = -1)
```

- 文字の種類数が $X$ で最小の文字が $\mathrm{margin}$ であるような空の木 `trie` を作ります．

- `c` は根ノードの文字です．

- `p` は親ノードの番号です．

**計算量**

- $O(1)$

## next
```cpp
int& next(int i, int j)
```

基本的に内部用の関数です．

ノード $i$ からのびる $j$ 番目に小さい文字のノード番号を返します．<br>
そのようなノードがない場合は $-1$ を返します．

**制約**

- $i$ に存在しないノードを指定しない．
- $0 \leq j < X$

**計算量**

- $O(1)$

## insert
```cpp
void insert(string s, int x)
```

`trie` に識別子 $x$ として文字列 $s$ を追加します．

**計算量**

$s$ の長さを $n$ として，

- $O(n)$

## find
```cpp
int find(string s)
```

文字列 $s$ の最後の文字に対応するノード番号を返します．<br>
文字列 $s$ が `trie` に含まれていない場合は $-1$ を返します．

**計算量**

$s$ の長さを $n$ として，

- $O(n)$

## move
```cpp
int move(int pos, char c)
```

ノード $\mathrm{pos}$ からのびる文字 $c$ のノード番号を返します．

**制約**

- $\mathrm{pos}$ に存在しないノードを指定しない．

**計算量**

- $O(1)$

## size
```cpp
int size()
```

`trie` のノードの個数を返します．

**計算量**

- $O(1)$

## idx
```cpp
int idx(int pos)
```

ノード $\mathrm{pos}$ がある文字列の最後の文字に対応するノードである場合，その文字列の識別子を返します (2つ以上ある場合，最新のものを返します)．

**制約**

- $\mathrm{pos}$ に存在しないノードを指定しない．

**計算量**

- $O(1)$

## idxs
```cpp
vector<int> idxs(int pos)
```

ノード $\mathrm{pos}$ がある文字列の最後の文字に対応するノードである場合，その文字列の識別子をすべて返します．

**制約**

- $\mathrm{pos}$ に存在しないノードを指定しない．

**計算量**

返り値の配列の長さを $m$ として，

- $O(m)$

## count
```cpp
int count(int pos)
```

ノード $\mathrm{pos}$ 以下に格納されている文字列の個数を返します．

**制約**

- $\mathrm{pos}$ に存在しないノードを指定しない．

**計算量**

- $O(1)$

## par
```cpp
int par(int pos)
```

ノード $\mathrm{pos}$ の親ノードの番号を返します．

**制約**

- $\mathrm{pos}$ に存在しないノードを指定しない．

**計算量**

- $O(1)$