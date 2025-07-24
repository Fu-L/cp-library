#pragma once
#include "../template/template.hpp"
#include "../dp/monotone_minima.hpp"
template <typename T>
vector<T> min_plus_convolution(const vector<T>& a, const vector<T>& b) {
    if(a.empty() or b.empty()) return {};
    const int n = a.size(), m = b.size();
    auto f = [&](const int i, const int j, const int k) -> bool {
        if(i < k) return true;
        if(i - j >= n) return false;
        return a[i - j] + b[j] < a[i - k] + b[k];
    };
    const auto argmin = monotone_minima(n + m - 1, m, f);
    vector<T> res(n + m - 1);
    for(int i = 0; i < n + m - 1; ++i) {
        const int j = argmin[i];
        res[i] = a[i - j] + b[j];
    }
    return res;
}
template <typename T>
vector<T> max_plus_convolution(const vector<T>& a, const vector<T>& b) {
    if(a.empty() or b.empty()) return {};
    const int n = a.size(), m = b.size();
    auto f = [&](const int i, const int j, const int k) -> bool {
        if(i < k) return true;
        if(i - j >= n) return false;
        return a[i - j] + b[j] > a[i - k] + b[k];
    };
    const auto argmax = monotone_minima(n + m - 1, m, f);
    vector<T> res(n + m - 1);
    for(int i = 0; i < n + m - 1; ++i) {
        const int j = argmax[i];
        res[i] = a[i - j] + b[j];
    }
    return res;
}