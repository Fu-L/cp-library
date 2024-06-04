#pragma once
#include "../template/template.hpp"
#include "./graph_template.hpp"
template <typename T>
vector<pair<T, int>> dijkstra(const Graph<T>& g, const int s = 0) {
    const int n = g.size();
    assert(0 <= s and s < n);
    vector<pair<T, int>> d(n, {numeric_limits<T>::max(), -1});
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
    d[s] = {0, -1};
    pq.emplace(0, s);
    while(!pq.empty()) {
        const auto [dist, cur] = pq.top();
        pq.pop();
        if(d[cur].first < dist) continue;
        for(const Edge<T>& e : g[cur]) {
            if(d[e.to].first > d[cur].first + e.cost) {
                d[e.to] = {d[cur].first + e.cost, cur};
                pq.emplace(d[e.to].first, e.to);
            }
        }
    }
    return d;
}