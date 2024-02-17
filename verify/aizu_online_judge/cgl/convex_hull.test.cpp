#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A"
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/template.hpp"
#include "../../../src/geometry/point_2d.hpp"
#include "../../../src/geometry/polygon_2d.hpp"
int main(void) {
    int n;
    cin >> n;
    vector<Point> ps(n);
    rep(i, 0, n) {
        cin >> ps[i];
    }
    vector<Point> ch = convex_hull(ps);
    int m = ch.size();
    int idx = 0;
    rep(i, 1, n) {
        if(ch[idx].imag() > ch[i].imag() or (ch[idx].imag() == ch[i].imag() and ch[idx].real() > ch[i].real())) idx = i;
    }
    cout << m << '\n';
    rep(i, 0, m) {
        Point p = ch[(idx + i) % m];
        cout << fixed << setprecision(0) << p << '\n';
    }
}