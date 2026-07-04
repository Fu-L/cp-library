#pragma once
#include "../template/template.hpp"
#include "./graph_template.hpp"
template <typename T>
struct CompressedSparseRow {
    vector<int> start, elist;
    CompressedSparseRow(const Graph<T>& g)
        : start(g.size() + 1) {
        const int n = g.size();
        for(int i = 0; i < n; ++i) {
            start[i + 1] = start[i] + g[i].size();
        }
        elist.resize(start[n]);
        for(int i = 0; i < n; ++i) {
            int counter = start[i];
            for(const Edge<T>& e : g[i]) {
                elist[counter++] = e.to;
            }
        }
    }
};