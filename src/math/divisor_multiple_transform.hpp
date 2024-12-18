#pragma once
#include "../template/template.hpp"
#include "./eratosthenes_sieve.hpp"
struct DivisorTransform {
    template <typename T>
    static void zeta_transform(vector<T>& f) {
        const int N = f.size() - 1;
        const auto sieve = EratosthenesSieve(N).primes;
        for(const auto& p : sieve) {
            for(int k = 1; k * p <= N; ++k) f[k * p] += f[k];
        }
    }
    template <typename T>
    static void moebius_transform(vector<T>& g) {
        const int N = g.size() - 1;
        const auto sieve = EratosthenesSieve(N).primes;
        for(const auto& p : sieve) {
            for(int k = N / p; k > 0; --k) g[k * p] -= g[k];
        }
    }
};
struct MultipleTransform {
    template <typename T>
    static void zeta_transform(vector<T>& f) {
        const int N = f.size() - 1;
        const auto sieve = EratosthenesSieve(N).primes;
        for(const auto& p : sieve) {
            for(int k = N / p; k > 0; --k) f[k] += f[k * p];
        }
    }
    template <typename T>
    static void moebius_transform(vector<T>& g) {
        const int N = g.size() - 1;
        const auto sieve = EratosthenesSieve(N).primes;
        for(const auto& p : sieve) {
            for(int k = 1; k * p <= N; ++k) g[k] -= g[k * p];
        }
    }
};