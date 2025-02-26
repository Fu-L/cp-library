#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"
#include "../../../src/template/template.hpp"
#include "../../../src/dp/longest_increasing_sequence.hpp"
int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> lis = longest_increasing_sequence(a);
    cout << lis.size() << '\n';
    rep(i, 0, (int)lis.size()) cout << lis[i] << " \n"[i + 1 == (int)lis.size()];
}