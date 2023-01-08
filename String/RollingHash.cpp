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
    const ll MASK30 = (1ll << 30) - 1;
    const ll MASK31 = (1ll << 31) - 1;
    const ll MOD = (1ll << 61) - 1;
    const ll POSITIVIZER = MOD * ((1ll << 3) - 1);
    ll base;
    vector<ll> pow;
    vector<ll> hash;
    RollingHash(string s, ll BASE = rng(1e8, 1e9)) {
        base = BASE;
        pow.resize(s.size() + 5);
        pow[0] = 1;
        rep(i, 1, (int)pow.size()) {
            pow[i] = calc_mod(mul(pow[i - 1], base));
        }
        hash.resize(s.size() + 1);
        rep(i, 0, (int)s.size()) {
            hash[i + 1] = calc_mod(mul(hash[i], base) + s[i]);
        }
    }
    ll mul(ll x, ll y) {
        ll xu = x >> 31;
        ll xd = x & MASK31;
        ll yu = y >> 31;
        ll yd = y & MASK31;
        ll middlebit = xd * yu + xu * yd;
        return ((xu * yu) << 1) + xd * yd + ((middlebit & MASK30) << 31) + (middlebit >> 30);
    }
    ll calc_mod(ll val) {
        val = (val & MOD) + (val >> 61);
        if(val > MOD) val -= MOD;
        return val;
    }
    ll get(int l, int r) {
        return calc_mod(hash[r] + POSITIVIZER - mul(hash[l], pow[r - l]));
    }
};
