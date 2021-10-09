// Rerooting g(n)でn頂点のグラフを作成。
struct Rerooting{
    const ll id=0;
    function<ll(ll,ll)> merge=[](ll dp_cum,ll d)->ll{
        return max(dp_cum,d);
    };
    function<ll(ll,ll)> add_root=[](ll v,ll d)->ll{
        return max(D[v],d);
    };
    struct edge{
        ll to,cost;
    };
    vector<vector<ll>> dp;
    vector<ll> ans;
    vector<vector<edge>> g;
    Rerooting(ll n):g(n){
        dp.resize(n);
        ans.assign(n,id);
    }
    void add_edge(ll a,ll b,ll c){
        g[a].push_back({b,c});
    }
    void build(){
        dfs(0);
        bfs(0,id);
    }
    ll dfs(ll v,ll p=-1){
        ll dp_cum=id;
        ll deg=g[v].size();
        dp[v]=vector<ll>(deg,id);
        rep(i,0,deg){
            ll to=g[v][i].to;
            if(to==p) continue;
            dp[v][i]=dfs(to,v);
            dp_cum=merge(dp_cum,dp[v][i]);
        }
        return add_root(v,dp_cum);
    }
    void bfs(ll v,const ll& dp_p,ll p=-1){
        ll deg=g[v].size();
        rep(i,0,deg){
            if(g[v][i].to==p) dp[v][i]=dp_p;
        }
        vector<ll> dp_l(deg+1,id),dp_r(deg+1,id);
        rep(i,0,deg){
            dp_l[i+1]=merge(dp_l[i],dp[v][i]);
        }
        rrep(i,deg-1,0){
            dp_r[i]=merge(dp_r[i+1],dp[v][i]);
        }
        ans[v]=add_root(v,dp_l[deg]);
        rep(i,0,deg){
            ll to=g[v][i].to;
            if(to==p) continue;
            bfs(to,add_root(v,merge(dp_l[i],dp_r[i+1])),v);
        }
    }
};
