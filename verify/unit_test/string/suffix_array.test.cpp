#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/string/suffix_array.hpp"
int main() {
    assert(suffix_array(string()).empty());
    assert(suffix_array(vector<int>()).empty());
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}