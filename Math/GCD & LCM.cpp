// ll g=gcd(a,b); でGCD(a,b)を,ll l=lcm(a,b); でLCM(a,b)を求める。;
ll gcd(ll a,ll b) {return __gcd(a,b);}
ll lcm(ll a,ll b) {return a/__gcd(a,b)*b;}