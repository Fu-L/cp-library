#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/data_structure/slide_window_aggregation.hpp"
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
    SlideWindowAggregation<S, op, e> swag;
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            mint a, b;
            cin >> a >> b;
            swag.push({a, b});
        } else if(t == 1) {
            swag.pop();
        } else {
            mint x;
            cin >> x;
            S res = swag.prod();
            cout << res.a * x + res.b << '\n';
        }
    }
}