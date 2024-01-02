#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include "src/template/template.hpp"
#include "src/string/suffix_array.hpp"
int main(void) {
    string s;
    cin >> s;
    vector<int> sa = suffix_array(s);
    vector<int> lcp = lcp_array(s, sa);
    ll sum = 0;
    rep(i, 0, (int)lcp.size()) {
        sum += (i + 1) - lcp[i];
    }
    cout << sum + (int)s.size() << '\n';
}