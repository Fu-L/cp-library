#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/point_2d.hpp"
int main(void) {
    int n;
    cin >> n;
    vector<Point> ps(n);
    rep(i, 0, n) {
        cin >> ps[i];
    }
    sort(ps.begin(), ps.end(), comp_arg);
    rep(i, 0, n) {
        cout << setprecision(0) << ps[i] << '\n';
    }
}