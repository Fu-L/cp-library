#pragma once
#include "../template/template.hpp"
template <template <typename> typename FPS, typename T>
FPS<T> all_product(vector<FPS<T>> f) {
    if(f.empty()) return {1};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < (int)f.size(); ++i) pq.emplace(f[i].size(), i);
    while((int)pq.size() > 1) {
        const auto [d1, i1] = pq.top();
        pq.pop();
        const auto [d2, i2] = pq.top();
        pq.pop();
        f[i1] *= f[i2];
        f[i2].clear();
        pq.emplace(d1 + d2, i1);
    }
    return f[pq.top().second];
}