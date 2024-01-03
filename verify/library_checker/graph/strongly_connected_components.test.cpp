#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/graph/strongly_connected_components.hpp"
int main(void) {
    int n, m;
    cin >> n >> m;
    Graph<int> g(n);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        g.add_directed_edge(a, b);
    }
    vector<vector<int>> scc = strongly_connected_components(g);
    int k = scc.size();
    cout << k << '\n';
    rep(i, 0, k) {
        int l = scc[i].size();
        cout << l << ' ';
        rep(j, 0, l) {
            cout << scc[i][j] << " \n"[j + 1 == l];
        }
    }
}