#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C"
#include "../../../src/template/template.hpp"
#include "../../../src/math/is_prime.hpp"
int main(void) {
    int n;
    cin >> n;
    int ans = 0;
    while(n--) {
        int m;
        cin >> m;
        if(is_prime(m)) {
            ans++;
        }
    }
    cout << ans << '\n';
}