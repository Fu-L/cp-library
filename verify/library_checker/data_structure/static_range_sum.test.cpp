#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/disjoint_sparse_table.hpp"
ll op(ll x, ll y) {
    return x + y;
}
ll e() {
    return 0;
}
int main(void) {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    DisjointSparseTable<ll, op, e> dst(a);
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << dst.prod(l, r) << '\n';
    }
}