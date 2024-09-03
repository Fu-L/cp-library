#pragma once
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/max_cardinality_matching.hpp>
#include "../template/template.hpp"
#include "../graph/graph_template.hpp"
template <typename T>
Edges<T> max_matching(int n, const Edges<T>& es) {
    using namespace boost;
    using G = adjacency_list<vecS, vecS, undirectedS>;
    using V = graph_traits<G>::vertex_descriptor;
    G g(n);
    for(const Edge<T>& e : es) {
        assert(e.cost == 1);
        add_edge(e.from, e.to, g);
    }
    vector<V> mate(n);
    edmonds_maximum_cardinality_matching(g, &mate[0]);
    Edges<T> res;
    for(V v = 0; v < num_vertices(g); ++v) {
        if(mate[v] != graph_traits<G>::null_vertex() and v < mate[v]) {
            res.push_back({(int)v, (int)mate[v], 1});
        }
    }
    return res;
}