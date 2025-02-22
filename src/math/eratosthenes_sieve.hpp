#pragma once
#include "../template/template.hpp"
struct EratosthenesSieve {
    vector<int> primes, min_factor, moebius, euler;
    EratosthenesSieve(const int N)
        : primes(), min_factor(N + 1), moebius(N + 1, 1), euler(N + 1), N(N) {
        assert(N >= 1);
        iota(min_factor.begin(), min_factor.end(), 0);
        min_factor[0] = min_factor[1] = -1;
        iota(euler.begin(), euler.end(), 0);
        for(int i = 2; i <= N; ++i) {
            if(min_factor[i] < i) continue;
            primes.emplace_back(i);
            moebius[i] = -1;
            euler[i] = euler[i] / i * (i - 1);
            for(int j = i * 2; j <= N; j += i) {
                if(min_factor[j] == j) min_factor[j] = i;
                if((j / i) % i == 0) moebius[j] = 0;
                else moebius[j] = -moebius[j];
                euler[j] = euler[j] / i * (i - 1);
            }
        }
    }
    vector<pair<int, int>> prime_factors(int n) const {
        assert(1 <= n and n <= N);
        vector<pair<int, int>> res;
        while(n > 1) {
            const int p = min_factor[n];
            int exp = 0;
            while(min_factor[n] == p) {
                n /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }
    vector<int> divisor(const int n) const {
        assert(1 <= n and n <= n);
        vector<int> res({1});
        const auto pf = prime_factors(n);
        for(const auto& p : pf) {
            const int s = (int)res.size();
            for(int i = 0; i < s; ++i) {
                int v = 1;
                for(int j = 0; j < p.second; ++j) {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }

   private:
    int N;
};