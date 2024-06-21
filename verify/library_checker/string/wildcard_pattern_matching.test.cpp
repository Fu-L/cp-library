#define PROBLEM "https://judge.yosupo.jp/problem/wildcard_pattern_matching"
#include "../../../src/template/template.hpp"
#include "../../../src/string/wildcard_pattern_matching.hpp"
int main(void) {
    string s, t;
    cin >> s >> t;
    vector<bool> ans = wildcard_pattrn_matching(s, t);
    rep(i, 0, (int)ans.size()) {
        cout << ans[i];
    }
    cout << '\n';
}