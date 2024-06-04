#pragma once
#include "../template/template.hpp"
template <typename T>
struct Edge {
    int from, to;
    T cost;
    int idx;
    Edge()
        : from(-1), to(-1), cost(-1), idx(-1) {}
    Edge(int from, int to, const T& cost = 1, int idx = -1)
        : from(from), to(to), cost(cost), idx(idx) {}
    operator int() const {
        return to;
    }
};
template <typename T>
struct Graph {
    Graph(int N)
        : n(N), es(0), g(N) {}
    int size() const {
        return n;
    }
    int edge_size() const {
        return es;
    }
    void add_edge(int from, int to, const T& cost = 1) {
        assert(0 <= from and from < n);
        assert(0 <= to and to < n);
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }
    void add_directed_edge(int from, int to, const T& cost = 1) {
        assert(0 <= from and from < n);
        assert(0 <= to and to < n);
        g[from].emplace_back(from, to, cost, es++);
    }
    inline vector<Edge<T>>& operator[](const int& k) {
        assert(0 <= k and k < n);
        return g[k];
    }
    inline const vector<Edge<T>>& operator[](const int& k) const {
        assert(0 <= k and k < n);
        return g[k];
    }

   private:
    int n, es;
    vector<vector<Edge<T>>> g;
};
template <typename T>
using Edges = vector<Edge<T>>;