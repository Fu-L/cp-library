#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/graph/kruskal.hpp"
int main(void) {
    int n, m;
    cin >> n >> m;
    Edges<int> e;
    e.reserve(m);
    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        e.emplace_back(a, b, c, i);
    }
    cout << kruskal(n, e).first << '\n';
}