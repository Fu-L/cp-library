#pragma once
#include "cp-library/src/template/template.hpp"
template <typename S, auto op, auto e>
struct SlideWindowAggregation {
    SlideWindowAggregation()
        : f0(e()), f1(e()) {}
    void push(const S &x) {
        if(a0.empty()) {
            push_s0(x);
            transfer();
        } else {
            push_s1(x);
        }
    }
    void pop() {
        if(a0.empty()) transfer();
        a0.pop_back();
        r0.pop_back();
        f0 = r0.empty() ? e() : r0.back();
    }
    S query() {
        return op(f0, f1);
    }

   private:
    vector<S> a0, a1, r0, r1;
    S f0, f1;
    void push_s0(const S &x) {
        a0.push_back(x);
        r0.push_back(f0 = op(x, f0));
    }
    void push_s1(const S &x) {
        a1.push_back(x);
        r1.push_back(f1 = op(f1, x));
    }
    void transfer() {
        while(!a1.empty()) {
            push_s0(a1.back());
            a1.pop_back();
        }
        while(!r1.empty()) r1.pop_back();
        f1 = e();
    }
};