struct RandomNumberGenerator {
    mt19937_64 mt;
    RandomNumberGenerator()
        : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    ll operator()(ll l, ll r) {
        uniform_int_distribution<ll> dist(l, r);
        return dist(mt);
    }
} rng;

struct RealRandomNumberGenerator {
    mt19937_64 mt;
    RealRandomNumberGenerator()
        : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    long double operator()(long double l, long double r) {
        uniform_real_distribution<long double> dist(l, r);
        return dist(mt);
    }
} rrng;
