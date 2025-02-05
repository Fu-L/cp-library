#pragma once
#include "../template/template.hpp"
template <typename S, auto op, auto e>
struct DisjointSparseTable {
    DisjointSparseTable(const vector<S>& v)
        : n((int)v.size() + 2) {
        const int b = 32 - __builtin_clz(n - 1);
        table.assign(b, vector<S>(n, e()));
        for(int k = 1; k < b; ++k) {
            const int w = (1 << k);
            for(int i = w; i < n; i += w * 2) {
                for(int j = i - 1; j > i - w; --j) {
                    table[k][j - 1] = op(table[k][j], v[j - 1]);
                }
                const int m = min(i + w - 1, n - 1);
                for(int j = i; j < m; ++j) {
                    table[k][j + 1] = op(table[k][j], v[j - 1]);
                }
            }
        }
    }
    S prod(const int l, int r) const {
        assert(0 <= l and l <= r and r <= n);
        ++r;
        const auto& s = table[31 - __builtin_clz(l xor r)];
        return op(s[l], s[r]);
    }

   private:
    int n;
    vector<vector<S>> table;
};