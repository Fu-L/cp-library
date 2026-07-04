#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/template.hpp"
#include "../../../src/geometry/point_2d.hpp"
#include "../../../src/geometry/line_and_segment_2d.hpp"
#include "../../../src/geometry/circle_2d.hpp"
#include "../../../src/geometry/polygon_2d.hpp"
int main() {
    assert(convex_hull(vector<Point>{}).empty());
    assert(eq(convex_diameter(vector<Point>{}), 0.0));
    assert(eq(convex_diameter(vector<Point>{Point(1, 2)}), 0.0));
    assert(intersection_cc(Circle(Point(0, 0), 1), Circle(Point(0, 0), 1)).empty());
    assert(intersection_cc(Circle(Point(0, 0), 1), Circle(Point(3, 0), 1)).empty());
    assert(tangent_cp(Circle(Point(0, 0), 2), Point(1, 0)).empty());
    assert(tangent_cp(Circle(Point(0, 0), 2), Point(2, 0)).size() == 1);
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}