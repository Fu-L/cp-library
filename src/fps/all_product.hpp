#pragma once
#include "src/template/template.hpp"
template <template <typename> typename FormalPowerSeries, typename mint>
FormalPowerSeries<mint> all_product(vector<FormalPowerSeries<mint>> f) {
    if((int)f.size() == 0) return {1};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    rep(i, 0, (int)f.size()) pq.push({f[i].size(), i});
    while((int)pq.size() > 1) {
        auto [d1, i1] = pq.top();
        pq.pop();
        auto [d2, i2] = pq.top();
        pq.pop();
        f[i1] *= f[i2];
        f[i2].clear();
        pq.push({d1 + d2, i1});
    }
    return f[pq.top().second];
}