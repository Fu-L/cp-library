#pragma once
#include "../template/template.hpp"
template <size_t X = 26, char margin = 'a'>
struct Trie {
    struct Node {
        array<int, X> nxt;
        vector<int> idxs;
        int idx, count, parent;
        char key;
        Node(const char c, const int par)
            : idx(-1), count(0), parent(par), key(c) {
            fill(nxt.begin(), nxt.end(), -1);
        }
    };
    vector<Node> st;
    Trie(const char c = '$', const int p = -1) {
        st.emplace_back(c, p);
    }
    inline int& next(const int i, const int j) {
        assert(0 <= i and i < (int)st.size());
        assert(0 <= j and j < (int)X);
        return st[i].nxt[j];
    }
    void insert(const string& s, const int x) {
        int pos = 0;
        for(int i = 0; i < (int)s.size(); ++i) {
            ++st[pos].count;
            const int k = s[i] - margin;
            if(~next(pos, k)) {
                pos = next(pos, k);
                continue;
            }
            const int npos = st.size();
            next(pos, k) = npos;
            st.emplace_back(s[i], pos);
            pos = npos;
        }
        ++st[pos].count;
        st[pos].idx = x;
        st[pos].idxs.emplace_back(x);
    }
    int find(const string& s) {
        int pos = 0;
        for(int i = 0; i < (int)s.size(); ++i) {
            const int k = s[i] - margin;
            if(next(pos, k) < 0) return -1;
            pos = next(pos, k);
        }
        return pos;
    }
    int move(const int pos, const char c) {
        assert(0 <= pos and pos < (int)st.size());
        return next(pos, c - margin);
    }
    int size() const {
        return st.size();
    }
    int idx(const int pos) const {
        assert(0 <= pos and pos < (int)st.size());
        return st[pos].idx;
    }
    int count(const int pos) const {
        assert(0 <= pos and pos < (int)st.size());
        return st[pos].count;
    }
    int par(const int pos) const {
        assert(0 <= pos and pos < (int)st.size());
        return st[pos].parent;
    }
    vector<int> idxs(const int pos) const {
        assert(0 <= pos and pos < (int)st.size());
        return st[pos].idxs;
    }
};