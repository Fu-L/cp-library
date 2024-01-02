#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../../../src/template/template.hpp"
#include "../../../src/string/z_algorithm.hpp"
int main(void) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z = z_algorithm(s);
    rep(i, 0, n) {
        cout << z[i] << " \n"[i + 1 == n];
    }
}