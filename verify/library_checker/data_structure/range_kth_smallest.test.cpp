#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/wavelet_matrix.hpp"
int main(void) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    WaveletMatrix<int> wm(a);
    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << wm.kth_smallest(l, r, k) << '\n';
    }
}