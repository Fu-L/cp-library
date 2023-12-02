// vector<int> vec(n); SparseTable<int> st(vec); でSparseTableを構築。
// st.query(l,r); でvec[l]~vec[r-1]のminを求める。minをmax,gcd,lcmに変えることもできる。vecの更新はできない。
// string s; vector<int> sa=saffix_array(s); vector<int> lcp=lcp_array(s,sa); SparseTable<int> st(lcp);を求めておくと、
// int len=st.query(l,r); でsのsa[l]からとsa[r]からの接頭辞が何文字共通しているかが求められる。
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
    // [l, r)
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