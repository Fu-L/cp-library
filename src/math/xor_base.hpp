#pragma once
#include "../template/template.hpp"
template <typename T>
vector<T> xor_base(const vector<T>& a) {
    vector<T> base;
    for(T v : a) {
        for(const T e : base) {
            v = min(v, v xor e);
        }
        if(v > 0) base.emplace_back(v);
    }
    return base;
}