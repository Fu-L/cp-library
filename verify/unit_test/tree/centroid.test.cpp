#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/random/random_number_generator.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/centroid.hpp"
void test() {
    int n = rng(2, 1000);
    auto [u, v] = rng.tree(n, false);
    Graph<int> g(n);
    rep(i, 0, n - 1) {
        g.add_edge(u[i], v[i]);
    }
    vector<bool> visited(n);
    auto dfs = [&](auto& dfs, int cur, int root, bool is_centroid) -> int {
        visited[cur] = true;
        vector<int> sub;
        int sum = 1;
        for(const auto& e : g[cur]) {
            if(visited[e.to]) continue;
            sub.push_back(dfs(dfs, e.to, root, is_centroid));
            sum += sub.back();
        }
        if(cur == root) {
            if(is_centroid) {
                for(const int val : sub) {
                    assert(2 * val <= n);
                }
            } else {
                bool flag = false;
                for(const int val : sub) {
                    if(2 * val > n) flag = true;
                }
                assert(flag);
            }
        }
        visited[cur] = false;
        return sum;
    };
    vector<int> cent = centroid(g);
    rep(i, 0, n) {
        bool is_centroid = false;
        for(const int x : cent) {
            if(i == x) is_centroid = true;
        }
        dfs(dfs, i, i, is_centroid);
    }
}
int main(void) {
    constexpr int test_num = 100;
    rep(i, 0, test_num) {
        test();
    }
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}