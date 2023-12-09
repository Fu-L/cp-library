#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
struct LowestCommonAncestor {
    LowestCommonAncestor(int n)
        : n(n), to(n), co(n), dep(n), costs(n) {
        l = 0;
        while((1 << l) < n) ++l;
        par = vector<vector<int>>(l, vector<int>(n + 1, n));
    }
    void add_edge(int a, int b, const T& c = 0) {
        assert(0 <= a and a < n and 0 <= b and b < n);
        to[a].push_back(b);
        co[a].push_back(c);
        to[b].push_back(a);
        co[b].push_back(c);
    }
    void init(int _root = 0) {
        root = _root;
        assert(0 <= root and root < n);
        dfs(root, 0, 0, n);
        for(int i = 0; i < l - 1; ++i) {
            for(int v = 0; v < n; ++v) {
                par[i + 1][v] = par[i][par[i][v]];
            }
        }
    }
    int parent(int a) const {
        assert(0 <= a and a < n);
        return par[0][a];
    }
    int lca(int a, int b) const {
        assert(0 <= a and a < n and 0 <= b and b < n);
        if(dep[a] > dep[b]) swap(a, b);
        int gap = dep[b] - dep[a];
        for(int i = l - 1; i >= 0; --i) {
            int len = 1 << i;
            if(gap >= len) {
                gap -= len;
                b = par[i][b];
            }
        }
        if(a == b) return a;
        for(int i = l - 1; i >= 0; --i) {
            int na = par[i][a];
            int nb = par[i][b];
            if(na != nb) a = na, b = nb;
        }
        return par[0][a];
    }
    int length(int a, int b) const {
        assert(0 <= a and a < n and 0 <= b and b < n);
        int c = lca(a, b);
        return dep[a] + dep[b] - dep[c] * 2;
    }
    T dist(int a, int b) const {
        assert(0 <= a and a < n and 0 <= b and b < n);
        int c = lca(a, b);
        return costs[a] + costs[b] - costs[c] * 2;
    }

   private:
    int n, root, l;
    vector<vector<int>> to;
    vector<vector<T>> co;
    vector<int> dep;
    vector<T> costs;
    vector<vector<int>> par;
    void dfs(int v, int d, T c, int p) {
        par[0][v] = p;
        dep[v] = d;
        costs[v] = c;
        for(int i = 0; i < (int)to[v].size(); ++i) {
            int u = to[v][i];
            if(u == p) continue;
            dfs(u, d + 1, c + co[v][i], v);
        }
    }
};