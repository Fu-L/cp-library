#pragma once
#include "../template/template.hpp"
#include "./graph_template.hpp"
#include "./strongly_connected_components.hpp"
struct TwoSAT {
    TwoSAT(int N)
        : n(N), ans(N), graph(2 * N) {}
    void add_clause(int i, bool f, int j, bool g) {
        graph.add_directed_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        graph.add_directed_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
        auto id = scc_ids(graph).second;
        for(int i = 0; i < n; ++i) {
            if(id[2 * i] == id[2 * i + 1]) return false;
            ans[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }
    vector<bool> answer() {
        return ans;
    }

   private:
    int n;
    vector<bool> ans;
    Graph<int> graph;
};