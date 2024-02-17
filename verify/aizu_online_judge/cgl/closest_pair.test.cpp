#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/5/CGL_5_A"
#define ERROR 0.000001
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/template.hpp"
#include "../../../src/geometry/point_2d.hpp"
int main(void) {
    int n;
    cin >> n;
    vector<Point> ps(n);
    rep(i, 0, n) {
        cin >> ps[i];
    }
    cout << closest_pair(ps) << '\n';
}