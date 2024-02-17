#pragma once
#include "../template/template.hpp"
#include "./template.hpp"
#include "./point_2d.hpp"
#include "./line_and_segment_2d.hpp"
Real area(const vector<Point>& ps) {
    Real res = 0.0;
    int n = ps.size();
    for(int i = 0; i < n; ++i) {
        res += cross(ps[i], ps[(i + 1) % n]);
    }
    return abs(res * 0.5);
}
bool is_convex(const vector<Point>& ps) {
    int n = ps.size();
    for(int i = 0; i < n; ++i) {
        if(ccw(ps[(i - 1 + n) % n], ps[i], ps[(i + 1) % n]) == -1) return false;
    }
    return true;
}
int in_polygon(const vector<Point>& ps, const Point& p) {
    int n = ps.size();
    int ret = 0;
    for(int i = 0; i < n; ++i) {
        Point a = ps[i] - p, b = ps[(i + 1) % n] - p;
        if(eq(cross(a, b), 0.0) and sign(dot(a, b)) <= 0) return 1;
        if(a.imag() > b.imag()) swap(a, b);
        if(sign(a.imag()) <= 0 and sign(b.imag()) == 1 and sign(cross(a, b)) == 1) ret ^= 2;
    }
    return ret;
}
vector<Point> convex_hull(vector<Point> ps) {
    sort(ps.begin(), ps.end(), comp_x);
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    int n = ps.size(), k = 0;
    if(n == 1) return ps;
    vector<Point> ch(2 * n);
    for(int i = 0; i < n; ch[k++] = ps[i++]) {
        while(k >= 2 and sign(cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1])) == -1) {
            --k;
        }
    }
    for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) {
        while(k >= t and sign(cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1])) == -1) {
            --k;
        }
    }
    ch.resize(k - 1);
    return ch;
}
Real convex_diameter(const vector<Point>& ps) {
    int n = ps.size(), is = 0, js = 0;
    for(int i = 1; i < n; ++i) {
        if(sign(ps[i].imag() - ps[is].imag()) == 1) is = i;
        if(sign(ps[i].imag() - ps[js].imag()) == -1) js = i;
    }
    Real maxdis = norm(ps[is] - ps[js]);
    int i = is, j = js;
    do {
        if(sign(cross(ps[(i + 1) % n] - ps[i], ps[(j + 1) % n] - ps[j])) >= 0) {
            j = (j + 1) % n;
        } else {
            i = (i + 1) % n;
        }
        if(norm(ps[i] - ps[j]) > maxdis) {
            maxdis = norm(ps[i] - ps[j]);
        }
    } while(i != is or j != js);
    return sqrt(maxdis);
}
vector<Point> convex_cut(const vector<Point>& ps, const Line& l) {
    int n = ps.size();
    vector<Point> res;
    for(int i = 0; i < n; ++i) {
        Point cur = ps[i], nex = ps[(i + 1) % n];
        if(ccw(l.a, l.b, cur) != -1) res.push_back(cur);
        if(ccw(l.a, l.b, cur) * ccw(l.a, l.b, nex) < 0) {
            res.push_back(intersection_ll(Line(cur, nex), l)[0]);
        }
    }
    return res;
}