#pragma once
#include "../template/template.hpp"
#include "../graph/graph_template.hpp"
template <typename T>
struct LowestCommonAncestor {
    LowestCommonAncestor(const Graph<T>& g, const int root = 0) {
        assert(0 <= root and root < g.size());
        init(g, root);
    }
    int depth(const int v) const {
        assert(0 <= v and v < n);
        return dep[v];
    }
    T cost(const int v) const {
        assert(0 <= v and v < n);
        return co[v];
    }
    int parent(const int v) const {
        assert(0 <= v and v < n);
        return par[0][v];
    }
    int la(int v, int x) const {
        assert(0 <= v and v < n);
        assert(x >= 0);
        if(x > dep[v]) return -1;
        for(int i = 0; x > 0; ++i) {
            if(x & 1) v = par[i][v];
            x >>= 1;
        }
        return v;
    }
    int lca(int u, int v) const {
        assert(0 <= u and u < n and 0 <= v and v < n);
        if(dep[u] > dep[v]) swap(u, v);
        v = la(v, dep[v] - dep[u]);
        if(u == v) return u;
        for(int i = (int)par.size() - 1; i >= 0; --i) {
            if(par[i][u] != par[i][v]) {
                u = par[i][u];
                v = par[i][v];
            }
        }
        return par[0][u];
    }
    int dist(const int u, const int v) const {
        assert(0 <= u and u < n and 0 <= v and v < n);
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    T length(const int u, const int v) const {
        assert(0 <= u and u < n and 0 <= v and v < n);
        return co[u] + co[v] - 2 * co[lca(u, v)];
    }

   private:
    int n;
    vector<vector<int>> par;
    vector<int> dep;
    vector<T> co;
    void init(const Graph<T>& g, const int root = 0) {
        n = g.size();
        int h = 1;
        while((1 << h) < n) ++h;
        par.assign(h, vector<int>(n, -1));
        dep.assign(n, -1);
        co.assign(n, -1);
        dfs(g, root, -1, 0, 0);
        for(int i = 0; i + 1 < (int)par.size(); ++i) {
            for(int v = 0; v < n; ++v) {
                if(par[i][v] != -1) {
                    par[i + 1][v] = par[i][par[i][v]];
                }
            }
        }
    }
    void dfs(const Graph<T>& g, const int v, const int p, const int d, const T& c) {
        par[0][v] = p;
        dep[v] = d;
        co[v] = c;
        for(const Edge<T>& e : g[v]) {
            if(e.to == p) continue;
            dfs(g, e.to, v, d + 1, c + e.cost);
        }
    }
};