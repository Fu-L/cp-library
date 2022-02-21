// cht.add(a,b); で、直線y=ax+bを追加する。aは単調性が必要。
// cht.query(x); で、x=xでの最小値がもとまる。
template<typename T>
struct CHT{
    deque<pair<T,T>> deq;
    T calc(pair<T,T> p,T x){
        return p.first*x+p.second;
    }
    ll check(pair<T,T> A,pair<T,T> B,pair<T,T> C){
        return ((A.second-C.second)*(B.first-A.first)<=(A.second-B.second)*(C.first-A.first));
    }
    void add(T a,T b){
        deq.push_back({a,b});
        ll v;
        while((v=deq.size())>=3&&check(deq[v-3],deq[v-2],deq[v-1])){
            deq[v-2]=deq[v-1];
            deq.pop_back();
        }
    }
    T query(T x){
        ll l=-1,r=deq.size()-1;
        while(r-l>1){
            ll m=(l+r)/2;
            if(calc(deq[m],x)>=calc(deq[m+1],x)){
                l=m;
            }else{
                r=m;
            }
        }
        return calc(deq[r],x);
    }
};
