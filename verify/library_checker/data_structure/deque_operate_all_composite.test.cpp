#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"
#include "src/template/template.hpp"
#include "src/template/static_modint.hpp"
#include "src/data_structure/slide_window_aggregation_deque.hpp"
using mint = modint998244353;
struct S {
    mint a, b;
};
S op(S x, S y) {
    return {x.a * y.a, x.b * y.a + y.b};
}
S e() {
    return {1, 0};
}
int main(void) {
    SlideWindowAggregationDeque<S, op, e> swag;
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            mint a, b;
            cin >> a >> b;
            swag.push_front({a, b});
        } else if(t == 1) {
            mint a, b;
            cin >> a >> b;
            swag.push_back({a, b});
        } else if(t == 2) {
            swag.pop_front();
        } else if(t == 3) {
            swag.pop_back();
        } else {
            mint x;
            cin >> x;
            S res = swag.query();
            cout << res.a * x + res.b << '\n';
        }
    }
}