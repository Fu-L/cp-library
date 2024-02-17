#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_A"
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/template.hpp"
#include "../../../src/geometry/circle_2d.hpp"
int main(void) {
    Circle c1, c2;
    cin >> c1.p >> c1.r;
    cin >> c2.p >> c2.r;
    cout << is_intersect_cc(c1, c2) << '\n';
}