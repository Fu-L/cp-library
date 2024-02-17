#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A"
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/template.hpp"
#include "../../../src/geometry/point_2d.hpp"
#include "../../../src/geometry/line_and_segment_2d.hpp"
int main(void) {
    int q;
    cin >> q;
    while(q--) {
        Point p0, p1, p2, p3;
        cin >> p0 >> p1 >> p2 >> p3;
        Line l1 = Line(p0, p1), l2 = Line(p2, p3);
        if(is_parallel(l1, l2)) {
            cout << 2 << '\n';
        } else if(is_orthogonal(l1, l2)) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}