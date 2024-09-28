#pragma once
#include "../template/template.hpp"
#include "./graph_template.hpp"
vector<pair<int, int>> bfs(const Graph<int>& g, const int s = 0) {
    const int n = g.size();
    assert(0 <= s and s < n);
    vector<pair<int, int>> d(n, {numeric_limits<int>::max(), -1});
    queue<int> q;
    d[s] = {0, -1};
    q.emplace(s);
    while(!q.empty()) {
        const int cur = q.front();
        q.pop();
        for(const Edge<int>& e : g[cur]) {
            if(d[e.to].first == numeric_limits<int>::max()) {
                d[e.to] = {d[cur].first + 1, cur};
                q.emplace(e.to);
            }
        }
    }
    return d;
}