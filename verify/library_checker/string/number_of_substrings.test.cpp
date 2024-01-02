#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include "src/template/template.hpp"
#include "src/string/rolling_hash.hpp"
#include "src/string/suffix_array.hpp"
int main(void) {
    string s;
    cin >> s;
    ll n = s.size();
    RollingHash rh(s);
    ll ans = n * (n + 1) / 2;
    vector<int> sa = suffix_array(s);
    rep(i, 0, n - 1) {
        ans -= rh.lcp(rh, rh, sa[i], sa[i + 1]);
    }
    cout << ans << '\n';
}