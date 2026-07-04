#pragma once
#include "../template/template.hpp"
#include "../graph/graph_template.hpp"
template <typename T>
Edges<T> max_matching(const int n, const Edges<T>& es) {
    struct GabowEdmonds {
        struct AdjEdge {
            int to, id;
        };
        int n, offset;
        vector<vector<AdjEdge>> g;
        vector<pair<int, int>> edges;
        vector<int> mate, label, first, que;
        GabowEdmonds(const int n)
            : n(n), offset(n + 1), g(n + 1), mate(n + 1), label(n + 1, -1), first(n + 1) {
            que.reserve(n + 1);
        }
        void add_edge(int u, int v) {
            ++u;
            ++v;
            const int id = offset + (int)edges.size();
            g[u].push_back({v, id});
            g[v].push_back({u, id});
            edges.emplace_back(u, v);
        }
        int find(const int v) {
            if(label[first[v]] < 0) return first[v];
            return first[v] = find(first[v]);
        }
        void rematch(const int v, const int w) {
            const int t = mate[v];
            mate[v] = w;
            if(mate[t] != v) return;
            if(label[v] < offset) {
                mate[t] = label[v];
                rematch(label[v], t);
            } else {
                const auto& [x, y] = edges[label[v] - offset];
                rematch(x, y);
                rematch(y, x);
            }
        }
        void assign_label(const int x, const int y, const int id) {
            int r = find(x), s = find(y);
            if(r == s) return;
            int join = 0;
            label[r] = label[s] = -id;
            while(true) {
                if(s != 0) swap(r, s);
                r = find(label[mate[r]]);
                if(label[r] == -id) {
                    join = r;
                    break;
                }
                label[r] = -id;
            }
            int v = first[x];
            while(v != join) {
                que.push_back(v);
                label[v] = id;
                first[v] = join;
                v = first[label[mate[v]]];
            }
            v = first[y];
            while(v != join) {
                que.push_back(v);
                label[v] = id;
                first[v] = join;
                v = first[label[mate[v]]];
            }
        }
        bool augment(const int root) {
            int head = 0;
            que.clear();
            first[root] = 0;
            label[root] = 0;
            que.push_back(root);
            while(head < (int)que.size()) {
                const int v = que[head++];
                for(const AdjEdge& e : g[v]) {
                    const int u = e.to;
                    if(mate[u] == 0 and u != root) {
                        mate[u] = v;
                        rematch(v, u);
                        return true;
                    }
                    if(label[u] >= 0) {
                        assign_label(v, u, e.id);
                    } else if(label[mate[u]] < 0) {
                        label[mate[u]] = v;
                        first[mate[u]] = u;
                        que.push_back(mate[u]);
                    }
                }
            }
            return false;
        }
        vector<pair<int, int>> solve() {
            for(int i = 1; i <= n; ++i) {
                if(mate[i] != 0) continue;
                if(augment(i)) fill(label.begin(), label.end(), -1);
            }
            vector<pair<int, int>> res;
            res.reserve(n / 2);
            for(int i = 1; i <= n; ++i) {
                if(i < mate[i]) res.emplace_back(i - 1, mate[i] - 1);
            }
            return res;
        }
    };
    GabowEdmonds matching(n);
    vector<int> deg(n);
    for(const Edge<T>& e : es) {
        assert(e.cost == 1);
        assert(0 <= e.from and e.from < n);
        assert(0 <= e.to and e.to < n);
        if(e.from == e.to) continue;
        ++deg[e.from];
        ++deg[e.to];
    }
    for(int i = 0; i < n; ++i) {
        matching.g[i + 1].reserve(deg[i]);
    }
    for(const Edge<T>& e : es) {
        if(e.from != e.to) matching.add_edge(e.from, e.to);
    }
    const vector<pair<int, int>> pairs = matching.solve();
    Edges<T> res;
    res.reserve(pairs.size());
    for(const auto& [u, v] : pairs) {
        res.emplace_back(u, v, T(1));
    }
    return res;
}