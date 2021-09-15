// ll p=seive(n); でn以下の素数を列挙する。pはn以下の素数の個数、prime[i]はi番目の素数、is_prime[i]はiが素数かどうかを表す。
ll prime[MAX_N];
bool is_prime[MAX_N];
ll seive(ll n){
    ll p=0;
    for(ll i=0;i<=n;i++){
        is_prime[i]=true;
    }
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++){
        if(is_prime[i]){
            prime[p++]=i;
            for(ll j=2*i;j<=n;j+=i){
                is_prime[j]=false;
            }
        }
    }
    return p;
}
