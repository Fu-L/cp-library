#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/template/debug.hpp"
#include "../../../src/modint/static_modint.hpp"
#include "../../../src/modint/dynamic_modint.hpp"
using mint = modint998244353;
using Mint = modint;
struct Printable {
    int x;
};
ostream& operator<<(ostream& os, const Printable& p) {
    return os << "Printable{" << p.x << "}";
}
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
    vector<bool> vb = {true, false, true};
    array<int, 3> ar = {8, 9, 10};
    debug(vb, ar, '\0', '\n');
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
    tuple<int, string, vector<int>, pair<int, int>, bool> tp = {1, "abc", {2, 3}, {4, 5}, true};
    debug(tp);
    optional<pair<int, string>> op = pair<int, string>{3, "opt"};
    optional<int> nop;
    debug(op, nop);
    variant<int, string, vector<int>> var = vector<int>{1, 2, 3};
    debug(var);
    stack<int> stk;
    queue<string> que;
    priority_queue<int> pq;
    for(int x : {1, 3, 2}) {
        stk.push(x);
        pq.push(x);
    }
    que.push("front");
    que.push("back");
    debug(stk, que, pq);
    __int128_t big = ((__int128_t)1 << 100) + 123;
    __uint128_t ubig = ((__uint128_t)1 << 100) + 456;
    debug(big, ubig);
    Printable pr{42};
    debug(pr);
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
