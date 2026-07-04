#pragma once
#include "../template/template.hpp"
#include "./graph_template.hpp"
#include "./low_link.hpp"
template <typename T>
struct BiconnectedComponents {
    vector<vector<pair<int, int>>> bc;
    BiconnectedComponents(const Graph<T>& g)
        : n(g.size()), lowlink(g), used(n) {
        for(int i = 0; i < n; ++i) {
            if(!used[i]) dfs(g, i, -1);
        }
    }

   private:
    struct edge_key {
        int u, v, idx;
    };
    int n;
    LowLink<T> lowlink;
    vector<int> used;
    vector<edge_key> tmp;
    void dfs(const Graph<T>& g, const int idx, const int par_edge_idx) {
        used[idx] = true;
        for(const Edge<T>& e : g[idx]) {
            const int to = e.to;
            if(e.idx == par_edge_idx) continue;
            if(!used[to] or lowlink.ord[to] < lowlink.ord[idx]) {
                const auto [u, v] = minmax(idx, to);
                tmp.push_back({u, v, e.idx});
            }
            if(!used[to]) {
                dfs(g, to, e.idx);
                if(lowlink.low[to] >= lowlink.ord[idx]) {
                    bc.emplace_back();
                    while(true) {
                        const edge_key ed = tmp.back();
                        bc.back().emplace_back(ed.u, ed.v);
                        tmp.pop_back();
                        if(ed.idx == e.idx) break;
                    }
                }
            }
        }
    }
};