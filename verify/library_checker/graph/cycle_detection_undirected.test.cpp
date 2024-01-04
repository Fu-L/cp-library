#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection_undirected"
#include "src/template/template.hpp"
#include "src/graph/graph_template.hpp"
#include "src/graph/cycle_detection.hpp"
int main(void) {
    int n, m;
    cin >> n >> m;
    Graph<int> g(n);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b);
    }
    Edges<int> cycle = cycle_detection(g, false);
    if(cycle.empty()) {
        cout << -1 << '\n';
        return 0;
    }
    cout << cycle.size() << '\n';
    for(const Edge<int>& e : cycle) {
        cout << e.from << ' ';
    }
    cout << '\n';
    for(const Edge<int>& e : cycle) {
        cout << e.idx << ' ';
    }
    cout << '\n';
}