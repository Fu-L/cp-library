#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include "../../../src/template/template.hpp"
#include "../../../src/math/two_sat.hpp"
int main(void) {
    string p, cnf;
    int n, m;
    cin >> p >> cnf >> n >> m;
    TwoSAT ts(n);
    rep(i, 0, m) {
        int a, b, z;
        cin >> a >> b >> z;
        bool f = a > 0, g = b > 0;
        a = abs(a) - 1;
        b = abs(b) - 1;
        ts.add_clause(a, f, b, g);
    }
    if(ts.satisfiable()) {
        cout << "s SATISFIABLE" << '\n';
        vector<bool> ans = ts.answer();
        cout << "v ";
        rep(i, 0, n) {
            if(!ans[i]) cout << '-';
            cout << i + 1 << ' ';
        }
        cout << 0 << '\n';
    } else {
        cout << "s UNSATISFIABLE" << '\n';
    }
}