#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/centroid_decomposition.hpp"
#include "../../../src/fps/formal_power_series_ll.hpp"
using fps = FormalPowerSeriesLL<ll>;
int main() {
    int n;
    cin >> n;
    Graph<int> g(n);
    rep(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b);
    }
    auto [tree, root] = centroid_decomposition(g);
    vector<bool> visited(n);
    auto get_depth = [&](auto& get_depth, int cur, int depth, fps& res) -> void {
        visited[cur] = true;
        if((int)res.size() < depth + 1) res.resize(depth + 1);
        res[depth]++;
        for(const auto& e : g[cur]) {
            if(visited[e.to]) continue;
            get_depth(get_depth, e.to, depth + 1, res);
        }
        visited[cur] = false;
    };
    auto dfs = [&](auto& get_depth, auto& dfs, int cur, fps& res) -> void {
        visited[cur] = true;
        for(const auto& e : tree[cur]) {
            if(visited[e.to]) continue;
            dfs(get_depth, dfs, e.to, res);
        }
        vector<fps> depth;
        fps sum(0), sum2(0);
        for(const auto& e : g[cur]) {
            if(visited[e.to]) continue;
            depth.emplace_back();
            get_depth(get_depth, e.to, 1, depth.back());
            sum += depth.back();
            sum2 += depth.back() * depth.back();
        }
        res += (sum * sum - sum2) / 2 + sum;
        visited[cur] = false;
    };
    fps ans(0);
    dfs(get_depth, dfs, root, ans);
    ans.resize(n);
    rep(i, 1, n) {
        cout << ans[i] << " \n"[i + 1 == n];
    }
}