#pragma once
#include "../template/template.hpp"
struct EratosthenesSeive {
    vector<int> primes, min_factor, moebius, euler;
    EratosthenesSeive(const int n)
        : primes(), min_factor(n + 1), moebius(n + 1, 1), euler(n + 1) {
        assert(n >= 1);
        iota(min_factor.begin(), min_factor.end(), 0);
        min_factor[0] = min_factor[1] = -1;
        iota(euler.begin(), euler.end(), 0);
        for(int i = 2; i <= n; ++i) {
            if(min_factor[i] < i) continue;
            primes.emplace_back(i);
            moebius[i] = -1;
            euler[i] = euler[i] / i * (i - 1);
            for(int j = i * 2; j <= n; j += i) {
                if(min_factor[j] == j) min_factor[j] = i;
                if((j / i) % i == 0) moebius[j] = 0;
                else moebius[j] = -moebius[j];
                euler[j] = euler[j] / i * (i - 1);
            }
        }
    }
};