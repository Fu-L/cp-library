#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_A"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/graph/topological_sort.hpp"
int main(void) {
    int n, m;
    cin >> n >> m;
    Graph<int> g(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g.add_directed_edge(u, v);
    }
    vector<int> topo = topological_sort(g);
    if((int)topo.size() == 0) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}