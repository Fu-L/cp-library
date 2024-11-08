#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/rooted_hash_tree.hpp"
int main(void) {
    int n;
    cin >> n;
    Graph<int> g(n);
    rep(i, 1, n) {
        int p;
        cin >> p;
        g.add_edge(i, p);
    }
    vector<ll> h = rooted_tree_hash(g, 0);
    unordered_map<ll, int> mp;
    int idx = 0;
    rep(i, 0, n) {
        if(mp.find(h[i]) == mp.end()) {
            mp[h[i]] = idx++;
        }
    }
    cout << idx << '\n';
    rep(i, 0, n) {
        cout << mp[h[i]] << " \n"[i + 1 == n];
    }
}