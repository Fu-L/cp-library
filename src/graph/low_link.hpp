#pragma once
#include "../template/template.hpp"
#include "./graph_template.hpp"
template <typename T>
struct LowLink {
    vector<int> ord, low, articulation;
    vector<pair<int, int>> bridge;
    LowLink(const Graph<T>& g)
        : ord(g.size(), -1), low(g.size(), -1) {
        for(int i = 0, k = 0; i < g.size(); ++i) {
            if(ord[i] == -1) k = dfs(g, i, k, -1);
        }
    }

   private:
    int dfs(const Graph<T>& g, const int idx, int k, const int par) {
        low[idx] = (ord[idx] = k++);
        int cnt = 0;
        bool arti = false, second = false;
        for(const Edge<T>& e : g[idx]) {
            const int to = e.to;
            if(ord[to] == -1) {
                ++cnt;
                k = dfs(g, to, k, idx);
                low[idx] = min(low[idx], low[to]);
                arti |= (par != -1) and (low[to] >= ord[idx]);
                if(ord[idx] < low[to]) {
                    bridge.emplace_back(minmax(idx, to));
                }
            } else if(to != par or second) {
                low[idx] = min(low[idx], ord[to]);
            } else {
                second = true;
            }
        }
        arti |= (par == -1) and (cnt > 1);
        if(arti) articulation.emplace_back(idx);
        return k;
    }
};