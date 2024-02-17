#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C"
#include "../../../src/template/template.hpp"
#include "../../../src/geometry/template.hpp"
#include "../../../src/geometry/point_2d.hpp"
int main(void) {
    Point p1, p2;
    cin >> p1 >> p2;
    int q;
    cin >> q;
    while(q--) {
        Point p3;
        cin >> p3;
        int c = ccw(p1, p2, p3);
        if(c == 1) cout << "COUNTER_CLOCKWISE" << '\n';
        else if(c == -1) cout << "CLOCKWISE" << '\n';
        else if(c == 2) cout << "ONLINE_BACK" << '\n';
        else if(c == -2) cout << "ONLINE_FRONT" << '\n';
        else if(c == 0) cout << "ON_SEGMENT" << '\n';
        else assert(0);
    }
}