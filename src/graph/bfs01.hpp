#pragma once
#include "../template/template.hpp"
#include "./graph_template.hpp"
vector<pair<int, int>> bfs01(const Graph<int>& g, const int s = 0) {
    const int n = g.size();
    assert(0 <= s and s < n);
    vector<pair<int, int>> d(n, {numeric_limits<int>::max(), -1});
    vector<int> visited(n);
    deque<int> deq;
    d[s] = {0, -1};
    deq.emplace_back(s);
    while(!deq.empty()) {
        const int cur = deq.front();
        deq.pop_front();
        if(visited[cur]) continue;
        visited[cur] = 1;
        for(const Edge<int>& e : g[cur]) {
            if(d[e.to].first != numeric_limits<int>::max() and d[e.to].first <= d[cur].first + e.cost) continue;
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