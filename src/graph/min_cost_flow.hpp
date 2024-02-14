#pragma once
#include "../template/template.hpp"
namespace internal {
template <class E>
struct csr {
    vector<int> start;
    vector<E> elist;
    explicit csr(int n, const vector<pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for(auto e : edges) {
            ++start[e.first + 1];
        }
        for(int i = 1; i <= n; ++i) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for(auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};
template <class T>
struct simple_queue {
    vector<T> payload;
    int pos = 0;
    void reserve(int n) {
        payload.reserve(n);
    }
    int size() const {
        return int(payload.size()) - pos;
    }
    bool empty() const {
        return pos == int(payload.size());
    }
    void push(const T& t) {
        payload.push_back(t);
    }
    T& front() {
        return payload[pos];
    }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() {
        ++pos;
    }
};
}  // namespace internal
template <class Cap, class Cost>
struct MinCostFlow {
   public:
    MinCostFlow() {}
    explicit MinCostFlow(int n)
        : _n(n) {}
    int add_edge(int from, int to, const Cap& cap, const Cost& cost) {
        assert(0 <= from and from < _n);
        assert(0 <= to and to < _n);
        assert(0 <= cap);
        assert(0 <= cost);
        int m = int(_edges.size());
        _edges.push_back({from, to, cap, 0, cost});
        return m;
    }
    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
    };
    edge get_edge(int i) {
        int m = int(_edges.size());
        assert(0 <= i and i < m);
        return _edges[i];
    }
    vector<edge> edges() {
        return _edges;
    }
    pair<Cap, Cost> flow(int s, int t) {
        return flow(s, t, numeric_limits<Cap>::max());
    }
    pair<Cap, Cost> flow(int s, int t, const Cap& flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    vector<pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, numeric_limits<Cap>::max());
    }
    vector<pair<Cap, Cost>> slope(int s, int t, const Cap& flow_limit) {
        assert(0 <= s and s < _n);
        assert(0 <= t and t < _n);
        assert(s != t);
        int m = int(_edges.size());
        vector<int> edge_idx(m);
        auto g = [&]() {
            vector<int> degree(_n), redge_idx(m);
            vector<pair<int, _edge>> elist;
            elist.reserve(2 * m);
            for(int i = 0; i < m; ++i) {
                auto e = _edges[i];
                edge_idx[i] = degree[e.from]++;
                redge_idx[i] = degree[e.to]++;
                elist.push_back({e.from, {e.to, -1, e.cap - e.flow, e.cost}});
                elist.push_back({e.to, {e.from, -1, e.flow, -e.cost}});
            }
            auto _g = internal::csr<_edge>(_n, elist);
            for(int i = 0; i < m; ++i) {
                auto e = _edges[i];
                edge_idx[i] += _g.start[e.from];
                redge_idx[i] += _g.start[e.to];
                _g.elist[edge_idx[i]].rev = redge_idx[i];
                _g.elist[redge_idx[i]].rev = edge_idx[i];
            }
            return _g;
        }();
        auto result = slope(g, s, t, flow_limit);
        for(int i = 0; i < m; ++i) {
            auto e = g.elist[edge_idx[i]];
            _edges[i].flow = _edges[i].cap - e.cap;
        }
        return result;
    }

   private:
    int _n;
    vector<edge> _edges;
    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };
    vector<pair<Cap, Cost>> slope(internal::csr<_edge>& g, int s, int t, const Cap& flow_limit) {
        vector<pair<Cost, Cost>> dual_dist(_n);
        vector<int> prev_e(_n);
        vector<bool> vis(_n);
        struct Q {
            Cost key;
            int to;
            inline bool operator<(Q r) const {
                return key > r.key;
            }
        };
        vector<int> que_min;
        vector<Q> que;
        auto dual_ref = [&]() {
            for(int i = 0; i < _n; ++i) {
                dual_dist[i].second = numeric_limits<Cost>::max();
            }
            fill(vis.begin(), vis.end(), false);
            que_min.clear();
            que.clear();
            size_t heap_r = 0;
            dual_dist[s].second = 0;
            que_min.push_back(s);
            while(!que_min.empty() or !que.empty()) {
                int v;
                if(!que_min.empty()) {
                    v = que_min.back();
                    que_min.pop_back();
                } else {
                    while(heap_r < que.size()) {
                        ++heap_r;
                        push_heap(que.begin(), que.begin() + heap_r);
                    }
                    v = que.front().to;
                    pop_heap(que.begin(), que.end());
                    que.pop_back();
                    --heap_r;
                }
                if(vis[v]) continue;
                vis[v] = true;
                if(v == t) break;
                Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;
                for(int i = g.start[v]; i < g.start[v + 1]; ++i) {
                    auto e = g.elist[i];
                    if(!e.cap) continue;
                    Cost cost = e.cost - dual_dist[e.to].first + dual_v;
                    if(dual_dist[e.to].second - dist_v > cost) {
                        Cost dist_to = dist_v + cost;
                        dual_dist[e.to].second = dist_to;
                        prev_e[e.to] = e.rev;
                        if(dist_to == dist_v) {
                            que_min.push_back(e.to);
                        } else {
                            que.push_back(Q{dist_to, e.to});
                        }
                    }
                }
            }
            if(!vis[t]) {
                return false;
            }
            for(int v = 0; v < _n; ++v) {
                if(!vis[v]) continue;
                dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;
            }
            return true;
        };
        Cap flow = 0;
        Cost cost = 0, prev_cost_per_flow = -1;
        vector<pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};
        while(flow < flow_limit) {
            if(!dual_ref()) break;
            Cap c = flow_limit - flow;
            for(int v = t; v != s; v = g.elist[prev_e[v]].to) {
                c = min(c, g.elist[g.elist[prev_e[v]].rev].cap);
            }
            for(int v = t; v != s; v = g.elist[prev_e[v]].to) {
                auto& e = g.elist[prev_e[v]];
                e.cap += c;
                g.elist[e.rev].cap -= c;
            }
            Cost d = -dual_dist[s].first;
            flow += c;
            cost += c * d;
            if(prev_cost_per_flow == d) {
                result.pop_back();
            }
            result.push_back({flow, cost});
            prev_cost_per_flow = d;
        }
        return result;
    }
};