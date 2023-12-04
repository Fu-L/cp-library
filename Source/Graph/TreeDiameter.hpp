#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct TreeDiameter {
    TreeDiameter(int n)
        : n(n), to(n), cost(n) {}
    void add_edge(int u, int v, const T& c = 1) {
        to[u].push_back(v);
        to[v].push_back(u);
        cost[u].push_back(c);
        cost[v].push_back(c);
    }
    pair<T, vector<int>> diameter() {
        vector<T> dist(n);
        vector<int> par(n);
        auto dfs = [&](auto& dfs, int v, int p, const T& dep) -> void {
            dist[v] = dep;
            par[v] = p;
            for(int i = 0; i < (int)to[v].size(); ++i) {
                if(to[v][i] == p) continue;
                dfs(dfs, to[v][i], v, dep + cost[v][i]);
            }
        };
        dfs(dfs, 0, -1, 0);
        int s = -1;
        T ma = -1;
        for(int i = 0; i < n; ++i) {
            if(ma < dist[i]) {
                s = i;
                ma = dist[i];
            }
        }
        dfs(dfs, s, -1, 0);
        int t = -1;
        ma = -1;
        for(int i = 0; i < n; ++i) {
            if(ma < dist[i]) {
                t = i;
                ma = dist[i];
            }
        }
        vector<int> vec;
        int cur = t;
        while(cur != -1) {
            vec.push_back(cur);
            cur = par[cur];
        }
        return {ma, vec};
    }

   private:
    int n;
    vector<vector<int>> to;
    vector<vector<T>> cost;
};