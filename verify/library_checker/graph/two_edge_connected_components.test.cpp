#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/graph/two_edge_connected_components.hpp"
int main(void) {
    int n, m;
    cin >> n >> m;
    Graph<int> g(n);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b);
    }
    TwoEdgeConnectedComponents<int> low(g);
    int k = low.groups.size();
    cout << k << '\n';
    rep(i, 0, k) {
        int l = low.groups[i].size();
        cout << l << ' ';
        rep(j, 0, l) {
            cout << low.groups[i][j] << " \n"[j + 1 == l];
        }
    }
}