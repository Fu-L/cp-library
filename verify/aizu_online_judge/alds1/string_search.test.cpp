#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"
#include "src/template/template.hpp"
#include "src/string/rolling_hash.hpp"
int main(void) {
    string t, p;
    cin >> t >> p;
    int n = t.size(), m = p.size();
    RollingHash rh(t);
    ll ha = rh.get_hash(p);
    rep(i, 0, n - m + 1) {
        if(rh.get(i, i + m) == ha) {
            cout << i << '\n';
        }
    }
}