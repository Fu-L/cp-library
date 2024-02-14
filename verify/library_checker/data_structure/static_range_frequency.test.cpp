#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"
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
        int l, r, x;
        cin >> l >> r >> x;
        cout << wm.range_freq(l, r, x + 1) - wm.range_freq(l, r, x) << '\n';
    }
}