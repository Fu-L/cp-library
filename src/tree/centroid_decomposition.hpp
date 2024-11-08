#pragma once
#include "../template/template.hpp"
#include "../graph/graph_template.hpp"
template <typename T>
pair<Graph<int>, int> centroid_decomposition(const Graph<T>& g) {
    const int n = g.size();
    vector<int> sub(n);
    vector<bool> visited(n);
    Graph<int> tree(n);
    auto get_size = [&](const auto& get_size, const int cur, const int par) -> int {
        sub[cur] = 1;
        for(const Edge<T>& e : g[cur]) {
            if(e.to == par or visited[e.to]) continue;
            sub[cur] += get_size(get_size, e.to, cur);
        }
        return sub[cur];
    };
    auto get_centroid = [&](const auto& get_centroid, const int cur, const int par, const int mid) -> int {
        for(const Edge<T>& e : g[cur]) {
            if(e.to == par or visited[e.to]) continue;
            if(sub[e.to] > mid) return get_centroid(get_centroid, e.to, cur, mid);
        }
        return cur;
    };
    auto dfs = [&](const auto& dfs, const int cur) -> int {
        const int centroid = get_centroid(get_centroid, cur, -1, get_size(get_size, cur, -1) / 2);
        visited[centroid] = true;
        for(const Edge<T>& e : g[centroid]) {
            if(visited[e.to]) continue;
            const int nex = dfs(dfs, e.to);
            if(centroid != nex) tree.add_directed_edge(centroid, nex);
        }
        visited[centroid] = false;
        return centroid;
    };
    const int root = dfs(dfs, 0);
    return {tree, root};
}