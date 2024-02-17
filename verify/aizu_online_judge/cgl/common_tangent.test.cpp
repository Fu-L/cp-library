#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_G"
#define ERROR 0.00001
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/template.hpp"
#include "../../../src/geometry/point_2d.hpp"
#include "../../../src/geometry/line_and_segment_2d.hpp"
#include "../../../src/geometry/circle_2d.hpp"
int main(void) {
    Circle c1, c2;
    cin >> c1.p >> c1.r >> c2.p >> c2.r;
    vector<Line> res = tangent_cc(c1, c2);
    vector<Point> ans;
    for(const Line& l : res) {
        ans.push_back(intersection_cl(c1, l)[0]);
    }
    sort(ans.begin(), ans.end(), comp_x);
    for(const Point& p : ans) {
        cout << p << '\n';
    }
}