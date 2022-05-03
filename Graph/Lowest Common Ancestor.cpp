// 根付き木で最近共通祖先LCAを求める。
// LCA<ll> g(n); でn頂点のグラフを作る。
// g.add_edge(a,b,c); でaとbの間にコストcの辺を張る。
// g.init() でlcaを求める準備をする。
// g.dep[v] で頂点vの深さ、g.par[v][0] で頂点vの親が求まる。
// g.lca(a,b) でaとbのLCAを求める。
// g.length(a,b) でaとbの最短距離を求める。
template<typename T> // T: type of cost
struct LCA{
    ll n,root,l;
    vector<vector<ll>> to;
    vector<vector<T>> co;
    vector<ll> dep;
    vector<T> costs;
    vector<vector<ll>> par;
    LCA(ll n):n(n),to(n),co(n),dep(n),costs(n){
        l=0;
        while((1<<l)<n) ++l;
        par=vector<vector<ll>>(n+1,vector<ll>(l,n));
    }
    void add_edge(ll a,ll b,T c=0){
        to[a].push_back(b); co[a].push_back(c);
        to[b].push_back(a); co[b].push_back(c);
    }
    void dfs(ll v,ll d=0,T c=0,ll p=-1){
        if(p!=-1) par[v][0]=p;
        dep[v]=d;
        costs[v]=c;
        for(ll i=0;i<to[v].size();++i){
            ll u=to[v][i];
            if(u==p) continue;
            dfs(u,d+1,c+co[v][i],v);
        }
    }
    void init(ll _root=0){
        root=_root;
        dfs(root);
        dep[n]=-1;
        for(ll i=0;i<l-1;++i){
            for(ll v=0;v<n;++v){
                par[v][i+1]=par[par[v][i]][i];
            }
        }
    }
    // LCA
    ll lca(ll a,ll b){
        if(dep[a]>dep[b]) swap(a,b);
        ll gap=dep[b]-dep[a];
        for(ll i=l-1;i>=0;--i){
            ll len=1<<i;
            if(gap>=len){
                gap-=len;
                b=par[b][i];
            }
        }
        if(a==b) return a;
        for(ll i=l-1;i>=0;--i){
            ll na=par[a][i];
            ll nb=par[b][i];
            if(na!=nb) a=na,b=nb;
        }
        return par[a][0];
    }
    ll length(ll a,ll b){
        ll c=lca(a,b);
        return dep[a]+dep[b]-dep[c]*2;
    }
    T dist(ll a,ll b){
        ll c=lca(a,b);
        return costs[a]+costs[b]-costs[c]*2;
    }
};
