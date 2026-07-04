#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/graph/compressed_sparse_row.hpp"
int main() {
    Graph<int> undirected(4);
    undirected.add_edge(0, 1);
    undirected.add_edge(0, 2);
    undirected.add_edge(2, 3);
    CompressedSparseRow<int> csr1(undirected);
    assert(csr1.start == vector<int>({0, 2, 3, 5, 6}));
    assert(csr1.elist == vector<int>({1, 2, 0, 0, 3, 2}));
    Graph<int> directed(4);
    directed.add_directed_edge(0, 1);
    directed.add_directed_edge(0, 2);
    directed.add_directed_edge(2, 3);
    CompressedSparseRow<int> csr2(directed);
    assert(csr2.start == vector<int>({0, 2, 2, 3, 3}));
    assert(csr2.elist == vector<int>({1, 2, 3}));
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}