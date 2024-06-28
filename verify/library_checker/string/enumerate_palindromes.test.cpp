#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "../../../src/template/template.hpp"
#include "../../../src/string/manacher.hpp"
int main(void) {
    string s;
    cin >> s;
    vector<int> l = manacher(s);
    rep(i, 0, (int)l.size()) {
        cout << l[i] << " \n"[i + 1 == (int)s.size()];
    }
}