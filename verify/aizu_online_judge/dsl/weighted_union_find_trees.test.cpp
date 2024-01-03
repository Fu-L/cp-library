#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/weighted_union_find.hpp"
int main(void) {
    int n, q;
    cin >> n >> q;
    WeightedUnionFind<int> uf(n);
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            int x, y, z;
            cin >> x >> y >> z;
            uf.merge(y, x, z);
        } else {
            int x, y;
            cin >> x >> y;
            if(uf.same(x, y)) {
                cout << uf.diff(y, x) << '\n';
            } else {
                cout << '?' << '\n';
            }
        }
    }
}