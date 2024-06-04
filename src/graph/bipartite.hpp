#pragma once
#include "../template/template.hpp"
#include "./graph_template.hpp"
template <typename T>
vector<int> bipartite(const Graph<T>& g) {
    const int n = g.size();
    vector<int> color(n, -1);
    auto dfs = [&](auto& dfs, int cur, int col) -> bool {
        color[cur] = col;
        for(const Edge<T>& e : g[cur]) {
            if(color[e.to] == col) return false;
            if(color[e.to] == -1 and !dfs(dfs, e.to, 1 - col)) return false;
        }
        return true;
    };
    for(int i = 0; i < n; ++i) {
        if(color[i] != -1) continue;
        if(!dfs(dfs, i, 0)) return {};
    }
    return color;
}