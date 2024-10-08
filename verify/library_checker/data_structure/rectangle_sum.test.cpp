#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/rectangle_sum.hpp"
int main(void) {
    int n, q;
    cin >> n >> q;
    RectangleSum<int, ll> rs;
    rep(i, 0, n) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        rs.add_point(x, y, w);
    }
    rs.build();
    while(q--) {
        int l, d, r, u;
        cin >> l >> d >> r >> u;
        cout << rs.sum(l, d, r, u) << '\n';
    }
}