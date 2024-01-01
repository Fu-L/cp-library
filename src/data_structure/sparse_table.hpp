#pragma once
#include "src/template/template.hpp"
template <typename S, auto op, auto e>
struct SparseTable {
    SparseTable(const vector<S>& v)
        : n((int)v.size()) {
        int b = 1;
        while((1 << b) <= n) ++b;
        table.push_back(v);
        for(int i = 1; i < b; ++i) {
            table.push_back(vector<S>(n, e()));
            for(int j = 0; j + (1 << i) <= n; ++j) {
                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    S query(int l, int r) const {
        assert(0 <= l and l <= r and r <= n);
        if(l == r) return e();
        int b = 31 - __builtin_clz(r - l);
        return op(table[b][l], table[b][r - (1 << b)]);
    }

   private:
    int n;
    vector<vector<S>> table;
};