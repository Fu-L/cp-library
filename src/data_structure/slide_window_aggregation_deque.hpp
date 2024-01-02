#pragma once
#include "../template/template.hpp"
template <typename S, auto op, auto e>
struct SlideWindowAggregationDeque {
    void push_front(const S &t) {
        push0(t);
    }
    void push_back(const S &t) {
        push1(t);
    }
    S front() const {
        return a0.empty() ? a1.front() : a0.back();
    }
    S back() const {
        return a1.empty() ? a0.front() : a1.back();
    }
    void pop_front() {
        if(a0.empty()) rebalance();
        assert(!a0.empty());
        a0.pop_back(), r0.pop_back();
    }
    void pop_back() {
        if(a1.empty()) rebalance();
        assert(!a1.empty());
        a1.pop_back(), r1.pop_back();
    }
    S query() {
        return op(get0(), get1());
    }

   private:
    vector<S> a0, a1, r0, r1;
    S get0() const {
        return r0.empty() ? e() : r0.back();
    }
    S get1() const {
        return r1.empty() ? e() : r1.back();
    }
    void push0(const S &x) {
        a0.push_back(x);
        r0.push_back(op(x, get0()));
    }
    void push1(const S &x) {
        a1.push_back(x);
        r1.push_back(op(get1(), x));
    }
    void rebalance() {
        int n = a0.size() + a1.size();
        int s0 = n / 2 + (a0.empty() ? n % 2 : 0);
        vector<S> a{a0};
        reverse(begin(a), end(a));
        copy(begin(a1), end(a1), back_inserter(a));
        a0.clear(), r0.clear();
        a1.clear(), r1.clear();
        for(int i = s0 - 1; i >= 0; --i) push0(a[i]);
        for(int i = s0; i < n; ++i) push1(a[i]);
    }
};