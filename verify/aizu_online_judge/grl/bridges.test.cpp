#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/graph/low_link.hpp"
int main(void) {
    int n, m;
    cin >> n >> m;
    Graph<int> g(n);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b);
    }
    LowLink<int> low(g);
    sort(low.bridge.begin(), low.bridge.end());
    for(const pair<int, int>& bri : low.bridge) {
        cout << bri.first << ' ' << bri.second << '\n';
    }
}