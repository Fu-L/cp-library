#pragma once
#include "../template/template.hpp"
#include "../graph/graph_template.hpp"
template <typename T>
struct HeavyLightDecomposition {
    HeavyLightDecomposition(Graph<T>& _g, int root = 0)
        : g(_g), n(g.size()), id(0), size(n, 0), depth(n, 0), down(n, -1), up(n, -1), nex(n, root), par(n, root), rev(n, 0) {
        assert(0 <= root and root < n);
        dfs_sz(root);
        dfs_hld(root);
    }
    pair<int, int> idx(int i) const {
        assert(0 <= i and i < n);
        return make_pair(down[i], up[i]);
    }
    int la(int a, int k) const {
        assert(0 <= a and a < n);
        if(k > depth[a]) return -1;
        while(true) {
            int b = nex[a];
            if(down[a] - k >= down[b]) return rev[down[a] - k];
            k -= down[a] - down[b] + 1;
            a = par[b];
        }
    }
    int lca(int a, int b) const {
        assert(0 <= a and a < n);
        assert(0 <= b and b < n);
        while(nex[a] != nex[b]) {
            if(down[a] < down[b]) swap(a, b);
            a = par[nex[a]];
        }
        return depth[a] < depth[b] ? a : b;
    }
    int dist(int a, int b) const {
        assert(0 <= a and a < n);
        assert(0 <= b and b < n);
        return depth[a] + depth[b] - depth[lca(a, b)] * 2;
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
    void subtree_query(int u, bool vertex, const F& f) {
        assert(0 <= u and u < n);
        f(down[u] + int(!vertex), up[u]);
    }

   private:
    Graph<T>& g;
    int n, id;
    vector<int> size, depth, down, up, nex, par, rev;
    void dfs_sz(int cur) {
        size[cur] = 1;
        for(auto& edge : g[cur]) {
            if(edge.to == par[cur]) {
                if(g[cur].size() >= 2 and edge.to == g[cur][0].to) {
                    swap(g[cur][0], g[cur][1]);
                } else {
                    continue;
                }
            }
            depth[edge.to] = depth[cur] + 1;
            par[edge.to] = cur;
            dfs_sz(edge.to);
            size[cur] += size[edge.to];
            if(size[edge.to] > size[g[cur][0].to]) {
                swap(edge, g[cur][0]);
            }
        }
    }
    void dfs_hld(int cur) {
        down[cur] = id++;
        rev[down[cur]] = cur;
        for(const auto& edge : g[cur]) {
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