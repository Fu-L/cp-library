#pragma once
#include "../template/template.hpp"
#include "../graph/graph_template.hpp"
template <typename T = int>
pair<T, vector<int>> tree_diameter(const Graph<T>& g) {
    int n = (int)g.size();
    vector<T> depth(n);
    vector<int> par(n);
    auto dfs = [&](auto& dfs, int v, int p, T d) -> void {
        depth[v] = d;
        par[v] = p;
        for(auto& e : g[v]) {
            if(e.to == p) continue;
            dfs(dfs, e.to, v, d + e.cost);
        }
    };
    int s = 0;
    for(int i = 0; i < 2; ++i) {
        dfs(dfs, s, -1, 0);
        T ma = -1;
        for(int j = 0; j < n; ++j) {
            if(depth[j] > ma) {
                ma = depth[j];
                s = j;
            }
        }
    }
    vector<int> path;
    T diameter = depth[s];
    while(s != -1) {
        path.push_back(s);
        s = par[s];
    }
    return {diameter, path};
}