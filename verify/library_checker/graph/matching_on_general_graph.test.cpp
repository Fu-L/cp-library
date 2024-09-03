#define PROBLEM "https://judge.yosupo.jp/problem/general_matching"
#include "../../../src/graph/max_matching.hpp"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
int main(void) {
    int n, m;
    cin >> n >> m;
    Edges<int> e(m);
    rep(i, 0, m) {
        cin >> e[i].from >> e[i].to;
        e[i].cost = 1;
    }
    Edges<int> ans = max_matching(n, e);
    cout << ans.size() << '\n';
    for(const auto& e : ans) {
        cout << e.from << ' ' << e.to << '\n';
    }
}