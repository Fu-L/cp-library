#pragma once
#include "cp-library/src/template/template.hpp"
template <typename T = int>
struct Edge {
    int from, to;
    T cost;
    int idx;
    Edge(int from, int to, T cost = 1, int idx = -1)
        : from(from), to(to), cost(cost), idx(idx) {}
    operator int() const {
        return to;
    }
};
template <typename T = int>
using Edges = vector<Edge<T>>;
template <typename T = int>
struct Graph {
    vector<Edges> g;
    int es;
    Graph(int n)
        : g(n), es(0) {}
    size_t size() const {
        return g.size();
    }
    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }
    void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }
    inline Edges& operator[](const int& k) {
        return g[k];
    }
    inline const Edges& operator[](const int& k) const {
        return g[k];
    }
};