#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct RandomNumberGenerator {
    mt19937_64 mt;
    RandomNumberGenerator()
        : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    inline ll operator()(ll lower, ll upper) {
        assert(lower <= upper);
        uniform_int_distribution<ll> dist(lower, upper);
        return dist(mt);
    }
} rng;
struct RollingHash {
    using ull = unsigned long long;
    RollingHash(const string &s, ll BASE = rng(1e8, 1e9)) {
        len = (int)s.size();
        base = BASE;
        pow.resize(len + 5);
        pow[0] = 1;
        for(int i = 1; i < len + 5; ++i) {
            pow[i] = calc_mod(mul(pow[i - 1], base));
        }
        hash.resize(len + 1);
        for(int i = 0; i < len; ++i) {
            hash[i + 1] = calc_mod(mul(hash[i], base) + s[i]);
        }
    }
    ll get(int lower, int upper) const {
        assert(0 <= lower and lower <= upper and upper <= len);
        return calc_mod(hash[upper] + POSITIVIZER - mul(hash[lower], pow[upper - lower]));
    }
    ll get_hash(const string &t) const {
        ll res = 0;
        for(int i = 0; i < (int)t.size(); ++i) {
            res = calc_mod(mul(res, base) + t[i]);
        }
        return res;
    }
    int find(const string &t, int lower = 0) const {
        ll ha = get_hash(t);
        for(int i = lower; i < len - (int)t.size() + 1; ++i) {
            if(ha == get(i, i + (int)t.size())) return i;
        }
        return -1;
    }
    int LCP(const RollingHash &a, const RollingHash &b, int al, int bl) const {
        int ok = 0, ng = min(a.len - al, b.len - bl) + 1;
        while(ok + 1 < ng) {
            int med = (ok + ng) / 2;
            if(a.get(al, med + al) == b.get(bl, med + bl)) {
                ok = med;
            } else {
                ng = med;
            }
        }
        return ok;
    }

   private:
    const ull MASK30 = (1ull << 30) - 1;
    const ull MASK31 = (1ull << 31) - 1;
    const ull MOD = (1ull << 61) - 1;
    const ull POSITIVIZER = MOD * ((1ull << 3) - 1);
    int len;
    ll base;
    vector<ull> pow;
    vector<ull> hash;
    inline ull mul(ull x, ull y) const {
        ll xu = x >> 31;
        ll xd = x & MASK31;
        ll yu = y >> 31;
        ll yd = y & MASK31;
        ll middlebit = xd * yu + xu * yd;
        return ((xu * yu) << 1) + xd * yd + ((middlebit & MASK30) << 31) + (middlebit >> 30);
    }
    inline ll calc_mod(ull val) const {
        val = (val & MOD) + (val >> 61);
        if(val > MOD) val -= MOD;
        return val;
    }
};