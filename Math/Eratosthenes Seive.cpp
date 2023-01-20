// seive(n); でn以下の素数を列挙する。prime[i]はi番目の素数、is_prime[i]はiが素数かどうかを表す。
vector<ll> prime;
vector<bool> is_prime;
void seive(ll n) {
    is_prime.resize(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    rep(i, 2, n + 1) {
        if(is_prime[i]) {
            prime.push_back(i);
            for(ll j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
