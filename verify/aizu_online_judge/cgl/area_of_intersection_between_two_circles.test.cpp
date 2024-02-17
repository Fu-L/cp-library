#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_I"
#define ERROR 0.000001
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/template.hpp"
#include "../../../src/geometry/circle_2d.hpp"
int main(void) {
    Circle c1, c2;
    cin >> c1.p >> c1.r >> c2.p >> c2.r;
    cout << area_cc(c1, c2) << '\n';
}