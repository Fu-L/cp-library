#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/fenwick_tree_on_wavelet_matrix.hpp"
int main(void) {
    int n, q;
    cin >> n >> q;
    FenwickTreeonWaveletMatrix<int, ll> wm;
    vector<int> x(n), y(n), w(n);
    rep(i, 0, n) {
        cin >> x[i] >> y[i] >> w[i];
        wm.add_point(x[i], y[i]);
    }
    vector<int> t(q), xq(q), yq(q), wq(q), l(q), d(q), r(q), u(q);
    rep(i, 0, q) {
        cin >> t[i];
        if(t[i] == 0) {
            cin >> xq[i] >> yq[i] >> wq[i];
            wm.add_point(xq[i], yq[i]);
        } else {
            cin >> l[i] >> d[i] >> r[i] >> u[i];
        }
    }
    wm.build();
    rep(i, 0, n) {
        wm.add(x[i], y[i], w[i]);
    }
    rep(i, 0, q) {
        if(t[i] == 0) {
            wm.add(xq[i], yq[i], wq[i]);
        } else {
            cout << wm.sum(l[i], d[i], r[i], u[i]) << '\n';
        }
    }
}