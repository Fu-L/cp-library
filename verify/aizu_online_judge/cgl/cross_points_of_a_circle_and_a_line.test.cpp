#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D"
#define ERROR 0.000001
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/template.hpp"
#include "../../../src/geometry/point_2d.hpp"
#include "../../../src/geometry/line_and_segment_2d.hpp"
#include "../../../src/geometry/circle_2d.hpp"
int main(void) {
    Circle c;
    cin >> c.p >> c.r;
    int q;
    cin >> q;
    while(q--) {
        Point p1, p2;
        cin >> p1 >> p2;
        Line l = Line(p1, p2);
        auto cross_point = intersection_cl(c, l);
        assert(int(cross_point.size()) == 1 or int(cross_point.size()) == 2);
        if(int(cross_point.size()) == 1) cross_point.push_back(cross_point[0]);
        sort(cross_point.begin(), cross_point.end(), comp_x);
        cout << cross_point[0] << ' ' << cross_point[1] << '\n';
    }
}