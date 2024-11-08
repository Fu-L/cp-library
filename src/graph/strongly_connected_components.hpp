#pragma once
#include "../template/template.hpp"
#include "./graph_template.hpp"
#include "./compressed_sparse_row.hpp"
template <typename T>
pair<int, vector<int>> scc_ids(const Graph<T>& g) {
    const int n = g.size();
    const CompressedSparseRow<T> g_csr(g);
    int now_ord = 0, group_num = 0;
    vector<int> visited, low(n), ord(n, -1), ids(n);
    visited.reserve(n);
    auto dfs = [&](const auto& dfs, const int v) -> void {
        low[v] = ord[v] = now_ord++;
        visited.emplace_back(v);
        for(int i = g_csr.start[v]; i < g_csr.start[v + 1]; ++i) {
            const int to = g_csr.elist[i];
            if(ord[to] == -1) {
                dfs(dfs, to);
                low[v] = min(low[v], low[to]);
            } else {
                low[v] = min(low[v], ord[to]);
            }
        }
        if(low[v] == ord[v]) {
            while(true) {
                const int u = visited.back();
                visited.pop_back();
                ord[u] = n;
                ids[u] = group_num;
                if(u == v) break;
            }
            ++group_num;
        }
    };
    for(int i = 0; i < n; ++i) {
        if(ord[i] == -1) {
            dfs(dfs, i);
        }
    }
    for(auto& x : ids) x = group_num - 1 - x;
    return {group_num, ids};
}
template <typename T>
vector<vector<int>> strongly_connected_components(const Graph<T>& g) {
    const auto [group_num, ids] = scc_ids(g);
    const int n = g.size();
    vector<int> counts(group_num);
    for(const int x : ids) ++counts[x];
    vector<vector<int>> groups(group_num);
    for(int i = 0; i < group_num; ++i) groups[i].reserve(counts[i]);
    for(int i = 0; i < n; ++i) groups[ids[i]].emplace_back(i);
    return groups;
}