#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/random/random_number_generator.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/graph/bfs.hpp"
#include "../../../src/graph/dijkstra.hpp"
void undirected() {
    int n = rng(1, 200000), m = rng(1, (int)min(200000ll, 1ll * n * (n - 1) / 2));
    auto [u, v] = rng.graph(n, m, false);
    Graph<int> g(n);
    rep(i, 0, m) {
        g.add_edge(u[i], v[i]);
    }
    vector<pair<int, int>> ans = dijkstra(g, 0), res = bfs(g, 0);
    rep(i, 0, n) {
        assert(ans[i].first == res[i].first);
    }
}
void directed() {
    int n = rng(1, 200000), m = rng(1, (int)min(200000ll, 1ll * n * (n - 1) / 2));
    auto [u, v] = rng.graph(n, m, false);
    Graph<int> g(n);
    rep(i, 0, m) {
        g.add_directed_edge(u[i], v[i]);
    }
    vector<pair<int, int>> ans = dijkstra(g, 0), res = bfs(g, 0);
    rep(i, 0, n) {
        assert(ans[i].first == res[i].first);
    }
}
int main(void) {
    int test_num = 50;
    rep(i, 0, test_num) {
        undirected();
    }
    rep(i, 0, test_num) {
        directed();
    }
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}