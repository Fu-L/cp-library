#pragma once
#include "src/template/template.hpp"
pair<vector<int>, vector<bool>> seive(int n) {
    assert(n >= 1);
    vector<bool> is_prime(n + 1, true);
    vector<int> prime;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; ++i) {
        if(is_prime[i]) {
            prime.push_back(i);
            for(int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return {prime, is_prime};
}