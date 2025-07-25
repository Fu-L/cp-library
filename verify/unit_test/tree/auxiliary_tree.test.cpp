#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/random/random_number_generator.hpp"
#include "../../../src/template/static_modint.hpp"
using mint = modint998244353;
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/auxiliary_tree.hpp"
// ABC340-G
void test() {
    int n = rng(1, 500);
    int ma = rng(1, n);
    vector<int> a = rng.vec(n, 1, ma, true);
    auto [u, v] = rng.tree(n, true);
    auto brute = [&](int n, vector<int> a, vector<int> u, vector<int> v) -> mint {
        rep(i, 0, n) {
            a[i]--;
        }
        Graph<int> g(n);
        rep(i, 0, n - 1) {
            u[i]--;
            v[i]--;
            g.add_edge(u[i], v[i]);
        }
        mint ans = 0;
        rep(i, 0, n) {
            map<int, mint> dp1, dp2;
            auto dfs = [&](auto& dfs, int cur, int p) -> void {
                dp1[cur] = 1;
                dp2[cur] = 1;
                for(const auto& e : g[cur]) {
                    if(e.to == p) continue;
                    dfs(dfs, e.to, cur);
                    dp1[cur] *= dp2[e.to] + 1;
                    dp2[cur] *= dp2[e.to] + 1;
                }
                if(a[cur] != i) {
                    for(const auto& e : g[cur]) {
                        if(e.to == p) continue;
                        dp1[cur] -= dp2[e.to];
                    }
                    dp1[cur]--;
                    dp2[cur]--;
                }
                ans += dp1[cur];
            };
            dfs(dfs, 0, -1);
        }
        return ans;
    };
    auto fast = [&](int n, vector<int> a, vector<int> u, vector<int> v) -> mint {
        vector<vector<int>> col(n);
        rep(i, 0, n) {
            a[i]--;
            col[a[i]].push_back(i);
        }
        Graph<int> g(n);
        rep(i, 0, n - 1) {
            u[i]--;
            v[i]--;
            g.add_edge(u[i], v[i]);
        }
        AuxiliaryTree<int> aux(g);
        mint ans = 0;
        rep(i, 0, n) {
            if(col[i].empty()) continue;
            auto [tree, idx] = aux.get(col[i]);
            map<int, mint> dp1, dp2;
            auto dfs = [&](auto& dfs, int cur, int p) -> void {
                dp1[cur] = 1;
                dp2[cur] = 1;
                for(const auto& e : tree[cur]) {
                    if(e.to == p) continue;
                    dfs(dfs, e.to, cur);
                    dp1[cur] *= dp2[e.to] + 1;
                    dp2[cur] *= dp2[e.to] + 1;
                }
                if(a[idx[cur]] != i) {
                    for(const auto& e : tree[cur]) {
                        if(e.to == p) continue;
                        dp1[cur] -= dp2[e.to];
                    }
                    dp1[cur]--;
                    dp2[cur]--;
                }
                ans += dp1[cur];
            };
            dfs(dfs, 0, -1);
        }
        return ans;
    };
    assert(brute(n, a, u, v) == fast(n, a, u, v));
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