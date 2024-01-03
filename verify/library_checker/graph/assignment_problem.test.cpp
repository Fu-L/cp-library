#define PROBLEM "https://judge.yosupo.jp/problem/assignment"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/min_cost_flow.hpp"
int main(void) {
    int N;
    cin >> N;
    MinCostFlow<int, long long> graph(2 * N + 2);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int a;
            cin >> a;
            a += int(1e9);
            graph.add_edge(i, N + j, 1, a);
        }
    }
    for(int i = 0; i < N; i++) {
        graph.add_edge(2 * N, i, 1, 0);
        graph.add_edge(N + i, 2 * N + 1, 1, 0);
    }
    auto res = graph.flow(2 * N, 2 * N + 1);
    cout << res.second - (long long)(1e9) * N << '\n';
    vector<int> ans(N);
    for(int i = 0; i < N * N; i++) {
        auto edge = graph.get_edge(i);
        if(0 <= edge.from and edge.from < N and edge.flow > 0) {
            ans[edge.from] = edge.to - N;
        }
    }
    for(int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
    }
}