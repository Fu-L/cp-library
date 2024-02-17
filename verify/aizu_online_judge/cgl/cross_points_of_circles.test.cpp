#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_E"
#define ERROR 0.000001
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/template.hpp"
#include "../../../src/geometry/point_2d.hpp"
#include "../../../src/geometry/circle_2d.hpp"
int main(void) {
    Circle c1, c2;
    cin >> c1.p >> c1.r >> c2.p >> c2.r;
    auto cross_point = intersection_cc(c1, c2);
    assert(int(cross_point.size()) == 1 or int(cross_point.size()) == 2);
    if(int(cross_point.size()) == 1) cross_point.push_back(cross_point[0]);
    sort(cross_point.begin(), cross_point.end(), comp_x);
    cout << cross_point[0] << ' ' << cross_point[1] << '\n';
}