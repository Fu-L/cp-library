#pragma once
#include "../template/template.hpp"
#include "../graph/graph_template.hpp"
#include "./matrix.hpp"
#include "./matrix/gauss_elimination.hpp"
template <typename T, typename U>
T counting_spanning_tree_undirected(const Graph<U>& g) {
    const int n = g.size();
    Matrix<T> mat(n, n);
    for(int i = 0; i < n; ++i) {
        mat[i][i] = (int)g[i].size();
        for(const auto& e : g[i]) {
            --mat[i][e.to];
        }
    }
    Matrix<T> lap(n - 1, n - 1);
    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n - 1; ++j) {
            lap[i][j] = mat[i][j];
        }
    }
    return gauss_elimination(lap).second;
}