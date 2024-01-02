#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/dynamic_li_chao_tree.hpp"
int main(void) {
    int n, q;
    cin >> n >> q;
    DynamicLiChaoTree<ll, (ll)-1e9, (ll)1e9> cht;
    rep(i, 0, n) {
        ll l, r, a, b;
        cin >> l >> r >> a >> b;
        cht.add_segment(l, r, a, b);
    }
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            ll l, r, a, b;
            cin >> l >> r >> a >> b;
            cht.add_segment(l, r, a, b);
        } else {
            ll p;
            cin >> p;
            ll ans = cht(p);
            if(ans == numeric_limits<ll>::max()) {
                cout << "INFINITY" << '\n';
            } else {
                cout << ans << '\n';
            }
        }
    }
}