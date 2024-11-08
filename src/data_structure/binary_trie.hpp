#pragma once
#include "../template/template.hpp"
template <typename T, int MAX_LOG>
struct BinaryTrie {
    BinaryTrie()
        : root(new Node) {}
    void insert(const T& x) {
        assert(0 <= x and x < (T(1) << MAX_LOG));
        if(!contains(x)) update(x, 1);
    }
    void erase(const T& x) {
        assert(0 <= x and x < (T(1) << MAX_LOG));
        if(contains(x)) update(x, -1);
    }
    bool contains(const T& x) const {
        assert(0 <= x and x < (T(1) << MAX_LOG));
        Node* cur = root;
        for(int i = MAX_LOG - 1; i >= 0; --i) {
            if(!cur) break;
            const int nex = (x >> i) & 1;
            cur = cur->child[nex];
        }
        return cur and cur->cnt;
    }
    int size() const {
        return root->cnt;
    }
    T min(const T& x = 0) const {
        assert(root->cnt > 0);
        assert(0 <= x and x < (T(1) << MAX_LOG));
        return kth_element(0, x);
    }
    T max(const T& x = 0) const {
        assert(root->cnt > 0);
        assert(0 <= x and x < (T(1) << MAX_LOG));
        return kth_element(root->cnt - 1, x);
    }
    T kth_element(int k, const T& x = 0) const {
        assert(0 <= k and k < root->cnt);
        assert(0 <= x and x < (T(1) << MAX_LOG));
        T res = 0;
        Node* cur = root;
        for(int i = MAX_LOG - 1; i >= 0; --i) {
            const int nex = (x >> i) & 1;
            const int cnt = (cur->child[nex] ? cur->child[nex]->cnt : 0);
            if(cnt <= k) {
                k -= cnt;
                res += T(1) << i;
                cur = cur->child[nex ^ 1];
            } else {
                cur = cur->child[nex];
            }
        }
        return res;
    }
    int lower_bound(const T& val, const T& x = 0) const {
        assert(0 <= val and val < (T(1) << MAX_LOG));
        assert(0 <= x and x < (T(1) << MAX_LOG));
        int res = 0;
        Node* cur = root;
        for(int i = MAX_LOG - 1; i >= 0; --i) {
            if(!cur) break;
            const int xi = (x >> i) & 1, vi = (val >> i) & 1;
            const int nex = xi xor vi;
            if(vi and cur->child[xi]) {
                res += cur->child[xi]->cnt;
            }
            cur = cur->child[nex];
        }
        return res;
    }
    int upper_bound(const T& val, const T& x = 0) const {
        assert(0 <= val and val < (T(1) << MAX_LOG));
        assert(0 <= x and x < (T(1) << MAX_LOG));
        return lower_bound(val + 1, x);
    }

   private:
    struct Node {
        Node* child[2] = {};
        int cnt = 0;
        Node() {}
    };
    Node* root;
    void update(const T& x, const int delta) {
        Node* cur = root;
        cur->cnt += delta;
        for(int i = MAX_LOG - 1; i >= 0; --i) {
            const int nex = (x >> i) & 1;
            if(!cur->child[nex]) {
                cur->child[nex] = new Node;
            }
            cur = cur->child[nex];
            cur->cnt += delta;
        }
    }
};