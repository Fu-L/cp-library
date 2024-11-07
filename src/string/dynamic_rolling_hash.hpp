#pragma once
#include "../template/template.hpp"
#include "../template/modint_2_61m1.hpp"
#include "../data_structure/fenwick_tree.hpp"
struct DynamicRollingHash {
    using mint = Modint_2_61m1;
    DynamicRollingHash(const string& s, unsigned long long BASE = 0)
        : len((int)s.size()), pow(len + 1), inv_pow(len + 1), hash(len) {
        if(BASE == 0) {
            mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
            uniform_int_distribution<unsigned long long> dist(1ull << 10, 1ull << 60);
            BASE = dist(mt);
        }
        base = BASE;
        pow[0] = 1;
        for(int i = 0; i < len; ++i) {
            pow[i + 1] = pow[i] * base;
        }
        inv = base.inv();
        inv_pow[0] = 1;
        for(int i = 0; i < len; ++i) {
            inv_pow[i + 1] = inv_pow[i] * inv;
        }
        for(int i = 0; i < len; ++i) {
            hash.add(i, pow[i] * s[i]);
        }
    }
    unsigned long long get(const int lower, const int upper) const {
        assert(0 <= lower and lower <= upper and upper <= len);
        return (hash.sum(lower, upper) * inv_pow[lower]).val();
    }
    unsigned long long get_hash(const string& t) const {
        mint res = 0;
        for(int i = 0; i < (int)t.size(); ++i) {
            res += pow[i] * t[i];
        }
        return res.val();
    }
    void set(const int idx, const char c) {
        assert(0 <= idx and idx < len);
        hash.add(idx, pow[idx] * c - hash.get(idx));
    }

   private:
    int len;
    mint base, inv;
    vector<mint> pow, inv_pow;
    FenwickTree<mint> hash;
};