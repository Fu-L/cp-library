#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/template/random_number_generator.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/graph/bipartite.hpp"
#include "../../../src/tree/lowest_common_ancestor.hpp"
void random_yes() {
    int n = rng(1, 100000);
    vector<vector<int>> color(2);
    rep(i, 0, n) {
        color[rng(0, 1)].push_back(i);
    }
    Graph<int> g(n);
    if(color[0].empty() or color[1].empty()) {
        vector<int> col = bipartite(g);
        assert(!col.empty());
        rep(i, 0, n) assert(col[i] == 0 or col[i] == 1);
        return;
    }
    int m = rng(0, 200000);
    rep(i, 0, m) {
        int a = rng(0, (int)color[0].size() - 1);
        int b = rng(0, (int)color[1].size() - 1);
        g.add_edge(color[0][a], color[1][b]);
    }
    vector<int> col = bipartite(g);
    assert(!col.empty());
    rep(i, 0, n) {
        assert(col[i] == 0 or col[i] == 1);
        for(const int to : g[i]) {
            assert(col[to] == 1 - col[i]);
        }
    }
}
void namori() {
    int n = rng(1, 100000);
    auto [u, v] = rng.tree(n, false);
    Graph<int> g(n);
    rep(i, 0, n - 1) {
        g.add_edge(u[i], v[i]);
    }
    LowestCommonAncestor<int> tree(g);
    int a = rng(0, n - 1);
    int b = a;
    while(b == a) b = rng(0, n - 1);
    g.add_edge(a, b);
    vector<int> color = bipartite(g);
    if(tree.dist(a, b) % 2 == 0) {
        assert(color.empty());
    } else {
        assert(!color.empty());
        rep(i, 0, n) {
            assert(color[i] == 0 or color[i] == 1);
            for(const int to : g[i]) {
                assert(color[to] == 1 - color[i]);
            }
        }
    }
}
void tree() {
    int n = rng(1, 100000);
    auto [u, v] = rng.tree(n, false);
    Graph<int> g(n);
    rep(i, 0, n - 1) {
        g.add_edge(u[i], v[i]);
    }
    vector<int> color = bipartite(g);
    assert(!color.empty());
    rep(i, 0, n) {
        assert(color[i] == 0 or color[i] == 1);
        for(const int to : g[i]) {
            assert(color[to] == 1 - color[i]);
        }
    }
}
int main(void) {
    int test_num = 33;
    rep(i, 0, test_num) {
        random_yes();
    }
    rep(i, 0, test_num) {
        namori();
    }
    rep(i, 0, test_num) {
        tree();
    }
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}