#pragma once
#include "../template/template.hpp"
#include "./graph_template.hpp"
template <typename T>
vector<pair<T, int>> dijkstra(const Graph<T>& g, const int s = 0) {
    int n = g.size();
    assert(0 <= s and s < n);
    vector<pair<T, int>> d(n, {numeric_limits<T>::max(), -1});
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
    d[s] = {0, -1};
    pq.push({0, s});
    while(!pq.empty()) {
        pair<T, int> p = pq.top();
        pq.pop();
        T dist = p.first;
        int cur = p.second;
        if(d[cur].first < dist) continue;
        for(const Edge<T>& edge : g[cur]) {
            if(d[edge.to].first > d[cur].first + edge.cost) {
                d[edge.to] = {d[cur].first + edge.cost, cur};
                pq.push({d[edge.to].first, edge.to});
            }
        }
    }
    return d;
}