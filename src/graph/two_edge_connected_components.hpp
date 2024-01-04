#pragma once
#include "../template/template.hpp"
#include "./graph_template.hpp"
#include "./low_link.hpp"
template <typename T>
struct TwoEdgeConnectedComponents {
    vector<vector<int>> groups, tree;
    TwoEdgeConnectedComponents(const Graph<T>& g)
        : n(g.size()), k(0), low(g), comp(n, -1) {
        for(int i = 0; i < n; ++i) {
            if(comp[i] == -1) dfs(g, i, -1);
        }
        groups.resize(k);
        tree.resize(k);
        for(int i = 0; i < n; ++i) {
            groups[comp[i]].push_back(i);
        }
        for(const auto& e : low.bridge) {
            int u = comp[e.first], v = comp[e.second];
            tree[u].push_back(v);
        }
    }
    inline int operator[](const int& i) const {
        assert(0 <= i and i < n);
        return comp[i];
    }

   private:
    int n, k;
    LowLink<T> low;
    vector<int> comp;
    void dfs(const Graph<T>& g, int i, int p) {
        if(p >= 0 and low.ord[p] >= low.low[i]) comp[i] = comp[p];
        else comp[i] = k++;
        for(const int to : g[i]) {
            if(comp[to] == -1) dfs(g, to, i);
        }
    }
};