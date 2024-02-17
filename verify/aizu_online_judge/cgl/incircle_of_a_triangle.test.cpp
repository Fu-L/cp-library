#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B"
#define ERROR 0.000001
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/template.hpp"
#include "../../../src/geometry/point_2d.hpp"
#include "../../../src/geometry/circle_2d.hpp"
int main(void) {
    Point p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    Circle c = inscribed_circle(p1, p2, p3);
    cout << c.p << ' ' << c.r << '\n';
}