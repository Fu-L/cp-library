#pragma once
#include "../template/template.hpp"
struct RollingHash {
    RollingHash(const string& s, unsigned long long BASE = 0) {
        if(BASE == 0) {
            mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
            uniform_int_distribution<unsigned long long> dist(1ull << 10, 1ull << 60);
            BASE = dist(mt);
        }
        base = BASE;
        len = (int)s.size();
        pow.resize(len + 1);
        pow[0] = 1;
        for(int i = 1; i < len + 1; ++i) {
            pow[i] = calc_mod(mul(pow[i - 1], base));
        }
        hash.resize(len + 1);
        for(int i = 0; i < len; ++i) {
            hash[i + 1] = calc_mod(mul(hash[i], base) + s[i]);
        }
    }
    long long get(const int lower, const int upper) const {
        assert(0 <= lower and lower <= upper and upper <= len);
        return calc_mod(hash[upper] + POSITIVIZER - mul(hash[lower], pow[upper - lower]));
    }
    long long get_hash(const string& t) const {
        unsigned long long res = 0;
        for(int i = 0; i < (int)t.size(); ++i) {
            res = calc_mod(mul(res, base) + t[i]);
        }
        return res;
    }
    int find(const string& t, const int lower = 0) const {
        if((int)t.size() > len) return -1;
        const long long ha = get_hash(t);
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
    static constexpr unsigned long long MASK30 = (1ull << 30) - 1;
    static constexpr unsigned long long MASK31 = (1ull << 31) - 1;
    static constexpr unsigned long long MOD = (1ull << 61) - 1;
    static constexpr unsigned long long POSITIVIZER = MOD * ((1ull << 3) - 1);
    int len;
    unsigned long long base;
    vector<unsigned long long> pow;
    vector<unsigned long long> hash;
    inline unsigned long long mul(const unsigned long long x, const unsigned long long y) const {
        const unsigned long long xu = x >> 31;
        const unsigned long long xd = x & MASK31;
        const unsigned long long yu = y >> 31;
        const unsigned long long yd = y & MASK31;
        const unsigned long long middlebit = xd * yu + xu * yd;
        return ((xu * yu) << 1) + xd * yd + ((middlebit & MASK30) << 31) + (middlebit >> 30);
    }
    inline unsigned long long calc_mod(unsigned long long val) const {
        val = (val & MOD) + (val >> 61);
        if(val > MOD) val -= MOD;
        return val;
    }
};