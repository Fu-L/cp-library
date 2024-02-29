#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0502"
#include "../../../src/template/template.hpp"
#include "../../../src/others/dice.hpp"
int main(void) {
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        Dice d;
        int ans = 1;
        while(n--) {
            string s;
            cin >> s;
            if(s == "North") d.roll_back();
            if(s == "East") d.roll_right();
            if(s == "South") d.roll_front();
            if(s == "West") d.roll_left();
            if(s == "Right") d.roll_cw();
            if(s == "Left") d.roll_ccw();
            ans += d.top;
        }
        cout << ans << '\n';
    }
}