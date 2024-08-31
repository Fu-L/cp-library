#pragma once
#include "../template/template.hpp"
#include "../graph/graph_template.hpp"
template <typename T>
struct HeavyLightDecomposition {
    HeavyLightDecomposition(Graph<T>& _g, int root = 0)
        : g(_g), n(g.size()), id(0), sz(n, 0), dep(n, 0), down(n, -1), up(n, -1), nex(n, root), par(n, root), rev(n, 0) {
        assert(0 <= root and root < n);
        dfs_sz(root);
        dfs_hld(root);
    }
    pair<int, int> idx(int i) const {
        assert(0 <= i and i < n);
        return make_pair(down[i], up[i]);
    }
    int depth(int v) const {
        assert(0 <= v and v < n);
        return dep[v];
    }
    int parent(int v) const {
        assert(0 <= v and v < n);
        return par[v];
    }
    int la(int v, int x) const {
        assert(0 <= v and v < n);
        assert(x >= 0);
        if(x > dep[v]) return -1;
        while(true) {
            const int u = nex[v];
            if(down[v] - x >= down[u]) return rev[down[v] - x];
            x -= down[v] - down[u] + 1;
            v = par[u];
        }
    }
    int lca(int u, int v) const {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        while(nex[u] != nex[v]) {
            if(down[u] < down[v]) swap(u, v);
            u = par[nex[u]];
        }
        return dep[u] < dep[v] ? u : v;
    }
    int dist(int u, int v) const {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        return dep[u] + dep[v] - dep[lca(u, v)] * 2;
    }
    template <typename F>
    void path_query(int u, int v, bool vertex, const F& f) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        int l = lca(u, v);
        for(auto&& [a, b] : ascend(u, l)) f(a + 1, b);
        if(vertex) f(down[l], down[l] + 1);
        for(auto&& [a, b] : descend(l, v)) f(a, b + 1);
    }
    template <typename F>
    void subtree_query(int v, bool vertex, const F& f) {
        assert(0 <= v and v < n);
        f(down[v] + int(!vertex), up[v]);
    }

   private:
    Graph<T>& g;
    int n, id;
    vector<int> sz, dep, down, up, nex, par, rev;
    void dfs_sz(int cur) {
        sz[cur] = 1;
        for(Edge<T>& edge : g[cur]) {
            if(edge.to == par[cur]) {
                if(g[cur].size() >= 2 and edge.to == g[cur][0].to) {
                    swap(g[cur][0], g[cur][1]);
                } else {
                    continue;
                }
            }
            dep[edge.to] = dep[cur] + 1;
            par[edge.to] = cur;
            dfs_sz(edge.to);
            sz[cur] += sz[edge.to];
            if(sz[edge.to] > sz[g[cur][0].to]) {
                swap(edge, g[cur][0]);
            }
        }
    }
    void dfs_hld(int cur) {
        down[cur] = id++;
        rev[down[cur]] = cur;
        for(const Edge<T>& edge : g[cur]) {
            if(edge.to == par[cur]) continue;
            nex[edge.to] = (edge.to == g[cur][0].to ? nex[cur] : edge.to);
            dfs_hld(edge.to);
        }
        up[cur] = id;
    }
    vector<pair<int, int>> ascend(int u, int v) const {
        vector<pair<int, int>> res;
        while(nex[u] != nex[v]) {
            res.emplace_back(down[u], down[nex[u]]);
            u = par[nex[u]];
        }
        if(u != v) res.emplace_back(down[u], down[v] + 1);
        return res;
    }
    vector<pair<int, int>> descend(int u, int v) const {
        if(u == v) return {};
        if(nex[u] == nex[v]) return {{down[u] + 1, down[v]}};
        auto res = descend(u, par[nex[v]]);
        res.emplace_back(down[nex[v]], down[v]);
        return res;
    }
};