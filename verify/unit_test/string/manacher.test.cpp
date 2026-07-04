#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/string/manacher.hpp"
int main() {
    assert(manacher(string()).empty());
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}