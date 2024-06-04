#pragma once
#include "../template/template.hpp"
#include "../template/policy_based_data_structure.hpp"
long long log_mod(long long a, long long b, long long mod) {
    assert(mod >= 1);
    long long g = 1;
    for(long long i = mod; i; i /= 2) (g *= a) %= mod;
    g = gcd(g, mod);
    long long t = 1, c = 0;
    for(; t % g; ++c) {
        if(t == b) return c;
        (t *= a) %= mod;
    }
    if(b % g) return -1;
    t /= g;
    b /= g;
    long long n = mod / g, h = 0, gs = 1;
    for(; h * h < n; ++h) (gs *= a) %= n;
    gp_hash_table<long long, long long> ht;
    for(long long s = 0, e = b; s < h; ht[e] = ++s) {
        (e *= a) %= n;
    }
    for(long long s = 0, e = t; s < n;) {
        (e *= gs) %= n;
        s += h;
        if(ht.find(e) != ht.end()) return c + s - ht[e];
    }
    return -1;
}