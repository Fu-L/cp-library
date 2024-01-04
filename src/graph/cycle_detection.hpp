#pragma once
#include "../template/template.hpp"
#include "./graph_template.hpp"
template <typename T>
Edges<T> cycle_detection(const Graph<T>& g, bool directed = true) {
    int n = g.size();
    for(int i = 0; i < n; ++i) {
        for(const Edge<T>& e : g[i]) {
            if(i == e.to) return {e};
        }
    }
    Edges<T> cycle;
    vector<int> pre(n, -1), visited(n, 0);
    int finish = 0;
    auto dfs = [&](auto& dfs, int cur, int pval, const Edge<T>& par) -> int {
        pre[cur] = pval;
        visited[cur] = 1;
        for(const Edge<T>& e : g[cur]) {
            if(finish) return -1;
            if(!directed and e.idx == par.idx) continue;
            if(pre[e.to] == pre[cur]) {
                cycle.emplace_back(e);
                return e.to;
            }
            if(visited[e.to]) continue;
            int nx = dfs(dfs, e.to, pval, e);
            if(nx != -1) {
                cycle.emplace_back(e);
                if(cur == nx) {
                    finish = 1;
                    return -1;
                }
                return nx;
            }
        }
        pre[cur] = -1;
        return -1;
    };
    for(int i = 0; i < n; ++i) {
        if(visited[i]) continue;
        dfs(dfs, i, i, Edge());
        if(finish) {
            reverse(begin(cycle), end(cycle));
            return cycle;
        }
    }
    return {};
}