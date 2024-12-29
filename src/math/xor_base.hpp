#pragma once
#include "../template/template.hpp"
template <typename T>
vector<T> xor_base(const vector<T>& a) {
    vector<T> base;
    for(T v : a) {
        for(const T& e : base) {
            if((v xor e) < v) v ^= e;
        }
        for(T& e : base) {
            if((v xor e) < e) e ^= v;
        }
        if(v) base.emplace_back(v);
    }
    return base;
}