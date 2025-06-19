#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/cumulative_sum_2d.hpp"
int main(void) {
    int n;
    cin >> n;
    CumulativeSum2D<int> cum(1001, 1001);
    rep(i, 0, n) {
        int xl, yl, xr, yr;
        cin >> xl >> yl >> xr >> yr;
        cum.add(xl, yl, 1);
        cum.add(xl, yr, -1);
        cum.add(xr, yl, -1);
        cum.add(xr, yr, 1);
    }
    cum.build();
    int ans = 0;
    rep(i, 0, 1001) {
        rep(j, 0, 1001) {
            ans = max(ans, cum.sum(0, 0, i, j));
        }
    }
    cout << ans << '\n';
}