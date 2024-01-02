#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/dynamic_li_chao_tree.hpp"
int main(void) {
    int n, q;
    cin >> n >> q;
    DynamicLiChaoTree<ll, (ll)-1e9, (ll)1e9> cht;
    rep(i, 0, n) {
        ll a, b;
        cin >> a >> b;
        cht.add_line(a, b);
    }
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            ll a, b;
            cin >> a >> b;
            cht.add_line(a, b);
        } else {
            ll p;
            cin >> p;
            cout << cht(p) << '\n';
        }
    }
}