#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/template/debug.hpp"
using mint = modint998244353;
using Mint = modint;
void test() {
    int a = 5, b = 7, c = -1;
    debug(a, b, c);
    pair<int, int> p = {3, 4};
    pair<pair<int, int>, pair<pair<int, bool>, int>> q;
    debug(p);
    debug(q);
    debug(p, q);
    pair<string, char> ps;
    ps.second = 'f';
    debug(ps);
    vector<vector<pair<string, char>>> v(3, vector<pair<string, char>>(4));
    debug(v);
    map<int, int> mp;
    mp[4] = 7;
    mp[-2] = 9;
    debug(mp);
    set<double> st;
    st.insert(4.1);
    st.insert(3173.4178);
    debug(st);
    map<long double, set<pair<string, vector<bool>>>> ms;
    debug(ms);
    map<string, vector<pair<int, long double>>> mp2;
    mp2["hello"] = {{2, 3}, {4, 5}};
    mp2["hoge"] = {{4, 1}, {3, 8}, {7, 10}};
    debug(mp2);
    vector<pair<vector<ll>, vector<string>>> v2 = {{{2, 3, 4, 5}, {"hello", "hoge"}}, {{3, 1, 4}, {"hfo", "fah"}}};
    debug(v2);
    mint ma = 998244352, mb = 2, mc = ma * mb;
    debug(mc);
    Mint::set_mod(1000000007);
    Mint dma = 500000004, dmb = 6, dmc = dma * dmb;
    debug(dmc);
}
int main(void) {
    test();
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}