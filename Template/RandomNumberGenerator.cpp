struct RandomNumberGenerator {
    mt19937_64 mt;
    RandomNumberGenerator()
        : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    inline ll operator()(const ll l, const ll r) {
        uniform_int_distribution<ll> dist(l, r);
        return dist(mt);
    }
} rng;

struct RealRandomNumberGenerator {
    mt19937_64 mt;
    RealRandomNumberGenerator()
        : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    inline long double operator()(const long double l, const long double r) {
        uniform_real_distribution<long double> dist(l, r);
        return dist(mt);
    }
} rrng;