#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/graph/biconnected_components.hpp"
int main(void) {
    int n, m;
    cin >> n >> m;
    Graph<int> g(n);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b);
    }
    BiconnectedComponents<int> low(g);
    vector<vector<int>> ans;
    vector<bool> used(n);
    rep(i, 0, (int)low.bc.size()) {
        set<int> st;
        for(const auto& e : low.bc[i]) {
            st.insert(e.first);
            st.insert(e.second);
        }
        ans.emplace_back();
        for(const int val : st) {
            ans.back().push_back(val);
            used[val] = true;
        }
    }
    rep(i, 0, n) {
        if(!used[i]) {
            ans.emplace_back();
            ans.back().push_back(i);
        }
    }
    int k = ans.size();
    cout << k << '\n';
    rep(i, 0, k) {
        int l = ans[i].size();
        cout << l << ' ';
        rep(j, 0, l) {
            cout << ans[i][j] << " \n"[j + 1 == l];
        }
    }
}