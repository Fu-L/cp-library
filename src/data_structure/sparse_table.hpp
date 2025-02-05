#pragma once
#include "../template/template.hpp"
template <typename S, auto op, auto e>
struct SparseTable {
    SparseTable(const vector<S>& v)
        : n((int)v.size()) {
        const int b = 32 - __builtin_clz(n);
        table.assign(b, vector<S>(n, e()));
        table[0] = v;
        for(int i = 1; i < b; ++i) {
            const int w = 1 << (i - 1);
            for(int j = 0; j + w * 2 <= n; ++j) {
                table[i][j] = op(table[i - 1][j], table[i - 1][j + w]);
            }
        }
    }
    S prod(const int l, const int r) const {
        assert(0 <= l and l <= r and r <= n);
        if(l == r) return e();
        const int b = 31 - __builtin_clz(r - l);
        return op(table[b][l], table[b][r - (1 << b)]);
    }

   private:
    int n;
    vector<vector<S>> table;
};