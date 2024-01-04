#define PROBLEM "https://yukicoder.me/problems/no/186"
#include "../../src/template/template.hpp"
#include "../../src/math/chinese_remainder_theorem.hpp"
int main(void) {
    vector<ll> x(3), y(3);
    rep(i, 0, 3) cin >> x[i] >> y[i];
    P ans = chinese_remainder_theorem(x, y);
    if(ans == P(0, 0)) {
        cout << -1 << '\n';
    } else {
        if(ans.first == 0) ans.first = ans.second;
        cout << ans.first << '\n';
    }
}