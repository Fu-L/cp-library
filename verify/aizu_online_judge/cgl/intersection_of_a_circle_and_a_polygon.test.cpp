#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_H"
#define ERROR 0.00001
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/template.hpp"
#include "../../../src/geometry/point_2d.hpp"
#include "../../../src/geometry/circle_2d.hpp"
int main(void) {
    int n, r;
    cin >> n >> r;
    Circle c = Circle(Point(0.0, 0.0), r);
    vector<Point> polygon(n);
    rep(i, 0, n) {
        cin >> polygon[i];
    }
    cout << area_pc(polygon, c) << '\n';
}