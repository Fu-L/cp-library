#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_C"
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
    vector<int> idx(n);
    rep(i, 0, (int)scc.size()) {
        rep(j, 0, (int)scc[i].size()) {
            idx[scc[i][j]] = i;
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        if(idx[u] == idx[v]) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}