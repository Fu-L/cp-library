#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/template/debug.hpp"
void test() {
    vector<int> v = {1, 2, 3};
    debug(v);
}
int main(void) {
    test();
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}
