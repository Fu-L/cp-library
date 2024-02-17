#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C"
#define ERROR 0.00001
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/template.hpp"
#include "../../../src/geometry/point_2d.hpp"
#include "../../../src/geometry/polygon_2d.hpp"
int main(void) {
    int n;
    cin >> n;
    vector<Point> polygon(n);
    rep(i, 0, n) {
        cin >> polygon[i];
    }
    int q;
    cin >> q;
    while(q--) {
        Point p1, p2;
        cin >> p1 >> p2;
        Line l = Line(p1, p2);
        vector<Point> cut = convex_cut(polygon, l);
        cout << area(cut) << '\n';
    }
}