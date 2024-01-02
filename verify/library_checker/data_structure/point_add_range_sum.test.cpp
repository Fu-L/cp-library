#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/fenwick_tree.hpp"
int main(void) {
    int n, q;
    cin >> n >> q;
    FenwickTree<ll> fw(n);
    rep(i, 0, n) {
        ll a;
        cin >> a;
        fw.add(i, a);
    }
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            int p, x;
            cin >> p >> x;
            fw.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << '\n';
        }
    }
}