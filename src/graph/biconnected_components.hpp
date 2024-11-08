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
    int n;
    LowLink<T> lowlink;
    vector<int> used;
    vector<pair<int, int>> tmp;
    void dfs(const Graph<T>& g, const int idx, const int par) {
        used[idx] = true;
        for(const Edge<T>& e : g[idx]) {
            const int to = e.to;
            if(to == par) continue;
            if(!used[to] or lowlink.ord[to] < lowlink.ord[idx]) {
                tmp.emplace_back(minmax(idx, to));
            }
            if(!used[to]) {
                dfs(g, to, idx);
                if(lowlink.low[to] >= lowlink.ord[idx]) {
                    bc.emplace_back();
                    while(true) {
                        const pair<int, int> ed = tmp.back();
                        bc.back().emplace_back(ed);
                        tmp.pop_back();
                        if(ed.first == min(idx, to) and ed.second == max(idx, to)) break;
                    }
                }
            }
        }
    }
};