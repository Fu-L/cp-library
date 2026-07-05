#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/dp/longest_increasing_sequence.hpp"
int brute_length(const vector<int>& a) {
    const int n = (int)a.size();
    int res = 0;
    for(int bit = 0; bit < (1 << n); ++bit) {
        vector<int> b;
        for(int i = 0; i < n; ++i) {
            if((bit >> i) & 1) b.push_back(a[i]);
        }
        bool ok = true;
        for(int i = 1; i < (int)b.size(); ++i) {
            if(b[i - 1] >= b[i]) ok = false;
        }
        if(ok) res = max(res, (int)b.size());
    }
    return res;
}
void check(const vector<int>& a) {
    const vector<int> lis = longest_increasing_sequence(a);
    assert((int)lis.size() == brute_length(a));
    for(int i = 0; i < (int)lis.size(); ++i) {
        assert(0 <= lis[i] and lis[i] < (int)a.size());
        if(i) {
            assert(lis[i - 1] < lis[i]);
            assert(a[lis[i - 1]] < a[lis[i]]);
        }
    }
}
int main() {
    check({});
    check({3, 2, 1});
    check({1, 1, 1});
    check({3, 1, 2, 1, 4});
    for(int n = 0; n <= 10; ++n) {
        const int total = 1 << n;
        for(int bit = 0; bit < total; ++bit) {
            vector<int> a(n);
            for(int i = 0; i < n; ++i) a[i] = ((bit >> i) & 1) ? 1 : 0;
            check(a);
        }
    }
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}