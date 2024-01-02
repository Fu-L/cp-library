#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
#include "src/template/template.hpp"
#include "src/data_structure/fenwick_tree.hpp"
#include "src/data_structure/mo.hpp"
int main(void) {
    int n, q;
    cin >> n >> q;
    Mo mo(n, q);
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> comp = a;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    rep(i, 0, n) a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
    rep(i, 0, q) {
        int l, r;
        cin >> l >> r;
        mo.insert(l, r);
    }
    vector<ll> ans(q);
    FenwickTree<int> fw(n);
    ll cnt = 0;
    auto add_left = [&](int idx) {
        cnt += fw.sum(0, a[idx]);
        fw.add(a[idx], 1);
    };
    auto add_right = [&](int idx) {
        cnt += fw.sum(a[idx] + 1, n);
        fw.add(a[idx], 1);
    };
    auto delete_left = [&](int idx) {
        cnt -= fw.sum(0, a[idx]);
        fw.add(a[idx], -1);
    };
    auto delete_right = [&](int idx) {
        cnt -= fw.sum(a[idx] + 1, n);
        fw.add(a[idx], -1);
    };
    auto out = [&](int idx) {
        ans[idx] = cnt;
    };
    mo.run(add_left, add_right, delete_left, delete_right, out);
    rep(i, 0, q) {
        cout << ans[i] << '\n';
    }
}