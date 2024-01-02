#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D"
#include "src/template/template.hpp"
#include "src/math/divisor.hpp"
int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    vector<ll> d = divisor(c);
    int ans = 0;
    for(int i = 0; i < (int)d.size(); i++) {
        if(a <= d[i] and d[i] <= b) {
            ans++;
        }
    }
    cout << ans << '\n';
}