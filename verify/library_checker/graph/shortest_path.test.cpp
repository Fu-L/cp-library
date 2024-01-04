#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/graph/dijkstra.hpp"
int main(void) {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    Graph<ll> g(n);
    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        g.add_directed_edge(a, b, c);
    }
    vector<pair<ll, int>> d = dijkstra(g, s);
    if(d[t].first == numeric_limits<ll>::max()) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> path;
    int cur = t;
    path.push_back(cur);
    while(d[cur].second != -1) {
        cur = d[cur].second;
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    cout << d[t].first << ' ' << (int)path.size() - 1 << '\n';
    rep(i, 0, (int)path.size() - 1) {
        cout << path[i] << ' ' << path[i + 1] << '\n';
    }
}