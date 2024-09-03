---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/trie.hpp
    title: Trie
  - icon: ':question:'
    path: src/template/template.hpp
    title: template
  _extendedRequiredBy: []
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
    \ < 0 ? vector<int>() : st[pos].idxs;\n    }\n};\n#line 4 \"src/string/aho_corasick.hpp\"\
    \ntemplate <size_t X = 26, char margin = 'a', bool heavy = true>\nstruct AhoCorasick\
    \ : Trie<X + 1, margin> {\n    using TRIE = Trie<X + 1, margin>;\n    using TRIE::next;\n\
    \    using TRIE::st;\n    using TRIE::TRIE;\n    vector<int> cnt;\n    void build()\
    \ {\n        int n = (int)st.size();\n        cnt.resize(n);\n        for(int\
    \ i = 0; i < n; ++i) {\n            if(heavy) sort(st[i].idxs.begin(), st[i].idxs.end());\n\
    \            cnt[i] = (int)st[i].idxs.size();\n        }\n        queue<int> que;\n\
    \        for(int i = 0; i < (int)X; ++i) {\n            if(~next(0, i)) {\n  \
    \              next(next(0, i), X) = 0;\n                que.emplace(next(0, i));\n\
    \            } else {\n                next(0, i) = 0;\n            }\n      \
    \  }\n        while(!que.empty()) {\n            auto& x = st[que.front()];\n\
    \            int fail = x.nxt[X];\n            cnt[que.front()] += cnt[fail];\n\
    \            que.pop();\n            for(int i = 0; i < (int)X; ++i) {\n     \
    \           int& nx = x.nxt[i];\n                if(nx < 0) {\n              \
    \      nx = next(fail, i);\n                    continue;\n                }\n\
    \                que.emplace(nx);\n                next(nx, X) = next(fail, i);\n\
    \                if(heavy) {\n                    auto& idx = st[nx].idxs;\n \
    \                   auto& idy = st[next(fail, i)].idxs;\n                    vector<int>\
    \ idz;\n                    set_union(idx.begin(), idx.end(), idy.begin(), idy.end(),\
    \ back_inserter(idz));\n                    idx = idz;\n                }\n  \
    \          }\n        }\n    }\n    conditional_t<heavy, unordered_map<int, long\
    \ long>, long long> match(const string& s) {\n        unordered_map<int, int>\
    \ pos_cnt;\n        int pos = 0;\n        for(const auto& c : s) {\n         \
    \   pos = next(pos, c - margin);\n            ++pos_cnt[pos];\n        }\n   \
    \     conditional_t<heavy, unordered_map<int, long long>, long long> res{};\n\
    \        for(const auto& [key, val] : pos_cnt) {\n            if constexpr(heavy)\
    \ {\n                for(const auto& x : st[key].idxs) res[x] += val;\n      \
    \      } else {\n                res += 1ll * cnt[key] * val;\n            }\n\
    \        }\n        return res;\n    }\n    int count(int pos) {\n        return\
    \ cnt[pos];\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"./trie.hpp\"\
    \ntemplate <size_t X = 26, char margin = 'a', bool heavy = true>\nstruct AhoCorasick\
    \ : Trie<X + 1, margin> {\n    using TRIE = Trie<X + 1, margin>;\n    using TRIE::next;\n\
    \    using TRIE::st;\n    using TRIE::TRIE;\n    vector<int> cnt;\n    void build()\
    \ {\n        int n = (int)st.size();\n        cnt.resize(n);\n        for(int\
    \ i = 0; i < n; ++i) {\n            if(heavy) sort(st[i].idxs.begin(), st[i].idxs.end());\n\
    \            cnt[i] = (int)st[i].idxs.size();\n        }\n        queue<int> que;\n\
    \        for(int i = 0; i < (int)X; ++i) {\n            if(~next(0, i)) {\n  \
    \              next(next(0, i), X) = 0;\n                que.emplace(next(0, i));\n\
    \            } else {\n                next(0, i) = 0;\n            }\n      \
    \  }\n        while(!que.empty()) {\n            auto& x = st[que.front()];\n\
    \            int fail = x.nxt[X];\n            cnt[que.front()] += cnt[fail];\n\
    \            que.pop();\n            for(int i = 0; i < (int)X; ++i) {\n     \
    \           int& nx = x.nxt[i];\n                if(nx < 0) {\n              \
    \      nx = next(fail, i);\n                    continue;\n                }\n\
    \                que.emplace(nx);\n                next(nx, X) = next(fail, i);\n\
    \                if(heavy) {\n                    auto& idx = st[nx].idxs;\n \
    \                   auto& idy = st[next(fail, i)].idxs;\n                    vector<int>\
    \ idz;\n                    set_union(idx.begin(), idx.end(), idy.begin(), idy.end(),\
    \ back_inserter(idz));\n                    idx = idz;\n                }\n  \
    \          }\n        }\n    }\n    conditional_t<heavy, unordered_map<int, long\
    \ long>, long long> match(const string& s) {\n        unordered_map<int, int>\
    \ pos_cnt;\n        int pos = 0;\n        for(const auto& c : s) {\n         \
    \   pos = next(pos, c - margin);\n            ++pos_cnt[pos];\n        }\n   \
    \     conditional_t<heavy, unordered_map<int, long long>, long long> res{};\n\
    \        for(const auto& [key, val] : pos_cnt) {\n            if constexpr(heavy)\
    \ {\n                for(const auto& x : st[key].idxs) res[x] += val;\n      \
    \      } else {\n                res += 1ll * cnt[key] * val;\n            }\n\
    \        }\n        return res;\n    }\n    int count(int pos) {\n        return\
    \ cnt[pos];\n    }\n};"
  dependsOn:
  - src/template/template.hpp
  - src/string/trie.hpp
  isVerificationFile: false
  path: src/string/aho_corasick.hpp
  requiredBy: []
  timestamp: '2024-08-31 16:58:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/430.test.cpp
documentation_of: src/string/aho_corasick.hpp
layout: document
title: AhoCorasick
---

# AhoCorasick

複数のパターン文字列に対する文字列マッチングを行います．

## コンストラクタ
```cpp
AhoCorasick<size_t X = 26, char margin = 'a', bool heavy = true> aho()
```

- 文字の種類数が $X$ で最小の文字が $\mathrm{margin}$ であるような空のデータ構造 `aho` を作ります．
- `heavy` が `true` であるとき， `match` では各パターン文字列を区別して回数を数えます．
- `heavy` が `false` であるとき， `match` では全パターン文字列にマッチした回数の合計を数えます．

**計算量**

- $O(1)$

## insertなど
```cpp
void insert(string s, int x)
```

`Trie` を継承しているため `Trie` にある関数が使えます．

`aho`　にパターン文字列 $s$ を識別子 $x$ として追加します．

**計算量**

$s$ の長さを $n$ として，

- $O(n)$

## build
```cpp
void build()
```

追加されたパターン文字列集合をもとにオートマトンを構築します．

**制約**

- パターン文字列を追加した後にちょうど1回だけ呼ぶ．
- `build` を呼んだ以降 `insert` を呼ばない．

**計算量**

- $O(\sum n)$

## match

```cpp
unordered_map<int, long long> match(string s)
```

テキスト文字列 $s$ が各パターン文字列とマッチした回数を返します．<br>
`heavy` が `true` のときは `unordered_map` を返しますが， `false` のときは `long long` を返すので注意してください．

**制約**

- `build` を呼んだ後に使う．

**計算量**

$s$ の長さを $n$ として，

- $O(n)$