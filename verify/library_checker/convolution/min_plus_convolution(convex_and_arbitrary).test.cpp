#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary"
#include "../../../src/template/template.hpp"
#include "../../../src/convolution/min_plus_convolution.hpp"
int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    vector<int> c = min_plus_convolution(a, b);
    rep(i, 0, n + m - 1) {
        cout << c[i] << " \n"[i + 1 == n + m - 1];
    }
}