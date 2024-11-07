#pragma once
#include "../template/template.hpp"
#include "../template/modint_2_61m1.hpp"
struct RollingHash {
    using mint = Modint_2_61m1;
    RollingHash(const string& s, unsigned long long BASE = 0)
        : len((int)s.size()), pow(len + 1), hash(len + 1) {
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
        for(int i = 0; i < len; ++i) {
            hash[i + 1] = hash[i] * base + s[i];
        }
    }
    unsigned long long get(const int lower, const int upper) const {
        assert(0 <= lower and lower <= upper and upper <= len);
        return (hash[upper] - hash[lower] * pow[upper - lower]).val();
    }
    unsigned long long get_hash(const string& t) const {
        mint res = 0;
        for(int i = 0; i < (int)t.size(); ++i) {
            res = res * base + t[i];
        }
        return res.val();
    }
    int find(const string& t, const int lower = 0) const {
        if((int)t.size() > len) return -1;
        const unsigned long long ha = get_hash(t);
        for(int i = lower; i < len - (int)t.size() + 1; ++i) {
            if(ha == get(i, i + (int)t.size())) return i;
        }
        return -1;
    }
    int lcp(const RollingHash& a, const RollingHash& b, const int al, const int bl) const {
        int ok = 0, ng = min(a.len - al, b.len - bl) + 1;
        while(ok + 1 < ng) {
            const int med = (ok + ng) / 2;
            if(a.get(al, med + al) == b.get(bl, med + bl)) {
                ok = med;
            } else {
                ng = med;
            }
        }
        return ok;
    }

   private:
    int len;
    mint base;
    vector<mint> pow;
    vector<mint> hash;
};