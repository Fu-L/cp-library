#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/graph/kruskal.hpp"
int main(void) {
    int n, m;
    cin >> n >> m;
    Edges<ll> e(m);
    rep(i, 0, m) {
        cin >> e[i].from >> e[i].to >> e[i].cost;
        e[i].idx = i;
    }
    auto [cost, tree] = kruskal(n, e);
    cout << cost << '\n';
    rep(i, 0, n - 1) {
        cout << tree[i].idx << " \n"[i == n - 2];
    }
}