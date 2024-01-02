#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "src/template/template.hpp"
#include "src/string/suffix_array.hpp"
int main(void) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> sa = suffix_array(s);
    rep(i, 0, n) {
        cout << sa[i] << " \n"[i + 1 == n];
    }
}