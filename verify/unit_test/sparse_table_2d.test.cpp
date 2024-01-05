#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../src/template/template.hpp"
#include "../../src/template/random_number_generator.hpp"
#include "../../src/data_structure/sparse_table_2d.hpp"
int op(int a, int b) {
    return min(a, b);
}
int e() {
    return (int)1e9;
}
void test() {
    int h = rng(10, 100), w = rng(10, 100);
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, 0, h) {
        rep(j, 0, w) {
            a[i][j] = rng(0, (int)1e9);
        }
    }
    SparseTable2D<int, op, e> st(a);
    int query_num = 1000;
    while(query_num--) {
        int xl = rng(0, h), xr = rng(xl, h);
        int yl = rng(0, w), yr = rng(yl, w);
        int expected = 1e9;
        rep(i, xl, xr) {
            rep(j, yl, yr) {
                expected = min(expected, a[i][j]);
            }
        }
        assert(st.query(xl, xr, yl, yr) == expected);
    }
}
int main(void) {
    constexpr int test_num = 100;
    rep(i, 0, test_num) {
        test();
    }
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}