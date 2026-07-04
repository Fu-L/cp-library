#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/sparse_table.hpp"
int op(int a, int b) {
    return min(a, b);
}
int e() {
    return (int)1e9;
}
int main() {
    SparseTable<int, op, e> st(vector<int>{});
    assert(st.prod(0, 0) == e());
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}