template <typename Cap>
struct mf_graph {
    struct _edge {
        int to, rev;
        Cap cap;
    };
    struct edge {
        int from, to;
        Cap cap, flow;
    };
    int n;
    vector<pair<int, int>> pos;
    vector<vector<_edge>> g;
    mf_graph(int N)
        : n(N), g(N) {}
    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if(from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }
    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    vector<edge> edges() {
        int m = int(pos.size());
        vector<edge> result;
        rep(i, 0, m) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }
    Cap flow(int s, int t) {
        return flow(s, t, numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < n);
        assert(0 <= t && t < n);
        assert(s != t);
        vector<int> level(n), iter(n);
        queue<int> que;
        auto bfs = [&]() -> void {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            queue<int>().swap(que);
            que.push(s);
            while(!que.empty()) {
                int v = que.front();
                que.pop();
                for(auto e : g[v]) {
                    if(e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if(e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto& dfs, int v, Cap up) -> Cap {
            if(v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for(int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if(level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d = dfs(dfs, e.to, min(up - res, g[e.to][e.rev].cap));
                if(d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if(res == up) return res;
            }
            level[v] = n;
            return res;
        };
        Cap flow = 0;
        while(flow < flow_limit) {
            bfs();
            if(level[t] == -1) break;
            fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(dfs, t, flow_limit - flow);
            if(!f) break;
            flow += f;
        }
        return flow;
    }
    vector<bool> min_cut(int s) {
        vector<bool> visited(n);
        queue<int> que;
        que.push(s);
        while(!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for(auto e : g[p]) {
                if(e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }
};
