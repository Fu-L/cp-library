#define PROBLEM "https://yukicoder.me/problems/481"
#include "../../src/template/template.hpp"
#include "../../src/math/xor_base.hpp"
int main(void) {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> base = xor_base(a);
    ll ans = 1;
    rep(i, 0, (int)base.size()) ans *= 2;
    cout << ans << '\n';
}