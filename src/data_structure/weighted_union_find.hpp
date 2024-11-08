#pragma once
#include "../template/template.hpp"
template <typename T>
struct WeightedUnionFind {
    WeightedUnionFind(const int N)
        : n(N), data(N, -1), ws(N, T()) {}
    bool merge(const int a, const int b, T w) {
        assert(0 <= a and a < n);
        assert(0 <= b and b < n);
        w += weight(b) - weight(a);
        int x = leader(a), y = leader(b);
        if(x == y) return w == T();
        if(-data[x] > -data[y]) swap(x, y), w = -w;
        data[y] += data[x];
        data[x] = y;
        ws[x] = w;
        return true;
    }
    bool same(const int a, const int b) {
        assert(0 <= a and a < n);
        assert(0 <= b and b < n);
        return leader(a) == leader(b);
    }
    int leader(const int a) {
        assert(0 <= a and a < n);
        if(data[a] < 0) return a;
        const int r = leader(data[a]);
        ws[a] += ws[data[a]];
        return data[a] = r;
    }
    int size(const int a) {
        assert(0 <= a and a < n);
        return -data[leader(a)];
    }
    T weight(const int a) {
        assert(0 <= a and a < n);
        leader(a);
        return ws[a];
    }
    T diff(const int a, const int b) {
        assert(0 <= a and a < n);
        assert(0 <= b and b < n);
        return weight(a) - weight(b);
    }

   private:
    int n;
    vector<int> data;
    vector<T> ws;
};