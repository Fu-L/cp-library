#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/data_structure/weighted_union_find.hpp"
using mint = modint998244353;
int main(void) {
    int n, q;
    cin >> n >> q;
    WeightedUnionFind<mint> uf(n);
    while(q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0) {
            int x;
            cin >> x;
            cout << uf.merge(u, v, x) << '\n';
        } else {
            if(!uf.same(u, v)) {
                cout << -1 << '\n';
            } else {
                cout << uf.diff(u, v) << '\n';
            }
        }
    }
}