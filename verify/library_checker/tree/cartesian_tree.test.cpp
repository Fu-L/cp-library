#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"
#include "../../../src/template/template.hpp"
#include "../../../src/tree/cartesian_tree.hpp"
int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    auto [tree, root] = cartesian_tree(a);
    vector<int> ans(n);
    ans[root] = root;
    rep(i, 0, n) {
        for(const int to : tree[i]) {
            ans[to] = i;
        }
    }
    rep(i, 0, n) {
        cout << ans[i] << " \n"[i + 1 == n];
    }
}