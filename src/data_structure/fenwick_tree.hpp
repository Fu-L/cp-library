#pragma once
#include "../template/template.hpp"
template <typename T>
struct FenwickTree {
    FenwickTree(const int N)
        : n(N), data(N) {}
    void add(int p, const T& x) {
        assert(0 <= p and p < n);
        ++p;
        while(p <= n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }
    T sum(const int l, const int r) const {
        assert(0 <= l and l <= r and r <= n);
        return sum(r) - sum(l);
    }
    T get(const int x) const {
        assert(0 <= x and x < n);
        return sum(x + 1) - sum(x);
    }

   private:
    int n;
    vector<T> data;
    inline T sum(int r) const {
        T s = 0;
        while(r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};