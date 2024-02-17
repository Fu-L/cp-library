#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D"
#define ERROR 0.00000001
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
        Segment s1 = Segment(p0, p1), s2 = Segment(p2, p3);
        cout << dist_ss(s1, s2) << '\n';
    }
}