#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C"
#include "../../../src/template/template.hpp"
#include "../../../src/math/seive.hpp"
int main(void) {
    auto [prime, min_factor] = seive(100000000);
    int n;
    cin >> n;
    int ans = 0;
    rep(i, 0, n) {
        int m;
        cin >> m;
        if(min_factor[m] == m) ans++;
    }
    cout << ans << '\n';
}