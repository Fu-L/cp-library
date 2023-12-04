#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct SparseTable {
    SparseTable(const vector<T>& v)
        : n((int)v.size()) {
        int b = 1;
        while((1 << b) <= n) ++b;
        table.push_back(v);
        for(int i = 1; i < b; ++i) {
            table.push_back(vector<T>(n, e()));
            for(int j = 0; j + (1 << i) <= n; ++j) {
                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    T query(int l, int r) const {
        assert(0 <= l and l <= r and r <= n);
        if(l == r) return e();
        int b = 31 - __builtin_clz(r - l);
        return op(table[b][l], table[b][r - (1 << b)]);
    }

   private:
    inline static constexpr T INF = numeric_limits<T>::max() / 2;
    int n;
    vector<vector<T>> table;
    inline T op(const T& a, const T& b) const {
        return min(a, b);
    }
    inline T e() const {
        return INF;
    }
};