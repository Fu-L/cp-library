struct TreeDiameter {
    int n;
    vector<vector<int>> to;
    vector<vector<ll>> cost;
    TreeDiameter(int n)
        : n(n), to(n), cost(n) {}
    void add_edge(int u, int v, ll c = 1) {
        to[u].push_back(v);
        to[v].push_back(u);
        cost[u].push_back(c);
        cost[v].push_back(c);
    }
    pair<ll, vector<int>> diameter() {
        vector<ll> dist(n);
        vector<int> par(n);
        auto dfs = [&](auto& dfs, int v, int p, ll dep) -> void {
            dist[v] = dep;
            par[v] = p;
            rep(i, 0, (int)to[v].size()) {
                if(to[v][i] == p) continue;
                dfs(dfs, to[v][i], v, dep + cost[v][i]);
            }
        };
        dfs(dfs, 0, -1, 0);
        int s = -1;
        ll ma = -1;
        rep(i, 0, n) {
            if(ma < dist[i]) {
                s = i;
                ma = dist[i];
            }
        }
        dfs(dfs, s, -1, 0);
        int t = -1;
        ma = -1;
        rep(i, 0, n) {
            if(ma < dist[i]) {
                t = i;
                ma = dist[i];
            }
        }
        vector<int> vec;
        ll cur = t;
        while(cur != -1) {
            vec.push_back(cur);
            cur = par[cur];
        }
        pair<ll, vector<int>> res = {ma, vec};
        return res;
    }
};
