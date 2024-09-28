#pragma once
#include "../template/template.hpp"
#include "./graph_template.hpp"
template <typename T>
vector<pair<T, int>> bfs01(const Graph<T>& g, const int s = 0) {
    const int n = g.size();
    assert(0 <= s and s < n);
    vector<pair<T, int>> d(n, {numeric_limits<T>::max(), -1});
    vector<int> visited(n);
    deque<int> deq;
    d[s] = {0, -1};
    deq.emplace_back(s);
    while(!deq.empty()) {
        const int cur = deq.front();
        deq.pop_front();
        if(visited[cur]) continue;
        visited[cur] = 1;
        for(const Edge<T>& e : g[cur]) {
            if(d[e.to].first != numeric_limits<T>::max() and d[e.to].first <= d[cur].first + e.cost) continue;
            d[e.to] = {d[cur].first + e.cost, cur};
            if(e.cost == 0) {
                deq.emplace_front(e.to);
            } else {
                deq.emplace_back(e.to);
            }
        }
    }
    return d;
}