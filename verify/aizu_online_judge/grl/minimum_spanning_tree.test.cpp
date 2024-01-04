#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/graph/kruskal.hpp"
int main(void) {
    int n, m;
    cin >> n >> m;
    Edges<int> e(m);
    rep(i, 0, m) {
        cin >> e[i].from >> e[i].to >> e[i].cost;
        e[i].idx = i;
    }
    cout << kruskal(n, e).first << '\n';
}