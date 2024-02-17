#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_A"
#define ERROR 0.00000001
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/template.hpp"
#include "../../../src/geometry/point_2d.hpp"
#include "../../../src/geometry/line_and_segment_2d.hpp"
int main(void) {
    Point p1, p2;
    cin >> p1 >> p2;
    Line l = Line(p1, p2);
    int q;
    cin >> q;
    while(q--) {
        Point p;
        cin >> p;
        cout << projection(l, p) << '\n';
    }
}