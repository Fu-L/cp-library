struct RandomNumberGenerator {
    mt19937_64 mt;
    RandomNumberGenerator()
        : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    ll operator()(ll l, ll r) {
        uniform_int_distribution<ll> dist(l, r);
        return dist(mt);
    }
} rng;
struct RollingHash {
    using ull = unsigned long long;
    const ull MASK30 = (1ull << 30) - 1;
    const ull MASK31 = (1ull << 31) - 1;
    const ull MOD = (1ull << 61) - 1;
    const ull POSITIVIZER = MOD * ((1ull << 3) - 1);
    int len;
    ll base;
    vector<ull> pow;
    vector<ull> hash;
    RollingHash(string s, ll BASE = rng(1e8, 1e9)) {
        len = s.size();
        base = BASE;
        pow.resize(len + 5);
        pow[0] = 1;
        rep(i, 1, (int)pow.size()) {
            pow[i] = calc_mod(mul(pow[i - 1], base));
        }
        hash.resize(len + 1);
        rep(i, 0, (int)len) {
            hash[i + 1] = calc_mod(mul(hash[i], base) + s[i]);
        }
    }
    ull mul(ull x, ull y) {
        ll xu = x >> 31;
        ll xd = x & MASK31;
        ll yu = y >> 31;
        ll yd = y & MASK31;
        ll middlebit = xd * yu + xu * yd;
        return ((xu * yu) << 1) + xd * yd + ((middlebit & MASK30) << 31) + (middlebit >> 30);
    }
    ll calc_mod(ull val) {
        val = (val & MOD) + (val >> 61);
        if(val > MOD) val -= MOD;
        return val;
    }
    ll get(int l, int r) {
        assert(0 <= l and l <= r and r <= len);
        return calc_mod(hash[r] + POSITIVIZER - mul(hash[l], pow[r - l]));
    }
    ll get_hash(string &t) {
        ll res = 0;
        rep(i, 0, (int)t.size()) {
            res = calc_mod(mul(res, base) + t[i]);
        }
        return res;
    }
    int find(string &t, int lower = 0) {
        ll ha = get_hash(t);
        rep(i, lower, len - (int)t.size() + 1) {
            if(ha == get(i, i + (int)t.size())) return i;
        }
        return -1;
    }
    int LCP(RollingHash &a, RollingHash &b, int al, int bl) {
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
};
