#pragma once
#include "src/template/template.hpp"
template <typename T, T x_low, T x_high>
struct DynamicLiChaoTree {
    DynamicLiChaoTree()
        : root{nullptr} {}
    void add_line(const T &a, const T &b) {
        Line x(a, b);
        root = add_line(root, x, x_low, x_high, x.get(x_low), x.get(x_high));
    }
    void add_segment(const T &l, const T &r, const T &a, const T &b) {
        Line x(a, b);
        root = add_segment(root, x, l, r - 1, x_low, x_high, x.get(x_low), x.get(x_high));
    }
    T query(const T &x) const {
        assert(x_low <= x and x <= x_high);
        return query(root, x_low, x_high, x);
    }

   private:
    struct Line {
        T a, b;
        Line(const T &a, const T &b)
            : a(a), b(b) {}
        inline T get(const T &x) const {
            return a * x + b;
        }
    };
    struct Node {
        Line x;
        Node *l, *r;
        Node(const Line &x)
            : x{x}, l{nullptr}, r{nullptr} {}
    };
    const T id = numeric_limits<T>::max();
    Node *root;
    Node *add_line(Node *t, Line &x, const T &l, const T &r, const T &x_l, const T &x_r) {
        if(!t) return new Node(x);
        T t_l = t->x.get(l), t_r = t->x.get(r);
        if(t_l <= x_l and t_r <= x_r) {
            return t;
        } else if(t_l >= x_l and t_r >= x_r) {
            t->x = x;
            return t;
        } else {
            T m = (l + r) / 2;
            if(m == r) --m;
            T t_m = t->x.get(m), x_m = x.get(m);
            if(t_m > x_m) {
                swap(t->x, x);
                if(x_l >= t_l) t->l = add_line(t->l, x, l, m, t_l, t_m);
                else t->r = add_line(t->r, x, m + 1, r, t_m + x.a, t_r);
            } else {
                if(t_l >= x_l) t->l = add_line(t->l, x, l, m, x_l, x_m);
                else t->r = add_line(t->r, x, m + 1, r, x_m + x.a, x_r);
            }
            return t;
        }
    }
    Node *add_segment(Node *t, Line &x, const T &a, const T &b, const T &l, const T &r, const T &x_l, const T &x_r) {
        if(r < a or b < l) return t;
        if(a <= l and r <= b) {
            Line y{x};
            return add_line(t, y, l, r, x_l, x_r);
        }
        if(t) {
            T t_l = t->x.get(l), t_r = t->x.get(r);
            if(t_l <= x_l and t_r <= x_r) return t;
        } else {
            t = new Node(Line(0, id));
        }
        T m = (l + r) / 2;
        if(m == r) --m;
        T x_m = x.get(m);
        t->l = add_segment(t->l, x, a, b, l, m, x_l, x_m);
        t->r = add_segment(t->r, x, a, b, m + 1, r, x_m + x.a, x_r);
        return t;
    }
    T query(const Node *t, const T &l, const T &r, const T &x) const {
        if(!t) return id;
        if(l == r) return t->x.get(x);
        T m = (l + r) / 2;
        if(m == r) --m;
        if(x <= m) return min(t->x.get(x), query(t->l, l, m, x));
        else return min(t->x.get(x), query(t->r, m + 1, r, x));
    }
};