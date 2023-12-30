#pragma once
#include "cp-library/src/template/template.hpp"
template <typename T>
struct ConvexHullTrick {
    void add(const T& a, const T& b) {
        Linear l(a, b);
        assert((int)ls.size() == 0 or ls.back().a >= l.a);
        int len = (int)ls.size();
        while(len >= 2 and check(ls[len - 2], ls[len - 1], l)) {
            --len;
            ls.pop_back();
        }
        ls.push_back(l);
    }
    T operator()(const T& x) {
        assert(x >= x_last);
        while((int)ls.size() >= 2 and ls[0](x) >= ls[1](x)) {
            ls.pop_front();
        }
        x_last = x;
        return ls[0](x);
    }

   private:
    struct Linear {
        T a, b;
        Linear(const T& a = 0, const T& b = 0)
            : a(a), b(b) {}
        inline T operator()(const T& x) const {
            return a * x + b;
        }
    };
    inline bool check(const Linear& f1, const Linear& f2, const Linear& f3) const {
        return (f2.a - f1.a) * (f3.b - f2.b) >= (f2.b - f1.b) * (f3.a - f2.a);
    }
    deque<Linear> ls;
    T x_last = numeric_limits<T>::min();
};