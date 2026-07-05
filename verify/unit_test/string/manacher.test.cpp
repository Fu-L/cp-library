#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/string/manacher.hpp"
vector<int> brute(const string& s) {
    const int n = (int)s.size();
    if(n == 0) return {};
    vector<int> res(2 * n - 1);
    for(int c = 0; c < 2 * n - 1; ++c) {
        for(int len = (c % 2 == 0);; len += 2) {
            const int l = (c - len + 1) / 2;
            const int r = (c + len + 1) / 2;
            if(l < 0 or n < r) break;
            bool ok = true;
            for(int i = l, j = r - 1; i < j; ++i, --j) {
                if(s[i] != s[j]) {
                    ok = false;
                    break;
                }
            }
            if(ok) res[c] = len;
        }
    }
    return res;
}
int main() {
    assert(manacher(string()).empty());
    assert(manacher(string("ab")) == vector<int>({1, 0, 1}));
    assert(manacher(string("aa")) == vector<int>({1, 2, 1}));
    assert(manacher(string("abba")) == vector<int>({1, 0, 1, 4, 1, 0, 1}));
    for(int n = 0; n <= 9; ++n) {
        for(int bit = 0; bit < (1 << n); ++bit) {
            string s(n, 'a');
            for(int i = 0; i < n; ++i) {
                if((bit >> i) & 1) s[i] = 'b';
            }
            assert(manacher(s) == brute(s));
        }
    }
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}