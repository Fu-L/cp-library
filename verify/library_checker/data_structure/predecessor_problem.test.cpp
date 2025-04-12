#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "../../../src/template/template.hpp"
#include "../../../src/data_structure/segment_tree.hpp"
int op(int a, int b) {
    return a + b;
}
int e() {
    return 0;
}
int main(void) {
    int n, q;
    cin >> n >> q;
    string t;
    cin >> t;
    vector<int> a(n);
    rep(i, 0, n) {
        a[i] = t[i] - '0';
    }
    SegmentTree<int, op, e> seg(a);
    while(q--) {
        int c, k;
        cin >> c >> k;
        if(c == 0) {
            seg.set(k, 1);
        } else if(c == 1) {
            seg.set(k, 0);
        } else if(c == 2) {
            cout << seg.get(k) << '\n';
        } else if(c == 3) {
            auto f = [&](int v) -> bool {
                return v == 0;
            };
            int ans = seg.max_right(k, f);
            if(ans == n) ans = -1;
            cout << ans << '\n';
        } else if(c == 4) {
            auto f = [&](int v) -> bool {
                return v == 0;
            };
            int ans = seg.min_left(k + 1, f) - 1;
            cout << ans << '\n';
        } else {
            assert(0);
        }
    }
}