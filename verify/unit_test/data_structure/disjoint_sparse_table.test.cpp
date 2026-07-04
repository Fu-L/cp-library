#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/disjoint_sparse_table.hpp"
int op(int a, int b) {
    return min(a, b);
}
int e() {
    return (int)1e9;
}
int main() {
    DisjointSparseTable<int, op, e> dst(vector<int>{});
    assert(dst.prod(0, 0) == e());
    DisjointSparseTable<int, op, e> dst2(vector<int>{5, 2, 7});
    assert(dst2.prod(0, 0) == e());
    assert(dst2.prod(0, 3) == 2);
    assert(dst2.prod(2, 3) == 7);
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}