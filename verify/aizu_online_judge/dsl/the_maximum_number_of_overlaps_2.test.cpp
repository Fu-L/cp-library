#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/fenwick_tree_2d.hpp"
int main(void) {
    int n;
    cin >> n;
    FenwickTree2D<int> fw(1001, 1001);
    rep(i, 0, n) {
        int xl, yl, xr, yr;
        cin >> xl >> yl >> xr >> yr;
        fw.add(xl, yl, 1);
        fw.add(xl, yr, -1);
        fw.add(xr, yl, -1);
        fw.add(xr, yr, 1);
    }
    int ans = 0;
    rep(i, 0, 1001) {
        rep(j, 0, 1001) {
            ans = max(ans, fw.sum(0, 0, i, j));
        }
    }
    cout << ans << '\n';
}