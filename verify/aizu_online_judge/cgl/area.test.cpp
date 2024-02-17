#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A"
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/template.hpp"
#include "../../../src/geometry/point_2d.hpp"
#include "../../../src/geometry/polygon_2d.hpp"
int main(void) {
    int n;
    cin >> n;
    vector<Point> polygon(n);
    rep(i, 0, n) {
        cin >> polygon[i];
    }
    cout << fixed << setprecision(1) << area(polygon) << '\n';
}