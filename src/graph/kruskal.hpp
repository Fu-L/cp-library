#pragma once
#include "../template/template.hpp"
#include "./graph_template.hpp"
#include "../data_structure/union_find.hpp"
template <typename T>
pair<T, Edges<T>> kruskal(int n, Edges<T> es) {
    sort(es.begin(), es.end(), [&](const Edge<T>& a, const Edge<T>& b) { return a.cost < b.cost; });
    UnionFind uf(n);
    T cost = 0;
    Edges<T> res;
    res.reserve(n - 1);
    for(const Edge<T>& e : es) {
        if(uf.same(e.from, e.to)) continue;
        cost += e.cost;
        uf.merge(e.from, e.to);
        res.emplace_back(e);
    }
    return {cost, res};
}