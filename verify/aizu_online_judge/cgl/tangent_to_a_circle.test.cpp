#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_F"
#define ERROR 0.00001
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/template.hpp"
#include "../../../src/geometry/point_2d.hpp"
#include "../../../src/geometry/circle_2d.hpp"
int main(void) {
    Point p;
    Circle c;
    cin >> p >> c.p >> c.r;
    auto tangent = tangent_cp(c, p);
    sort(tangent.begin(), tangent.end(), comp_x);
    for(const Point& ans : tangent) {
        cout << ans << '\n';
    }
}