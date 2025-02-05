#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/disjoint_sparse_table.hpp"
int op(int x, int y) {
    return min(x, y);
}
int e() {
    return 1e9;
}
int main(void) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    DisjointSparseTable<int, op, e> dst(a);
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << dst.prod(l, r) << '\n';
    }
}