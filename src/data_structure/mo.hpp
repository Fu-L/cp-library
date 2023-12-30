#pragma once
#include "cp-library/src/template/template.hpp"
template <typename T>
struct Mo {
    Mo(int N, int Q)
        : n(N), order(Q) {
        width = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));
        iota(order.begin(), order.end(), 0);
    }
    void insert(int l, int r) {
        assert(0 <= l and l <= r and r <= n);
        left.push_back(l);
        right.push_back(r);
    }
    template <auto AL, auto AR, auto DL, auto DR, auto OUT>
    void run(const AL& add_left, const AR& add_right, const DL& delete_left, const DR& delete_right, const OUT& out) {
        assert(left.size() == order.size());
        sort(order.begin(), order.end(), [&](int i, int j) {
            int iblock = left[i] / width, jblock = left[j] / width;
            if(iblock != jblock) return iblock < jblock;
            if(iblock & 1) return right[i] < right[j];
            return right[i] > right[j];
        });
        int nl = 0, nr = 0;
        for(int idx : order) {
            while(nl > left[idx]) add_left(--nl);
            while(nr < right[idx]) add_right(nr++);
            while(nl < left[idx]) delete_left(nl++);
            while(nr > right[idx]) delete_right(--nr);
            out(idx);
        }
    }

   private:
    int n, width;
    vector<int> left, right, order;
};