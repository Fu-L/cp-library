#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "src/template/template.hpp"
#include "src/data_structure/union_find.hpp"
int main(void) {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    while(q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0) {
            uf.merge(u, v);
        } else {
            cout << uf.same(u, v) << '\n';
        }
    }
}