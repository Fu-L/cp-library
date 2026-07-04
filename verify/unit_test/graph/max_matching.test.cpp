#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/graph/max_matching.hpp"
int brute_max_matching(const int n, const vector<pair<int, int>>& es) {
    const int m = es.size();
    int res = 0;
    for(int bit = 0; bit < (1 << m); ++bit) {
        vector<int> used(n, false);
        int cnt = 0;
        bool ok = true;
        for(int i = 0; i < m; ++i) {
            if(!(bit >> i & 1)) continue;
            const auto& [u, v] = es[i];
            if(used[u] or used[v]) {
                ok = false;
                break;
            }
            used[u] = used[v] = true;
            ++cnt;
        }
        if(ok) res = max(res, cnt);
    }
    return res;
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
    mt19937 rng(12345);
    rep(n, 1, 9) {
        vector<pair<int, int>> all_edges;
        rep(i, 0, n) rep(j, i + 1, n) all_edges.emplace_back(i, j);
        rep(_, 0, 200) {
            Edges<int> input;
            vector<pair<int, int>> es;
            for(const auto& [u, v] : all_edges) {
                if((rng() & 1) == 0) continue;
                input.emplace_back(u, v, 1);
                es.emplace_back(u, v);
            }
            const auto got = max_matching(n, input);
            assert((int)got.size() == brute_max_matching(n, es));
            vector<int> used(n, false);
            for(const auto& e : got) {
                assert(0 <= e.from and e.from < n);
                assert(0 <= e.to and e.to < n);
                assert(!used[e.from]);
                assert(!used[e.to]);
                used[e.from] = used[e.to] = true;
            }
        }
    }
}