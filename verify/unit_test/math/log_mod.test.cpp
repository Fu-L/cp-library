#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/math/log_mod.hpp"
ll brute(ll a, ll b, ll mod) {
    a %= mod;
    b %= mod;
    if(a < 0) a += mod;
    if(b < 0) b += mod;
    ll cur = 1 % mod;
    rep(k, 0, 100) {
        if(cur == b) return k;
        cur = cur * a % mod;
    }
    return -1;
}
int main() {
    rep(mod, 1, 50) {
        rep(a, -50, 50) {
            rep(b, -50, 50) {
                assert(log_mod(a, b, mod) == brute(a, b, mod));
            }
        }
    }
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}