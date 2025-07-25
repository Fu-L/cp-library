#pragma once
#include "../template/template.hpp"
#include "../graph/graph_template.hpp"
#include "./heavy_light_decomposition.hpp"
template <typename T>
struct AuxiliaryTree {
    AuxiliaryTree(const Graph<T>& _g, const int root = 0)
        : g(_g), hld(g, root) {}
    pair<Graph<int>, vector<int>> get(vector<int> idx) {
        if(idx.empty()) return {Graph<int>(0), {}};
        auto comp = [&](const int i, const int j) {
            return hld.idx(i).first < hld.idx(j).first;
        };
        sort(begin(idx), end(idx), comp);
        for(int i = 0, ie = idx.size(); i + 1 < ie; ++i) {
            idx.push_back(hld.lca(idx[i], idx[i + 1]));
        }
        sort(begin(idx), end(idx), comp);
        idx.erase(unique(begin(idx), end(idx)), end(idx));
        Graph<int> aux(idx.size());
        vector<int> rs;
        rs.push_back(0);
        for(int i = 1; i < (int)idx.size(); ++i) {
            const int l = hld.lca(idx[rs.back()], idx[i]);
            while(idx[rs.back()] != l) rs.pop_back();
            aux.add_directed_edge(rs.back(), i);
            rs.push_back(i);
        }
        return make_pair(aux, idx);
    }

   private:
    Graph<T> g;
    HeavyLightDecomposition<T> hld;
};