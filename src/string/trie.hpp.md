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
    using namespace std;\nusing ll = long long;\nusing P = pair<ll, ll>;\n#define\
    \ rep(i, a, b) for(ll i = a; i < b; ++i)\n#define rrep(i, a, b) for(ll i = a;\
    \ i >= b; --i)\nconstexpr ll inf = 4e18;\nstruct SetupIO {\n    SetupIO() {\n\
    \        ios::sync_with_stdio(0);\n        cin.tie(0);\n        cout << fixed\
    \ << setprecision(30);\n    }\n} setup_io;\n#line 3 \"src/string/trie.hpp\"\n\
    template <size_t X = 26, char margin = 'a'>\nstruct Trie {\n    struct Node {\n\
    \        array<int, X> nxt;\n        vector<int> idxs;\n        int idx;\n   \
    \     int count;\n        char key;\n        Node(char c)\n            : idx(-1),\
    \ count(0), key(c) {\n            fill(nxt.begin(), nxt.end(), -1);\n        }\n\
    \    };\n    vector<Node> st;\n    Trie(char c = '$') {\n        st.emplace_back(c);\n\
    \    }\n    inline int& next(int i, int j) {\n        return st[i].nxt[j];\n \
    \   }\n    void insert(const string& s, int x) {\n        int pos = 0;\n     \
    \   for(int i = 0; i < (int)s.size(); ++i) {\n            ++st[pos].count;\n \
    \           int k = s[i] - margin;\n            if(~next(pos, k)) {\n        \
    \        pos = next(pos, k);\n                continue;\n            }\n     \
    \       int npos = st.size();\n            next(pos, k) = npos;\n            st.emplace_back(s[i]);\n\
    \            pos = npos;\n        }\n        ++st[pos].count;\n        st[pos].idx\
    \ = x;\n        st[pos].idxs.emplace_back(x);\n    }\n    int find(const string&\
    \ s) {\n        int pos = 0;\n        for(int i = 0; i < (int)s.size(); ++i) {\n\
    \            int k = s[i] - margin;\n            if(next(pos, k) < 0) return -1;\n\
    \            pos = next(pos, k);\n        }\n        return pos;\n    }\n    int\
    \ move(int pos, char c) {\n        assert(pos < (int)st.size());\n        return\
    \ pos < 0 ? -1 : next(pos, c - margin);\n    }\n    int size() const {\n     \
    \   return st.size();\n    }\n    int idx(int pos) {\n        return pos < 0 ?\
    \ -1 : st[pos].idx;\n    }\n    int count(int pos) {\n        return pos < 0 ?\
    \ 0 : st[pos].count;\n    }\n    vector<int> idxs(int pos) {\n        return pos\
    \ < 0 ? vector<int>() : st[pos].idxs;\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\ntemplate <size_t X =\
    \ 26, char margin = 'a'>\nstruct Trie {\n    struct Node {\n        array<int,\
    \ X> nxt;\n        vector<int> idxs;\n        int idx;\n        int count;\n \
    \       char key;\n        Node(char c)\n            : idx(-1), count(0), key(c)\
    \ {\n            fill(nxt.begin(), nxt.end(), -1);\n        }\n    };\n    vector<Node>\
    \ st;\n    Trie(char c = '$') {\n        st.emplace_back(c);\n    }\n    inline\
    \ int& next(int i, int j) {\n        return st[i].nxt[j];\n    }\n    void insert(const\
    \ string& s, int x) {\n        int pos = 0;\n        for(int i = 0; i < (int)s.size();\
    \ ++i) {\n            ++st[pos].count;\n            int k = s[i] - margin;\n \
    \           if(~next(pos, k)) {\n                pos = next(pos, k);\n       \
    \         continue;\n            }\n            int npos = st.size();\n      \
    \      next(pos, k) = npos;\n            st.emplace_back(s[i]);\n            pos\
    \ = npos;\n        }\n        ++st[pos].count;\n        st[pos].idx = x;\n   \
    \     st[pos].idxs.emplace_back(x);\n    }\n    int find(const string& s) {\n\
    \        int pos = 0;\n        for(int i = 0; i < (int)s.size(); ++i) {\n    \
    \        int k = s[i] - margin;\n            if(next(pos, k) < 0) return -1;\n\
    \            pos = next(pos, k);\n        }\n        return pos;\n    }\n    int\
    \ move(int pos, char c) {\n        assert(pos < (int)st.size());\n        return\
    \ pos < 0 ? -1 : next(pos, c - margin);\n    }\n    int size() const {\n     \
    \   return st.size();\n    }\n    int idx(int pos) {\n        return pos < 0 ?\
    \ -1 : st[pos].idx;\n    }\n    int count(int pos) {\n        return pos < 0 ?\
    \ 0 : st[pos].count;\n    }\n    vector<int> idxs(int pos) {\n        return pos\
    \ < 0 ? vector<int>() : st[pos].idxs;\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  isVerificationFile: false
  path: src/string/trie.hpp
  requiredBy:
  - src/string/aho_corasick.hpp
  timestamp: '2024-06-28 18:08:24+09:00'
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
Trie<size_t X = 26, char margin = 'a'> trie(char c = '$')
```

- 文字の種類数が $X$ で最小の文字が $\mathrm{margin}$ であるような空の木 `trie` を作ります．

- $c$ は根ノードの文字です．

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

- $O(|s|)$

## find
```cpp
int find(string s)
```

文字列 $s$ の最後の文字に対応するノード番号を返します．<br>
文字列 $s$ が `trie` に含まれていない場合は $-1$ を返します．

**計算量**

- $O(|s|)$

## move
```cpp
int move(int pos, char c)
```

ノード $\mathrm{pos}$ からのびる文字 $c$ のノード番号を返します．<br>
そのようなノードがない場合は $-1$ を返します．

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

ノード $\mathrm{pos}$ がある文字列の最後の文字に対応するノードである場合，その文字列の識別子を返します (2つ以上ある場合，最新のものを返します)．<br>
そうでない場合は $-1$ を返します．

**計算量**

- $O(1)$

## idxs
```cpp
vector<int> idxs(int pos)
```

ノード $\mathrm{pos}$ がある文字列の最後の文字に対応するノードである場合，その文字列の識別子をすべて返します．<br>
そうでない場合は $-1$ を返します．

**計算量**

- $O(|\mathrm{idxs}|)$

## count
```cpp
int count(int pos)
```

ノード $\mathrm{pos}$ 以下に格納されている文字列の個数を返します．

**計算量**

- $O(1)$