#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/graph/dijkstra.hpp"
int main(void) {
    int n, m, s;
    cin >> n >> m >> s;
    Graph<ll> g(n);
    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        g.add_directed_edge(a, b, c);
    }
    vector<pair<ll, int>> d = dijkstra(g, s);
    rep(i, 0, n) {
        if(d[i].first == numeric_limits<ll>::max()) {
            cout << "INF" << '\n';
        } else {
            cout << d[i].first << '\n';
        }
    }
}