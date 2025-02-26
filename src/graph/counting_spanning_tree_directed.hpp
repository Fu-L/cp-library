#pragma once
#include "../template/template.hpp"
#include "../graph/graph_template.hpp"
#include "../matrix/matrix.hpp"
#include "../matrix/gauss_elimination.hpp"
template <typename T, typename U>
T counting_spanning_tree_directed(const Graph<U>& g, const int r) {
    const int n = g.size();
    assert(0 <= r and r < n);
    Matrix<T> mat(n, n);
    for(int i = 0; i < n; ++i) {
        for(const auto& e : g[i]) {
            --mat[i][e.to];
            ++mat[e.to][e.to];
        }
    }
    Matrix<T> lap(n - 1, n - 1);
    int h = 0, w = 0;
    for(int i = 0; i < n; ++i) {
        if(i == r) {
            h = 1;
            continue;
        }
        for(int j = 0; j < n; ++j) {
            if(j == r) {
                w = 1;
                continue;
            }
            lap[i - h][j - w] = mat[i][j];
        }
        w = 0;
    }
    return gauss_elimination(lap).second;
}