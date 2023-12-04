#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct RandomNumberGenerator {
    mt19937_64 mt;
    RandomNumberGenerator()
        : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    inline ll operator()(const ll lower, const ll upper) {
        return num(lower, upper);
    }
    inline ll num(ll lower, ll upper) {
        uniform_int_distribution<ll> dist(lower, upper);
        return dist(mt);
    }
    inline vector<ll> vec(int n, ll lower, ll upper) {
        vector<ll> res(n);
        for(int i = 0; i < n; ++i) res[i] = num(lower, upper);
        return res;
    }
    inline vector<ll> perm(int n) {
        vector<ll> res(n);
        for(int i = 0; i < n; ++i) res[i] = i + 1;
        for(int i = n - 1; i > 0; --i) {
            swap(res[i], res[num(0, i)]);
        }
        return res;
    }
} rng;
struct RealRandomNumberGenerator {
    mt19937_64 mt;
    RealRandomNumberGenerator()
        : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    inline long double operator()(const long double lower, const long double upper) {
        return num(lower, upper);
    }
    inline long double num(long double lower, long double upper) {
        uniform_real_distribution<long double> dist(lower, upper);
        return dist(mt);
    }
    inline vector<long double> vec(int n, long double lower, long double upper) {
        vector<long double> res(n);
        for(int i = 0; i < n; ++i) res[i] = num(lower, upper);
        return res;
    }
} rrng;