// cht.add(a, b); で、直線y=ax+bを追加する。aは単調非増加であることが必要。
// cht(x); で、x=xでの最小値がもとまる。
#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct CHT {
    struct Linear {
        Linear(const T& a = 0, const T& b = 0)
            : a(a), b(b) {}
        inline T operator()(const T& x) const {
            return a * x + b;
        }

       private:
        T a, b;
    };
    void add(const T& a, const T& b) {
        Linear l(a, b);
        assert((int)ls.size() == 0 or ls.back().a <= l.a);
        while((int)ls.size() >= 2) {
            const Linear& l1 = ls[(int)ls.size() - 2];
            const Linear& l2 = ls.back();
            if((l.a - l2.a) * (l1.b - l2.b) < (l2.a - l1.a) * (l2.b - l.b)) break;
            ls.pop_back();
        }
    }
    T operator()(const T& x) {
        T res = ls[0](x);
        while((int)ls.size() >= 2) {
            T now = ls[1](x);
            if(now < res) break;
            res = now;
            ls.pop_front();
        }
        return res;
    }

   private:
    deque<Linear> ls;
};
